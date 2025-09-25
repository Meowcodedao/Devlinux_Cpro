CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRC = $(wildcard source/*.c)
OBJ = $(SRC:.c=.o)
TARGET = spws

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

