CC = gcc
CFLAGS = -std=c2x -pedantic -Werror=pedantic -Wall -Wextra

SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib
TEST_DIR = tests

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/contact.c 
OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(SRC_DIR)/contact.o
LIBRARY = $(LIB_DIR)/libcontact.a 
TARGET = $(BIN_DIR)/contact_manager
TEST_TARGET = $(BIN_DIR)/test_runner 

all: $(TARGET) 

$(LIBRARY): $(LIB_OBJS) 
	ar rcs $(LIBRARY) $(LIB_OBJS) 

$(TARGET): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -L$(LIB_DIR) -lcontact 

$(TEST_TARGET): $(TEST_DIR)/tests.c $(SRC_DIR)/contact.c
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_DIR)/tests.c $(SRC_DIR)/contact.c 

test: $(TEST_TARGET)
	./$(TEST_TARGET)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(LIB_OBJS) $(TARGET) $(TEST_TARGET) $(LIBRARY) 

