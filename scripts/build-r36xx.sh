#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$ROOT_DIR/build/arm64-gles"

echo "=========================================================="
echo " Building Diddy Kong Racing (Recompiled) for R36XX / RK3326"
echo " Target: AArch64 Cortex-A35 / Mali-G31 MP2 / PortMaster"
echo "=========================================================="

# Check for aarch64 cross-compiler / clang
if ! command -v clang >/dev/null 2>&1 || ! command -v clang++ >/dev/null 2>&1; then
    echo "ERROR: clang or clang++ not found!"
    echo "Install via: sudo apt-get install clang"
    exit 1
fi

# Check for recompiled ROM sources
V77_DIR="${DKR_GENERATED_SOURCE_V77:-$ROOT_DIR/runtime-recomp/RecompiledFuncs}"
V80_DIR="${DKR_GENERATED_SOURCE_V80:-$ROOT_DIR/runtime-recomp/RecompiledFuncs-v80}"

BUILD_GENERATED="OFF"
TARGET_NAME="DKRGLESInteractiveDemo"

if [ -d "$V77_DIR" ] && [ -d "$V80_DIR" ]; then
    echo "[info] Found recompiled sources for v1.0 and v1.1. Enabling full game build."
    BUILD_GENERATED="ON"
    TARGET_NAME="DKRPortGame"
else
    echo "[notice] Recompiled ROM sources not detected ($V77_DIR / $V80_DIR)."
    echo "[notice] Building standalone F3DDKR GLES Handheld Demo binary."
fi

if [ "$1" = "--clean" ] || [ "$CLEAN" = "1" ]; then
    echo "Performing clean build: removing $BUILD_DIR and $ROOT_DIR/dist..."
    rm -rf "$BUILD_DIR" "$ROOT_DIR/dist"
fi

mkdir -p "$BUILD_DIR"

echo "Configuring CMake for OpenGL ES..."
CMAKE_ARGS=(
    -S "$ROOT_DIR/runtime-recomp"
    -B "$BUILD_DIR"
    -DCMAKE_BUILD_TYPE=Release
    -DDKR_RUNTIME_BUILD_RT64=OFF
    -DDKR_RUNTIME_BUILD_GLES=ON
    -DDKR_RUNTIME_BUILD_SDL3_INPUT_HOST=OFF
    -DDKR_NETPLAY_WEBRTC=OFF
    -DDKR_RUNTIME_BUILD_GENERATED="$BUILD_GENERATED"
)

if [ "$BUILD_GENERATED" = "ON" ]; then
    CMAKE_ARGS+=(
        -DDKR_GENERATED_SOURCE_V77="$V77_DIR"
        -DDKR_GENERATED_SOURCE_V80="$V80_DIR"
    )
fi

# Use cross-compiler toolchain if building on host for aarch64
if [ "$(uname -m)" != "aarch64" ]; then
    SYSROOT_DIR="${PORTMASTER_SYSROOT:-${DKR_AARCH64_SYSROOT:-$ROOT_DIR/aarch64-sysroot-focal}}"
    if [ ! -d "$SYSROOT_DIR/usr/include" ]; then
        echo "[notice] PortMaster AArch64 sysroot not detected at: $SYSROOT_DIR"
        echo "[notice] Automatically invoking scripts/setup-aarch64-sysroot.sh..."
        "$ROOT_DIR/scripts/setup-aarch64-sysroot.sh"
    fi

    CMAKE_ARGS+=(-DCMAKE_TOOLCHAIN_FILE="$ROOT_DIR/runtime-recomp/cmake/aarch64-linux-gnu.toolchain.cmake")
    if [ -n "$PORTMASTER_SYSROOT" ]; then
        CMAKE_ARGS+=(-DCMAKE_SYSROOT="$PORTMASTER_SYSROOT")
    fi
fi

cmake "${CMAKE_ARGS[@]}"

echo "Building target: $TARGET_NAME..."
cmake --build "$BUILD_DIR" --target "$TARGET_NAME" -j"$(nproc)"

echo "Packaging PortMaster distribution..."
"$ROOT_DIR/portmaster/package.sh" ${PACKAGE_ARGS:-"$@"}

echo "=========================================================="
echo " Build & Packaging Complete!"
echo " Output: $ROOT_DIR/dist/DiddyKongRacing-R36XX-PortMaster.zip"
echo "=========================================================="
