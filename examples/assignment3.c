/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:Celia Ramirez
 * Student ID:918689985
 * Github ID:celiarr
 * Project: Assignment 3 - Motors & Motor Shield*
 * File:assignment3.c
 * Description: this file contains a program that controls a DC MOTOR . The program 
 * waits  until there is a voltage in a gpio pin. When it reads a voltage from this pin
 * it starts the program  that makes a DC motor turn. 
 *
 * **************************************************************/
#include "assignment3.h"

#define PUSHBUTTON 15

int main(void) {

  wiringPiSetup();
  pinMode(PUSHBUTTON, INPUT);

  while (1) {

    if (digitalRead(PUSHBUTTON) == HIGH) {
      printf("Button pressed!\n");

      if (DEV_ModuleInit())
        exit(0);

      MotorInit();

      int forwardSpeed = 100;
      int backwardSpeed = 20;

      for (int i = 0; i <= 9; i++) {
        if (i == 0) {
          MotorForward(MOTOR, forwardSpeed);
          delay(2000);
          forwardSpeed = forwardSpeed - 10;
        } else if (forwardSpeed == 10) {
          forwardSpeed = forwardSpeed + 5;
          MotorForward(MOTOR, forwardSpeed);
          delay(3000);
        } else {
          MotorForward(MOTOR, forwardSpeed);
          delay(3000);
          forwardSpeed = forwardSpeed - 10;
        }
      }

      MotorForward(MOTOR, 0);
      delay(1000);

      for (int i = 0; 0 <= 9; i++) {
        if (i == 0) {
          MotorBackward(MOTOR, 15);
          delay(3000);
        } else {
          MotorBackward(MOTOR, backwardSpeed);
          delay(3000);
          backwardSpeed = backwardSpeed + 10;
        }if(i == 9){
        MotorStop(MOTOR);
        exit(0);
}
      }
        
    } 
  }
  DEV_ModuleExit();
  return 0;
}
