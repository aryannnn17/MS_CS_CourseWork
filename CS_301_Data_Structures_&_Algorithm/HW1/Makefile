# Makefile for compiling and running C++ projects

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = program
SRC = homework1.cpp

# Default rule to compile and run the program
all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean all
