#pragma once

#include "ultramodern/renderer_context.hpp"
#include "ultramodern/ultra64.h"

#include <GLES2/gl2.h>
#include <atomic>
#include <cstdint>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>

namespace dkr::runtime {

class GLES2Renderer final : public ultramodern::renderer::RendererContext {
public:
    GLES2Renderer(std::uint8_t* rdram,
                  ultramodern::renderer::WindowHandle window_handle,
                  bool developer_mode);
    ~GLES2Renderer() override;

    bool valid() override;
    bool update_config(const ultramodern::renderer::GraphicsConfig& old_config,
                       const ultramodern::renderer::GraphicsConfig& new_config) override;
    void enable_instant_present() override;
    void send_dl(const OSTask* task, std::uint8_t* rdram_snapshot) override;
    void update_screen() override;
    void shutdown() override;
    std::uint32_t get_display_framerate() const override;
    float get_resolution_scale() const override;

    void set_target_fps(std::uint32_t fps);
    void enable_frame_pacing(bool enable);

private:
    std::mutex presentation_mutex_;
    std::uint8_t* rdram_ = nullptr;
    void* window_ = nullptr;
    void* gl_context_ = nullptr;
    std::atomic<std::uint64_t> display_list_count_{0};
    std::atomic<std::uint64_t> present_count_{0};
    bool valid_ = false;
    bool developer_mode_ = false;
    int viewport_width_ = 640;
    int viewport_height_ = 480;

    // Handheld frame pacing & battery saver (30 FPS default for DKR)
    bool frame_pacing_enabled_ = true;
    bool frame_rendered_ = false;
    std::uint32_t target_fps_ = 30;
    std::chrono::steady_clock::time_point last_present_time_{};

    std::unique_ptr<class F3DDKRGLESBridge> bridge_;

    // Native resolution FBO and display scaling
    GLuint fbo_ = 0;
    GLuint fbo_color_tex_ = 0;
    GLuint fbo_depth_rb_ = 0;
    int fbo_w_ = 0;
    int fbo_h_ = 0;
    int render_scale_ = 1;
    std::string scale_mode_ = "fit";
    std::string scale_filter_ = "nearest";

    // Fullscreen blit shader and geometry
    GLuint blit_program_ = 0;
    GLint blit_pos_loc_ = -1;
    GLint blit_uv_loc_ = -1;
    GLint blit_tex_loc_ = -1;
    GLuint blit_vbo_ = 0;

    // Extension function pointer for glDiscardFramebufferEXT
    typedef void (*PFNGLDISCARDFRAMEBUFFEREXTPROC)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
    PFNGLDISCARDFRAMEBUFFEREXTPROC glDiscardFramebufferEXT_ = nullptr;
    bool has_discard_framebuffer_ = false;

    void initialize_gl_state();
    void init_fbo(int width, int height);
    void destroy_fbo();
    void init_blit_pipeline();
};

std::unique_ptr<ultramodern::renderer::RendererContext> CreateGLES2Renderer(
    std::uint8_t* rdram,
    ultramodern::renderer::WindowHandle window_handle,
    bool developer_mode);

} // namespace dkr::runtime
