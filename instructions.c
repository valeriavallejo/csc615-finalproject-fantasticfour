#include "instructions.h"


// add conditionals

// examples:

// if linestate[0] == 1
    // move left

//if right echo sensor senses it within 10 cm, turn left again, go forward, 
// turn right and check for obstacle again

void right(){
    MotorForward(MOTORA, speed);
    MotorBackward(MOTORB, speed);
    MotorForward(MOTORC, speed);
    MotorBackward(MOTORD, speed);
}
void left(){
    MotorForward(MOTORA, speed);
    MotorBackward(MOTORB, speed);
    MotorForward(MOTORC, speed);
    MotorBackward(MOTORD, speed);
}

// ***** CHECKING IF ON LINE
void onLine(){
    if( linestate[0] == 1 &&
        linestate[1] == 0 &&
        linestate[2] == 0 ){
        while(  linestate[0] == 1 &&
                linestate[1] == 0 &&
                linestate[2] == 0 )
        {
            left();
        }
    }
    else if(linestate[0] == 0 &&
            linestate[1] == 0 &&
            linestate[2] == 1 ){
        while(linestate[0] == 0 &&
            linestate[1] == 0 &&
            linestate[2] == 1 )
            {
                right();
            }
    }

    else if(linestate[0] == 0 &&
            linestate[1] == 1 &&
            linestate[2] == 0 ){

        while(linestate[0] == 0 &&
            linestate[1] == 1 &&
            linestate[2] == 0 )
            {
                printf("Going straight");
            }
    }
    else{
        printf("Mulitple line sensors or none detecting")
    }
}