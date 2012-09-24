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

//zone dedicated for .bss -> should be zeroed in startup.
//get addreses from the linker script.
extern unsigned char *common_zeroed_vars_begin;
extern unsigned char *common_zeroed_vars_end;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

//FUNC(void, OS_CODE) fill_with_zeros (u8 *from, u8 *to)
void fill_with_zeros(unsigned char *from, unsigned char *to)
{
	unsigned char *zero_vars_ptr;
	if (from != to)
	{
		zero_vars_ptr = from;
		do  
		{
			*zero_vars_ptr = 0;
			zero_vars_ptr++;
		}
		while (zero_vars_ptr != to);
	}
}

/* this function should not return as
 * it is called straight after reset
 */
void tpl_arm_bootstrap_stage2 ()
{
    /* initialisation */
    
    /*
     * initialіze memory segments
     */
    /* BSS section should be zeroed */
    fill_with_zeros (common_zeroed_vars_begin, common_zeroed_vars_end);
	
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
