#include "readAndParse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseFields (char ** dataString, roomData ** room, int *** items, 
                  numOfElements * amount, location * position) {
    int i = 0;
    int j = 0;
    int f, numDoor, numMonster, numGold, numMagic, numWeapon, numPotion;

    //int for saving total number os respective elements
    numDoor = 0;
    numMonster = 0;
    numGold = 0;
    numMagic = 0;
    numWeapon = 0;
    numPotion = 0;
    int shift = 0;
    char * token;
    char * token0;
    char * token1;
    char * token2;
    char * token3;
    char * token4;
    char * token5;
    char * str;
    amount->nDoor = 0;
    amount->nMonster = 0;
    amount->nGold = 0;
    amount->nMagic = 0;
    amount->nWeapon = 0;
    amount->nPotion = 0;
    char fields[6][20][8];

    //tokenize the strings and save elemts into fields array
    f = 0;
    token0 = strtok (dataString[0], " ");
    while (token0 != NULL) {
        strcpy (fields[0][f], token0);
        token0 = strtok(NULL, " ");
        f++;
    }

    f = 0;
    token1 = strtok (dataString[1], " ");
    while (token1 != NULL) {
        strcpy (fields[1][f], token1);
        token1 = strtok(NULL, " ");
        f++;
    }

    f = 0;
    token2 = strtok (dataString[2], " ");
    while (token2 != NULL) {
        strcpy (fields[2][f], token2);
        token2 = strtok(NULL, " ");
        f++;
    }

    f = 0;
    token3 = strtok (dataString[3], " ");
    while (token3 != NULL) {
        strcpy (fields[3][f], token3);
        token3 = strtok(NULL, " ");
        f++;
    }

    f = 0;
    token4 = strtok (dataString[4], " ");
    while (token4 != NULL) {
        strcpy (fields[4][f], token4);
        token4 = strtok(NULL, " ");
        f++;
    }

    f = 0;
    token5 = strtok (dataString[5], " ");
    while (token5 != NULL) {
        strcpy (fields[5][f], token5);
        token5 = strtok(NULL, " ");
        f++;
    }

    //calculates total amount of all the elements
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 20; j++) {
            switch (fields[i][j][0]) {
                case 'd':
                    numDoor++;
                    break;

                case 'M':
                    numMonster++;
                    break;

                case 'g':
                    numGold++;
                    break;

                case 'm':
                    numMagic++;
                    break;

                case 'w':
                    numWeapon++;
                    break;

                case 'p':
                    numPotion++;
                    break;
            }
        }
    }

    //allocates memory given the total number of elements
    items[DOOR] = malloc (sizeof (int *)*numDoor);
    items[MONSTER] = malloc (sizeof (int *)*numMonster);
    items[GOLD] = malloc (sizeof (int *)*numGold);
    items[MAGIC] = malloc (sizeof (int *)*numMagic);
    items[WEAPON] = malloc (sizeof (int *)*numWeapon);
    items[POTION] = malloc (sizeof (int *)*numPotion);

    //initializes the room data and fills the items array with elements data
    for (i = 0; i < 6; i++) {
        if ((i == 0)||(i == 1)||(i == 2)) {
            room[i]->yPos = 4;
        }
        if ((i == 0)||(i == 3)) {
            room[i]->xPos = 4;
        }
        if ((i == 1)||(i == 4)) {
            room[i]->xPos = 33;
        }
        if ((i == 2)||(i == 5)) {
            room[i]->xPos = 62;
        }
        if ((i == 3)||(i == 4)||(i == 5)) {
            room[i]->yPos = 28;
        }
        token = strtok (fields[i][0], " X");
        room[i]->width = atoi (token);
        token = strtok (NULL, " X");
        room[i]->length = atoi (token);
        for (j = 0; j < 20; j++) {

            switch (fields[i][j][0])
            {
            case 'd':
                shift = atoi(fields[i][j] + 2);
                items[DOOR][amount->nDoor] = malloc (sizeof (int) * 3);
                items[DOOR][amount->nDoor][2] = i;

                switch (fields[i][j][1])
                {
                case 'n':
                    while (shift >= room[i]->length) {
                        shift--;
                    }
                    items[DOOR][amount->nDoor][0] = room[i]->yPos-1;
                    items[DOOR][amount->nDoor][1] = room[i]->xPos+shift;
                    amount->nDoor++;
                    break;

                case 'e':
                    while (shift >= room[i]->width) {
                        shift--;
                    }
                    items[DOOR][amount->nDoor][0] = room[i]->yPos+shift;
                    items[DOOR][amount->nDoor][1] = room[i]->xPos+
                                                    room[i]->length;
                    amount->nDoor++;
                    break;

                case 'w':
                    while (shift >= room[i]->width) {
                        shift--;
                    }
                    items[DOOR][amount->nDoor][0] = room[i]->yPos+shift;
                    items[DOOR][amount->nDoor][1] = room[i]->xPos-1;
                    amount->nDoor++;
                    break;

                case 's':
                    while (shift >= room[i]->length) {
                        shift--;
                    }
                    items[DOOR][amount->nDoor][0] = room[i]->yPos+
                                                    room[i]->width;
                    items[DOOR][amount->nDoor][1] = room[i]->xPos+shift;
                    amount->nDoor++;
                    break;
                }
            break;

            case 'M':
                str = strtok(fields[i][j], ",");
                shift = atoi (str + 1);
                while (shift >= room[i]->width) {
                    shift--;
                }
                items[MONSTER][amount->nMonster] = malloc (sizeof (int) * 2);
                items[MONSTER][amount->nMonster][0] = room[i]->yPos+shift;
                str = strtok (NULL, " ");
                shift = atoi (str);
                while (shift >= room[i]->length) {
                    shift--;
                }
                items[MONSTER][amount->nMonster][1] = room[i]->xPos+shift;
                amount->nMonster++;
                break;

            case 'g':
                str = strtok(fields[i][j], ",");
                shift = atoi (str + 1);
                while (shift >= room[i]->width) {
                    shift--;
                }
                items[GOLD][amount->nGold] = malloc (sizeof (int) * 2);
                items[GOLD][amount->nGold][0] = room[i]->yPos+shift;
                str = strtok (NULL, " ");
                shift = atoi (str);
                while (shift >= room[i]->length) {
                    shift--;
                }
                items[GOLD][amount->nGold][1] = room[i]->xPos+shift;
                amount->nGold++;
                break;

            case 'm':
                str = strtok(fields[i][j], ",");
                shift = atoi (str + 1);
                while (shift >= room[i]->width) {
                    shift--;
                }
                items[MAGIC][amount->nMagic] = malloc (sizeof (int) * 2);
                items[MAGIC][amount->nMagic][0] = room[i]->yPos+shift;
                str = strtok (NULL, " ");
                shift = atoi (str);
                while (shift >= room[i]->length) {
                    shift--;
                }
                items[MAGIC][amount->nMagic][1] = room[i]->xPos+shift;
                amount->nMagic++;
                break;

            case 'w':
                str = strtok(fields[i][j], ",");
                shift = atoi (str + 1);
                while (shift >= room[i]->width) {
                    shift--;
                }
                items[WEAPON][amount->nWeapon] = malloc (sizeof (int) * 2);
                items[WEAPON][amount->nWeapon][0] = room[i]->yPos+shift;
                str = strtok (NULL, " ");
                shift = atoi (str);
                while (shift >= room[i]->length) {
                    shift--;
                }
                items[WEAPON][amount->nWeapon][1] = room[i]->xPos+shift;
                amount->nWeapon++;
                break;

            case 'p':
                str = strtok(fields[i][j], ",");
                shift = atoi (str + 1);
                while (shift >= room[i]->width) {
                    shift--;
                }
                items[POTION][amount->nPotion] = malloc (sizeof (int) * 2);
                items[POTION][amount->nPotion][0] = room[i]->yPos+shift;
                str = strtok (NULL, " ");
                shift = atoi (str);
                while (shift >= room[i]->length) {
                    shift--;
                }
                items[POTION][amount->nPotion][1] = room[i]->xPos+shift;
                amount->nPotion++;
                break;

            case 'h':
                str = strtok(fields[i][j], ",");
                shift = atoi (str + 1);
                while (shift >= room[i]->width) {
                    shift--;
                }
                position->heroY = room[i]->yPos+shift;
                str = strtok (NULL, " ");
                shift = atoi (str);
                while (shift >= room[i]->length) {
                    shift--;
                }
                position->heroX = room[i]->xPos+shift;
                break;

            case 's':
                str = strtok(fields[i][j], ",");
                shift = atoi (str + 1);
                while (shift >= room[i]->width) {
                    shift--;
                }
                position->stairY = room[i]->yPos+shift;
                str = strtok (NULL, " ");
                shift = atoi (str);
                while (shift >= room[i]->length) {
                    shift--;
                }
                position->stairX = room[i]->xPos+shift;
                break;

            }
        }
    }
}
