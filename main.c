// putting everything together

// will have the main running loop for all the parts

// pi set up too

#include "line.h"


int running;

int main(){

    /* ***** PI SETUP ***** */
    wiringPiSetupGpio();

    // IR SENSOR 
    pinMode(LEFT_PIN, OUTPUT);
    pinMode(MID_PIN, OUTPUT);
    pinMode(RIGHT_PIN, OUTPUT);

    /* ***** BUTTON PRESSED ***** */
    running = 1;

    while (running){
        /* ***** LINE SENSORS ***** */
        /*(threadInit();
        int lThread = piThreadCreate (leftSens); // i think once these are called, the program that constantly checks and updates values starts running
        int mThread = piThreadCreate (midSens);
        int rThread = piThreadCreate (rightSens);

        if (lThread != 0 ||
            mThread != 0 ||
            rThread != 0){
            
            printf("Thread start fail...");
            }*/

        
        int lineThread = piThreadCreate (lineSens);
        

        /* ***** ECHO SENSORS ***** */

    }
    
    /* ***** LINE SENSORS ***** */

}