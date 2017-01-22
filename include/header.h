#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#define DOOR 0
#define MONSTER 1
#define GOLD 2
#define MAGIC 3
#define WEAPON 4
#define POTION 5

typedef struct RoomData{
    int xPos;
    int yPos;
    int length;
    int width;
}roomData;

typedef struct totalAmount{
    int nDoor;
    int nMonster;
    int nGold;
    int nMagic;
    int nWeapon;
    int nPotion;
}numOfElements;

typedef struct itemsPicked{
    int potion;
    int gold;
    int magic;
    int weapon;
}pickedItems;

typedef struct Location{
    int heroX;
    int heroY;
    int stairX;
    int stairY;
}location;

void readFile (char ** dataString, int argc, char * argv);
void parseFields (char ** dataString, roomData ** room, int *** items, 
                  numOfElements * amount, location * position);
void drawLevel(roomData ** room, int *** items, numOfElements amount, location
position);
void makeMove (int *** items, numOfElements amount, char input, char * prevChar,
               pickedItems * inventory, location * position);
void freeElements (int *** items, roomData ** room, char ** dataString,
                   numOfElements amount);
void printInventory (pickedItems inventory);
