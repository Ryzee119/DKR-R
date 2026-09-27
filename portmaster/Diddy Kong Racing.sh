#!/bin/bash
# Diddy Kong Racing (Recompiled) PortMaster Launch Script
# Target: R36S / R36XX / RK3326 Handheld Devices (ArkOS / AmberELEC / UnofficialOS)

XDG_DATA_HOME=${XDG_DATA_HOME:-$HOME/.local/share}

if [ -d "/opt/system/Tools/PortMaster/" ]; then
  controlfolder="/opt/system/Tools/PortMaster"
elif [ -d "/opt/tools/PortMaster/" ]; then
  controlfolder="/opt/tools/PortMaster"
else
  controlfolder="/roms/ports/PortMaster"
fi

if [ -f "$controlfolder/control.txt" ]; then
  source "$controlfolder/control.txt"
  [ -f "${controlfolder}/mod_${CFW_NAME}.txt" ] && source "${controlfolder}/mod_${CFW_NAME}.txt"
  get_controls
fi

GAMEDIR="/$directory/ports/dkrr"
[ ! -d "$GAMEDIR" ] && GAMEDIR="$(dirname "$0")/dkrr"
cd "$GAMEDIR"

> "$GAMEDIR/log.txt" && exec > >(tee "$GAMEDIR/log.txt") 2>&1

export LD_LIBRARY_PATH="$GAMEDIR/lib:$LD_LIBRARY_PATH"
export SDL_GAMECONTROLLERCONFIG_FILE="$GAMEDIR/gamecontrollerdb.txt"
if [ -z "$SDL_VIDEODRIVER" ]; then
  export SDL_VIDEODRIVER="kmsdrm,mali,x11"
fi

# Self-contained save data directory on the SD card
mkdir -p "$GAMEDIR/saves"
export XDG_DATA_HOME="$GAMEDIR/saves"
export XDG_CONFIG_HOME="$GAMEDIR/saves"

# GLES Renderer scaling and filtering configuration:
# DKR_RENDER_SCALE: 1 = native N64 320x240 (fastest, authentic 2x integer scale on R36XX), 2 = 640x480
# export DKR_RENDER_SCALE=1
# DKR_SCALE_MODE: fit (aspect ratio preserved, letterboxed), integer (integer scale), stretch (fullscreen)
# export DKR_SCALE_MODE=fit
# DKR_SCALE_FILTER: nearest (crisp pixels), linear (smooth)
# export DKR_SCALE_FILTER=nearest
# DKR_CULL_SIGN: 1 = normal backface culling, -1 = inverted
# export DKR_CULL_SIGN=1

# Force Performance CPU governor for stable framerate on RK3326
if [ -f /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor ]; then
  echo "performance" | $ESUDO tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor 2>/dev/null
fi

# Enable virtual memory overcommit so the 64-bit address space reservation succeeds on 1GB devices
if [ -f /proc/sys/vm/overcommit_memory ]; then
  echo 1 | $ESUDO tee /proc/sys/vm/overcommit_memory 2>/dev/null || true
fi

# Locate ROM
ROM_FILE=""
for candidate in \
  "$GAMEDIR/gamedata/dkr.z64" \
  "$GAMEDIR/gamedata/dkr.v64" \
  "$GAMEDIR/gamedata/dkr.n64" \
  "$GAMEDIR/dkr.z64" \
  "$GAMEDIR/gamedata/Diddy Kong Racing (USA) (En,Fr).z64" \
  "$GAMEDIR/Diddy Kong Racing (USA) (En,Fr).z64" \
  "$GAMEDIR/gamedata/"*.z64 \
  "$GAMEDIR/"*.z64; do
  if [ -f "$candidate" ]; then
    ROM_FILE="$candidate"
    break
  fi
done

if [ -z "$ROM_FILE" ]; then
  echo "ERROR: Diddy Kong Racing US ROM not found!"
  echo "Please place your legally dumped dkr.z64 into $GAMEDIR/gamedata/"
  if [ -n "$(type -t pm_message)" ]; then
    pm_message "ROM not found! Place dkr.z64 into ports/dkrr/gamedata/"
  fi
  sleep 5
  exit 1
fi

echo "Found ROM at: $ROM_FILE"

BIN_FILE="./dkr-r"
[ -f "./DKR-R" ] && BIN_FILE="./DKR-R"
[ -x "$GAMEDIR/DKR-R" ] && BIN_FILE="$GAMEDIR/DKR-R"
[ -x "$GAMEDIR/dkr-r" ] && BIN_FILE="$GAMEDIR/dkr-r"

# Start gptokeyb if available
if [ -n "$GPTOKEYB" ] && [ -f "$GAMEDIR/gptokeyb/dkrr.gptk" ]; then
  $GPTOKEYB "$(basename "$BIN_FILE")" -c "$GAMEDIR/gptokeyb/dkrr.gptk" &
fi

chmod +x "$BIN_FILE" 2>/dev/null

if [ -n "$(type -t pm_platform_helper)" ]; then
  pm_platform_helper "$BIN_FILE"
fi


# Launch Diddy Kong Racing Recompiled with OpenGL ES
"$BIN_FILE" --rom "$ROM_FILE" --config "$GAMEDIR/saves"
EXIT_CODE=$?
echo "[launcher] DKR-R exited with code $EXIT_CODE"

if [ -f "$GAMEDIR/saves/logs/runtime.log" ]; then
  echo "=== Content of saves/logs/runtime.log ==="
  cat "$GAMEDIR/saves/logs/runtime.log"
  echo "=========================================="
fi

# Cleanup on exit
if [ -n "$(type -t pm_finish)" ]; then
  pm_finish
else
  $ESUDO kill -9 $(pidof gptokeyb) 2>/dev/null || true
  wait $(pidof gptokeyb) 2>/dev/null || true
  printf "\033c" > /dev/tty1 2>/dev/null
fi
