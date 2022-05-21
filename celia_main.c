/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:
 * Student ID:
 * Github ID:
 * Project:
 * File: main.c
 * Description:
 * **************************************************************/
#include "main.h"
int running;
/* ***** ECHO SENSORS ***** */
bool distanceSensing = true;
extern int measurmentOne; //left
extern int measurmentTwo; //middle
extern int measurmentThree; //right

extern bool flagOne;
extern bool flagTwo;
extern bool flagThree;
/* ***** ECHO SENSORS ***** */

int main(){

    /* ***** PI SETUP ***** */
   // wiringPiSetupGpio();
    wiringPiSetup();

    //Red led light (light on == car on, light off == car off)
    pinMode(RED, OUTPUT);
    
    // IR SENSOR
   // pinMode(LEFT_PIN, OUTPUT);
    //pinMode(MID_PIN, OUTPUT);
    //pinMode(RIGHT_PIN, OUTPUT);

    
    // malloc here, update in loop
 //   struct LineState linestate = (struct LineState *)malloc(sizeof(struct LineState));

    /* ***** BUTTON PRESSED ***** */
    running = 1;


    while (running){
        digitalWrite(RED, HIGH);
        delay(500);
        

        while(distanceSensing){
        /* ***** ECHO SENSORS ***** */
        inItDistanceThreads();
        if(flagOne == false){
            printf("one %d\n", measurmentOne);
printf("one %d\n", flagOne);
    //
    distanceSensing = false;
            running = 0;
        }
       if(flagTwo == false){
            printf("two %d\n", measurmentTwo);
printf("two %d\n", flagTwo);
 
 //          distanceSensing = false;
          running = 0;

        }
        if(flagThree == false){
            printf("three %d\n", measurmentThree);
printf("three %d\n", flagThree);

//            distanceSensing = false;
            running = 0;

        }
        
    }

    }
   //turn RED led light off
    digitalWrite(RED, LOW);

    // ****** FREE STRUCTS MALLOC
    // linestate
    return 0;
}



