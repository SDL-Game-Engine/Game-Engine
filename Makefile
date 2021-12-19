# source files
OBJS = -C src/*.cpp

# gcc/g++
CC = g++

# must get the SDL2 include files in the include/ directory for windows,
# or install it in terminal using linux
INCLUDE_PATHS = -I include

# must get the SDL2 lib folder in the lib/ directory for windows
LIBRARY_PATHS = -L lib/SDL2

LINUX_LINKERS = -lSDL2 -lSDL2_image

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# -Wall to see all warnings
DEBUG_FLAGS = -Wall -g

# -O3 for optimization, -s to strip all unused components
RELEASE_FLAGS = -O3 -s

DEBUG_OBJ = bin/debug/main
RELEASE_OBJ = bin/release/main

debug:
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(DEBUG_FLAGS) -o $(DEBUG_OBJ) $(LINKER_FLAGS) && start $(DEBUG_OBJ)

release:
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS)  $(RELEASE_FLAGS) -o $(RELEASE_OBJ) $(LINKER_FLAGS) && start $(RELEASE_OBJ)

all:
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LINUX_LINKERS) $(RELEASE_FLAGS) -o $(RELEASE_OBJ) && ./$(RELEASE_OBJ)
