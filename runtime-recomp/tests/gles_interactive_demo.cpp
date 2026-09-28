#include "f3ddkr_gles.hpp"

#include <SDL.h>

#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <vector>

namespace {

constexpr int kScreenWidth = 640;
constexpr int kScreenHeight = 480;
constexpr uint32_t kRDRAMSize = 0x00800000U; // 8 MB

void WriteVtx(uint8_t* rdram, uint32_t addr, int16_t x, int16_t y, int16_t z,
              uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    std::memcpy(rdram + ((addr + 0U) ^ 2U), &x, sizeof(x));
    std::memcpy(rdram + ((addr + 2U) ^ 2U), &y, sizeof(y));
    std::memcpy(rdram + ((addr + 4U) ^ 2U), &z, sizeof(z));
    rdram[(addr + 6U) ^ 3U] = r;
    rdram[(addr + 7U) ^ 3U] = g;
    rdram[(addr + 8U) ^ 3U] = b;
    rdram[(addr + 9U) ^ 3U] = a;
}

void WriteTri(uint8_t* rdram, uint32_t addr, uint8_t v0, uint8_t v1, uint8_t v2,
              int16_t s0, int16_t t0, int16_t s1, int16_t t1, int16_t s2, int16_t t2) {
    rdram[addr + 0] = 0x40; // No culling
    rdram[addr + 1] = v0;
    rdram[addr + 2] = v1;
    rdram[addr + 3] = v2;
    std::memcpy(rdram + ((addr + 4U) ^ 2U), &s0, sizeof(s0));
    std::memcpy(rdram + ((addr + 6U) ^ 2U), &t0, sizeof(t0));
    std::memcpy(rdram + ((addr + 8U) ^ 2U), &s1, sizeof(s1));
    std::memcpy(rdram + ((addr + 10U) ^ 2U), &t1, sizeof(t1));
    std::memcpy(rdram + ((addr + 12U) ^ 2U), &s2, sizeof(s2));
    std::memcpy(rdram + ((addr + 14U) ^ 2U), &t2, sizeof(t2));
}

void WriteFixedPointMatrix(uint8_t* rdram, uint32_t addr, const float m[4][4]) {
    addr &= 0x00FFFFFFU;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            const uint32_t idx = static_cast<uint32_t>((i * 4 + j) * 2);
            float val = m[i][j];
            int16_t int_part = static_cast<int16_t>(val);
            float frac = val - static_cast<float>(int_part);
            uint16_t frac_part = static_cast<uint16_t>(std::clamp(frac * 65536.0f, 0.0f, 65535.0f));
            std::memcpy(rdram + ((addr + idx) ^ 2U), &int_part, sizeof(int_part));
            std::memcpy(rdram + ((addr + 32U + idx) ^ 2U), &frac_part, sizeof(frac_part));
        }
    }
}

} // namespace

int main(int argc, char* argv[]) {
    std::printf("=====================================================\n");
    std::printf(" Diddy Kong Racing (Recompiled) - GLES Handheld Demo\n");
    std::printf(" Target: R36XX / RK3326 ARM Mali-G31 MP2 / PortMaster\n");
    std::printf("=====================================================\n");

    bool fullscreen = false;
    uint32_t max_frames = 0;
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--fullscreen") == 0 || std::strcmp(argv[i], "-f") == 0) {
            fullscreen = true;
        } else if ((std::strcmp(argv[i], "--frames") == 0 || std::strcmp(argv[i], "-n") == 0) && i + 1 < argc) {
            max_frames = static_cast<uint32_t>(std::atoi(argv[++i]));
        }
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO) != 0) {
        std::fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    // Load gamecontrollerdb if present
    SDL_GameControllerAddMappingsFromFile("gamecontrollerdb.txt");
    SDL_GameControllerAddMappingsFromFile("dkrr/gamecontrollerdb.txt");

    // Open first available game controller
    SDL_GameController* controller = nullptr;
    for (int i = 0; i < SDL_NumJoysticks(); ++i) {
        if (SDL_IsGameController(i)) {
            controller = SDL_GameControllerOpen(i);
            if (controller != nullptr) {
                std::printf("[input] Opened game controller %d: %s\n", i, SDL_GameControllerName(controller));
                break;
            }
        }
    }

    // Configure GLES 2.0 context attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

    Uint32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    if (fullscreen) {
        window_flags |= SDL_WINDOW_FULLSCREEN;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Diddy Kong Racing Recompiled (GLES)",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        kScreenWidth, kScreenHeight, window_flags
    );

    if (window == nullptr) {
        std::fprintf(stderr, "Failed to create SDL window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_GLContext gl_ctx = SDL_GL_CreateContext(window);
    if (gl_ctx == nullptr) {
        std::fprintf(stderr, "Failed to create GLES context: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_GL_MakeCurrent(window, gl_ctx);
    SDL_GL_SetSwapInterval(1); // Enable VSync

    std::printf("[gles] Vendor:   %s\n", glGetString(GL_VENDOR));
    std::printf("[gles] Renderer: %s\n", glGetString(GL_RENDERER));
    std::printf("[gles] Version:  %s\n", glGetString(GL_VERSION));

    // Initialize F3DDKR GLES Bridge
    dkr::runtime::F3DDKRGLESBridge bridge;
    bridge.init();
    bridge.set_viewport(0, 0, kScreenWidth, kScreenHeight);

    // Simulated RDRAM memory
    std::vector<uint8_t> rdram(kRDRAMSize, 0);

    // 1. Create 16x16 RGBA16 Checkerboard Texture in RDRAM (address 0x10000)
    const uint32_t tex_addr = 0x10000;
    for (int y = 0; y < 16; ++y) {
        for (int x = 0; x < 16; ++x) {
            bool check = ((x / 4) + (y / 4)) % 2 == 0;
            // Yellow (0xFFE1) / Orange (0xFBE1)
            uint16_t col = check ? 0xFFE1 : 0xFA01;
            uint32_t offset = tex_addr + static_cast<uint32_t>((y * 16 + x) * 2);
            rdram[offset + 0] = static_cast<uint8_t>(col >> 8);
            rdram[offset + 1] = static_cast<uint8_t>(col & 0xFF);
        }
    }

    // 2. Setup Terrain Vertices at 0x20000
    const uint32_t terrain_vtx_addr = 0x20000;
    WriteVtx(rdram.data(), terrain_vtx_addr + 0,  -200, -80, -200,  80, 200, 80, 255);
    WriteVtx(rdram.data(), terrain_vtx_addr + 10,  200, -80, -200,  80, 200, 80, 255);
    WriteVtx(rdram.data(), terrain_vtx_addr + 20,  200, -80,  200,  50, 160, 50, 255);
    WriteVtx(rdram.data(), terrain_vtx_addr + 30, -200, -80,  200,  50, 160, 50, 255);

    // Terrain Triangles at 0x21000
    const uint32_t terrain_tri_addr = 0x21000;
    WriteTri(rdram.data(), terrain_tri_addr + 0, 0, 1, 2, 0, 0, 16*32, 0, 16*32, 16*32);
    WriteTri(rdram.data(), terrain_tri_addr + 16, 0, 2, 3, 0, 0, 16*32, 16*32, 0, 16*32);

    // 3. Setup Kart Model Vertices at 0x22000 (Pyramid/Prism kart)
    const uint32_t kart_vtx_addr = 0x22000;
    WriteVtx(rdram.data(), kart_vtx_addr + 0,   0,  30,   0, 255, 50,  50, 255); // Top (Red)
    WriteVtx(rdram.data(), kart_vtx_addr + 10, -40, -20, -50, 240, 200, 30, 255); // Back-Left (Yellow)
    WriteVtx(rdram.data(), kart_vtx_addr + 20,  40, -20, -50, 240, 200, 30, 255); // Back-Right (Yellow)
    WriteVtx(rdram.data(), kart_vtx_addr + 30,   0, -20,  60,  30, 180, 240, 255); // Nose (Cyan)

    // Kart Triangles at 0x23000
    const uint32_t kart_tri_addr = 0x23000;
    WriteTri(rdram.data(), kart_tri_addr + 0,  0, 1, 3, 8*32, 0, 0, 16*32, 16*32, 16*32);
    WriteTri(rdram.data(), kart_tri_addr + 16, 0, 3, 2, 8*32, 0, 16*32, 16*32, 0, 16*32);
    WriteTri(rdram.data(), kart_tri_addr + 32, 0, 2, 1, 8*32, 0, 16*32, 16*32, 0, 16*32);

    // Matrices addresses
    const uint32_t proj_mtx_addr = 0x40000;
    const uint32_t view_mtx_addr = 0x40040;
    const uint32_t kart_mtx_addr = 0x40080;

    // Display List address
    const uint32_t dl_addr = 0x50000;

    // Projection matrix (Perspective: fov 60 deg, 640/480 aspect, near 10, far 1000)
    float fov_y = 60.0f * 3.14159265f / 180.0f;
    float aspect = 640.0f / 480.0f;
    float f = 1.0f / std::tan(fov_y / 2.0f);
    float near_z = 10.0f, far_z = 1000.0f;
    float proj[4][4] = {
        {f / aspect, 0, 0, 0},
        {0, f, 0, 0},
        {0, 0, (far_z + near_z) / (near_z - far_z), (2.0f * far_z * near_z) / (near_z - far_z)},
        {0, 0, -1.0f, 0}
    };
    WriteFixedPointMatrix(rdram.data(), proj_mtx_addr, proj);

    float kart_rot_y = 0.0f;
    float cam_rot_x = 0.25f;
    float cam_dist = 280.0f;
    bool running = true;

    auto last_time = std::chrono::steady_clock::now();
    uint64_t frame_count = 0;
    uint64_t total_frames = 0;
    auto last_fps_report = last_time;

    std::printf("[demo] Running demo loop (Press Start+Select or Esc to exit)...\n");

    while (running) {
        if (max_frames > 0 && total_frames >= max_frames) {
            std::printf("[demo] Reached requested limit of %u frames. Exiting cleanly.\n", max_frames);
            break;
        }
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            } else if (event.type == SDL_CONTROLLERBUTTONDOWN) {
                if (event.cbutton.button == SDL_CONTROLLER_BUTTON_START) {
                    // Check if Select is also held for PortMaster exit
                    if (controller != nullptr && SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK)) {
                        running = false;
                    }
                }
            }
        }

        // Controller analog stick / button input
        if (controller != nullptr) {
            int16_t axis_x = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX);
            int16_t axis_y = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY);
            if (std::abs(axis_x) > 4000) {
                kart_rot_y += static_cast<float>(axis_x) / 32768.0f * 0.06f;
            }
            if (std::abs(axis_y) > 4000) {
                cam_dist += static_cast<float>(axis_y) / 32768.0f * 4.0f;
                cam_dist = std::clamp(cam_dist, 100.0f, 600.0f);
            }
        } else {
            // Auto-rotate if no gamepad connected
            kart_rot_y += 0.03f;
        }

        // View matrix
        float cam_y = cam_dist * std::sin(cam_rot_x);
        float cam_z = cam_dist * std::cos(cam_rot_x);
        float view[4][4] = {
            {1.0f, 0.0f, 0.0f, 0.0f},
            {0.0f, std::cos(-cam_rot_x), -std::sin(-cam_rot_x), -cam_y * 0.5f},
            {0.0f, std::sin(-cam_rot_x),  std::cos(-cam_rot_x), -cam_z},
            {0.0f, 0.0f, 0.0f, 1.0f}
        };
        WriteFixedPointMatrix(rdram.data(), view_mtx_addr, view);

        // Kart model matrix
        float cos_r = std::cos(kart_rot_y);
        float sin_r = std::sin(kart_rot_y);
        float kart_m[4][4] = {
            {cos_r, 0.0f, sin_r, 0.0f},
            {0.0f,  1.0f, 0.0f,  0.0f},
            {-sin_r, 0.0f, cos_r, 0.0f},
            {0.0f,  0.0f, 0.0f,  1.0f}
        };
        WriteFixedPointMatrix(rdram.data(), kart_mtx_addr, kart_m);

        // Build Display List
        uint32_t dl_idx = 0;
        auto emit_cmd = [&](uint32_t w0, uint32_t w1) {
            std::memcpy(rdram.data() + dl_addr + dl_idx * 8U, &w0, sizeof(w0));
            std::memcpy(rdram.data() + dl_addr + dl_idx * 8U + 4U, &w1, sizeof(w1));
            ++dl_idx;
        };

        // Render States
        emit_cmd(0xEF000000U, 0x00000030U | 0x00000001U); // depth test on
        emit_cmd(0xB7000000U, 0x00002000U); // G_SETGEOMETRYMODE: cull back (F3D)
        emit_cmd(0xFA000000U, 0xFFFFFFFFU); // prim color white
        emit_cmd(0xFB000000U, 0xFFFFFFFFU); // env color white
        emit_cmd(0xFC121824U, 0xFF33FFFFU); // combiner: modulate

        // Load Projection Matrix
        emit_cmd(0x01000000U, proj_mtx_addr); // gSPMatrix (Projection)
        // Load View Matrix
        emit_cmd(0x01020000U, view_mtx_addr); // gSPMatrix (ModelView)

        // Texture setup: 16x16 RGBA16
        emit_cmd(0xFD10000FU, tex_addr);      // G_SETTIMG
        emit_cmd(0xF5100000U, 0x00000000U);  // G_SETTILE
        emit_cmd(0xF2000000U, 0x0003C03CU);  // G_SETTILESIZE (16x16)
        emit_cmd(0xF3000000U, 0x000FF000U);  // G_LOADBLOCK (256 texels)

        // Draw Terrain
        emit_cmd(0x04180000U, terrain_vtx_addr); // 4 vertices
        emit_cmd(0x05010000U, terrain_tri_addr); // 2 triangles

        // Push ModelView matrix, multiply with Kart rotation matrix
        emit_cmd(0x01030000U, kart_mtx_addr);

        // Draw Kart Model
        emit_cmd(0x04180000U, kart_vtx_addr);    // 4 vertices
        emit_cmd(0x05010000U, kart_tri_addr);    // 2 triangles
        emit_cmd(0x05010000U, kart_tri_addr + 32); // 1 triangle

        // 2D HUD: Draw Speedometer & Minimap Background using G_FILLRECT & G_TEXRECT
        emit_cmd(0xED000000U, 0x00A00078U); // scissor full
        emit_cmd(0xF7000000U, 0x00000080U); // transparent dark fill
        emit_cmd(0xF6010010U, 0x000A0050U); // fillrect HUD border

        // End Display List
        emit_cmd(0xB8000000U, 0x00000000U);

        // Execute Display List
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        bridge.execute_display_list(dl_addr, rdram.data());
        bridge.flush_batch();

        SDL_GL_SwapWindow(window);

        // 30 FPS Frame Pacing & Battery Saver
        using namespace std::chrono;
        const auto target_frame_us = microseconds(33333); // 30 FPS
        auto now = steady_clock::now();
        auto elapsed = duration_cast<microseconds>(now - last_time);
        if (elapsed < target_frame_us) {
            auto remaining = target_frame_us - elapsed;
            if (remaining > microseconds(2500)) {
                std::this_thread::sleep_for(remaining - microseconds(1500));
            }
            while (duration_cast<microseconds>(steady_clock::now() - last_time) < target_frame_us) {
                std::this_thread::yield();
            }
        }
        last_time = steady_clock::now();

        ++frame_count;
        ++total_frames;
        if (duration_cast<seconds>(last_time - last_fps_report).count() >= 3) {
            double fps = static_cast<double>(frame_count) /
                         duration_cast<duration<double>>(last_time - last_fps_report).count();
            std::printf("[demo] Render loop: %.1f FPS (30 FPS target, VSync locked)\n", fps);
            frame_count = 0;
            last_fps_report = last_time;
        }
    }

    std::printf("[demo] Exiting demo cleanly.\n");

    if (controller != nullptr) {
        SDL_GameControllerClose(controller);
    }
    SDL_GL_DeleteContext(gl_ctx);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
