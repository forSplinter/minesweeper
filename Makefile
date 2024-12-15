CC = gcc
CFLAGS = -Wall
SRC = src/main.c src/game_logic.c
TARGET = build/minesweeper

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean

