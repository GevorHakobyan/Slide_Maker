cmake_minimum_required(VERSION 3.10)
# Project name
project(power)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories (recursive for headers)
include_directories(document)

# Glob all source files recursively
file(GLOB_RECURSE SOURCES 
    "${CMAKE_SOURCE_DIR}/document/main.cpp"
    "${CMAKE_SOURCE_DIR}/document/Exception.cpp"
    "${CMAKE_SOURCE_DIR}/document/Slide.cpp"
    "${CMAKE_SOURCE_DIR}/document/InvalidIndex_Cerr.cpp"
    "${CMAKE_SOURCE_DIR}/document/InvalidAttribute_Cerr.cpp"
    "${CMAKE_SOURCE_DIR}/document/TextBox.cpp"
    "${CMAKE_SOURCE_DIR}/document/TextBox_Attr.cpp"
    "${CMAKE_SOURCE_DIR}/document/I_Attribute_Cerr.cpp"
    "${CMAKE_SOURCE_DIR}/document/I_Attributes.cpp"
    "${CMAKE_SOURCE_DIR}/document/Item.cpp"
)

# Glob all header files recursively (if needed)
file(GLOB_RECURSE HEADERS
    "${CMAKE_SOURCE_DIR}/document/Slide.h"
    "${CMAKE_SOURCE_DIR}/document/Exception.h"
    "${CMAKE_SOURCE_DIR}/document/InvalidIndex_Cerr.h"
    "${CMAKE_SOURCE_DIR}/document/InvalidAttribute_Cerr.h"
    "${CMAKE_SOURCE_DIR}/document/I_Attribute_Cerr.h"
    "${CMAKE_SOURCE_DIR}/document/TextBox.h"
    "${CMAKE_SOURCE_DIR}/document/TextBox_Attr.h"
    "${CMAKE_SOURCE_DIR}/document/I_Attributes.h"
    "${CMAKE_SOURCE_DIR}/document/Item.h"
)
# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})