CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=bin/%.o)
TARGET = bin/gerenciador

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

bin/%.o: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf bin/*.o $(TARGET)

run: all
	./$(TARGET)