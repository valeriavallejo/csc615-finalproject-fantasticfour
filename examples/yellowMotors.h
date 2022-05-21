/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:
 * Student ID:
 * Github ID:
 * Project:
 * File: yellowMotors.h
 * Description:
 * **************************************************************/
#ifndef yellowMotors_h
#define yellowMotors_h

#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
#include <wiringPi.h>
#include "DEV_Config.h"
#include <time.h>
#include "MotorDriver.h"
#include "PCA9685.h"

int speed;

void motorsForward(int speed);
void motorsBackward(int speed);

void inItYellowMotors();
void exitYellowMotors();
#endif