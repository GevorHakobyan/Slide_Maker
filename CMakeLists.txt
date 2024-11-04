cmake_minimum_required(VERSION 3.10)

# Project name
project(power)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Enable export of compile commands (for IDE integration)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the build type to Debug to include debugging symbols for gdb
set(CMAKE_BUILD_TYPE Debug)

# Include directories for headers
include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/../Include"
    "${CMAKE_SOURCE_DIR}/CLI"
    "${CMAKE_SOURCE_DIR}/CLI/CommandFactory"
    "${CMAKE_SOURCE_DIR}/CLI/Controller"
    "${CMAKE_SOURCE_DIR}/CLI/Exception"
    "${CMAKE_SOURCE_DIR}/Edition"
)

# Glob all source files recursively
file(GLOB_RECURSE SOURCES 
    "${CMAKE_SOURCE_DIR}/CLI/*.cpp"
    "${CMAKE_SOURCE_DIR}/Document/*.cpp"
    "${CMAKE_SOURCE_DIR}/Edition/*.cpp"
)

# Glob all header files recursively (if needed)
file(GLOB_RECURSE HEADERS
    "${CMAKE_SOURCE_DIR}/Include/*.h"
    "${CMAKE_SOURCE_DIR}/CLI/*.h"
    "${CMAKE_SOURCE_DIR}/Document/*.h"
    "${CMAKE_SOURCE_DIR}/Edition/*.h"
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})


