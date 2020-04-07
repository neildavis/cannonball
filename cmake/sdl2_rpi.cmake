# CMake setup used for SDL2 Builds on Raspberry Pi.

set(lib_base /usr/include)
set(sdl_root ${lib_base}/SDL2)

include_directories("${sdl_root}")

find_library(wiringPi_LIB wiringPi)

link_libraries(cannonball 
    SDL2
    ${wiringPi_LIB}
)

# Linking
link_directories(
    "${sdl_root}/lib"
)

add_definitions(-O3 -DSDL2 -DUSE_WIRING_PI -mcpu=cortex-a53 -mfpu=neon-fp-armv8 -mfloat-abi=hard)
 
# Location for Cannonball to create save files
# Used to auto-generate setup.hpp with various file paths
set(xml_directory ./)
set(sdl_flags "SDL_WINDOW_RESIZABLE")

# Set SDL2 instead of SDL1
set(SDL2 1)
