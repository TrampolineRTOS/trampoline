/**
 * @section descr File description
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright DG for function and data structures documentation and THUMB2 port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 */

#include <stdint.h>
#include "tpl_os.h"
#include "tpl_clocks.h"
#include "msp430.h"
#include "tpl_app_define.h"
#if WITH_CHECKPOINTING == YES
#  include "tpl_chkpt_checkpoint_kernel.h"
#  include "tpl_chkpt_io.h"
#  include "tpl_chkpt_adc.h"
#endif

extern int main (void);
extern int restart_main (void);

/*
 * Lower MPU boundary defined in link script
 */
extern unsigned TPL_MPU_B1_BOUNDARY;
/*
 * This MPU boundary is hard coded for the small model,
 * as we can't use pointers over 64kb
 */
static const uint32_t TPL_MPU_B2_BOUNDARY = 0x3E800;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_MPU_violation(void) {
  while(1);
};

/** copy a memory chunk of 'size' bytes
 *  from @ src (in FRAM)
 *  to   @ dst (either SRAM or FRAM)
 *  It uses the DMA if WITH_INIT_WITH_DMA is set.
 */
FUNC(void, OS_CODE) memInit(
		P2VAR(void,AUTOMATIC,OS_CONST) src,
		P2VAR(void,AUTOMATIC,OS_CONST) dst,
		  VAR(uint16_t,AUTOMATIC)      size)
{
#if WITH_INIT_WITH_DMA == YES
#ifdef __MSP430_HAS_DMAX_3__
  DMACTL0 = 0;             /* DMA0 trigger is manual             */
  DMA0SA = (uint16)src;    /* Source address for transfer        */
  DMA0DA = (uint16)dst;    /* Dest address for the transfer      */
  DMA0SZ = size >> 1;      /* transfer size (in 16-bit words)    */
  DMA0CTL = DMADT_1        /* Block transfer mode                */
          | DMASRCINCR_3   /* Source address incremented         */
          | DMADSTINCR_3   /* Destination address incremented    */
          | DMASWDW        /* Word transfer                      */
          | DMAEN          /* Enable                             */
          | DMAREQ         /* Launch transfer                    */
          /* 0x1F11 */;
#else
#warning "INIT_WITH_DMA is TRUE but the target does not have the expected DMA"
#endif
#elif WITH_INIT_WITH_DMA == NO
  unsigned *pSrc = src;
  unsigned *pDest = dst;
  unsigned *pDestMax = dst+size;
  while (pDest != pDestMax) {
    *pDest = *pSrc;
    pDest++;
    pSrc++;
  }
#else
#error "Misconfiguration, WITH_INIT_WITH_DMA symbol is missing"
#endif
}

FUNC(void, OS_CODE) tpl_continue_reset_handler(void)
{
#if WITH_CHECKPOINTING == YES
  tpl_init_io_for_reset_handler();
#endif

  /* Init .bss section */
  extern unsigned __bss_start__;
  extern unsigned __bss_end__;
  unsigned *p = &__bss_start__;
  while (p != &__bss_end__) {
    *p = 0;
    p++;
  }
  /* Init .data section */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
  extern unsigned __data_load_start;
  extern unsigned __data_start;
  extern unsigned __data_end;
  memInit(
    &__data_load_start,
    &__data_start,
    (uint16_t)&__data_end-(uint16_t)&__data_start
  );
#pragma GCC diagnostic pop //"-Wpointer-to-int-cast"

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
   * | code/const    |  start with initial value of FRAM vars (not to be updated)
   * |               |
   *  -------------- => MPU Segment 1 limit
   * | FRAM for vars | (if there are vars in FRAM, a multiple of 1024 bytes
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
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
  MPUSEGB2 = (uint16_t)(TPL_MPU_B2_BOUNDARY >> 4);  /* high border (0x10000)  */
  MPUSEGB1 = (uint16_t)(&TPL_MPU_B1_BOUNDARY) >> 4; /* low border before code */
#pragma GCC diagnostic pop
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

#if WITH_CHECKPOINTING == YES
  tpl_adc_init_simple();
  if (tpl_cold_startup() //button pushed during startup ?
      || (tpl_checkpoint_buffer == NO_CHECKPOINT) // no checkpoint available ?
      ) {
    /* Exec user program */
    main();
  }
  else {
    /* Exec user program */
    restart_main();
  }
#else
  main();
#endif

  /* should not get there */
  /* so we don't call global destructors... */
  while(1);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* MPU basic configuration:
 * The MPU uses 2 register to split the memory in 3 chunks:
 *  ------------  
 * |            |
 * | RW FRAM    |  FRAM with R/W access
 * |   (seg3)   |
 *  ------------ => MPU Segment 2 limit = 0xFFFF
 * |            |
 * | R/X FRAM   |  FRAM with R/eXecute access => code, interrupts
 * |   (seg2)   |  should include 0xFF80-FFFF to prevent to "secure" the chip!
 * |            |
 *  ------------ => MPU Segment 1 limit = 0x4400 (start of FRAM)
 * |     RAM    |
 * |            |
 * | peripheral |
 * |   (seg1)   |
 *  ------------  
 */

// #define ADDR_LOW  0x4400
// #define ADDR_HIGH 0xffff

// extern int main (void);

// extern FUNC(void, OS_CODE) tpl_MPU_violation(void) {while(1);};

// void tpl_continue_reset_handler(void)
// {
// 	//---------3- Init .bss section
// 	extern unsigned __bss_start__ ;
// 	extern unsigned __bss_end__ ;
// 	unsigned * p = & __bss_start__ ;
// 	while (p != & __bss_end__) {
// 	  * p = 0 ;
// 	  p ++ ;
// 	}
// 	//---------4- Init .data section 
// 	extern unsigned __data_start ;
// 	extern unsigned __data_end ;
// 	extern unsigned __data_load_start ;
// 	unsigned * pSrc = & __data_load_start ;
// 	unsigned * pDest = & __data_start ;
// 	while (pDest != & __data_end) {
// 	  * pDest = * pSrc ;
// 	  pDest ++ ;
// 	  pSrc ++ ;
// 	}

// 	//program MPU so that flash below 0xFFFF should not be overwritten
// 	MPUCTL0  = 0xA500;         //password
// 	MPUSEGB2 = ADDR_HIGH >> 4; //only 16 most significant bits.
// 	MPUSEGB1 = ADDR_LOW  >> 4; //only 16 most significant bits.
// 	MPUSAM   = 0x0353;         // Segment 3 => -WR (3), segment 2, X-R (5), segment 1 -WR (3)
// 	MPUCTL0  = 0xA500 | MPUSEGIE | MPULOCK | MPUENA;         //it (SYSNMI)+lock+enable
	
// //---------5- Exec constructors for global variables
//   /*extern void (* __preinit_array_start) (void) ;
//   extern void (* __preinit_array_end) (void) ;
//   void (** ptr) (void) = & __preinit_array_start ;
//   while (ptr != & __preinit_array_end) {
//     (* ptr) () ;
//     ptr ++ ;
//   }
// //---------6- Exécuter les routines d'initialisation de la section init_routine_array
//    extern void (* __init_array_start) (void) ;
//    extern void (* __init_array_end) (void) ;
//    ptr = & __init_array_start ;
//    while (ptr != & __init_array_end) {
//      (* ptr) () ;
//      ptr ++ ;
//    }*/
// //---------7- Exécuter le programme utilisateur
// 	main();
// 	while (1) ;
// }
