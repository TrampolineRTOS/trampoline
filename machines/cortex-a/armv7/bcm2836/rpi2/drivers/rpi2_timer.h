/**
 * @file timer.h
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
#ifndef _RPI2_TIMER_H_
#define _RPI2_TIMER_H_

void timer_init();

#include "lpc22xx.h"
#include "check-lpc2200-timing-settings.h" //for PCLK
//#include "check-lpc2294-timing-settings.h" //for PCLK

void InitTimer0(void);
void InitTimer1(void);
void WaitTimer_100us(unsigned long time);

#endif /* _RPI2_TIMER_H_ */

/* End of file timer.h */
