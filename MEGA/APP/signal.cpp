#include <Arduino.h>
#include "signal.h"

void SIGNAL_Init(void)
{
    pinMode(EMG,INPUT);
    pinMode(EMG_POTENTIOMETER,INPUT);
    pinMode(SIGNAL_BUTTON,INPUT);
}

int SIGNAL_Reading(void)
{
  int error = analogRead(EMG_POTENTIOMETER) - analogRead(EMG);
  
  if(error < 0)
  {
    error = -1*error;  
  }
  if(error > 250 || digitalRead(SIGNAL_BUTTON))
  {
    return 1;  
  }
  else
  {
    return 0;  
  }
}
