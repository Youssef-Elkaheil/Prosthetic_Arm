#include <Arduino.h>
#include "signal.h"
#include "PID.h"
void SIGNAL_Init(void)
{
    PIDController_Init();
    pinMode(EMG,INPUT);
    pinMode(EMG_POTENTIOMETER,INPUT);
    pinMode(SIGNAL_BUTTON,INPUT);
}

int SIGNAL_Reading(void)
{
  int PIDout = PIDController_Update(350,analogRead(EMG));
  int flag = 0;
  if(digitalRead(SIGNAL_BUTTON) == 0 )
  {
    delay(50);
    if(digitalRead(SIGNAL_BUTTON) == 0 )
  {
    flag = 1;
  }
  if(flag)
  {
    return 1;  
  }
  }
  return 0;
 }
