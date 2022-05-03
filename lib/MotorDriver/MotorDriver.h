/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:Celia Ramirez
 * Student ID:918689985
 * Github ID:celiarr
 * Project: Assignment 3 - Motors & Motor Shield*
 * File: MotorDriver.h
 *  Description:
 * **************************************************************/
#ifndef __TB6612FNG_
#define __TB6612FNG_

#include "DEV_Config.h"
#include "PCA9685.h"

#define PWM        PCA_CHANNEL_0
#define AIN1        PCA_CHANNEL_1
#define AIN2        PCA_CHANNEL_2

#define MOTOR       0

void MotorInit(void);
void MotorForward(UBYTE motor, UWORD speed);
void MotorBackward(UBYTE motor, UWORD speed);
void MotorStop(UBYTE motor);

#endif
