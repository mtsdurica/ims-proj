CXX			:= g++
CXXFLAGS	:= -std=c++20 -Werror -Wall -Wpedantic -g -O2
TARGET		:= skicentrum-sim
BUILD		:= ./build
OBJ_DIR 	:= $(BUILD)/objects
SRC_FILES 	:=						\
	$(wildcard src/*.cpp)			\
	
OBJECTS 	:= $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all clean build run

all: build ./$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

./$(TARGET): $(OBJECTS)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lsimlib 

build:
	mkdir -p $(OBJ_DIR)

run: all
	@./$(TARGET)

clean:
	rm -rf $(TARGET)
	rm -rf $(OBJ_DIR)
