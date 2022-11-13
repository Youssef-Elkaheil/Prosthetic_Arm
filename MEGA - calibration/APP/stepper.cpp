#include <Arduino.h>
#include "stepper.h"
#define STEP    1000
void Motor_Init(void)
{
  pinMode(THUMB_ID, OUTPUT);
  pinMode(THUMB_ID + 1, OUTPUT);

  pinMode(INDEX_ID, OUTPUT);
  pinMode(INDEX_ID + 1, OUTPUT);

  pinMode(MIDDLE_ID, OUTPUT);
  pinMode(MIDDLE_ID + 1, OUTPUT);

  pinMode(RING_ID, OUTPUT);
  pinMode(RING_ID + 1, OUTPUT); 
}

void Motor_MoveForward(int MotorID)
{
  digitalWrite(MotorID ,LOW);
  digitalWrite(MotorID + 1,LOW);
  delayMicroseconds(STEP);
  digitalWrite(MotorID,HIGH);
  digitalWrite(MotorID + 1,LOW);
  delayMicroseconds(STEP);
  digitalWrite(MotorID, HIGH);
  digitalWrite(MotorID + 1,HIGH);
  delayMicroseconds(STEP);
  digitalWrite(MotorID,LOW);
  digitalWrite(MotorID + 1,HIGH);
  delayMicroseconds(STEP);  
//  digitalWrite(MotorID + 1,HIGH);
//  delayMicroseconds(STEP);  
//  digitalWrite(MotorID + 1,LOW);
//  delayMicroseconds(STEP);  

}

void Motor_MoveBackward(int MotorID) 
{
  digitalWrite(MotorID, LOW);
  digitalWrite(MotorID + 1,HIGH);
  delayMicroseconds(STEP);    
  digitalWrite(MotorID, HIGH);
  digitalWrite(MotorID + 1,HIGH);
  delayMicroseconds(STEP);
  digitalWrite(MotorID, HIGH);
  digitalWrite(MotorID + 1,LOW);
  delayMicroseconds(STEP);
  digitalWrite(MotorID ,LOW);
  digitalWrite(MotorID + 1,LOW);
  delayMicroseconds(STEP);  
//  digitalWrite(MotorID + 1,HIGH);
//  delayMicroseconds(STEP);  
//  digitalWrite(MotorID + 1,LOW);
//  delayMicroseconds(STEP); 
}
 
