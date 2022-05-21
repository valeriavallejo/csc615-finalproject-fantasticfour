/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:fantastic four
 * Student ID:
 * Github ID:
 * Project: robot car
 * File: MotorDriver.h
 * Description: this file allows each motor to connect and receive instructions from the motor HAT
 . Each motor is labled and is given a set of channels. 
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
//MOTORC         
#define PWMC        PCA_CHANNEL_6
#define CIN1        PCA_CHANNEL_7
#define CIN2        PCA_CHANNEL_8
//MOTORD
#define PWMD        PCA_CHANNEL_9
#define DIN1        PCA_CHANNEL_10
#define DIN2        PCA_CHANNEL_11

#define MOTORA       0  //MA1 &MA2
#define MOTORB       1    //MB1 & MB2
#define MOTORC        0    //MA1 &MA2
#define MOTORD         1   //MB1 & MB2

void MotorInitOne(void);
void MotorInit(void);
void MotorForward(UBYTE motor, UWORD speed);
void MotorBackward(UBYTE motor, UWORD speed);
void MotorStop(UBYTE motor);
