CC = gcc
CFLAGS = -I -Wall

SRC_DIR = ./src
ASSETS_DIR = ./assets

LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

SRC=$(wildcard $(SRC_DIR)/*.c)

game: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
