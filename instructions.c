/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:fantastic four
 * Student ID: 920594217
 * Github ID: valeriavallejo
 * Project:robot car
 * File: instructions.c
 * Description: This file contains the logic for the bot to move 
 * around the course using the functions and variables in distance.c,
 * line.c, and yellowMotors.c
 * **************************************************************/

#include "instructions.h"

// moves the bot slightly right
void right(){
    MotorForward(MOTORA, speed);
    MotorBackward(MOTORB, speed);
    MotorForward(MOTORC, speed);
    MotorBackward(MOTORD, speed);
}

// moves the bot slightly left
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