#include "ncursesFunc.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

void drawLevel(roomData ** room, int *** items, numOfElements amount, location
position) {

    int i, j, k;

    //draws the walls and rooms
    for (i = 0; i < 6; i++) {
        for (j = room[i]->xPos-1; j < room[i]->xPos+room[i]->length+1; j++) {
            mvaddch (room[i]->yPos-1, j, '-');
            mvaddch (room[i]->yPos+room[i]->width, j, '-');
        }
        for (j = room[i]->yPos; j < room[i]->yPos+room[i]->width; j++) {
            mvaddch (j, room[i]->xPos-1,'|');
            mvaddch (j, room[i]->xPos+room[i]->length, '|');
        }
        for (j = room[i]->yPos; j < room[i]->yPos+room[i]->width; j++) {
            for (k = room[i]->xPos; k < room[i]->xPos+room[i]->length; k++) {
                mvaddch (j, k, '.');
            }
        }
    }

    //draws all the elements in their respective locations
    for (i = 0; i < amount.nDoor; i++) {
        mvaddch (items[DOOR][i][0], items[DOOR][i][1], '+');
    }
    for (i = 0; i < amount.nMonster; i++) {
        mvaddch (items[MONSTER][i][0], items[MONSTER][i][1], 'M');
    }
    for (i = 0; i < amount.nGold; i++) {
        mvaddch (items[GOLD][i][0], items[GOLD][i][1], '*');
    }
     for (i = 0; i < amount.nMagic; i++) {
        mvaddch (items[MAGIC][i][0], items[MAGIC][i][1], '$');
    }
     for (i = 0; i < amount.nWeapon; i++) {
        mvaddch (items[WEAPON][i][0], items[WEAPON][i][1], ')');
    }
     for (i = 0; i < amount.nPotion; i++) {
        mvaddch (items[POTION][i][0], items[POTION][i][1], '!');
    }
    mvaddch (position.heroY, position.heroX, '@');
    mvaddch (position.stairY, position.stairX, '%');
    move (position.heroY, position.heroX);
}
