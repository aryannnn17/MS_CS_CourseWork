# Makefile for compiling and running C++ projects

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = program
SRC = hw4.cpp

# Default rule to compile and run the program
all: $(TARGET)
	./$(TARGET) Sequence.txt Letters.txt

$(TARGET): $(SRC) hw4.h
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean all
