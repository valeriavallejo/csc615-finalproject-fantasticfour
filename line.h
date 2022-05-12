#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <pthread.h>

#define LEFT_PIN 10
#define MID_PIN 10
#define RIGHT_PIN 10

// protect from threads trying to write and access at same time
// main threads waits for 3 threads in here ? or vice versa ?
bool linesensing;

// args for thread_create:
struct LineSensor {
    int value;
    int pin;
}

struct LineState {
    int left_val;
    int mid_val;
    int right_val;
}

void threadInit();
struct LineState getLineState();
void freeLines();

struct LineSensor *left;
struct LineSensor *mid;
struct LineSensor *right;
