/**
 * @file olimex_tpl_stubs.c
 *
 * @section descr File description
 *
 * SIMTEC platform specific routines and variables
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
 * $Date: 2010-10-27 19:39:06 +0200 (Wed, 27 Oct 2010) $
 * $Rev: 1230 $
 * $Author: pacco $
 * $URL: https://trampoline.rts-software.org/svn/trunk/machines/thumb2/cortex-m3/cm3_tpl_stubs.c $
 */
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern FUNC (void, OS_CODE) tpl_init_machine_generic (void);

void tpl_init_machine()
{
    tpl_init_machine_generic ();
    //Init();
}

void tpl_shutdown ()
{
    /* FIXME: this is does not conform to AUTOSAR OS specifications, 
     * should return to main with initial context */
    //DISABLE_FIQ ();
    //DISABLE_IRQ ();
	// remove ITs
		
  	// spurious events can wake up processor :
	__asm__ (" CPSID	I");

	// we need a loop to ensure sleep		 
	while(1)
	{    	
		__asm__ ("   wfi ;"); 	// go to sleep until NMI/HARD FAULT/RESET
	} 
	
    /* TODO : fall into very low consumption mode : all
     * internal CPU clocks are disabled.
     */
    
    while (1);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file olimex_tpl_stubs.c */
