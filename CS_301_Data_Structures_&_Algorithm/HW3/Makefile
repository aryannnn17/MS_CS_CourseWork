# Makefile for compiling and running C++ projects

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = program
SRC = hw3.cpp

# Default rule to compile and run the program
all: $(TARGET)
	./$(TARGET) HW3DataFile.txt

$(TARGET): $(SRC) hw3.h
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean all
