// three global variables for each sensor (0 / 1)

// threads tracking variables

// have loop that checks if middle sensor is on line
    // if not on middle sensor, check other sensors

        //if detected by left sensor
            //call left function until the middle sensor senses again

        //if detected by right sensor
            //call right function until the middle sensor senses again

#include "line.h"

PI_THREAD (lineSens)
    {
        // not sure if setting other variables to 0 is necessary if we trust that the line sensors are far apart enough
        while (1){
            if (digitalRead(LEFT_PIN)){
                leftVal = 1;
                midVal = 0;
                rightVal = 0;
            }
            else if (digitalRead(MID_PIN)){
                leftVal = 0;
                midVal = 1;
                rightVal = 0;
            }
            else if (digitalRead(RIGHT_PIN)){
                leftVal = 0;
                midVal = 0;
                rightVal = 1;
            }
            else {
                // none tracked, probably in echo sensor mode 
            }
        }
    }

// thread for each sensor to keep track of its value, to be used in main loop.


/*void threadInit(){

    PI_THREAD (leftSens)
    {
        while (1){
            if (digitalRead(LEFT_PIN)){
                leftVal = 1;
            }
            else {
                leftVal = 0;
            }
        }
    }

    PI_THREAD (midSens)
    {
        while (1){
            if (digitalRead(MID_PIN)){
                midVal = 1;
            }
            else {
                midVal = 0;
            }
    }
    }

    PI_THREAD (rightSens)
    {
        while (1){
            if (digitalRead(RIGHT_PIN)){
                rightVal = 1;
            }
            else {
                rightVal = 0;
            }
    }
    }

}*/