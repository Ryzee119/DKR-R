#include "f3ddkr_gles.hpp"

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

#include <EGL/egl.h>

namespace {

void TestFixedPointMatrix() {
    std::printf("[test] Running TestFixedPointMatrix...\n");
    std::vector<uint8_t> rdram(65536, 0);

    // Write a known 4x4 matrix in N64 fixed-point format (int parts at [0..31], frac parts at [32..63])
    // Identity matrix:
    for (int i = 0; i < 4; ++i) {
        const uint32_t idx = static_cast<uint32_t>((i * 4 + i) * 2);
        int16_t int_val = 1;
        uint16_t frac_val = 0;
        std::memcpy(rdram.data() + (idx ^ 2U), &int_val, sizeof(int_val));
        std::memcpy(rdram.data() + ((32U + idx) ^ 2U), &frac_val, sizeof(frac_val));
    }

    dkr::runtime::F3DGLESMtx mtx{};
    mtx.load_fixed_point(rdram.data(), 0);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            float expected = (i == j) ? 1.0f : 0.0f;
            assert(std::fabs(mtx.m[i][j] - expected) < 1e-4f);
        }
    }
    std::printf("[test] TestFixedPointMatrix PASSED\n");
}

void TestDisplayListExecution() {
    std::printf("[test] Running TestDisplayListExecution...\n");

    // Initialize EGL headless context for GL execution
    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);

    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);
    eglBindAPI(EGL_OPENGL_ES_API);

    const EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    assert(context != EGL_NO_CONTEXT);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 640,
        EGL_HEIGHT, 480,
        EGL_NONE
    };
    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    assert(surface != EGL_NO_SURFACE);

    eglMakeCurrent(display, surface, surface, context);

    // Create bridge
    dkr::runtime::F3DDKRGLESBridge bridge;
    bridge.init();
    bridge.set_viewport(0, 0, 640, 480);

    // Prepare simulated RDRAM
    constexpr uint32_t kRDRAMSize = 0x00800000U;
    std::vector<uint8_t> rdram(kRDRAMSize, 0);

    // 1. Write Texture image at address 0x10000 (16x16 RGBA16 texture = 512 bytes)
    const uint32_t tex_addr = 0x10000;
    for (uint32_t i = 0; i < 256; ++i) {
        // Red color in 5-5-5-1: 11111 00000 00000 1 = 0xF801
        uint16_t color = 0xF801;
        rdram[tex_addr + i * 2 + 0] = static_cast<uint8_t>(color >> 8);
        rdram[tex_addr + i * 2 + 1] = static_cast<uint8_t>(color & 0xFF);
    }

    // 2. Write Palette at address 0x11000 (16 entries of RGBA16 for CI4 testing)
    const uint32_t pal_addr = 0x11000;
    for (uint32_t i = 0; i < 16; ++i) {
        uint16_t color = static_cast<uint16_t>((i << 11) | 1U);
        rdram[pal_addr + i * 2 + 0] = static_cast<uint8_t>(color >> 8);
        rdram[pal_addr + i * 2 + 1] = static_cast<uint8_t>(color & 0xFF);
    }

    // 3. Write 3 vertices at address 0x20000 (F3DDKR 10-byte packed vertices)
    const uint32_t vtx_addr = 0x20000;
    // Vertex 0: (-100, -100, 0), color white (255, 255, 255, 255)
    auto write_vtx = [&](uint32_t addr, int16_t x, int16_t y, int16_t z, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        std::memcpy(rdram.data() + ((addr + 0U) ^ 2U), &x, sizeof(x));
        std::memcpy(rdram.data() + ((addr + 2U) ^ 2U), &y, sizeof(y));
        std::memcpy(rdram.data() + ((addr + 4U) ^ 2U), &z, sizeof(z));
        rdram[(addr + 6U) ^ 3U] = r;
        rdram[(addr + 7U) ^ 3U] = g;
        rdram[(addr + 8U) ^ 3U] = b;
        rdram[(addr + 9U) ^ 3U] = a;
    };
    write_vtx(vtx_addr + 0, -50, -50, 0, 255, 255, 255, 255);
    write_vtx(vtx_addr + 10, 50, -50, 0, 255, 255, 255, 255);
    write_vtx(vtx_addr + 20, 0, 50, 0, 255, 255, 255, 255);

    // 4. Write Triangle command at address 0x21000 (F3DDKR 16-byte triangle)
    const uint32_t tri_addr = 0x21000;
    rdram[tri_addr + 0] = 0x40; // flag (no culling)
    rdram[tri_addr + 1] = 0;    // v0
    rdram[tri_addr + 2] = 1;    // v1
    rdram[tri_addr + 3] = 2;    // v2
    // Texcoords (s0, t0, s1, t1, s2, t2)
    int16_t s0 = 0, t0 = 0;
    int16_t s1 = 16 * 32, t1 = 0;
    int16_t s2 = 8 * 32, t2 = 16 * 32;
    std::memcpy(rdram.data() + ((tri_addr + 4U) ^ 2U), &s0, sizeof(s0));
    std::memcpy(rdram.data() + ((tri_addr + 6U) ^ 2U), &t0, sizeof(t0));
    std::memcpy(rdram.data() + ((tri_addr + 8U) ^ 2U), &s1, sizeof(s1));
    std::memcpy(rdram.data() + ((tri_addr + 10U) ^ 2U), &t1, sizeof(t1));
    std::memcpy(rdram.data() + ((tri_addr + 12U) ^ 2U), &s2, sizeof(s2));
    std::memcpy(rdram.data() + ((tri_addr + 14U) ^ 2U), &t2, sizeof(t2));

    // 5. Build Display List at address 0x30000
    const uint32_t dl_addr = 0x30000;
    uint32_t dl_idx = 0;
    auto emit_cmd = [&](uint32_t w0, uint32_t w1) {
        std::memcpy(rdram.data() + dl_addr + dl_idx * 8U, &w0, sizeof(w0));
        std::memcpy(rdram.data() + dl_addr + dl_idx * 8U + 4U, &w1, sizeof(w1));
        ++dl_idx;
    };

    // G_SETOTHERMODE: depth test, alpha compare
    emit_cmd(0xEF000000U, 0x00000030U | 0x00000001U);
    // G_SETGEOMETRYMODE: cull back
    emit_cmd(0xB7000000U, 0x00000400U);
    // G_SETPRIMCOLOR: white
    emit_cmd(0xFA000000U, 0xFFFFFFFFU);
    // G_SETENVCOLOR: white
    emit_cmd(0xFB000000U, 0xFFFFFFFFU);
    // G_SETCOMBINE: Modulate
    emit_cmd(0xFC121824U, 0xFF33FFFFU);

    // G_SETTIMG: RGBA16, width 16, address 0x10000
    // w0: [0xFD (8)][fmt=0 (3)][size=2 (2)][width-1=15 (12)]
    emit_cmd(0xFD10000FU, tex_addr);

    // G_SETTILE: tile 0, RGBA16
    emit_cmd(0xF5100000U, 0x00000000U);

    // G_SETTILESIZE: tile 0, 16x16
    // sl=0, tl=0, sh=(15 << 2), th=(15 << 2)
    emit_cmd(0xF2000000U, 0x0003C03CU);

    // G_LOADBLOCK: tile 0, 256 texels
    emit_cmd(0xF3000000U, 0x000FF000U);

    // G_VTX_F3DDKR: 3 vertices at vtx_addr
    // w0: [0x04 (8)][count-1=2 (5)][dest=0 (5)][flags (14)]
    emit_cmd(0x04100000U, vtx_addr);

    // G_TRI_F3DDKR: 1 triangle, textured (texture on = bit 16)
    emit_cmd(0x05010000U, tri_addr);

    // G_FILLRECT: 2D rectangle
    emit_cmd(0xF6050050U, 0x00010010U);

    // G_TEXRECT: 2D texture rectangle (3 packets)
    emit_cmd(0xE4080080U, 0x00020020U); // packet 0: lrx=128, lry=128, tile=0, ulx=32, uly=32
    emit_cmd(0x00000000U, 0x00000000U); // packet 1: s=0, t=0
    emit_cmd(0x00000000U, 0x04000400U); // packet 2: dsdx=1024 (1.0), dtdy=1024 (1.0)

    // G_ENDDL
    emit_cmd(0xB8000000U, 0x00000000U);

    // Execute display list!
    bridge.execute_display_list(dl_addr, rdram.data());
    bridge.flush_batch();

    std::printf("[test] Display list executed successfully!\n");

    // Clean up EGL
    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestDisplayListExecution PASSED\n");
}

void Test16BitTextureDecoding() {
    std::printf("[test] Running Test16BitTextureDecoding...\n");

    // 1. Test RGBA16 (fmt=0, size=2)
    std::vector<uint8_t> tmem(4096, 0);
    // Write 4 pixels of RGBA16: Red (0xF801), Green (0x07C1), Blue (0x003F), Yellow (0xFFE1)
    const uint16_t test_colors[4] = {0xF801, 0x07C1, 0x003F, 0xFFE1};
    for (int i = 0; i < 4; ++i) {
        tmem[i * 2 + 0] = static_cast<uint8_t>(test_colors[i] >> 8);
        tmem[i * 2 + 1] = static_cast<uint8_t>(test_colors[i] & 0xFF);
    }

    std::vector<uint16_t> out16;
    bool ok = dkr::runtime::DecodeTMEMToRGBA16(tmem.data(), 0, 2, 0, 0, 2, 2, out16);
    assert(ok);
    assert(out16.size() == 4);
    for (int i = 0; i < 4; ++i) {
        assert(out16[i] == test_colors[i]);
    }

    // 2. Test CI4 (fmt=2, size=0) with 16-color palette
    // Set palette base at 0x800:
    for (int i = 0; i < 16; ++i) {
        uint16_t c = static_cast<uint16_t>((i << 11) | 1U);
        tmem[0x800 + i * 2 + 0] = static_cast<uint8_t>(c >> 8);
        tmem[0x800 + i * 2 + 1] = static_cast<uint8_t>(c & 0xFF);
    }
    // Set indices in TMEM at 0x100: pixel 0=3, pixel 1=7, pixel 2=12, pixel 3=15
    tmem[0x100 + 0] = (3 << 4) | 7;
    tmem[0x100 + 1] = (12 << 4) | 15;

    std::vector<uint16_t> out_ci4;
    ok = dkr::runtime::DecodeTMEMToRGBA16(tmem.data(), 2, 0, 0, 0x100, 2, 2, out_ci4);
    assert(ok);
    assert(out_ci4.size() == 4);
    assert(out_ci4[0] == static_cast<uint16_t>((3 << 11) | 1U));
    assert(out_ci4[1] == static_cast<uint16_t>((7 << 11) | 1U));
    assert(out_ci4[2] == static_cast<uint16_t>((12 << 11) | 1U));
    assert(out_ci4[3] == static_cast<uint16_t>((15 << 11) | 1U));

    std::printf("[test] Test16BitTextureDecoding PASSED\n");
}

void TestOddLineSwapI4() {
    std::printf("[test] Running TestOddLineSwapI4...\n");

    // 16x4 I4 texture: 16 texels per row, 8 bytes per row, total 32 bytes
    constexpr uint32_t width = 16;
    constexpr uint32_t height = 4;
    constexpr uint32_t stride = 8;

    std::vector<uint8_t> tmem_unswapped(4096, 0);
    std::vector<uint8_t> tmem_preswapped(4096, 0);

    for (uint32_t y = 0; y < height; ++y) {
        for (uint32_t b = 0; b < stride; ++b) {
            // Assign distinct nibbles for every byte
            const uint8_t val = static_cast<uint8_t>(((y * 16U + b * 2U) & 0x0FU) << 4U |
                                                     ((y * 16U + b * 2U + 1U) & 0x0FU));
            tmem_unswapped[y * stride + b] = val;

            // Pre-swap odd rows by 4 bytes (b ^ 4)
            const bool is_odd = ((y & 1U) != 0U);
            const uint32_t dest_b = is_odd ? (b ^ 4U) : b;
            tmem_preswapped[y * stride + dest_b] = val;
        }
    }

    std::vector<uint32_t> out_unswapped;
    dkr::runtime::DecodeTMEMToRGBA(tmem_unswapped.data(), 4, 0, 0, 0, width, height, stride, out_unswapped, false);

    std::vector<uint32_t> out_preswapped;
    dkr::runtime::DecodeTMEMToRGBA(tmem_preswapped.data(), 4, 0, 0, 0, width, height, stride, out_preswapped, true);

    assert(out_unswapped.size() == width * height);
    assert(out_preswapped.size() == width * height);

    for (size_t i = 0; i < out_unswapped.size(); ++i) {
        assert(out_unswapped[i] == out_preswapped[i]);
    }

    // Verify that without unswapping, the pre-swapped data mismatches on odd rows
    std::vector<uint32_t> out_no_unswap;
    dkr::runtime::DecodeTMEMToRGBA(tmem_preswapped.data(), 4, 0, 0, 0, width, height, stride, out_no_unswap, false);
    bool had_mismatch = false;
    for (size_t i = 0; i < out_unswapped.size(); ++i) {
        if (out_unswapped[i] != out_no_unswap[i]) {
            had_mismatch = true;
            break;
        }
    }
    assert(had_mismatch);

    std::printf("[test] TestOddLineSwapI4 PASSED\n");
}

void TestTaskCountFallback() {
    std::printf("[test] Running TestTaskCountFallback...\n");
    uint64_t count = dkr::runtime::completed_f3ddkr_task_count();
    std::printf("[test] completed_f3ddkr_task_count returned %llu\n", static_cast<unsigned long long>(count));
    std::printf("[test] TestTaskCountFallback PASSED\n");
}

void TestLoaderBoundsRegression() {
    std::printf("[test] Running TestLoaderBoundsRegression...\n");

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);
    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);

    const EGLint config_attribs[] = {
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_BLUE_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_RED_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);
    assert(num_configs > 0);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 320,
        EGL_HEIGHT, 240,
        EGL_NONE
    };
    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    assert(surface != EGL_NO_SURFACE);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    assert(context != EGL_NO_CONTEXT);
    eglMakeCurrent(display, surface, surface, context);

    dkr::runtime::F3DDKRGLESBridge bridge;
    bridge.init();

    // 8 MB buffer snapshot
    std::vector<uint8_t> rdram(0x00800000, 0);

    const uint32_t dl_addr = 0x20000;
    uint32_t dl_idx = 0;
    auto emit_cmd = [&](uint32_t w0, uint32_t w1) {
        std::memcpy(rdram.data() + dl_addr + dl_idx * 8U, &w0, sizeof(w0));
        std::memcpy(rdram.data() + dl_addr + dl_idx * 8U + 4U, &w1, sizeof(w1));
        ++dl_idx;
    };

    // SetTile with line = 4
    emit_cmd(0xF5100800U, 0x00000000U);
    // SetTImg at 0x7FFFF0
    emit_cmd(0xFD10000FU, 0x007FFFF0U);
    // LoadTile with sh < sl
    emit_cmd(0xF4028000U, 0x00014028U);
    // LoadTile with th < tl
    emit_cmd(0xF4000028U, 0x00028014U);
    // LoadBlock with lrs = 0xFFF
    emit_cmd(0xF3000000U, 0x00FFF000U);
    // G_ENDDL
    emit_cmd(0xB8000000U, 0x00000000U);

    bridge.execute_display_list(dl_addr, rdram.data());
    bridge.flush_batch();

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestLoaderBoundsRegression PASSED\n");
}

void TestDisplayListFuzz() {
    std::printf("[test] Running TestDisplayListFuzz (10000 commands)...\n");

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);
    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);

    const EGLint config_attribs[] = {
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);
    assert(num_configs > 0);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 320,
        EGL_HEIGHT, 240,
        EGL_NONE
    };
    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    assert(surface != EGL_NO_SURFACE);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    assert(context != EGL_NO_CONTEXT);
    eglMakeCurrent(display, surface, surface, context);

    dkr::runtime::F3DDKRGLESBridge bridge;
    bridge.init();

    std::vector<uint8_t> rdram(0x00800000, 0);
    uint64_t rng = 0x12345678DEADBEEFULL;
    auto next_u32 = [&]() -> uint32_t {
        rng ^= rng >> 12;
        rng ^= rng << 25;
        rng ^= rng >> 27;
        return static_cast<uint32_t>((rng * 0x2545F4914F6CDD1DULL) >> 32);
    };

    // Emit 10,000 random 64-bit commands at random addresses
    const uint32_t fuzz_dl_addr = 0x200000;
    for (uint32_t i = 0; i < 10000; ++i) {
        uint32_t w0 = next_u32();
        uint32_t w1 = next_u32();
        std::memcpy(rdram.data() + fuzz_dl_addr + i * 8U, &w0, 4);
        std::memcpy(rdram.data() + fuzz_dl_addr + i * 8U + 4U, &w1, 4);
    }

    // Execute at multiple random entry points inside the fuzz buffer
    for (int iter = 0; iter < 100; ++iter) {
        uint32_t start_addr = fuzz_dl_addr + ((next_u32() % 9900) * 8U);
        bridge.execute_display_list(start_addr, rdram.data());
        bridge.flush_batch();
    }

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestDisplayListFuzz PASSED\n");
}

void TestPerspectiveFog() {
    std::printf("[test] Running TestPerspectiveFog...\n");

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);

    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);
    eglBindAPI(EGL_OPENGL_ES_API);

    const EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 64,
        EGL_HEIGHT, 64,
        EGL_NONE
    };
    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    eglMakeCurrent(display, surface, surface, context);

    dkr::runtime::F3DDKRGLESBridge bridge;
    bridge.init();

    std::vector<uint8_t> rdram(0x00800000, 0);

    // 1. Write identity projection matrix at 0x10000
    const uint32_t mtx_addr = 0x10000;
    for (int i = 0; i < 4; ++i) {
        const uint32_t idx = static_cast<uint32_t>((i * 4 + i) * 2);
        int16_t int_val = 1;
        uint16_t frac_val = 0;
        std::memcpy(rdram.data() + ((mtx_addr + idx) ^ 2U), &int_val, sizeof(int_val));
        std::memcpy(rdram.data() + ((mtx_addr + 32U + idx) ^ 2U), &frac_val, sizeof(frac_val));
    }

    // 2. Write 3 vertices at 0x20000 with distinct alpha (0x80 = 128/255)
    const uint32_t vtx_addr = 0x20000;
    auto write_vtx = [&](uint32_t addr, int16_t x, int16_t y, int16_t z, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        std::memcpy(rdram.data() + ((addr + 0U) ^ 2U), &x, sizeof(x));
        std::memcpy(rdram.data() + ((addr + 2U) ^ 2U), &y, sizeof(y));
        std::memcpy(rdram.data() + ((addr + 4U) ^ 2U), &z, sizeof(z));
        rdram[(addr + 6U) ^ 3U] = r;
        rdram[(addr + 7U) ^ 3U] = g;
        rdram[(addr + 8U) ^ 3U] = b;
        rdram[(addr + 9U) ^ 3U] = a;
    };
    write_vtx(vtx_addr + 0,  -10, -10, 0, 200, 200, 200, 128);
    write_vtx(vtx_addr + 10,  10, -10, 0, 200, 200, 200, 128);
    write_vtx(vtx_addr + 20,   0,  10, 0, 200, 200, 200, 128);

    // 3. Write 16-byte triangle command at 0x21000
    const uint32_t tri_addr = 0x21000;
    rdram[tri_addr + 0] = 0x40; // flag (no culling)
    rdram[tri_addr + 1] = 0;    // v0
    rdram[tri_addr + 2] = 1;    // v1
    rdram[tri_addr + 3] = 2;    // v2

    // 4. Build Display List at 0x30000
    const uint32_t dl_addr = 0x30000;
    uint32_t dl_idx = 0;
    auto emit_cmd = [&](uint32_t w0, uint32_t w1) {
        std::memcpy(rdram.data() + dl_addr + dl_idx * 8U, &w0, sizeof(w0));
        std::memcpy(rdram.data() + dl_addr + dl_idx * 8U + 4U, &w1, sizeof(w1));
        ++dl_idx;
    };

    // G_MTX: Load projection matrix
    emit_cmd(0x01000000U, mtx_addr);
    // G_SETOTHERMODE: enable blender fog (P=G_BL_CLR_FOG (3), A=G_BL_A_SHADE (2))
    emit_cmd(0xEF000000U, 0xC8000030U);
    // G_SETGEOMETRYMODE: G_FOG (0x00010000U)
    emit_cmd(0xB7000000U, 0x00010000U);
    // G_MOVEWORD: G_MW_FOG (0x08U) -> mul = 500 (0x01F4), off = -100 (0xFF9C)
    emit_cmd(0xBC000008U, 0x01F4FF9CU);
    // G_SETFOGCOLOR: (128, 64, 192, 255)
    emit_cmd(0xF8000000U, 0x8040C0FFU);
    // G_VTX_F3DDKR: 3 vertices
    emit_cmd(0x04100000U, vtx_addr);
    // G_TRI_F3DDKR: 1 triangle
    emit_cmd(0x05000000U, tri_addr);
    // G_ENDDL
    emit_cmd(0xB8000000U, 0x00000000U);

    bridge.execute_display_list(dl_addr, rdram.data());

    // Check state:
    // Fog multiplier and offset should match w1
    assert(bridge.debug_state().fog_mul == 0x01F4);
    assert(bridge.debug_state().fog_off == static_cast<int16_t>(0xFF9CU));
    assert(bridge.debug_state().fog_enabled == true);
    assert((bridge.debug_state().geometry_mode & 0x00010000U) != 0U);

    // Verify vertex alpha was NOT overwritten by CPU fog (should be 128 / 255.0f ≈ 0.50196f)
    const float loaded_alpha = bridge.debug_state().vertex_cache[0].a;
    assert(std::fabs(loaded_alpha - (128.0f / 255.0f)) < 1e-3f);

    bridge.flush_batch();

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestPerspectiveFog PASSED\n");
}

void TestTriStateGLCache() {
    std::printf("[test] Running TestTriStateGLCache...\n");

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);

    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);
    eglBindAPI(EGL_OPENGL_ES_API);

    const EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    assert(context != EGL_NO_CONTEXT);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 640,
        EGL_HEIGHT, 480,
        EGL_NONE
    };
    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    assert(surface != EGL_NO_SURFACE);

    eglMakeCurrent(display, surface, surface, context);

    dkr::runtime::F3DDKRGLESBridge bridge;
    bridge.init();
    bridge.set_viewport(0, 0, 640, 480);

    // Force GL state directly away from what will be requested
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_ALWAYS);

    // Invalidate bridge cache to set trackers to unknown (-1/0)
    bridge.invalidate_gl_cache();

    // Prepare simulated RDRAM
    constexpr uint32_t kRDRAMSize = 0x00800000U;
    std::vector<uint8_t> rdram(kRDRAMSize, 0);

    const uint32_t mtx_addr = 0x10000;
    for (int i = 0; i < 4; ++i) {
        const uint32_t idx = static_cast<uint32_t>((i * 4 + i) * 2);
        int16_t int_val = 1;
        uint16_t frac_val = 0;
        std::memcpy(rdram.data() + ((mtx_addr + idx) ^ 2U), &int_val, sizeof(int_val));
        std::memcpy(rdram.data() + ((mtx_addr + 32U + idx) ^ 2U), &frac_val, sizeof(frac_val));
    }

    const uint32_t vtx_addr = 0x20000;
    auto write_vtx = [&](uint32_t addr, int16_t x, int16_t y, int16_t z, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        std::memcpy(rdram.data() + ((addr + 0U) ^ 2U), &x, sizeof(x));
        std::memcpy(rdram.data() + ((addr + 2U) ^ 2U), &y, sizeof(y));
        std::memcpy(rdram.data() + ((addr + 4U) ^ 2U), &z, sizeof(z));
        rdram[(addr + 6U) ^ 3U] = r;
        rdram[(addr + 7U) ^ 3U] = g;
        rdram[(addr + 8U) ^ 3U] = b;
        rdram[(addr + 9U) ^ 3U] = a;
    };
    write_vtx(vtx_addr + 0,  -10, -10, 0, 200, 200, 200, 128);
    write_vtx(vtx_addr + 10,  10, -10, 0, 200, 200, 200, 128);
    write_vtx(vtx_addr + 20,   0,  10, 0, 200, 200, 200, 128);

    const uint32_t tri_addr = 0x21000;
    rdram[tri_addr + 0] = 0x40; // flag (no culling)
    rdram[tri_addr + 1] = 0;    // v0
    rdram[tri_addr + 2] = 1;    // v1
    rdram[tri_addr + 3] = 2;    // v2

    const uint32_t dl_addr = 0x30000;
    uint32_t dl_idx = 0;
    auto emit_cmd = [&](uint32_t w0, uint32_t w1) {
        std::memcpy(rdram.data() + dl_addr + dl_idx * 8U, &w0, sizeof(w0));
        std::memcpy(rdram.data() + dl_addr + dl_idx * 8U + 4U, &w1, sizeof(w1));
        ++dl_idx;
    };

    // G_MTX
    emit_cmd(0x01000000U, mtx_addr);
    // G_SETOTHERMODE: Z_COMPARE (bit 4) on, Z_UPD (bit 5) off
    emit_cmd(0xEF000000U, 0x00000010U);
    // G_VTX_F3DDKR: 3 vertices
    emit_cmd(0x04100000U, vtx_addr);
    // G_TRI_F3DDKR: 1 triangle
    emit_cmd(0x05000000U, tri_addr);
    // G_ENDDL
    emit_cmd(0xB8000000U, 0x00000000U);

    bridge.execute_display_list(dl_addr, rdram.data());
    bridge.flush_batch();

    // Verify GL state: depth mask should be GL_FALSE, depth func should be GL_LEQUAL
    GLboolean depth_mask = GL_TRUE;
    glGetBooleanv(GL_DEPTH_WRITEMASK, &depth_mask);
    assert(depth_mask == GL_FALSE);

    GLint depth_func = 0;
    glGetIntegerv(GL_DEPTH_FUNC, &depth_func);
    assert(depth_func == GL_LEQUAL);

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestTriStateGLCache PASSED\n");
}

void TestTMEMHashCollision() {
    std::printf("[test] Running TestTMEMHashCollision...\n");
    uint8_t buf1[64] = {0};
    uint8_t buf2[64] = {0};
    // Two 64-byte buffers that differ only in bit 7 of byte 7 and byte 15
    buf1[7] = 0x80;
    buf2[15] = 0x80;

    uint64_t h1 = dkr::runtime::HashTMEM(buf1, 0, 64);
    uint64_t h2 = dkr::runtime::HashTMEM(buf2, 0, 64);
    assert(h1 != h2);
    assert(h1 != 0);
    assert(h2 != 0);
    std::printf("[test] TestTMEMHashCollision PASSED\n");
}

void TestNestedDLStackIsolation() {
    std::printf("[test] Running TestNestedDLStackIsolation...\n");

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);

    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);
    eglBindAPI(EGL_OPENGL_ES_API);

    const EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    assert(context != EGL_NO_CONTEXT);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 640,
        EGL_HEIGHT, 480,
        EGL_NONE
    };
    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    assert(surface != EGL_NO_SURFACE);

    eglMakeCurrent(display, surface, surface, context);

    dkr::runtime::F3DDKRGLESBridge bridge;
    bridge.init();
    bridge.set_viewport(0, 0, 640, 480);

    constexpr uint32_t kRDRAMSize = 0x00800000U;
    std::vector<uint8_t> rdram(kRDRAMSize, 0);

    // Matrix at 0x10000
    const uint32_t mtx_addr = 0x10000;
    for (int i = 0; i < 4; ++i) {
        const uint32_t idx = static_cast<uint32_t>((i * 4 + i) * 2);
        int16_t int_val = 1;
        uint16_t frac_val = 0;
        std::memcpy(rdram.data() + ((mtx_addr + idx) ^ 2U), &int_val, sizeof(int_val));
        std::memcpy(rdram.data() + ((mtx_addr + 32U + idx) ^ 2U), &frac_val, sizeof(frac_val));
    }

    // Vertices at 0x20000
    const uint32_t vtx_addr = 0x20000;
    auto write_vtx = [&](uint32_t addr, int16_t x, int16_t y, int16_t z, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        std::memcpy(rdram.data() + ((addr + 0U) ^ 2U), &x, sizeof(x));
        std::memcpy(rdram.data() + ((addr + 2U) ^ 2U), &y, sizeof(y));
        std::memcpy(rdram.data() + ((addr + 4U) ^ 2U), &z, sizeof(z));
        rdram[(addr + 6U) ^ 3U] = r;
        rdram[(addr + 7U) ^ 3U] = g;
        rdram[(addr + 8U) ^ 3U] = b;
        rdram[(addr + 9U) ^ 3U] = a;
    };
    write_vtx(vtx_addr + 0,  -10, -10, 0, 255, 255, 255, 255);
    write_vtx(vtx_addr + 10,  10, -10, 0, 255, 255, 255, 255);
    write_vtx(vtx_addr + 20,   0,  10, 0, 255, 255, 255, 255);

    // Triangle at 0x21000
    const uint32_t tri_addr = 0x21000;
    rdram[tri_addr + 0] = 0x40; // flag (no culling)
    rdram[tri_addr + 1] = 0;    // v0
    rdram[tri_addr + 2] = 1;    // v1
    rdram[tri_addr + 3] = 2;    // v2

    auto emit = [&](uint32_t base, uint32_t idx, uint32_t w0, uint32_t w1) {
        std::memcpy(rdram.data() + base + idx * 8U, &w0, sizeof(w0));
        std::memcpy(rdram.data() + base + idx * 8U + 4U, &w1, sizeof(w1));
    };

    // 1. Leaf DL at 0x50000: draws 1 triangle, then G_ENDDL
    const uint32_t leaf_dl = 0x50000;
    emit(leaf_dl, 0, 0x04100000U, vtx_addr); // G_VTX
    emit(leaf_dl, 1, 0x05000000U, tri_addr); // G_TRI
    emit(leaf_dl, 2, 0xB8000000U, 0x00000000U); // G_ENDDL

    // 2. Counted DL at 0x40000: 1 command calling leaf DL with G_DL (non-branch)
    const uint32_t counted_dl = 0x40000;
    emit(counted_dl, 0, 0x06000000U, leaf_dl); // G_DL -> leaf_dl

    // 3. Intermediate DL at 0x38000: invokes counted DL (1 command), then G_ENDDL
    const uint32_t inter_dl = 0x38000;
    emit(inter_dl, 0, 0x07010000U, counted_dl); // G_COUNTEDDL: count=1, addr=counted_dl
    emit(inter_dl, 1, 0xB8000000U, 0x00000000U); // G_ENDDL

    // 4. Outer DL at 0x30000: sets MTX, calls intermediate DL with G_DL (pushing stack), then G_ENDDL
    const uint32_t outer_dl = 0x30000;
    emit(outer_dl, 0, 0x01000000U, mtx_addr); // G_MTX
    emit(outer_dl, 1, 0x06000000U, inter_dl); // G_DL -> inter_dl (pushes outer_dl return addr)
    emit(outer_dl, 2, 0xB8000000U, 0x00000000U); // G_ENDDL

    bridge.execute_display_list(outer_dl, rdram.data());
    bridge.flush_batch();

    // Leaf's triangle must be drawn exactly once
    assert(bridge.tri_count() == 1);

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestNestedDLStackIsolation PASSED\n");
}

void TestSamplerStateDecoupling() {
    std::printf("[test] Running TestSamplerStateDecoupling...\n");

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);

    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);
    eglBindAPI(EGL_OPENGL_ES_API);

    const EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    assert(context != EGL_NO_CONTEXT);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 64,
        EGL_HEIGHT, 64,
        EGL_NONE
    };
    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    assert(surface != EGL_NO_SURFACE);
    eglMakeCurrent(display, surface, surface, context);

    dkr::runtime::F3DDKRGLESBridge bridge;
    bridge.init();

    std::vector<uint8_t> rdram(1024 * 1024, 0);

    // Matrix
    const uint32_t mtx_addr = 0x10000;
    dkr::runtime::F3DGLESMtx identity = dkr::runtime::F3DGLESMtx::identity();
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            int32_t val = static_cast<int32_t>(identity.m[r][c] * 65536.0f);
            uint16_t int_part = static_cast<uint16_t>((val >> 16) & 0xFFFF);
            uint16_t frac_part = static_cast<uint16_t>(val & 0xFFFF);
            std::memcpy(rdram.data() + mtx_addr + (r * 4 + c) * 2, &int_part, 2);
            std::memcpy(rdram.data() + mtx_addr + 32 + (r * 4 + c) * 2, &frac_part, 2);
        }
    }

    // Dummy RGBA16 texture at 0x20000 (32x32 = 2048 bytes)
    const uint32_t tex_addr = 0x20000;
    for (uint32_t i = 0; i < 1024; ++i) {
        uint16_t color = 0xF801; // Red
        std::memcpy(rdram.data() + tex_addr + i * 2, &color, 2);
    }

    // Vertex data at 0x15000
    const uint32_t vtx_addr = 0x15000;
    int16_t raw_vtx[3][8] = {
        { -10, -10, -50, 0, 0, 0, (int16_t)0xFF00, (int16_t)0x00FF },
        {  10, -10, -50, 0, 31, 0, (int16_t)0x00FF, (int16_t)0x00FF },
        {   0,  10, -50, 0, 16, 31, (int16_t)0x0000, (int16_t)0xFFFF }
    };
    std::memcpy(rdram.data() + vtx_addr, raw_vtx, sizeof(raw_vtx));

    const uint32_t tri_addr = 0x16000;
    uint8_t tri_cmd[8] = { 0, 0, 0, 0, 0, 1, 2, 0 };
    std::memcpy(rdram.data() + tri_addr, tri_cmd, sizeof(tri_cmd));

    auto emit = [&](uint32_t base, uint32_t idx, uint32_t w0, uint32_t w1) {
        std::memcpy(rdram.data() + base + idx * 8U, &w0, sizeof(w0));
        std::memcpy(rdram.data() + base + idx * 8U + 4U, &w1, sizeof(w1));
    };

    // DL 1: LoadBlock texture, set tile 0 with repeat (clamp_s=0, mask_s=5), draw triangle
    const uint32_t dl1 = 0x30000;
    emit(dl1, 0, 0x01000000U, mtx_addr); // G_MTX
    emit(dl1, 1, 0xFD000000U, tex_addr); // G_SETTIMG
    emit(dl1, 2, 0xF5100000U, 0x07000000U); // G_SETTILE: fmt=RGBA(0), size=16(2), line=0, tmem=0
    emit(dl1, 3, 0xF3000000U, 0x073FF000U); // G_LOADBLOCK: tile 7, texels=1023
    emit(dl1, 4, 0xF5100400U, 0x00000155U); // G_SETTILE: tile 0, RGBA16, line=8, clamp_s=0, mask_s=5
    emit(dl1, 5, 0xF2000000U, 0x0007C07CU); // G_SETTILESIZE: tile 0, 32x32
    emit(dl1, 6, 0x04100000U, vtx_addr); // G_VTX
    emit(dl1, 7, 0x05000000U, tri_addr); // G_TRI
    emit(dl1, 8, 0xB8000000U, 0x00000000U); // G_ENDDL

    bridge.execute_display_list(dl1, rdram.data());
    bridge.flush_batch();

    assert(bridge.tex_misses() == 1);
    assert(bridge.tex_hits() == 0);

    // DL 2: same texture in TMEM, but tile 0 with clamp_s=1 (clamp mode)
    const uint32_t dl2 = 0x32000;
    emit(dl2, 0, 0xF5100400U, 0x00000255U); // G_SETTILE: tile 0, RGBA16, line=8, clamp_s=1, mask_s=5
    emit(dl2, 1, 0x04100000U, vtx_addr); // G_VTX
    emit(dl2, 2, 0x05000000U, tri_addr); // G_TRI
    emit(dl2, 3, 0xB8000000U, 0x00000000U); // G_ENDDL

    bridge.execute_display_list(dl2, rdram.data());
    bridge.flush_batch();

    // Must be a texture cache HIT (sampler updated in place without duplicate texture)
    assert(bridge.tex_misses() == 1);
    assert(bridge.tex_hits() == 1);

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestSamplerStateDecoupling PASSED\n");
}

void TestP2Batching() {
    using namespace dkr::runtime;
    std::printf("[test] Running TestP2Batching...\n");

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);

    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);
    eglBindAPI(EGL_OPENGL_ES_API);

    const EGLint config_attribs[] = {
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_BLUE_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_RED_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE
    };

    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);
    assert(num_configs > 0);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };

    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    assert(context != EGL_NO_CONTEXT);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 640,
        EGL_HEIGHT, 480,
        EGL_NONE
    };

    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    assert(surface != EGL_NO_SURFACE);

    eglMakeCurrent(display, surface, surface, context);

    std::vector<uint8_t> rdram(0x100000, 0);
    F3DDKRGLESBridge bridge;
    bridge.init();
    bridge.set_viewport(0, 0, 640, 480);

    auto emit = [&](uint32_t base, uint32_t idx, uint32_t w0, uint32_t w1) {
        std::memcpy(rdram.data() + base + idx * 8U, &w0, sizeof(w0));
        std::memcpy(rdram.data() + base + idx * 8U + 4U, &w1, sizeof(w1));
    };

    // 1. Test consecutive FILL rects:
    // Set othermode cycle type to 3 (FILL mode)
    // Set fill color
    // Draw 4 fill rects
    // End DL
    const uint32_t fill_dl = 0x20000;
    emit(fill_dl, 0, 0xEF000000U, 0x00300000U); // G_RDPSETOTHERMODE: cycle_type = 3 (FILL)
    emit(fill_dl, 1, 0xF7000000U, 0xFF00FF00U); // G_SETFILLCOLOR
    emit(fill_dl, 2, 0xF6014014U, 0x00000000U); // G_FILLRECT: (0,0) to (5,5)
    emit(fill_dl, 3, 0xF6028028U, 0x00014014U); // G_FILLRECT: (5,5) to (10,10)
    emit(fill_dl, 4, 0xF603C03CU, 0x00028028U); // G_FILLRECT: (10,10) to (15,15)
    emit(fill_dl, 5, 0xF6050050U, 0x0003C03CU); // G_FILLRECT: (15,15) to (20,20)
    emit(fill_dl, 6, 0xB8000000U, 0x00000000U); // G_ENDDL

    assert(bridge.draw_calls() == 0);
    bridge.execute_display_list(fill_dl, rdram.data());

    // During DL execution, rects must NOT have flushed individually!
    // Total draw calls before flush_batch should be 0.
    assert(bridge.draw_calls() == 0);
    assert(bridge.current_batch().kind == BatchKind::Rect2D);
    assert(bridge.current_batch().ovr == DrawOverride::FillShade);

    bridge.flush_batch(FlushReason::EndTask);
    // All 4 fill rects must have been drawn in exactly 1 draw call!
    assert(bridge.draw_calls() == 1);
    assert(bridge.flush_reasons()[static_cast<size_t>(FlushReason::FillRect)] == 0);

    // 2. State preservation:
    // Set a custom combiner and enable blending in othermode
    const uint32_t comb_dl = 0x25000;
    emit(comb_dl, 0, 0xEF000000U, 0x0000C000U); // G_RDPSETOTHERMODE: 1-cycle, blend enabled (0xC000)
    emit(comb_dl, 1, 0xFC123456U, 0x789ABCDEU); // G_SETCOMBINE: custom combiner
    emit(comb_dl, 2, 0xB8000000U, 0x00000000U); // G_ENDDL
    bridge.execute_display_list(comb_dl, rdram.data());

    const auto saved_cc_a = bridge.debug_state().cc_a;
    const auto saved_cc_b = bridge.debug_state().cc_b;
    const bool saved_blend = bridge.debug_state().blend_enabled;

    // Now execute 3 consecutive FILL rects
    const uint32_t fill_dl2 = 0x26000;
    emit(fill_dl2, 0, 0xEF000000U, 0x00300000U); // cycle_type = 3 (FILL)
    emit(fill_dl2, 1, 0xF6014014U, 0x00000000U); // G_FILLRECT
    emit(fill_dl2, 2, 0xF6028028U, 0x00014014U); // G_FILLRECT
    emit(fill_dl2, 3, 0xF603C03CU, 0x00028028U); // G_FILLRECT
    emit(fill_dl2, 4, 0xB8000000U, 0x00000000U); // G_ENDDL
    bridge.execute_display_list(fill_dl2, rdram.data());

    // Batched fill rects should not have flushed yet
    assert(bridge.draw_calls() == 1);
    bridge.flush_batch(FlushReason::EndTask);
    // Exactly 1 new draw call for the 3 fill rects
    assert(bridge.draw_calls() == 2);

    // Verify combiner and blend mode in state_ were NOT clobbered by the fill rect override!
    assert(bridge.debug_state().cc_a == saved_cc_a);
    assert(bridge.debug_state().cc_b == saved_cc_b);
    assert(bridge.debug_state().blend_enabled == saved_blend);

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestP2Batching PASSED\n");
}

void TestSpecializedCombinerShaders() {
    std::printf("[test] Running TestSpecializedCombinerShaders...\n");

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);

    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);
    eglBindAPI(EGL_OPENGL_ES_API);

    const EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    assert(context != EGL_NO_CONTEXT);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 64,
        EGL_HEIGHT, 64,
        EGL_NONE
    };
    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    assert(surface != EGL_NO_SURFACE);

    eglMakeCurrent(display, surface, surface, context);

    using namespace dkr::runtime;

    std::vector<uint8_t> rdram(0x00800000, 0);

    F3DDKRGLESBridge bridge;
    bridge.init();
    bridge.set_viewport(0, 0, 64, 64);

    // 1. Identity projection matrix at 0x10000
    const uint32_t mtx_addr = 0x10000;
    for (int i = 0; i < 4; ++i) {
        const uint32_t idx = static_cast<uint32_t>((i * 4 + i) * 2);
        int16_t int_val = 1;
        uint16_t frac_val = 0;
        std::memcpy(rdram.data() + ((mtx_addr + idx) ^ 2U), &int_val, sizeof(int_val));
        std::memcpy(rdram.data() + ((mtx_addr + 32U + idx) ^ 2U), &frac_val, sizeof(frac_val));
    }

    // 2. Texture at 0x11000 (16x16 RGBA16 texture, filled with 0x9333: R=18, G=12, B=25, A=1)
    const uint32_t tex_addr = 0x11000;
    const uint16_t tex_color = 0x9333; // 5-5-5-1
    for (uint32_t i = 0; i < 256; ++i) {
        rdram[tex_addr + i * 2 + 0] = static_cast<uint8_t>(tex_color >> 8);
        rdram[tex_addr + i * 2 + 1] = static_cast<uint8_t>(tex_color & 0xFF);
    }

    // 3. 4 Vertices at 0x20000: covering full viewport NDC [-1, 1], with vertex color (140, 160, 180, 240)
    const uint32_t vtx_addr = 0x20000;
    auto write_vtx = [&](uint32_t addr, int16_t x, int16_t y, int16_t z, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        std::memcpy(rdram.data() + ((addr + 0U) ^ 2U), &x, sizeof(x));
        std::memcpy(rdram.data() + ((addr + 2U) ^ 2U), &y, sizeof(y));
        std::memcpy(rdram.data() + ((addr + 4U) ^ 2U), &z, sizeof(z));
        rdram[(addr + 6U) ^ 3U] = r;
        rdram[(addr + 7U) ^ 3U] = g;
        rdram[(addr + 8U) ^ 3U] = b;
        rdram[(addr + 9U) ^ 3U] = a;
    };
    write_vtx(vtx_addr + 0,  -1, -1, 0, 140, 160, 180, 240);
    write_vtx(vtx_addr + 10,  1, -1, 0, 140, 160, 180, 240);
    write_vtx(vtx_addr + 20,  1,  1, 0, 140, 160, 180, 240);
    write_vtx(vtx_addr + 30, -1,  1, 0, 140, 160, 180, 240);

    // 4. 2 Triangles at 0x21000 forming a quad
    const uint32_t tri_addr = 0x21000;
    auto write_tri = [&](uint32_t addr, uint8_t v0, uint8_t v1, uint8_t v2) {
        rdram[(addr + 0U) ^ 3U] = 0x40; // flag (no culling)
        rdram[(addr + 1U) ^ 3U] = v0;
        rdram[(addr + 2U) ^ 3U] = v1;
        rdram[(addr + 3U) ^ 3U] = v2;
        int16_t s = 0, t = 0;
        std::memcpy(rdram.data() + ((addr + 4U) ^ 2U), &s, sizeof(s));
        std::memcpy(rdram.data() + ((addr + 6U) ^ 2U), &t, sizeof(t));
        std::memcpy(rdram.data() + ((addr + 8U) ^ 2U), &s, sizeof(s));
        std::memcpy(rdram.data() + ((addr + 10U) ^ 2U), &t, sizeof(t));
        std::memcpy(rdram.data() + ((addr + 12U) ^ 2U), &s, sizeof(s));
        std::memcpy(rdram.data() + ((addr + 14U) ^ 2U), &t, sizeof(t));
    };
    write_tri(tri_addr + 0, 0, 1, 2);
    write_tri(tri_addr + 16, 0, 2, 3);

    const uint32_t dl_addr = 0x30000;

    auto make_combine = [](uint32_t a0, uint32_t b0, uint32_t c0, uint32_t d0,
                           uint32_t Aa0, uint32_t Ab0, uint32_t Ac0, uint32_t Ad0,
                           uint32_t a1 = 0, uint32_t b1 = 0, uint32_t c1 = 0, uint32_t d1 = 0,
                           uint32_t Aa1 = 0, uint32_t Ab1 = 0, uint32_t Ac1 = 0, uint32_t Ad1 = 0) {
        uint32_t w0 = 0xFC000000U |
                      ((a0 & 0x0FU) << 20U) | ((c0 & 0x1FU) << 15U) |
                      ((Aa0 & 0x07U) << 12U) | ((Ac0 & 0x07U) << 9U) |
                      ((a1 & 0x0FU) << 5U) | (c1 & 0x1FU);
        uint32_t w1 = ((b0 & 0x0FU) << 28U) | ((b1 & 0x0FU) << 24U) |
                      ((Aa1 & 0x07U) << 21U) | ((Ac1 & 0x07U) << 18U) |
                      ((d0 & 0x07U) << 15U) | ((Ab0 & 0x07U) << 12U) |
                      ((Ad0 & 0x07U) << 9U) | ((d1 & 0x07U) << 6U) |
                      ((Ab1 & 0x07U) << 3U) | (Ad1 & 0x07U);
        return std::make_pair(w0, w1);
    };

    constexpr uint32_t C_COMB = 0, C_TEX0 = 1, C_TEX1 = 2, C_PRIM = 3, C_SHADE = 4, C_ENV = 5, C_1 = 6;
    constexpr uint32_t C_0 = 15, C_0_C = 31, C_LOD = 14;
    constexpr uint32_t A_COMB = 0, A_TEX0 = 1, A_TEX1 = 2, A_PRIM = 3, A_SHADE = 4, A_ENV = 5, A_1 = 6, A_0 = 7, A_LOD = 6;

    struct TestCase {
        const char* name;
        uint32_t w0;
        uint32_t w1;
        bool two_cycle = false;
        bool use_tex = true;
        uint8_t alpha_mode = 0;
        bool fog = false;
        bool is_copy_rect = false;
        bool is_fill_rect = false;
    };

    std::vector<TestCase> cases;

    auto add_case = [&](const char* name, std::pair<uint32_t, uint32_t> p, bool two_cyc = false, bool tex = true, uint8_t a_mode = 0, bool fog_en = false, bool copy_r = false, bool fill_r = false) {
        cases.push_back({name, p.first, p.second, two_cyc, tex, a_mode, fog_en, copy_r, fill_r});
    };

    // 1. G_CC_PRIMITIVE
    add_case("G_CC_PRIMITIVE", make_combine(C_0, C_0, C_0_C, C_PRIM, A_0, A_0, A_0, A_PRIM), false, false);
    // 2. G_CC_SHADE
    add_case("G_CC_SHADE", make_combine(C_0, C_0, C_0_C, C_SHADE, A_0, A_0, A_0, A_SHADE), false, false);
    // 3. G_CC_MODULATERGBA
    add_case("G_CC_MODULATERGBA", make_combine(C_TEX0, C_0, C_SHADE, C_0, A_TEX0, A_0, A_SHADE, A_0));
    // 4. G_CC_MODULATEIDECALA
    add_case("G_CC_MODULATEIDECALA", make_combine(C_TEX0, C_0, C_SHADE, C_0, A_0, A_0, A_0, A_TEX0));
    // 5. G_CC_MODULATEIA_PRIM
    add_case("G_CC_MODULATEIA_PRIM", make_combine(C_TEX0, C_0, C_PRIM, C_0, A_TEX0, A_0, A_PRIM, A_0));
    // 6. G_CC_DECALRGBA
    add_case("G_CC_DECALRGBA", make_combine(C_0, C_0, C_0_C, C_TEX0, A_0, A_0, A_0, A_TEX0));
    // 7. G_CC_BLENDI
    add_case("G_CC_BLENDI", make_combine(C_ENV, C_SHADE, C_TEX0, C_SHADE, A_0, A_0, A_0, A_SHADE));
    // 8. G_CC_BLENDIA
    add_case("G_CC_BLENDIA", make_combine(C_ENV, C_SHADE, C_TEX0, C_SHADE, A_TEX0, A_0, A_SHADE, A_0));
    // 9. G_CC_HILITERGB
    add_case("G_CC_HILITERGB", make_combine(C_PRIM, C_SHADE, C_TEX0, C_SHADE, A_0, A_0, A_0, A_SHADE));
    // 10. G_CC_ADDRGB
    add_case("G_CC_ADDRGB", make_combine(C_1, C_0, C_TEX0, C_SHADE, A_0, A_0, A_0, A_SHADE));
    // 11. G_CC_REFLECTRGB
    add_case("G_CC_REFLECTRGB", make_combine(C_ENV, C_0, C_TEX0, C_SHADE, A_0, A_0, A_0, A_SHADE));
    // 12. G_CC_BLENDPE
    add_case("G_CC_BLENDPE", make_combine(C_PRIM, C_ENV, C_TEX0, C_ENV, A_TEX0, A_0, A_SHADE, A_0));
    // 13. G_CC_TRILERP (LOD fraction)
    add_case("G_CC_TRILERP", make_combine(C_PRIM, C_ENV, C_LOD, C_ENV, A_PRIM, A_ENV, A_LOD, A_ENV));
    // 14. 2-Cycle PASS2
    add_case("2Cycle_PASS2", make_combine(C_TEX0, C_0, C_SHADE, C_0, A_TEX0, A_0, A_SHADE, A_0, C_0, C_0, C_0_C, C_COMB, A_0, A_0, A_0, A_COMB), true);
    // 15. 2-Cycle MODULATERGBA2
    add_case("2Cycle_MODULATERGBA2", make_combine(C_TEX0, C_0, C_SHADE, C_0, A_TEX0, A_0, A_SHADE, A_0, C_COMB, C_0, C_PRIM, C_0, A_COMB, A_0, A_PRIM, A_0), true);
    // 16. 2-Cycle BLENDI2
    add_case("2Cycle_BLENDI2", make_combine(C_TEX0, C_0, C_SHADE, C_0, A_TEX0, A_0, A_SHADE, A_0, C_ENV, C_SHADE, C_COMB, C_SHADE, A_0, A_0, A_0, A_SHADE), true);
    // 17. 2-Cycle HILITERGB2
    add_case("2Cycle_HILITERGB2", make_combine(C_TEX0, C_0, C_SHADE, C_0, A_0, A_0, A_0, A_SHADE, C_ENV, C_COMB, C_TEX0, C_COMB, A_0, A_0, A_0, A_COMB), true);
    // 18. Alpha-test threshold
    add_case("AlphaTest_Threshold", make_combine(C_TEX0, C_0, C_SHADE, C_0, A_TEX0, A_0, A_SHADE, A_0), false, true, 1 /*threshold*/);
    // 19. Perspective fog
    add_case("Perspective_Fog", make_combine(C_TEX0, C_0, C_SHADE, C_0, A_TEX0, A_0, A_SHADE, A_0), false, true, 0, true /*fog*/);
    // 20. Untextured fallback
    add_case("Untextured_Fallback", make_combine(C_TEX0, C_0, C_SHADE, C_0, A_TEX0, A_0, A_SHADE, A_0), false, false /*tex=false*/);
    // 21. CopyTexel override
    add_case("CopyTexel_Override", {0, 0}, false, true, 0, false, true /*copy_rect*/);
    // 22. FillShade override
    add_case("FillShade_Override", {0, 0}, false, false, 0, false, false, true /*fill_rect*/);

    for (const auto& tc : cases) {
        uint8_t uber_pixels[64] = {0};
        uint8_t spec_pixels[64] = {0};

        auto render = [&](bool use_uber, uint8_t* out_pixels) {
            bridge.set_use_ubershader(use_uber);
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            uint32_t dl_idx = 0;
            auto emit = [&](uint32_t w0, uint32_t w1) {
                std::memcpy(rdram.data() + dl_addr + dl_idx * 8U, &w0, sizeof(w0));
                std::memcpy(rdram.data() + dl_addr + dl_idx * 8U + 4U, &w1, sizeof(w1));
                ++dl_idx;
            };

            // Othermode
            uint32_t om_l = 0x00000000U;
            if (tc.two_cycle) om_l |= 0x00100000U; // cycle_type = 1
            if (tc.is_copy_rect) om_l |= 0x00200000U; // cycle_type = 2
            if (tc.is_fill_rect) om_l |= 0x00300000U; // cycle_type = 3
            if (tc.alpha_mode == 1) om_l |= 0x00000001U; // threshold
            if (tc.fog) om_l |= 0xC8000000U; // fog blend (p=3, a=2)
            emit(0xEF000000U, om_l);

            // Geometry mode
            emit(0xB6000000U, 0xFFFFFFFFU); // clear all
            if (tc.fog) {
                emit(0xB7000000U, 0x00010000U); // set G_FOG
                emit(0xBC000008U, 0x01F4FF9CU); // fog mul and offset
                emit(0xF8000000U, 0x284664FFU); // fog color (40, 70, 100, 255)
            }

            // Colors:
            // Prim color: (200, 150, 100, 220), min_level=128 (lod_frac ~0.5)
            emit(0xFA008000U, 0xC89664DCU);
            // Env color: (60, 90, 120, 210)
            emit(0xFB000000U, 0x3C5A78D2U);
            // Blend color (threshold = 64/255 = 0.25f when alpha_mode == 1)
            emit(0xF9000000U, 0x00000040U);
            // Fill color (for FillShade): (140, 160, 180, 224)
            emit(0xF7000000U, 0x8CA0B4E0U);

            // Combiner
            if (!tc.is_copy_rect && !tc.is_fill_rect) {
                emit(tc.w0, tc.w1);
            }

            // Texture setup
            emit(0xFD10000FU, tex_addr); // RGBA16, width 16
            emit(0xF5100000U, 0x00000000U); // tile 0
            emit(0xF2000000U, 0x0003C03CU); // tile size 16x16
            emit(0xF3000000U, 0x000FF000U); // load block 256 texels

            if (tc.is_fill_rect) {
                emit(0xF65003C0U, 0x00000000U); // G_FILLRECT from (0,0) to (320, 240)
            } else if (tc.is_copy_rect) {
                emit(0xE45003C0U, 0x00000000U); // G_TEXRECT from (0,0) to (320, 240)
                emit(0x00000000U, 0x00000000U); // s=0, t=0
                emit(0x00000000U, 0x04000400U); // dsdx=1024, dtdy=1024
            } else {
                emit(0x01000000U, mtx_addr); // G_MTX
                emit(0x04180000U, vtx_addr); // G_VTX: 4 vertices
                const uint32_t tex_flag = tc.use_tex ? (1U << 16U) : 0U;
                emit(0x05000000U | (1U << 20U) | tex_flag, tri_addr); // G_TRI: 2 triangles
            }

            emit(0xB8000000U, 0x00000000U); // G_ENDDL

            bridge.execute_display_list(dl_addr, rdram.data());
            bridge.flush_batch(FlushReason::EndTask);

            glReadPixels(0, 0, 4, 4, GL_RGBA, GL_UNSIGNED_BYTE, out_pixels);
        };

        render(true, uber_pixels);
        render(false, spec_pixels);

        for (int i = 0; i < 64; ++i) {
            int diff = std::abs(static_cast<int>(uber_pixels[i]) - static_cast<int>(spec_pixels[i]));
            if (diff > 1) {
                std::printf("MISMATCH in %s at byte %d (pixel %d chan %d): uber=%d spec=%d diff=%d\n",
                            tc.name, i, i / 4, i % 4, uber_pixels[i], spec_pixels[i], diff);
                assert(diff <= 1);
            }
        }
    }

    std::printf("[test] bridge.program_count() = %zu\n", bridge.program_count());
    assert(bridge.program_count() >= 15);

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestSpecializedCombinerShaders PASSED\n");
}

void TestP3VertexFormat() {
    std::printf("[test] Running TestP3VertexFormat...\n");
    using namespace dkr::runtime;

    static_assert(sizeof(F3DGLESVertex) == 28, "F3DGLESVertex must be 28 bytes");
    static_assert(sizeof(F3DGLESState::CachedVertex) == 20, "CachedVertex must be 20 bytes");

    F3DDKRGLESBridge bridge;

    // Verify CachedVertex stores raw uint8_t colors without loss
    std::vector<uint8_t> rdram(0x10000, 0);
    const uint32_t vtx_addr = 0x1000;
    // (-50, -50, 0), color (12, 34, 56, 78)
    int16_t x = -50, y = -50, z = 0;
    std::memcpy(rdram.data() + ((vtx_addr + 0U) ^ 2U), &x, sizeof(x));
    std::memcpy(rdram.data() + ((vtx_addr + 2U) ^ 2U), &y, sizeof(y));
    std::memcpy(rdram.data() + ((vtx_addr + 4U) ^ 2U), &z, sizeof(z));
    rdram[(vtx_addr + 6U) ^ 3U] = 12;
    rdram[(vtx_addr + 7U) ^ 3U] = 34;
    rdram[(vtx_addr + 8U) ^ 3U] = 56;
    rdram[(vtx_addr + 9U) ^ 3U] = 78;

    // Load vertex via G_VTX: 1 vertex (count-1=0)
    const uint32_t dl_addr = 0x2000;
    const uint32_t w0 = 0x04000000U;
    const uint32_t w1 = vtx_addr;
    const uint32_t end_w0 = 0xB8000000U;
    const uint32_t end_w1 = 0;
    std::memcpy(rdram.data() + dl_addr, &w0, sizeof(w0));
    std::memcpy(rdram.data() + dl_addr + 4U, &w1, sizeof(w1));
    std::memcpy(rdram.data() + dl_addr + 8U, &end_w0, sizeof(end_w0));
    std::memcpy(rdram.data() + dl_addr + 12U, &end_w1, sizeof(end_w1));

    bridge.execute_display_list(dl_addr, rdram.data());

    assert(bridge.debug_state().vertex_cache[0].r == 12);
    assert(bridge.debug_state().vertex_cache[0].g == 34);
    assert(bridge.debug_state().vertex_cache[0].b == 56);
    assert(bridge.debug_state().vertex_cache[0].a == 78);

    std::printf("[test] TestP3VertexFormat PASSED\n");
}

void TestP4FastMemoryReaders() {
    std::printf("[test] Running TestP4FastMemoryReaders...\n");
    using namespace dkr::runtime;

    F3DDKRGLESBridge bridge;
    std::vector<uint8_t> rdram(0x20000, 0);

    // 1. Setup 3 vertices in RDRAM at 0x1000
    // Vertex 0: (-50, -50, 0), color (10, 20, 30, 255)
    // Vertex 1: (50, -50, 0), color (40, 50, 60, 255)
    // Vertex 2: (0, 50, 0), color (70, 80, 90, 255)
    const uint32_t vtx_addr = 0x1000;
    int16_t x0 = -50, y0 = -50, z0 = 0;
    int16_t x1 = 50,  y1 = -50, z1 = 0;
    int16_t x2 = 0,   y2 = 50,  z2 = 0;

    std::memcpy(rdram.data() + ((vtx_addr + 0U) ^ 2U), &x0, sizeof(x0));
    std::memcpy(rdram.data() + ((vtx_addr + 2U) ^ 2U), &y0, sizeof(y0));
    std::memcpy(rdram.data() + ((vtx_addr + 4U) ^ 2U), &z0, sizeof(z0));
    rdram[(vtx_addr + 6U) ^ 3U] = 10;
    rdram[(vtx_addr + 7U) ^ 3U] = 20;
    rdram[(vtx_addr + 8U) ^ 3U] = 30;
    rdram[(vtx_addr + 9U) ^ 3U] = 255;

    std::memcpy(rdram.data() + ((vtx_addr + 10U) ^ 2U), &x1, sizeof(x1));
    std::memcpy(rdram.data() + ((vtx_addr + 12U) ^ 2U), &y1, sizeof(y1));
    std::memcpy(rdram.data() + ((vtx_addr + 14U) ^ 2U), &z1, sizeof(z1));
    rdram[(vtx_addr + 16U) ^ 3U] = 40;
    rdram[(vtx_addr + 17U) ^ 3U] = 50;
    rdram[(vtx_addr + 18U) ^ 3U] = 60;
    rdram[(vtx_addr + 19U) ^ 3U] = 255;

    std::memcpy(rdram.data() + ((vtx_addr + 20U) ^ 2U), &x2, sizeof(x2));
    std::memcpy(rdram.data() + ((vtx_addr + 22U) ^ 2U), &y2, sizeof(y2));
    std::memcpy(rdram.data() + ((vtx_addr + 24U) ^ 2U), &z2, sizeof(z2));
    rdram[(vtx_addr + 26U) ^ 3U] = 70;
    rdram[(vtx_addr + 27U) ^ 3U] = 80;
    rdram[(vtx_addr + 28U) ^ 3U] = 90;
    rdram[(vtx_addr + 29U) ^ 3U] = 255;

    // Load the 3 vertices: opcode 0x04, count 3 (count-1 = 2 -> 2 << 19)
    const uint32_t dl_load_vtx = 0x2000;
    uint32_t cmd_w0 = 0x04100000U;
    uint32_t cmd_w1 = vtx_addr;
    uint32_t cmd_end_w0 = 0xB8000000U;
    uint32_t cmd_end_w1 = 0;
    std::memcpy(rdram.data() + dl_load_vtx, &cmd_w0, 4);
    std::memcpy(rdram.data() + dl_load_vtx + 4U, &cmd_w1, 4);
    std::memcpy(rdram.data() + dl_load_vtx + 8U, &cmd_end_w0, 4);
    std::memcpy(rdram.data() + dl_load_vtx + 12U, &cmd_end_w1, 4);

    bridge.execute_display_list(dl_load_vtx, rdram.data());
    assert(bridge.debug_state().vertex_cache[0].r == 10);
    assert(bridge.debug_state().vertex_cache[1].r == 40);
    assert(bridge.debug_state().vertex_cache[2].r == 70);
    assert(bridge.is_batch_empty());

    // 2. Aligned Front-Facing Triangle (0x3000): flags=0, idx0=0, idx1=1, idx2=2
    const uint32_t tri_aligned_front = 0x3000;
    uint32_t tw0 = (0U << 24) | (0U << 16) | (1U << 8) | 2U;
    uint32_t tw1 = 0; // s0=0, t0=0
    uint32_t tw2 = 0; // s1=0, t1=0
    uint32_t tw3 = 0; // s2=0, t2=0
    std::memcpy(rdram.data() + tri_aligned_front + 0U, &tw0, 4);
    std::memcpy(rdram.data() + tri_aligned_front + 4U, &tw1, 4);
    std::memcpy(rdram.data() + tri_aligned_front + 8U, &tw2, 4);
    std::memcpy(rdram.data() + tri_aligned_front + 12U, &tw3, 4);

    const uint32_t dl_tri1 = 0x2100;
    uint32_t tri_cmd_w0 = 0x05000000U; // opcode 0x05, count=1, tex_en=0
    uint32_t tri_cmd_w1 = tri_aligned_front;
    std::memcpy(rdram.data() + dl_tri1, &tri_cmd_w0, 4);
    std::memcpy(rdram.data() + dl_tri1 + 4U, &tri_cmd_w1, 4);
    std::memcpy(rdram.data() + dl_tri1 + 8U, &cmd_end_w0, 4);
    std::memcpy(rdram.data() + dl_tri1 + 12U, &cmd_end_w1, 4);

    bridge.execute_display_list(dl_tri1, rdram.data());
    assert(bridge.batched_vertex_count() == 3);

    // 3. Aligned Back-Facing Triangle (0x3010): flags=0, idx0=0, idx1=2, idx2=1 (winding reversed)
    const uint32_t tri_aligned_back = 0x3010;
    uint32_t btw0 = (0U << 24) | (0U << 16) | (2U << 8) | 1U;
    std::memcpy(rdram.data() + tri_aligned_back + 0U, &btw0, 4);
    std::memcpy(rdram.data() + tri_aligned_back + 4U, &tw1, 4);
    std::memcpy(rdram.data() + tri_aligned_back + 8U, &tw2, 4);
    std::memcpy(rdram.data() + tri_aligned_back + 12U, &tw3, 4);

    const uint32_t dl_tri2 = 0x2200;
    tri_cmd_w1 = tri_aligned_back;
    std::memcpy(rdram.data() + dl_tri2, &tri_cmd_w0, 4);
    std::memcpy(rdram.data() + dl_tri2 + 4U, &tri_cmd_w1, 4);
    std::memcpy(rdram.data() + dl_tri2 + 8U, &cmd_end_w0, 4);
    std::memcpy(rdram.data() + dl_tri2 + 12U, &cmd_end_w1, 4);

    bridge.execute_display_list(dl_tri2, rdram.data());
    // Should be culled, count remains 3!
    assert(bridge.batched_vertex_count() == 3);

    // 4. Aligned Back-Facing Triangle with BACKFACE_DRAW flag (0x40): flags=0x40
    const uint32_t tri_aligned_back_draw = 0x3020;
    uint32_t bdtw0 = (0x40U << 24) | (0U << 16) | (2U << 8) | 1U;
    std::memcpy(rdram.data() + tri_aligned_back_draw + 0U, &bdtw0, 4);
    std::memcpy(rdram.data() + tri_aligned_back_draw + 4U, &tw1, 4);
    std::memcpy(rdram.data() + tri_aligned_back_draw + 8U, &tw2, 4);
    std::memcpy(rdram.data() + tri_aligned_back_draw + 12U, &tw3, 4);

    const uint32_t dl_tri3 = 0x2300;
    tri_cmd_w1 = tri_aligned_back_draw;
    std::memcpy(rdram.data() + dl_tri3, &tri_cmd_w0, 4);
    std::memcpy(rdram.data() + dl_tri3 + 4U, &tri_cmd_w1, 4);
    std::memcpy(rdram.data() + dl_tri3 + 8U, &cmd_end_w0, 4);
    std::memcpy(rdram.data() + dl_tri3 + 12U, &cmd_end_w1, 4);

    bridge.execute_display_list(dl_tri3, rdram.data());
    // Not culled because of 0x40 flag! Batched count increases to 6
    assert(bridge.batched_vertex_count() == 6);

    // 5. Unaligned Triangle (0x3032 -> addr & 3 == 2):
    // Write using byte/halfword XOR layout
    const uint32_t tri_unaligned = 0x3032;
    rdram[(tri_unaligned + 0U) ^ 3U] = 0;   // flags = 0
    rdram[(tri_unaligned + 1U) ^ 3U] = 0;   // idx0 = 0
    rdram[(tri_unaligned + 2U) ^ 3U] = 1;   // idx1 = 1
    rdram[(tri_unaligned + 3U) ^ 3U] = 2;   // idx2 = 2
    int16_t s0 = 10, t0 = 20, s1 = 30, t1 = 40, s2 = 50, t2 = 60;
    std::memcpy(rdram.data() + ((tri_unaligned + 4U)  ^ 2U), &s0, sizeof(s0));
    std::memcpy(rdram.data() + ((tri_unaligned + 6U)  ^ 2U), &t0, sizeof(t0));
    std::memcpy(rdram.data() + ((tri_unaligned + 8U)  ^ 2U), &s1, sizeof(s1));
    std::memcpy(rdram.data() + ((tri_unaligned + 10U) ^ 2U), &t1, sizeof(t1));
    std::memcpy(rdram.data() + ((tri_unaligned + 12U) ^ 2U), &s2, sizeof(s2));
    std::memcpy(rdram.data() + ((tri_unaligned + 14U) ^ 2U), &t2, sizeof(t2));

    const uint32_t dl_tri4 = 0x2400;
    tri_cmd_w1 = tri_unaligned;
    std::memcpy(rdram.data() + dl_tri4, &tri_cmd_w0, 4);
    std::memcpy(rdram.data() + dl_tri4 + 4U, &tri_cmd_w1, 4);
    std::memcpy(rdram.data() + dl_tri4 + 8U, &cmd_end_w0, 4);
    std::memcpy(rdram.data() + dl_tri4 + 12U, &cmd_end_w1, 4);

    bridge.execute_display_list(dl_tri4, rdram.data());
    // Unaligned front-facing triangle should be batched -> total 9 vertices!
    assert(bridge.batched_vertex_count() == 9);

    std::printf("[test] TestP4FastMemoryReaders PASSED\n");
}

void TestP5LuminanceAlphaDecoding() {
    std::printf("[test] Running TestP5LuminanceAlphaDecoding...\n");
    using namespace dkr::runtime;

    std::vector<uint8_t> tmem(4096);
    // Fill TMEM with deterministically patterned data
    for (size_t i = 0; i < tmem.size(); ++i) {
        tmem[i] = static_cast<uint8_t>((i * 37U + 11U) & 0xFFU);
    }

    struct FormatCase {
        const char* name;
        uint8_t fmt;
        uint8_t size;
        uint8_t palette;
        uint8_t tlut_type;
    };

    const FormatCase cases[] = {
        {"I8",       4, 1, 0, 2},
        {"I4",       4, 0, 0, 2},
        {"IA16",     3, 2, 0, 2},
        {"IA8",      3, 1, 0, 2},
        {"IA4",      3, 0, 0, 2},
        {"CI4_IA16", 2, 0, 1, 3},
        {"CI8_IA16", 2, 1, 0, 3}
    };

    constexpr uint32_t width = 16;
    constexpr uint32_t height = 8;
    std::vector<uint8_t> la8_buf;
    std::vector<uint32_t> rgba_buf;

    for (const auto& tc : cases) {
        for (bool odd_swap : {false, true}) {
            bool ok_la8 = DecodeTMEMToLA8(tmem.data(), tc.fmt, tc.size, tc.palette, 0U, width, height, 0U, la8_buf, odd_swap, tc.tlut_type);
            assert(ok_la8);
            assert(la8_buf.size() == width * height * 2U);

            DecodeTMEMToRGBA(tmem.data(), tc.fmt, tc.size, tc.palette, 0U, width, height, 0U, rgba_buf, odd_swap, tc.tlut_type);
            assert(rgba_buf.size() == width * height);

            for (uint32_t i = 0; i < width * height; ++i) {
                const uint8_t L = la8_buf[i * 2U + 0U];
                const uint8_t A = la8_buf[i * 2U + 1U];
                const uint8_t expected_R = static_cast<uint8_t>(rgba_buf[i] & 0xFFU);
                const uint8_t expected_A = static_cast<uint8_t>((rgba_buf[i] >> 24U) & 0xFFU);
                if (L != expected_R || A != expected_A) {
                    std::printf("[test] %s (swap=%d) mismatch at pixel %u: LA8=(%u, %u) RGBA=(%u, %u)\n",
                                tc.name, odd_swap, i, L, A, expected_R, expected_A);
                    assert(L == expected_R && A == expected_A);
                }
            }
        }
    }

    // Verify rejection of non-LA8 formats:
    // RGBA16 (fmt=0, size=2)
    assert(!DecodeTMEMToLA8(tmem.data(), 0, 2, 0, 0, width, height, 0, la8_buf));
    // RGBA32 (fmt=0, size=3)
    assert(!DecodeTMEMToLA8(tmem.data(), 0, 3, 0, 0, width, height, 0, la8_buf));
    // CI4 with standard RGBA16 TLUT (fmt=2, tlut_type=2)
    assert(!DecodeTMEMToLA8(tmem.data(), 2, 0, 0, 0, width, height, 0, la8_buf, false, 2));

    std::printf("[test] TestP5LuminanceAlphaDecoding PASSED\n");
}

void TestP6TextureCacheEviction() {
    std::printf("[test] Running TestP6TextureCacheEviction...\n");

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);

    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);
    eglBindAPI(EGL_OPENGL_ES_API);

    const EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    assert(context != EGL_NO_CONTEXT);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 64,
        EGL_HEIGHT, 64,
        EGL_NONE
    };
    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    assert(surface != EGL_NO_SURFACE);

    eglMakeCurrent(display, surface, surface, context);

    using namespace dkr::runtime;
    F3DDKRGLESBridge bridge;
    bridge.init();
    bridge.set_viewport(0, 0, 64, 64);

    constexpr uint32_t kRDRAMSize = 0x00800000U;
    std::vector<uint8_t> rdram(kRDRAMSize, 0);

    // Initialize 550 small 4x4 RGBA16 textures (32 bytes each)
    constexpr size_t kNumTextures = 550;
    for (size_t i = 0; i < kNumTextures; ++i) {
        const uint32_t addr = 0x10000U + static_cast<uint32_t>(i * 64U);
        for (uint32_t p = 0; p < 16; ++p) {
            uint16_t c = static_cast<uint16_t>(0xF800U | (i & 0x1FU));
            rdram[addr + p * 2 + 0] = static_cast<uint8_t>(c >> 8);
            rdram[addr + p * 2 + 1] = static_cast<uint8_t>(c & 0xFF);
        }
    }

    const uint32_t dl_base = 0x40000U;
    uint32_t pc = dl_base;
    auto emit_cmd = [&](uint32_t w0, uint32_t w1) {
        std::memcpy(rdram.data() + pc, &w0, 4);
        std::memcpy(rdram.data() + pc + 4U, &w1, 4);
        pc += 8U;
    };

    // Cycle type 1-cycle, white prim/env
    emit_cmd(0xEF000000U, 0x00000030U);
    emit_cmd(0xFA000000U, 0xFFFFFFFFU);
    emit_cmd(0xFB000000U, 0xFFFFFFFFU);
    emit_cmd(0xFC121824U, 0xFF33FFFFU);

    for (size_t i = 0; i < kNumTextures; ++i) {
        const uint32_t tex_addr = 0x10000U + static_cast<uint32_t>(i * 64U);
        // G_SETTIMG: RGBA16, width 4, address tex_addr
        emit_cmd(0xFD100003U, tex_addr);
        // G_SETTILE: tile 0, RGBA16
        emit_cmd(0xF5100000U, 0x00000000U);
        // G_SETTILESIZE: tile 0, 4x4 -> (3 << 2) = 12 = 0x0C
        emit_cmd(0xF2000000U, 0x0000C00CU);
        // G_LOADBLOCK: tile 0, 16 texels (16-1=15 -> 0xF)
        emit_cmd(0xF3000000U, 0x0000F000U);
        // G_TEXRECT (3 packets)
        emit_cmd(0xE4010010U, 0x00000000U);
        emit_cmd(0x00000000U, 0x00000000U);
        emit_cmd(0x00000000U, 0x04000400U);
    }
    emit_cmd(0xB8000000U, 0x00000000U); // G_ENDDL

    bridge.execute_display_list(dl_base, rdram.data());
    bridge.flush_batch();

    // After loading 550 textures, cache eviction MUST have triggered at 512 entries,
    // reducing to 384, and then accumulating the remaining (550 - 512 = 38) entries.
    // Total size should be exactly 384 + 38 = 422!
    std::printf("[test] bridge.texture_cache_size() = %zu\n", bridge.texture_cache_size());
    assert(bridge.texture_cache_size() <= 512);
    assert(bridge.texture_cache_size() >= 384);
    assert(bridge.texture_cache_size() == 384 + (kNumTextures - 512));

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestP6TextureCacheEviction PASSED\n");
}

void TestVertexAttribArrayRestoration() {
    std::printf("[test] Running TestVertexAttribArrayRestoration...\n");

    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(display != EGL_NO_DISPLAY);

    EGLint major = 0, minor = 0;
    eglInitialize(display, &major, &minor);
    eglBindAPI(EGL_OPENGL_ES_API);

    const EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE
    };
    EGLConfig config;
    EGLint num_configs = 0;
    eglChooseConfig(display, config_attribs, &config, 1, &num_configs);

    const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attribs);
    assert(context != EGL_NO_CONTEXT);

    const EGLint pbuffer_attribs[] = {
        EGL_WIDTH, 64,
        EGL_HEIGHT, 64,
        EGL_NONE
    };
    EGLSurface surface = eglCreatePbufferSurface(display, config, pbuffer_attribs);
    assert(surface != EGL_NO_SURFACE);

    eglMakeCurrent(display, surface, surface, context);

    using namespace dkr::runtime;
    F3DDKRGLESBridge bridge;
    bridge.init();
    bridge.set_viewport(0, 0, 64, 64);

    // Simulate renderer's blit pipeline disabling vertex attrib arrays 0 and 1
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    GLint enabled0 = GL_FALSE, enabled1 = GL_FALSE, enabled2 = GL_FALSE;
    glGetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled0);
    glGetVertexAttribiv(1, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled1);
    assert(enabled0 == GL_FALSE && enabled1 == GL_FALSE);

    // Invalidate GL cache as done between VI swap and task
    bridge.invalidate_gl_cache();

    // Set up RDRAM with a simple front-facing triangle
    std::vector<uint8_t> rdram(0x20000, 0);
    const uint32_t vtx_addr = 0x1000;
    int16_t x0 = -50, y0 = -50, z0 = 0;
    int16_t x1 = 50,  y1 = -50, z1 = 0;
    int16_t x2 = 0,   y2 = 50,  z2 = 0;

    std::memcpy(rdram.data() + ((vtx_addr + 0U) ^ 2U), &x0, sizeof(x0));
    std::memcpy(rdram.data() + ((vtx_addr + 2U) ^ 2U), &y0, sizeof(y0));
    std::memcpy(rdram.data() + ((vtx_addr + 4U) ^ 2U), &z0, sizeof(z0));
    rdram[(vtx_addr + 6U) ^ 3U] = 255;
    rdram[(vtx_addr + 7U) ^ 3U] = 0;
    rdram[(vtx_addr + 8U) ^ 3U] = 0;
    rdram[(vtx_addr + 9U) ^ 3U] = 255;

    std::memcpy(rdram.data() + ((vtx_addr + 10U) ^ 2U), &x1, sizeof(x1));
    std::memcpy(rdram.data() + ((vtx_addr + 12U) ^ 2U), &y1, sizeof(y1));
    std::memcpy(rdram.data() + ((vtx_addr + 14U) ^ 2U), &z1, sizeof(z1));
    rdram[(vtx_addr + 16U) ^ 3U] = 0;
    rdram[(vtx_addr + 17U) ^ 3U] = 255;
    rdram[(vtx_addr + 18U) ^ 3U] = 0;
    rdram[(vtx_addr + 19U) ^ 3U] = 255;

    std::memcpy(rdram.data() + ((vtx_addr + 20U) ^ 2U), &x2, sizeof(x2));
    std::memcpy(rdram.data() + ((vtx_addr + 22U) ^ 2U), &y2, sizeof(y2));
    std::memcpy(rdram.data() + ((vtx_addr + 24U) ^ 2U), &z2, sizeof(z2));
    rdram[(vtx_addr + 26U) ^ 3U] = 0;
    rdram[(vtx_addr + 27U) ^ 3U] = 0;
    rdram[(vtx_addr + 28U) ^ 3U] = 255;
    rdram[(vtx_addr + 29U) ^ 3U] = 255;

    const uint32_t tri_addr = 0x3000;
    uint32_t tw0 = (0U << 24) | (0U << 16) | (1U << 8) | 2U;
    uint32_t tw1 = 0, tw2 = 0, tw3 = 0;
    std::memcpy(rdram.data() + tri_addr + 0U, &tw0, 4);
    std::memcpy(rdram.data() + tri_addr + 4U, &tw1, 4);
    std::memcpy(rdram.data() + tri_addr + 8U, &tw2, 4);
    std::memcpy(rdram.data() + tri_addr + 12U, &tw3, 4);

    const uint32_t dl = 0x2000;
    uint32_t pc = dl;
    auto emit = [&](uint32_t w0, uint32_t w1) {
        std::memcpy(rdram.data() + pc, &w0, 4);
        std::memcpy(rdram.data() + pc + 4U, &w1, 4);
        pc += 8U;
    };
    emit(0x04100000U, vtx_addr); // load 3 vertices
    emit(0x05000000U, tri_addr); // 1 tri
    emit(0xB8000000U, 0U);       // end dl

    bridge.execute_display_list(dl, rdram.data());
    bridge.flush_batch();

    // After flush_batch(), all 3 vertex attribute arrays (0=pos, 1=tex, 2=col) must be restored!
    glGetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled0);
    glGetVertexAttribiv(1, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled1);
    glGetVertexAttribiv(2, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled2);
    assert(enabled0 == GL_TRUE);
    assert(enabled1 == GL_TRUE);
    assert(enabled2 == GL_TRUE);

    eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::printf("[test] TestVertexAttribArrayRestoration PASSED\n");
}

} // namespace

int main() {
    std::printf("========================================\n");
    std::printf("Running DKR-R GLES Advanced Feature Tests\n");
    std::printf("========================================\n");

    TestFixedPointMatrix();
    Test16BitTextureDecoding();
    TestOddLineSwapI4();
    TestDisplayListExecution();
    TestTaskCountFallback();
    TestLoaderBoundsRegression();
    TestDisplayListFuzz();
    TestPerspectiveFog();
    TestTriStateGLCache();
    TestTMEMHashCollision();
    TestNestedDLStackIsolation();
    TestSamplerStateDecoupling();
    TestP2Batching();
    TestSpecializedCombinerShaders();
    TestP3VertexFormat();
    TestP4FastMemoryReaders();
    TestP5LuminanceAlphaDecoding();
    TestP6TextureCacheEviction();
    TestVertexAttribArrayRestoration();

    std::printf("========================================\n");
    std::printf("ALL ADVANCED GLES TESTS PASSED!\n");
    std::printf("========================================\n");
    return 0;
}
