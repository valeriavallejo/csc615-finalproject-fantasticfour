#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <pthread.h>

#define LEFT_PIN 5
#define MID_PIN 6
#define RIGHT_PIN 13

// protect from threads trying to write and access at same time
// main threads waits for 3 threads in here ? or vice versa ?
bool linesensing;

// holds data for current state, replaces LineState
/*
   linestate[0] is the left sensor's state
   linestate[1] is the middle sensor's state
   linestate[2] is the right sensor's state
*/
string lineState = "000";

// args for thread_create:
struct LineSensor {
    int value;
    int pin;
}

/* struct LineState {
    int left_val;
    int mid_val;
    int right_val;
} */

void threadInit();
struct LineState getLineState();
void freeLines();

struct LineSensor *left;
struct LineSensor *mid;
struct LineSensor *right;


/* ****** WITHOUT EACH LINE SENSOR HAVING A THREAD
int leftlineval;
int midlineval;
int rightlineval;
*/