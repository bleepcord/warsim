#OBJS says which files to compile as part of the project
OBJS = sim.c unitBuilder.c members.c battle.c

#CC specifies which compiler to use
CC = gcc

#COMPILER_FLAGS for additional options
COMPILER_FLAGS = -w -std=c99

#LINKER_FLAGS specifies which libraries to use
LINKER_FLAGS =

#OBJ_NAME specifies the name of the executable after compilation
OBJ_NAME = warsim

#the target that compiles the executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

debug	:	$(OBJ)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -g $(LINKER_FLAGS) -o $(OBJ_NAME)
