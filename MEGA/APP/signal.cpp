#include <Arduino.h>
#include "signal.h"
#include "PID.h"



void SIGNAL_Init(void)
{   pinMode(EMG,INPUT);
    pinMode(EMG_potentiometer,INPUT);

    pinMode(SIGNAL_BUTTON,INPUT);
}

int SIGNAL_Reading(void)
{ 
  int pot_read = analogRead(EMG_potentiometer); 
  
  
  int EMG_read = analogRead(EMG);
  delay(200);
  
  if (EMG_read != 0 )
  {
    
  EMG_read = PIDController_Update(EMG_read,analogRead(EMG));
  
  }
 
  if(EMG_read > pot_read || digitalRead(SIGNAL_BUTTON))
  {
    return 1;  
  }
  else
  {
    return 0;  
  }
}
