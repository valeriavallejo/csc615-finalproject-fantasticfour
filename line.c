/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:fantastic four
 * Student ID: 920594217
 * Github ID: valeriavallejo
 * Project:robot car
 * File: line.c
 * Description: This file contains the code that the line_thread in main
 * will run. The loop checks whether the IR sensor sees the line or not
 * and updates lineState array with the values to later be evaluated
 * in instructions.c
 * **************************************************************/

#include "line.h"

void *setLineState(){
    int counter = 0; // just for testing'
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

/*int main(){
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
    return 0;
}*/
