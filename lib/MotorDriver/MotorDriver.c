/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:
 * Student ID:
 * Github ID:
 * Project:
 * File: MotorDriver.c
 * Description:
 * **************************************************************/
#include "MotorDriver.h"
#include "Debug.h"

void MotorInitOne(void){
    PCA9685_InitOne(0x41);
    PCA9685_SetPWMFreqOne(100);
}

void MotorInit(void) { PCA9685_Init(0x40);
    PCA9685_SetPWMFreq(100);
}

void MotorForward(UBYTE motor, UWORD speed)
{
if(motor == MOTORA){
        PCA9685_SetPwmDutyCycle(PWMA, speed);

             DEBUG("forward...\r\n");
            PCA9685_SetLevel(AIN1, 0);
            PCA9685_SetLevel(AIN2, 1);

}else if(motor == MOTORB){
    PCA9685_SetPwmDutyCycle(PWMB, speed);

         DEBUG("forward...\r\n");
        PCA9685_SetLevel(BIN1, 0);
        PCA9685_SetLevel(BIN2, 1);

}
    if(motor == MOTORC){
            PCA9685_SetPwmDutyCycle(PWMA, speed);

                 DEBUG("forward...\r\n");
                PCA9685_SetLevel(CIN1, 0);
                 PCA9685_SetLevel(CIN2, 1);

    }else if(motor == MOTORD){
        PCA9685_SetPwmDutyCycle(PWMB, speed);

             DEBUG("forward...\r\n");
            PCA9685_SetLevel(DIN1, 0);
            PCA9685_SetLevel(DIN2, 1);

    }
}

void MotorBackward(UBYTE motor, UWORD speed){
if(motor == MOTORA){
PCA9685_SetPwmDutyCycle(PWMA, speed);

DEBUG("backward \n");
PCA9685_SetLevel(AIN1, 1);
PCA9685_SetLevel(AIN2, 0);

}else if(motor == MOTORB){
    PCA9685_SetPwmDutyCycle(PWMB, speed);
    DEBUG("backward \n");
    PCA9685_SetLevel(BIN1, 1);
    PCA9685_SetLevel(BIN2, 0);
}
    if(motor == MOTORC){
    PCA9685_SetPwmDutyCycle(PWMA, speed);

    DEBUG("backward \n");
    PCA9685_SetLevel(CIN1, 1);
    PCA9685_SetLevel(CIN2, 0);

    }else if(motor == MOTORD){
        PCA9685_SetPwmDutyCycle(PWMB, speed);

        DEBUG("backward \n");
        PCA9685_SetLevel(DIN1, 1);
        PCA9685_SetLevel(DIN2, 0);
    }

}

void MotorStop(UBYTE motor)
{
    if(motor == MOTORA) {
      DEBUG("Motor stop \n");
        PCA9685_SetPwmDutyCycle(PWMA, 0);
    }else if(motor == MOTORB){
        DEBUG("Motor stop \n");
          PCA9685_SetPwmDutyCycle(PWMB, 0);
    }
    if(motor == MOTORC) {
      DEBUG("Motor stop \n");
        PCA9685_SetPwmDutyCycle(PWMC, 0);
    }else if(motor == MOTORD){
        DEBUG("Motor stop \n");
          PCA9685_SetPwmDutyCycle(PWMD, 0);
    }
}