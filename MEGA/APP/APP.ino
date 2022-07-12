  #include "stepper.h"

#define VOLTMETER           A3

#define V_MOTOR             2

void setup() {
  Serial.begin(9600);

  pinMode(VOLTMETER, INPUT);

  /* Vibration motor */
  pinMode(V_MOTOR, OUTPUT);
}

void loop() {
  
}
