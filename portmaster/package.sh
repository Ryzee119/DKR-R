#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
DIST_DIR="$ROOT_DIR/dist/portmaster"
ZIP_NAME="DiddyKongRacing-R36XX-PortMaster.zip"

echo "=== Packaging DKR-R for PortMaster (R36XX / RK3326) ==="

rm -rf "$DIST_DIR"
mkdir -p "$DIST_DIR/dkrr/gamedata"
mkdir -p "$DIST_DIR/dkrr/gptokeyb"
mkdir -p "$DIST_DIR/dkrr/lib"

# Copy PortMaster launcher and configs
cp "$SCRIPT_DIR/Diddy Kong Racing.sh" "$DIST_DIR/"
chmod +x "$DIST_DIR/Diddy Kong Racing.sh"

cp "$SCRIPT_DIR/dkrr/gptokeyb/dkrr.gptk" "$DIST_DIR/dkrr/gptokeyb/"
cp "$SCRIPT_DIR/dkrr/gamecontrollerdb.txt" "$DIST_DIR/dkrr/"
cp "$SCRIPT_DIR/dkrr/README.md" "$DIST_DIR/dkrr/"
[ -f "$SCRIPT_DIR/dkrr/icon.png" ] && cp "$SCRIPT_DIR/dkrr/icon.png" "$DIST_DIR/dkrr/"
[ -f "$SCRIPT_DIR/dkrr/cover.png" ] && cp "$SCRIPT_DIR/dkrr/cover.png" "$DIST_DIR/dkrr/"
[ -f "$SCRIPT_DIR/dkrr/screenshot.png" ] && cp "$SCRIPT_DIR/dkrr/screenshot.png" "$DIST_DIR/dkrr/"
[ -f "$SCRIPT_DIR/port.json" ] && cp "$SCRIPT_DIR/port.json" "$DIST_DIR/"

# Copy bundled support libraries (like SDL 2.30.2)
if [ -d "$SCRIPT_DIR/dkrr/lib" ]; then
    echo "Copying bundled libraries from $SCRIPT_DIR/dkrr/lib..."
    cp -a "$SCRIPT_DIR/dkrr/lib/"* "$DIST_DIR/dkrr/lib/" 2>/dev/null || true
fi

# Copy assets if present in build directory
if [ -d "$ROOT_DIR/build/arm64-gles/bin/Release/assets" ]; then
    echo "Copying assets to distribution..."
    cp -r "$ROOT_DIR/build/arm64-gles/bin/Release/assets" "$DIST_DIR/dkrr/"
fi

# Auto-stage local ROM into gamedata if present in repository root (unless --no-rom / NO_ROM=1)
if [ "$1" != "--no-rom" ] && [ "$NO_ROM" != "1" ]; then
    for rom_candidate in \
        "$ROOT_DIR/Diddy Kong Racing (USA) (En,Fr).z64" \
        "$ROOT_DIR/dkr.z64" \
        "$ROOT_DIR/dkr.v64" \
        "$ROOT_DIR/dkr.n64"; do
        if [ -f "$rom_candidate" ]; then
            echo "Found local ROM: $(basename "$rom_candidate") -> staging to gamedata/dkr.z64"
            mkdir -p "$DIST_DIR/dkrr/gamedata"
            cp "$rom_candidate" "$DIST_DIR/dkrr/gamedata/dkr.z64"
            break
        fi
    done
fi

# Look for compiled executable
FOUND_BIN=""
for candidate in \
    "$ROOT_DIR/build/arm64-gles/bin/Release/DKR-R" \
    "$ROOT_DIR/build/arm64-gles/bin/DKR-R" \
    "$ROOT_DIR/build/arm64-gles/bin/dkr-r" \
    "$ROOT_DIR/build/arm64-gles/DKRGLESInteractiveDemo" \
    "$ROOT_DIR/build/gles-game/bin/Release/DKR-R" \
    "$ROOT_DIR/build/gles-game/bin/DKR-R" \
    "$ROOT_DIR/build/gles-game/bin/dkr-r" \
    "$ROOT_DIR/build/gles-test/bin/DKR-R" \
    "$ROOT_DIR/build/gles-test/bin/dkr-r" \
    "$ROOT_DIR/build/gles-test/DKRGLESInteractiveDemo"; do
    if [ -f "$candidate" ]; then
        FOUND_BIN="$candidate"
        break
    fi
done

if [ -n "$FOUND_BIN" ]; then
    echo "Found executable: $FOUND_BIN"
    cp "$FOUND_BIN" "$DIST_DIR/dkrr/dkr-r"
    cp "$FOUND_BIN" "$DIST_DIR/dkrr/DKR-R"
    chmod +x "$DIST_DIR/dkrr/dkr-r" "$DIST_DIR/dkrr/DKR-R"
else
    echo "Notice: No dkr-r binary copied. Compile with toolchain before final distribution."
fi

# Create zip archive
mkdir -p "$ROOT_DIR/dist"
cd "$DIST_DIR"
if command -v zip >/dev/null 2>&1; then
    zip -r "$ROOT_DIR/dist/$ZIP_NAME" ./*
else
    python3 -c "import zipfile, os, sys; z = zipfile.ZipFile('$ROOT_DIR/dist/$ZIP_NAME', 'w', zipfile.ZIP_DEFLATED); [z.write(os.path.join(root, file), os.path.relpath(os.path.join(root, file), '.')) for root, dirs, files in os.walk('.') for file in files]; z.close()"
fi

echo "=== Package created at: $ROOT_DIR/dist/$ZIP_NAME ==="
