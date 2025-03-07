# Kompilator i flagi
CC = gcc
CFLAGS = -std=c2x -pedantic -Werror=pedantic -Wall -Wextra

# Katalogi
SRC_DIR := src
BIN_DIR := bin
LIB_DIR := lib
TEST_DIR := tests

# Pobieranie wszystkich plików .c w src/
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

LIBRARY := $(LIB_DIR)/libutils.a
TARGET := $(BIN_DIR)/my_program
TEST_TARGET := $(BIN_DIR)/test_runner

# Domyślna reguła
all: $(TARGET)

# Kompilacja biblioteki statycznej
$(LIBRARY): $(BIN_DIR)/utils.o
	mkdir -p $(LIB_DIR)
	ar rcs $(LIBRARY) $(BIN_DIR)/utils.o

# Kompilacja głównego programu
$(TARGET): $(OBJS) $(LIBRARY)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -L$(LIB_DIR) -lutils

# Reguła kompilacji testów
$(TEST_TARGET): $(TEST_DIR)/tests.c $(SRC_DIR)/math_utils.c
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_DIR)/tests.c $(SRC_DIR)/math_utils.c

# Reguła uruchamiania testów
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Kompilacja plików .c do .o (zapisuje je w bin/)
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Czyszczenie plików tymczasowych
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_TARGET) $(LIBRARY)

