/*These functions read from file and extract the required information
and saves them in their respective places.*/
#ifndef _DHIMANA_READANDPARSEH
#define _DHIMANA_READANDPARSEH
#include "consAndStruct.h"

/*
readFile: checks for valid number of inputs, read from a file and 
saves 1 line at a time to a string array
Pre: the string array, args and argv are required
Post: Reads file and saves lines to the string array
*/
void readFile (char ** dataString, int argc, char * argv);

/*
parseFields: Takes the string array, breaks it into elements content
and saves the elements in their appropriate places. It also checks
for valid placement of the elements and if invalid, moves them to the
closest position of the corresponding room
Pre: The string array, room struct, items array, amount struct and
position struct
Post: Tokenizes the strings and saves the elements characteristics
*/
void parseFields (char ** dataString, roomData ** room, int *** items,
                  numOfElements * amount, location * position);

#endif
