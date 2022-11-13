#ifndef BUTTON_H
#define BUTTON_H

#define GRIPS_BUTTON        31

#define THUMB_BUTTON        53
#define INDEX_BUTTON        53
#define MIDDLE_BUTTON       53
#define RING_BUTTON         53

#define FORWARD_BUTTONS     53
#define BACKWARD_BUTTONS    53

void Button_Init(void);
int Button_CheckGrip(void);
int Button_CheckFingerState(int FingerID);

#endif
