# Executable names:
EXE = main
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o DFS.o Dijkstra.o Edge.o GraphStructure.o IDDFS.o Vertex.o

#OBJS += #more needed?

# Generated files
#CLEAN_RM = 

# Use the cs225 makefile template:
include cs225/make/cs225.mk