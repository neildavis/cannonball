# -----------------------------------------------------------------------------
# CannonBall Linux Setup
# -----------------------------------------------------------------------------

# Use OpenGL for rendering.
find_package(OpenGL REQUIRED)

# Include functions provided by PkgConfig module.
find_package(PkgConfig) 

find_library(wiringPi_LIB wiringPi)

# Use DBus
pkg_check_modules(DBUS dbus-1) 

# Platform Specific Includes
set(platform_include_dirs
    ${DBUS_INCLUDE_DIRS}
)

# Platform Specific Libraries
set(platform_link_libs
    ${OPENGL_LIBRARIES}
    ${DBUS_LIBRARIES}
    ${wiringPi_LIB}
)

add_definitions(-DUSE_WIRING_PI -mcpu=cortex-a53 -mfpu=neon-fp-armv8 -mfloat-abi=hard)
