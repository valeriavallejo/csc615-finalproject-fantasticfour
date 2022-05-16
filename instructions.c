#include "instructions.h"

// add conditionals

// examples:

// if linestate[0] == 1
    // move left

//if right echo sensor senses it within 10 cm, turn left again, go forward, 
// turn right and check for obstacle again

// each instruction thing should probably have its own thread (one for echo and one for line sensor)

// ***** CHECKING IF ON LINE
if(strcmp(linestate, "100") == 0)
{
    while(strcmp(linestate, "100" != 0)){
        // turn left, should be defined in wheels.c
    }
}
else if(strcmp(linestate, "010"))
{
    // no while loop, keep moving straight
}
else if(strcmp(linestate, "001"))
{
    while(strcmp(linestate, "001" != 0)){
        // turn right, should be defined in wheels.c
    }
}
else{
    printf("line sensor sensing nothing or multiple sensing at once");
}