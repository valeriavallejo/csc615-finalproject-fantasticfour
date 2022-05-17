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

void *distanceSensorOne(void *arg){
    long startT;
     long endT;
     long echoT;
    int centimeters;
     flagOne = true;
    
    wiringPiSetup();
    
    while(flagOne){
   

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
       

    if(centimeters <= 10){
        flagOne = false;
        pthread_exit((void*)centimeters);
    }
        
    }
}
void *distanceSensorTwo(void *arg){
    long startT;
     long endT;
     long echoT;
    int centimeters;
    flagTwo = true;
    
    wiringPiSetup();
    while(flagTwo){
   
    
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

        if(centimeters <= 10){
            flagTwo = false;
            pthread_exit((void*)centimeters);
            
        }
    }
}
void *distanceSensorThree(void *arg){
    long startT;
     long endT;
     long echoT;
    int centimeters;
     flagThree = true;
    
   wiringPiSetup();
    while(flagThree){
   
  
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
                

        if(centimeters <= 10){
            flagThree = false;
            pthread_exit((void*)centimeters);
            
        }
    }
}
void threadOneInIt(){
    threadOne = pthread_create(&one,NULL,distanceSensorOne,NULL);

}
void threadTwoInIt(){
    threadTwo = pthread_create(&two,NULL,distanceSensorTwo, NULL);

}
void threadThreeInIt(){
    threadThree = pthread_create(&three,NULL,distanceSensorThree,NULL);
     

}

void inItDistanceThreads(){
    
        
    wiringPiSetup();

    threadOneInIt();
   threadTwoInIt();
    threadThreeInIt();
    
    if(pthread_join(one, &distanceOne) == 0){
           measurmentOne = (int) distanceOne;
        printf("thread one : %d \n", measurmentOne);
        }
        if(pthread_join(two, &distanceTwo)== 0){
           measurmentTwo = (int) distanceTwo;
           printf("thread two : %d \n", measurmentTwo);

       }
      if (pthread_join(three, &distanceThree) == 0){
           measurmentThree = (int) distanceThree;
         printf("thread three : %d \n", measurmentThree);

       }
pthread_join(one, &distanceOne);

pthread_join(two, &distanceTwo);
pthread_join(three, &distanceThree);

      //  printf("thread one : %d \n", measurmentOne);
        //   printf("thread two : %d \n", measurmentTwo);
         //printf("thread three : %d \n", measurmentThree);

  
}





