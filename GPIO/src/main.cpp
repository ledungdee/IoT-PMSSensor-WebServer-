#include <Arduino.h>

#define RL1 32
//#define RL2 34


void setup() {
  pinMode(RL1, OUTPUT);
  digitalWrite(RL1, LOW);
 // pinMode(RL2, OUTPUT);
  digitalWrite(RL1,HIGH);
  delay(3000);
  digitalWrite(RL1, LOW);
  delay(3000);
  digitalWrite(RL1,HIGH);
  delay(3000);
  digitalWrite(RL1, LOW);
//   digitalWrite(RL2,HIGH);
//   delay(3000);
//   digitalWrite(RL2, LOW);
}

void loop() 
{
  // put your main code here, to run repeatedly:
}