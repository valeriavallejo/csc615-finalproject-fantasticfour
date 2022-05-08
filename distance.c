#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define TRIGGER 15
#define ECHO 16

int main(void) {
  long startT;
  long endT;
  long echoT;
  wiringPiSetup();
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  while (digitalRead(ECHO) == LOW)
    ;
  startT = micros();
  while (digitalRead(ECHO) == HIGH)
    ;
  endT = micros();
  echoT = endT - startT;
  int centimeters = echoT * 0.034 / 2;
  printf("Distance:  %dcm\n", centimeters);

  return 0;
}
