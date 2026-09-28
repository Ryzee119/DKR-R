#pragma once

#include "ultramodern/ultra64.h"

#if defined(__ANDROID__) || defined(TARGET_PORTMASTER) || defined(__arm__) || defined(__aarch64__)
#include <GLES2/gl2.h>
#else
#include <GLES2/gl2.h>
#endif

#include <array>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

#ifndef XXH_INLINE_ALL
#define XXH_INLINE_ALL
#endif
#include "xxHash/xxhash.h"

namespace dkr::runtime {

#if !DKR_RUNTIME_HAS_RT64
std::uint64_t completed_f3ddkr_task_count();
#endif

bool DecodeTMEMToRGBA16(const uint8_t* tmem, uint8_t fmt, uint8_t size, uint8_t palette,
                        uint32_t tmem_offset, uint32_t width, uint32_t height,
                        uint32_t row_stride_bytes,
                        std::vector<uint16_t>& out_rgba16,
                        bool odd_line_swap = false,
                        uint8_t tlut_type = 2);

inline bool DecodeTMEMToRGBA16(const uint8_t* tmem, uint8_t fmt, uint8_t size, uint8_t palette,
                               uint32_t tmem_offset, uint32_t width, uint32_t height,
                               std::vector<uint16_t>& out_rgba16) {
    return DecodeTMEMToRGBA16(tmem, fmt, size, palette, tmem_offset, width, height, 0U, out_rgba16);
}

void DecodeTMEMToRGBA(const uint8_t* tmem, uint8_t fmt, uint8_t size, uint8_t palette,
                      uint32_t tmem_offset, uint32_t width, uint32_t height,
                      uint32_t row_stride_bytes,
                      std::vector<uint32_t>& out_rgba,
                      bool odd_line_swap = false,
                      uint8_t tlut_type = 2);

inline void DecodeTMEMToRGBA(const uint8_t* tmem, uint8_t fmt, uint8_t size, uint8_t palette,
                             uint32_t tmem_offset, uint32_t width, uint32_t height,
                             std::vector<uint32_t>& out_rgba) {
    DecodeTMEMToRGBA(tmem, fmt, size, palette, tmem_offset, width, height, 0U, out_rgba);
}

bool DecodeTMEMToLA8(const uint8_t* tmem, uint8_t fmt, uint8_t size, uint8_t palette,
                     uint32_t tmem_offset, uint32_t width, uint32_t height,
                     uint32_t row_stride_bytes,
                     std::vector<uint8_t>& out_la8,
                     bool odd_line_swap = false,
                     uint8_t tlut_type = 2);

inline bool DecodeTMEMToLA8(const uint8_t* tmem, uint8_t fmt, uint8_t size, uint8_t palette,
                            uint32_t tmem_offset, uint32_t width, uint32_t height,
                            std::vector<uint8_t>& out_la8) {
    return DecodeTMEMToLA8(tmem, fmt, size, palette, tmem_offset, width, height, 0U, out_la8);
}

uint64_t HashTMEM(const uint8_t* tmem_base, size_t offset, size_t len);

struct F3DGLESVertex {
    float x, y, z, w;
    float u, v;
    uint8_t r, g, b, a;
};
static_assert(sizeof(F3DGLESVertex) == 28, "F3DGLESVertex must be 28 bytes");

struct F3DGLESMtx {
    float m[4][4];

    static F3DGLESMtx identity();
    static F3DGLESMtx multiply(const F3DGLESMtx& a, const F3DGLESMtx& b);
    void load_fixed_point(const uint8_t* rdram, uint32_t address);
};

struct F3DGLESTile {
    uint8_t fmt = 0;
    uint8_t size = 0;
    uint16_t line = 0;
    uint16_t tmem = 0;
    uint8_t palette = 0;
    uint8_t clamp_s = 0;
    uint8_t mirror_s = 0;
    uint8_t mask_s = 0;
    uint8_t shift_s = 0;
    uint8_t clamp_t = 0;
    uint8_t mirror_t = 0;
    uint8_t mask_t = 0;
    uint8_t shift_t = 0;
    uint16_t sl = 0, tl = 0, sh = 0, th = 0;

    bool params_dirty = true;
    uint32_t cached_tile_w = 32;
    uint32_t cached_tile_h = 32;
    float cached_scale_s = 1.0f / 1024.0f;
    float cached_scale_t = 1.0f / 1024.0f;
    float cached_s_offset = 0.0f;
    float cached_t_offset = 0.0f;
};

struct TextureKey {
    uint32_t source_addr = 0;
    uint64_t tmem_hash = 0;
    uint16_t width = 0;
    uint16_t height = 0;
    uint16_t line = 0;
    uint16_t tmem = 0;
    uint8_t fmt = 0;
    uint8_t size = 0;
    uint8_t palette = 0;
    uint8_t line_swapped = 0;
    uint8_t tlut_type = 0;

    bool operator==(const TextureKey& o) const {
        return source_addr == o.source_addr &&
               tmem_hash == o.tmem_hash &&
               width == o.width &&
               height == o.height &&
               line == o.line &&
               tmem == o.tmem &&
               fmt == o.fmt &&
               size == o.size &&
               palette == o.palette &&
               line_swapped == o.line_swapped &&
               tlut_type == o.tlut_type;
    }
};

struct TextureKeyHash {
    std::size_t operator()(const TextureKey& k) const noexcept {
        std::size_t h = static_cast<std::size_t>(k.source_addr);
        h ^= static_cast<std::size_t>(k.tmem_hash);
        h ^= (static_cast<std::size_t>(k.width) << 16) ^ static_cast<std::size_t>(k.height);
        h ^= (static_cast<std::size_t>(k.line) << 20) ^ (static_cast<std::size_t>(k.tmem) << 4);
        h ^= (static_cast<std::size_t>(k.fmt) << 24) |
             (static_cast<std::size_t>(k.size) << 20) |
             (static_cast<std::size_t>(k.palette) << 16) |
             (static_cast<std::size_t>(k.line_swapped) << 10) |
             (static_cast<std::size_t>(k.tlut_type) << 8);
        return h;
    }
};

struct CachedGLTexture {
    GLuint id = 0;
    uint32_t width = 0;
    uint32_t height = 0;
    GLenum current_filter = 0;
    GLenum wrap_s = 0;
    GLenum wrap_t = 0;
    uint64_t last_used_frame = 0;
};

enum class BatchKind {
    Tri3D,
    Rect2D
};

enum class DrawOverride : uint8_t {
    None,
    CopyTexel, // (0-0)*0+TEXEL0, no blend
    FillShade, // (0-0)*0+SHADE, no blend, no tex
    Untextured // real combiner with use_texture = 0
};

struct BatchState {
    BatchKind kind = BatchKind::Tri3D;
    DrawOverride ovr = DrawOverride::None;
    bool tex = false;
    GLuint tex_id = 0;

    bool operator==(const BatchState& o) const {
        return kind == o.kind && ovr == o.ovr && tex == o.tex && tex_id == o.tex_id;
    }
    bool operator!=(const BatchState& o) const {
        return !(*this == o);
    }
};

enum class FlushReason : uint8_t {
    Texture,
    Combiner,
    OtherMode,
    Color,
    Fog,
    Scissor,
    Viewport,
    BatchKind,
    TexEnable,
    CopyRect,
    FillRect,
    DepthClear,
    ColorImage,
    EndTask,
    Count
};

struct CombinerKey {
    uint8_t cc[4];               // cycle 0: a,b,c,d
    uint8_t ac[4];               // cycle 0: a,b,c,d
    uint8_t cc1[4];              // cycle 1 (zeroed when not 2-cycle)
    uint8_t ac1[4];              // cycle 1 (zeroed when not 2-cycle)
    uint8_t two_cycle;           // cycle_type == 1
    uint8_t use_texture;
    uint8_t alpha_mode;          // 0 off, 1 threshold, 2 dither
    uint8_t fog_geom;            // geometry fog enabled
    uint8_t fog_blend;           // blend fog enabled
    uint8_t pad[3];              // explicit padding to 24 bytes

    bool operator==(const CombinerKey& o) const noexcept {
        return std::memcmp(this, &o, sizeof(CombinerKey)) == 0;
    }
};
static_assert(sizeof(CombinerKey) == 24, "CombinerKey must be exactly 24 bytes");

struct CombinerKeyHash {
    size_t operator()(const CombinerKey& k) const noexcept {
        return static_cast<size_t>(XXH3_64bits(&k, sizeof(CombinerKey)));
    }
};

struct ShaderProgram {
    GLuint id = 0;
    GLint u_prim = -1;
    GLint u_env = -1;
    GLint u_fog_color = -1;
    GLint u_lod_frac = -1;
    GLint u_alpha_thresh = -1;
    GLint u_fog_params = -1;
    GLint u_sampler = -1;
    // Last values uploaded to *this* program:
    float prim[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float env[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float fog_color[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float lod_frac = -1.0f;
    float alpha_thresh = -1.0f;
    float fog_params[2] = {0.0f, 0.0f};
    bool uploaded_once = false;
};

std::string GenerateFragmentShader(const CombinerKey& key);

enum UniformDirtyFlags : uint32_t {
    DIRTY_UNIFORM_NONE       = 0,
    DIRTY_UNIFORM_PRIM_COLOR = 1 << 0,
    DIRTY_UNIFORM_ENV_COLOR  = 1 << 1,
    DIRTY_UNIFORM_FOG_COLOR  = 1 << 2,
    DIRTY_UNIFORM_TEXTURE_EN = 1 << 3,
    DIRTY_UNIFORM_COMBINER   = 1 << 4,
    DIRTY_UNIFORM_ALPHA_TEST = 1 << 5,
    DIRTY_UNIFORM_FOG_EN     = 1 << 6,
    DIRTY_UNIFORM_FOG_PARAMS = 1 << 7,
    DIRTY_UNIFORM_ALL        = 0xFFFFFFFFU
};

struct F3DGLESState {
    std::array<F3DGLESMtx, 4> modelview_stack{};

    struct CachedVertex {
        float x = 0.0f, y = 0.0f, z = 0.0f, w = 1.0f;
        uint8_t r = 255, g = 255, b = 255, a = 255;
    };
    std::array<CachedVertex, 64> vertex_cache{};
    CachedVertex anchor{};

    std::array<uint32_t, 16> segments{};

    uint32_t geometry_mode = 0;
    uint64_t other_mode = 0;
    float prim_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    uint8_t prim_rgba8[4] = {255, 255, 255, 255};
    float env_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float blend_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float fog_color[4] = {0.0f, 0.0f, 0.0f, 1.0f};

    uint32_t timg_address = 0;
    uint8_t timg_fmt = 0;
    uint8_t timg_size = 0;
    uint16_t timg_width = 0;
    std::array<F3DGLESTile, 8> tiles{};
    std::array<uint8_t, 4096> tmem{};
    std::array<uint32_t, 512> tmem_source_addr{};
    std::array<uint32_t, 512> tmem_loaded_bytes{};
    std::array<uint64_t, 512> tmem_slot_hash{};
    uint32_t last_tlut_address = 0;
    bool texture_state_dirty = true;
    uint64_t cached_tmem_hash = 0;
    uint8_t last_bound_tile = 0xFF;

    std::array<uint8_t, 512> tmem_line_swapped{};
    uint8_t tlut_type = 2;

    uint32_t texture_offset = 0;
    uint16_t texture_shift = 0;
    uint32_t texture_count = 0;

    float fill_color[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    uint32_t fill_color_raw = 0;
    uint32_t color_image_address = 0xFFFFFFFFU;
    uint32_t depth_image_address = 0xEEEEEEEEU;
    uint8_t color_image_size = 2;
    uint8_t cycle_type = 0;
    bool depth_test_enabled = false;
    bool depth_write_enabled = false;

    int combine_mode = 0;
    uint8_t cc_a = 1;
    uint8_t cc_b = 15;
    uint8_t cc_c = 4;
    uint8_t cc_d = 7;
    uint8_t ac_a = 1;
    uint8_t ac_b = 7;
    uint8_t ac_c = 4;
    uint8_t ac_d = 7;
    uint8_t cc_a1 = 0;
    uint8_t cc_b1 = 0;
    uint8_t cc_c1 = 0;
    uint8_t cc_d1 = 1;
    uint8_t ac_a1 = 0;
    uint8_t ac_b1 = 0;
    uint8_t ac_c1 = 0;
    uint8_t ac_d1 = 1;
    float prim_lod_frac = 0.0f;
    uint8_t alpha_mode = 0; // 0 = off, 1 = threshold, 2 = dither
    bool alpha_test = false;
    float alpha_threshold = 0.3f;

    int viewport_x = 0, viewport_y = 0;
    int viewport_w = 320, viewport_h = 240;
    int scissor_ulx = 0, scissor_uly = 0;
    int scissor_lrx = 320, scissor_lry = 240;

    struct CallFrame {
        uint32_t address;
    };
    std::vector<CallFrame> dl_stack;

    uint32_t vertex_offset = 0;
    uint32_t matrix_offset = 0;
    uint32_t vertex_cursor = 0;
    bool billboard = false;
    uint32_t selected_matrix = 0;

    bool texture_enabled = false;
    GLuint current_texture_id = 0;
    bool uniforms_dirty = true;
    bool scissor_test_enabled = false;
    bool blend_enabled = false;
    bool blend_additive = false;
    bool decal_mode = false;
    bool fog_enabled = false;
    int16_t fog_mul = 0;
    int16_t fog_off = 0;
    uint8_t text_filter = 2;
    uint32_t dirty_uniforms = DIRTY_UNIFORM_ALL;
};

class F3DDKRGLESBridge {
public:
    F3DDKRGLESBridge();
    ~F3DDKRGLESBridge();

    F3DDKRGLESBridge(const F3DDKRGLESBridge&) = delete;
    F3DDKRGLESBridge& operator=(const F3DDKRGLESBridge&) = delete;

    void init();
    void reset();

    void process_task(const OSTask& task, const uint8_t* rdram);
    void execute_display_list(uint32_t address, const uint8_t* rdram);
    void flush_batch(FlushReason why = FlushReason::EndTask);

    void set_viewport(int x, int y, int width, int height);
    void set_window_size(int w, int h);
    void set_target_size(int w, int h);
    void invalidate_gl_cache();

    int n64_fb_width() const { return n64_fb_w_; }
    int n64_fb_height() const { return n64_fb_h_; }
    const F3DGLESState& debug_state() const { return state_; }
    const auto& flush_reasons() const { return flush_reasons_; }
    uint64_t use_program_count() const { return use_program_count_; }
    uint64_t uniform_upload_count() const { return uniform_upload_count_; }
    uint64_t tri_count() const { return tri_count_; }
    uint64_t draw_calls() const { return draw_calls_; }
    const BatchState& current_batch() const { return batch_; }
    size_t program_count() const { return programs_.size(); }
    void set_use_ubershader(bool enable) { use_ubershader_ = enable; gl_current_program_ = 0xFFFFFFFF; }
    bool use_ubershader() const { return use_ubershader_; }
    bool is_batch_empty() const { return batched_vertices_.empty(); }
    size_t batched_vertex_count() const { return batched_vertices_.size(); }
    size_t texture_cache_size() const { return texture_cache_.size(); }
    uint64_t tex_hits() const { return tex_hits_; }
    uint64_t tex_misses() const { return tex_misses_; }

private:
    struct DLEntry {
        uint32_t raw;
        uint32_t resolved;
    };

    void record_dl_history(uint32_t raw, uint32_t resolved);
    void handle_unexpected_opcode(uint8_t opcode, uint32_t address);
    void execute_command(uint32_t w0, uint32_t w1, const uint8_t* rdram, uint32_t cmd_address = 0);
    uint32_t resolve_segmented_address(uint32_t addr) const;
    void apply_deferred_gl_state();
    void begin_primitives(BatchKind kind, DrawOverride ovr, bool tex, GLuint tex_id, FlushReason why);

    ShaderProgram* get_or_compile_program(const CombinerKey& key);
    void build_combiner_key(CombinerKey& key) const;
    void normalize_key(CombinerKey& key) const;

    void handle_matrix(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_vertex(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_triangle(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_move_mem(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_move_word(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_dma_offsets(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_texture_offset(uint32_t w0, uint32_t w1);
    void handle_set_timg(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_set_tile(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_set_tile_size(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_load_block(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_load_tlut(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_load_tile(uint32_t w0, uint32_t w1, const uint8_t* rdram);
    void handle_set_combine(uint32_t w0, uint32_t w1);
    void apply_other_mode(uint32_t hi, uint32_t lo);
    void handle_set_other_mode(uint32_t w0, uint32_t w1);
    void handle_set_other_mode_hl(bool is_high, uint32_t w0, uint32_t w1);
    void handle_set_color(uint8_t opcode, uint32_t w0, uint32_t w1);
    void handle_set_fill_color(uint32_t w1);
    void handle_set_color_image(uint32_t w0, uint32_t w1);
    void handle_set_depth_image(uint32_t w0, uint32_t w1);
    void handle_geometry_mode(uint8_t opcode, uint32_t w1);
    void handle_set_scissor(uint32_t w0, uint32_t w1);
    void handle_fill_rect(uint32_t w0, uint32_t w1);
    void handle_tex_rect(uint32_t w0, uint32_t w1, uint32_t w1_st, uint32_t w1_dxdy, bool flip);
    void run_counted_dl(uint32_t target, uint32_t count, const uint8_t* rdram);

    void update_tile_params(F3DGLESTile& t);
    void invalidate_tmem_hashes(uint32_t write_start, uint32_t write_bytes);

    GLuint bind_tile_texture(uint8_t tile_idx);
    void apply_sampler_state(CachedGLTexture& cached, GLenum wrap_s, GLenum wrap_t, GLenum filter);
    void clear_texture_cache();

    bool try_load_cached_shader(GLuint program, const char* cache_path);
    void try_save_cached_shader(GLuint program, const char* cache_path);

    F3DGLESState state_;
    std::vector<F3DGLESVertex> batched_vertices_;
    std::unordered_map<TextureKey, CachedGLTexture, TextureKeyHash> texture_cache_;
    std::vector<uint16_t> rgba16_buf_;
    std::vector<uint32_t> rgba32_buf_;
    std::vector<uint8_t> la8_buf_;

    BatchState batch_{};
    DrawOverride last_flushed_ovr_ = static_cast<DrawOverride>(0xFF);
    BatchKind last_flushed_kind_ = static_cast<BatchKind>(0xFF);
    int8_t last_flushed_tex_en_ = -1;

    // Hardware GL state tracking to eliminate redundant GL driver calls
    int8_t gl_depth_test_ = -1;
    GLenum gl_depth_func_ = 0;
    int8_t gl_depth_mask_ = -1;
    int8_t gl_blend_ = -1;
    int gl_blend_additive_ = -1;
    int8_t gl_scissor_test_ = -1;
    int gl_scissor_x_ = -1, gl_scissor_y_ = -1, gl_scissor_w_ = -1, gl_scissor_h_ = -1;
    int gl_viewport_x_ = -1, gl_viewport_y_ = -1, gl_viewport_w_ = -1, gl_viewport_h_ = -1;
    int8_t gl_polygon_offset_ = -1;
    GLuint gl_bound_texture_ = 0xFFFFFFFF;

    GLuint default_shader_ = 0;
    std::unordered_map<CombinerKey, ShaderProgram, CombinerKeyHash> programs_;
    std::vector<CombinerKey> known_keys_;
    GLuint gl_current_program_ = 0xFFFFFFFF;
    GLuint vertex_shader_ = 0;
    bool use_ubershader_ = false;

    uint64_t tex_hits_ = 0;
    uint64_t tex_misses_ = 0;
    uint64_t draw_calls_ = 0;
    uint64_t tri_count_ = 0;
    std::chrono::steady_clock::time_point last_perf_log_{};
    GLuint vbo_ = 0;
    GLuint dummy_white_texture_ = 0;

    GLint u_prim_color_loc_ = -1;
    GLint u_env_color_loc_ = -1;
    GLint u_fog_color_loc_ = -1;
    GLint u_use_texture_loc_ = -1;
    GLint u_cycle_type_loc_ = -1;
    GLint u_prim_lod_frac_loc_ = -1;
    GLint u_cc_a_loc_ = -1;
    GLint u_cc_b_loc_ = -1;
    GLint u_cc_c_loc_ = -1;
    GLint u_cc_d_loc_ = -1;
    GLint u_ac_a_loc_ = -1;
    GLint u_ac_b_loc_ = -1;
    GLint u_ac_c_loc_ = -1;
    GLint u_ac_d_loc_ = -1;
    GLint u_cc_a1_loc_ = -1;
    GLint u_cc_b1_loc_ = -1;
    GLint u_cc_c1_loc_ = -1;
    GLint u_cc_d1_loc_ = -1;
    GLint u_ac_a1_loc_ = -1;
    GLint u_ac_b1_loc_ = -1;
    GLint u_ac_c1_loc_ = -1;
    GLint u_ac_d1_loc_ = -1;
    GLint u_alpha_test_loc_ = -1;
    GLint u_alpha_threshold_loc_ = -1;
    GLint u_fog_enabled_loc_ = -1;
    GLint u_fog_geom_loc_ = -1;
    GLint u_fog_params_loc_ = -1;
    GLint u_sampler_loc_ = -1;

    GLint a_pos_loc_ = -1;
    GLint a_tex_loc_ = -1;
    GLint a_col_loc_ = -1;

    uint32_t dl_budget_ = 0;
    uint32_t dl_recursion_depth_ = 0;
    bool dl_abort_ = false;
    bool dl_unexpected_opcode_seen_ = false;

    std::array<DLEntry, 8> dl_history_{};
    size_t dl_history_idx_ = 0;
    size_t dl_history_count_ = 0;

    bool initialized_ = false;
    bool attribs_enabled_ = false;
    uint64_t processed_tasks_ = 0;
    std::array<uint64_t, static_cast<size_t>(FlushReason::Count)> flush_reasons_{};
    uint64_t use_program_count_ = 0;
    uint64_t uniform_upload_count_ = 0;
    int n64_fb_w_ = 320;
    int n64_fb_h_ = 240;
    int target_w_ = 320;
    int target_h_ = 240;
};

} // namespace dkr::runtime
