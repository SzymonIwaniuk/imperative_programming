# Kompilator i flagi 
CC = gcc
CFLAGS = -std=c2x -pedantic -Werror=pedantic -Wall -Wextra

# Pliki źródłowe i obiektowe
SRCS = main.c utils.c math_utils.c
OBJS = $(SRCS:.c=.o)

# Nazwa pliku wykonywalnego
TARGET = my_program

# Reguła domyślna
all: $(TARGET)

# Linkowanie
$(TARGET): $(OBJS)
$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Kompilacja plików .c do.o 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Czyszczenie plików tymczasowych 
clean:
	rm -f $(OBJS) $(TARGET)

