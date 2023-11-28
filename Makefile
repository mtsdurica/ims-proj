CXX			:= g++
CXXFLAGS	:= -std=c++20 -Werror -Wall -Wpedantic
TARGET		:= sim
BUILD		:= ./build
OBJ_DIR 	:= $(BUILD)/objects
SRC_FILES 	:=						\
	$(wildcard src/*.cpp)			\
	$(wildcard src/*.cpp)			\

OBJECTS 	:= $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all clean build

all: build ./$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

./$(TARGET): $(OBJECTS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^

build:
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(TARGET)
	rm -rf $(OBJ_DIR)
