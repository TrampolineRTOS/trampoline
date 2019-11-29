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

#include <stdint.h>
#include "tpl_os.h"
#include "tpl_clocks.h"
#include "msp430.h"

extern int main (void);

/*
 * Lower MPU boundary defined in link script
 */
extern unsigned TPL_MPU_B1_BOUNDARY;
/*
 * This MPU boundary is hard coded for the small model,
 * as we can't use pointers over 64kb
 */
static const uint32_t TPL_MPU_B2_BOUNDARY = 0x10000;

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
#if WITH_INIT_WITH_DMA == YES
#ifdef __MSP430_HAS_DMAX_3__
  DMACTL0 = 0;                          /* DMA0 trigger is manual             */
  DMA0SA = (uint16)&__data_load_start;  /* Source address for transfer        */
  DMA0DA = (uint16)&__data_start;       /* Dest address for the transfer      */
  /* Size for the transfer                                                    */
  DMA0SZ = ((uint16)&__data_end - (uint16)&__data_start) / 2;
  DMA0CTL = DMADT_1       /* Block transfer mode                              */
          | DMASRCINCR_3  /* Source address incremented                       */
          | DMADSTINCR_3  /* Destination address incremented                  */
          | DMASWDW       /* Word transfer                                    */
          | DMAEN         /* Enable                                           */
          | DMAREQ        /* Launch transfer                                  */
          /* 0x1F11 */;
#else
#warning "INIT_WITH_DMA is TRUE but the target does not have the expected DMA"
#endif
#elif WITH_INIT_WITH_DMA == NO
  unsigned *pSrc = &__data_load_start;
  unsigned *pDest = &__data_start;
  while (pDest != &__data_end) {
    *pDest = *pSrc;
    pDest++;
    pSrc++;
  }
#else
#error "Misconfiguration, WITH_INIT_WITH_DMA symbol is missing"
#endif

  /* start clock: default to 1MHz
   * (at least .bss section should be initialized)
   **/
  tpl_set_mcu_clock(CPU_FREQ_MHZ);

  /* MPU basic configuration:
   * The MPU uses 2 register to split the memory in 3 chunks:
   *  --------------- => high addr
   * |               |
   * |               |  Segment 3: RW
   * | RW FRAM       |  FRAM with R/W access (checkpointing)
   * |   (seg3)      |
   *  --------------- => MPU Segment 2 limit -> 0x10000
   * |               |
   * |               |  Segment 2: RX
   * | R/X FRAM      |  FRAM with R/eXecute access => code, interrupts
   * |   (seg2)      |  should include 0xFF80-FFFF not to "secure" the chip!
   * |               |
   *  -------------- => MPU Segment 1 limit (start of code in FRAM)
   * | FRAM for vars |
   * |   ---------   |
   * |     RAM       |
   * |   ---------   |  Segment 1: RW
   * |  peripherals  |
   * |    (seg1)     |
   *  ------------ =>low addr
   * program the MPU so that FRAM between the end of the SRAM and below 0xFFFF
   * are not be overwritten. This prevent program / constant modification and
   * JTAG lock modification in order to not brick the board.
   */
  MPUCTL0  = 0xA500;  /* password to unlock MPU                      */
  /* for MPUSEGx registers, we only give the 16 Most significant bits
   * but, the 6 lowest bits are not used. The minimal segment size is 1024 bytes
   * */
  MPUSEGB2 = (uint16_t)(TPL_MPU_B2_BOUNDARY >> 4);  /* high border (0x10000)  */
  MPUSEGB1 = (uint16_t)(&TPL_MPU_B1_BOUNDARY) >> 4; /* low border before code */
  MPUSAM   = 0x0353;  /* Seg3: -WR(3), seg2: X-R(5), seg1: -WR(3)    */
  MPUCTL0  =
     0xA500 |         /* password to unlock MPU                      */
     MPUSEGIE |       /* interrupt when MPU segment violation        */
     MPUENA;          /* enable the MPU                              */
  MPUCTL0_H = 0;      /* lock MPU (byte access required).pwd required */


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
