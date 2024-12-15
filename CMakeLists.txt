# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(SlideMakerProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the build type to Debug for GDB support
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Add include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/CLI
    ${PROJECT_SOURCE_DIR}/CLI/CommandFactory
    ${PROJECT_SOURCE_DIR}/CLI/Commands
    ${PROJECT_SOURCE_DIR}/CLI/Controller
    ${PROJECT_SOURCE_DIR}/CLI/Exception
    ${PROJECT_SOURCE_DIR}/CLI/Parser
    ${PROJECT_SOURCE_DIR}/Document
    ${PROJECT_SOURCE_DIR}/Document/Attributes
    ${PROJECT_SOURCE_DIR}/Document/Doc_Exceptions
    ${PROJECT_SOURCE_DIR}/Document/Items
    ${PROJECT_SOURCE_DIR}/Document/Slide
    ${PROJECT_SOURCE_DIR}/Document/Storage
    ${PROJECT_SOURCE_DIR}/Edition/Exceptions
    ${PROJECT_SOURCE_DIR}/Edition/Factories
    ${PROJECT_SOURCE_DIR}/Edition/Managers
    ${PROJECT_SOURCE_DIR}/Edition/Actions
)

# Collect all source files for CLI
file(GLOB_RECURSE CLI_SOURCES
    "${PROJECT_SOURCE_DIR}/CLI/CommandFactory/*.cpp"
    "${PROJECT_SOURCE_DIR}/CLI/Commands/*.cpp"
    "${PROJECT_SOURCE_DIR}/CLI/Controller/*.cpp"
    "${PROJECT_SOURCE_DIR}/CLI/Exception/*.cpp"
    "${PROJECT_SOURCE_DIR}/CLI/Parser/*.cpp"
)

 #Collect all source files for Document
 file(GLOB_RECURSE DOCUMENT_SOURCES
     "${PROJECT_SOURCE_DIR}/Document/Attributes/*.cpp"
     "${PROJECT_SOURCE_DIR}/Document/Doc_Exceptions/*.cpp"
     "${PROJECT_SOURCE_DIR}/Document/Items/*.cpp"
     "${PROJECT_SOURCE_DIR}/Document/Slide/*.cpp"
     "${PROJECT_SOURCE_DIR}/Document/Storage/*.cpp"
 )

# Collect all source files for Edition
file(GLOB_RECURSE EDITION_SOURCES
    "${PROJECT_SOURCE_DIR}/Edition/*.cpp"
)

# Combine all source files into one variable
set(ALL_SOURCES
    ${CLI_SOURCES}
    ${DOCUMENT_SOURCES}
    ${EDITION_SOURCES}
)

# Create the executable from the main file in CLI/Controller
add_executable(SlideMakerProject
    ${ALL_SOURCES}
)

# Set debug flags for the compiler to enable GDB support
target_compile_options(SlideMakerProject PRIVATE
    $<$<CONFIG:Debug>:-g>
)
