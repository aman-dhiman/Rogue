all:
	gcc src/main.c src/readFile.c src/parseFields.c src/drawLevel.c src/makeMove.c src/freeElements.c src/printInventory.c -std=c99 -Wall -pedantic -lncurses -lm -Iinclude -o bin/runMe
