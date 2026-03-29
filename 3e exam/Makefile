CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -fPIC

SRC_DIR = src
INC_DIR = inc
TEST_DIR = test
BIN_DIR = out/bin
LIB_DIR = out/lib

SRCS = $(SRC_DIR)/compare_characters.c \
       $(SRC_DIR)/find_anagram_in_dict.c \
       $(SRC_DIR)/is_anagram.c

LIB_OBJS = $(SRCS:.c=.o)

TARGET = $(BIN_DIR)/anagram
TEST_TARGET = $(BIN_DIR)/main_test
LIBRARY = $(LIB_DIR)/libfunctions.so

all: $(LIBRARY) $(TARGET) $(TEST_TARGET)

$(LIBRARY): $(LIB_OBJS)
	mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) -shared $^ -o $@

$(TARGET): $(SRC_DIR)/anagram.c $(LIBRARY)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(LIBRARY) -I$(INC_DIR) -o $@

$(TEST_TARGET): $(TEST_DIR)/main_test.c $(LIBRARY)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(LIBRARY) -I$(INC_DIR) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(LIB_OBJS) $(LIBRARY) $(TARGET) $(TEST_TARGET)

.PHONY: all clean