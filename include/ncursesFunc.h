/*Thses functions uses ncurses to draw and move the user around.*/
#ifndef _DHIMANA_NCURSESFUNCH
#define _DHIMANA_NCURSESFUNCH
#include "consAndStruct.h"

/*
drawLevel: Draws the rooms from the data provided
Pre: The items and room arrays are required as well as the amount and
position struct
Post: Draws all the rooms and elements
*/
void drawLevel (roomData ** room, int *** items, numOfElements amount,
                location position);

/*
makeMove: validates user input, makes appropriate move from the given input,
provides user with appropriate message and also calculates the closest door 
of another room when user arrives at a door.
Pre: Uses the items array, amount struct, inventory struct, position
struct, input and prevChar as parameters
Post: makes appropriate move if user input is valid
*/
void makeMove (int *** items, numOfElements amount, char input, char * prevChar,
               pickedItems * inventory, location * position);

#endif
