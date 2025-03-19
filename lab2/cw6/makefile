CC = gcc 
CFLAGS = -std=c2x -pedatnic -Wall -Werror -Wextra 
BIN_DIR = bin
BUILD_DIR = build

main: main.o | $(BIN_DIR)
	$(CC) $(CFlAGS) -o $(BIN_DIR)/$@ $(BUILD_DIR)/$< 

main.o: main.c | $(BUILD_DIR)
	$(CC) $(CFlAGS) -c $< -o $(BUILD_DIR)/$@ 

$(BUILD_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean: 
	rm -rf $(BIN_DIR) $(BUILD_DIR)

