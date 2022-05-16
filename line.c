// three global variables for each sensor (0 / 1)

// threads tracking variables

// have loop that checks if middle sensor is on line
    // if not on middle sensor, check other sensors

        //if detected by left sensor
            //call left function until the middle sensor senses again

        //if detected by right sensor
            //call right function until the middle sensor senses again

#include "line.h"

// ****** QUESTION ********
    // do we need a thread join or mutex ?

    // online: no, you can detach one thread if you want it to leave it 
    // alone. If you start a thread, either you detach it or you join it 
    //before the program ends, otherwise this is undefined behaviour.

    //ill just detach them all
    // **** or maybe i do need to join them so they can all combine to make
    // one single state to prevent getting 2 sensors with the value of 1 or smn

//maybe put all this into a function thats called in main

//how will other files get info from this file ?
    // function that can access the value in the struct whenever it needs to
    // there should be an "alarm" when they line is not detected by mid sensor

void threadInit(){
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

    // detach so no error ??? idk if i should opt for joining
    pthread_detach(left_line_thread);
    pthread_detach(mid_line_thread);
    pthread_detach(right_line_thread);

    // do we have to return here, will i need to save the data?
    // should most of the vars be global?
    // does my thread stuff get lost when this funtion is over?

}

// threads will each run their own version of this to keep track of own line sensor
void *setLineState(struct LineSensor *linesensor){
    while (linesensing){
        if (digitalRead((*linesensor).pin)){
            (*linesensor).value = 1;
        }
        else {
            (*linesensor).value = 0;
        }
    }

    
}

string getLineState(){
    linestate[0] = (*left).value;
    linestate[1] = (*mid).value;
    linestate[2] = (*right).value;
    return lineState;
}

// idk if initialized correctly
// note, this isnt the main line thread's function i think.
// this one should be constantly called in main or motor so we know if we should
// be turning or going straight
/*struct LineState getLineState(){
    struct LineState linestate = (struct LineState *)malloc(sizeof(struct LineState));
    (*linestate).left_val = left.value;
    (*linestate).mid_val = mid.value;
    (*linestate).right_val = right.value;

    return linestate;
}*/

// needs params?
void freeLines(){



}


/* ****** WITHOUT EACH LINE SENSOR HAVING A THREAD

    while(linesensing){
        if(digitalRead(LEFT_PIN)
        {
            leftlineval = 1;
        }
        else{
            leftlineval = 0;
        }

        if(digitalRead(MID_PIN)
        {
            midlineval = 1;
        }
        else{
            midlineval = 0;
        }

        if(digitalRead(RIGHT_PIN)
        {
            rightlineval = 1;
        }
        else{
            rightlineval = 0;
        }  
    }

    
*/