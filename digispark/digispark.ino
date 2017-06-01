/*************************************
* This code is written by Laurens Wuyts
* For questions: laurens.wuyts@gmail.com
* 
* Corrected by Ivan Rusakov
* 
* Microcontroller: ATtiny85
* Dev board:       Digispark
* 
*************************************/

/**** Define Remote control keys ****/
#define Power     194
#define Mute      226
#define Record    242
#define Prev      216
#define Next      200
#define Pause     42
#define Info      10
#define Menu      120
#define Up        114
#define Down      122
#define Left      16
#define Right     32
#define OK        168
#define Home      68
#define Zoom      248
#define Return    72
#define Vol_Up    136
#define Vol_Dwn   184
#define Audio     88
#define Subtitle  152
#define Ch_Up     40
#define Ch_Dwn    104
#define Red       186
#define Green     154
#define Yellow    224
#define Blue      138
#define Rotate    210
#define Rew       56
#define Fwd       8
#define PIP       74
#define Key_1     66
#define Key_2     130
#define Key_3     2
#define Key_4     98
#define Key_5     162
#define Key_6     34
#define Key_7     82
#define Key_8     146
#define Key_9     18
#define Key_0     178
#define Key_Del   250
#define Key_F     90

/************************************/

#include "TrinketHidCombo.h"

uint8_t situation = 0;
uint8_t START = 0;
uint8_t x = 0;
uint8_t BIT = 0;
uint8_t Id = 0;
uint8_t Id_inv = 0;
uint8_t Data = 0;
uint8_t Data_back = 0;
uint8_t Data_inv = 0;
uint8_t Repeat = 0;
uint8_t sended = 0;

uint16_t Time_old = 0;
uint16_t Time = 0;
uint16_t TimeDelta = 0;
 
void setup(void) {
  /* Use INT0(P2) on the Digispark */
  attachInterrupt(0, IR_Read, FALLING);
  
  pinMode(1,OUTPUT);
  digitalWrite(1,LOW);

  TrinketHidCombo.begin();
  delay(300);
}
 
void loop(void) {
  if(sended == 1) {
    /* Assign functions to the buttons */
    if(Data_back == Power) {
      TrinketHidCombo.pressKey(0, KEYCODE_S);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Mute) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_MUTE);
    } else if(Data_back == Record) {
      TrinketHidCombo.pressKey(0, KEYCODE_K);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Prev) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_SCAN_PREV_TRACK);
    } else if(Data_back == Next) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_SCAN_NEXT_TRACK);
    } else if(Data_back == Pause) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_PLAYPAUSE);
    } else if(Data_back == Info) {
      TrinketHidCombo.pressKey(0, KEYCODE_I);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Menu) {
      TrinketHidCombo.pressKey(0, KEYCODE_M);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Up) {
      TrinketHidCombo.pressKey(0, KEYCODE_ARROW_UP);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Down) {
      TrinketHidCombo.pressKey(0, KEYCODE_ARROW_DOWN);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Left) {
      TrinketHidCombo.pressKey(0, KEYCODE_ARROW_LEFT);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Right) {
      TrinketHidCombo.pressKey(0, KEYCODE_ARROW_RIGHT);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == OK) {
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Home) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_KB_MENU);
    } else if(Data_back == Zoom) {
      TrinketHidCombo.pressKey(0, KEYCODE_Z);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Return) {
      TrinketHidCombo.pressKey(0, KEYCODE_BACKSPACE);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Vol_Up) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
    } else if(Data_back == Vol_Dwn) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
    } else if(Data_back == Audio) {
      TrinketHidCombo.pressKey(0, KEYCODE_A);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Subtitle) {
      TrinketHidCombo.pressKey(0, KEYCODE_T);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Ch_Up) {
      TrinketHidCombo.pressKey(0, KEYCODE_ARROW_UP);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Ch_Dwn) {
      TrinketHidCombo.pressKey(0, KEYCODE_ARROW_DOWN);
      TrinketHidCombo.pressKey(0, 0);
    /*} else if(Data_back == Red) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
    } else if(Data_back == Green) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
    } else if(Data_back == Yellow) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
    } else if(Data_back == Blue) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
    } else if(Data_back == Rotate) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);*/
    } else if(Data_back == Rew) {
      TrinketHidCombo.pressKey(0, KEYCODE_R);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Fwd) {
      TrinketHidCombo.pressKey(0, KEYCODE_F);
      TrinketHidCombo.pressKey(0, 0);
    /*} else if(Data_back == PIP) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);*/
    } else if(Data_back == Key_1) {
      TrinketHidCombo.pressKey(0, KEYCODE_1);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_2) {
      TrinketHidCombo.pressKey(0, KEYCODE_2);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_3) {
      TrinketHidCombo.pressKey(0, KEYCODE_3);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_4) {
      TrinketHidCombo.pressKey(0, KEYCODE_4);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_5) {
      TrinketHidCombo.pressKey(0, KEYCODE_5);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_6) {
      TrinketHidCombo.pressKey(0, KEYCODE_6);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_7) {
      TrinketHidCombo.pressKey(0, KEYCODE_7);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_8) {
      TrinketHidCombo.pressKey(0, KEYCODE_8);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_9) {
      TrinketHidCombo.pressKey(0, KEYCODE_9);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_0) {
      TrinketHidCombo.pressKey(0, KEYCODE_0);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_Del) {
      TrinketHidCombo.pressKey(0, KEYCODE_DELETE);
      TrinketHidCombo.pressKey(0, 0);
    } else if(Data_back == Key_F) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_STOP);
    } 
    sended = 0;
  } else {
      TrinketHidCombo.poll();
  }
}

/* Read the IR code */
void IR_Read(void) {
  digitalWrite(1,HIGH);
  Time = micros();
  if (Time_old != 0) {
    TimeDelta = Time - Time_old;
    if ((TimeDelta > 12000)&&(TimeDelta < 16000)) {
      START = 1;
      x = 0;
      situation = 1;
      Id = 0;
      Id_inv = 0;
      Data = 0;
      Data_inv = 0;
    } else if ((TimeDelta > 10000)&&(TimeDelta < 12000)) {
      situation = 2; // repeat
    } else if ((TimeDelta > 1500)&&(TimeDelta < 2500)) {
      situation = 3; //"1"
      BIT = 1;
    } else if ((TimeDelta > 1000)&&(TimeDelta < 1500)) {
      situation = 3; //"0"
      BIT = 0;
    } else situation = 5; 
    if (situation == 3) {
      if (x < 8) {
        Id |= BIT;
        if (x < 7) Id <<= 1;  
        x++;
      } else if (x < 16) {
        Id_inv |= BIT;
        if (x < 15) Id_inv <<= 1;
        x++;
      } else if (x < 24) {
        Data |= BIT;
        if (x < 23) Data <<= 1;
        x++;
      } else if (x < 32) {
        Data_inv |= BIT;
        if (x < 31) {
          Data_inv <<= 1;
        } else {
          
          /* DO SOMETHING HERE */
          sended = 1;
          
          Data_back = Data;
          Repeat = 0;
        }
        x++;
      }
    } else if (situation == 2) {
      if(Repeat == 1) {
        
        /* DO SOMETHING HERE */
        sended = 1;
        
      } else {
        Repeat = 1;
      }
    }
  }
  Time_old = Time;
  digitalWrite(1,LOW);
}
