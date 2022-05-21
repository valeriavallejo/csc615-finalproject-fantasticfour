/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:fantastic four
 * Student ID:
 * Github ID:
 * Project:robot car
 * File: distance.h
 * Description:this file contains a program that runs three threads that control
 three ultrasonic sensors. Each thread exits when they detect an object
 that is less than or equal to 10cm.
 * **************************************************************/
#ifndef distance_h
#define distance_h

#include <unistd.h>
#include <wiringPi.h>
#include <stdbool.h>
//left ultrasonic sensor
#define ECHOONE 5 //GPIO24/WPI 5 
#define TRIGGERONE 6 //GPIO25/WPI 6
//middle ultrasonic sensor
#define ECHOTWO 2 //GPIO27/WPI 2
#define TRIGGERTWO 0 //GPIO17/WPI 0
//right ultrasonic sensor
#define ECHOTHREE 28 //GPIO2O/WPI 28
#define TRIGGERTHREE 26 //GPIO12/WPI 26

int threadOne;
int threadTwo;
int threadThree;

void *distanceOne;
void *distanceTwo;
void *distanceThree;
    
    
pthread_t one;
pthread_t two;
pthread_t three;
//used to help exit the methods being run my the threads
bool flagOne;
bool flagTwo;
bool flagThree;
///a method for each thread to run
void *distanceSensorOne(void *arg);
void *distanceSensorTwo(void *arg);
void *distanceSensorThree(void *arg);
//each function initializes a thread
void threadOneInIt();
void threadTwoInIt();
void threadThreeInIt();
//initializes all three threads
void inItDistanceThreads();

#endif /* distance_h */