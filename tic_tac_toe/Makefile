CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = tic_tac_toe
SRC = tic_tac_toe.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
