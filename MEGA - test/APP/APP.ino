#include "stepper.h"
#include "signal.h"
#include "button.h"
#include"RGB.h"
#include"PID.h"
char command = '0';

int THUMB_count = 0;
int INDEX_count = 0;
int RING_count = 0;

float pidOUTPUT ;
float potentiometer ;
int Grips = 0;
int critical = 0;
void Grip_start(int Grips);
int Motor_positions = 0;
int flag = 1;
void setup()
{
  SIGNAL_Init();
  Motor_Init();
  Button_Init();
  RGB_Init();
  Serial.begin(9600);
//  delay(5000);
}

void loop()
{
// int PIDout = PIDController_Update(350,analogRead(EMG));
// int EMGS = analogRead(EMG);
// Serial.print("EMG ");
// Serial.println(EMGS);
// Serial.println(',');
// Serial.print("PIDout ");
// Serial.println(PIDout);
// delay(100);
// Serial.println(Button_CheckGrip());
 
//  if(Serial.available())
//  {
//    command = Serial.read();
//  }
//
//      if(PIDout<700 || flag == 1)
//      {
//        for(int i = 0;i<800;i++)
//        {
//          if(THUMB_count<500)
//          {
//            THUMB_count++;
//            Motor_MoveForward(THUMB_ID);   
//          }
//          if(INDEX_count<780)
//          {
//            INDEX_count++;  
//            Motor_MoveForward(INDEX_ID);
//          }
//          if(RING_count<650){
//            RING_count++;
//            Motor_MoveForward(RING_ID);
//          }
//        }
//        flag = 0;
//      }
//      else if(PIDout<700 || flag == 0)
//      {
//        for(int i = 0;i<800;i++)
//        { 
//          if(THUMB_count>0)
//          {
//            THUMB_count--;
//            Motor_MoveBackward(THUMB_ID);   
//          }
//          if(INDEX_count>0)
//          {
//            INDEX_count--;  
//            Motor_MoveBackward(INDEX_ID);
//          }
//          if(RING_count>0)
//          {
//            RING_count--;
//            Motor_MoveBackward(RING_ID);
//          }
//        }
//        flag = 1;
//      }
//  
//  switch(command)
//  {
//    case '0':
//      /* Stop*/
//    break;
//    case '1':
//      Grip_start(0);
//    break;
//    case '2':
//      Grip_Release(0);
//    break;
//    case '3':
//      Grip_start(1);
//    break;
//    case '4':
//      Grip_Release(1);
//    break;
//    case '5':
//      Grip_start(2);
//    break;
//    case '6':
//      Grip_Release(2);
//    break;
////  }
//  Serial.print(THUMB_count);
//  Serial.print(',');
//  
//  Serial.print(INDEX_count);
//  Serial.print(',');
//  
//  Serial.println(RING_count);
}

void Grip_start(int Grip)
{
  switch(Grip)
  {
    case 0:

        if(THUMB_count<500)
        {
          THUMB_count++;
          Motor_MoveForward(THUMB_ID);
        }  
       if(INDEX_count<700)
        {
         INDEX_count++;
         Motor_MoveForward(INDEX_ID);
        }          
       if(RING_count<680)
        {
          RING_count++;
          Motor_MoveForward(RING_ID);
        }
      
    break;
    
    case 1:

        if(THUMB_count<500)
        {
          THUMB_count++;
          Motor_MoveForward(THUMB_ID);
        }  
       if(INDEX_count<700)
        {
          INDEX_count++;
          Motor_MoveForward(INDEX_ID);
        }

      
    break;

      case 2:
      
       if(INDEX_count<700)
        {
          INDEX_count++;
         Motor_MoveForward(INDEX_ID);
        }
          
       if(RING_count<680)
        {
          RING_count++;
          Motor_MoveForward(RING_ID);
        }
    break;
    
  }  
}

void Grip_Release(int Grip)
{
  switch(Grip)
  {
    case 0:

        if(THUMB_count<500)
        {
          THUMB_count--;
          Motor_MoveBackward(THUMB_ID);
        }  
       if(INDEX_count<700)
        {
          INDEX_count--;
         Motor_MoveBackward(INDEX_ID);
        }
          
       if(RING_count<680)
        {
          RING_count--;
          Motor_MoveBackward(RING_ID);
        }
      
    break;
    
        case 1:

        if(THUMB_count<500)
        {
          THUMB_count--;
          Motor_MoveBackward(THUMB_ID);
        }  
       if(INDEX_count<700)
        {
          INDEX_count--;
         Motor_MoveBackward(INDEX_ID);
        }
          
       if(RING_count<680)
        {
          RING_count--;
          Motor_MoveBackward(RING_ID);
        }
      
    break;

      case 2:

        if(THUMB_count<500)
        {
          THUMB_count--;
          Motor_MoveBackward(THUMB_ID);
        }  
       if(INDEX_count<700)
        {
          INDEX_count--;
         Motor_MoveBackward(INDEX_ID);
        }

       if(RING_count<680)
        {
          RING_count--;
          Motor_MoveBackward(RING_ID);
        }
      
    break;
  }  
  
}
