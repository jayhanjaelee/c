CC = clang
CFLAGS = -Wall
INCLUDE = `pkg-config --cflags sdl3`
LIBS = `pkg-config --cflags --libs sdl3`

TARGET = main

SRCS = main.c

all:
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -o bin/$(TARGET) $(SRCS)

