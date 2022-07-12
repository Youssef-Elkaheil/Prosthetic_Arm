#include <Arduino.h>
#include "RGB.h"

void RGB_Init(void)
{
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void RGB_ChangeColor(color newColor)
{
  switch(newColor)
  {
     case Black :
       digitalWrite(RED_LED, LOW);
       digitalWrite(GREEN_LED, LOW);
       digitalWrite(BLUE_LED, LOW);
     break;
 
     case Blue :
       digitalWrite(RED_LED, LOW);
       digitalWrite(GREEN_LED, LOW);
       digitalWrite(BLUE_LED, HIGH);     
     break;
     
     case Green :
       digitalWrite(RED_LED, LOW);
       digitalWrite(GREEN_LED, HIGH);
       digitalWrite(BLUE_LED, LOW);     
     break;
     
     case Cyan :
       digitalWrite(RED_LED, LOW);
       digitalWrite(GREEN_LED, HIGH);
       digitalWrite(BLUE_LED, HIGH);     
     break;
     
     case Red :
       digitalWrite(RED_LED, HIGH);
       digitalWrite(GREEN_LED, LOW);
       digitalWrite(BLUE_LED, LOW);     
     break;
     
     case Magenta :
       digitalWrite(RED_LED, HIGH);
       digitalWrite(GREEN_LED, LOW);
       digitalWrite(BLUE_LED, HIGH);     
     break;
     
     case Yellow :
       digitalWrite(RED_LED, HIGH);
       digitalWrite(GREEN_LED, HIGH);
       digitalWrite(BLUE_LED, LOW);     
     break;
 
     case White :
       digitalWrite(RED_LED, HIGH);
       digitalWrite(GREEN_LED, HIGH);
       digitalWrite(BLUE_LED, HIGH);     
     break;
     
     default:
       Serial.println("[ERROR]: Invalid Color");
     break;
  }  
}
