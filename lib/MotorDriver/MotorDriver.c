/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:Celia Ramirez
 * Student ID:918689985
 * Github ID:celiarr
 * Project: Assignment 3 - Motors & Motor Shield*
 * File: MotorDriver.c
 *  Description:
 * **************************************************************/
#include "MotorDriver.h" 
#include "Debug.h"


void MotorInit(void) { PCA9685_Init(0x40); PCA9685_SetPWMFreq(100);
}

void MotorForward(UBYTE motor, UWORD speed)
{
if(motor == MOTOR){    
        PCA9685_SetPwmDutyCycle(PWM, speed);
           
             DEBUG("forward...\r\n");
            PCA9685_SetLevel(AIN1, 0);
            PCA9685_SetLevel(AIN2, 1);
     
}}

void MotorBackward(UBYTE motor, UWORD speed){
if(motor == MOTOR){ 
PCA9685_SetPwmDutyCycle(PWM, speed);

DEBUG("backward \n");
PCA9685_SetLevel(AIN1, 1);
PCA9685_SetLevel(AIN2, 0);

}

}
void MotorStop(UBYTE motor)
{
    if(motor == MOTOR) {
      DEBUG("Motor stop \n");
        PCA9685_SetPwmDutyCycle(PWM, 0);
    } 
}
