/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:
 * Student ID:
 * Github ID:
 * Project:
 * File: distance.h
 * Description:
 * **************************************************************/
#ifndef distance_h
#define distance_h

#include <unistd.h>
#include <wiringPi.h>
#include <stdbool.h>

#define ECHOONE 5 //GPIO24/WPI 5
#define TRIGGERONE 6 //GPIO25/WPI 6
#define ECHOTWO 2 //GPIO27/WPI 2
#define TRIGGERTWO 0 //GPIO17/WPI 0
#define ECHOTHREE 28 //GPIO2O/WPI 28
#define TRIGGERTHREE 26 //GPIO12/WPI 26

int measurmentOne; //left
int measurmentTwo; //middle
int measurmentThree; //right

int threadOne;
int threadTwo;
int threadThree;

void *distanceOne;
void *distanceTwo;
void *distanceThree;
    
    
pthread_t one;
pthread_t two;
pthread_t three;

bool flagOne;
bool flagTwo;
bool flagThree;

void *distanceSensorOne(void *arg);
void *distanceSensorTwo(void *arg);
void *distanceSensorThree(void *arg);

void threadOneInIt();
void threadTwoInIt();
void threadThreeInIt();

void inItDistanceThreads();

#endif /* distance_h */


