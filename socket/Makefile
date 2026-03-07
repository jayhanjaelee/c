CC = cc
FLAGS = -Wall -g
TARGET = main

all: main

main: main.c
	$(CC) $(FLAGS) -o ./bin/$(TARGET) $^

tcp_server: tcp_server.c
	$(CC) $(FLAGS) -o ./bin/$(TARGET) $^

server: server.c
	$(CC) $(FLAGS) -o ./bin/$(TARGET) $^

.PHONY: clean

clean:
	rm -f ./bin/$(TARGET)
