// three global variables for each sensor (0 / 1)

// threads tracking variables

// have loop that checks if middle sensor is on line
    // if not on middle sensor, check other sensors

        //if detected by left sensor
            //call left function until the middle sensor senses again

        //if detected by right sensor
            //call right function until the middle sensor senses again

#include "line.h"

//maybe put all this into a function thats called in main

//how will other files get info from this file ?
    // function that can access the value in the struct whenever it needs to
    // there should be an "alarm" when they line is not detected by mid sensor



// ***** init line sensors *****
struct LineSensor *left = (struct LineSensor *)malloc(sizeof(struct LineSensor));
left->value = 0;
left->pin = LEFT_PIN;

struct LineSensor *mid = (struct LineSensor *)malloc(sizeof(struct LineSensor));
left->value = 0;
left->pin = MID_PIN;

struct LineSensor *right = (struct LineSensor *)malloc(sizeof(struct LineSensor));
left->value = 0;
left->pin = RIGHT_PIN;

// init threads
pthread_t left_line_thread;
pthread_t mid_line_thread;
pthread_t right_line_thread;

// create threads
pthread_create(&left_line_thread, NULL, setLineState, &left);
pthread_create(&mid_line_thread, NULL, setLineState, &mid);
pthread_create(&right_line_thread, NULL, setLineState, &right);

// threads will each run their own version of this to keep track of own line sensor
void *setLineState(struct LineSensor *linesensor){
    while (1){
        if (digitalRead((*linesensor).pin)){
            (*linesensor).value = 1;
        }
        else {
            (*linesensor).value = 0;
        }
    }
}
