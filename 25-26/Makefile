CC = gcc
CFLAGS = -std=c99 -Wall -Werror

all: main

main: main.o queue.o
	$(CC) $(CFLAGS) -o main main.o queue.o
main.o: main.c queue.h
	$(CC) $(CFLAGS) -c main.c
queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c
clean:
	rm -f main *.o
