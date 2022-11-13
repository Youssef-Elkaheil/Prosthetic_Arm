#ifndef MOTOR_H
#define MOTOR_H

/*  2 pins for each motor ( MOTOR_ID, MOTOR_ID + 1 )  */
#define THUMB_ID     2

#define INDEX_ID     6 

#define MIDDLE_ID    8 

#define RING_ID      4

void Motor_Init(void);
void Motor_MoveForward(int MotorID);
void Motor_MoveBackward(int MotorID); 

#endif
