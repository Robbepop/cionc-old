cmake_minimum_required (VERSION 2.6)

project (CionCompiler)

#-----------------------------------------------------------------------------------------
# Compiler Flags
#-----------------------------------------------------------------------------------------
set (CMAKE_CXX_FLAGS "-g -Wall -Wextra -pedantic -std=c++14 -fdiagnostics-color=auto")

#-----------------------------------------------------------------------------------------
# Version
#-----------------------------------------------------------------------------------------
set (Version_Major 1)
set (Version_Minor 0)
set (Version_Patch 0)
set (Version "$(Version_Major).$(Version_Minor).$(Version_Patch)")

#-----------------------------------------------------------------------------------------
# Environment
#-----------------------------------------------------------------------------------------

include_directories (
	$(PROJECT_SOURCE_DIR)include
	$(PROJECT_SOURCE_DIR)include/ast
	$(PROJECT_SOURCE_DIR)include/error
	$(PROJECT_SOURCE_DIR)include/lexer
	$(PROJECT_SOURCE_DIR)include/parser
	$(PROJECT_SOURCE_DIR)include/token
)

add_subdirectory (src)
