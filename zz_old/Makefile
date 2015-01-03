#######################################
# Generic Makefile
# for OpenCL Wrapper cppCL
#
# requires specific project
# folder structure:
# - src (source files)
# - include (header files)
# - build (object files)
# - bin (binary files)
#######################################

#######################################
# Compiler & Compiler Flags
#######################################
CC := g++
#CC := clang --analyze
CFLAGS := -g -Wall -Wextra -pedantic -std=c++14 -fdiagnostics-color=auto

#######################################
# Directories
#######################################
MODULES   := ast
DIR_SRC   := $(addprefix src/,$(MODULES))
DIR_BUILD := $(addprefix build/,$(MODULES))
DIR_BIN := bin
DIR_TEST := test

#######################################
# File Extensions
#######################################
EXT_SRC := cpp
EXT_HEADER := hpp
EXT_TEMPLATE := tcc

#######################################
# Targets
#######################################
TARGET_MAIN := $(DIR_BIN)/main

#######################################
# Includes & Libraries
#######################################
PATH_INC := -I$(DIR_INCLUDE)
PATH_LIB := -lboost_regex

#######################################
# Generic catching of all source
# files in src/ directory and all
# object files in build/ directory.
#######################################
#SRC_FILES := $(wildcard $(DIR_SRC)/*.$(EXT_SRC))
#OBJ_FILES := $(pathsubst $(DIR_SRC)/%.$(EXT_SRC), $(DIR_BUILD)/%.o, $(SRC_FILES))
#OBJ_FILES := $(addprefix $(DIR_BUILD)/, $(notdir $(SRC_FILES:.$(EXT_SRC)=.o)))

SRC_FILES     := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ_FILES     := $(patsubst src/%.cpp,build/%.o,$(SRC))
INCLUDES      := $(addprefix -I,$(SRC_DIR))

vpath %.cpp $(SRC_DIR)

#######################################
# linking of all object files
# for TARGET_MAIN.
#######################################
$(TARGET_MAIN): $(OBJ_FILES)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET_MAIN) $(PATH_LIB)"; $(CC) $^ -o $(TARGET_MAIN) $(PATH_LIB)

#######################################
# Compiling of all source files
# within the given src directory.
#######################################
$(DIR_BUILD)/%.o: $(DIR_SRC)/%.$(EXT_SRC)
	@mkdir -p $(DIR_BUILD) $(DIR_BIN)
	@echo " $(CC) $(CFLAGS) $(PATH_INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#######################################
# Clean
#######################################
clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(DIR_BUILD) $(TARGET_MAIN)"; $(RM) -r $(DIR_BUILD) $(DIR_BIN)

#######################################
# PHONY declarations
#######################################
.PHONY: clean
