#ifndef BUTTON_H
#define BUTTON_H

#define GRIPS_BUTTON        4

#define THUMB_BUTTON        3
#define INDEX_BUTTON        5
#define MIDDLE_BUTTON       6
#define RING_BUTTON         2

#define FORWARD_BUTTONS     7
#define BACKWARD_BUTTONS    8

void Button_Init(void);
int Button_CheckGrip(void);
int Button_CheckFingerState(int FingerID);

#endif
