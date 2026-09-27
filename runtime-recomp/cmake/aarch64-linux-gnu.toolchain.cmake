# AArch64 Linux cross-compilation toolchain targeting Cortex-A35 / RK3326 (R36XX / R36S)
# Uses Ubuntu 20.04 (Focal) ARM64 sysroot to ensure GLIBC <= 2.31 compatibility with ArkOS/AmberELEC.
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER_TARGET aarch64-linux-gnu)
set(CMAKE_CXX_COMPILER_TARGET aarch64-linux-gnu)

if(DEFINED ENV{DKR_AARCH64_SYSROOT})
    set(_AARCH64_SYSROOT "$ENV{DKR_AARCH64_SYSROOT}")
else()
    get_filename_component(_AARCH64_SYSROOT "${CMAKE_CURRENT_LIST_DIR}/../../aarch64-sysroot-focal" ABSOLUTE)
endif()

if(EXISTS "${_AARCH64_SYSROOT}/usr/include")
    set(CMAKE_SYSROOT "${_AARCH64_SYSROOT}")
    list(APPEND CMAKE_PREFIX_PATH
        "${_AARCH64_SYSROOT}/usr"
        "${_AARCH64_SYSROOT}/usr/lib/aarch64-linux-gnu"
    )

    include_directories(SYSTEM
        "${_AARCH64_SYSROOT}/usr/include"
        "${_AARCH64_SYSROOT}/usr/include/aarch64-linux-gnu"
        "${_AARCH64_SYSROOT}/usr/include/SDL2"
    )

    link_directories(
        "${_AARCH64_SYSROOT}/usr/lib/aarch64-linux-gnu"
        "${_AARCH64_SYSROOT}/lib/aarch64-linux-gnu"
        "${_AARCH64_SYSROOT}/usr/lib"
    )

    set(SDL2_DIR "${_AARCH64_SYSROOT}/usr/lib/aarch64-linux-gnu/cmake/SDL2")

    set(CMAKE_FIND_ROOT_PATH "${_AARCH64_SYSROOT}")
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

    set(CMAKE_C_FLAGS_INIT "--gcc-toolchain=${_AARCH64_SYSROOT}/usr")
    set(CMAKE_CXX_FLAGS_INIT "--gcc-toolchain=${_AARCH64_SYSROOT}/usr")
    set(CMAKE_EXE_LINKER_FLAGS_INIT "--gcc-toolchain=${_AARCH64_SYSROOT}/usr -static-libstdc++ -static-libgcc -fuse-ld=bfd -ldl -Wl,--allow-shlib-undefined")
    set(CMAKE_SHARED_LINKER_FLAGS_INIT "--gcc-toolchain=${_AARCH64_SYSROOT}/usr -static-libstdc++ -static-libgcc -fuse-ld=bfd -ldl -Wl,--allow-shlib-undefined")
    set(CMAKE_EXE_LINKER_FLAGS "--gcc-toolchain=${_AARCH64_SYSROOT}/usr -static-libstdc++ -static-libgcc -fuse-ld=bfd -ldl -Wl,--allow-shlib-undefined" CACHE STRING "Linker flags" FORCE)
    set(CMAKE_SHARED_LINKER_FLAGS "--gcc-toolchain=${_AARCH64_SYSROOT}/usr -static-libstdc++ -static-libgcc -fuse-ld=bfd -ldl -Wl,--allow-shlib-undefined" CACHE STRING "Linker flags" FORCE)
else()
    if(NOT CMAKE_SYSROOT)
        message(FATAL_ERROR
            "AArch64 sysroot not found at ${_AARCH64_SYSROOT}. "
            "Run scripts/setup-aarch64-sysroot.sh, or pass -DCMAKE_SYSROOT=<path> "
            "(PORTMASTER_SYSROOT env var in build-r36xx.sh).")
    endif()

    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

    set(CMAKE_EXE_LINKER_FLAGS_INIT "-static-libstdc++ -static-libgcc -fuse-ld=bfd -ldl -Wl,--allow-shlib-undefined")
    set(CMAKE_SHARED_LINKER_FLAGS_INIT "-static-libstdc++ -static-libgcc -fuse-ld=bfd -ldl -Wl,--allow-shlib-undefined")
    set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++ -static-libgcc -fuse-ld=bfd -ldl -Wl,--allow-shlib-undefined" CACHE STRING "Linker flags" FORCE)
    set(CMAKE_SHARED_LINKER_FLAGS "-static-libstdc++ -static-libgcc -fuse-ld=bfd -ldl -Wl,--allow-shlib-undefined" CACHE STRING "Linker flags" FORCE)
endif()

# Optimization flags tailored for quad Cortex-A35
set(CMAKE_C_FLAGS_RELEASE "-O3 -mcpu=cortex-a35 -fomit-frame-pointer" CACHE STRING "Release C flags" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -mcpu=cortex-a35 -fomit-frame-pointer" CACHE STRING "Release CXX flags" FORCE)

