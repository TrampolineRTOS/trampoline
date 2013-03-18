/**
 * @file lcd.c
 *
 * @section descr File description
 *
 * Trampoline core exported definitions
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date:$
 * $Rev:$
 * $Author:$
 * $URL:$
 */

#include "lcd.h"

extern void WaitTimer_100us(unsigned long time);

unsigned long data;

/**
 *
 * E_Pulse
 *
 * Set E (P0_29) to high level during 2ms (random) before
 * going back to low level
 *
 */
void E_Pulse(void)
{
  IO0SET = 0x20000000;      
  WaitTimer_100us(20);     
  IO0CLR = 0x20000000;      
}

/**
 *
 * LCDInit
 *
 * Initialise output ports required
 * Initialize LCD device by sending commands from the datasheet (sending a pulse
 * between each nibbles for a FOUR bit mode)
 * Select FOUR bit mode and initialize display (clean LCD, cursor start position...)
 *
 */
void InitLCD(void)
{
  /* Set D4, D5, D6, D7, LCD_LIGHT, RS, E , RW to output ports
      --> P0_4,P0_5,P0_6,P0_7,P0_10,P0_11,P0_28,P0_29= 1;
   */
  IO0DIR=0x30000CF0;

  /* Set RS (P0_28) to "instruction" mode (low level)
     Set E (P0_29) to low level
     Set R/W (P0_30) to low level
   */
  IO0CLR= 0x10000000;
  IO0CLR= 0x20000000;
  IO0CLR= 0x40000000;

  /* LCD initialization (for FOUR bit mode) from datasheet (sending a pulse between each nibbles) :
      - Wait 15ms
      - Send 0x03 and wait 5ms
      - Send 0x03 and wait 160us
      - Send 0x03 and wait 160us
      - Send 0x02 (to select FOUR bit mode)
      - Initialise LCD to display as you want...
   */
  WaitTimer_100us(150);

  IO0SET=0x00000010;
  IO0SET=0x00000020;
  E_Pulse();
  WaitTimer_100us(50);

  IO0SET=0x00000010;
  IO0SET=0x00000020;
  E_Pulse();
  WaitTimer_100us(2);

  IO0SET=0x00000010;
  IO0SET=0x00000020;
  E_Pulse();
  WaitTimer_100us(2);

  IO0SET=0x00000020;
  IO0CLR=0x00000010;
  E_Pulse();

  /* 'Set Interface Length' : 0 0 1 DL N F * *
      DL : Data interface length : 1 (8 bits)
      N : Number of Display lines : 1 (2 lignes) 
      F : Character Font : 0 (5x7)
  */
  LCDSendCommand(0x28);  

  /* 'Disable Display / Cursor' : 0 0 0 0 1 D C B
      D : Turn Display On : 0 (non)
      C : Turn Cursor On : 0 (non)
      B : Cursor Blink On : 0 (non)
   */
  LCDSendCommand(0x08);

  /* 'Clear Display'
  */
  LCDSendCommand(0x01);

  /* 'Set Cursor Move Direction' : 0 0 0 0 0 1 ID S
      ID : Increment Cursor after Each Byte Written to Display : 1 (oui)
      S : Shift Display When Byte Written : 0 (non) 
  */
  LCDSendCommand(0x06);

  /* 'Move Cursor / Shift Display' : 0 0 0 1 SC RL * *
      SC : Display Shift On : 1 (oui)
      RL : Direction of Shift : 1 (vers la droite)
  */
  LCDSendCommand(0x1C);

  /* 'Return Cursor and LCD to Home Position'
  */
  LCDSendCommand(0x02);

  /* 'Enable Display / Cursor' : 0 0 0 0 1 D C B
      D : Turn Display On : 1 (oui)
      C : Turn Cursor On : 0 (non)
      B : Cursor Blink On : 0 (non)
  */
  LCDSendCommand(0x0C);
     
}

/**
 *
 * LCDSendCommand
 *
 * Set RW to low level to tell the LCD the command what will arrive are instructions
 * and not text to display
 *
 */
void LCDSendCommand(unsigned long a)
{
  /* P0_28 = 1; --> set RS port to 0 -> display set to command mode */
  IO0CLR = 0x10000000;
  
  /* get high 4 bits */
  data = 0xffffff0f | a;
  IO0CLR |= 0x000000f0;
  IO0SET = (IO0SET | 0x000000f0) & data;
  E_Pulse();
  
  /* get low 4 bits */
  data = (a << 4) & 0x000000f0;
  IO0CLR |= 0x000000f0;
  IO0SET = (IO0SET & 0xffffff0f) | data;
  E_Pulse();
    
}

/**
 *
 * LCDSendChar
 *
 * Set RW to high level to tell the LCD the command what will arrive are text to
 * display and not intructions
 *
 */
void LCDSendChar(unsigned long a)
{
  /* P0_28 = 1; --> set RS port to 1 -> display set to data mode */
  IO0SET = 0x10000000;                     
  
  data = 0xffffff0f | a;
  IO0CLR |= 0x000000f0;
  IO0SET = (IO0SET | 0x000000f0) & data;
  E_Pulse();
  
  data = (a << 4) & 0x000000f0;
  IO0CLR |= 0x000000f0;
  IO0SET = (IO0SET & 0xffffff0f) | data;
  E_Pulse();

}

/**
 *
 * LCDSendTxt
 *
 * Send several caracters with LCDSendChar function
 *
 */
void LCDSendTxt(char* a)
{
  char i=0;
  while(a[i]!='\0') 
  {
    LCDSendChar(a[i]);
    // TODO : check if the line is full and go to the other one (clean if lcd full)
    i++;
  }
  
    
}

/* End of file lcd.c */
