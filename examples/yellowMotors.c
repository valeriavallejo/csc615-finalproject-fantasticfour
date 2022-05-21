/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:fantastic four
 * Student ID:
 * Github ID:
 * Project:robot car
 * File: yellowMotors.c
 * Description:this file contains functions that control which direction a DC motor rotates. 
 * It contains functions that a allow a motor to rotate either forward or backward
 * **************************************************************/
#include "yellowMotors.h"
#include "yellowMotors.h"

//initializes the motor hat used to manage the DC motors
void inItYellowMotors() {

  wiringPiSetup();

if (DEV_ModuleInit())
exit(0);
    MotorInit();
    MotorInitOne();
}
//this functions makes a motor go forward at the speed entered 
void  motorsForward(int speed){
    MotorForward(MOTORA,speed);

    MotorForward(MOTORB,speed);
  MotorForward(MOTORC,speed);

    MotorForward(MOTORD,speed);
}
//this function makes a motor go backwards at the speed entered
 void motorsBackward(int speed){
    MotorBackward(MOTORA,speed);

    MotorBackward(MOTORB,speed);
    MotorBackward(MOTORC,speed);

    MotorBackward(MOTORD,speed);
}

//uninitializes all motors 
 void exitYellowMotors(){
    MotorStop(MOTORA);
    MotorStop(MOTORB);
MotorStop(MOTORC);
    MotorStop(MOTORD);
  DEV_ModuleExit();
  }
//test case for the motors
int main(void){
speed = 40;
inItYellowMotors();
motorsForward(speed);
delay(10000);
 motorsBackward(speed);
delay(10000);
exitYellowMotors();
return 0;
}
