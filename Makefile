# Define variables
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
LDFLAGS = 
SOURCES = src/main.cpp src/menu.cpp src/explain.cpp src/plane.cpp src/seat.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = plane_reservation

# Default target
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up build files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
