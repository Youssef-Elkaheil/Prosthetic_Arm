#ifndef RGB_H
#define RGB_H

/* PWM pins */
#define RED_LED     24
#define GREEN_LED   25
#define BLUE_LED    22

typedef enum 
{
  Black   = 0,
  Blue    = 1,
  Green   = 2, 
  Cyan    = 3,
  Red     = 4,
  Magenta = 5,
  Yellow  = 6,
  White   = 7
}color;

void RGB_Init(void);
void RGB_ChangeColor(color newColor);

#endif
