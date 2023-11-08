CC = gcc
CFLAGS = -std=c99 -Wall -Werror

all: main

main: main.o tree.o
	$(CC) $(CFLAGS) -o main main.o tree.o
main.o: main.c tree.h
	$(CC) $(CFLAGS) -c main.c
tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c
clean:
	rm -f main *.o
