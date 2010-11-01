/**
 * @file apf27_bootstrap_stage2.c
 *
 * @section descr File description
 *
 * ARMADEUS platform bootstrap second steop
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
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */
#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_definitions.h"
#include "tpl_os_application_def.h"
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"
#endif /* WITH_AUTOSAR */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern int main (void);

/* TODO: replace this by a goil template which generates a declaration in .h */
extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[64];


/* this function should not return as
 * it is called straight after reset
 */
FUNC(void, OS_CODE) tpl_arm_bootstrap_stage2 ()
{
	u32 *target;
	int i;

	/*TODO armadeus_memory_setup_defaults ();*/

	/* we copy exception table to the right place */
	target = (u32*)0xFFFFFEF0;
	for (i = 0 ; i < 4 ; i++)
	{
		*target = (u32)exception_table[i];
    target++;
	}

  /* we copy (goil) generated interrupt table to the interrupt
   vector RAM */
  target = (u32*)0xFFFFFF00;
  for (i = 0 ; i < 64 ; i++)
  {
    *target = (u32)tpl_it_vector[i].func;
    target++;
  }

	/*
	 * initialize memory segments
	 */
 /* FIXME: usually, BSS segment is zeroed and DATA segment
  * gets initial values from ROM. How should we handle this
	* with memory mapping ?
	*/
	
	/*
	 * start application (which may start Trampoline via StartOS)
	 */
	main ();

	/* ends in a loop, as we should not return from reset */
	while (1);
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

