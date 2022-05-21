#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <pthread.h>
#include <stdbool.h>

#define LEFT_PIN 5
#define MID_PIN 6
#define RIGHT_PIN 13

bool linesensing;

int leftlineval;
int midlineval;
int rightlineval;

// holds data for current state
int lineState[3] = {0, 0, 0};
/*
   linestate[0] is the left sensor's state
   linestate[1] is the middle sensor's state
   linestate[2] is the right sensor's state
*/