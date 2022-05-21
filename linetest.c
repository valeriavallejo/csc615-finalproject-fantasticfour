#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <pthread.h>
#include <stdbool.h>

#include <time.h>

#define LEFT_PIN 23// 13
#define MID_PIN 24//19
#define RIGHT_PIN 29//21

int leftlineval;
int midlineval;
int rightlineval;

bool linesensing;

int lineState[3] = {1, 1, 1};
void *setLineState(){
    wiringPiSetup();
    int counter = 0; // just for testing'
    digitalWrite(LEFT_PIN, HIGH);
    digitalWrite(MID_PIN, HIGH);
    digitalWrite(RIGHT_PIN, HIGH);
    while(linesensing){
        delay(500);
        if(digitalRead(LEFT_PIN))
        {
            digitalWrite(LEFT_PIN, HIGH);
            leftlineval = 1;
            printf("val updated");
        }
        else{
            digitalWrite(LEFT_PIN, LOW);
            leftlineval = 0;
        }

        if(digitalRead(MID_PIN))
        {
            digitalWrite(MID_PIN, HIGH);
            midlineval = 1;
        }
        else{
            digitalWrite(MID_PIN, LOW);
            midlineval = 0;
        }

        if(digitalRead(RIGHT_PIN))
        {
            digitalWrite(RIGHT_PIN, HIGH);
            rightlineval = 1;
        }
        else{
            digitalWrite(RIGHT_PIN, LOW);
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
    wiringPiSetup();
    // IR SENSOR
    pinMode(LEFT_PIN, OUTPUT);
    pinMode(MID_PIN, OUTPUT);
    pinMode(RIGHT_PIN, OUTPUT);

     digitalWrite(LEFT_PIN, HIGH);
     digitalWrite(MID_PIN, HIGH);
     digitalWrite(RIGHT_PIN, HIGH);

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