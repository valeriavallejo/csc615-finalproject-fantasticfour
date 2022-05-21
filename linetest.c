#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <pthread.h>
#include <stdbool.h>

#include <time.h>

#define LEFT_PIN 5
#define MID_PIN 6
#define RIGHT_PIN 13

int leftlineval;
int midlineval;
int rightlineval;

bool linesensing;

int lineState[3] = {0, 0, 0};

void *setLineState(){
    int counter = 0; // just for testing'
    while(linesensing){
        delay(500);
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
        lineState[0] = leftlineval;
        lineState[1] = midlineval;
        lineState[2] = rightlineval;

        printf("Line State: %d %d %d\n", lineState[0], lineState[1], lineState[2]);

        // temporary, just for testing a limited amount of time
        counter++;
        if(counter >= 20){
            linesensing = false;
        }
    }
    return NULL;
}

int main(){
    pthread_t line_thread;
    linesensing = true;

        if(linesensing){
            int thread_ok = pthread_create(&line_thread, NULL, setLineState, NULL);
            if(thread_ok != 0){
                printf("\nLine thread creation failed.\n");
            }
            pthread_join(line_thread, NULL);
        }
        return 0;
}