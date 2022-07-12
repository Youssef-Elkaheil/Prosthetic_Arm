#include <Arduino.h>
#include "button.h"


void Button_Init(void)
{
  pinMode(GRIPS_BUTTON,INPUT);
    
  pinMode(THUMB_BUTTON,INPUT);
  pinMode(INDEX_BUTTON,INPUT);
  pinMode(MIDDLE_BUTTON,INPUT);
  pinMode(RING_BUTTON,INPUT);

  pinMode(FORWARD_BUTTONS,OUTPUT);
  pinMode(BACKWARD_BUTTONS,OUTPUT);
  
  digitalWrite(FORWARD_BUTTONS,LOW);
  digitalWrite(BACKWARD_BUTTONS,HIGH);
}
int Button_CheckGrip(void)
{
  static int Grip = 0;
  int debounce;
  int flag = 1;
  if(digitalRead(GRIPS_BUTTON) == 0 )
  {
    for(debounce =0;debounce<20;debounce++)
    {
      delay(1);
      if(digitalRead(GRIPS_BUTTON) == 0 )
      {
        flag = 0;
        break;
      }
    }
    
    if(flag == 1)
    {
      Grip += 1;
      Grip = Grip%3;
    }       
   } 
  return Grip;
}
int Button_GetForwardKeysPressed(int FingerID)
{
  int pressedkeys = 0;
  digitalWrite(FORWARD_BUTTONS,HIGH);
  digitalWrite(BACKWARD_BUTTONS,LOW);
  pressedkeys = digitalRead(THUMB_BUTTON) +2*digitalRead(INDEX_BUTTON) +4*digitalRead(MIDDLE_BUTTON) +8*digitalRead(RING_BUTTON);
  return pressedkeys;
}

int Button_GetBackwardKeysPressed(int FingerID)
{
  int pressedkeys = 0;
  digitalWrite(FORWARD_BUTTONS,LOW);
  digitalWrite(BACKWARD_BUTTONS,HIGH);
  pressedkeys = digitalRead(THUMB_BUTTON) +2*digitalRead(INDEX_BUTTON) +4*digitalRead(MIDDLE_BUTTON) +8*digitalRead(RING_BUTTON);
  return pressedkeys;
}
