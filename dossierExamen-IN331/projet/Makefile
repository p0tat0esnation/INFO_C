CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -fPIC
LIBS= -lm

INC = -Iinc
SRC_DIR = src

SRCS = $(SRC_DIR)/file_metrics.c $(SRC_DIR)/fibo.c $(SRC_DIR)/unscrambler.c $(SRC_DIR)/caesar.c

BIN_DIR = out/bin
LIB_DIR = out/lib

all: $(BIN_DIR)/exam

$(BIN_DIR)/exam: $(SRC_DIR)/main.c $(LIB_DIR)/libfile_metrics.so | $(BIN_DIR) 
	$(CC) $(CFLAGS) $^ -L$(LIB_DIR) -lfile_metrics $(INC) $(LIBS) -Wl,-rpath,'$$ORIGIN/../lib' -o $@

$(LIB_DIR)/libfile_metrics.so: $(SRCS) | $(LIB_DIR)
	$(CC) $(CFLAGS) -shared $^ $(INC) $(LIBS) -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

run: all
	LD_LIBRARY_PATH=$(LIB_DIR):$$LD_LIBRARY_PATH $(BIN_DIR)/exam

clean:
	rm -rf $(BIN_DIR) $(LIB_DIR)

.PHONY: all clean