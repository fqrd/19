CC=gcc
CFLAGS= -Werror -Wextra -Wall

output: main.o
	gcc main.o -o output

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm output *.o