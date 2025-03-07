# Kompilator i flagi 
CC = gcc
CFLAGS = -std=c2x -pedantic -Werror=pedantic -Wall -Wextra

# Katalogi 
SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib
TEST_DIR = tests

# Pliki źródłowe i obiektowe
SRCS = $(wildcard $(SRC_DIR)/*.c)  # Wszystkie pliki .c w src/
OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(SRC_DIR)/utils.o
LIBRARY = $(LIB_DIR)/libutils.a
TARGET = $(BIN_DIR)/my_program
TEST_TARGET = $(BIN_DIR)/test_runner  

# Reguła domyślna
all: $(TARGET)

# Kopiowanie plików .c do bin/

# Kompilacja biblioteki statycznej
$(LIBRARY): $(LIB_OBJS)
	ar rcs $(LIBRARY) $(OBJS)

# Kompilacja głównego programu
$(TARGET): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -L$(LIB_DIR) -lutils

# Regula kompilacji testow
$(TEST_TARGET) : $(TEST_DIR)/tests.c $(SRC_DIR)/math_utils.c $(SRC_DIR)/is_greater.c $(SRC_DIR)/is_devide.c
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_DIR)/tests.c $(SRC_DIR)/math_utils.c $(SRC_DIR)/is_greater.c $(SRC_DIR)/is_devide.c 

# Regula uruchamiania testow
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Kompilacja plików .c do .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Czyszczenie plików tymczasowych
clean:
	rm -f $(BIN_DIR)/* $(LIB_DIR)/*

