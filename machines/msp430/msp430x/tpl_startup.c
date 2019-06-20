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

#include <sys/types.h>

void __attribute__((weak)) tpl_continue_reset_handler(void);

//initialise the data section
inline void data_init(unsigned int* from, unsigned int* section_begin, unsigned int* section_end);
extern unsigned int __data_load_start;
extern unsigned int __data_start;
extern unsigned int __data_end;

//clear the bss section
inline void bss_init(unsigned int* section_begin, unsigned int* section_end);
extern unsigned int __bss_start__;
extern unsigned int __bss_end__;

extern void __libc_init_array(void);

extern void __libc_fini_array(void);

extern int main(void);

extern void _exit(int);

/*extern unsigned __data_start ;
  extern unsigned __data_end ;
  extern unsigned __data_load_start ;
  unsigned * pSrc = & __data_load_start ;
  unsigned * pDest = & __data_start ;
  while (pDest != & __data_end) {
    * pDest = * pSrc ;
    pDest ++ ;
    pSrc ++ ;
  }*/

inline void __attribute__((always_inline)) data_init(unsigned int* from, unsigned int*section_begin, unsigned int* section_end) {
  unsigned int *p = section_begin;
  while(p < section_end) {
    *p++ = *from++;
  }
}

inline void __attribute__((always_inline)) bss_init(unsigned int* section_begin, unsigned int* section_end) {
  unsigned int *p = section_begin;
  while(p < section_end) {
    *p++ = 0;
  }
}

extern void (*__preinit_array_start[])(void) __attribute__((weak));
extern void (*__preinit_array_end[])(void) __attribute__((weak));
extern void (*__init_array_start[])(void) __attribute__((weak));
extern void (*__init_array_end[])(void) __attribute__((weak));
extern void (*__fini_array_start[])(void) __attribute__((weak));
extern void (*__fini_array_end[])(void) __attribute__((weak));

//---------5- Exec constructors for global variables
//  extern void (* __constructor_array_start) (void) ;
//  extern void (* __constructor_array_end) (void) ;
//  void (** ptr) (void) = & __constructor_array_start ;
//  while (ptr != & __constructor_array_end) {
//    (* ptr) () ;
//    ptr ++ ;
//  }

inline void __libc_init_array(void) {
  unsigned short/* size_t */ count;
  unsigned short/* size_t */ i;

  count = __preinit_array_end - __preinit_array_start;
  for(i = 0; i < count; i++) {
    __preinit_array_start[i]();
  }

  count = __init_array_end - __init_array_start;
  for(i = 0; i < count; i++) {
    __init_array_start[i]();
  }
}

inline void __libc_fini_array(void) {
  unsigned short/* size_t */ count;
  unsigned short/* size_t */ i;

  count = __fini_array_end - __fini_array_start;
  for(i = count; i > 0; i--) {
    __fini_array_start[i-1]();
  }
}

void /*__attribute__ ((section(".after_vectors")))*/ tpl_continue_reset_handler(void) {
  bss_init(&__bss_start__, &__bss_end__);

  __libc_init_array();

  int r = main();

  __libc_fini_array();

  _exit(r);
}

void /*__attribute__((section(".after_vectors")))*/ system_init() {
  data_init(&__data_load_start, &__data_start, &__data_end);
}

void* __attribute__((section(".preinit_array_sysinit")))
p_system_init = (void*) system_init;

/*
#include "tpl_os.h"
//#include "tpl_compiler.h"
//#include "tpl_os_interrupt_kernel.h"

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

//---------5- Exec constructors for global variables
//  extern void (* __constructor_array_start) (void) ;
//  extern void (* __constructor_array_end) (void) ;
//  void (** ptr) (void) = & __constructor_array_start ;
//  while (ptr != & __constructor_array_end) {
//    (* ptr) () ;
//    ptr ++ ;
//  }
//---------6- Exécuter les routines d'initialisation de la section init_routine_array
//   extern void (* __init_routine_array_start) (void) ;
//   extern void (* __init_routine_array_end) (void) ;
//   ptr = & __init_routine_array_start ;
//   while (ptr != & __init_routine_array_end) {
//     (* ptr) () ;
//     ptr ++ ;
//   }
//---------7- Exécuter le programme utilisateur
  main();
  while (1) ;
}
*/