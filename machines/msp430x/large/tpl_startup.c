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

#include "tpl_os.h"
#include "msp430.h"

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

#define ADDR_LOW  0x4400
#define ADDR_HIGH 0xffff

extern int main (void);

extern FUNC(void, OS_CODE) tpl_MPU_violation(void) {while(1);};

void tpl_continue_reset_handler(void)
{
	//---------3- Init .bss section
	extern unsigned __bss_start__ ;
	extern unsigned __bss_end__ ;
	unsigned * p = & __bss_start__ ;
	while (p != & __bss_end__) {
	  * p = 0 ;
	  p ++ ;
	}
	//---------4- Init .data section 
	extern unsigned __data_start ;
	extern unsigned __data_end ;
	extern unsigned __data_load_start ;
	unsigned * pSrc = & __data_load_start ;
	unsigned * pDest = & __data_start ;
	while (pDest != & __data_end) {
	  * pDest = * pSrc ;
	  pDest ++ ;
	  pSrc ++ ;
	}

	//program MPU so that flash below 0xFFFF should not be overwritten
	MPUCTL0  = 0xA500;         //password
	MPUSEGB2 = ADDR_HIGH >> 4; //only 16 most significant bits.
	MPUSEGB1 = ADDR_LOW  >> 4; //only 16 most significant bits.
	MPUSAM   = 0x0353;         // Segment 3 => -WR (3), segment 2, X-R (5), segment 1 -WR (3)
	MPUCTL0  = 0xA500 | MPUSEGIE | MPULOCK | MPUENA;         //it (SYSNMI)+lock+enable
	
//---------5- Exec constructors for global variables
  /*extern void (* __preinit_array_start) (void) ;
  extern void (* __preinit_array_end) (void) ;
  void (** ptr) (void) = & __preinit_array_start ;
  while (ptr != & __preinit_array_end) {
    (* ptr) () ;
    ptr ++ ;
  }
//---------6- Exécuter les routines d'initialisation de la section init_routine_array
   extern void (* __init_array_start) (void) ;
   extern void (* __init_array_end) (void) ;
   ptr = & __init_array_start ;
   while (ptr != & __init_array_end) {
     (* ptr) () ;
     ptr ++ ;
   }*/
//---------7- Exécuter le programme utilisateur
	main();
	while (1) ;
}
