#include "ncursesFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>//Used for calculating the closest door of another room to move into

void makeMove (int *** items, numOfElements amount, char input, char * prevChar,
               pickedItems * inventory, location * position) {

    mvprintw (55, 0, "                                                     "
                     "                           ");
    move (position->heroY, position->heroX);

    //checks for validity of user input
    if ((input != 'w') && (input != 'a') && (input != 's') &&
        (input != 'd')) {
        mvprintw (55, 0, "Invalid input. Use 'w', 'a', 's' or 'd' to move "
                         "or 'q' to quit");
        move (position->heroY, position->heroX);
        return;
    }

    int i, x, y, nextX, nextY, plusY, plusX, plusRoom;
    double distance, newDistance;
    char icon;
    distance = 100;
    getyx(stdscr, y, x);
    mvaddch (y, x, *prevChar);


    for (i = 0; i < amount.nDoor; i++) {
        mvaddch (items[DOOR][i][0], items[DOOR][i][1], '+');
    }
    mvaddch(position->stairY, position->stairX, '%');

    //moves according to the input
    switch (input) {
        case 'w':
            move (y-1, x);
            getyx (stdscr, nextY, nextX);
            getyx (stdscr, plusY, plusX);
            break;

        case 's':
            move (y+1, x);
            getyx (stdscr, nextY, nextX);
            getyx (stdscr, plusY, plusX);
            break;

        case 'a':
            move (y, x-1);
            getyx (stdscr, nextY, nextX);
            getyx (stdscr, plusY, plusX);
            break;

        case 'd':
            move (y, x+1);
            getyx (stdscr, nextY, nextX);
            getyx (stdscr, plusY, plusX);
            break;
    }

    icon = mvinch(nextY, nextX);
    if ((icon != 'M') && (icon != '|') && (icon != '-')) {
        *prevChar = icon;
    }
    if ((icon == '*') || (icon == ')') || (icon == '$') || (icon == '!')) {
        *prevChar = '.';
    }

    //checks whether move possible and make the move, if not prints a message
    if ((icon == '|') || (icon == '-') || (icon == ' ')) {
        mvaddch (y, x, '@');
        mvprintw (55, 0, "You cannot move into the walls or out of room");
    }
    //determines the closest door of another room to move into
    else if (icon == '+') {
        for (i = 0; i < amount.nDoor; i++) {
            if ((nextY == items[DOOR][i][0]) && (nextX == items[DOOR][i][1])) {
                plusRoom = items[DOOR][i][2];
            }
        }
        for (i = 0; i < amount.nDoor; i++) {
            if (items[DOOR][i][2] != plusRoom) {
                newDistance = sqrt ((pow ((items[DOOR][i][0] - plusY), 2) +
                                  pow ((items[DOOR][i][1] - plusX), 2)));
                if (newDistance < distance) {
                    distance = newDistance;
                    nextY = items[DOOR][i][0];
                    nextX = items[DOOR][i][1];
                }
            }
        }
        mvaddch (nextY, nextX, '@');
        position->heroY = nextY;
        position->heroX = nextX;
    }
    else if (icon == '%') {
        mvaddch (nextY, nextX, '@');
        position->heroY = nextY;
        position->heroX = nextX;
    }
    else if (icon == 'M') {
        mvaddch (y, x, '@');
        mvprintw (55, 0, "You cannot move into a Monster");
    }
    else if (icon == '*') {
        mvaddch (nextY, nextX, '@');
        position->heroY = nextY;
        position->heroX = nextX;
        mvprintw (55, 0, "You just picked a gold");
        inventory->gold++;
    }
    else if (icon == '$') {
        mvaddch (nextY, nextX, '@');
        position->heroY = nextY;
        position->heroX = nextX;
        mvprintw (55, 0, "You just picked a magic");
        inventory->magic++;
    }
    else if (icon == ')') {
        mvaddch (nextY, nextX, '@');
        position->heroY = nextY;
        position->heroX = nextX;
        mvprintw (55, 0, "You just picked a weapon");
        inventory->weapon++;
    }
    else if (icon == '!') {
        mvaddch (nextY, nextX, '@');
        position->heroY = nextY;
        position->heroX = nextX;
        mvprintw (55, 0, "You just picked a potion");
        inventory->potion++;
    }
    else if (icon == '.') {
        mvaddch (nextY, nextX, '@');
        position->heroY = nextY;
        position->heroX = nextX;
    }

    mvprintw (56, 0, "Inventory:    Gold = %d    Potion = %d    Magic = %d"
                      "    Weapon = %d", inventory->gold, inventory->potion,
                                         inventory->magic, inventory->weapon);
    move (position->heroY, position->heroX);
    refresh();
}
