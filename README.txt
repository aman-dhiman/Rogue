About the program:
This program takes a .txt file as an input and then draws the rooms and its 
attributes according to the file. These rooms together create a level for a
rogue-like game.



Compiling the program:

To compile, type:


make

 OR 

gcc src/main.c src/readFile.c src/parseFields.c src/drawLevel.c src/makeMove.c src/freeElements.c src/printInventory.c -std=c99 -Wall -pedantic -lncurses -lm -Iinclude -o bin/runMe



The program will compile without any erors or warnings



Running the program:

to run, type:

./bin/runMe <room.txt file path>



The program will read the file and draw the level. User can move using the 'w',
'a', 's' and 'd' keys or 'q' to quit. Any other key input will be ignored and 
appropriate message will appear. When moving, user picks up items and items are
stored in the inventory. User cannot move into Monsters or walls. When user move into
a door, the user gets moved to the closest door of another room on the map to the 
door user is currently at and moves into another room. 
To determine the closest door of another room, Pythagoras theorem was used 
to calculate the length of the diagonal from that room to all the rooms and the 
one with the shortest length is the closest one. 



Limitations:

This program is only tested to work on Pi. It may or may not work on other platforms.
The program only does minimal error checking which is what was required by the 
assignment. 