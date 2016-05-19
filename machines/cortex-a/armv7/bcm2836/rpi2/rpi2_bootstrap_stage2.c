/**
 * @file olimex_bootstrap_stage2.c
 *
 * @section descr File description
 *
 * Second part of the bootstrap for OLIMEX
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
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */
 #include "tpl_os.h"
 #include "emblib.h"
 #include "rpi2_uart.h"
#include "bcm2836.h"

extern int main (void);
extern void initialize_lpc2200_pll(void);

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

// Begin address for the .bss section; defined in linker script
extern unsigned int __bss_start__;
// End address for the .bss section; defined in linker script
extern unsigned int __bss_end__;

inline void
__attribute__((always_inline)) data_init(unsigned int* from, unsigned int* section_begin,
    unsigned int* section_end)
{
  // Iterate and copy word by word.
  // It is assumed that the pointers are word aligned.
  unsigned int *p = section_begin;
  while (p < section_end)
    *p++ = *from++;
}

inline void __attribute__((always_inline))
bss_init(unsigned int* section_begin, unsigned int* section_end)
{
  // Iterate and clear word by word.
  // It is assumed that the pointers are word aligned.
  unsigned int *p = section_begin;
  while (p < section_end)
    *p++ = 0;
}

/* this function should not return as
 * it is called straight after reset
 */
void tpl_armv7_bootstrap_stage2 ()
{
    /* initialisation */
    // initialize_lpc2200_pll();
    /*
     * initialіze memory segments
     */
    /* BSS section should be zeroed */
    // Zero fill the bss segment
    bss_init(&__bss_start__, &__bss_end__);

    /* DATA section initial values copied from ROM
      */

    /*
     * start application (which may start Trampoline via StartOS)
     */
    main ();

    /* ends in a loop, as we should not return from "reset call" */
    while (1);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file olimex_bootstrap_stage2.c */
