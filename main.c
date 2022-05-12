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

    // malloc here, update in loop
    struct LineState linestate = (struct LineState *)malloc(sizeof(struct LineState));

    /* ***** BUTTON PRESSED ***** */
    running = 1;


    while (running){

        // init threads for each sensor thing?

        /* ***** LINE SENSORS ***** */
        linesensing = true;
        threadInit();
        // if i make a thread for the line sensor one, then the while loop
        // should be in the getLineState function and that function should
        // be the thread's function
        while(linesensing){
            // make thread to track line state (apart from the 3 in line.c)
            linestate = getLineState();
            // use linestate in other files to determine movement
        }

         

        /* ***** ECHO SENSORS ***** */

    }



    // ****** FREE STRUCTS MALLOC
    // linestate

}