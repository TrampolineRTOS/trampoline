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
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"
#endif /* WITH_AUTOSAR */

/* this function should not return as
 * it is called straight after reset
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_arm_bootstrap_stage2 ()
{
	/*TODO armadeus_memory_setup_defaults ();*/

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

