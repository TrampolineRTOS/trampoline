#include "tpl_os.h"
#include "LPC22xx.h"

/* Main */
#define LPC2294_CRYSTAL_FREQUENCY  (14745600)
#define LPC2294_PLL_FREQUENCY_MULTIPLIER (4)
#define LPC2294_APB_DIVIDER (1)
#define CCLK ((LPC2294_PLL_FREQUENCY_MULTIPLIER) * (LPC2294_CRYSTAL_FREQUENCY))
#define PCLK ((CCLK) / (LPC2294_APB_DIVIDER))

#define APP_Task_periodicTask_START_SEC_CODE
#include "tpl_memmap.h"
/** This routine is called by the interrupt handler, in supervisor mode.
 *  no application related code should be inserted here!
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

void initES()
{
	// set io pins for led P0.30
	PINSEL1 &= ~(1 << 28) ; // Configure P0.30 as I/O pin (by default, is AIN3)
	IO0DIR |= (1 << 30) ;  // pin P0.30 is an output, everything else is input after reset
	IO0SET =  1 << 30 ;  // led off
	InitTimer1();
}

FUNC(int, OS_APPL_CODE) main(void)
{            
	initES();
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

TASK(periodicTask)
{
	static int val = 0;
	if(val & 0x1) IO0CLR =  1 << 30 ;  // led on
	else    IO0SET =  1 << 30 ;  // led off
	val ^= 1;
    TerminateTask();
}
#define APP_Task_periodicTask_STOP_SEC_CODE
#include "tpl_memmap.h"

