/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:
 * Student ID:
 * Github ID:
 * Project:
 * File: yellowMotors.c
 * Description:
 * **************************************************************/
/*#include "yellowMotors.h"
void inItYellowMotors() {

  wiringPiSetup();

if (DEV_ModuleInit())
        exit(0);
    MotorInit();
    MotorInitOne();
}
void  motorsForward(int speed){
    MotorForward(MOTORA,speed);

    MotorForward(MOTORB,speed);
MotorForward(MOTORC,speed);

    MotorForward(MOTORD,speed);
}
 void motorsBackward(int speed){
    MotorBackward(MOTORA,speed);

    MotorBackward(MOTORB,speed);
MotorBackward(MOTORC,speed);

    MotorBackward(MOTORD,speed);
}


 void exitYellowMotors(){
    MotorStop(MOTORA);
    MotorStop(MOTORB);
MotorStop(MOTORC);
    MotorStop(MOTORD);

    DEV_ModuleExit();
}
int main(void){
speed = 40;
inItYellowMotors();
motorsForward(speed);
delay(1000);
 motorsBackward(speed);
delay(1000);
exitYellowMotors();
return 0;
}

*/
#include "yellowMotors.h"
void inItYellowMotors() {

  wiringPiSetup();

if (DEV_ModuleInit())
exit(0);
    MotorInit();
    MotorInitOne();
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