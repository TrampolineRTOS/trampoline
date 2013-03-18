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

extern int main (void);
extern void initialize_lpc2200_pll(void);

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/* this function should not return as
 * it is called straight after reset
 */
void tpl_arm_bootstrap_stage2 ()
{
    /* initialisation */
    /*initialize_lpc2200_pll();   */ 
    /*
     * initialіze memory segments
     */
    /* BSS section should be zeroed */
    
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
