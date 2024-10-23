cmake_minimum_required(VERSION 3.10)
# Project name
project(power)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories (recursive for headers)
include_directories()

# Glob all source files recursively
file(GLOB_RECURSE SOURCES 
    "${CMAKE_SOURCE_DIR}/document/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

# Glob all header files recursively (if needed)
file(GLOB_RECURSE HEADERS
    "${CMAKE_SOURCE_DIR}/Include/*.h"
    )

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})