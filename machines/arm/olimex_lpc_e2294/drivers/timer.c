/**
 * @file timer.c
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
#include "check-lpc2294-timing-settings.h" //for PCLK

/**
 *
 * InitTimer
 *
 * Initialize Timer0 (see UM10114, chapter 15)
 *
 */
void InitTimer(void)
{
    /* --- 1. Reset Counter 0 (Timer Control Register)
        Bit 0 : 0 (Disables counting)
        Bit 1 : 1 (Reset)
     */
    TIMER0_TCR = 2 ;
    /* --- 2. Set Prescaler
        If PCLK = 4 * 14.7456 MHz
        We want T = 0.1 ms (counter is incremented every 100 µs), so F = 10 kHz
        So: PRESCALER = PCLK / F - 1 = 5897
     */
    TIMER0_PR = ((PCLK) / 10000) - 1 ;
    /* --- 3. Set Count control Register
        Bits 1-0: 00 (timer mode)
        Bits 3-2: XX (any value, because timer mode)
     */
    TIMER0_CCR = 0 ;
    /* --- 4. Match Control Register
        Bit 0: 1 (interrupt on MR0 match)
        Bit 1: 1 (reset on MR0 match)
        Bit 2: 0 (do not stop on MR0 match)
        Bit 5-3: 000 (MR1 not used)
        Bit 8-6: 000 (MR2 not used)
        Bit 11-9: 000 (MR3 not used)
     */
    TIMER0_MCR = 0 ;
}

/**
 *
 * WaitTimer_100us
 *
 * Wait a multiple of 100us
 *
 */
void WaitTimer_100us(unsigned long time)
{
    /* Reset timer */
    TIMER0_TCR = 2 ; 
    /* Start timer */
    TIMER0_TCR = 1 ; 
    /* Wait until flag is set */
    while(TIMER0_TC < time){};
    
}

/* End of file timer.c */
