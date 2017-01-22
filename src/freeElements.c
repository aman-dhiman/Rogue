#include <stdlib.h>
#include <stdio.h>
#include "freeElements.h"

void freeElements (int *** items, roomData ** room, char ** dataString,
                   numOfElements amount) {
    int i;

    //frees all the arrays which were allocated in the main and elsewhere
    for (i = 0; i < 6; i++) {
        free (dataString[i]);
        free (room[i]);
    }
    for (i = 0; i < amount.nDoor; i++) {
        free (items[DOOR][i]);
    }
    for (i = 0; i < amount.nMonster; i++) {
        free (items[MONSTER][i]);
    }
    for (i = 0; i < amount.nGold; i++) {
        free (items[GOLD][i]);
    }
    for (i = 0; i < amount.nMagic; i++) {
        free (items[MAGIC][i]);
    }
    for (i = 0; i < amount.nWeapon; i++) {
        free (items[WEAPON][i]);
    }
    for (i = 0; i < amount.nPotion; i++) {
        free (items[POTION][i]);
    }
    free (items[DOOR]);
    free (items[MONSTER]);
    free (items[GOLD]);
    free (items[MAGIC]);
    free (items[WEAPON]);
    free (items[POTION]);
    free (items);
    free (dataString);
    free (room);
}
