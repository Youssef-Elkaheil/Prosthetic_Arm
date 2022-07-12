#ifndef MOTOR_H
#define MOTOR_H

/*  2 pins for each motor ( MOTOR_ID, MOTOR_ID + 1 )  */
#define THUMB_ID     24

#define INDEX_ID     26  

#define MIDDLE_ID    28 

#define RING_ID      30

void Motor_Init(void);
void Motor_MoveForward(int MotorID);
void Motor_MoveBackward(int MotorID); 

#endif
