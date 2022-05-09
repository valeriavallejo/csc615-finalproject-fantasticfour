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


  DEV_ModuleExit();
  return 0;
}
