CC = gcc 
CFLAGS = -std=c2x -pedantic -Werror=pedantic -Wall -Wextra

version: main.o 
	$(CC) $(CFLAGS) -o version main.o

main.o: main.c 
	$(CC) $(CFLAGS) -c main.o main.c 

clean: 
	rm -f version main.o 
