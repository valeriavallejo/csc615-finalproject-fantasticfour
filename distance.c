/**************************************************************
 * Class: CSC-615-01 Spring 2022
 * Name:
 * Student ID:
 * Github ID:
 * Project:
 * File: distance.c
 * Description:
 * **************************************************************/
#include "distance.h"
int measurmentOne;
int measurmentTwo;
int measurmentThree;

void *distanceSensorOne(void *arg){
    long startT;
     long endT;
     long echoT;
    int centimeters;
    
    wiringPiSetup();
    
    pinMode(TRIGGERONE, OUTPUT);
    pinMode(ECHOONE,INPUT);
    
    digitalWrite(TRIGGERONE, LOW);
      delayMicroseconds(2);
      digitalWrite(TRIGGERONE, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIGGERONE, LOW);
    
      while (digitalRead(ECHOONE) == LOW)
        ;
      startT = micros();
      while (digitalRead(ECHOONE) == HIGH)
        ;
      endT = micros();
      echoT = endT - startT;
      centimeters = echoT * 0.034 / 2;
    pthread_exit((void*)centimeters);
}
void *distanceSensorTwo(void *arg){
    long startT;
     long endT;
     long echoT;
    int centimeters;
    
    wiringPiSetup();
    
    pinMode(TRIGGERTWO, OUTPUT);
    pinMode(ECHOTWO,INPUT);
    
    digitalWrite(TRIGGERTWO, LOW);
      delayMicroseconds(2);
      digitalWrite(TRIGGERTWO, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIGGERTWO, LOW);
    
      while (digitalRead(ECHOTWO) == LOW)
        ;
      startT = micros();
      while (digitalRead(ECHOTWO) == HIGH)
        ;
      endT = micros();
      echoT = endT - startT;
       centimeters = echoT * 0.034 / 2;
    pthread_exit((void*)centimeters);
}
void *distanceSensorThree(void *arg){
    long startT;
     long endT;
     long echoT;
    int centimeters;
    
    wiringPiSetup();
    
    pinMode(TRIGGERTHREE, OUTPUT);
    pinMode(ECHOTHREE,INPUT);
    
    digitalWrite(TRIGGERTHREE, LOW);
      delayMicroseconds(2);
      digitalWrite(TRIGGERTHREE, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIGGERTHREE, LOW);
      while (digitalRead(ECHOTHREE) == LOW)
        ;
      startT = micros();
      while (digitalRead(ECHOTHREE) == HIGH)
        ;
      endT = micros();
      echoT = endT - startT;
        centimeters = echoT * 0.034 / 2;
    pthread_exit((void*)centimeters);
}

int getMeasurmentOne(void){
    return measurmentOne;
}
int  getMeasurmentTwo(void){
    return measurmentTwo;
}
int  getMeasurmentThree(void){
    return measurmentThree;
}

void inItDistanceThreads(){
   void *distanceOne;
   void *distanceTwo;
   void *distanceThree;
    
    pthread_t one;
    pthread_t two;
    pthread_t three;
    
    wiringPiSetup();
    
    int threadOne = pthread_create(&one,NULL,distanceSensorOne,NULL);
   int threadTwo = pthread_create(&two,NULL,distanceSensorTwo, NULL);
   int threadThree = pthread_create(&three,NULL,distanceSensorThree,NULL);
    
    pthread_join(one, &distanceOne);
    pthread_join(two, &distanceTwo);
   pthread_join(three, &distanceThree);
    
    measurmentOne = (int) distanceOne;
    measurmentTwo = (int) distanceTwo;
    measurmentThree = (int) distanceThree;
    
}
