/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:fantastic four
 * Student ID:
 * Github ID:
 * Project:robot car
 * File: yellowMotors.h
 * Description:this file contains functions that control which direction a DC motor rotates. 
 * It contains functions that a allow a motor to rotate either forward or backward
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
//initializes all motors
void inItYellowMotors();
//exits all motors
void exitYellowMotors();

#endif 
