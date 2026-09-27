# Diddy Kong Racing (Recompiled) - PortMaster for R36XX / RK3326

This port runs Diddy Kong Racing natively on the Rockchip RK3326 handheld (R36S, R35S, RG351, RGB20S) using a dedicated OpenGL ES 2.0 / 3.0 renderer.

## Prerequisites & Setup (BYOR: Bring Your Own ROM)

1. Obtain a legally dumped **Diddy Kong Racing (USA) v1.0** ROM (`.z64`, `.v64`, or `.n64`).
   - Supported SHA-1 (normalized): `c2ad117ab823528b49e37c44ef5d194c79803154` (or retail US releases)
2. Rename the file to:
   ```text
   dkr.z64
   ```
3. Place `dkr.z64` into:
   ```text
   /roms/ports/dkrr/gamedata/dkr.z64
   ```
   *(Alternatively, `dkr.v64` or `dkr.n64` in `gamedata/` will also be detected automatically).*
4. Copy the PortMaster package files to your handheld SD card:
   - `Diddy Kong Racing.sh` -> `/roms/ports/`
   - `dkrr/` directory -> `/roms/ports/dkrr/`
5. Boot your handheld, navigate to **Ports** in EmulationStation, and launch **Diddy Kong Racing**!

## Building from Source

To cross-compile and package DKR-R for PortMaster / RK3326 devices on a Linux x86_64 host:

### 1. Requirements
- Clang / LLVM toolchain: `sudo apt-get install clang llvm lld`
- AArch64 GCC cross-compiler: `sudo apt-get install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu`
- CMake 3.24+ and Ninja: `sudo apt-get install cmake ninja-build`
- Python 3

### 2. Build and Package
From the repository root:
```bash
./scripts/build-r36xx.sh
```
This script will:
1. Configure CMake with `-DDKR_RUNTIME_BUILD_GLES=ON` using the AArch64 toolchain.
2. Compile the native arm64 executable `DKR-R`.
3. Auto-stage any local ROM in the project root to `gamedata/dkr.z64` (if present).
4. Bundle runtime libraries, launcher script, and `gptokeyb` mappings.
5. Create the ready-to-flash PortMaster distribution archive:
   ```text
   dist/DiddyKongRacing-R36XX-PortMaster.zip
   ```

To perform a clean rebuild:
```bash
./scripts/build-r36xx.sh --clean
```

## Handheld Controls

| Handheld Button | N64 Action |
| :--- | :--- |
| **D-Pad / Left Stick** | Steer (Analog) |
| **A Button** | Accelerate |
| **B Button** | Brake / Reverse |
| **R1 / R2 Trigger** | Drift / Hop |
| **L1 / L2 Trigger** | Use Weapon / Item |
| **Right Stick** | C-Buttons |
| **Start** | Pause |
| **Select + Start** | Quit game |

## Runtime Options & Tuning

The launcher script `Diddy Kong Racing.sh` provides environment variables to customize the GLES renderer:

- `DKR_RENDER_SCALE`: `1` (native 320x240, 2x integer scale on 640x480 screen, recommended) or `2` (640x480).
- `DKR_SCALE_MODE`: `fit` (aspect ratio preserved, letterboxed), `integer` (pixel-perfect integer scaling), or `stretch`.
- `DKR_SCALE_FILTER`: `nearest` (authentic crisp pixels) or `linear` (smooth filtering).
- `DKR_GLES_GL_ERRORS`: Set to `1` in `Diddy Kong Racing.sh` to log any OpenGL ES errors.
- `DKR_GLES_PERF`: Set to `1` in `Diddy Kong Racing.sh` to log runtime performance counters once every second.
- `DKR_GLES_LOG`: Set to `1` in `Diddy Kong Racing.sh` to enable VI present frame logging.
*(Note: verbose and continuous logging are disabled by default to minimize SD card write wear).*
