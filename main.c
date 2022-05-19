#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#include "distance.h"
#include "instructions.h"
#include "line.h"


int running;
#define REDLED 27 //GPIO16/WIPI 27
bool runFlag;

int main(){

    /* ***** PI SETUP ***** */
    wiringPiSetupGpio();

    // IR SENSOR 
    pinMode(LEFT_PIN, OUTPUT);
    pinMode(MID_PIN, OUTPUT);
    pinMode(RIGHT_PIN, OUTPUT);

    //Red led light (light on == car on, light off == car off)
    pinMode(RED, OUTPUT);

    // ****** THREADS ******
    pthread_t line_thread;

    /* ***** BUTTON PRESSED ***** */
    running = 1;
    
    while (running){

        digitalWrite(RED, HIGH);
        delay(500);

        /* ***** LINE SENSORS ***** */
        linesensing = true;
        threadInit();

        // need to make new thread everytime we go in this mode
        // thread will enter loop withing the thread function
        if(linesensing){
            int thread_ok = pthread_create(&line_thread, NULL, setLineState, NULL);
            if(thread_ok != 0){
                printf("\nLine thread creation failed.\n");
            }

            // thread automatically destroyed when run function has completed.

            // *********** JOIN THREADS SOMEWHERE *****************
            pthread_join(line_thread, NULL);
        }

         

        /* ***** ECHO SENSORS ***** */

        while(distanceSensing){
        inItDistanceThreads();

            if(flagOne == false){
                printf("one %d\n", measurmentOne);
                printf("one %d\n", flagOne);

                distanceSensing = false;
                running = 0;
            }

        if(flagTwo == false){
                printf("two %d\n", measurmentTwo);
                printf("two %d\n", flagTwo);
    
//              distanceSensing = false;
                running = 0;

            }

            if(flagThree == false){
                printf("three %d\n", measurmentThree);
                printf("three %d\n", flagThree);

//              distanceSensing = false;
                running = 0;

            }
        
        }
    }   
}

    /****** MOTORS ??? ******

    }



    // ****** FREE STRUCTS MALLOC
    // linestate

}