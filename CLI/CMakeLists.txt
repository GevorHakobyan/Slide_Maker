cmake_minimum_required(VERSION 3.10)
# Project name
project(power)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories (recursive for headers)
include_directories(CommandFactory)
include_directories(Controller)
include_directories(Exception)
include_directories(Parser)

# Glob all source files recursively
file(GLOB_RECURSE SOURCES 
    "${CMAKE_SOURCE_DIR}/Controller/*.cpp"
    "${CMAKE_SOURCE_DIR}/CommandFactory/*.cpp"
    "${CMAKE_SOURCE_DIR}/Exception/*.cpp"
    "${CMAKE_SOURCE_DIR}/Parser/*.cpp"
)

# Glob all header files recursively (if needed)
file(GLOB_RECURSE HEADERS
    "${CMAKE_SOURCE_DIR}/Controller/*.h"
    "${CMAKE_SOURCE_DIR}/CommandFactory/*.h"
    "${CMAKE_SOURCE_DIR}/Exception/*.h"
    "${CMAKE_SOURCE_DIR}/Parser/*.h"
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})