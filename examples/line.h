/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:fantastic four
 * Student ID: 920594217
 * Github ID: valeriavallejo
 * Project:robot car
 * File: line.h
 * Description: This file contains a program that holds the includes and 
 * global variables for the line.c program.
 * **************************************************************/

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

// holds data for current state of the bot on the line
int lineState[3] = {0, 0, 0};
/*
   linestate[0] is the left sensor's state
   linestate[1] is the middle sensor's state
   linestate[2] is the right sensor's state
*/