#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <pthread.h>

#define LEFT_PIN 10
#define MID_PIN 10
#define RIGHT_PIN 10

// args for thread_create:
struct LineSensor {
    int value;
    int pin;
}

void threadInit();

