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

#include "timer.h"

/**
 *
 * InitTimer0
 *
 * Initialize Timer0 (see UM10114, chapter 15)
 *
 */
void InitTimer0(void)
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
    
    /* TODO : stop timer ?*/
    
}

/**
 * TIMER1InterruptServiceRoutine
 *
 */
void TIMER1InterruptServiceRoutine (void) {
    TIMER1_IR = 1 ; // Clears MR0 interrupt
    
}

/**
 * 
 * InitTimer1
 *
 * Iniialize timer for Trampoline (for tpl_tick_timer1)
 *
 */
void InitTimer1(void)
{
    
    //------------------- Init TIMER 1 (see UM10114, chapter 15)
    //--- 1. Reset Counter 0 (Timer Control Register)
    // Bit 0 : 0 (Disables counting)
    // Bit 1 : 1 (Reset)
    TIMER1_TCR = 2 ;
    //--- 2. Set Prescaler
    //    If PCLK = 4 * 14.7456 MHz
    //    We want T = 0.1 ms (counter is incremented every 100 µs), so F = 10 kHz
    //    So: PRESCALER = PCLK / F - 1 = 5897
    TIMER1_PR = ((PCLK) / 10000) - 1 ;
    //--- 3. Set Match Register 0
    //    We want an interrupt every milli-second (1ms = 10 * 100 µs)
    TIMER1_MR0 = 10 - 1 ;
    //--- 4. Set Count control Register
    //    Bits 1-0: 00 (timer mode)
    //    Bits 3-2: XX (any value, because timer mode)
    TIMER1_CCR = 0 ;
    //--- 5. Match Control Register
    //    Bit 0: 1 (interrupt on MR0 match)
    //    Bit 1: 1 (reset on MR0 match)
    //    Bit 2: 0 (do not stop on MR0 match)
    //    Bit 5-3: 000 (MR1 not used)
    //    Bit 8-6: 000 (MR2 not used)
    //    Bit 11-9: 000 (MR3 not used)
    TIMER1_MCR = 3 ;
    //--- 6. Use vector 12 for TIMER1 interrupt
    VICVectAddr12 = (unsigned long) TIMER1InterruptServiceRoutine ;
    VICVectCntl12 = 0x20 | 5 ;
  
  /*-------------------------------------
   * BE CAREFUL : 
   * 0x20 above is to enable the interrupt
   * and 5 is the 0x20 for the Timer1
   * interrrupt as you can see it again as
   * below
   * -------------------------------------*/
  
    //--- 7. Use IRQ for receiving characters
    //  TIMER1 gets interruption #5 (mask: 0x20)
    VICIntEnClr   = 0x20 ; // TimER1 interrupt generates IRQ
    VICIntEnable |= 0x20 ; // Enable TimER1 interrupt
    //--- 7. Start Counter 0 (Timer Control Register)
    // Bit 0 : 1 (Enables counting)
    // Bit 1 : 0 (no Reset)
    TIMER1_TCR = 1 ;          
    
}

/* End of file timer.c */
