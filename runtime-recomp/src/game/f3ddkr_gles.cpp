#include "f3ddkr_gles.hpp"

#include <SDL.h>

#include <algorithm>
#include <atomic>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>

namespace dkr::runtime {

static std::atomic<std::uint64_t> g_completed_tasks{0};

#if !DKR_RUNTIME_HAS_RT64
std::uint64_t completed_f3ddkr_task_count() {
    return g_completed_tasks.load();
}
#endif

#define XXH_INLINE_ALL
#include "xxHash/xxhash.h"

uint64_t HashTMEM(const uint8_t* tmem_base, size_t offset, size_t len) {
    offset &= 0x0FFFU;
    if (len > 4096U) len = 4096U;
    const size_t first = std::min(len, static_cast<size_t>(4096U - offset));
    uint64_t h = XXH3_64bits(tmem_base + offset, first);
    if (len > first) h = XXH3_64bits_withSeed(tmem_base, len - first, h);
    return h ? h : 1;   // 0 is the "no hash" sentinel
}

namespace {

constexpr uint8_t kMatrixOpcode = 0x01;
constexpr uint8_t kTextureOffsetOpcode = 0x02;
constexpr uint8_t kMoveMemOpcode = 0x03;
constexpr uint8_t kVertexOpcode = 0x04;
constexpr uint8_t kTriangleOpcode = 0x05;
constexpr uint8_t kDisplayListOpcode = 0x06;
constexpr uint8_t kCountedDisplayListOpcode = 0x07;
constexpr uint8_t kClearGeometryModeOpcode = 0xB6;
constexpr uint8_t kSetGeometryModeOpcode = 0xB7;
constexpr uint8_t kEndDisplayListOpcode = 0xB8;
constexpr uint8_t kSetOtherModeLOpcode = 0xB9;
constexpr uint8_t kSetOtherModeHOpcode = 0xBA;
constexpr uint8_t kTextureOpcode = 0xBB;
constexpr uint8_t kMoveWordOpcode = 0xBC;
constexpr uint8_t kDMAOffsetsOpcode = 0xBF;

constexpr uint8_t kTexRectOpcode = 0xE4;
constexpr uint8_t kTexRectFlipOpcode = 0xE5;
constexpr uint8_t kSetScissorOpcode = 0xED;
constexpr uint8_t kSetOtherModeOpcode = 0xEF;
constexpr uint8_t kLoadTLUTOpcode = 0xF0;
constexpr uint8_t kSetTileSizeOpcode = 0xF2;
constexpr uint8_t kLoadBlockOpcode = 0xF3;
constexpr uint8_t kLoadTileOpcode = 0xF4;
constexpr uint8_t kSetTileOpcode = 0xF5;
constexpr uint8_t kFillRectOpcode = 0xF6;
constexpr uint8_t kSetFillColorOpcode = 0xF7;
constexpr uint8_t kSetFogColorOpcode = 0xF8;
constexpr uint8_t kSetBlendColorOpcode = 0xF9;
constexpr uint8_t kSetPrimColorOpcode = 0xFA;
constexpr uint8_t kSetEnvColorOpcode = 0xFB;
constexpr uint8_t kSetCombineOpcode = 0xFC;
constexpr uint8_t kSetTextureImageOpcode = 0xFD;
constexpr uint8_t kSetDepthImageOpcode = 0xFE;
constexpr uint8_t kSetColorImageOpcode = 0xFF;

constexpr uint32_t kRDRAMAddressMask = 0x00FFFFFFU;
constexpr uint32_t kRDRAMSize = 0x00800000U; // Must equal RDRAMSnapshotSize in events.cpp:617

inline bool RdramRangeOk(uint64_t addr, uint64_t len) {
    return addr <= kRDRAMSize && len <= (static_cast<uint64_t>(kRDRAMSize) - addr);
}

static const bool s_no_fog = []() {
    if (const char* env = std::getenv("DKR_GLES_NO_FOG")) {
        return std::atoi(env) != 0;
    }
    return false;
}();

static const bool s_perf_detail = []() {
    if (const char* env = std::getenv("DKR_GLES_PERF_DETAIL")) {
        return std::atoi(env) != 0;
    }
    return false;
}();

static const bool s_no_texcache = []() {
    if (const char* env = std::getenv("DKR_GLES_NO_TEXCACHE")) {
        return std::atoi(env) != 0;
    }
    return false;
}();

static const bool s_log_tex = []() {
    if (const char* env = std::getenv("DKR_GLES_LOG_TEX")) {
        return std::atoi(env) != 0;
    }
    return false;
}();

int16_t ReadS16(const uint8_t* rdram, uint32_t address) {
    address &= kRDRAMAddressMask;
    if (!RdramRangeOk(address & ~3U, 4)) return 0;
    int16_t value = 0;
    std::memcpy(&value, rdram + (address ^ 2U), sizeof(value));
    return value;
}

uint16_t ReadU16(const uint8_t* rdram, uint32_t address) {
    address &= kRDRAMAddressMask;
    if (!RdramRangeOk(address & ~3U, 4)) return 0;
    uint16_t value = 0;
    std::memcpy(&value, rdram + (address ^ 2U), sizeof(value));
    return value;
}

uint8_t ReadU8(const uint8_t* rdram, uint32_t address) {
    address &= kRDRAMAddressMask;
    if (!RdramRangeOk(address & ~3U, 4)) return 0;
    return rdram[address ^ 3U];
}

uint32_t ReadU32(const uint8_t* rdram, uint32_t address) {
    address &= kRDRAMAddressMask;
    if (!RdramRangeOk(address & ~3U, 4)) return 0;
    uint32_t value = 0;
    std::memcpy(&value, rdram + address, sizeof(value));
    return value;
}

inline int16_t RawS16(const uint8_t* r, uint32_t a) {
    int16_t v = 0;
    std::memcpy(&v, r + (a ^ 2U), sizeof(v));
    return v;
}

inline uint8_t RawU8(const uint8_t* r, uint32_t a) {
    return r[a ^ 3U];
}

void CopyRDRAMToTMEM(uint8_t* tmem, size_t tmem_dest, const uint8_t* rdram, size_t rdram_src, size_t bytes) {
    bytes = std::min<size_t>(bytes, 4096U);
    tmem_dest &= 0x0FFFU;
    while (bytes > 0) {
        const size_t chunk = std::min(bytes, static_cast<size_t>(4096U - tmem_dest));
        size_t i = 0;
        if (((tmem_dest | rdram_src) & 3U) == 0) {
            for (; i + 4 <= chunk; i += 4) {
                uint32_t w = 0;
                std::memcpy(&w, rdram + rdram_src + i, 4);
                w = __builtin_bswap32(w);
                std::memcpy(tmem + tmem_dest + i, &w, 4);
            }
        }
        for (; i < chunk; ++i) {
            tmem[tmem_dest + i] = rdram[(rdram_src + i) ^ 3U];
        }
        tmem_dest = 0;
        rdram_src += chunk;
        bytes -= chunk;
    }
}

constexpr uint32_t kShaderGenVersion = 2;

static uint64_t HashShaderSource(const char* s1, const char* s2, const char* renderer, const char* version) {
    uint64_t hash = 14695981039346656037ULL;
    auto add_str = [&](const char* s) {
        if (!s) return;
        while (*s) {
            hash ^= static_cast<uint8_t>(*s++);
            hash *= 1099511628211ULL;
        }
    };
    auto add_u32 = [&](uint32_t v) {
        for (int i = 0; i < 4; ++i) {
            hash ^= static_cast<uint8_t>(v & 0xFF);
            hash *= 1099511628211ULL;
            v >>= 8;
        }
    };
    add_u32(kShaderGenVersion);
    add_str(s1);
    add_str(s2);
    add_str(renderer);
    add_str(version);
    return hash;
}

static void compute_tile_dims(const F3DGLESTile& t, uint32_t& w, uint32_t& h) {
    const bool wrap_or_mirror_s = (!t.clamp_s || t.mirror_s);
    if (wrap_or_mirror_s && t.mask_s > 0 && t.mask_s <= 10) {
        w = 1U << t.mask_s;
    } else if (t.sh > t.sl) {
        w = ((t.sh - t.sl) >> 2U) + 1U;
    } else if (t.mask_s > 0 && t.mask_s <= 10) {
        w = 1U << t.mask_s;
    } else if (t.line > 0) {
        uint32_t texels_per_word = 4;
        if (t.size == 0) texels_per_word = 16;
        else if (t.size == 1) texels_per_word = 8;
        else if (t.size == 2) texels_per_word = 4;
        else if (t.size == 3) texels_per_word = 4;
        w = std::min(static_cast<uint32_t>(t.line * texels_per_word), 1024U);
    } else {
        w = 32U;
    }

    const bool wrap_or_mirror_t = (!t.clamp_t || t.mirror_t);
    if (wrap_or_mirror_t && t.mask_t > 0 && t.mask_t <= 10) {
        h = 1U << t.mask_t;
    } else if (t.th > t.tl) {
        h = ((t.th - t.tl) >> 2U) + 1U;
    } else if (t.mask_t > 0 && t.mask_t <= 10) {
        h = 1U << t.mask_t;
    } else {
        h = w;
    }
}

} // namespace

bool DecodeTMEMToRGBA16(const uint8_t* tmem, uint8_t fmt, uint8_t size, uint8_t palette,
                        uint32_t tmem_offset, uint32_t width, uint32_t height,
                        uint32_t row_stride_bytes,
                        std::vector<uint16_t>& out_rgba16,
                        bool odd_line_swap,
                        uint8_t tlut_type) {
    if (tlut_type == 3) {
        return false;
    }

    const size_t total_pixels = static_cast<size_t>(width) * height;
    out_rgba16.resize(total_pixels, 0xFFFFU);

    const uint32_t swap_xor = 4U;

    if (fmt == 0 && size == 2) { // RGBA16 (5-5-5-1)
        const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : (width * 2U);
        for (uint32_t y = 0; y < height; ++y) {
            const uint32_t row_start = tmem_offset + y * stride;
            const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? swap_xor : 0U;
            for (uint32_t x = 0; x < width; ++x) {
                const uint32_t byte_off = (x * 2U) ^ xor_mask;
                const uint32_t src0 = (row_start + byte_off) & 0x0FFFU;
                const uint32_t src1 = (row_start + byte_off + 1U) & 0x0FFFU;
                out_rgba16[y * width + x] = static_cast<uint16_t>((tmem[src0] << 8) | tmem[src1]);
            }
        }
        return true;
    } else if (fmt == 2) { // CI4 or CI8 with 16-bit palette
        if (size == 0) { // CI4 (16 colors)
            uint32_t pal_base = 0x800U + static_cast<uint32_t>(palette & 0x0FU) * 32U;
            if (pal_base + 32U > 4096U) {
                pal_base = 0x800U;
            }
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : ((width + 1U) / 2U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? swap_xor : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x / 2U) ^ xor_mask;
                    const uint32_t byte_addr = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t byte_val = tmem[byte_addr];
                    const uint8_t idx = ((x & 1U) == 0U) ? ((byte_val >> 4U) & 0x0FU) : (byte_val & 0x0FU);
                    const uint32_t c_addr = pal_base + static_cast<uint32_t>(idx * 2U);
                    const uint32_t p0 = c_addr & 0x0FFFU;
                    const uint32_t p1 = (c_addr + 1U) & 0x0FFFU;
                    out_rgba16[y * width + x] = static_cast<uint16_t>((tmem[p0] << 8) | tmem[p1]);
                }
            }
            return true;
        } else if (size == 1) { // CI8 (256 colors)
            const uint32_t pal_base = 0x800U;
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : width;
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? swap_xor : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = x ^ xor_mask;
                    const uint32_t byte_addr = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t idx = tmem[byte_addr];
                    const uint32_t c_addr = pal_base + static_cast<uint32_t>(idx * 2U);
                    const uint32_t p0 = c_addr & 0x0FFFU;
                    const uint32_t p1 = (c_addr + 1U) & 0x0FFFU;
                    out_rgba16[y * width + x] = static_cast<uint16_t>((tmem[p0] << 8) | tmem[p1]);
                }
            }
            return true;
        }
    }
    return false;
}

void DecodeTMEMToRGBA(const uint8_t* tmem, uint8_t fmt, uint8_t size, uint8_t palette,
                      uint32_t tmem_offset, uint32_t width, uint32_t height,
                      uint32_t row_stride_bytes,
                      std::vector<uint32_t>& out_rgba,
                      bool odd_line_swap,
                      uint8_t tlut_type) {
    const size_t total_pixels = static_cast<size_t>(width) * height;
    out_rgba.resize(total_pixels, 0xFFFFFFFFU);

    if (fmt == 0) { // RGBA
        if (size == 2) { // RGBA16 (5-5-5-1)
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : (width * 2U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? 4U : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x * 2U) ^ xor_mask;
                    const uint32_t src0 = (row_start + byte_off) & 0x0FFFU;
                    const uint32_t src1 = (row_start + byte_off + 1U) & 0x0FFFU;
                    const uint16_t c = static_cast<uint16_t>((tmem[src0] << 8) | tmem[src1]);
                    const uint32_t r = static_cast<uint32_t>(((c >> 11) & 0x1F) * 255 / 31);
                    const uint32_t g = static_cast<uint32_t>(((c >> 6) & 0x1F) * 255 / 31);
                    const uint32_t b = static_cast<uint32_t>(((c >> 1) & 0x1F) * 255 / 31);
                    const uint32_t a = (c & 0x01) ? 255U : 0U;
                    out_rgba[y * width + x] = (a << 24) | (b << 16) | (g << 8) | r;
                }
            }
        } else if (size == 3) { // RGBA32 (8-8-8-8)
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : (width * 4U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? 8U : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x * 4U) ^ xor_mask;
                    const uint32_t src0 = (row_start + byte_off) & 0x0FFFU;
                    const uint32_t src1 = (row_start + byte_off + 1U) & 0x0FFFU;
                    const uint32_t src2 = (row_start + byte_off + 2U) & 0x0FFFU;
                    const uint32_t src3 = (row_start + byte_off + 3U) & 0x0FFFU;
                    const uint32_t r = tmem[src0];
                    const uint32_t g = tmem[src1];
                    const uint32_t b = tmem[src2];
                    const uint32_t a = tmem[src3];
                    out_rgba[y * width + x] = (a << 24) | (b << 16) | (g << 8) | r;
                }
            }
        }
    } else if (fmt == 2) { // Color Indexed (CI)
        if (size == 0) { // CI4 (16 colors)
            uint32_t pal_base = 0x800U + static_cast<uint32_t>(palette & 0x0FU) * 32U;
            if (pal_base + 32U > 4096U) {
                pal_base = 0x800U;
            }
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : ((width + 1U) / 2U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? 4U : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x / 2U) ^ xor_mask;
                    const uint32_t byte_addr = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t byte_val = tmem[byte_addr];
                    const uint8_t idx = ((x & 1U) == 0U) ? ((byte_val >> 4U) & 0x0FU) : (byte_val & 0x0FU);
                    const uint32_t c_addr = pal_base + static_cast<uint32_t>(idx * 2U);
                    const uint32_t p0 = c_addr & 0x0FFFU;
                    const uint32_t p1 = (c_addr + 1U) & 0x0FFFU;
                    if (tlut_type == 3) { // IA16 TLUT
                        const uint32_t I = tmem[p0];
                        const uint32_t A = tmem[p1];
                        out_rgba[y * width + x] = (A << 24) | (I << 16) | (I << 8) | I;
                    } else {
                        const uint16_t c = static_cast<uint16_t>((tmem[p0] << 8) | tmem[p1]);
                        const uint32_t r = static_cast<uint32_t>(((c >> 11) & 0x1F) * 255 / 31);
                        const uint32_t g = static_cast<uint32_t>(((c >> 6) & 0x1F) * 255 / 31);
                        const uint32_t b = static_cast<uint32_t>(((c >> 1) & 0x1F) * 255 / 31);
                        const uint32_t a = (c & 0x01) ? 255U : 0U;
                        out_rgba[y * width + x] = (a << 24) | (b << 16) | (g << 8) | r;
                    }
                }
            }
        } else if (size == 1) { // CI8 (256 colors)
            const uint32_t pal_base = 0x800U;
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : width;
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? 4U : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = x ^ xor_mask;
                    const uint32_t byte_addr = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t idx = tmem[byte_addr];
                    const uint32_t c_addr = pal_base + static_cast<uint32_t>(idx * 2U);
                    const uint32_t p0 = c_addr & 0x0FFFU;
                    const uint32_t p1 = (c_addr + 1U) & 0x0FFFU;
                    if (tlut_type == 3) { // IA16 TLUT
                        const uint32_t I = tmem[p0];
                        const uint32_t A = tmem[p1];
                        out_rgba[y * width + x] = (A << 24) | (I << 16) | (I << 8) | I;
                    } else {
                        const uint16_t c = static_cast<uint16_t>((tmem[p0] << 8) | tmem[p1]);
                        const uint32_t r = static_cast<uint32_t>(((c >> 11) & 0x1F) * 255 / 31);
                        const uint32_t g = static_cast<uint32_t>(((c >> 6) & 0x1F) * 255 / 31);
                        const uint32_t b = static_cast<uint32_t>(((c >> 1) & 0x1F) * 255 / 31);
                        const uint32_t a = (c & 0x01) ? 255U : 0U;
                        out_rgba[y * width + x] = (a << 24) | (b << 16) | (g << 8) | r;
                    }
                }
            }
        }
    } else if (fmt == 3) { // Intensity + Alpha (IA)
        if (size == 2) { // IA16
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : (width * 2U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? 4U : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x * 2U) ^ xor_mask;
                    const uint32_t src0 = (row_start + byte_off) & 0x0FFFU;
                    const uint32_t src1 = (row_start + byte_off + 1U) & 0x0FFFU;
                    const uint32_t val = tmem[src0];
                    const uint32_t a = tmem[src1];
                    out_rgba[y * width + x] = (a << 24) | (val << 16) | (val << 8) | val;
                }
            }
        } else if (size == 1) { // IA8 (4-4)
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : width;
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? 4U : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = x ^ xor_mask;
                    const uint32_t src = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t byte_val = tmem[src];
                    const uint32_t val = static_cast<uint32_t>(((byte_val >> 4) & 0x0F) * 255 / 15);
                    const uint32_t a = static_cast<uint32_t>((byte_val & 0x0F) * 255 / 15);
                    out_rgba[y * width + x] = (a << 24) | (val << 16) | (val << 8) | val;
                }
            }
        } else if (size == 0) { // IA4 (3-1)
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : ((width + 1U) / 2U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? 4U : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x / 2U) ^ xor_mask;
                    const uint32_t byte_addr = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t byte_val = tmem[byte_addr];
                    const uint8_t nib = ((x & 1U) == 0U) ? ((byte_val >> 4) & 0x0F) : (byte_val & 0x0F);
                    const uint32_t val = static_cast<uint32_t>(((nib >> 1) & 0x07) * 255 / 7);
                    const uint32_t a = (nib & 1) ? 255U : 0U;
                    out_rgba[y * width + x] = (a << 24) | (val << 16) | (val << 8) | val;
                }
            }
        }
    } else if (fmt == 4) { // Intensity (I)
        if (size == 1) { // I8
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : width;
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? 4U : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = x ^ xor_mask;
                    const uint32_t src = (row_start + byte_off) & 0x0FFFU;
                    const uint32_t val = tmem[src];
                    out_rgba[y * width + x] = (val << 24) | (val << 16) | (val << 8) | val;
                }
            }
        } else if (size == 0) { // I4
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : ((width + 1U) / 2U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? 4U : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x / 2U) ^ xor_mask;
                    const uint32_t byte_addr = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t byte_val = tmem[byte_addr];
                    const uint8_t nib = ((x & 1U) == 0U) ? ((byte_val >> 4) & 0x0F) : (byte_val & 0x0F);
                    const uint32_t val = static_cast<uint32_t>(nib * 255 / 15);
                    out_rgba[y * width + x] = (val << 24) | (val << 16) | (val << 8) | val;
                }
            }
        }
    }
}

bool DecodeTMEMToLA8(const uint8_t* tmem, uint8_t fmt, uint8_t size, uint8_t palette,
                     uint32_t tmem_offset, uint32_t width, uint32_t height,
                     uint32_t row_stride_bytes,
                     std::vector<uint8_t>& out_la8,
                     bool odd_line_swap,
                     uint8_t tlut_type) {
    const size_t total_pixels = static_cast<size_t>(width) * height;
    const uint32_t swap_xor = 4U;

    if (fmt == 4) { // Intensity (I) -> L = I, A = I
        out_la8.resize(total_pixels * 2U);
        if (size == 1) { // I8
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : width;
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? swap_xor : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = x ^ xor_mask;
                    const uint32_t src = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t val = tmem[src];
                    const size_t out_idx = (y * width + x) * 2U;
                    out_la8[out_idx + 0U] = val;
                    out_la8[out_idx + 1U] = val;
                }
            }
            return true;
        } else if (size == 0) { // I4
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : ((width + 1U) / 2U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? swap_xor : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x / 2U) ^ xor_mask;
                    const uint32_t byte_addr = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t byte_val = tmem[byte_addr];
                    const uint8_t nib = ((x & 1U) == 0U) ? ((byte_val >> 4U) & 0x0FU) : (byte_val & 0x0FU);
                    const uint8_t val = static_cast<uint8_t>(nib * 255U / 15U);
                    const size_t out_idx = (y * width + x) * 2U;
                    out_la8[out_idx + 0U] = val;
                    out_la8[out_idx + 1U] = val;
                }
            }
            return true;
        }
    } else if (fmt == 3) { // Intensity + Alpha (IA)
        out_la8.resize(total_pixels * 2U);
        if (size == 2) { // IA16 (8-8)
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : (width * 2U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? swap_xor : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x * 2U) ^ xor_mask;
                    const uint32_t src0 = (row_start + byte_off) & 0x0FFFU;
                    const uint32_t src1 = (row_start + byte_off + 1U) & 0x0FFFU;
                    const uint8_t val = tmem[src0];
                    const uint8_t a = tmem[src1];
                    const size_t out_idx = (y * width + x) * 2U;
                    out_la8[out_idx + 0U] = val;
                    out_la8[out_idx + 1U] = a;
                }
            }
            return true;
        } else if (size == 1) { // IA8 (4-4)
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : width;
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? swap_xor : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = x ^ xor_mask;
                    const uint32_t src = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t byte_val = tmem[src];
                    const uint8_t val = static_cast<uint8_t>(((byte_val >> 4U) & 0x0FU) * 255U / 15U);
                    const uint8_t a = static_cast<uint8_t>((byte_val & 0x0FU) * 255U / 15U);
                    const size_t out_idx = (y * width + x) * 2U;
                    out_la8[out_idx + 0U] = val;
                    out_la8[out_idx + 1U] = a;
                }
            }
            return true;
        } else if (size == 0) { // IA4 (3-1)
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : ((width + 1U) / 2U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? swap_xor : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x / 2U) ^ xor_mask;
                    const uint32_t byte_addr = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t byte_val = tmem[byte_addr];
                    const uint8_t nib = ((x & 1U) == 0U) ? ((byte_val >> 4U) & 0x0FU) : (byte_val & 0x0FU);
                    const uint8_t val = static_cast<uint8_t>(((nib >> 1U) & 0x07U) * 255U / 7U);
                    const uint8_t a = (nib & 1U) ? 255U : 0U;
                    const size_t out_idx = (y * width + x) * 2U;
                    out_la8[out_idx + 0U] = val;
                    out_la8[out_idx + 1U] = a;
                }
            }
            return true;
        }
    } else if (fmt == 2 && tlut_type == 3) { // Color Indexed with IA16 TLUT
        out_la8.resize(total_pixels * 2U);
        if (size == 0) { // CI4 (16 colors)
            uint32_t pal_base = 0x800U + static_cast<uint32_t>(palette & 0x0FU) * 32U;
            if (pal_base + 32U > 4096U) {
                pal_base = 0x800U;
            }
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : ((width + 1U) / 2U);
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? swap_xor : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = (x / 2U) ^ xor_mask;
                    const uint32_t byte_addr = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t byte_val = tmem[byte_addr];
                    const uint8_t idx = ((x & 1U) == 0U) ? ((byte_val >> 4U) & 0x0FU) : (byte_val & 0x0FU);
                    const uint32_t c_addr = pal_base + static_cast<uint32_t>(idx * 2U);
                    const uint32_t p0 = c_addr & 0x0FFFU;
                    const uint32_t p1 = (c_addr + 1U) & 0x0FFFU;
                    const uint8_t I = tmem[p0];
                    const uint8_t A = tmem[p1];
                    const size_t out_idx = (y * width + x) * 2U;
                    out_la8[out_idx + 0U] = I;
                    out_la8[out_idx + 1U] = A;
                }
            }
            return true;
        } else if (size == 1) { // CI8 (256 colors)
            const uint32_t pal_base = 0x800U;
            const uint32_t stride = (row_stride_bytes > 0) ? row_stride_bytes : width;
            for (uint32_t y = 0; y < height; ++y) {
                const uint32_t row_start = tmem_offset + y * stride;
                const uint32_t xor_mask = (odd_line_swap && ((y & 1U) != 0U)) ? swap_xor : 0U;
                for (uint32_t x = 0; x < width; ++x) {
                    const uint32_t byte_off = x ^ xor_mask;
                    const uint32_t byte_addr = (row_start + byte_off) & 0x0FFFU;
                    const uint8_t idx = tmem[byte_addr];
                    const uint32_t c_addr = pal_base + static_cast<uint32_t>(idx * 2U);
                    const uint32_t p0 = c_addr & 0x0FFFU;
                    const uint32_t p1 = (c_addr + 1U) & 0x0FFFU;
                    const uint8_t I = tmem[p0];
                    const uint8_t A = tmem[p1];
                    const size_t out_idx = (y * width + x) * 2U;
                    out_la8[out_idx + 0U] = I;
                    out_la8[out_idx + 1U] = A;
                }
            }
            return true;
        }
    }
    return false;
}

namespace {

const char* kVertexShaderSource = R"(
attribute vec4 a_position;
attribute vec2 a_texcoord;
attribute vec4 a_color;
varying highp vec2 v_texcoord;
varying mediump vec4 v_color;
varying highp vec2 v_clip_zw;
void main() {
    gl_Position = a_position;
    v_texcoord = a_texcoord;
    v_color = a_color;
    v_clip_zw = a_position.zw;
}
)";

const char* kFragmentShaderSource = R"(
precision mediump float;
#ifdef GL_FRAGMENT_PRECISION_HIGH
#define FRAG_HIGHP highp
#else
#define FRAG_HIGHP mediump
#endif
varying FRAG_HIGHP vec2 v_texcoord;
varying mediump vec4 v_color;
varying FRAG_HIGHP vec2 v_clip_zw;
uniform sampler2D u_sampler;
uniform vec4 u_prim_color;
uniform vec4 u_env_color;
uniform vec4 u_fog_color;
uniform int u_use_texture;
uniform int u_cycle_type;
uniform float u_prim_lod_frac;
uniform int u_alpha_test;
uniform float u_alpha_threshold;
uniform int u_fog_enabled;
uniform int u_fog_geom;
uniform vec2 u_fog_params;

uniform int u_cc_a;
uniform int u_cc_b;
uniform int u_cc_c;
uniform int u_cc_d;
uniform int u_ac_a;
uniform int u_ac_b;
uniform int u_ac_c;
uniform int u_ac_d;

uniform int u_cc_a1;
uniform int u_cc_b1;
uniform int u_cc_c1;
uniform int u_cc_d1;
uniform int u_ac_a1;
uniform int u_ac_b1;
uniform int u_ac_c1;
uniform int u_ac_d1;

vec3 get_cc_color_a(int src, vec3 comb, vec4 tex, vec4 shade) {
    if (src == 0) return comb;
    if (src == 1 || src == 2) return (u_use_texture != 0) ? tex.rgb : vec3(1.0);
    if (src == 3) return u_prim_color.rgb;
    if (src == 4) return shade.rgb;
    if (src == 5) return u_env_color.rgb;
    if (src == 6) return vec3(1.0);
    return vec3(0.0);
}

vec3 get_cc_color_b(int src, vec3 comb, vec4 tex, vec4 shade) {
    if (src == 0) return comb;
    if (src == 1 || src == 2) return (u_use_texture != 0) ? tex.rgb : vec3(1.0);
    if (src == 3) return u_prim_color.rgb;
    if (src == 4) return shade.rgb;
    if (src == 5) return u_env_color.rgb;
    return vec3(0.0);
}

vec3 get_cc_factor_c(int src, vec3 comb, float comb_a, vec4 tex, vec4 shade) {
    if (src == 0) return comb;
    if (src == 1 || src == 2) return (u_use_texture != 0) ? tex.rgb : vec3(1.0);
    if (src == 3) return u_prim_color.rgb;
    if (src == 4) return shade.rgb;
    if (src == 5) return u_env_color.rgb;
    if (src == 7) return vec3(comb_a);
    if (src == 8 || src == 9) return vec3((u_use_texture != 0) ? tex.a : 1.0);
    if (src == 10) return vec3(u_prim_color.a);
    if (src == 11) return vec3(shade.a);
    if (src == 12) return vec3(u_env_color.a);
    if (src == 14) return vec3(u_prim_lod_frac);
    return vec3(0.0);
}

vec3 get_cc_color_d(int src, vec3 comb, vec4 tex, vec4 shade) {
    if (src == 0) return comb;
    if (src == 1 || src == 2) return (u_use_texture != 0) ? tex.rgb : vec3(1.0);
    if (src == 3) return u_prim_color.rgb;
    if (src == 4) return shade.rgb;
    if (src == 5) return u_env_color.rgb;
    if (src == 6) return vec3(1.0);
    return vec3(0.0);
}

float get_ac_abd(int src, float comb_a, vec4 tex, vec4 shade) {
    if (src == 0) return comb_a;
    if (src == 1 || src == 2) return (u_use_texture != 0) ? tex.a : 1.0;
    if (src == 3) return u_prim_color.a;
    if (src == 4) return shade.a;
    if (src == 5) return u_env_color.a;
    if (src == 6) return 1.0;
    return 0.0;
}

float get_ac_c(int src, float comb_a, vec4 tex, vec4 shade) {
    if (src == 1 || src == 2) return (u_use_texture != 0) ? tex.a : 1.0;
    if (src == 3) return u_prim_color.a;
    if (src == 4) return shade.a;
    if (src == 5) return u_env_color.a;
    if (src == 6) return u_prim_lod_frac;
    return 0.0;
}

void main() {
    vec4 tex = (u_use_texture != 0) ? texture2D(u_sampler, v_texcoord) : vec4(1.0);
    vec4 shade = v_color;
    if (u_fog_geom != 0) {
        float z_over_w = v_clip_zw.x / max(v_clip_zw.y, 1e-6);
        shade.a = clamp(z_over_w * u_fog_params.x + u_fog_params.y, 0.0, 1.0);
    }

    vec3 c0_a = get_cc_color_a(u_cc_a, vec3(0.0), tex, shade);
    vec3 c0_b = get_cc_color_b(u_cc_b, vec3(0.0), tex, shade);
    vec3 c0_c = get_cc_factor_c(u_cc_c, vec3(0.0), 0.0, tex, shade);
    vec3 c0_d = get_cc_color_d(u_cc_d, vec3(0.0), tex, shade);
    vec3 rgb0 = clamp((c0_a - c0_b) * c0_c + c0_d, 0.0, 1.0);

    float a0_a = get_ac_abd(u_ac_a, 0.0, tex, shade);
    float a0_b = get_ac_abd(u_ac_b, 0.0, tex, shade);
    float a0_c = get_ac_c(u_ac_c, 0.0, tex, shade);
    float a0_d = get_ac_abd(u_ac_d, 0.0, tex, shade);
    float alpha0 = clamp((a0_a - a0_b) * a0_c + a0_d, 0.0, 1.0);

    vec3 rgb = rgb0;
    float alpha = alpha0;

    if (u_cycle_type == 1) { // 2-cycle combiner
        vec3 c1_a = get_cc_color_a(u_cc_a1, rgb0, tex, shade);
        vec3 c1_b = get_cc_color_b(u_cc_b1, rgb0, tex, shade);
        vec3 c1_c = get_cc_factor_c(u_cc_c1, rgb0, alpha0, tex, shade);
        vec3 c1_d = get_cc_color_d(u_cc_d1, rgb0, tex, shade);
        rgb = clamp((c1_a - c1_b) * c1_c + c1_d, 0.0, 1.0);

        float a1_a = get_ac_abd(u_ac_a1, alpha0, tex, shade);
        float a1_b = get_ac_abd(u_ac_b1, alpha0, tex, shade);
        float a1_c = get_ac_c(u_ac_c1, alpha0, tex, shade);
        float a1_d = get_ac_abd(u_ac_d1, alpha0, tex, shade);
        alpha = clamp((a1_a - a1_b) * a1_c + a1_d, 0.0, 1.0);
    }

    if (u_alpha_test == 1) {
        if (alpha < u_alpha_threshold) {
            discard;
        }
    } else if (u_alpha_test == 2) {
        float dither = fract(sin(dot(gl_FragCoord.xy, vec2(12.9898, 78.233))) * 43758.5453);
        if (alpha < dither) {
            discard;
        }
    }

    if (u_fog_enabled != 0) {
        rgb = mix(rgb, u_fog_color.rgb, shade.a);
    }

    gl_FragColor = vec4(rgb, alpha);
}
)";

GLuint CompileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    GLint compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        char info_log[512];
        glGetShaderInfoLog(shader, sizeof(info_log), nullptr, info_log);
        std::fprintf(stderr, "[gles][shader] compile error: %s\n", info_log);
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

struct UniformUsage {
    bool prim = false;
    bool env = false;
    bool lod_frac = false;
    bool fog_params = false;
    bool fog_color = false;
    bool alpha_thresh = false;
    bool sampler = false;
};

static std::string GetCCColorA(uint8_t src, int cycle, bool use_tex, UniformUsage& u) {
    if (src == 0) return (cycle == 0) ? "vec3(0.0)" : "rgb0";
    if (src == 1 || src == 2) return use_tex ? "tex.rgb" : "vec3(1.0)";
    if (src == 3) { u.prim = true; return "u_prim_color.rgb"; }
    if (src == 4) return "shade.rgb";
    if (src == 5) { u.env = true; return "u_env_color.rgb"; }
    if (src == 6) return "vec3(1.0)";
    return "vec3(0.0)";
}

static std::string GetCCColorB(uint8_t src, int cycle, bool use_tex, UniformUsage& u) {
    if (src == 0) return (cycle == 0) ? "vec3(0.0)" : "rgb0";
    if (src == 1 || src == 2) return use_tex ? "tex.rgb" : "vec3(1.0)";
    if (src == 3) { u.prim = true; return "u_prim_color.rgb"; }
    if (src == 4) return "shade.rgb";
    if (src == 5) { u.env = true; return "u_env_color.rgb"; }
    return "vec3(0.0)";
}

static std::string GetCCFactorC(uint8_t src, int cycle, bool use_tex, UniformUsage& u) {
    if (src == 0) return (cycle == 0) ? "vec3(0.0)" : "rgb0";
    if (src == 1 || src == 2) return use_tex ? "tex.rgb" : "vec3(1.0)";
    if (src == 3) { u.prim = true; return "u_prim_color.rgb"; }
    if (src == 4) return "shade.rgb";
    if (src == 5) { u.env = true; return "u_env_color.rgb"; }
    if (src == 7) return (cycle == 0) ? "vec3(0.0)" : "vec3(alpha0)";
    if (src == 8 || src == 9) return use_tex ? "vec3(tex.a)" : "vec3(1.0)";
    if (src == 10) { u.prim = true; return "vec3(u_prim_color.a)"; }
    if (src == 11) return "vec3(shade.a)";
    if (src == 12) { u.env = true; return "vec3(u_env_color.a)"; }
    if (src == 14) { u.lod_frac = true; return "vec3(u_prim_lod_frac)"; }
    return "vec3(0.0)";
}

static std::string GetCCColorD(uint8_t src, int cycle, bool use_tex, UniformUsage& u) {
    if (src == 0) return (cycle == 0) ? "vec3(0.0)" : "rgb0";
    if (src == 1 || src == 2) return use_tex ? "tex.rgb" : "vec3(1.0)";
    if (src == 3) { u.prim = true; return "u_prim_color.rgb"; }
    if (src == 4) return "shade.rgb";
    if (src == 5) { u.env = true; return "u_env_color.rgb"; }
    if (src == 6) return "vec3(1.0)";
    return "vec3(0.0)";
}

static std::string GetACAbd(uint8_t src, int cycle, bool use_tex, UniformUsage& u) {
    if (src == 0) return (cycle == 0) ? "0.0" : "alpha0";
    if (src == 1 || src == 2) return use_tex ? "tex.a" : "1.0";
    if (src == 3) { u.prim = true; return "u_prim_color.a"; }
    if (src == 4) return "shade.a";
    if (src == 5) { u.env = true; return "u_env_color.a"; }
    if (src == 6) return "1.0";
    return "0.0";
}

static std::string GetACC(uint8_t src, int cycle, bool use_tex, UniformUsage& u) {
    if (src == 1 || src == 2) return use_tex ? "tex.a" : "1.0";
    if (src == 3) { u.prim = true; return "u_prim_color.a"; }
    if (src == 4) return "shade.a";
    if (src == 5) { u.env = true; return "u_env_color.a"; }
    if (src == 6) { u.lod_frac = true; return "u_prim_lod_frac"; }
    return "0.0";
}

static std::string EmitFormula(const std::string& a, const std::string& b,
                               const std::string& c, const std::string& d,
                               bool is_vec3) {
    const std::string zero = is_vec3 ? "vec3(0.0)" : "0.0";
    const std::string one  = is_vec3 ? "vec3(1.0)" : "1.0";

    auto is_zero = [&](const std::string& s) { return s == zero; };
    auto is_one  = [&](const std::string& s) { return s == one; };

    // Case 1: if c is zero, (a - b) * 0 + d == d
    if (is_zero(c)) {
        return d;
    }
    // Case 2: if a == b, (a - a) * c + d == d
    if (a == b) {
        return d;
    }
    // Case 3: if c is one: (a - b) * 1 + d == (a - b) + d
    if (is_one(c)) {
        if (is_zero(b)) {
            if (is_zero(d)) return a;
            return a + " + " + d;
        }
        if (is_zero(a)) {
            if (is_zero(d)) return "(-" + b + ")";
            return d + " - " + b;
        }
        if (is_zero(d)) return a + " - " + b;
        return a + " - " + b + " + " + d;
    }
    // Case 4: General c:
    std::string term;
    if (is_zero(b)) {
        if (is_one(a)) term = c;
        else term = a + " * " + c;
    } else if (is_zero(a)) {
        term = "(-" + b + ") * " + c;
    } else {
        term = "(" + a + " - " + b + ") * " + c;
    }

    if (is_zero(d)) {
        return term;
    }
    return term + " + " + d;
}

static bool reads_texture(const CombinerKey& key) {
    if (!key.use_texture) return false;
    auto is_tex_cc = [](uint8_t src, bool is_c) {
        if (src == 1 || src == 2) return true;
        if (is_c && (src == 8 || src == 9)) return true;
        return false;
    };
    auto is_tex_ac = [](uint8_t src) {
        return (src == 1 || src == 2);
    };
    if (is_tex_cc(key.cc[0], false) || is_tex_cc(key.cc[1], false) ||
        is_tex_cc(key.cc[2], true)  || is_tex_cc(key.cc[3], false) ||
        is_tex_ac(key.ac[0]) || is_tex_ac(key.ac[1]) ||
        is_tex_ac(key.ac[2]) || is_tex_ac(key.ac[3])) {
        return true;
    }
    if (key.two_cycle) {
        if (is_tex_cc(key.cc1[0], false) || is_tex_cc(key.cc1[1], false) ||
            is_tex_cc(key.cc1[2], true)  || is_tex_cc(key.cc1[3], false) ||
            is_tex_ac(key.ac1[0]) || is_tex_ac(key.ac1[1]) ||
            is_tex_ac(key.ac1[2]) || is_tex_ac(key.ac1[3])) {
            return true;
        }
    }
    return false;
}

static uint64_t HashProgramKey(uint32_t gen_version, const char* renderer, const char* version, const CombinerKey& key) {
    uint64_t seed = 0x50315350ULL ^ static_cast<uint64_t>(gen_version);
    if (renderer) seed = XXH3_64bits_withSeed(renderer, std::strlen(renderer), seed);
    if (version) seed = XXH3_64bits_withSeed(version, std::strlen(version), seed);
    return XXH3_64bits_withSeed(&key, sizeof(CombinerKey), seed);
}

} // namespace

std::string GenerateFragmentShader(const CombinerKey& key) {
    UniformUsage usage{};
    const bool use_tex = (key.use_texture != 0);
    usage.sampler = reads_texture(key);
    usage.fog_params = (key.fog_geom != 0);
    usage.fog_color = (key.fog_blend != 0);
    usage.alpha_thresh = (key.alpha_mode == 1);

    const std::string c0_a = GetCCColorA(key.cc[0], 0, use_tex, usage);
    const std::string c0_b = GetCCColorB(key.cc[1], 0, use_tex, usage);
    const std::string c0_c = GetCCFactorC(key.cc[2], 0, use_tex, usage);
    const std::string c0_d = GetCCColorD(key.cc[3], 0, use_tex, usage);

    const std::string a0_a = GetACAbd(key.ac[0], 0, use_tex, usage);
    const std::string a0_b = GetACAbd(key.ac[1], 0, use_tex, usage);
    const std::string a0_c = GetACC(key.ac[2], 0, use_tex, usage);
    const std::string a0_d = GetACAbd(key.ac[3], 0, use_tex, usage);

    const std::string expr_rgb0 = EmitFormula(c0_a, c0_b, c0_c, c0_d, true);
    const std::string expr_a0   = EmitFormula(a0_a, a0_b, a0_c, a0_d, false);

    std::string expr_rgb1;
    std::string expr_a1;
    if (key.two_cycle) {
        const std::string c1_a = GetCCColorA(key.cc1[0], 1, use_tex, usage);
        const std::string c1_b = GetCCColorB(key.cc1[1], 1, use_tex, usage);
        const std::string c1_c = GetCCFactorC(key.cc1[2], 1, use_tex, usage);
        const std::string c1_d = GetCCColorD(key.cc1[3], 1, use_tex, usage);

        const std::string a1_a = GetACAbd(key.ac1[0], 1, use_tex, usage);
        const std::string a1_b = GetACAbd(key.ac1[1], 1, use_tex, usage);
        const std::string a1_c = GetACC(key.ac1[2], 1, use_tex, usage);
        const std::string a1_d = GetACAbd(key.ac1[3], 1, use_tex, usage);

        expr_rgb1 = EmitFormula(c1_a, c1_b, c1_c, c1_d, true);
        expr_a1   = EmitFormula(a1_a, a1_b, a1_c, a1_d, false);
    }

    std::string src = R"(precision mediump float;
#ifdef GL_FRAGMENT_PRECISION_HIGH
#define FRAG_HIGHP highp
#else
#define FRAG_HIGHP mediump
#endif
varying FRAG_HIGHP vec2 v_texcoord;
varying mediump vec4 v_color;
varying FRAG_HIGHP vec2 v_clip_zw;
)";

    if (usage.sampler) src += "uniform sampler2D u_sampler;\n";
    if (usage.prim) src += "uniform vec4 u_prim_color;\n";
    if (usage.env) src += "uniform vec4 u_env_color;\n";
    if (usage.fog_color) src += "uniform vec4 u_fog_color;\n";
    if (usage.lod_frac) src += "uniform float u_prim_lod_frac;\n";
    if (usage.alpha_thresh) src += "uniform float u_alpha_threshold;\n";
    if (usage.fog_params) src += "uniform vec2 u_fog_params;\n";

    src += "\nvoid main() {\n";
    if (usage.sampler) {
        src += "    vec4 tex = texture2D(u_sampler, v_texcoord);\n";
    }
    src += "    vec4 shade = v_color;\n";
    if (key.fog_geom) {
        src += "    float z_over_w = v_clip_zw.x / max(v_clip_zw.y, 1e-6);\n";
        src += "    shade.a = clamp(z_over_w * u_fog_params.x + u_fog_params.y, 0.0, 1.0);\n";
    }

    src += "    vec3 rgb0 = clamp(" + expr_rgb0 + ", 0.0, 1.0);\n";
    src += "    float alpha0 = clamp(" + expr_a0 + ", 0.0, 1.0);\n";

    if (key.two_cycle) {
        src += "    vec3 rgb = clamp(" + expr_rgb1 + ", 0.0, 1.0);\n";
        src += "    float alpha = clamp(" + expr_a1 + ", 0.0, 1.0);\n";
    } else {
        src += "    vec3 rgb = rgb0;\n";
        src += "    float alpha = alpha0;\n";
    }

    if (key.alpha_mode == 1) {
        src += "    if (alpha < u_alpha_threshold) {\n        discard;\n    }\n";
    } else if (key.alpha_mode == 2) {
        src += "    float dither = fract(sin(dot(gl_FragCoord.xy, vec2(12.9898, 78.233))) * 43758.5453);\n    if (alpha < dither) {\n        discard;\n    }\n";
    }

    if (key.fog_blend) {
        src += "    rgb = mix(rgb, u_fog_color.rgb, shade.a);\n";
    }

    src += "    gl_FragColor = vec4(rgb, alpha);\n}\n";
    return src;
}

F3DGLESMtx F3DGLESMtx::identity() {
    F3DGLESMtx res{};
    for (int i = 0; i < 4; ++i) {
        res.m[i][i] = 1.0f;
    }
    return res;
}

F3DGLESMtx F3DGLESMtx::multiply(const F3DGLESMtx& a, const F3DGLESMtx& b) {
    F3DGLESMtx res{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            float sum = 0.0f;
            for (int k = 0; k < 4; ++k) {
                sum += a.m[i][k] * b.m[k][j];
            }
            res.m[i][j] = sum;
        }
    }
    return res;
}

void F3DGLESMtx::load_fixed_point(const uint8_t* rdram, uint32_t address) {
    address &= kRDRAMAddressMask;
    if (!RdramRangeOk(address, 64U)) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                m[i][j] = (i == j) ? 1.0f : 0.0f;
            }
        }
        return;
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            const uint32_t idx = static_cast<uint32_t>((i * 4 + j) * 2);
            int16_t int_part = 0;
            uint16_t frac_part = 0;
            std::memcpy(&int_part, rdram + ((address + idx) ^ 2U), sizeof(int_part));
            std::memcpy(&frac_part, rdram + ((address + 32U + idx) ^ 2U), sizeof(frac_part));
            const int32_t fixed_val = static_cast<int32_t>(
                (static_cast<uint32_t>(static_cast<uint16_t>(int_part)) << 16U) |
                static_cast<uint32_t>(frac_part)
            );
            m[i][j] = static_cast<float>(fixed_val) / 65536.0f;
        }
    }
}

F3DDKRGLESBridge::F3DDKRGLESBridge() {
    batched_vertices_.reserve(4096);
    reset();
}

F3DDKRGLESBridge::~F3DDKRGLESBridge() {
    clear_texture_cache();
    if (vbo_ != 0) {
        glDeleteBuffers(1, &vbo_);
        vbo_ = 0;
    }
    for (auto& entry : programs_) {
        if (entry.second.id != 0) {
            glDeleteProgram(entry.second.id);
        }
    }
    programs_.clear();
    if (vertex_shader_ != 0) {
        glDeleteShader(vertex_shader_);
        vertex_shader_ = 0;
    }
    if (default_shader_ != 0) {
        glDeleteProgram(default_shader_);
        default_shader_ = 0;
    }
    if (dummy_white_texture_ != 0) {
        glDeleteTextures(1, &dummy_white_texture_);
        dummy_white_texture_ = 0;
    }
}

void F3DDKRGLESBridge::clear_texture_cache() {
    for (auto& entry : texture_cache_) {
        if (entry.second.id != 0) {
            glDeleteTextures(1, &entry.second.id);
        }
    }
    texture_cache_.clear();
}

#ifndef GL_PROGRAM_BINARY_LENGTH_OES
#define GL_PROGRAM_BINARY_LENGTH_OES 0x8741
#endif
#ifndef GL_NUM_PROGRAM_BINARY_FORMATS_OES
#define GL_NUM_PROGRAM_BINARY_FORMATS_OES 0x87FE
#endif
#ifndef GL_PROGRAM_BINARY_FORMATS_OES
#define GL_PROGRAM_BINARY_FORMATS_OES 0x87FF
#endif

#ifndef GL_APIENTRY
#ifdef _WIN32
#define GL_APIENTRY __stdcall
#else
#define GL_APIENTRY
#endif
#endif

typedef void (GL_APIENTRY *PfnGetProgramBinary)(GLuint, GLsizei, GLsizei*, GLenum*, void*);
typedef void (GL_APIENTRY *PfnProgramBinary)(GLuint, GLenum, const void*, GLint);

bool F3DDKRGLESBridge::try_load_cached_shader(GLuint program, const char* cache_path) {
    auto pfn_program_binary = reinterpret_cast<PfnProgramBinary>(SDL_GL_GetProcAddress("glProgramBinaryOES"));
    if (!pfn_program_binary) {
        pfn_program_binary = reinterpret_cast<PfnProgramBinary>(SDL_GL_GetProcAddress("glProgramBinary"));
    }
    if (!pfn_program_binary) return false;

    GLint num_formats = 0;
    glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS_OES, &num_formats);
    if (num_formats <= 0) return false;

    std::vector<GLint> formats(static_cast<size_t>(num_formats));
    glGetIntegerv(GL_PROGRAM_BINARY_FORMATS_OES, formats.data());

    FILE* f = std::fopen(cache_path, "rb");
    if (!f) return false;

    GLenum format = 0;
    if (std::fread(&format, sizeof(format), 1, f) != 1) {
        std::fclose(f);
        return false;
    }

    bool format_supported = false;
    for (GLint supported_fmt : formats) {
        if (static_cast<GLenum>(supported_fmt) == format) {
            format_supported = true;
            break;
        }
    }
    if (!format_supported) {
        std::fclose(f);
        return false;
    }

    std::fseek(f, 0, SEEK_END);
    long size = std::ftell(f) - static_cast<long>(sizeof(format));
    if (size <= 0) {
        std::fclose(f);
        return false;
    }
    std::fseek(f, sizeof(format), SEEK_SET);

    std::vector<uint8_t> buffer(size);
    if (std::fread(buffer.data(), 1, size, f) != static_cast<size_t>(size)) {
        std::fclose(f);
        return false;
    }
    std::fclose(f);

    pfn_program_binary(program, format, buffer.data(), static_cast<GLint>(size));
    GLint linked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    return linked != 0;
}

void F3DDKRGLESBridge::try_save_cached_shader(GLuint program, const char* cache_path) {
    auto pfn_get_program_binary = reinterpret_cast<PfnGetProgramBinary>(SDL_GL_GetProcAddress("glGetProgramBinaryOES"));
    if (!pfn_get_program_binary) {
        pfn_get_program_binary = reinterpret_cast<PfnGetProgramBinary>(SDL_GL_GetProcAddress("glGetProgramBinary"));
    }
    if (!pfn_get_program_binary) return;

    GLint length = 0;
    glGetProgramiv(program, GL_PROGRAM_BINARY_LENGTH_OES, &length);
    if (length <= 0) return;

    GLenum format = 0;
    std::vector<uint8_t> buffer(length);
    GLsizei written = 0;
    pfn_get_program_binary(program, length, &written, &format, buffer.data());
    if (written <= 0) return;

    char tmp_path[128];
    std::snprintf(tmp_path, sizeof(tmp_path), "%s.tmp", cache_path);
    FILE* f = std::fopen(tmp_path, "wb");
    if (f) {
        bool ok = true;
        if (std::fwrite(&format, sizeof(format), 1, f) != 1) ok = false;
        if (ok && std::fwrite(buffer.data(), 1, written, f) != static_cast<size_t>(written)) ok = false;
        std::fclose(f);
        if (ok) {
            std::rename(tmp_path, cache_path);
            std::fprintf(stderr, "[gles][shader] Saved binary shader cache (%d bytes) to %s\n", written, cache_path);
        } else {
            std::remove(tmp_path);
        }
    }
}

void F3DDKRGLESBridge::build_combiner_key(CombinerKey& key) const {
    std::memset(&key, 0, sizeof(CombinerKey));
    if (batch_.ovr == DrawOverride::CopyTexel) {
        key.cc[0] = 15; key.cc[1] = 15; key.cc[2] = 31; key.cc[3] = 1;
        key.ac[0] = 7;  key.ac[1] = 7;  key.ac[2] = 7;  key.ac[3] = 1;
        key.two_cycle = 0;
    } else if (batch_.ovr == DrawOverride::FillShade) {
        key.cc[0] = 15; key.cc[1] = 15; key.cc[2] = 31; key.cc[3] = 4;
        key.ac[0] = 7;  key.ac[1] = 7;  key.ac[2] = 7;  key.ac[3] = 4;
        key.two_cycle = 0;
    } else {
        key.two_cycle = (state_.cycle_type == 1) ? 1 : 0;
        key.cc[0] = state_.cc_a;
        key.cc[1] = state_.cc_b;
        key.cc[2] = state_.cc_c;
        key.cc[3] = state_.cc_d;
        key.ac[0] = state_.ac_a;
        key.ac[1] = state_.ac_b;
        key.ac[2] = state_.ac_c;
        key.ac[3] = state_.ac_d;
        if (key.two_cycle) {
            key.cc1[0] = state_.cc_a1;
            key.cc1[1] = state_.cc_b1;
            key.cc1[2] = state_.cc_c1;
            key.cc1[3] = state_.cc_d1;
            key.ac1[0] = state_.ac_a1;
            key.ac1[1] = state_.ac_b1;
            key.ac1[2] = state_.ac_c1;
            key.ac1[3] = state_.ac_d1;
        }
    }

    key.use_texture = (batch_.ovr == DrawOverride::FillShade || batch_.ovr == DrawOverride::Untextured)
        ? 0
        : (batch_.tex ? 1 : 0);
    key.alpha_mode = static_cast<uint8_t>(state_.alpha_mode);

    const bool is_rect = (batch_.kind == BatchKind::Rect2D);
    const bool fog_geom = !s_no_fog && !is_rect && ((state_.geometry_mode & 0x00010000U) != 0U);
    const bool fog_enabled = !s_no_fog && !is_rect && state_.fog_enabled && fog_geom;
    key.fog_geom = fog_geom ? 1 : 0;
    key.fog_blend = fog_enabled ? 1 : 0;

    normalize_key(key);
}

void F3DDKRGLESBridge::normalize_key(CombinerKey& key) const {
    if (!key.two_cycle) {
        std::memset(key.cc1, 0, sizeof(key.cc1));
        std::memset(key.ac1, 0, sizeof(key.ac1));
    }

    auto norm_cc_operand = [](uint8_t& val, bool is_factor_c) {
        if (is_factor_c) {
            if (val == 2) val = 1;
            if (val == 9) val = 8;
        } else {
            if (val == 2) val = 1;
        }
    };

    auto norm_ac_operand = [](uint8_t& val) {
        if (val == 2) val = 1;
    };

    norm_cc_operand(key.cc[0], false);
    norm_cc_operand(key.cc[1], false);
    norm_cc_operand(key.cc[2], true);
    norm_cc_operand(key.cc[3], false);

    norm_ac_operand(key.ac[0]);
    norm_ac_operand(key.ac[1]);
    norm_ac_operand(key.ac[2]);
    norm_ac_operand(key.ac[3]);

    if (key.two_cycle) {
        norm_cc_operand(key.cc1[0], false);
        norm_cc_operand(key.cc1[1], false);
        norm_cc_operand(key.cc1[2], true);
        norm_cc_operand(key.cc1[3], false);

        norm_ac_operand(key.ac1[0]);
        norm_ac_operand(key.ac1[1]);
        norm_ac_operand(key.ac1[2]);
        norm_ac_operand(key.ac1[3]);
    }

    if (!key.use_texture) {
        if (key.cc[0] == 1) key.cc[0] = 6;
        if (key.cc[3] == 1) key.cc[3] = 6;
        if (key.ac[0] == 1) key.ac[0] = 6;
        if (key.ac[1] == 1) key.ac[1] = 6;
        if (key.ac[3] == 1) key.ac[3] = 6;

        if (key.two_cycle) {
            if (key.cc1[0] == 1) key.cc1[0] = 6;
            if (key.cc1[3] == 1) key.cc1[3] = 6;
            if (key.ac1[0] == 1) key.ac1[0] = 6;
            if (key.ac1[1] == 1) key.ac1[1] = 6;
            if (key.ac1[3] == 1) key.ac1[3] = 6;
        }
    }

    key.pad[0] = 0;
    key.pad[1] = 0;
    key.pad[2] = 0;
}

ShaderProgram* F3DDKRGLESBridge::get_or_compile_program(const CombinerKey& key) {
    auto it = programs_.find(key);
    if (it != programs_.end()) {
        return &it->second;
    }

    if (vertex_shader_ == 0) {
        vertex_shader_ = CompileShader(GL_VERTEX_SHADER, kVertexShaderSource);
        if (vertex_shader_ == 0) return nullptr;
    }

    std::string frag_src = GenerateFragmentShader(key);
    GLuint prog_id = glCreateProgram();
    if (prog_id == 0) return nullptr;

    const char* renderer = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
    const char* version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    const uint64_t prog_hash = HashProgramKey(kShaderGenVersion, renderer, version, key);
    char cache_path[64];
    std::snprintf(cache_path, sizeof(cache_path), "shader_cache_%016llx.bin", static_cast<unsigned long long>(prog_hash));

    bool loaded = try_load_cached_shader(prog_id, cache_path);
    if (loaded) {
        GLint pos_loc = glGetAttribLocation(prog_id, "a_position");
        GLint tex_loc = glGetAttribLocation(prog_id, "a_texcoord");
        GLint col_loc = glGetAttribLocation(prog_id, "a_color");
        if ((pos_loc != 0 && pos_loc != -1) || (tex_loc != 1 && tex_loc != -1) || (col_loc != 2 && col_loc != -1)) {
            std::fprintf(stderr, "[gles][shader] cached binary has wrong attrib locations (pos=%d, tex=%d, col=%d), recompiling: %s\n",
                         pos_loc, tex_loc, col_loc, cache_path);
            glDeleteProgram(prog_id);
            prog_id = glCreateProgram();
            loaded = false;
        } else {
            static bool s_logged_cached_spec = false;
            if (!s_logged_cached_spec) {
                s_logged_cached_spec = true;
                std::fprintf(stderr, "[gles][shader] loaded specialized program from binary cache: %s\n", cache_path);
            }
        }
    }
    if (!loaded) {
        GLuint frag_shader = CompileShader(GL_FRAGMENT_SHADER, frag_src.c_str());
        if (frag_shader == 0) {
            static bool s_logged_compile_fail = false;
            if (!s_logged_compile_fail) {
                s_logged_compile_fail = true;
                std::fprintf(stderr, "[gles][shader] Failed to compile specialized fragment shader. GLSL:\n%s\n", frag_src.c_str());
            }
            glDeleteProgram(prog_id);
            return nullptr;
        }

        glAttachShader(prog_id, vertex_shader_);
        glAttachShader(prog_id, frag_shader);

        glBindAttribLocation(prog_id, 0, "a_position");
        glBindAttribLocation(prog_id, 1, "a_texcoord");
        glBindAttribLocation(prog_id, 2, "a_color");

        glLinkProgram(prog_id);
        glDeleteShader(frag_shader);

        GLint linked = 0;
        glGetProgramiv(prog_id, GL_LINK_STATUS, &linked);
        if (!linked) {
            char log[512];
            glGetProgramInfoLog(prog_id, sizeof(log), nullptr, log);
            static bool s_logged_link_fail = false;
            if (!s_logged_link_fail) {
                s_logged_link_fail = true;
                std::fprintf(stderr, "[gles][shader] Specialized program link error: %s\nGLSL:\n%s\n", log, frag_src.c_str());
            }
            glDeleteProgram(prog_id);
            return nullptr;
        }

        try_save_cached_shader(prog_id, cache_path);
    }

    ShaderProgram prog{};
    prog.id = prog_id;
    prog.u_prim = glGetUniformLocation(prog_id, "u_prim_color");
    prog.u_env = glGetUniformLocation(prog_id, "u_env_color");
    prog.u_fog_color = glGetUniformLocation(prog_id, "u_fog_color");
    prog.u_lod_frac = glGetUniformLocation(prog_id, "u_prim_lod_frac");
    prog.u_alpha_thresh = glGetUniformLocation(prog_id, "u_alpha_threshold");
    prog.u_fog_params = glGetUniformLocation(prog_id, "u_fog_params");
    prog.u_sampler = glGetUniformLocation(prog_id, "u_sampler");

    if (prog.u_sampler >= 0) {
        glUseProgram(prog_id);
        glUniform1i(prog.u_sampler, 0);
        gl_current_program_ = prog_id;
        use_program_count_++;
    }

    auto [inserted_it, _] = programs_.emplace(key, prog);

    if (known_keys_.size() < 256) {
        if (std::find(known_keys_.begin(), known_keys_.end(), key) == known_keys_.end()) {
            known_keys_.push_back(key);
            FILE* f = std::fopen("shader_keys.bin", "ab");
            if (f) {
                std::fwrite(&key, sizeof(CombinerKey), 1, f);
                std::fclose(f);
            }
        }
    }

    return &inserted_it->second;
}

void F3DDKRGLESBridge::init() {
    if (initialized_) return;

    const char* ubershader_env = std::getenv("DKR_GLES_UBERSHADER");
    use_ubershader_ = (ubershader_env && std::strcmp(ubershader_env, "1") == 0);
    if (use_ubershader_) {
        std::fprintf(stderr, "[gles][shader] DKR_GLES_UBERSHADER=1: using monolithic uber-shader fallback\n");
    }

    vertex_shader_ = CompileShader(GL_VERTEX_SHADER, kVertexShaderSource);

    default_shader_ = glCreateProgram();
    char cache_path[64];
    const char* renderer = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
    const char* version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    const uint64_t shader_hash = HashShaderSource(kVertexShaderSource, kFragmentShaderSource, renderer, version);
    std::snprintf(cache_path, sizeof(cache_path), "shader_cache_%016llx.bin", static_cast<unsigned long long>(shader_hash));
    bool loaded = try_load_cached_shader(default_shader_, cache_path);
    if (loaded) {
        GLint pos_loc = glGetAttribLocation(default_shader_, "a_position");
        GLint tex_loc = glGetAttribLocation(default_shader_, "a_texcoord");
        GLint col_loc = glGetAttribLocation(default_shader_, "a_color");
        if ((pos_loc != 0 && pos_loc != -1) || (tex_loc != 1 && tex_loc != -1) || (col_loc != 2 && col_loc != -1)) {
            std::fprintf(stderr, "[gles][shader] cached binary has wrong attrib locations (pos=%d, tex=%d, col=%d), recompiling: %s\n",
                         pos_loc, tex_loc, col_loc, cache_path);
            glDeleteProgram(default_shader_);
            default_shader_ = glCreateProgram();
            loaded = false;
        }
    }
    if (!loaded) {
        GLuint frag = CompileShader(GL_FRAGMENT_SHADER, kFragmentShaderSource);
        bool link_ok = false;
        if (vertex_shader_ != 0 && frag != 0) {
            glAttachShader(default_shader_, vertex_shader_);
            glAttachShader(default_shader_, frag);
            glBindAttribLocation(default_shader_, 0, "a_position");
            glBindAttribLocation(default_shader_, 1, "a_texcoord");
            glBindAttribLocation(default_shader_, 2, "a_color");
            glLinkProgram(default_shader_);
            glDeleteShader(frag);

            GLint linked = 0;
            glGetProgramiv(default_shader_, GL_LINK_STATUS, &linked);
            if (!linked) {
                char log[512];
                glGetProgramInfoLog(default_shader_, sizeof(log), nullptr, log);
                static bool s_link_err_logged = false;
                if (!s_link_err_logged) {
                    s_link_err_logged = true;
                    std::fprintf(stderr, "[gles][shader] program link error: %s\n", log);
                }
            } else {
                link_ok = true;
                try_save_cached_shader(default_shader_, cache_path);
            }
        }
        if (!link_ok) {
            glDeleteProgram(default_shader_);
            default_shader_ = 0;
        }
    } else {
        std::fprintf(stderr, "[gles][shader] loaded program from binary cache: %s\n", cache_path);
    }

    a_pos_loc_ = 0;
    a_tex_loc_ = 1;
    a_col_loc_ = 2;

    if (default_shader_ != 0) {
        u_prim_color_loc_ = glGetUniformLocation(default_shader_, "u_prim_color");
        u_env_color_loc_ = glGetUniformLocation(default_shader_, "u_env_color");
        u_fog_color_loc_ = glGetUniformLocation(default_shader_, "u_fog_color");
        u_use_texture_loc_ = glGetUniformLocation(default_shader_, "u_use_texture");
        u_cycle_type_loc_ = glGetUniformLocation(default_shader_, "u_cycle_type");
        u_prim_lod_frac_loc_ = glGetUniformLocation(default_shader_, "u_prim_lod_frac");
        u_alpha_test_loc_ = glGetUniformLocation(default_shader_, "u_alpha_test");
        u_alpha_threshold_loc_ = glGetUniformLocation(default_shader_, "u_alpha_threshold");
        u_fog_enabled_loc_ = glGetUniformLocation(default_shader_, "u_fog_enabled");
        u_fog_geom_loc_ = glGetUniformLocation(default_shader_, "u_fog_geom");
        u_fog_params_loc_ = glGetUniformLocation(default_shader_, "u_fog_params");
        u_sampler_loc_ = glGetUniformLocation(default_shader_, "u_sampler");

        u_cc_a_loc_ = glGetUniformLocation(default_shader_, "u_cc_a");
        u_cc_b_loc_ = glGetUniformLocation(default_shader_, "u_cc_b");
        u_cc_c_loc_ = glGetUniformLocation(default_shader_, "u_cc_c");
        u_cc_d_loc_ = glGetUniformLocation(default_shader_, "u_cc_d");
        u_ac_a_loc_ = glGetUniformLocation(default_shader_, "u_ac_a");
        u_ac_b_loc_ = glGetUniformLocation(default_shader_, "u_ac_b");
        u_ac_c_loc_ = glGetUniformLocation(default_shader_, "u_ac_c");
        u_ac_d_loc_ = glGetUniformLocation(default_shader_, "u_ac_d");

        u_cc_a1_loc_ = glGetUniformLocation(default_shader_, "u_cc_a1");
        u_cc_b1_loc_ = glGetUniformLocation(default_shader_, "u_cc_b1");
        u_cc_c1_loc_ = glGetUniformLocation(default_shader_, "u_cc_c1");
        u_cc_d1_loc_ = glGetUniformLocation(default_shader_, "u_cc_d1");
        u_ac_a1_loc_ = glGetUniformLocation(default_shader_, "u_ac_a1");
        u_ac_b1_loc_ = glGetUniformLocation(default_shader_, "u_ac_b1");
        u_ac_c1_loc_ = glGetUniformLocation(default_shader_, "u_ac_c1");
        u_ac_d1_loc_ = glGetUniformLocation(default_shader_, "u_ac_d1");
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    attribs_enabled_ = true;

    // 1x1 white texture for untextured drawing
    glGenTextures(1, &dummy_white_texture_);
    glBindTexture(GL_TEXTURE_2D, dummy_white_texture_);
    const uint32_t white_pixel = 0xFFFFFFFFU;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, &white_pixel);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if (default_shader_ != 0) {
        glUseProgram(default_shader_);
        if (u_sampler_loc_ >= 0) {
            glUniform1i(u_sampler_loc_, 0);
        }
    }

    // Warm-up specialized shaders from shader_keys.bin
    FILE* fk = std::fopen("shader_keys.bin", "rb");
    if (fk) {
        CombinerKey k;
        while (known_keys_.size() < 256 && std::fread(&k, sizeof(CombinerKey), 1, fk) == 1) {
            known_keys_.push_back(k);
        }
        std::fclose(fk);
        for (const auto& key : known_keys_) {
            get_or_compile_program(key);
        }
        if (!known_keys_.empty()) {
            std::fprintf(stderr, "[gles][shader] Warmed up %zu specialized shaders from shader_keys.bin\n", known_keys_.size());
        }
    }

    gl_viewport_x_ = -1;
    gl_viewport_y_ = -1;
    gl_viewport_w_ = -1;
    gl_viewport_h_ = -1;
    gl_depth_test_ = -1;
    gl_depth_func_ = 0;
    gl_depth_mask_ = -1;
    gl_blend_ = -1;
    gl_blend_additive_ = -1;
    gl_scissor_test_ = -1;
    gl_scissor_x_ = -1; gl_scissor_y_ = -1; gl_scissor_w_ = -1; gl_scissor_h_ = -1;
    gl_bound_texture_ = 0xFFFFFFFF;
    gl_polygon_offset_ = -1;
    gl_current_program_ = 0xFFFFFFFF;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_BLEND);

    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    initialized_ = true;
    std::fprintf(stderr, "[gles][f3ddkr] initialized shaders, GL state, and texture cache (set DKR_GLES_GL_ERRORS=1 for GL error logging)\n");
}

void F3DDKRGLESBridge::reset() {
    state_ = F3DGLESState{};
    state_.viewport_x = 0;
    state_.viewport_y = 0;
    state_.viewport_w = target_w_;
    state_.viewport_h = target_h_;
    state_.scissor_ulx = 0;
    state_.scissor_uly = 0;
    state_.scissor_lrx = n64_fb_w_;
    state_.scissor_lry = n64_fb_h_;
    state_.tmem_source_addr.fill(0);
    state_.tmem_loaded_bytes.fill(0);
    state_.tmem_line_swapped.fill(0);
    state_.tlut_type = 2;
    state_.last_tlut_address = 0;
    state_.color_image_address = 0xFFFFFFFFU;
    state_.depth_image_address = 0xEEEEEEEEU;
    state_.color_image_size = 2;
    state_.fill_color_raw = 0;
    batch_ = BatchState{};
    last_flushed_ovr_ = static_cast<DrawOverride>(0xFF);
    last_flushed_kind_ = static_cast<BatchKind>(0xFF);
    last_flushed_tex_en_ = -1;
    state_.cc_a = 1;
    state_.cc_b = 15;
    state_.cc_c = 4;
    state_.cc_d = 7;
    state_.ac_a = 1;
    state_.ac_b = 7;
    state_.ac_c = 4;
    state_.ac_d = 7;
    state_.cc_a1 = 0;
    state_.cc_b1 = 0;
    state_.cc_c1 = 0;
    state_.cc_d1 = 1;
    state_.ac_a1 = 0;
    state_.ac_b1 = 0;
    state_.ac_c1 = 0;
    state_.ac_d1 = 1;
    state_.prim_lod_frac = 0.0f;
    for (auto& m : state_.modelview_stack) {
        m = F3DGLESMtx::identity();
    }
    state_.tmem_slot_hash.fill(0);
    state_.dirty_uniforms = DIRTY_UNIFORM_ALL;
    state_.scissor_test_enabled = false;
    state_.blend_enabled = false;
    state_.blend_additive = false;
    state_.prim_rgba8[0] = 255;
    state_.prim_rgba8[1] = 255;
    state_.prim_rgba8[2] = 255;
    state_.prim_rgba8[3] = 255;
    batched_vertices_.clear();
    la8_buf_.clear();

    dl_budget_ = 0;
    dl_recursion_depth_ = 0;
    dl_abort_ = false;
    dl_unexpected_opcode_seen_ = false;
    dl_history_idx_ = 0;
    dl_history_count_ = 0;
    dl_history_.fill({0, 0});
}

void F3DDKRGLESBridge::record_dl_history(uint32_t raw, uint32_t resolved) {
    dl_history_[dl_history_idx_] = {raw, resolved};
    dl_history_idx_ = (dl_history_idx_ + 1U) % dl_history_.size();
    if (dl_history_count_ < dl_history_.size()) {
        ++dl_history_count_;
    }
}

void F3DDKRGLESBridge::handle_unexpected_opcode(uint8_t opcode, uint32_t address) {
    dl_abort_ = true;
    state_.dl_stack.clear();

    if (!dl_unexpected_opcode_seen_) {
        dl_unexpected_opcode_seen_ = true;
        static uint32_t s_unexpected_opcode_logs = 0;
        if (s_unexpected_opcode_logs < 5) {
            ++s_unexpected_opcode_logs;
            std::string ring_str = "<";
            const size_t count = dl_history_count_;
            const size_t start = (dl_history_count_ < dl_history_.size()) ? 0 : dl_history_idx_;
            for (size_t i = 0; i < count; ++i) {
                const auto& ent = dl_history_[(start + i) % dl_history_.size()];
                char buf[64];
                std::snprintf(buf, sizeof(buf), "%s0x%08X->0x%08X", (i > 0 ? ", " : ""), ent.raw, ent.resolved);
                ring_str += buf;
            }
            ring_str += ">";

            std::fprintf(stderr, "[gles][dl] unexpected opcode 0x%02X at 0x%08X via %s\n", opcode, address, ring_str.c_str());
            std::fprintf(stderr, "[gles][dl] segments:");
            for (size_t i = 0; i < 16; ++i) {
                std::fprintf(stderr, " %02zu:0x%08X", i, state_.segments[i]);
            }
            std::fprintf(stderr, "\n");
        }
    }
}

void F3DDKRGLESBridge::set_viewport(int x, int y, int width, int height) {
    state_.viewport_x = x;
    state_.viewport_y = y;
    state_.viewport_w = width;
    state_.viewport_h = height;
    if (batch_.kind == BatchKind::Tri3D) {
        if (gl_viewport_x_ != x || gl_viewport_y_ != y || gl_viewport_w_ != width || gl_viewport_h_ != height) {
            glViewport(x, y, width, height);
            gl_viewport_x_ = x;
            gl_viewport_y_ = y;
            gl_viewport_w_ = width;
            gl_viewport_h_ = height;
        }
    }
}

void F3DDKRGLESBridge::set_target_size(int w, int h) {
    target_w_ = w;
    target_h_ = h;
    invalidate_gl_cache();
}

void F3DDKRGLESBridge::set_window_size(int w, int h) {
    set_target_size(w, h);
}

void F3DDKRGLESBridge::invalidate_gl_cache() {
    gl_viewport_x_ = -1;
    gl_viewport_y_ = -1;
    gl_viewport_w_ = -1;
    gl_viewport_h_ = -1;
    gl_scissor_x_ = -1;
    gl_scissor_y_ = -1;
    gl_scissor_w_ = -1;
    gl_scissor_h_ = -1;
    gl_scissor_test_ = -1;
    gl_depth_test_ = -1;
    gl_depth_func_ = 0;
    gl_depth_mask_ = -1;
    gl_blend_ = -1;
    gl_blend_additive_ = -1;
    gl_bound_texture_ = 0xFFFFFFFF;
    gl_polygon_offset_ = -1;
    gl_current_program_ = 0xFFFFFFFF;
    last_flushed_ovr_ = static_cast<DrawOverride>(0xFF);
    last_flushed_kind_ = static_cast<BatchKind>(0xFF);
    last_flushed_tex_en_ = -1;
    attribs_enabled_ = false;
}

uint32_t F3DDKRGLESBridge::resolve_segmented_address(uint32_t addr) const {
    const uint32_t segment = (addr >> 24U) & 0x0FU;
    const uint32_t offset = addr & 0x00FFFFFFU;
    return (state_.segments[segment] + offset) & kRDRAMAddressMask;
}

void F3DDKRGLESBridge::apply_deferred_gl_state() {
    const bool is_rect = (batch_.kind == BatchKind::Rect2D);

    // Depth test and func
    const int8_t desired_depth_test = (!is_rect && (state_.depth_test_enabled || state_.depth_write_enabled)) ? 1 : 0;
    if (gl_depth_test_ != desired_depth_test) {
        if (desired_depth_test) glEnable(GL_DEPTH_TEST);
        else glDisable(GL_DEPTH_TEST);
        gl_depth_test_ = desired_depth_test;
    }
    if (desired_depth_test) {
        const GLenum desired_depth_func = state_.depth_test_enabled ? GL_LEQUAL : GL_ALWAYS;
        if (gl_depth_func_ != desired_depth_func) {
            glDepthFunc(desired_depth_func);
            gl_depth_func_ = desired_depth_func;
        }
    }
    const int8_t desired_depth_mask = (!is_rect && state_.depth_write_enabled) ? 1 : 0;
    if (gl_depth_mask_ != desired_depth_mask) {
        glDepthMask(desired_depth_mask ? GL_TRUE : GL_FALSE);
        gl_depth_mask_ = desired_depth_mask;
    }

    // Decal depth mode (glPolygonOffset) (Phase 3.3)
    const int8_t desired_polygon_offset = (!is_rect && state_.decal_mode) ? 1 : 0;
    if (gl_polygon_offset_ != desired_polygon_offset) {
        if (desired_polygon_offset) {
            glEnable(GL_POLYGON_OFFSET_FILL);
            glPolygonOffset(-1.0f, -1.0f);
        } else {
            glDisable(GL_POLYGON_OFFSET_FILL);
        }
        gl_polygon_offset_ = desired_polygon_offset;
    }

    // Blending
    const bool effective_blend = (batch_.ovr == DrawOverride::CopyTexel || batch_.ovr == DrawOverride::FillShade)
        ? false
        : state_.blend_enabled;
    const int8_t desired_blend = effective_blend ? 1 : 0;
    if (gl_blend_ != desired_blend) {
        if (desired_blend) glEnable(GL_BLEND);
        else glDisable(GL_BLEND);
        gl_blend_ = desired_blend;
    }
    if (desired_blend) {
        const int desired_additive = state_.blend_additive ? 1 : 0;
        if (gl_blend_additive_ != desired_additive) {
            if (desired_additive == 1) {
                glBlendFunc(GL_SRC_ALPHA, GL_ONE);
            } else {
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            }
            gl_blend_additive_ = desired_additive;
        }
    }

    // Scissor test
    const int8_t desired_scissor_test = state_.scissor_test_enabled ? 1 : 0;
    if (gl_scissor_test_ != desired_scissor_test) {
        if (desired_scissor_test) glEnable(GL_SCISSOR_TEST);
        else glDisable(GL_SCISSOR_TEST);
        gl_scissor_test_ = desired_scissor_test;
    }
    if (state_.scissor_test_enabled) {
        const float scale_x = static_cast<float>(target_w_) / static_cast<float>(n64_fb_w_);
        const float scale_y = static_cast<float>(target_h_) / static_cast<float>(n64_fb_h_);
        const int sx = static_cast<int>(state_.scissor_ulx * scale_x);
        const int sy = static_cast<int>((static_cast<float>(n64_fb_h_) - state_.scissor_lry) * scale_y);
        const int sw = static_cast<int>((state_.scissor_lrx - state_.scissor_ulx) * scale_x);
        const int sh = static_cast<int>((state_.scissor_lry - state_.scissor_uly) * scale_y);
        if (sx != gl_scissor_x_ || sy != gl_scissor_y_ || sw != gl_scissor_w_ || sh != gl_scissor_h_) {
            glScissor(sx, sy, sw, sh);
            gl_scissor_x_ = sx; gl_scissor_y_ = sy; gl_scissor_w_ = sw; gl_scissor_h_ = sh;
        }
    }

    // Viewport
    const int vp_x = is_rect ? 0 : state_.viewport_x;
    const int vp_y = is_rect ? 0 : state_.viewport_y;
    const int vp_w = is_rect ? target_w_ : state_.viewport_w;
    const int vp_h = is_rect ? target_h_ : state_.viewport_h;
    if (vp_x != gl_viewport_x_ || vp_y != gl_viewport_y_ ||
        vp_w != gl_viewport_w_ || vp_h != gl_viewport_h_) {
        glViewport(vp_x, vp_y, vp_w, vp_h);
        gl_viewport_x_ = vp_x; gl_viewport_y_ = vp_y;
        gl_viewport_w_ = vp_w; gl_viewport_h_ = vp_h;
    }
}

void F3DDKRGLESBridge::update_tile_params(F3DGLESTile& t) {
    if (!t.params_dirty) return;
    compute_tile_dims(t, t.cached_tile_w, t.cached_tile_h);

    float scale_s = 1.0f / (32.0f * static_cast<float>(t.cached_tile_w));
    if (t.shift_s > 0 && t.shift_s <= 10) {
        scale_s /= static_cast<float>(1U << t.shift_s);
    } else if (t.shift_s > 10) {
        scale_s *= static_cast<float>(1U << (16U - t.shift_s));
    }

    float scale_t = 1.0f / (32.0f * static_cast<float>(t.cached_tile_h));
    if (t.shift_t > 0 && t.shift_t <= 10) {
        scale_t /= static_cast<float>(1U << t.shift_t);
    } else if (t.shift_t > 10) {
        scale_t *= static_cast<float>(1U << (16U - t.shift_t));
    }

    t.cached_scale_s = scale_s;
    t.cached_scale_t = scale_t;
    t.cached_s_offset = static_cast<float>(t.sl) * 8.0f;
    t.cached_t_offset = static_cast<float>(t.tl) * 8.0f;
    t.params_dirty = false;
}

void F3DDKRGLESBridge::invalidate_tmem_hashes(uint32_t write_start, uint32_t write_bytes) {
    if (write_bytes == 0) return;
    const uint32_t write_end = write_start + write_bytes;
    for (size_t i = 0; i < 512; ++i) {
        const uint32_t slot_start = static_cast<uint32_t>(i * 8U);
        const uint32_t slot_len = state_.tmem_loaded_bytes[i] ? state_.tmem_loaded_bytes[i] : 8U;
        const uint32_t slot_end = slot_start + slot_len;
        if (!(slot_end <= write_start || slot_start >= write_end)) {
            state_.tmem_slot_hash[i] = 0;
        }
    }
}

void F3DDKRGLESBridge::begin_primitives(BatchKind kind, DrawOverride ovr, bool tex, GLuint tex_id, FlushReason why) {
    BatchState next{kind, ovr, tex, tex_id};
    if (!batched_vertices_.empty() && batch_ != next) {
        FlushReason reason = why;
        if (batch_.kind != next.kind) {
            reason = FlushReason::BatchKind;
        } else if (batch_.tex != next.tex) {
            reason = FlushReason::TexEnable;
        } else if (batch_.tex_id != next.tex_id) {
            reason = FlushReason::Texture;
        }
        flush_batch(reason);
    }
    batch_ = next;
}

void F3DDKRGLESBridge::flush_batch(FlushReason why) {
    if (batched_vertices_.empty()) return;
    flush_reasons_[static_cast<size_t>(why)]++;
    if (default_shader_ == 0) {
        batched_vertices_.clear();
        return;
    }

    apply_deferred_gl_state();

    ShaderProgram* prog = nullptr;
    if (!use_ubershader_) {
        CombinerKey key;
        build_combiner_key(key);
        prog = get_or_compile_program(key);
    }

    if (prog && prog->id != 0) {
        if (gl_current_program_ != prog->id) {
            glUseProgram(prog->id);
            gl_current_program_ = prog->id;
            use_program_count_++;
        }

        if (prog->u_prim >= 0) {
            if (!prog->uploaded_once || std::memcmp(prog->prim, state_.prim_color, sizeof(prog->prim)) != 0) {
                glUniform4fv(prog->u_prim, 1, state_.prim_color);
                std::memcpy(prog->prim, state_.prim_color, sizeof(prog->prim));
                uniform_upload_count_++;
            }
        }
        if (prog->u_env >= 0) {
            if (!prog->uploaded_once || std::memcmp(prog->env, state_.env_color, sizeof(prog->env)) != 0) {
                glUniform4fv(prog->u_env, 1, state_.env_color);
                std::memcpy(prog->env, state_.env_color, sizeof(prog->env));
                uniform_upload_count_++;
            }
        }
        if (prog->u_fog_color >= 0) {
            if (!prog->uploaded_once || std::memcmp(prog->fog_color, state_.fog_color, sizeof(prog->fog_color)) != 0) {
                glUniform4fv(prog->u_fog_color, 1, state_.fog_color);
                std::memcpy(prog->fog_color, state_.fog_color, sizeof(prog->fog_color));
                uniform_upload_count_++;
            }
        }
        if (prog->u_lod_frac >= 0) {
            if (!prog->uploaded_once || prog->lod_frac != state_.prim_lod_frac) {
                glUniform1f(prog->u_lod_frac, state_.prim_lod_frac);
                prog->lod_frac = state_.prim_lod_frac;
                uniform_upload_count_++;
            }
        }
        if (prog->u_alpha_thresh >= 0) {
            if (!prog->uploaded_once || prog->alpha_thresh != state_.alpha_threshold) {
                glUniform1f(prog->u_alpha_thresh, state_.alpha_threshold);
                prog->alpha_thresh = state_.alpha_threshold;
                uniform_upload_count_++;
            }
        }
        if (prog->u_fog_params >= 0) {
            float cur_fog[2] = {
                s_no_fog ? 0.0f : static_cast<float>(state_.fog_mul) / 256.0f,
                s_no_fog ? 0.0f : static_cast<float>(state_.fog_off) / 256.0f
            };
            if (!prog->uploaded_once || std::memcmp(prog->fog_params, cur_fog, sizeof(cur_fog)) != 0) {
                glUniform2f(prog->u_fog_params, cur_fog[0], cur_fog[1]);
                std::memcpy(prog->fog_params, cur_fog, sizeof(cur_fog));
                uniform_upload_count_++;
            }
        }
        prog->uploaded_once = true;

        last_flushed_ovr_ = batch_.ovr;
        last_flushed_kind_ = batch_.kind;
        last_flushed_tex_en_ = batch_.tex ? 1 : 0;
    } else {
        if (gl_current_program_ != default_shader_) {
            glUseProgram(default_shader_);
            gl_current_program_ = default_shader_;
            use_program_count_++;
            state_.dirty_uniforms = DIRTY_UNIFORM_ALL;
        }

        const int effective_use_tex = batch_.tex ? 1 : 0;
        const bool need_uniform_update = (state_.dirty_uniforms != DIRTY_UNIFORM_NONE)
            || (last_flushed_ovr_ != batch_.ovr)
            || (last_flushed_tex_en_ != effective_use_tex)
            || (last_flushed_kind_ != batch_.kind);

        if (need_uniform_update) {
            if (state_.dirty_uniforms & DIRTY_UNIFORM_PRIM_COLOR) {
                if (u_prim_color_loc_ >= 0) { glUniform4fv(u_prim_color_loc_, 1, state_.prim_color); uniform_upload_count_++; }
                state_.dirty_uniforms &= ~DIRTY_UNIFORM_PRIM_COLOR;
            }
            if (state_.dirty_uniforms & DIRTY_UNIFORM_ENV_COLOR) {
                if (u_env_color_loc_ >= 0) { glUniform4fv(u_env_color_loc_, 1, state_.env_color); uniform_upload_count_++; }
                state_.dirty_uniforms &= ~DIRTY_UNIFORM_ENV_COLOR;
            }
            if (state_.dirty_uniforms & DIRTY_UNIFORM_FOG_COLOR) {
                if (u_fog_color_loc_ >= 0) { glUniform4fv(u_fog_color_loc_, 1, state_.fog_color); uniform_upload_count_++; }
                state_.dirty_uniforms &= ~DIRTY_UNIFORM_FOG_COLOR;
            }
            if (last_flushed_tex_en_ != effective_use_tex || (state_.dirty_uniforms & DIRTY_UNIFORM_TEXTURE_EN)) {
                if (u_use_texture_loc_ >= 0) { glUniform1i(u_use_texture_loc_, effective_use_tex); uniform_upload_count_++; }
                last_flushed_tex_en_ = static_cast<int8_t>(effective_use_tex);
                state_.dirty_uniforms &= ~DIRTY_UNIFORM_TEXTURE_EN;
            }
            const bool combiner_dirty = (state_.dirty_uniforms & DIRTY_UNIFORM_COMBINER) || (last_flushed_ovr_ != batch_.ovr);
            if (combiner_dirty) {
                if (batch_.ovr == DrawOverride::CopyTexel) {
                    if (u_cycle_type_loc_ >= 0) { glUniform1i(u_cycle_type_loc_, 0); uniform_upload_count_++; }
                    if (u_prim_lod_frac_loc_ >= 0) { glUniform1f(u_prim_lod_frac_loc_, 0.0f); uniform_upload_count_++; }
                    if (u_cc_a_loc_ >= 0) { glUniform1i(u_cc_a_loc_, 15); uniform_upload_count_++; }
                    if (u_cc_b_loc_ >= 0) { glUniform1i(u_cc_b_loc_, 15); uniform_upload_count_++; }
                    if (u_cc_c_loc_ >= 0) { glUniform1i(u_cc_c_loc_, 31); uniform_upload_count_++; }
                    if (u_cc_d_loc_ >= 0) { glUniform1i(u_cc_d_loc_, 1); uniform_upload_count_++; }
                    if (u_ac_a_loc_ >= 0) { glUniform1i(u_ac_a_loc_, 7); uniform_upload_count_++; }
                    if (u_ac_b_loc_ >= 0) { glUniform1i(u_ac_b_loc_, 7); uniform_upload_count_++; }
                    if (u_ac_c_loc_ >= 0) { glUniform1i(u_ac_c_loc_, 7); uniform_upload_count_++; }
                    if (u_ac_d_loc_ >= 0) { glUniform1i(u_ac_d_loc_, 1); uniform_upload_count_++; }
                } else if (batch_.ovr == DrawOverride::FillShade) {
                    if (u_cycle_type_loc_ >= 0) { glUniform1i(u_cycle_type_loc_, 0); uniform_upload_count_++; }
                    if (u_prim_lod_frac_loc_ >= 0) { glUniform1f(u_prim_lod_frac_loc_, 0.0f); uniform_upload_count_++; }
                    if (u_cc_a_loc_ >= 0) { glUniform1i(u_cc_a_loc_, 15); uniform_upload_count_++; }
                    if (u_cc_b_loc_ >= 0) { glUniform1i(u_cc_b_loc_, 15); uniform_upload_count_++; }
                    if (u_cc_c_loc_ >= 0) { glUniform1i(u_cc_c_loc_, 31); uniform_upload_count_++; }
                    if (u_cc_d_loc_ >= 0) { glUniform1i(u_cc_d_loc_, 4); uniform_upload_count_++; }
                    if (u_ac_a_loc_ >= 0) { glUniform1i(u_ac_a_loc_, 7); uniform_upload_count_++; }
                    if (u_ac_b_loc_ >= 0) { glUniform1i(u_ac_b_loc_, 7); uniform_upload_count_++; }
                    if (u_ac_c_loc_ >= 0) { glUniform1i(u_ac_c_loc_, 7); uniform_upload_count_++; }
                    if (u_ac_d_loc_ >= 0) { glUniform1i(u_ac_d_loc_, 4); uniform_upload_count_++; }
                } else {
                    if (u_cycle_type_loc_ >= 0) { glUniform1i(u_cycle_type_loc_, state_.cycle_type); uniform_upload_count_++; }
                    if (u_prim_lod_frac_loc_ >= 0) { glUniform1f(u_prim_lod_frac_loc_, state_.prim_lod_frac); uniform_upload_count_++; }
                    if (u_cc_a_loc_ >= 0) { glUniform1i(u_cc_a_loc_, state_.cc_a); uniform_upload_count_++; }
                    if (u_cc_b_loc_ >= 0) { glUniform1i(u_cc_b_loc_, state_.cc_b); uniform_upload_count_++; }
                    if (u_cc_c_loc_ >= 0) { glUniform1i(u_cc_c_loc_, state_.cc_c); uniform_upload_count_++; }
                    if (u_cc_d_loc_ >= 0) { glUniform1i(u_cc_d_loc_, state_.cc_d); uniform_upload_count_++; }
                    if (u_ac_a_loc_ >= 0) { glUniform1i(u_ac_a_loc_, state_.ac_a); uniform_upload_count_++; }
                    if (u_ac_b_loc_ >= 0) { glUniform1i(u_ac_b_loc_, state_.ac_b); uniform_upload_count_++; }
                    if (u_ac_c_loc_ >= 0) { glUniform1i(u_ac_c_loc_, state_.ac_c); uniform_upload_count_++; }
                    if (u_ac_d_loc_ >= 0) { glUniform1i(u_ac_d_loc_, state_.ac_d); uniform_upload_count_++; }

                    if (u_cc_a1_loc_ >= 0) { glUniform1i(u_cc_a1_loc_, state_.cc_a1); uniform_upload_count_++; }
                    if (u_cc_b1_loc_ >= 0) { glUniform1i(u_cc_b1_loc_, state_.cc_b1); uniform_upload_count_++; }
                    if (u_cc_c1_loc_ >= 0) { glUniform1i(u_cc_c1_loc_, state_.cc_c1); uniform_upload_count_++; }
                    if (u_cc_d1_loc_ >= 0) { glUniform1i(u_cc_d1_loc_, state_.cc_d1); uniform_upload_count_++; }
                    if (u_ac_a1_loc_ >= 0) { glUniform1i(u_ac_a1_loc_, state_.ac_a1); uniform_upload_count_++; }
                    if (u_ac_b1_loc_ >= 0) { glUniform1i(u_ac_b1_loc_, state_.ac_b1); uniform_upload_count_++; }
                    if (u_ac_c1_loc_ >= 0) { glUniform1i(u_ac_c1_loc_, state_.ac_c1); uniform_upload_count_++; }
                    if (u_ac_d1_loc_ >= 0) { glUniform1i(u_ac_d1_loc_, state_.ac_d1); uniform_upload_count_++; }
                    state_.dirty_uniforms &= ~DIRTY_UNIFORM_COMBINER;
                }
                last_flushed_ovr_ = batch_.ovr;
            }
            if (state_.dirty_uniforms & DIRTY_UNIFORM_ALPHA_TEST) {
                if (u_alpha_test_loc_ >= 0) { glUniform1i(u_alpha_test_loc_, static_cast<int>(state_.alpha_mode)); uniform_upload_count_++; }
                if (u_alpha_threshold_loc_ >= 0) { glUniform1f(u_alpha_threshold_loc_, state_.alpha_threshold); uniform_upload_count_++; }
                state_.dirty_uniforms &= ~DIRTY_UNIFORM_ALPHA_TEST;
            }
            if (last_flushed_kind_ != batch_.kind || (state_.dirty_uniforms & DIRTY_UNIFORM_FOG_EN)) {
                const bool is_rect = (batch_.kind == BatchKind::Rect2D);
                const bool fog_geom = !s_no_fog && !is_rect && ((state_.geometry_mode & 0x00010000U) != 0U);
                const bool fog_enabled = !s_no_fog && !is_rect && state_.fog_enabled && fog_geom;
                if (u_fog_enabled_loc_ >= 0) { glUniform1i(u_fog_enabled_loc_, fog_enabled ? 1 : 0); uniform_upload_count_++; }
                if (u_fog_geom_loc_ >= 0) { glUniform1i(u_fog_geom_loc_, fog_geom ? 1 : 0); uniform_upload_count_++; }
                last_flushed_kind_ = batch_.kind;
                state_.dirty_uniforms &= ~DIRTY_UNIFORM_FOG_EN;
            }
            if (state_.dirty_uniforms & DIRTY_UNIFORM_FOG_PARAMS) {
                if (u_fog_params_loc_ >= 0) {
                    if (s_no_fog) {
                        glUniform2f(u_fog_params_loc_, 0.0f, 0.0f);
                    } else {
                        glUniform2f(u_fog_params_loc_,
                                    static_cast<float>(state_.fog_mul) / 256.0f,
                                    static_cast<float>(state_.fog_off) / 256.0f);
                    }
                    uniform_upload_count_++;
                }
                state_.dirty_uniforms &= ~DIRTY_UNIFORM_FOG_PARAMS;
            }
            state_.uniforms_dirty = (state_.dirty_uniforms != DIRTY_UNIFORM_NONE);
        }
    }

    const GLuint target_tex = (batch_.tex && batch_.tex_id != 0)
        ? batch_.tex_id
        : dummy_white_texture_;
    if (gl_bound_texture_ != target_tex) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, target_tex);
        gl_bound_texture_ = target_tex;
    }

    draw_calls_++;
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    if (!attribs_enabled_) {
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        attribs_enabled_ = true;
    }
    const auto* base = batched_vertices_.data();
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(F3DGLESVertex), &base->x);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(F3DGLESVertex), &base->u);
    glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(F3DGLESVertex), &base->r);

    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(batched_vertices_.size()));

    batched_vertices_.clear();
}

void F3DDKRGLESBridge::apply_sampler_state(CachedGLTexture& cached, GLenum wrap_s, GLenum wrap_t, GLenum filter) {
    const bool wrap_changed = (cached.wrap_s != wrap_s || cached.wrap_t != wrap_t);
    const bool filter_changed = (cached.current_filter != filter);
    if (!wrap_changed && !filter_changed) {
        return;
    }
    if (cached.id == state_.current_texture_id && !batched_vertices_.empty()) {
        flush_batch(FlushReason::Texture);
    }
    if (gl_bound_texture_ != cached.id) {
        glBindTexture(GL_TEXTURE_2D, cached.id);
        gl_bound_texture_ = cached.id;
    }
    if (wrap_changed) {
        if (cached.wrap_s != wrap_s) {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, static_cast<GLint>(wrap_s));
            cached.wrap_s = wrap_s;
        }
        if (cached.wrap_t != wrap_t) {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, static_cast<GLint>(wrap_t));
            cached.wrap_t = wrap_t;
        }
    }
    if (filter_changed) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(filter));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(filter));
        cached.current_filter = filter;
    }
}

GLuint F3DDKRGLESBridge::bind_tile_texture(uint8_t tile_idx) {
    if (!state_.texture_state_dirty && state_.last_bound_tile == tile_idx && state_.current_texture_id != 0) {
        tex_hits_++;
        return state_.current_texture_id;
    }

    auto& t = state_.tiles[tile_idx & 0x07U];
    update_tile_params(t);
    const uint32_t width = t.cached_tile_w;
    const uint32_t height = t.cached_tile_h;

    const bool clamp_s = t.clamp_s || (t.mask_s == 0);
    const bool clamp_t = t.clamp_t || (t.mask_t == 0);
    GLenum wrap_s = clamp_s ? GL_CLAMP_TO_EDGE : (t.mirror_s ? GL_MIRRORED_REPEAT : GL_REPEAT);
    GLenum wrap_t = clamp_t ? GL_CLAMP_TO_EDGE : (t.mirror_t ? GL_MIRRORED_REPEAT : GL_REPEAT);

    // Phase 1.4: Force GL_CLAMP_TO_EDGE for NPOT textures on GLES2
    const bool is_npot_w = (width & (width - 1U)) != 0U;
    const bool is_npot_h = (height & (height - 1U)) != 0U;
    if (is_npot_w && wrap_s != GL_CLAMP_TO_EDGE) {
        wrap_s = GL_CLAMP_TO_EDGE;
        static bool s_logged_npot_s = false;
        if (!s_logged_npot_s) {
            s_logged_npot_s = true;
            std::fprintf(stderr, "[gles][tex] NPOT width %u with wrap forced to GL_CLAMP_TO_EDGE\n", width);
        }
    }
    if (is_npot_h && wrap_t != GL_CLAMP_TO_EDGE) {
        wrap_t = GL_CLAMP_TO_EDGE;
        static bool s_logged_npot_t = false;
        if (!s_logged_npot_t) {
            s_logged_npot_t = true;
            std::fprintf(stderr, "[gles][tex] NPOT height %u with wrap forced to GL_CLAMP_TO_EDGE\n", height);
        }
    }
    const GLenum desired_filter = (state_.text_filter == 0) ? GL_NEAREST : GL_LINEAR;

    const uint32_t tmem_offset = static_cast<uint32_t>(t.tmem) * 8U;
    uint32_t row_bytes = width * 2U;
    switch (t.size) {
        case 0: row_bytes = (width + 1U) / 2U; break;
        case 1: row_bytes = width; break;
        case 2: row_bytes = width * 2U; break;
        case 3: row_bytes = width * 4U; break;
        default: break;
    }

    const uint32_t row_stride_bytes = (t.line > 0)
        ? static_cast<uint32_t>(t.line * ((t.size == 3) ? 16U : 8U))
        : row_bytes;
    const uint32_t span = std::min(4096U, (height > 0) ? (row_stride_bytes * (height - 1U) + row_bytes) : row_bytes);

    const uint32_t tmem_slot = t.tmem & 0x01FFU;
    const uint32_t src_addr = state_.tmem_source_addr[tmem_slot];

    uint64_t hash = 0;
    if (state_.tmem_loaded_bytes[tmem_slot] == span) {
        hash = state_.tmem_slot_hash[tmem_slot];
    }
    if (hash == 0) {
        hash = HashTMEM(state_.tmem.data(), tmem_offset, span);
    }
    if (t.fmt == 2) {
        if (t.size == 0) {
            const uint32_t pal_offset = 0x800U + static_cast<uint32_t>(t.palette & 0x0FU) * 32U;
            hash ^= HashTMEM(state_.tmem.data(), pal_offset, 32U);
        } else {
            hash ^= HashTMEM(state_.tmem.data(), 0x800U, 512U);
        }
    }

    const bool odd_line_swap = (state_.tmem_line_swapped[tmem_slot] != 0);

    TextureKey key{};
    key.source_addr = src_addr;
    key.tmem_hash = hash;
    key.width = static_cast<uint16_t>(width);
    key.height = static_cast<uint16_t>(height);
    key.line = t.line;
    key.tmem = t.tmem;
    key.fmt = t.fmt;
    key.size = t.size;
    key.palette = t.palette;
    key.line_swapped = odd_line_swap ? 1 : 0;
    key.tlut_type = state_.tlut_type;

    if (!s_no_texcache) {
        auto it = texture_cache_.find(key);
        if (it != texture_cache_.end()) {
            tex_hits_++;
            it->second.last_used_frame = processed_tasks_;
            apply_sampler_state(it->second, wrap_s, wrap_t, desired_filter);
            if (state_.current_texture_id != it->second.id && !batched_vertices_.empty()) {
                flush_batch(FlushReason::Texture);
            }
            if (gl_bound_texture_ != it->second.id) {
                glBindTexture(GL_TEXTURE_2D, it->second.id);
                gl_bound_texture_ = it->second.id;
            }
            state_.current_texture_id = it->second.id;
            state_.last_bound_tile = tile_idx;
            state_.texture_state_dirty = false;
            return it->second.id;
        }
    }

    tex_misses_++;

    if (s_log_tex) {
        static uint32_t s_log_count = 0;
        if (s_log_count++ < 200) {
            std::fprintf(stderr, "[gles][tex] miss #%u fmt=%u size=%u w=%u h=%u line=%u tmem=%u swap=%u tlut=%u\n",
                         s_log_count, t.fmt, t.size, width, height, t.line, t.tmem, odd_line_swap ? 1 : 0, state_.tlut_type);
        }
    }

    // Flush pending batch BEFORE creating and binding the new texture
    if (!batched_vertices_.empty()) {
        flush_batch(FlushReason::Texture);
    }

    // Fast decode and upload texture: 16-bit RGBA, 16-bit LA8 (Luminance-Alpha), or 32-bit RGBA
    bool is_16bit = DecodeTMEMToRGBA16(state_.tmem.data(), t.fmt, t.size, t.palette, tmem_offset, width, height,
                                       row_stride_bytes, rgba16_buf_, odd_line_swap, state_.tlut_type);
    bool is_la8 = false;
    if (!is_16bit) {
        is_la8 = DecodeTMEMToLA8(state_.tmem.data(), t.fmt, t.size, t.palette, tmem_offset, width, height,
                                 row_stride_bytes, la8_buf_, odd_line_swap, state_.tlut_type);
    }

    GLuint tex_id = 0;
    glGenTextures(1, &tex_id);
    glBindTexture(GL_TEXTURE_2D, tex_id);
    gl_bound_texture_ = tex_id;
    if (is_16bit) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, static_cast<GLsizei>(width), static_cast<GLsizei>(height),
                     0, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, rgba16_buf_.data());
    } else if (is_la8) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE_ALPHA, static_cast<GLsizei>(width), static_cast<GLsizei>(height),
                     0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, la8_buf_.data());
    } else {
        DecodeTMEMToRGBA(state_.tmem.data(), t.fmt, t.size, t.palette, tmem_offset, width, height,
                         row_stride_bytes, rgba32_buf_, odd_line_swap, state_.tlut_type);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, static_cast<GLsizei>(width), static_cast<GLsizei>(height),
                     0, GL_RGBA, GL_UNSIGNED_BYTE, rgba32_buf_.data());
    }

    CachedGLTexture cached{};
    cached.id = tex_id;
    cached.width = width;
    cached.height = height;
    cached.wrap_s = 0;
    cached.wrap_t = 0;
    cached.current_filter = 0;
    apply_sampler_state(cached, wrap_s, wrap_t, desired_filter);

    constexpr size_t kMaxCacheEntries = 512;
    constexpr size_t kTargetCacheEntries = 384;
    if (texture_cache_.size() >= kMaxCacheEntries) {
        struct EvictCandidate {
            uint64_t last_used;
            TextureKey key;
            GLuint id;
        };
        std::vector<EvictCandidate> candidates;
        candidates.reserve(texture_cache_.size());
        for (const auto& [k, v] : texture_cache_) {
            candidates.push_back({v.last_used_frame, k, v.id});
        }

        const size_t num_to_evict = candidates.size() - kTargetCacheEntries;
        std::nth_element(candidates.begin(), candidates.begin() + num_to_evict, candidates.end(),
                         [](const EvictCandidate& a, const EvictCandidate& b) {
                             return a.last_used < b.last_used;
                         });

        for (size_t i = 0; i < num_to_evict; ++i) {
            const auto& c = candidates[i];
            if (c.id == state_.current_texture_id) {
                state_.current_texture_id = 0;
            }
            if (c.id == gl_bound_texture_) {
                gl_bound_texture_ = 0xFFFFFFFF;
            }
            glDeleteTextures(1, &c.id);
            texture_cache_.erase(c.key);
        }
    }

    cached.last_used_frame = processed_tasks_;
    auto existing_it = texture_cache_.find(key);
    if (existing_it != texture_cache_.end()) {
        if (existing_it->second.id != 0 && existing_it->second.id != tex_id) {
            glDeleteTextures(1, &existing_it->second.id);
        }
    }
    texture_cache_[key] = cached;

    state_.current_texture_id = tex_id;
    state_.last_bound_tile = tile_idx;
    state_.texture_state_dirty = false;
    return tex_id;
}

void F3DDKRGLESBridge::process_task(const OSTask& task, const uint8_t* rdram) {
    if (!initialized_) init();
    if (rdram == nullptr) return;

    state_.dl_stack.clear();
    state_.vertex_cursor = 0U;
    ++g_completed_tasks;
    ++processed_tasks_;
    gl_current_program_ = 0xFFFFFFFF;

    dl_budget_ = 200000U;
    dl_abort_ = false;
    dl_unexpected_opcode_seen_ = false;
    dl_recursion_depth_ = 0;

    const uint32_t start = resolve_segmented_address(task.t.data_ptr);
    record_dl_history(task.t.data_ptr, start);
    execute_display_list(start, rdram);
    flush_batch(FlushReason::EndTask);

#ifndef NDEBUG
    static const bool s_check_gl_errors = true;
#else
    static const bool s_check_gl_errors = []() {
        if (const char* env = std::getenv("DKR_GLES_GL_ERRORS")) {
            return std::atoi(env) != 0;
        }
        return false;
    }();
#endif

    if (s_check_gl_errors) {
        static int s_logged_gl_errors = 0;
        if (s_logged_gl_errors < 10) {
            GLenum err = glGetError();
            while (err != GL_NO_ERROR && s_logged_gl_errors < 10) {
                std::fprintf(stderr, "[gles][error] GL error 0x%04X in process_task\n", err);
                ++s_logged_gl_errors;
                err = glGetError();
            }
        }
    }

    auto now = std::chrono::steady_clock::now();
    static const bool s_perf_logging = []() {
        if (const char* env = std::getenv("DKR_GLES_PERF")) {
            return std::atoi(env) != 0;
        }
        return false;
    }();

    if ((s_perf_logging || s_perf_detail) &&
        (processed_tasks_ == 1 || std::chrono::duration_cast<std::chrono::milliseconds>(now - last_perf_log_).count() >= 1000)) {
        static uint64_t last_tasks = 0;
        static uint64_t last_draws = 0;
        static uint64_t last_tris = 0;
        static uint64_t last_misses = 0;
        static uint64_t last_programs = 0;
        static uint64_t last_uniforms = 0;
        static std::array<uint64_t, static_cast<size_t>(FlushReason::Count)> last_flushes{};

        if (!s_perf_detail) {
            std::fprintf(stderr,
                "[gles][perf] task=%llu tex_cache=%zu hits=%llu misses=%llu draws=%llu tris=%llu\n",
                static_cast<unsigned long long>(processed_tasks_),
                texture_cache_.size(),
                static_cast<unsigned long long>(tex_hits_),
                static_cast<unsigned long long>(tex_misses_),
                static_cast<unsigned long long>(draw_calls_),
                static_cast<unsigned long long>(tri_count_));
        } else {
            const uint64_t d_tasks = (processed_tasks_ > last_tasks) ? (processed_tasks_ - last_tasks) : 1;
            const uint64_t d_draws = draw_calls_ - last_draws;
            const uint64_t d_tris = tri_count_ - last_tris;
            const uint64_t d_misses = tex_misses_ - last_misses;
            const uint64_t d_progs = use_program_count_ - last_programs;
            const uint64_t d_unifs = uniform_upload_count_ - last_uniforms;

            std::fprintf(stderr,
                "[gles][perf] task=%llu tex_cache=%zu hits=%llu misses=%llu draws=%llu tris=%llu "
                "avg_draw=%.1f avg_tri=%.1f avg_miss=%.2f prog=%llu unif=%llu sh_progs=%zu "
                "flushes[tex=%llu comb=%llu other=%llu col=%llu fog=%llu scis=%llu vp=%llu kind=%llu texen=%llu copy=%llu fill=%llu depth=%llu cimg=%llu end=%llu]\n",
                static_cast<unsigned long long>(processed_tasks_),
                texture_cache_.size(),
                static_cast<unsigned long long>(tex_hits_),
                static_cast<unsigned long long>(tex_misses_),
                static_cast<unsigned long long>(draw_calls_),
                static_cast<unsigned long long>(tri_count_),
                static_cast<double>(d_draws) / static_cast<double>(d_tasks),
                static_cast<double>(d_tris) / static_cast<double>(d_tasks),
                static_cast<double>(d_misses) / static_cast<double>(d_tasks),
                static_cast<unsigned long long>(d_progs),
                static_cast<unsigned long long>(d_unifs),
                programs_.size(),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::Texture)] - last_flushes[static_cast<size_t>(FlushReason::Texture)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::Combiner)] - last_flushes[static_cast<size_t>(FlushReason::Combiner)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::OtherMode)] - last_flushes[static_cast<size_t>(FlushReason::OtherMode)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::Color)] - last_flushes[static_cast<size_t>(FlushReason::Color)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::Fog)] - last_flushes[static_cast<size_t>(FlushReason::Fog)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::Scissor)] - last_flushes[static_cast<size_t>(FlushReason::Scissor)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::Viewport)] - last_flushes[static_cast<size_t>(FlushReason::Viewport)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::BatchKind)] - last_flushes[static_cast<size_t>(FlushReason::BatchKind)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::TexEnable)] - last_flushes[static_cast<size_t>(FlushReason::TexEnable)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::CopyRect)] - last_flushes[static_cast<size_t>(FlushReason::CopyRect)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::FillRect)] - last_flushes[static_cast<size_t>(FlushReason::FillRect)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::DepthClear)] - last_flushes[static_cast<size_t>(FlushReason::DepthClear)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::ColorImage)] - last_flushes[static_cast<size_t>(FlushReason::ColorImage)]),
                static_cast<unsigned long long>(flush_reasons_[static_cast<size_t>(FlushReason::EndTask)] - last_flushes[static_cast<size_t>(FlushReason::EndTask)]));

            last_tasks = processed_tasks_;
            last_draws = draw_calls_;
            last_tris = tri_count_;
            last_misses = tex_misses_;
            last_programs = use_program_count_;
            last_uniforms = uniform_upload_count_;
            last_flushes = flush_reasons_;
        }
        last_perf_log_ = now;
    }
}

void F3DDKRGLESBridge::execute_display_list(uint32_t address, const uint8_t* rdram) {
    if (dl_budget_ == 0 && dl_recursion_depth_ == 0 && state_.dl_stack.empty()) {
        dl_budget_ = 200000U;
        dl_abort_ = false;
        dl_unexpected_opcode_seen_ = false;
    }

    const size_t base_depth = state_.dl_stack.size();

    address &= 0x00FFFFF8U;
    while (!dl_abort_ && dl_budget_ > 0 && RdramRangeOk(address, 8U)) {
        --dl_budget_;
        const uint32_t cmd_addr = address;
        const uint32_t w0 = ReadU32(rdram, address);
        const uint32_t w1 = ReadU32(rdram, address + 4U);
        address += 8U;

        const uint8_t opcode = static_cast<uint8_t>((w0 >> 24U) & 0xFFU);
        if (opcode == kEndDisplayListOpcode) {
            if (state_.dl_stack.size() <= base_depth) {
                break;
            }
            address = state_.dl_stack.back().address;
            state_.dl_stack.pop_back();
            continue;
        }

        if (opcode == kDisplayListOpcode) {
            const bool branch = (w0 & 0x00010000U) != 0U;
            const uint32_t target = resolve_segmented_address(w1) & 0x00FFFFF8U;
            record_dl_history(w1, target);
            if (!branch) {
                if (state_.dl_stack.size() >= 32) {
                    static bool s_logged_stack = false;
                    if (!s_logged_stack) {
                        std::fprintf(stderr, "[gles][dl] DL stack depth exceeded 32! Aborting DL task.\n");
                        s_logged_stack = true;
                    }
                    dl_abort_ = true;
                    state_.dl_stack.clear();
                    break;
                }
                state_.dl_stack.push_back({address});
            }
            address = target;
            continue;
        }

        if (opcode == kCountedDisplayListOpcode) {
            const uint32_t count = (w0 >> 16U) & 0xFFU;
            const uint32_t target = resolve_segmented_address(w1) & 0x00FFFFF8U;
            record_dl_history(w1, target);
            run_counted_dl(target, count, rdram);
            continue;
        }

        if (opcode == kTexRectOpcode || opcode == kTexRectFlipOpcode) {
            if (RdramRangeOk(address, 16U)) {
                const uint32_t w1_st = ReadU32(rdram, address + 4U);
                const uint32_t w1_dxdy = ReadU32(rdram, address + 12U);
                address += 16U;
                handle_tex_rect(w0, w1, w1_st, w1_dxdy, opcode == kTexRectFlipOpcode);
            }
            continue;
        }

        execute_command(w0, w1, rdram, cmd_addr);
    }
}

void F3DDKRGLESBridge::run_counted_dl(uint32_t target, uint32_t count, const uint8_t* rdram) {
    if (count > 0 && RdramRangeOk(target, static_cast<uint64_t>(count) * 8U)) {
        for (uint32_t i = 0; i < count && !dl_abort_ && dl_budget_ > 0; ++i) {
            --dl_budget_;
            const uint32_t c_addr = target + i * 8U;
            const uint32_t cw0 = ReadU32(rdram, c_addr);
            const uint32_t cw1 = ReadU32(rdram, c_addr + 4U);
            const uint8_t copcode = static_cast<uint8_t>((cw0 >> 24U) & 0xFFU);
            if ((copcode == kTexRectOpcode || copcode == kTexRectFlipOpcode) && i + 2 < count) {
                const uint32_t w1_st = ReadU32(rdram, target + (i + 1) * 8U + 4U);
                const uint32_t w1_dxdy = ReadU32(rdram, target + (i + 2) * 8U + 4U);
                handle_tex_rect(cw0, cw1, w1_st, w1_dxdy, copcode == kTexRectFlipOpcode);
                i += 2;
            } else {
                execute_command(cw0, cw1, rdram, c_addr);
            }
        }
    }
}

void F3DDKRGLESBridge::execute_command(uint32_t w0, uint32_t w1, const uint8_t* rdram, uint32_t cmd_address) {
    const uint8_t opcode = static_cast<uint8_t>((w0 >> 24U) & 0xFFU);
    switch (opcode) {
        case kMatrixOpcode:
            handle_matrix(w0, w1, rdram);
            break;
        case kTextureOffsetOpcode:
            handle_texture_offset(w0, w1);
            break;
        case kVertexOpcode:
            handle_vertex(w0, w1, rdram);
            break;
        case kTriangleOpcode:
            handle_triangle(w0, w1, rdram);
            break;
        case kMoveMemOpcode:
            handle_move_mem(w0, w1, rdram);
            break;
        case kMoveWordOpcode:
            handle_move_word(w0, w1, rdram);
            break;
        case kDMAOffsetsOpcode:
            handle_dma_offsets(w0, w1, rdram);
            break;
        case kSetTextureImageOpcode:
            handle_set_timg(w0, w1, rdram);
            break;
        case kSetTileOpcode:
            handle_set_tile(w0, w1, rdram);
            break;
        case kSetTileSizeOpcode:
            handle_set_tile_size(w0, w1, rdram);
            break;
        case kLoadBlockOpcode:
            handle_load_block(w0, w1, rdram);
            break;
        case kLoadTLUTOpcode:
            handle_load_tlut(w0, w1, rdram);
            break;
        case kLoadTileOpcode:
            handle_load_tile(w0, w1, rdram);
            handle_unexpected_opcode(opcode, cmd_address);
            break;
        case kDisplayListOpcode: {
            if (dl_recursion_depth_ >= 8) {
                static bool s_logged_recursion = false;
                if (!s_logged_recursion) {
                    std::fprintf(stderr, "[gles][dl] DL recursion depth exceeded 8! Aborting DL task.\n");
                    s_logged_recursion = true;
                }
                dl_abort_ = true;
                state_.dl_stack.clear();
                break;
            }
            const uint32_t target = resolve_segmented_address(w1) & 0x00FFFFF8U;
            record_dl_history(w1, target);
            ++dl_recursion_depth_;
            execute_display_list(target, rdram);
            --dl_recursion_depth_;
            break;
        }
        case kCountedDisplayListOpcode: {
            const uint32_t count = (w0 >> 16U) & 0xFFU;
            const uint32_t target = resolve_segmented_address(w1) & 0x00FFFFF8U;
            record_dl_history(w1, target);
            run_counted_dl(target, count, rdram);
            break;
        }
        case kSetOtherModeOpcode:
            apply_other_mode(w0 & 0x00FFFFFFU, w1);
            break;
        case kSetOtherModeHOpcode:
            handle_set_other_mode_hl(true, w0, w1);
            break;
        case kSetOtherModeLOpcode:
            handle_set_other_mode_hl(false, w0, w1);
            break;
        case kSetCombineOpcode:
            handle_set_combine(w0, w1);
            break;
        case kSetGeometryModeOpcode:
        case kClearGeometryModeOpcode:
            handle_geometry_mode(opcode, w1);
            break;
        case kSetScissorOpcode:
            handle_set_scissor(w0, w1);
            break;
        case kSetFogColorOpcode:
        case kSetBlendColorOpcode:
        case kSetPrimColorOpcode:
        case kSetEnvColorOpcode:
            handle_set_color(opcode, w0, w1);
            break;
        case kSetFillColorOpcode:
            handle_set_fill_color(w1);
            break;
        case kSetDepthImageOpcode:
            handle_set_depth_image(w0, w1);
            break;
        case kSetColorImageOpcode:
            handle_set_color_image(w0, w1);
            break;
        case kFillRectOpcode:
            handle_fill_rect(w0, w1);
            break;
        case kTextureOpcode: {
            const bool enable = ((w0 & 0xFFU) != 0U);
            if (enable != state_.texture_enabled) {
                if (!batched_vertices_.empty()) {
                    flush_batch(FlushReason::TexEnable);
                }
                state_.texture_enabled = enable;
                state_.dirty_uniforms |= DIRTY_UNIFORM_TEXTURE_EN;
                state_.uniforms_dirty = true;
            }
            break;
        }
        case 0x00: // G_SPNOOP
        case 0xC0: // G_NOOP
        case 0xB1: // G_RDPHALF_CONT
        case 0xB2: // G_RDPHALF_2
        case 0xB3: // G_RDPHALF_1
        case 0xB4: // G_PERSPNORMALIZE
        case 0xB5: // G_LINE3D
        case 0xBD: // G_POPMTX
        case 0xBE: // G_CULLDL
        case 0xEA: // G_SETKEYGB
        case 0xEB: // G_SETKEYR
        case 0xEC: // G_SETCONVERT
        case 0xEE: // G_SETPRIMDEPTH
        case 0xE6: // G_RDPLOADSYNC
        case 0xE7: // G_RDPPIPESYNC
        case 0xE8: // G_RDPTILESYNC
        case 0xE9: // G_RDPFULLSYNC
            break;
        default:
            handle_unexpected_opcode(opcode, cmd_address);
            break;
    }
}

void F3DDKRGLESBridge::handle_matrix(uint32_t w0, uint32_t w1, const uint8_t* rdram) {
    uint32_t index = (w0 >> 16U) & 0xFU;
    if (index == 0U) {
        index = (w0 >> 22U) & 0x3U;
    }
    index = std::min(index, 2U);
    state_.selected_matrix = index;

    const uint32_t address = (state_.matrix_offset + resolve_segmented_address(w1)) & kRDRAMAddressMask;
    if (RdramRangeOk(address, 64U)) {
        state_.modelview_stack[index].load_fixed_point(rdram, address);
    }
}

void F3DDKRGLESBridge::handle_texture_offset(uint32_t /*w0*/, uint32_t w1) {
    state_.texture_offset = w1 & kRDRAMAddressMask;
    state_.texture_shift = 0U;
    state_.texture_count = 0U;
}

void F3DDKRGLESBridge::handle_vertex(uint32_t w0, uint32_t w1, const uint8_t* rdram) {
    const bool append = (w0 & 0x00010000U) != 0U;
    const uint32_t count = ((w0 >> 19U) & 0x1FU) + 1U;
    if (append) {
        if (state_.billboard) {
            state_.vertex_cursor = 1U;
        }
    } else {
        state_.vertex_cursor = 0U;
    }
    const uint32_t destination = state_.vertex_cursor;
    const uint32_t source = (state_.vertex_offset + resolve_segmented_address(w1)) & kRDRAMAddressMask;

    if (RdramRangeOk(source, static_cast<uint64_t>(count) * 10U) && destination + count <= state_.vertex_cache.size()) {
        const F3DGLESMtx& m = state_.modelview_stack[std::min(state_.selected_matrix, 2U)];

        for (uint32_t i = 0; i < count; ++i) {
            const uint32_t addr = source + i * 10U;
            auto& v = state_.vertex_cache[destination + i];
            const float raw_x = static_cast<float>(RawS16(rdram, addr + 0U));
            const float raw_y = static_cast<float>(RawS16(rdram, addr + 2U));
            const float raw_z = static_cast<float>(RawS16(rdram, addr + 4U));

            if (state_.billboard && append) {
                // In DKR F3DDKR microcode, billboard vertices processed after the anchor (vertex 0)
                // use the billboard matrix stored in slot 2 (G_MTX_DKR_INDEX_2).
                // Their offsets are added to the anchor vertex in clip space, preserving the anchor's w.
                const auto& anchor = state_.vertex_cache[0];
                const auto& bm = state_.modelview_stack[2];
                const float bx = raw_x * bm.m[0][0] + raw_y * bm.m[1][0] + raw_z * bm.m[2][0] + bm.m[3][0];
                const float by = raw_x * bm.m[0][1] + raw_y * bm.m[1][1] + raw_z * bm.m[2][1] + bm.m[3][1];
                const float bz = raw_x * bm.m[0][2] + raw_y * bm.m[1][2] + raw_z * bm.m[2][2] + bm.m[3][2];
                v.x = anchor.x + bx;
                v.y = anchor.y + by;
                v.z = anchor.z + bz;
                v.w = anchor.w;
            } else {
                v.x = raw_x * m.m[0][0] + raw_y * m.m[1][0] + raw_z * m.m[2][0] + m.m[3][0];
                v.y = raw_x * m.m[0][1] + raw_y * m.m[1][1] + raw_z * m.m[2][1] + m.m[3][1];
                v.z = raw_x * m.m[0][2] + raw_y * m.m[1][2] + raw_z * m.m[2][2] + m.m[3][2];
                v.w = raw_x * m.m[0][3] + raw_y * m.m[1][3] + raw_z * m.m[2][3] + m.m[3][3];
            }

            v.r = RawU8(rdram, addr + 6U);
            v.g = RawU8(rdram, addr + 7U);
            v.b = RawU8(rdram, addr + 8U);
            v.a = RawU8(rdram, addr + 9U);
        }
        state_.vertex_cursor += count;
    }
}

void F3DDKRGLESBridge::handle_triangle(uint32_t w0, uint32_t w1, const uint8_t* rdram) {
    const uint32_t count = ((w0 >> 20U) & 0x0FU) + 1U;
    const bool tex_en = ((w0 >> 16U) & 0x0FU) != 0U;
    state_.texture_enabled = tex_en;
    GLuint tex_id = 0;
    if (tex_en) {
        tex_id = bind_tile_texture(0);
    }
    begin_primitives(BatchKind::Tri3D,
                     tex_en ? DrawOverride::None : DrawOverride::Untextured,
                     tex_en,
                     tex_id,
                     FlushReason::BatchKind);

    const uint32_t source = resolve_segmented_address(w1);

    auto& t = state_.tiles[0];
    update_tile_params(t);

    const float scale_s = t.cached_scale_s;
    const float scale_t = t.cached_scale_t;
    const float s_offset = t.cached_s_offset;
    const float t_offset = t.cached_t_offset;

    static const float s_cull_sign = []() {
        if (const char* env = std::getenv("DKR_CULL_SIGN")) {
            return static_cast<float>(std::atof(env));
        }
        return 1.0f;
    }();

    tri_count_ += count;
    if (RdramRangeOk(source, static_cast<uint64_t>(count) * 16U)) {
        const bool is_aligned = ((source & 3U) == 0U);
        for (uint32_t i = 0; i < count; ++i) {
            const uint32_t addr = source + i * 16U;
            uint8_t flags, idx0, idx1, idx2;
            int16_t s0, t0, s1, t1, s2, t2;

            if (is_aligned) {
                uint32_t w0, w1, w2, w3;
                std::memcpy(&w0, rdram + addr + 0U, 4);
                std::memcpy(&w1, rdram + addr + 4U, 4);
                std::memcpy(&w2, rdram + addr + 8U, 4);
                std::memcpy(&w3, rdram + addr + 12U, 4);

                flags = static_cast<uint8_t>(w0 >> 24U);
                idx0  = static_cast<uint8_t>((w0 >> 16U) & 0xFFU);
                idx1  = static_cast<uint8_t>((w0 >> 8U) & 0xFFU);
                idx2  = static_cast<uint8_t>(w0 & 0xFFU);

                s0 = static_cast<int16_t>(w1 >> 16U);
                t0 = static_cast<int16_t>(w1 & 0xFFFFU);
                s1 = static_cast<int16_t>(w2 >> 16U);
                t1 = static_cast<int16_t>(w2 & 0xFFFFU);
                s2 = static_cast<int16_t>(w3 >> 16U);
                t2 = static_cast<int16_t>(w3 & 0xFFFFU);
            } else {
                flags = RawU8(rdram, addr + 0U);
                idx0  = RawU8(rdram, addr + 1U);
                idx1  = RawU8(rdram, addr + 2U);
                idx2  = RawU8(rdram, addr + 3U);

                s0 = RawS16(rdram, addr + 4U);
                t0 = RawS16(rdram, addr + 6U);
                s1 = RawS16(rdram, addr + 8U);
                t1 = RawS16(rdram, addr + 10U);
                s2 = RawS16(rdram, addr + 12U);
                t2 = RawS16(rdram, addr + 14U);
            }

            if (idx0 >= 64U || idx1 >= 64U || idx2 >= 64U) continue;

            const auto& cv0 = state_.vertex_cache[idx0];
            const auto& cv1 = state_.vertex_cache[idx1];
            const auto& cv2 = state_.vertex_cache[idx2];

            // CPU Backface Culling (Phase 2.3 & P4)
            // In DKR, 0x40 flag indicates BACKFACE_DRAW (draw both sides).
            // If not set and all vertices are in front of near plane (w > 0), check screen-space winding.
            // w0*w1*w2 > 0 preserves the sign of cross_ndc, eliminating 6 divisions per triangle.
            if ((flags & 0x40U) == 0 && cv0.w > 0.0f && cv1.w > 0.0f && cv2.w > 0.0f) {
                const float cross = cv0.x * (cv1.y * cv2.w - cv2.y * cv1.w) +
                                    cv1.x * (cv2.y * cv0.w - cv0.y * cv2.w) +
                                    cv2.x * (cv0.y * cv1.w - cv1.y * cv0.w);
                if (cross * s_cull_sign <= 0.0f) {
                    continue;
                }
            }

            batched_vertices_.push_back({cv0.x, cv0.y, cv0.z, cv0.w, (s0 - s_offset) * scale_s, (t0 - t_offset) * scale_t, cv0.r, cv0.g, cv0.b, cv0.a});
            batched_vertices_.push_back({cv1.x, cv1.y, cv1.z, cv1.w, (s1 - s_offset) * scale_s, (t1 - t_offset) * scale_t, cv1.r, cv1.g, cv1.b, cv1.a});
            batched_vertices_.push_back({cv2.x, cv2.y, cv2.z, cv2.w, (s2 - s_offset) * scale_s, (t2 - t_offset) * scale_t, cv2.r, cv2.g, cv2.b, cv2.a});
        }
    }
    state_.vertex_cursor = 0U;
}

void F3DDKRGLESBridge::handle_move_mem(uint32_t w0, uint32_t w1, const uint8_t* rdram) {
    const uint8_t type = static_cast<uint8_t>((w0 >> 16U) & 0xFFU);
    const uint32_t address = resolve_segmented_address(w1);
    if (type == 0x80U || (w0 & 0xFFU) == 0x80U) { // Viewport movemem
        if (RdramRangeOk(address, 16U)) {
            const int16_t scale_x = ReadS16(rdram, address + 0U);
            const int16_t scale_y = ReadS16(rdram, address + 2U);
            const int16_t trans_x = ReadS16(rdram, address + 8U);
            const int16_t trans_y = ReadS16(rdram, address + 10U);

            // N64 viewport values are in 1/4 pixels
            const float native_w = std::abs(static_cast<float>(scale_x) * 2.0f / 4.0f);
            const float native_h = std::abs(static_cast<float>(scale_y) * 2.0f / 4.0f);
            const float native_x = (static_cast<float>(trans_x) / 4.0f) - (native_w * 0.5f);
            const float native_y = (static_cast<float>(trans_y) / 4.0f) - (native_h * 0.5f);

            const float sx = static_cast<float>(target_w_) / static_cast<float>(n64_fb_w_);
            const float sy = static_cast<float>(target_h_) / static_cast<float>(n64_fb_h_);

            const int vx = static_cast<int>(native_x * sx);
            const int vy = static_cast<int>((static_cast<float>(n64_fb_h_) - (native_y + native_h)) * sy);
            const int vw = std::max(1, static_cast<int>(native_w * sx));
            const int vh = std::max(1, static_cast<int>(native_h * sy));

            if (vx != state_.viewport_x || vy != state_.viewport_y ||
                vw != state_.viewport_w || vh != state_.viewport_h) {
                if (!batched_vertices_.empty()) {
                    flush_batch(FlushReason::Viewport);
                }
                set_viewport(vx, vy, vw, vh);
            }
        }
    }
}

void F3DDKRGLESBridge::handle_move_word(uint32_t w0, uint32_t w1, const uint8_t* /*rdram*/) {
    const uint8_t index = static_cast<uint8_t>(w0 & 0xFFU);
    if (index == 0x06U) { // G_MW_SEGMENT (Fast3D)
        const uint32_t segment = ((w0 >> 8U) & 0xFFFFU) >> 2U;
        if (segment < 16U) {
            state_.segments[segment] = w1 & kRDRAMAddressMask;
        }
    } else if (index == 0x08U) { // G_MW_FOG
        const int16_t new_mul = static_cast<int16_t>((w1 >> 16U) & 0xFFFFU);
        const int16_t new_off = static_cast<int16_t>(w1 & 0xFFFFU);
        if (new_mul != state_.fog_mul || new_off != state_.fog_off) {
            if (!batched_vertices_.empty()) {
                flush_batch(FlushReason::Fog);
            }
            state_.fog_mul = new_mul;
            state_.fog_off = new_off;
            state_.dirty_uniforms |= DIRTY_UNIFORM_FOG_PARAMS;
            state_.uniforms_dirty = true;
        }
    } else if (index == 0x02U) {
        state_.billboard = ((w1 & 1U) != 0U);
    } else if (index == 0x0AU) {
        state_.selected_matrix = std::min((w1 >> 6U) & 0x03U, 2U);
    }
}

void F3DDKRGLESBridge::handle_dma_offsets(uint32_t w0, uint32_t w1, const uint8_t* /*rdram*/) {
    state_.matrix_offset = (w0 & kRDRAMAddressMask);
    state_.vertex_offset = (w1 & kRDRAMAddressMask);
}

void F3DDKRGLESBridge::handle_set_timg(uint32_t w0, uint32_t w1, const uint8_t* rdram) {
    state_.timg_fmt = static_cast<uint8_t>((w0 >> 21U) & 0x07U);
    state_.timg_size = static_cast<uint8_t>((w0 >> 19U) & 0x03U);
    state_.timg_width = static_cast<uint16_t>((w0 & 0x0FFFU) + 1U);
    uint32_t addr = resolve_segmented_address(w1);

    if (state_.texture_offset != 0) {
        if (state_.timg_fmt == 0) {
            const uint32_t shift_address = state_.texture_offset + state_.texture_count * sizeof(uint16_t);
            if (RdramRangeOk(shift_address, sizeof(uint16_t))) {
                state_.texture_shift = ReadU16(rdram, shift_address);
                addr = (addr + state_.texture_shift) & kRDRAMAddressMask;
            }
        } else {
            state_.texture_offset = 0;
            state_.texture_shift = 0;
            state_.texture_count = 0;
        }
    }

    state_.timg_address = addr;
    state_.texture_state_dirty = true;
}

void F3DDKRGLESBridge::handle_set_tile(uint32_t w0, uint32_t w1, const uint8_t* /*rdram*/) {
    const uint8_t tile = static_cast<uint8_t>((w1 >> 24U) & 0x07U);
    auto& t = state_.tiles[tile];
    t.fmt = static_cast<uint8_t>((w0 >> 21U) & 0x07U);
    t.size = static_cast<uint8_t>((w0 >> 19U) & 0x03U);
    t.line = static_cast<uint16_t>((w0 >> 9U) & 0x01FFU);
    t.tmem = static_cast<uint16_t>(w0 & 0x01FFU);
    t.palette = static_cast<uint8_t>((w1 >> 20U) & 0x0FU);
    t.clamp_t = static_cast<uint8_t>((w1 >> 19U) & 0x01U);
    t.mirror_t = static_cast<uint8_t>((w1 >> 18U) & 0x01U);
    t.mask_t = static_cast<uint8_t>((w1 >> 14U) & 0x0FU);
    t.shift_t = static_cast<uint8_t>((w1 >> 10U) & 0x0FU);
    t.clamp_s = static_cast<uint8_t>((w1 >> 9U) & 0x01U);
    t.mirror_s = static_cast<uint8_t>((w1 >> 8U) & 0x01U);
    t.mask_s = static_cast<uint8_t>((w1 >> 4U) & 0x0FU);
    t.shift_s = static_cast<uint8_t>(w1 & 0x0FU);
    t.params_dirty = true;
    state_.texture_state_dirty = true;
}

void F3DDKRGLESBridge::handle_set_tile_size(uint32_t w0, uint32_t w1, const uint8_t* /*rdram*/) {
    const uint8_t tile = static_cast<uint8_t>((w1 >> 24U) & 0x07U);
    auto& t = state_.tiles[tile];
    t.sl = static_cast<uint16_t>((w0 >> 12U) & 0x0FFFU);
    t.tl = static_cast<uint16_t>(w0 & 0x0FFFU);
    t.sh = static_cast<uint16_t>((w1 >> 12U) & 0x0FFFU);
    t.th = static_cast<uint16_t>(w1 & 0x0FFFU);
    t.params_dirty = true;
    state_.texture_state_dirty = true;
}

void F3DDKRGLESBridge::handle_load_block(uint32_t w0, uint32_t w1, const uint8_t* rdram) {
    const uint8_t tile = static_cast<uint8_t>((w1 >> 24U) & 0x07U);
    const auto& t = state_.tiles[tile];
    const uint32_t tmem_dest = static_cast<uint32_t>(t.tmem) * 8U;
    const uint16_t lrs = static_cast<uint16_t>((w1 >> 12U) & 0x0FFFU);

    if (state_.texture_offset != 0) {
        const uint32_t block_size = (((lrs >> 2U) + 1U) << 3U);
        if (block_size == 0 || (state_.texture_shift % block_size) != 0) {
            if (state_.texture_shift > state_.timg_address) {
                state_.texture_offset = 0;
                state_.texture_shift = 0;
                state_.texture_count = 0;
            } else {
                state_.timg_address -= state_.texture_shift;
                state_.texture_offset = 0;
                state_.texture_shift = 0;
                state_.texture_count = 0;
            }
        } else {
            ++state_.texture_count;
        }
    }

    const uint32_t texels = lrs + 1U;
    uint32_t bytes_to_copy = texels * 2U;
    switch (state_.timg_size) {
        case 0: bytes_to_copy = (texels + 1U) / 2U; break;
        case 1: bytes_to_copy = texels; break;
        case 2: bytes_to_copy = texels * 2U; break;
        case 3: bytes_to_copy = texels * 4U; break;
        default: break;
    }
    bytes_to_copy = std::min(bytes_to_copy, 4096U);

    if (RdramRangeOk(state_.timg_address, bytes_to_copy)) {
        const uint32_t tmem_slot = t.tmem & 0x01FFU;
        state_.tmem_source_addr[tmem_slot] = state_.timg_address;
        state_.tmem_loaded_bytes[tmem_slot] = bytes_to_copy;

        const uint32_t dxt = w1 & 0x0FFFU;
        state_.tmem_line_swapped[tmem_slot] = (dxt == 0) ? 1 : 0;

        CopyRDRAMToTMEM(state_.tmem.data(), tmem_dest, rdram, state_.timg_address, bytes_to_copy);
        invalidate_tmem_hashes(tmem_dest, bytes_to_copy);
        state_.tmem_slot_hash[tmem_slot] = HashTMEM(state_.tmem.data(), tmem_dest, bytes_to_copy);
        state_.texture_state_dirty = true;
    }
}

void F3DDKRGLESBridge::handle_load_tlut(uint32_t /*w0*/, uint32_t w1, const uint8_t* rdram) {
    const uint8_t tile = static_cast<uint8_t>((w1 >> 24U) & 0x07U);
    const auto& t = state_.tiles[tile];
    const uint32_t tmem_dest = static_cast<uint32_t>(t.tmem) * 8U;
    const uint32_t raw_count = ((w1 >> 14U) & 0x03FFU) + 1U;
    const uint32_t count = std::min(raw_count, 256U);
    const uint32_t bytes_to_copy = count * 2U;

    if (RdramRangeOk(state_.timg_address, bytes_to_copy)) {
        const uint32_t tmem_slot = t.tmem & 0x01FFU;
        state_.tmem_source_addr[tmem_slot] = state_.timg_address;
        state_.tmem_loaded_bytes[tmem_slot] = bytes_to_copy;
        state_.tmem_line_swapped[tmem_slot] = 0;
        state_.last_tlut_address = state_.timg_address;
        CopyRDRAMToTMEM(state_.tmem.data(), tmem_dest, rdram, state_.timg_address, bytes_to_copy);
        invalidate_tmem_hashes(tmem_dest, bytes_to_copy);
        state_.tmem_slot_hash[tmem_slot] = HashTMEM(state_.tmem.data(), tmem_dest, bytes_to_copy);
        state_.texture_state_dirty = true;
    }
}

void F3DDKRGLESBridge::handle_load_tile(uint32_t w0, uint32_t w1, const uint8_t* rdram) {
    const uint8_t tile = static_cast<uint8_t>((w1 >> 24U) & 0x07U);
    const auto& t = state_.tiles[tile];
    const uint32_t dst_stride = static_cast<uint32_t>(t.line) * 8U;
    if (dst_stride == 0) {
        return;
    }

    const uint16_t sl = static_cast<uint16_t>((w0 >> 12U) & 0x0FFFU);
    const uint16_t tl = static_cast<uint16_t>(w0 & 0x0FFFU);
    const uint16_t sh = static_cast<uint16_t>((w1 >> 12U) & 0x0FFFU);
    const uint16_t th = static_cast<uint16_t>(w1 & 0x0FFFU);

    const int32_t w = (static_cast<int32_t>(sh) >> 2) - (static_cast<int32_t>(sl) >> 2) + 1;
    const int32_t h = (static_cast<int32_t>(th) >> 2) - (static_cast<int32_t>(tl) >> 2) + 1;
    if (w <= 0 || h <= 0) {
        return;
    }

    const uint32_t width = static_cast<uint32_t>(w);
    uint32_t height = static_cast<uint32_t>(h);

    if (height * dst_stride > 4096U) {
        height = 4096U / dst_stride;
        if (height == 0) return;
    }

    uint32_t row_bytes = 0;
    uint32_t src_stride = 0;
    const uint64_t sl_texel = static_cast<uint64_t>(sl >> 2U);
    const uint64_t tl_texel = static_cast<uint64_t>(tl >> 2U);
    uint64_t x_byte_offset = 0;

    if (state_.timg_size == 0) { // 4bpp
        row_bytes = (width + 1U) / 2U;
        src_stride = (static_cast<uint32_t>(state_.timg_width) + 1U) / 2U;
        x_byte_offset = sl_texel / 2U;
    } else {
        uint32_t bpp = 1U;
        if (state_.timg_size == 2) bpp = 2U;
        else if (state_.timg_size == 3) bpp = 4U;

        row_bytes = width * bpp;
        src_stride = static_cast<uint32_t>(state_.timg_width) * bpp;
        x_byte_offset = sl_texel * bpp;
    }

    row_bytes = std::min(row_bytes, dst_stride);

    const uint32_t tmem_dest = (static_cast<uint32_t>(t.tmem) * 8U) & 0x0FFFU;
    const uint32_t tmem_slot = t.tmem & 0x01FFU;
    state_.tmem_source_addr[tmem_slot] = state_.timg_address;
    state_.tmem_loaded_bytes[tmem_slot] = height * dst_stride;
    state_.tmem_line_swapped[tmem_slot] = 0;

    const uint64_t base_addr = static_cast<uint64_t>(state_.timg_address);
    for (uint32_t y = 0; y < height; ++y) {
        const uint64_t src_offset = base_addr + (tl_texel + y) * static_cast<uint64_t>(src_stride) + x_byte_offset;
        const uint32_t dst_offset = (tmem_dest + y * dst_stride) & 0x0FFFU;
        if (RdramRangeOk(src_offset, row_bytes)) {
            CopyRDRAMToTMEM(state_.tmem.data(), dst_offset, rdram, static_cast<size_t>(src_offset), row_bytes);
        }
    }

    invalidate_tmem_hashes(tmem_dest, height * dst_stride);
    state_.tmem_slot_hash[tmem_slot] = HashTMEM(state_.tmem.data(), tmem_dest, height * dst_stride);
    state_.texture_state_dirty = true;
}

void F3DDKRGLESBridge::handle_set_combine(uint32_t w0, uint32_t w1) {
    const uint8_t new_cc_a = static_cast<uint8_t>((w0 >> 20U) & 0x0FU);
    const uint8_t new_cc_c = static_cast<uint8_t>((w0 >> 15U) & 0x1FU);
    const uint8_t new_ac_a = static_cast<uint8_t>((w0 >> 12U) & 0x07U);
    const uint8_t new_ac_c = static_cast<uint8_t>((w0 >> 9U) & 0x07U);

    const uint8_t new_cc_b = static_cast<uint8_t>((w1 >> 28U) & 0x0FU);
    const uint8_t new_cc_d = static_cast<uint8_t>((w1 >> 15U) & 0x07U);
    const uint8_t new_ac_b = static_cast<uint8_t>((w1 >> 12U) & 0x07U);
    const uint8_t new_ac_d = static_cast<uint8_t>((w1 >> 9U) & 0x07U);

    const uint8_t new_cc_a1 = static_cast<uint8_t>((w0 >> 5U) & 0x0FU);
    const uint8_t new_cc_c1 = static_cast<uint8_t>(w0 & 0x1FU);
    const uint8_t new_cc_b1 = static_cast<uint8_t>((w1 >> 24U) & 0x0FU);
    const uint8_t new_cc_d1 = static_cast<uint8_t>((w1 >> 6U) & 0x07U);
    const uint8_t new_ac_a1 = static_cast<uint8_t>((w1 >> 21U) & 0x07U);
    const uint8_t new_ac_c1 = static_cast<uint8_t>((w1 >> 18U) & 0x07U);
    const uint8_t new_ac_b1 = static_cast<uint8_t>((w1 >> 3U) & 0x07U);
    const uint8_t new_ac_d1 = static_cast<uint8_t>(w1 & 0x07U);

    if (state_.cc_a != new_cc_a || state_.cc_b != new_cc_b ||
        state_.cc_c != new_cc_c || state_.cc_d != new_cc_d ||
        state_.ac_a != new_ac_a || state_.ac_b != new_ac_b ||
        state_.ac_c != new_ac_c || state_.ac_d != new_ac_d ||
        state_.cc_a1 != new_cc_a1 || state_.cc_b1 != new_cc_b1 ||
        state_.cc_c1 != new_cc_c1 || state_.cc_d1 != new_cc_d1 ||
        state_.ac_a1 != new_ac_a1 || state_.ac_b1 != new_ac_b1 ||
        state_.ac_c1 != new_ac_c1 || state_.ac_d1 != new_ac_d1) {
        if (!batched_vertices_.empty()) {
            flush_batch(FlushReason::Combiner);
        }
        state_.cc_a = new_cc_a; state_.cc_b = new_cc_b;
        state_.cc_c = new_cc_c; state_.cc_d = new_cc_d;
        state_.ac_a = new_ac_a; state_.ac_b = new_ac_b;
        state_.ac_c = new_ac_c; state_.ac_d = new_ac_d;
        state_.cc_a1 = new_cc_a1; state_.cc_b1 = new_cc_b1;
        state_.cc_c1 = new_cc_c1; state_.cc_d1 = new_cc_d1;
        state_.ac_a1 = new_ac_a1; state_.ac_b1 = new_ac_b1;
        state_.ac_c1 = new_ac_c1; state_.ac_d1 = new_ac_d1;
        state_.dirty_uniforms |= DIRTY_UNIFORM_COMBINER;
        state_.uniforms_dirty = true;
    }
}

void F3DDKRGLESBridge::apply_other_mode(uint32_t hi, uint32_t lo) {
    const uint64_t new_other_mode = (static_cast<uint64_t>(hi) << 32U) | lo;
    if (state_.other_mode == new_other_mode) return;

    const uint8_t new_cycle_type = static_cast<uint8_t>((hi >> 20U) & 0x03U);
    const uint8_t new_text_filter = static_cast<uint8_t>((hi >> 12U) & 0x03U);
    const uint8_t new_tlut_type = static_cast<uint8_t>((hi >> 14U) & 0x03U);
    const bool new_depth_test = (lo & 0x0010U) != 0U;
    const bool new_depth_write = (lo & 0x0020U) != 0U;

    const uint8_t alpha_compare = static_cast<uint8_t>(lo & 0x03U);
    const bool alpha_cvg_sel = (lo & 0x2000U) != 0U;
    uint8_t new_alpha_mode = 0;
    float new_threshold = 0.25f;
    if (alpha_compare == 1) { // G_AC_THRESHOLD: compare against blend color alpha
        new_alpha_mode = 1;
        new_threshold = state_.blend_color[3];
    } else if (alpha_compare == 3) { // G_AC_DITHER
        new_alpha_mode = 2;
    } else if (alpha_cvg_sel && alpha_compare == 0) {
        new_alpha_mode = 1;
        new_threshold = 0.5f;
    }

    const uint32_t zmode = (lo >> 10U) & 0x03U;
    const bool new_decal = (zmode == 3U); // ZMODE_DEC (Phase 3.3)

    // Blender fog detection (Phase 3.1): P = G_BL_CLR_FOG (3), A = G_BL_A_SHADE (2)
    const uint32_t p0 = (lo >> 30U) & 0x03U;
    const uint32_t a0 = (lo >> 26U) & 0x03U;
    const bool new_fog_enabled = (p0 == 3U && a0 == 2U);

    // Blending decoding:
    const bool is_2cycle = (new_cycle_type == 1);
    const uint32_t bp = is_2cycle ? ((lo >> 28U) & 0x03U) : ((lo >> 30U) & 0x03U);
    const uint32_t ba = is_2cycle ? ((lo >> 24U) & 0x03U) : ((lo >> 26U) & 0x03U);
    const uint32_t bm = is_2cycle ? ((lo >> 20U) & 0x03U) : ((lo >> 22U) & 0x03U);
    const uint32_t bb = is_2cycle ? ((lo >> 16U) & 0x03U) : ((lo >> 18U) & 0x03U);

    const bool is_additive = (bb == 2U);
    const bool is_translucent = (bp == 0U && ba == 0U && bm == 1U && bb == 0U);
    const bool new_blend = (zmode == 2U) || is_translucent || is_additive;

    const bool prev_effective_additive = state_.blend_enabled && state_.blend_additive;
    const bool new_effective_additive = new_blend && is_additive;

    if (state_.text_filter != new_text_filter) {
        if (!batched_vertices_.empty()) {
            flush_batch(FlushReason::OtherMode);
        }
        state_.texture_state_dirty = true;
    }

    if (state_.tlut_type != new_tlut_type) {
        if (!batched_vertices_.empty()) {
            flush_batch(FlushReason::OtherMode);
        }
        state_.texture_state_dirty = true;
    }

    if (state_.depth_test_enabled != new_depth_test ||
        state_.depth_write_enabled != new_depth_write ||
        state_.alpha_mode != new_alpha_mode ||
        state_.alpha_threshold != new_threshold ||
        state_.blend_enabled != new_blend ||
        prev_effective_additive != new_effective_additive ||
        state_.decal_mode != new_decal ||
        state_.fog_enabled != new_fog_enabled ||
        state_.cycle_type != new_cycle_type) {
        if (!batched_vertices_.empty()) {
            flush_batch(FlushReason::OtherMode);
        }
        if (state_.alpha_mode != new_alpha_mode || state_.alpha_threshold != new_threshold) {
            state_.dirty_uniforms |= DIRTY_UNIFORM_ALPHA_TEST;
            state_.uniforms_dirty = true;
        }
        if (state_.fog_enabled != new_fog_enabled) {
            state_.dirty_uniforms |= DIRTY_UNIFORM_FOG_EN;
            state_.uniforms_dirty = true;
        }
        if (state_.cycle_type != new_cycle_type) {
            state_.dirty_uniforms |= DIRTY_UNIFORM_COMBINER;
            state_.uniforms_dirty = true;
        }
    }

    state_.other_mode = new_other_mode;
    state_.cycle_type = new_cycle_type;
    state_.text_filter = new_text_filter;
    state_.tlut_type = new_tlut_type;
    state_.depth_test_enabled = new_depth_test;
    state_.depth_write_enabled = new_depth_write;
    state_.alpha_mode = new_alpha_mode;
    state_.alpha_test = (new_alpha_mode != 0);
    state_.alpha_threshold = new_threshold;
    state_.blend_enabled = new_blend;
    state_.blend_additive = is_additive;
    state_.decal_mode = new_decal;
    state_.fog_enabled = new_fog_enabled;
}

void F3DDKRGLESBridge::handle_set_other_mode(uint32_t w0, uint32_t w1) {
    apply_other_mode(w0 & 0x00FFFFFFU, w1);
}

void F3DDKRGLESBridge::handle_set_other_mode_hl(bool is_high, uint32_t w0, uint32_t w1) {
    const uint32_t shift = (w0 >> 8U) & 0xFFU;
    if (shift >= 32U) return;
    const uint32_t len = w0 & 0xFFU;
    const uint32_t mask = static_cast<uint32_t>(((len >= 32U ? 0xFFFFFFFFULL : ((1ULL << len) - 1ULL)) << shift));
    uint32_t hi = static_cast<uint32_t>((state_.other_mode >> 32U) & 0xFFFFFFFFU);
    uint32_t lo = static_cast<uint32_t>(state_.other_mode & 0xFFFFFFFFU);
    if (is_high) {
        hi = (hi & ~mask) | (w1 & mask);
    } else {
        lo = (lo & ~mask) | (w1 & mask);
    }
    apply_other_mode(hi, lo);
}

void F3DDKRGLESBridge::handle_geometry_mode(uint8_t opcode, uint32_t w1) {
    const uint32_t prev_geom = state_.geometry_mode;
    if (opcode == kSetGeometryModeOpcode) {
        state_.geometry_mode |= w1;
    } else {
        state_.geometry_mode &= ~w1;
    }
    const bool prev_fog = (prev_geom & 0x00010000U) != 0;
    const bool new_fog = (state_.geometry_mode & 0x00010000U) != 0;

    if (prev_fog != new_fog) {
        if (!batched_vertices_.empty()) {
            flush_batch(FlushReason::Fog);
        }
        state_.dirty_uniforms |= DIRTY_UNIFORM_FOG_EN;
        state_.uniforms_dirty = true;
    }
}

void F3DDKRGLESBridge::handle_set_scissor(uint32_t w0, uint32_t w1) {
    const float ulx = static_cast<float>((w0 >> 12U) & 0x0FFFU) / 4.0f;
    const float uly = static_cast<float>(w0 & 0x0FFFU) / 4.0f;
    const float lrx = static_cast<float>((w1 >> 12U) & 0x0FFFU) / 4.0f;
    const float lry = static_cast<float>(w1 & 0x0FFFU) / 4.0f;

    if (lry > 240.0f && n64_fb_h_ != 480) {
        n64_fb_h_ = 480;
    } else if (uly <= 0.0f && lry >= 200.0f && lry <= 240.0f && n64_fb_h_ != 240) {
        n64_fb_h_ = 240;
    }

    const int new_ulx = static_cast<int>(ulx);
    const int new_uly = static_cast<int>(uly);
    const int new_lrx = static_cast<int>(lrx);
    const int new_lry = static_cast<int>(lry);
    const bool new_enabled = (new_lrx > new_ulx && new_lry > new_uly);

    if (state_.scissor_ulx != new_ulx || state_.scissor_uly != new_uly ||
        state_.scissor_lrx != new_lrx || state_.scissor_lry != new_lry ||
        state_.scissor_test_enabled != new_enabled) {
        if (!batched_vertices_.empty()) {
            flush_batch(FlushReason::Scissor);
        }
        state_.scissor_ulx = new_ulx;
        state_.scissor_uly = new_uly;
        state_.scissor_lrx = new_lrx;
        state_.scissor_lry = new_lry;
        state_.scissor_test_enabled = new_enabled;
    }
}

void F3DDKRGLESBridge::handle_set_color(uint8_t opcode, uint32_t w0, uint32_t w1) {
    const float r = static_cast<float>((w1 >> 24U) & 0xFFU) / 255.0f;
    const float g = static_cast<float>((w1 >> 16U) & 0xFFU) / 255.0f;
    const float b = static_cast<float>((w1 >> 8U) & 0xFFU) / 255.0f;
    const float a = static_cast<float>(w1 & 0xFFU) / 255.0f;

    const uint8_t u8_r = static_cast<uint8_t>((w1 >> 24U) & 0xFFU);
    const uint8_t u8_g = static_cast<uint8_t>((w1 >> 16U) & 0xFFU);
    const uint8_t u8_b = static_cast<uint8_t>((w1 >> 8U) & 0xFFU);
    const uint8_t u8_a = static_cast<uint8_t>(w1 & 0xFFU);

    float* target = nullptr;
    uint32_t dirty_flag = DIRTY_UNIFORM_NONE;
    switch (opcode) {
        case kSetPrimColorOpcode: {
            target = state_.prim_color;
            dirty_flag = DIRTY_UNIFORM_PRIM_COLOR;
            const float new_lod_frac = static_cast<float>(w0 & 0xFFU) / 255.0f;
            if (state_.prim_lod_frac != new_lod_frac) {
                if (!batched_vertices_.empty()) {
                    flush_batch(FlushReason::Combiner);
                }
                state_.prim_lod_frac = new_lod_frac;
                state_.dirty_uniforms |= DIRTY_UNIFORM_COMBINER;
                state_.uniforms_dirty = true;
            }
            break;
        }
        case kSetEnvColorOpcode:   target = state_.env_color;   dirty_flag = DIRTY_UNIFORM_ENV_COLOR; break;
        case kSetBlendColorOpcode: target = state_.blend_color; dirty_flag = DIRTY_UNIFORM_NONE; break;
        case kSetFogColorOpcode:   target = state_.fog_color;   dirty_flag = DIRTY_UNIFORM_FOG_COLOR; break;
        default: break;
    }

    if (target != nullptr) {
        if (target[0] != r || target[1] != g || target[2] != b || target[3] != a) {
            if (!batched_vertices_.empty()) {
                flush_batch(FlushReason::Color);
            }
            target[0] = r; target[1] = g; target[2] = b; target[3] = a;
            if (opcode == kSetPrimColorOpcode) {
                state_.prim_rgba8[0] = u8_r;
                state_.prim_rgba8[1] = u8_g;
                state_.prim_rgba8[2] = u8_b;
                state_.prim_rgba8[3] = u8_a;
            }
            if (opcode == kSetBlendColorOpcode && state_.alpha_mode == 1) {
                state_.alpha_threshold = a;
                dirty_flag |= DIRTY_UNIFORM_ALPHA_TEST;
            }
            state_.dirty_uniforms |= dirty_flag;
            state_.uniforms_dirty = true;
        }
    }
}

void F3DDKRGLESBridge::handle_set_fill_color(uint32_t w1) {
    state_.fill_color_raw = w1;
}

void F3DDKRGLESBridge::handle_set_color_image(uint32_t w0, uint32_t w1) {
    const uint32_t addr = resolve_segmented_address(w1) & kRDRAMAddressMask;
    const uint8_t size = static_cast<uint8_t>((w0 >> 19U) & 0x03U);
    state_.color_image_size = size;

    if (state_.depth_image_address == 0 || addr != state_.depth_image_address) {
        const int width = static_cast<int>((w0 & 0x0FFFU) + 1U);
        if (width >= 320 && width <= 640) {
            n64_fb_w_ = width;
        }
    }

    if (state_.color_image_address != addr) {
        if (!batched_vertices_.empty()) {
            flush_batch(FlushReason::ColorImage);
        }
        state_.color_image_address = addr;
        static uint32_t s_primary_color_image = 0;
        static bool s_logged_offscreen = false;
        if (s_primary_color_image == 0 && addr != state_.depth_image_address) {
            s_primary_color_image = addr;
        } else if (!s_logged_offscreen && addr != state_.depth_image_address && addr != s_primary_color_image) {
            s_logged_offscreen = true;
            std::fprintf(stderr, "[gles][target] draw to offscreen image 0x%08X (primary 0x%08X)\n", addr, s_primary_color_image);
        }
    }
}

void F3DDKRGLESBridge::handle_set_depth_image(uint32_t /*w0*/, uint32_t w1) {
    const uint32_t addr = resolve_segmented_address(w1) & kRDRAMAddressMask;
    if (state_.depth_image_address != addr) {
        if (!batched_vertices_.empty()) {
            flush_batch(FlushReason::DepthClear);
        }
        state_.depth_image_address = addr;
    }
}

void F3DDKRGLESBridge::handle_fill_rect(uint32_t w0, uint32_t w1) {
    // Check if this fill rect is a depth buffer clear.
    // In N64 Fast3D / DKR, depth buffer is cleared when the render target (color_image_address)
    // is pointed at the depth buffer (depth_image_address).
    const bool is_depth_clear = (state_.depth_image_address != 0 &&
                                 state_.color_image_address == state_.depth_image_address);

    if (is_depth_clear) {
        if (!batched_vertices_.empty()) {
            flush_batch(FlushReason::DepthClear);
        }
        const bool scissor_was_enabled = (gl_scissor_test_ == 1);
        if (scissor_was_enabled) {
            glDisable(GL_SCISSOR_TEST);
            gl_scissor_test_ = 0;
        }
        glDepthMask(GL_TRUE);
        gl_depth_mask_ = 1;
        glClear(GL_DEPTH_BUFFER_BIT);
        if (scissor_was_enabled) {
            glEnable(GL_SCISSOR_TEST);
            gl_scissor_test_ = 1;
        }
        return;
    }

    const bool is_fill_mode = (state_.cycle_type == 3);
    const DrawOverride ovr = is_fill_mode ? DrawOverride::FillShade : DrawOverride::Untextured;

    begin_primitives(BatchKind::Rect2D, ovr, false, 0, FlushReason::FillRect);

    float ulx, uly, lrx, lry;
    if (state_.cycle_type < 2) {
        // 1-cycle or 2-cycle: 10.2 fixed-point coordinates
        lrx = static_cast<float>((w0 >> 12U) & 0x0FFFU) / 4.0f;
        lry = static_cast<float>(w0 & 0x0FFFU) / 4.0f;
        ulx = static_cast<float>((w1 >> 12U) & 0x0FFFU) / 4.0f;
        uly = static_cast<float>(w1 & 0x0FFFU) / 4.0f;
    } else {
        // COPY or FILL mode: 10.0 integer coordinates
        lrx = static_cast<float>((w0 >> 14U) & 0x03FFU);
        lry = static_cast<float>((w0 >> 2U) & 0x03FFU);
        ulx = static_cast<float>((w1 >> 14U) & 0x03FFU);
        uly = static_cast<float>((w1 >> 2U) & 0x03FFU);
    }

    const float extra = (state_.cycle_type >= 2) ? 1.0f : 0.0f;
    const float fb_w = static_cast<float>(n64_fb_w_);
    const float fb_h = static_cast<float>(n64_fb_h_);

    const float ndc_x0 = (ulx / fb_w) * 2.0f - 1.0f;
    const float ndc_y0 = 1.0f - (uly / fb_h) * 2.0f;
    const float ndc_x1 = ((lrx + extra) / fb_w) * 2.0f - 1.0f;
    const float ndc_y1 = 1.0f - ((lry + extra) / fb_h) * 2.0f;

    uint8_t r = 0, g = 0, b = 0, a = 255;
    if (is_fill_mode) {
        if (state_.color_image_size == 2) { // 16-bit RGBA5551
            const uint16_t c16 = static_cast<uint16_t>(state_.fill_color_raw & 0xFFFFU);
            const uint8_t r5 = static_cast<uint8_t>((c16 >> 11U) & 0x1FU);
            const uint8_t g5 = static_cast<uint8_t>((c16 >> 6U) & 0x1FU);
            const uint8_t b5 = static_cast<uint8_t>((c16 >> 1U) & 0x1FU);
            r = static_cast<uint8_t>((r5 << 3U) | (r5 >> 2U));
            g = static_cast<uint8_t>((g5 << 3U) | (g5 >> 2U));
            b = static_cast<uint8_t>((b5 << 3U) | (b5 >> 2U));
            a = (c16 & 1U) ? 255 : 0;
        } else if (state_.color_image_size == 3) { // 32-bit RGBA8888
            r = static_cast<uint8_t>((state_.fill_color_raw >> 24U) & 0xFFU);
            g = static_cast<uint8_t>((state_.fill_color_raw >> 16U) & 0xFFU);
            b = static_cast<uint8_t>((state_.fill_color_raw >> 8U) & 0xFFU);
            a = static_cast<uint8_t>(state_.fill_color_raw & 0xFFU);
        } else { // 8-bit or fallback
            r = static_cast<uint8_t>(state_.fill_color_raw & 0xFFU);
            g = r;
            b = r;
            a = 255;
        }
    } else {
        r = state_.prim_rgba8[0];
        g = state_.prim_rgba8[1];
        b = state_.prim_rgba8[2];
        a = state_.prim_rgba8[3];
    }

    batched_vertices_.push_back({ndc_x0, ndc_y0, 0.0f, 1.0f, 0.0f, 0.0f, r, g, b, a});
    batched_vertices_.push_back({ndc_x1, ndc_y0, 0.0f, 1.0f, 1.0f, 0.0f, r, g, b, a});
    batched_vertices_.push_back({ndc_x0, ndc_y1, 0.0f, 1.0f, 0.0f, 1.0f, r, g, b, a});

    batched_vertices_.push_back({ndc_x1, ndc_y0, 0.0f, 1.0f, 1.0f, 0.0f, r, g, b, a});
    batched_vertices_.push_back({ndc_x1, ndc_y1, 0.0f, 1.0f, 1.0f, 1.0f, r, g, b, a});
    batched_vertices_.push_back({ndc_x0, ndc_y1, 0.0f, 1.0f, 0.0f, 1.0f, r, g, b, a});
}

void F3DDKRGLESBridge::handle_tex_rect(uint32_t w0, uint32_t w1, uint32_t w1_st, uint32_t w1_dxdy, bool flip) {
    const uint8_t tile = static_cast<uint8_t>((w1 >> 24U) & 0x07U);
    const GLuint tex_id = bind_tile_texture(tile);

    const bool is_copy = (state_.cycle_type == 2);
    const DrawOverride ovr = is_copy ? DrawOverride::CopyTexel : DrawOverride::None;

    begin_primitives(BatchKind::Rect2D, ovr, true, tex_id, is_copy ? FlushReason::CopyRect : FlushReason::BatchKind);

    const float lrx = static_cast<float>((w0 >> 12U) & 0x0FFFU) / 4.0f;
    const float lry = static_cast<float>(w0 & 0x0FFFU) / 4.0f;
    const float ulx = static_cast<float>((w1 >> 12U) & 0x0FFFU) / 4.0f;
    const float uly = static_cast<float>(w1 & 0x0FFFU) / 4.0f;

    const int16_t s0 = static_cast<int16_t>((w1_st >> 16U) & 0xFFFFU);
    const int16_t t0 = static_cast<int16_t>(w1_st & 0xFFFFU);
    const int16_t dsdx = static_cast<int16_t>((w1_dxdy >> 16U) & 0xFFFFU);
    const int16_t dtdy = static_cast<int16_t>(w1_dxdy & 0xFFFFU);

    auto& t = state_.tiles[tile];
    update_tile_params(t);
    const uint32_t tile_w = t.cached_tile_w;
    const uint32_t tile_h = t.cached_tile_h;

    const float s_origin = static_cast<float>(t.sl) / 4.0f;
    const float t_origin = static_cast<float>(t.tl) / 4.0f;
    const float s_start = (static_cast<float>(s0) / 32.0f) - s_origin;
    const float t_start = (static_cast<float>(t0) / 32.0f) - t_origin;

    const float width = lrx - ulx;
    const float height = lry - uly;

    float step_s = static_cast<float>(dsdx) / 1024.0f;
    float step_t = static_cast<float>(dtdy) / 1024.0f;
    if (state_.cycle_type == 2) { // COPY mode: dsdx is in units of 4 texels per step
        step_s /= 4.0f;
    }

    const float inv_tw = 1.0f / static_cast<float>(tile_w);
    const float inv_th = 1.0f / static_cast<float>(tile_h);

    float u_tl, v_tl, u_tr, v_tr, u_bl, v_bl, u_br, v_br;
    if (!flip) {
        u_tl = s_start * inv_tw;
        v_tl = t_start * inv_th;
        u_tr = (s_start + width * step_s) * inv_tw;
        v_tr = t_start * inv_th;
        u_bl = s_start * inv_tw;
        v_bl = (t_start + height * step_t) * inv_th;
        u_br = (s_start + width * step_s) * inv_tw;
        v_br = (t_start + height * step_t) * inv_th;
    } else {
        // When flipped, s advances along screen Y and t along screen X
        u_tl = s_start * inv_tw;
        v_tl = t_start * inv_th;
        u_tr = s_start * inv_tw;
        v_tr = (t_start + width * step_t) * inv_th;
        u_bl = (s_start + height * step_s) * inv_tw;
        v_bl = t_start * inv_th;
        u_br = (s_start + height * step_s) * inv_tw;
        v_br = (t_start + width * step_t) * inv_th;
    }

    const float extra = (state_.cycle_type >= 2) ? 1.0f : 0.0f;
    const float fb_w = static_cast<float>(n64_fb_w_);
    const float fb_h = static_cast<float>(n64_fb_h_);

    const float ndc_x0 = (ulx / fb_w) * 2.0f - 1.0f;
    const float ndc_y0 = 1.0f - (uly / fb_h) * 2.0f;
    const float ndc_x1 = ((lrx + extra) / fb_w) * 2.0f - 1.0f;
    const float ndc_y1 = 1.0f - ((lry + extra) / fb_h) * 2.0f;

    const uint8_t r = state_.prim_rgba8[0];
    const uint8_t g = state_.prim_rgba8[1];
    const uint8_t b = state_.prim_rgba8[2];
    const uint8_t a = state_.prim_rgba8[3];

    batched_vertices_.push_back({ndc_x0, ndc_y0, 0.0f, 1.0f, u_tl, v_tl, r, g, b, a});
    batched_vertices_.push_back({ndc_x1, ndc_y0, 0.0f, 1.0f, u_tr, v_tr, r, g, b, a});
    batched_vertices_.push_back({ndc_x0, ndc_y1, 0.0f, 1.0f, u_bl, v_bl, r, g, b, a});

    batched_vertices_.push_back({ndc_x1, ndc_y0, 0.0f, 1.0f, u_tr, v_tr, r, g, b, a});
    batched_vertices_.push_back({ndc_x1, ndc_y1, 0.0f, 1.0f, u_br, v_br, r, g, b, a});
    batched_vertices_.push_back({ndc_x0, ndc_y1, 0.0f, 1.0f, u_bl, v_bl, r, g, b, a});
}

} // namespace dkr::runtime
