/**
 * @file init.h
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
#ifndef _RPI2_INIT_H_
#define _RPI2_INIT_H_

#include "lpc22xx.h"
#include "timer.h"
#include "lcd.h"
#include "extint.h"

/**
 * Init
 *
 * Initialize the timer, the lcd and
 * the push buttons in external interrupts
 *
 */
void Init(void);

/* Here is a list of the Interrupt vectors used :
 * 7 -> EINT0
 * 8 -> EINT2
 * 12 -> TIMER1
 *
 */

#endif /* _RPI2_INIT_H_ */
