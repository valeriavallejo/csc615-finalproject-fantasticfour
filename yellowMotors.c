/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:
 * Student ID:
 * Github ID:
 * Project:
 * File: yellowMotors.c
 * Description:
 * **************************************************************/
#include "yellowMotors.h"
void inItYellowMotors() {

  wiringPiSetup();
  
if (DEV_ModuleInit())
        exit(0);
    MotorInit();
}
void  motorsForward(int speed){
    MotorForward(MOTORA,speed);
    
    MotorForward(MOTORB,speed);
}
 void motorsBackward(int speed){
    MotorBackward(MOTORA,speed);
    
    MotorBackward(MOTORB,speed);
}
  
    
 void exitYellowMotors(){
    MotorStop(MOTORA);
    MotorStop(MOTORB);
    
  DEV_ModuleExit();
}
//delay(1000); use in main file

