# Kompilator i flagi 
CC = gcc
CFLAGS = -std=c2x -pedantic -Werror=pedantic -Wall -Wextra
LIBS = -lm

# Katalogi 
SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib
TEST_DIR = tests

# Pliki zrodlowe i obiektowe 
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(SRC_DIR)/is_prime.o
LIBRARY = $(LIB_DIR)/libisprime.a
TARGET = $(BIN_DIR)/my_program
TEST_TARGET = $(BIN_DIR)/test_runner

# Domyslna regula 
all: $(TARGET)

# Kompilacja biblioteki statycznej
$(LIBRARY): $(LIB_OBJS)
	ar rcs $(LIBRARY) $(LIB_OBJS)

# Kompilacja głównego programu
$(TARGET): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -L$(LIB_DIR) -lisprime $(LIBS)

# Reguła kompilacji testów
$(TEST_TARGET): $(TEST_DIR)/tests.c $(SRC_DIR)/is_prime.c
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_DIR)/tests.c $(SRC_DIR)/is_prime.c $(LIBS)

# Reguła uruchamiania testów
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Kompilacja plików .c do .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Czyszczenie plików tymczasowych
clean:
	rm -f $(OBJS) $(LIB_OBJS) $(TARGET) $(TEST_TARGET) $(LIBRARY)

