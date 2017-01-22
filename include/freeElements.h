/*This function frees the allocated memory for all the arrays.*/
#ifndef _DHIMANA_FREEELEMENTSH
#define _DHIMANA_FREEELEMENTSH
#include "consAndStruct.h"

/*
freeElements: frees the memory for all the allocated arrays
Pre: all the three arrays are input
Post: frees the memory allocated to those arrays
*/
void freeElements (int *** items, roomData ** room, char ** dataString,
                   numOfElements amount);

#endif
