/**
 * @file lcd.h
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
#ifndef LCD_H
#define LCD_H

#include "lpc22xx.h"

#define		DD_RAM_ADDR   0x00000080	//LCD 1 row
#define		DD_RAM_ADDR2	0x000000C0	//LCD 2 row
#define		CLR_DISP      0x00000001	
#define		DISP_ON       0x0000000C	
#define		DISP_OFF      0x00000008	
#define		CUR_HOME      0x00000002
#define		CUR_OFF       0x0000000C
#define   CUR_ON_UNDER  0x0000000E
#define   CUR_ON_BLINK  0x0000000F
#define   CUR_BACKSPACE 0x00000010
#define   CUR_SPACE     0x00000014
#define		CUR_UP        0x00000080	
#define		CUR_DOWN      0x000000C0
#define   ENTER         0x000000C0

void E_Pulse(void);
void InitLCD(void);
void LCDSendCommand(unsigned long a);
void LCDSendChar(unsigned long a);
void LCDSendTxt(char* a);

#endif /* LCD_H */

/* End of file lcd.h */
