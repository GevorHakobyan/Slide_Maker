# Add necessary Qt modules
QT += core gui widgets

# Specifies the type of project (app = application)
TEMPLATE = app

# The output binary name
TARGET = SlideMaker

# Use the C++20 standard
CONFIG += c++20

# Build both Debug and Release versions
CONFIG += debug_and_release

# Ensure the correct C++ standard flags are added
QMAKE_CXXFLAGS += -std=c++20
QMAKE_CXXFLAGS_RELEASE += -O2
QMAKE_CXXFLAGS_DEBUG += -g -O0

# Include paths
INCLUDEPATH += \
    $$PWD/CLI \
    $$PWD/CLI/CommandFactory \
    $$PWD/CLI/Commands \
    $$PWD/CLI/Commands/Validators \
    $$PWD/CLI/Controller \
    $$PWD/CLI/Exception \
    $$PWD/CLI/Parser \
    $$PWD/Document \
    $$PWD/Document/Attributes \
    $$PWD/Document/Doc_Exceptions \
    $$PWD/Document/Items \
    $$PWD/Document/Slide \
    $$PWD/Document/Storage \
    $$PWD/Edition \
    $$PWD/Edition/Exceptions \
    $$PWD/Edition/Factories \
    $$PWD/Edition/Managers \
    $$PWD/Edition/Actions

# Source files for CLI
SOURCES += \
    $$files($$PWD/CLI/CommandFactory/*.cpp) \
    $$files($$PWD/CLI/Commands/*.cpp) \
    $$files($$PWD/CLI/Commands/Validators/*.cpp) \
    $$files($$PWD/CLI/Controller/*.cpp) \
    $$files($$PWD/CLI/Exception/*.cpp) \
    $$files($$PWD/CLI/Parser/*.cpp)

# Source files for Document
SOURCES += \
    $$files($$PWD/Document/Attributes/*.cpp) \
    $$files($$PWD/Document/Doc_Exceptions/*.cpp) \
    $$files($$PWD/Document/Items/*.cpp) \
    $$files($$PWD/Document/Slide/*.cpp) \
    $$files($$PWD/Document/Storage/*.cpp)

# Source files for Edition
SOURCES += \
    $$files($$PWD/Edition/Exceptions/*.cpp) \
    $$files($$PWD/Edition/Factories/*.cpp) \
    $$files($$PWD/Edition/Managers/*.cpp) \
    $$files($$PWD/Edition/Actions/*.cpp)

# Debug settings for GDB support
QMAKE_CXXFLAGS_DEBUG += -g
