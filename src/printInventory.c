#include <stdlib.h>
#include <stdio.h>
#include "printInventory.h"

void printInventory (pickedItems inventory) {
    //prints the final inventory items at program exit
    printf ("Inventory includes: \n");
    printf ("Gold: %d\n", inventory.gold);
    printf ("Potion: %d\n", inventory.potion);
    printf ("Magic: %d\n", inventory.magic);
    printf ("Weapon: %d\n", inventory.weapon);
}
