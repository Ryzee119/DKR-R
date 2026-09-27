# Plan: Fix PortMaster CI build (`find_package(SDL2)` failure)

## Problem

The `Build PortMaster (R36XX / RK3326)` GitHub Actions job
(`.github/workflows/build-portmaster.yml`) fails at CMake configure:

```
CMake Error at CMakeLists.txt:750 (find_package):
  By not providing "FindSDL2.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "SDL2", but
  CMake did not find one.
```

### Root cause

1. The runner is x86_64, so `scripts/build-r36xx.sh` passes
   `-DCMAKE_TOOLCHAIN_FILE=runtime-recomp/cmake/aarch64-linux-gnu.toolchain.cmake`.
2. That toolchain expects an AArch64 sysroot at `<repo>/aarch64-sysroot-focal`.
   This directory is **gitignored** (`.gitignore` line 113: `/aarch64-sysroot*/`)
   and was assembled by hand on the developer's machine. It does not exist in CI.
3. Without the sysroot, the toolchain's `else()` branch runs. CMake searches
   `/usr/lib/aarch64-linux-gnu/cmake/SDL2`, which does not exist. The
   `libsdl2-dev` installed by the workflow is the **x86_64** package and is
   unusable for an aarch64 target anyway.

**Do not** "fix" this by pointing CMake at the host SDL2 or by dropping
`REQUIRED`. That links (or tries to link) x86_64 libraries into an aarch64
binary. The fix is to **reproducibly generate the sysroot in CI**.

## Reference: what the working local sysroot contains

CI must reproduce this layout (`aarch64-sysroot-focal/`):

| Component | Details |
|---|---|
| Base userland | Ubuntu 20.04 "focal" arm64, **glibc 2.31** (required for ArkOS / AmberELEC compatibility) |
| GCC runtime/headers | **GCC 13**: `usr/lib/gcc/aarch64-linux-gnu/13/` (crtbegin.o etc.), `usr/include/c++/13`, `usr/include/aarch64-linux-gnu/c++/13`. Likely from the `ubuntu-toolchain-r/test` PPA (focal build, linked against glibc 2.31) |
| GL | libglvnd EGL + GLESv2: `libEGL.so*`, `libGLESv2.so*`, `libGLdispatch.so*`, headers `EGL/`, `GLES2/`, `GLES3/`, `KHR/` |
| SDL2 | Headers at **2.30.2** in `usr/include/SDL2/`. `libSDL2-2.0.so.0.3000.2` (same library shipped in `portmaster/dkrr/lib/`), with symlinks `libSDL2-2.0.so.0 -> libSDL2-2.0.so.0.3000.2`, `libSDL2-2.0.so -> libSDL2-2.0.so.0`, `libSDL2.so -> libSDL2-2.0.so` |
| SDL2 CMake config | `usr/lib/aarch64-linux-gnu/cmake/SDL2/sdl2-config.cmake` (content below) |
| Other | `libasound`, `lib/ld-linux-aarch64.so.1`, `lib/aarch64-linux-gnu/*` |

The toolchain file already wires up `CMAKE_SYSROOT`, `CMAKE_FIND_ROOT_PATH`,
`SDL2_DIR`, `--gcc-toolchain=<sysroot>/usr`, `-static-libstdc++ -static-libgcc`
and `-fuse-ld=bfd`. None of that needs to change if the sysroot exists.

## Tasks

### Task 1: Create `scripts/setup-aarch64-sysroot.sh`

Requirements: bash, `set -euo pipefail`, no root needed, idempotent (safe to
re-run), outputs `$ROOT_DIR/aarch64-sysroot-focal`. Tools allowed: `curl`,
`gzip`, `dpkg-deb`, `tar`, `python3` (all present on `ubuntu-24.04` runners).

1. **Focal packages.** Download `dists/{focal,focal-updates}/main/binary-arm64/Packages.gz`
   from `http://ports.ubuntu.com/ubuntu-ports`. For each package below, take
   the newest `Filename:` entry (prefer `focal-updates`), download the `.deb`
   into a cache dir (e.g. `build/sysroot-debs/`), and extract with
   `dpkg-deb -x <deb> <sysroot>`. Do **not** use apt or dpkg multiarch.
   - `libc6`, `libc6-dev`, `linux-libc-dev`
   - `libasound2`, `libasound2-dev`
   - `libglvnd0`, `libglvnd-dev`, `libegl1`, `libegl-dev`, `libgles2`,
     `libgles-dev`, `libgl1`, `libglx0`, `libgl-dev`, `libglx-dev`
   - `libdrm2`, `libdrm-dev`
2. **GCC 13 packages.** Same method, using the PPA
   `https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu`, suite
   `focal`, `main/binary-arm64/Packages.gz`:
   - `gcc-13-base`, `libgcc-s1`, `libgcc-13-dev`, `libstdc++6`, `libstdc++-13-dev`,
     `libatomic1`, `libasan8`, `libubsan1`, `liblsan0`, `libtsan2`, `libhwasan0`, `libitm1`
   - After extracting, verify `usr/lib/gcc/aarch64-linux-gnu/13/crtbegin.o` and
     `usr/include/c++/13/vector` exist.
   - **Fallback** (only if the PPA lacks arm64 focal GCC 13): use focal's own
     `libgcc-10-dev` / `libstdc++-10-dev`, but first confirm the project
     compiles with libstdc++ 10 (the project uses modern C++; it may not).
     Report back rather than silently downgrading if it doesn't.
3. **SDL2 2.30.2.**
   - Download `https://github.com/libsdl-org/SDL/releases/download/release-2.30.2/SDL2-2.30.2.tar.gz`
     and verify its SHA256.
   - Copy `include/*.h` into `<sysroot>/usr/include/SDL2/`. The generic
     `include/SDL_config.h` in the release tarball is sufficient for compiling
     against. Make sure `SDL_revision.h` exists (the tarball ships one).
   - Copy `portmaster/dkrr/lib/libSDL2-2.0.so.0.3000.2` to
     `<sysroot>/usr/lib/aarch64-linux-gnu/` and create the three symlinks
     listed in the reference table (relative links).
   - Write `<sysroot>/usr/lib/aarch64-linux-gnu/cmake/SDL2/sdl2-config.cmake`
     with exactly this content:
     ```cmake
     set(prefix "/usr")
     set(exec_prefix "${prefix}")
     set(libdir "${prefix}/lib/aarch64-linux-gnu")
     set(SDL2_PREFIX "/usr")
     set(SDL2_EXEC_PREFIX "/usr")
     set(SDL2_INCLUDE_DIRS "${prefix}/include/SDL2")
     set(SDL2_LIBRARIES "-lSDL2")
     ```
     CMake's `CMAKE_FIND_ROOT_PATH` / sysroot handling maps `/usr` into the
     sysroot, and the include path is already added by the toolchain file.
4. **Fix absolute symlinks.** Debs contain links such as
   `usr/lib/aarch64-linux-gnu/libm.so -> /lib/aarch64-linux-gnu/libm.so.6`.
   Find them with `find "$SYSROOT" -type l -lname '/*'` and rewrite each as a
   relative link to `"$SYSROOT$(readlink "$link")"` (e.g. with
   `ln -sfn "$(realpath -m --relative-to="$(dirname "$link")" "$SYSROOT$target")" "$link"`).
   Leave linker scripts (`libc.so`, `libm.so`, `libpthread.so` text files)
   alone; `ld.bfd` resolves their absolute paths against `--sysroot`.
5. **Sanity checks.** Fail with a clear message if any of these is missing:
   - `usr/include/stdio.h`, `usr/include/SDL2/SDL.h`, `usr/include/GLES2/gl2.h`,
     `usr/include/EGL/egl.h`
   - `usr/lib/aarch64-linux-gnu/{crt1.o,crti.o,libc.so,libSDL2.so,libGLESv2.so,libEGL.so}`
   - `usr/lib/aarch64-linux-gnu/cmake/SDL2/sdl2-config.cmake`
   - `usr/lib/gcc/aarch64-linux-gnu/13/crtbegin.o`
   - `lib/ld-linux-aarch64.so.1`
6. **Reproducibility.** Pin the exact `.deb` filenames (or SHA256s) in an array
   at the top of the script, and check them after download. Print the pinned
   versions when the script runs.

### Task 2: Update `.github/workflows/build-portmaster.yml`

- In the apt install step, **remove `libsdl2-dev`** (it's the host arch and
  misleading). Keep `gcc-aarch64-linux-gnu` / `g++-aarch64-linux-gnu` (these
  provide `aarch64-linux-gnu-ld`, needed by `-fuse-ld=bfd`) and add
  `binutils-aarch64-linux-gnu` explicitly.
- Add these steps **before** "Build and Package for PortMaster":
  ```yaml
  - name: Cache aarch64 sysroot
    id: sysroot-cache
    uses: actions/cache@v4
    with:
      path: aarch64-sysroot-focal
      key: aarch64-sysroot-focal-${{ hashFiles('scripts/setup-aarch64-sysroot.sh', 'portmaster/dkrr/lib/**') }}

  - name: Build aarch64 sysroot
    if: steps.sysroot-cache.outputs.cache-hit != 'true'
    run: bash scripts/setup-aarch64-sysroot.sh
  ```
- Add a step after the build that checks the binary (see Acceptance criteria)
  so regressions in glibc version or architecture fail CI.

### Task 3: Make the toolchain fail clearly

File: `runtime-recomp/cmake/aarch64-linux-gnu.toolchain.cmake`

- Allow an override: if env var `DKR_AARCH64_SYSROOT` is set, use it for
  `_AARCH64_SYSROOT`.
- In the `else()` branch (sysroot not found), if `CMAKE_SYSROOT` is also not
  set, emit:
  ```cmake
  message(FATAL_ERROR
      "AArch64 sysroot not found at ${_AARCH64_SYSROOT}. "
      "Run scripts/setup-aarch64-sysroot.sh, or pass -DCMAKE_SYSROOT=<path> "
      "(PORTMASTER_SYSROOT env var in build-r36xx.sh).")
  ```
  This replaces the misleading SDL2 error with the real cause. Keep the
  existing behavior when `CMAKE_SYSROOT` is supplied externally.

### Task 4: Update `scripts/build-r36xx.sh`

- When cross-compiling (`uname -m` != `aarch64`), `PORTMASTER_SYSROOT` is
  unset, and `$ROOT_DIR/aarch64-sysroot-focal/usr/include` doesn't exist, run
  `"$ROOT_DIR/scripts/setup-aarch64-sysroot.sh"` automatically (print a notice
  first).

### Task 5 (optional hardening): SDL2 lookup in `runtime-recomp/CMakeLists.txt`

In the `if(DKR_RUNTIME_BUILD_GLES)` block (~line 750), replace
`find_package(SDL2 REQUIRED)` with:

```cmake
find_package(SDL2 CONFIG QUIET)
if(NOT SDL2_FOUND AND NOT SDL2_LIBRARIES)
    find_path(SDL2_INCLUDE_DIRS SDL.h PATH_SUFFIXES SDL2)
    find_library(SDL2_LIBRARIES NAMES SDL2 SDL2-2.0)
    if(NOT SDL2_INCLUDE_DIRS OR NOT SDL2_LIBRARIES)
        message(FATAL_ERROR "SDL2 not found for the GLES build (check the aarch64 sysroot).")
    endif()
endif()
```

Do not touch the RT64 / Windows / other SDL2 code paths.

### Task 6: Documentation

Add a short "Cross-compiling for PortMaster (R36XX)" section to
`docs/BUILDING.md` explaining `scripts/setup-aarch64-sysroot.sh`, the
`DKR_AARCH64_SYSROOT` / `PORTMASTER_SYSROOT` overrides, and why the sysroot is
focal-based (glibc 2.31).

## Acceptance criteria

Run on a clean `ubuntu-24.04` environment (or in CI):

1. `NO_ROM=1 ./scripts/build-r36xx.sh --clean --no-rom` succeeds and produces
   `dist/DiddyKongRacing-R36XX-PortMaster.zip`.
2. `file <packaged binary>` reports `ELF 64-bit LSB ... ARM aarch64`.
3. `aarch64-linux-gnu-objdump -T <binary> | grep -o 'GLIBC_2\.[0-9]*' | sort -uV | tail -1`
   prints **GLIBC_2.31 or lower**.
4. `aarch64-linux-gnu-readelf -d <binary>` lists `libSDL2-2.0.so.0` and
   `libGLESv2.so.2`, and does **not** list `libstdc++.so.6` (statically linked).
5. The existing "Verify package structure and ensure ROM is not included" step
   passes unchanged.
6. A second CI run on the same commit hits the sysroot cache and skips the
   setup step.
7. With the sysroot directory deleted and the setup script not run, CMake
   fails with the new clear `FATAL_ERROR` message from Task 3 (not the SDL2
   error).

## Constraints

- Don't commit the sysroot or any `.deb` files; keep `/aarch64-sysroot*/`
  gitignored and add the `.deb` cache dir to `.gitignore` if it lives outside `build/`.
- Don't change the compiler flags, `-mcpu=cortex-a35`, or static
  libstdc++/libgcc linking in the toolchain file.
- Don't switch CI to a native arm64 runner with a modern distro. Its glibc
  (2.39) would produce binaries that won't run on ArkOS / AmberELEC.
- Never include ROM files in any artifact.
