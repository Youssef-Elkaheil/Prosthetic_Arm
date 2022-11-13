#include <Arduino.h>
#include "thermistor.h"

#define R1  ((float)7000)
#define c1  ((float)1.009249522e-03)
#define c2  ((float)2.378405444e-04) 
#define c3  ((float)2.019202697e-07)

int Vo;
float logR2, R2, T;

void Thermistor_Init(void)
{
  pinMode(THERMISTOR,INPUT);
}

float Thermistor_Reading(void) {
  Vo = analogRead(THERMISTOR);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 
  return T;
}
