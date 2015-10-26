/**
 * @file extint.h
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

#ifndef EXTINT_H
#define EXTINT_H

#include "lpc22xx.h"
#include "check-lpc2200-timing-settings.h" //for PCLK
#include "lcd.h"

/**
 *
 * InitExtInt
 *
 *
 */
void InitExtInt(void);

/**
 *
 * InitEInt0
 *
 *
 */
void InitEInt0(void);

/**
 *
 * EINT0InterruptServiceRoutine
 *
 *
 */
void EINT0InterruptServiceRoutine(void);

/**
 *
 * InitEInt2
 *
 *
 */
void InitEInt2(void);

/**
 *
 * EINT0InterruptServiceRoutine
 *
 *
 */
void EINT2InterruptServiceRoutine(void);

#endif /* EXTINT_H */

/* End of file extint.h */
