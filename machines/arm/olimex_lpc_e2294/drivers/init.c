/**
 * @file init.c
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

#include "LPC22XX.h"
#include "timer.h"
#include "lcd.h"

void Init(void)
{
    
	/* To enable LCD communication */    
    PINSEL0 = 0;
	PINSEL1 = 0;
    
    InitTimer();
    
    InitLCD();
    
}

/* End of file init.c */
