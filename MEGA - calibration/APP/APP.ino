#include "stepper.h"
#include "signal.h"
#include "button.h"
#include"RGB.h"
char command = '0';

int THUMB_count = 0;
int INDEX_count = 0;
int MIDDLE_count = 0;
int RING_count = 0;

void setup()
{
  SIGNAL_Init();
  Motor_Init();
  Button_Init();
  RGB_Init();
  Serial.begin(9600);
}

void loop()
{
  /* switch to open and close the hand */
  int Signal = digitalRead(30);
  /* print the selected grip */
  Serial.print(Button_CheckGrip());
  /* change color of the RGB led */
  RGB_ChangeColor(Button_CheckGrip() + 1);
  /* if the hand is opened/
  /* the fingers will close */
  if(Signal == 1)
  {
    
  switch(Button_CheckGrip())
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
  /* if the hand is closed */
  /* the fingers will close */
  else if(Signal == 0)
    {
    switch(Button_CheckGrip())
    {
    case 0:

        if(THUMB_count>0)
        {
          THUMB_count--;
          Motor_MoveBackward(THUMB_ID);
        }  
       if(INDEX_count>0)
        {
          INDEX_count--;
         Motor_MoveBackward(INDEX_ID);
        }
          
       if(RING_count>0)
        {
          RING_count--;
          Motor_MoveBackward(RING_ID);
        }
      
    break;
    
        case 1:

        if(THUMB_count>0)
        {
          THUMB_count--;
          Motor_MoveBackward(THUMB_ID);
        }  
       if(INDEX_count>0)
        {
          INDEX_count--;
         Motor_MoveBackward(INDEX_ID);
        }

      
    break;

      case 2:
       if(INDEX_count>0)
        {
          INDEX_count--;
         Motor_MoveBackward(INDEX_ID);
        }

       if(RING_count>0)
        {
          RING_count--;
          Motor_MoveBackward(RING_ID);
        }
      
    break;
    }  
    }
    
//  if(Serial.available())
//  {
//    command = Serial.read();
//  }
//  switch(command)
//  {
//    case '0':
//      /* Stop*/
//    break;
//    case '1':
//      THUMB_count++;
//      Motor_MoveForward(THUMB_ID);
//    break;
//    
//    case '2':
//      INDEX_count++;
//      Motor_MoveForward(INDEX_ID);
//    break;
//    
//    case '3':
//      
//      
//      
////      MIDDLE_count++;
//      if(THUMB_count<500)
//      {
//        THUMB_count++;
//        Motor_MoveForward(THUMB_ID);   
//      }
//      if(INDEX_count<780)
//      {
//        INDEX_count++;  
//        Motor_MoveForward(INDEX_ID);
//      }
//      if(RING_count<650){
//        RING_count++;
//        Motor_MoveForward(RING_ID);
//      }
////      Motor_MoveForward(MIDDLE_ID);
//    break;
//    
//    case '4':
//      RING_count++;
//      Motor_MoveForward(RING_ID);
//    break;
//    
//    case '5':
//      THUMB_count--;
//      Motor_MoveBackward(THUMB_ID); 
//    break;
//    
//    case '6':
//      INDEX_count--;
//      Motor_MoveBackward(INDEX_ID);
//    break;
//    
//    case '7':
//      MIDDLE_count--;
//      Motor_MoveBackward(MIDDLE_ID);
//    break;
//    
//    case '8':
//      RING_count--;
//      Motor_MoveBackward(RING_ID);
//    break;
//    
//    case '9':
//      if(THUMB_count>0)
//      {
//        THUMB_count--;
//        Motor_MoveBackward(THUMB_ID);   
//      }
//      if(INDEX_count>0)
//      {
//        INDEX_count--;  
//        Motor_MoveBackward(INDEX_ID);
//      }
//      if(RING_count>0){
//        RING_count--;
//        Motor_MoveBackward(RING_ID);
//      }
//  }
//  Serial.print(THUMB_count);
//  Serial.print(',');
//  
//  Serial.print(INDEX_count);
//  Serial.print(',');
//  
//  Serial.print(MIDDLE_count);
//  Serial.print(',');
//  
//  Serial.println(RING_count);
}
