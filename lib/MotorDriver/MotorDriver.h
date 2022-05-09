/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:
 * Student ID:
 * Github ID:
 * Project:
 * File: MotorDriver.h
 * Description:
 * **************************************************************/
#ifndef __TB6612FNG_
#define __TB6612FNG_

#include "DEV_Config.h"
#include "PCA9685.h"
//MOTORA
#define PWMA        PCA_CHANNEL_0
#define AIN1        PCA_CHANNEL_1
#define AIN2        PCA_CHANNEL_2
//MOTORB
#define PWMB        PCA_CHANNEL_5
#define BIN1        PCA_CHANNEL_3
#define BIN2        PCA_CHANNEL_4

#define MOTORA       0  //MA1 &MA2
#define MOTORB       1    //MB1 & MB2


void MotorInit(void);
void MotorForward(UBYTE motor, UWORD speed);
void MotorBackward(UBYTE motor, UWORD speed);
void MotorStop(UBYTE motor);

#endif
