#include "readAndParse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile (char ** dataString,int argc, char * argv) {
    int i = 0;
    int length;
    char tempStr[100] = "";
    FILE * infile;

    //checks for valid number of input and terminates if invalid
    if (argc != 2) {
        printf("Invalid number of inputs, exiting\n");
        exit(0);
    }

    infile = fopen (argv, "r");
    while (i < 6) {
        fgets (tempStr, 100, infile);
        length = strlen (tempStr);
        if (tempStr[length-1] == '\n') {
            tempStr[length-1] = '\0';
        }
        dataString[i] = malloc (sizeof (char) * length+1);
        strcpy (dataString[i], tempStr);
        i++;
    }
    fclose (infile);
}
