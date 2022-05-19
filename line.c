//#include "line.h"

#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <stdbool.h>

#define LEFT_PIN 5
#define MID_PIN 6
#define RIGHT_PIN 13

int leftlineval;
int midlineval;
int rightlineval;

bool linesensing;

char lineState[4] = "000";

int main(){
    int counter = 0; // just for testing
    linesensing = true;
    while(linesensing){
        if(digitalRead(LEFT_PIN))
        {
            leftlineval = 1;
        }
        else{
            leftlineval = 0;
        }

        if(digitalRead(MID_PIN))
        {
            midlineval = 1;
        }
        else{
            midlineval = 0;
        }

        if(digitalRead(RIGHT_PIN))
        {
            rightlineval = 1;
        }
        else{
            rightlineval = 0;
        }  

        // update current state of line
        sprintf(lineState[0], "%d", leftlineval);
        sprintf(lineState[1], "%d", midlineval);
        sprintf(lineState[2], "%d", rightlineval);

        printf("Line State: %s\n", lineState);

        // temporary, just for testing a limited amount of time
        counter++;
        if(counter >= 20){
            linesensing = false;
        }
    }
    return 0;
}

/*void threadInit(){
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

}*/

// threads will each run their own version of this to keep track of own line sensor
/* void *setLineState(struct LineSensor *linesensor){
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

// needs params?
void freeLines(){



}*/