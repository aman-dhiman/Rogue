/*This header file defines the required constants and structs.*/
#ifndef _DHIMANA_CONSANDSTRUCTH
#define _DHIMANA_CONSANDSTRUCTH

#define DOOR 0
#define MONSTER 1
#define GOLD 2
#define MAGIC 3
#define WEAPON 4
#define POTION 5

//Struct for room characteristics
typedef struct RoomData {
    int xPos;
    int yPos;
    int length;
    int width;
}roomData;

//Struct for saving total number of the corresponding elements
typedef struct totalAmount {
    int nDoor;
    int nMonster;
    int nGold;
    int nMagic;
    int nWeapon;
    int nPotion;
}numOfElements;

//Struct for keeping track of the items picked by the user
typedef struct itemsPicked {
    int potion;
    int gold;
    int magic;
    int weapon;
}pickedItems;

//Struct for keeping the user's and stair's location
typedef struct Location {
    int heroX;
    int heroY;
    int stairX;
    int stairY;
}location;

#endif
