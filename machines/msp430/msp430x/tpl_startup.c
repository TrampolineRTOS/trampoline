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

extern int main (void);

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
	---------4- Init .data section 
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
