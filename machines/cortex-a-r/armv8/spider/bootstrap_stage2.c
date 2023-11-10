/**
 * @file bootstrap_stage2.c
 *
 * @section descr File description
 *
 * Second part of the bootstrap for Spider board
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

extern int main (void);

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

// Begin address for the .bss section; defined in linker script
extern unsigned int __bss_start__;
// End address for the .bss section; defined in linker script
extern unsigned int __bss_end__;

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
void tpl_bootstrap_stage2 ()
{
    /* Zero fill the bss segment */
    bss_init(&__bss_start__, &__bss_end__);

    /*
     * start application (which may start Trampoline via StartOS)
     */
    main ();

    /* ends in a loop, as we should not return from "reset call" */
    while (1);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
