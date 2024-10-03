# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Directories
SRC_DIR = CLI
CONTROLLER_DIR = $(SRC_DIR)/Controller
INCLUDE_DIRS = -I$(SRC_DIR)/CommandFactory -I$(CONTROLLER_DIR) \
               -I$(SRC_DIR)/Exception -I$(SRC_DIR)/Parser -I$(SRC_DIR)/Include

# Source file (main.cpp)
SRCS = $(CONTROLLER_DIR)/main.cpp

# Target executable
TARGET = cli_app

# Default rule to build the application
all: $(TARGET)

# Link source files to create the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -o $@ $^

# Clean up the executable
clean:
	rm -f $(TARGET)


