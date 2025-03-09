# Kompilator i flagi
CC = gcc
CFLAGS = -std=c2x -pedantic -Werror=pedantic -Wall -Wextra

# Katalogi
SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib
TEST_DIR = tests

# Pobieranie wszystkich plików .c w src/
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(SRC_DIR)/utils.o
LIBRARY = $(LIB_DIR)/libutils.a
TARGET = $(BIN_DIR)/my_program
TEST_TARGET = $(BIN_DIR)/test_runner

# Domyślna reguła
all: $(TARGET)

# Kompilacja biblioteki statycznej
$(LIBRARY): $(LIB_OBJS)
	ar rcs $(LIBRARY) $(LIB_OBJS)

# Kompilacja głównego programu
$(TARGET): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -L$(LIB_DIR) -lutils

# Reguła kompilacji testów
$(TEST_TARGET): $(TEST_DIR)/tests.c $(SRC_DIR)/math_utils.c
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_DIR)/tests.c $(SRC_DIR)/math_utils.c

# Reguła uruchamiania testów
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Kompilacja plikow
$.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Czyszczenie plików tymczasowych
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_TARGET) $(LIBRARY)

