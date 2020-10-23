/**
 * @section descr File description
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 */

#include "tpl_os.h"
#include "tpl_clocks.h"
#include "msp430.h"

extern int main (void);

/* TODO put this in OS_CODE */

FUNC(void, OS_CODE) tpl_MPU_violation(void) {
  while(1);
};

void tpl_continue_reset_handler(void)
{
  /* Init .bss section */
  extern unsigned __bss_start__;
  extern unsigned __bss_end__;
  unsigned *p = &__bss_start__;
  while (p != &__bss_end__) {
    *p = 0;
    p++;
  }
  /* Init .data section */
  extern unsigned __data_start;
  extern unsigned __data_end;
  extern unsigned __data_load_start;
  unsigned *pSrc = &__data_load_start;
  unsigned *pDest = &__data_start;
  while (pDest != &__data_end) {
    *pDest = *pSrc;
    pDest++;
    pSrc++;
  }
  /* start clock: default to 1MHz 
   * (at least .bss section should be initialized)
   **/
  tpl_set_mcu_clock(CPU_FREQ_MHZ);

#if WITH_BASIC_MPU == YES
  /* MPU basic configuration:
   * The MPU uses 2 register to split the memory in 3 chunks:
   *  ------------
   * |            |
   * | RW FRAM    |  FRAM with R/W access
   * |   (seg3)   |
   *  ------------ => MPU Segment 2 limit
   * |            |
   * | R/X FRAM   |  FRAM with R/eXecute access => code, interrupts
   * |   (seg2)   |  should include 0xFF80-FFFF to prevent to "secure" the chip!
   * |            |
   *  ------------ => MPU Segment 1 limit (start of FRAM)
   * |     RAM    |
   * |            |
   * | peripheral |
   * |   (seg1)   |
   *  ------------
   * program the MPU so that FRAM between the end of the SRAM and below 0xFFFF
   * are not be overwritten. This prevent program / constant modification and
   * JTAG lock modification in order to not brick the board.
   */
  MPUCTL0  = 0xA500;           /* password to unlock MPU                      */
  MPUSEGB2 = B2_BOUNDARY >> 4; /* only 16 most significant bits               */
  MPUSEGB1 = B1_BOUNDARY >> 4; /* only 16 most significant bits.              */
  MPUSAM   = 0x0353;           /* Seg3: -WR(3), seg2: X-R(5), seg1: -WR(3)    */
  MPUCTL0  =
     0xA500 |                  /* password to unlock MPU                      */
     MPUSEGIE |                /* interrupt when MPU segment violation        */
     MPULOCK |                 /* lock the MPU                                */
     MPUENA;                   /* enable the MPU                              */

#endif

  /* Exec constructors for global objects (c++)*/
  extern void (* __ctors_start) (void) ;
  extern void (* __ctors_end) (void) ;
  void (** ptr) (void) = & __ctors_start ;
  while (ptr != & __ctors_end) {
    (* ptr) () ;
    ptr ++ ;
  }
  
  /* Exec user program */
  main();

  /* should not get there */
  /* so we don't call global destructors... */
  while(1);
}
