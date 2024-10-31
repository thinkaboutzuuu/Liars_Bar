# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Output executable name
TARGET = game

# Source and object files
SRC = main.cpp Game.cpp Player.cpp
OBJ = main.o Game.o Player.o

# Default target to build the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Dependency rules
# main.cpp depends on Game.h and Player.h
main.o: main.cpp Game.h 
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Game.cpp depends on Game.h and Player.h
Game.o: Game.cpp Game.h Player.h
	$(CXX) $(CXXFLAGS) -c Game.cpp -o Game.o

# Player.cpp depends on Player.h
Player.o: Player.cpp Player.h
	$(CXX) $(CXXFLAGS) -c Player.cpp -o Player.o

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(TARGET)