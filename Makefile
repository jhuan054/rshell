CC = g++
CFLAGS = -g -Wall -Werror -ansi -pedantic

TARGETS = all rshell
all: rshell

rshell:
	@mkdir -p bin
	$(CC) $(CFLAGS) src/main.cpp  -o bin/rshell

