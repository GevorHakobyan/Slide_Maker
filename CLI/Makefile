# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -g -Wall

# Source files
SRCS = main.cpp Parser.h Parser.inl

# Output executable
TARGET = parser_program

# Default rule to build the executable
all: $(TARGET)

# Linking the object files
$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o

# Rule to compile main.cpp
main.o: main.cpp Parser.h Parser.inl
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean up build artifacts
clean:
	rm -f $(TARGET) *.o
