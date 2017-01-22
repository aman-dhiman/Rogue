/*main function creates arrays for elements, reads the file and save the data
in these arrays, use the arrays to draw the rooms, takes user input to move
the user around and then exits on pressing 'q'. Finally, it prints the final
inventory of the user.*/

#include "consAndStruct.h"
#include "readAndParse.h"
#include "ncursesFunc.h"
#include "freeElements.h"
#include "printInventory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

int main(int argc, char *argv[]) {
    int i, input;
    int *** items;
    char ** dataString;
    roomData ** room;
    char prevChar;

    numOfElements amount;
    pickedItems inventory;
    location position;

    inventory.gold = 0;
    inventory.magic = 0;
    inventory.weapon = 0;
    inventory.potion = 0;

    prevChar = '.';

    dataString = malloc (sizeof (char *) * 6);
    room = malloc (sizeof (roomData *) * 6);
    for (i = 0; i < 6; i++) {
        room[i] = malloc (sizeof (roomData));
    }
    items = malloc (sizeof (int **) * 6);

    readFile (dataString, argc, argv[1]);
    parseFields (dataString, room, items, &amount, &position);

    initscr();
    cbreak();
    noecho();
    drawLevel (room, items, amount, position);

    mvprintw (55, 0, "Welcome to rogue. Use 'w', 'a', 's' or 'd' to move around"
                     " or 'q' to quit.");
    mvprintw (56, 0, "Inventory:    Gold = %d    Potion = %d    Magic = %d"
                     "    Weapon = %d", inventory.gold, inventory.potion,
                                        inventory.magic, inventory.weapon);
    move (position.heroY, position.heroX);

    input = getch();
    while (input != 'q') {
        makeMove (items, amount, input, &prevChar, &inventory, &position);
        input = getch();
    }

    refresh();
    endwin();

    printInventory (inventory);
    freeElements (items, room, dataString, amount);
    return 0;
}
