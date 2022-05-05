#include <stdio.h>
#include <string.h>
#include <wiringPi.h>

#define LEFT_PIN 10
#define MID_PIN 10
#define RIGHT_PIN 10

int leftVal;
int midVal;
int rightVal;

void threadInit();