CXX = g++
CXXFLAGS = -Wall -std=c++17 -g -I ~/lc/programmercarl/lib

SRC_DIR = src
BIN_DIR = bin
LIB_DIR = ~/lc/programmercarl/lib
TEST_DIR = test


SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(LIB_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/*.cpp, $(BIN_DIR)/*.o, $(SRCS))

EXEC_NAME = $(notdir $(CURDIR))
EXEC = $(BIN_DIR)/$(EXEC_NAME)

all: $(EXEC)

$(EXEC) : $(OBJS)
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

test: $(EXEC)
	@echo "Running tests..."
	@$(EXEC) < $(TEST_DIR)/input

clean:
	@rm -rf $(BIN_DIR)

.PHONY: all test clean