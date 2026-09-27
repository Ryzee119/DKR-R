#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
SYSROOT_DIR="${DKR_AARCH64_SYSROOT:-$ROOT_DIR/aarch64-sysroot-focal}"
CACHE_DIR="$ROOT_DIR/build/sysroot-debs"

echo "=========================================================="
echo " Setting up AArch64 Focal Sysroot (GLIBC <= 2.31, GCC 13)"
echo " Destination: $SYSROOT_DIR"
echo "=========================================================="

mkdir -p "$CACHE_DIR"
mkdir -p "$SYSROOT_DIR"

declare -A PKGS=(
    # Focal Base & Libs (http://ports.ubuntu.com/ubuntu-ports)
    ["libasound2"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/a/alsa-lib/libasound2_1.2.2-2.1ubuntu2.5_arm64.deb|3cf3900c1b9e5aa90c340099b15f04d8f93c078cd69acf1856ea65fea42b003e"
    ["libasound2-dev"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/a/alsa-lib/libasound2-dev_1.2.2-2.1ubuntu2.5_arm64.deb|df662c7a6f0d7f3fbaafa6ed629ebc35f5eef6c56af577589b2a53292cd80b43"
    ["libc6"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/g/glibc/libc6_2.31-0ubuntu9.18_arm64.deb|4ff60d84ad78f3aa598297dc6966549fa6489f57599f197562ad91547f388da0"
    ["libc6-dev"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/g/glibc/libc6-dev_2.31-0ubuntu9.18_arm64.deb|a690787a4ed5ad1bb9ce6aebe0bef3300e483e7ed97d11a6af3cdb107e642292"
    ["libdrm-dev"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libd/libdrm/libdrm-dev_2.4.107-8ubuntu1~20.04.2_arm64.deb|159a462f36ca4f0c1ab0cd9c54623a3c6a1c5ffcee0d3c27b86b65860c6355c4"
    ["libdrm2"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libd/libdrm/libdrm2_2.4.107-8ubuntu1~20.04.2_arm64.deb|b7039d3dc8af3248a3b01366d47e6bfd080f1a76ad3b6c63fa0bb4f8bae257a0"
    ["libegl-dev"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libg/libglvnd/libegl-dev_1.3.2-1~ubuntu0.20.04.2_arm64.deb|f1f0089fd28726783313311b60eb65e34d8862171d61dcd31a59a19d6a681cd8"
    ["libegl1"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libg/libglvnd/libegl1_1.3.2-1~ubuntu0.20.04.2_arm64.deb|29b1151a71c9d80aff8ebbbd294b3d5176e434d1d2ddded54da70008469cb09e"
    ["libgl-dev"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libg/libglvnd/libgl-dev_1.3.2-1~ubuntu0.20.04.2_arm64.deb|182c0a0fbe6c9d7a4488655b40d6e9e93461dd37be3ed6f0b609ef6a2db0da1c"
    ["libgl1"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libg/libglvnd/libgl1_1.3.2-1~ubuntu0.20.04.2_arm64.deb|12ea5f30ccd534c9890c3345a891eab6fca5751b593d559593e89e4615090db5"
    ["libgles-dev"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libg/libglvnd/libgles-dev_1.3.2-1~ubuntu0.20.04.2_arm64.deb|3a3a92bc1a7cd3c19a1ff525b53a6f903fe01045254aec075ce33c63019dcef5"
    ["libgles2"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libg/libglvnd/libgles2_1.3.2-1~ubuntu0.20.04.2_arm64.deb|501d1fb0707f21a9881ec4ad1c71dfc9c857ba92f74ebc6f000dbf4e7a173bd5"
    ["libglvnd-dev"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libg/libglvnd/libglvnd-dev_1.3.2-1~ubuntu0.20.04.2_arm64.deb|e07260ac765ac894677bc33c12ad1015bf1a13f183f8db4cfb19ee8eec9738ee"
    ["libglvnd0"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libg/libglvnd/libglvnd0_1.3.2-1~ubuntu0.20.04.2_arm64.deb|727aeacea5219788cf3ba012dd10cced9e90a0ec34321849f84b7263fbbbe76f"
    ["libglx-dev"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libg/libglvnd/libglx-dev_1.3.2-1~ubuntu0.20.04.2_arm64.deb|928146bd992275886f04d8b9de5f73033e7b282c6bd3c63dc3cb784bb2104f11"
    ["libglx0"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/libg/libglvnd/libglx0_1.3.2-1~ubuntu0.20.04.2_arm64.deb|c53dc69e4a5dddd147b668b039deb08def013ab5a1c0cd1c675e2c2fd29e410f"
    ["linux-libc-dev"]="http://ports.ubuntu.com/ubuntu-ports/pool/main/l/linux/linux-libc-dev_5.4.0-216.236_arm64.deb|9f487e7f3a9fff7f42f67172e139fd23c11b30e9b70bf6ae5a2e90b099547990"

    # Toolchain PPA (https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu)
    ["gcc-13-base"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-13/gcc-13-base_13.1.0-8ubuntu1~20.04.2_arm64.deb|3e10d0c4d18ac67b5f3ad60d12086971f19dbbd63cafec39bbc834bf66d864fc"
    ["libgcc-13-dev"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-13/libgcc-13-dev_13.1.0-8ubuntu1~20.04.2_arm64.deb|6ec2733a5e36011f8686c6c92bc334329a45506712e058d7e7e7806227f8602e"
    ["libstdc++-13-dev"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-13/libstdc++-13-dev_13.1.0-8ubuntu1~20.04.2_arm64.deb|211ed34b21f4cfc8f125331975b4bded39e4aea6bb718f5ec644ba59e9b85e55"
    ["libstdc++6"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-16/libstdc++6_16-20260315-1ubuntu1~20~ppa1_arm64.deb|7d6a034b7fabdbf00c54a01e59a5eaeadb38a87c14f2d1d1156d7dcf0fb3a043"
    ["libgcc-s1"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-16/libgcc-s1_16-20260315-1ubuntu1~20~ppa1_arm64.deb|afe1d7ccc4c12c3b1b82e6ed811b0cb64ba20eaf86911c7f606c31cde86c3fc5"
    ["libatomic1"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-16/libatomic1_16-20260315-1ubuntu1~20~ppa1_arm64.deb|83a6cc0c78e03402d9070f15b4268c6e0659a3ac67e322ad4a8d604e6ad82d6b"
    ["libasan8"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-16/libasan8_16-20260315-1ubuntu1~20~ppa1_arm64.deb|8c714961e41d967f477e8a08ba3ab3e174329c0cdd288fc9b44ec8864b31fc87"
    ["libubsan1"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-16/libubsan1_16-20260315-1ubuntu1~20~ppa1_arm64.deb|17ba371215e641b960710cd09cb6ac2ce491de4d499b72f65e47b287a165921e"
    ["liblsan0"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-16/liblsan0_16-20260315-1ubuntu1~20~ppa1_arm64.deb|fc51e2f16589928a957a8041dbda89efee5939477b0d47ca8c685f92bbbae322"
    ["libtsan2"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-16/libtsan2_16-20260315-1ubuntu1~20~ppa1_arm64.deb|15b21d7dc7c66d2d25cd116a5d10229761c712c63ff71e2ed493b21cbd4b2995"
    ["libhwasan0"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-16/libhwasan0_16-20260315-1ubuntu1~20~ppa1_arm64.deb|a5c4f45f6a0cb2db39ea207a0c0d4fd6ca75af4e819ee78b1a66db13026f720b"
    ["libitm1"]="https://ppa.launchpadcontent.net/ubuntu-toolchain-r/test/ubuntu/pool/main/g/gcc-16/libitm1_16-20260315-1ubuntu1~20~ppa1_arm64.deb|a94b8f4c9c1b0c797f80eaa5e8d6145b12597a01875efc823b222104609083c6"
)

download_and_verify() {
    local url="$1"
    local expected_sha="$2"
    local dest="$3"

    if [ -f "$dest" ]; then
        local actual_sha
        actual_sha=$(sha256sum "$dest" | cut -d' ' -f1)
        if [ "$actual_sha" = "$expected_sha" ]; then
            return 0
        fi
        rm -f "$dest"
    fi

    echo "Downloading $url -> $dest"
    curl -fsSL --retry 3 --connect-timeout 15 "$url" -o "$dest"
    local actual_sha
    actual_sha=$(sha256sum "$dest" | cut -d' ' -f1)
    if [ "$actual_sha" != "$expected_sha" ]; then
        echo "ERROR: SHA256 mismatch for $dest!"
        echo "Expected: $expected_sha"
        echo "Actual:   $actual_sha"
        exit 1
    fi
}

echo "1. Downloading and extracting pinned deb packages..."
for pkg in "${!PKGS[@]}"; do
    val="${PKGS[$pkg]}"
    url="${val%%|*}"
    sha="${val##*|}"
    filename="$(basename "$url")"
    deb_path="$CACHE_DIR/$filename"

    download_and_verify "$url" "$sha" "$deb_path"
    dpkg-deb -x "$deb_path" "$SYSROOT_DIR"
done

echo "2. Installing SDL2 2.30.2 headers and runtime library..."
SDL2_TARBALL="$CACHE_DIR/SDL2-2.30.2.tar.gz"
SDL2_URL="https://github.com/libsdl-org/SDL/releases/download/release-2.30.2/SDL2-2.30.2.tar.gz"
SDL2_SHA="891d66ac8cae51361d3229e3336ebec1c407a8a2a063b61df14f5fdf3ab5ac31"

download_and_verify "$SDL2_URL" "$SDL2_SHA" "$SDL2_TARBALL"

mkdir -p "$CACHE_DIR/sdl2_src"
tar -xzf "$SDL2_TARBALL" -C "$CACHE_DIR/sdl2_src" --strip-components=1

mkdir -p "$SYSROOT_DIR/usr/include/SDL2"
cp -r "$CACHE_DIR/sdl2_src/include/"*.h "$SYSROOT_DIR/usr/include/SDL2/"

# Copy bundled PortMaster SDL2 ARM64 library
mkdir -p "$SYSROOT_DIR/usr/lib/aarch64-linux-gnu"
cp "$ROOT_DIR/portmaster/dkrr/lib/libSDL2-2.0.so.0.3000.2" "$SYSROOT_DIR/usr/lib/aarch64-linux-gnu/"
(
    cd "$SYSROOT_DIR/usr/lib/aarch64-linux-gnu"
    ln -sfn libSDL2-2.0.so.0.3000.2 libSDL2-2.0.so.0
    ln -sfn libSDL2-2.0.so.0 libSDL2-2.0.so
    ln -sfn libSDL2-2.0.so libSDL2.so
)

# Write cmake config for SDL2
mkdir -p "$SYSROOT_DIR/usr/lib/aarch64-linux-gnu/cmake/SDL2"
cat << 'EOF' > "$SYSROOT_DIR/usr/lib/aarch64-linux-gnu/cmake/SDL2/sdl2-config.cmake"
set(prefix "/usr")
set(exec_prefix "${prefix}")
set(libdir "${prefix}/lib/aarch64-linux-gnu")
set(SDL2_PREFIX "/usr")
set(SDL2_EXEC_PREFIX "/usr")
set(SDL2_INCLUDE_DIRS "${prefix}/include/SDL2")
set(SDL2_LIBRARIES "-lSDL2")
EOF

echo "3. Converting absolute symlinks to relative in sysroot..."
find "$SYSROOT_DIR" -type l -lname '/*' | while IFS= read -r link; do
    target="$(readlink "$link")"
    rel_target="$(realpath -m --relative-to="$(dirname "$link")" "$SYSROOT_DIR$target")"
    ln -sfn "$rel_target" "$link"
done

echo "4. Running sanity checks on generated sysroot..."
CHECK_FILES=(
    "usr/include/stdio.h"
    "usr/include/SDL2/SDL.h"
    "usr/include/GLES2/gl2.h"
    "usr/include/EGL/egl.h"
    "usr/include/c++/13/vector"
    "usr/lib/aarch64-linux-gnu/crt1.o"
    "usr/lib/aarch64-linux-gnu/crti.o"
    "usr/lib/aarch64-linux-gnu/libc.so"
    "usr/lib/aarch64-linux-gnu/libSDL2.so"
    "usr/lib/aarch64-linux-gnu/libGLESv2.so"
    "usr/lib/aarch64-linux-gnu/libEGL.so"
    "usr/lib/aarch64-linux-gnu/cmake/SDL2/sdl2-config.cmake"
    "usr/lib/gcc/aarch64-linux-gnu/13/crtbegin.o"
    "lib/ld-linux-aarch64.so.1"
)

for file in "${CHECK_FILES[@]}"; do
    if [ ! -e "$SYSROOT_DIR/$file" ]; then
        echo "ERROR: Missing required sysroot file: $SYSROOT_DIR/$file"
        exit 1
    fi
done

echo "=========================================================="
echo " Sysroot setup complete and validated successfully!"
echo " Location: $SYSROOT_DIR"
echo "=========================================================="
