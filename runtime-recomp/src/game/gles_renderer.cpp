#include "gles_renderer.hpp"
#include "f3ddkr_gles.hpp"

#include "game_registration.hpp"
#include "librecomp/game.hpp"

#include <GLES2/gl2.h>
#include <SDL2/SDL.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

namespace dkr::runtime {

GLES2Renderer::GLES2Renderer(std::uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle,
                             bool developer_mode)
    : rdram_(rdram), developer_mode_(developer_mode) {
    setup_result = ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
    chosen_api = ultramodern::renderer::GraphicsApi::Auto;

#if defined(_WIN32)
    window_ = window_handle.window;
#else
    window_ = window_handle;
#endif

    if (window_ == nullptr) {
        std::fprintf(stderr, "[boot][gles] Window handle is null; cannot initialize OpenGL ES\n");
        return;
    }

    auto* sdl_window = static_cast<SDL_Window*>(window_);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

    SDL_GLContext gl_ctx = SDL_GL_CreateContext(sdl_window);
    if (gl_ctx == nullptr) {
        std::fprintf(stderr, "[boot][gles] Failed to create OpenGL ES context: %s\n", SDL_GetError());
        setup_result = ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
        return;
    }

    gl_context_ = gl_ctx;
    if (SDL_GL_MakeCurrent(sdl_window, gl_ctx) != 0) {
        std::fprintf(stderr, "[boot][gles] Failed to make GLES context current: %s\n", SDL_GetError());
        SDL_GL_DeleteContext(gl_ctx);
        gl_context_ = nullptr;
        return;
    }

    SDL_GL_SetSwapInterval(1); // Enable VSync

    SDL_GetWindowSize(sdl_window, &viewport_width_, &viewport_height_);

    initialize_gl_state();

    setup_result = ultramodern::renderer::SetupResult::Success;
    valid_ = true;

    const auto* vendor = reinterpret_cast<const char*>(glGetString(GL_VENDOR));
    const auto* renderer_name = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
    const auto* version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    const auto* sl_version = reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION));

    std::fprintf(stderr,
                 "[boot][gles] Initialized OpenGL ES Context\n"
                 "             Vendor:   %s\n"
                 "             Renderer: %s\n"
                 "             Version:  %s\n"
                 "             GLSL:     %s\n"
                 "             Viewport: %dx%d\n",
                 vendor ? vendor : "Unknown", renderer_name ? renderer_name : "Unknown", version ? version : "Unknown",
                 sl_version ? sl_version : "Unknown", viewport_width_, viewport_height_);
}


GLES2Renderer::~GLES2Renderer() {
    shutdown();
    bridge_.reset();
}

void GLES2Renderer::init_fbo(int width, int height) {
    if (fbo_ != 0 && fbo_w_ == width && fbo_h_ == height) {
        return;
    }
    destroy_fbo();

    fbo_w_ = width;
    fbo_h_ = height;

    glGenFramebuffers(1, &fbo_);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo_);

    glGenTextures(1, &fbo_color_tex_);
    glBindTexture(GL_TEXTURE_2D, fbo_color_tex_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, fbo_w_, fbo_h_, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fbo_color_tex_, 0);

    glGenRenderbuffers(1, &fbo_depth_rb_);
    glBindRenderbuffer(GL_RENDERBUFFER, fbo_depth_rb_);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, fbo_w_, fbo_h_);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, fbo_depth_rb_);

    const GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        std::fprintf(stderr, "[gles] FBO incomplete (status 0x%X); falling back to default framebuffer\n", status);
        destroy_fbo();
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        return;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    static bool s_fbo_logged = false;
    if (!s_fbo_logged) {
        s_fbo_logged = true;
        std::fprintf(stderr, "[gles] Offscreen native FBO created: %dx%d (render_scale=%d)\n", fbo_w_, fbo_h_, render_scale_);
    }
}

void GLES2Renderer::destroy_fbo() {
    if (fbo_depth_rb_ != 0) {
        glDeleteRenderbuffers(1, &fbo_depth_rb_);
        fbo_depth_rb_ = 0;
    }
    if (fbo_color_tex_ != 0) {
        glDeleteTextures(1, &fbo_color_tex_);
        fbo_color_tex_ = 0;
    }
    if (fbo_ != 0) {
        glDeleteFramebuffers(1, &fbo_);
        fbo_ = 0;
    }
    fbo_w_ = 0;
    fbo_h_ = 0;
}

void GLES2Renderer::init_blit_pipeline() {
    const char* kBlitVS =
        "attribute vec2 a_pos;\n"
        "attribute vec2 a_uv;\n"
        "varying vec2 v_uv;\n"
        "void main() {\n"
        "    v_uv = a_uv;\n"
        "    gl_Position = vec4(a_pos, 0.0, 1.0);\n"
        "}\n";

    const char* kBlitFS =
        "precision mediump float;\n"
        "varying vec2 v_uv;\n"
        "uniform sampler2D u_tex;\n"
        "void main() {\n"
        "    gl_FragColor = texture2D(u_tex, v_uv);\n"
        "}\n";

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &kBlitVS, nullptr);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &kBlitFS, nullptr);
    glCompileShader(fs);

    blit_program_ = glCreateProgram();
    glAttachShader(blit_program_, vs);
    glAttachShader(blit_program_, fs);
    glLinkProgram(blit_program_);
    glDeleteShader(vs);
    glDeleteShader(fs);

    blit_pos_loc_ = glGetAttribLocation(blit_program_, "a_pos");
    blit_uv_loc_  = glGetAttribLocation(blit_program_, "a_uv");
    blit_tex_loc_ = glGetUniformLocation(blit_program_, "u_tex");

    // Fullscreen quad: triangle strip
    const float blit_verts[] = {
        // x, y, u, v
        -1.0f, -1.0f, 0.0f, 0.0f,
         1.0f, -1.0f, 1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f, 1.0f,
         1.0f,  1.0f, 1.0f, 1.0f,
    };
    glGenBuffers(1, &blit_vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, blit_vbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(blit_verts), blit_verts, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GLES2Renderer::initialize_gl_state() {
    if (const char* env_scale = std::getenv("DKR_RENDER_SCALE")) {
        render_scale_ = std::clamp(std::atoi(env_scale), 1, 4);
    } else {
        render_scale_ = 1;
    }

    if (const char* env_mode = std::getenv("DKR_SCALE_MODE")) {
        scale_mode_ = env_mode;
    } else {
        scale_mode_ = "fit";
    }

    if (const char* env_filter = std::getenv("DKR_SCALE_FILTER")) {
        scale_filter_ = env_filter;
    } else {
        scale_filter_ = "nearest";
    }

    const char* extensions = reinterpret_cast<const char*>(glGetString(GL_EXTENSIONS));
    if (extensions != nullptr && std::strstr(extensions, "GL_EXT_discard_framebuffer") != nullptr) {
        glDiscardFramebufferEXT_ = reinterpret_cast<PFNGLDISCARDFRAMEBUFFEREXTPROC>(SDL_GL_GetProcAddress("glDiscardFramebufferEXT"));
        has_discard_framebuffer_ = (glDiscardFramebufferEXT_ != nullptr);
        if (has_discard_framebuffer_) {
            std::fprintf(stderr, "[gles] GL_EXT_discard_framebuffer extension detected and loaded\n");
        }
    }

    glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    bridge_ = std::make_unique<F3DDKRGLESBridge>();
    bridge_->init();

    init_blit_pipeline();
    init_fbo(bridge_->n64_fb_width() * render_scale_, bridge_->n64_fb_height() * render_scale_);

    if (fbo_ != 0) {
        bridge_->set_target_size(fbo_w_, fbo_h_);
        bridge_->set_viewport(0, 0, fbo_w_, fbo_h_);
    } else {
        bridge_->set_window_size(viewport_width_, viewport_height_);
        bridge_->set_viewport(0, 0, viewport_width_, viewport_height_);
    }
}

bool GLES2Renderer::valid() {
    return valid_;
}

bool GLES2Renderer::update_config(const ultramodern::renderer::GraphicsConfig&,
                                  const ultramodern::renderer::GraphicsConfig&) {
    if (window_ != nullptr) {
        auto* sdl_window = static_cast<SDL_Window*>(window_);
        SDL_GL_GetDrawableSize(sdl_window, &viewport_width_, &viewport_height_);
    }
    return true;
}

void GLES2Renderer::enable_instant_present() {
    // Keep SDL_GL_SetSwapInterval(1) on KMS/DRM (Rockchip Mali-G31).
}

void GLES2Renderer::send_dl(const OSTask* task, std::uint8_t* rdram_snapshot) {
    std::scoped_lock lock(presentation_mutex_);
    if (!valid_ || task == nullptr) {
        return;
    }

    if (developer_mode_) {
        static bool s_thread_logged = false;
        if (!s_thread_logged) {
            s_thread_logged = true;
            std::fprintf(stderr, "[gles][thread] send_dl running on thread %zu\n",
                         std::hash<std::thread::id>{}(std::this_thread::get_id()));
        }
    }

    const auto index = ++display_list_count_;
    if (developer_mode_ && (index <= 5 || index % 120 == 0)) {
        std::fprintf(stderr, "[boot][gles][dl] task=%llu ucode=0x%08X data=0x%08X size=%u snapshot=%s\n",
                     static_cast<unsigned long long>(index), task->t.ucode, task->t.data_ptr, task->t.data_size,
                     rdram_snapshot != nullptr ? "valid" : "null");
    }

    if (bridge_) {
        const int target_w = bridge_->n64_fb_width() * render_scale_;
        const int target_h = bridge_->n64_fb_height() * render_scale_;
        init_fbo(target_w, target_h);

        if (fbo_ != 0) {
            glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
            bridge_->set_target_size(fbo_w_, fbo_h_);
            glDisable(GL_SCISSOR_TEST);
            glDepthMask(GL_TRUE);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            bridge_->invalidate_gl_cache();
        } else {
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
            bridge_->set_target_size(viewport_width_, viewport_height_);
        }

        bridge_->process_task(*task, rdram_snapshot != nullptr ? rdram_snapshot : rdram_);
        frame_rendered_ = true;
    }
}

void GLES2Renderer::set_target_fps(std::uint32_t fps) {
    target_fps_ = fps;
}

void GLES2Renderer::enable_frame_pacing(bool enable) {
    frame_pacing_enabled_ = enable;
}

void GLES2Renderer::update_screen() {
    auto* sdl_window = static_cast<SDL_Window*>(window_);
    std::scoped_lock lock(presentation_mutex_);
    if (!valid_ || window_ == nullptr || gl_context_ == nullptr) {
        return;
    }

    if (present_count_ == 0) {
        ++present_count_;
        std::fprintf(stderr, "[boot] VI initialized (GLES2); starting recompiled DKR entrypoint\n");
        recomp::start_game(kGameId);
        last_present_time_ = std::chrono::steady_clock::now();
        return;
    }

    if (!frame_rendered_) {
        // No graphics task rendered during this VI tick; do not swap backbuffer
        return;
    }
    frame_rendered_ = false;
    const uint64_t index = ++present_count_;

    int drawable_w = viewport_width_;
    int drawable_h = viewport_height_;
    SDL_GL_GetDrawableSize(sdl_window, &drawable_w, &drawable_h);

    if (fbo_ != 0 && blit_program_ != 0) {
        if (has_discard_framebuffer_ && glDiscardFramebufferEXT_ != nullptr) {
            const GLenum discard_attach[1] = { GL_DEPTH_ATTACHMENT };
            glDiscardFramebufferEXT_(GL_FRAMEBUFFER, 1, discard_attach);
        }

        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        glDisable(GL_DEPTH_TEST);
        glDepthMask(GL_FALSE);
        glDisable(GL_SCISSOR_TEST);
        glDisable(GL_BLEND);

        glViewport(0, 0, drawable_w, drawable_h);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        const float scale_x = static_cast<float>(drawable_w) / static_cast<float>(fbo_w_);
        const float scale_y = static_cast<float>(drawable_h) / static_cast<float>(fbo_h_);

        int dst_x = 0, dst_y = 0;
        int dst_w = drawable_w, dst_h = drawable_h;

        if (scale_mode_ == "stretch") {
            dst_x = 0; dst_y = 0;
            dst_w = drawable_w; dst_h = drawable_h;
        } else if (scale_mode_ == "integer") {
            const float scale = std::max(1.0f, std::floor(std::min(scale_x, scale_y)));
            dst_w = static_cast<int>(fbo_w_ * scale);
            dst_h = static_cast<int>(fbo_h_ * scale);
            dst_x = (drawable_w - dst_w) / 2;
            dst_y = (drawable_h - dst_h) / 2;
        } else { // "fit" (default)
            const float scale = std::min(scale_x, scale_y);
            dst_w = static_cast<int>(fbo_w_ * scale);
            dst_h = static_cast<int>(fbo_h_ * scale);
            dst_x = (drawable_w - dst_w) / 2;
            dst_y = (drawable_h - dst_h) / 2;
        }

        glViewport(dst_x, dst_y, dst_w, dst_h);

        GLenum filter = GL_NEAREST;
        if (scale_filter_ == "linear") {
            filter = GL_LINEAR;
        } else if (scale_filter_ == "nearest") {
            filter = GL_NEAREST;
        } else {
            const float min_scale = std::min(scale_x, scale_y);
            const bool is_int = (std::abs(min_scale - std::round(min_scale)) < 0.01f);
            filter = is_int ? GL_NEAREST : GL_LINEAR;
        }

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, fbo_color_tex_);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

        glUseProgram(blit_program_);
        if (blit_tex_loc_ >= 0) {
            glUniform1i(blit_tex_loc_, 0);
        }

        glBindBuffer(GL_ARRAY_BUFFER, blit_vbo_);
        if (blit_pos_loc_ >= 0) {
            glEnableVertexAttribArray(static_cast<GLuint>(blit_pos_loc_));
            glVertexAttribPointer(static_cast<GLuint>(blit_pos_loc_), 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), reinterpret_cast<void*>(0));
        }
        if (blit_uv_loc_ >= 0) {
            glEnableVertexAttribArray(static_cast<GLuint>(blit_uv_loc_));
            glVertexAttribPointer(static_cast<GLuint>(blit_uv_loc_), 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), reinterpret_cast<void*>(2 * sizeof(float)));
        }

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        if (blit_pos_loc_ >= 0) glDisableVertexAttribArray(static_cast<GLuint>(blit_pos_loc_));
        if (blit_uv_loc_ >= 0) glDisableVertexAttribArray(static_cast<GLuint>(blit_uv_loc_));
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    SDL_GL_SwapWindow(sdl_window);

    if (bridge_) {
        bridge_->invalidate_gl_cache();
    }

    last_present_time_ = std::chrono::steady_clock::now();

    static const bool s_log_vi = []() {
        if (const char* env = std::getenv("DKR_GLES_LOG")) {
            return std::atoi(env) != 0;
        }
        return false;
    }();

    if (s_log_vi && (index <= 5 || index % 60 == 0)) {
        std::fprintf(stderr, "[gles][vi] present=%llu\n", static_cast<unsigned long long>(index));
    }
}

void GLES2Renderer::shutdown() {
    std::scoped_lock lock(presentation_mutex_);
    destroy_fbo();
    if (blit_vbo_ != 0) {
        glDeleteBuffers(1, &blit_vbo_);
        blit_vbo_ = 0;
    }
    if (blit_program_ != 0) {
        glDeleteProgram(blit_program_);
        blit_program_ = 0;
    }
    if (gl_context_ != nullptr) {
        auto* sdl_ctx = static_cast<SDL_GLContext>(gl_context_);
        SDL_GL_MakeCurrent(nullptr, nullptr);
        SDL_GL_DeleteContext(sdl_ctx);
        gl_context_ = nullptr;
    }
    valid_ = false;
    window_ = nullptr;
}

std::uint32_t GLES2Renderer::get_display_framerate() const {
    return 30; // DKR simulation rate
}

float GLES2Renderer::get_resolution_scale() const {
    return static_cast<float>(render_scale_);
}

std::unique_ptr<ultramodern::renderer::RendererContext>
CreateGLES2Renderer(std::uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
    return std::make_unique<GLES2Renderer>(rdram, window_handle, developer_mode);
}

} // namespace dkr::runtime
