/**
 * @file tpl_machine_mk20dx256.c
 *
 * @section descr File description
 *
 * Trampoline processor dependant functions.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "mk20dx256.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_set_systick_timer()
{
 	/*
 	 * initialize the SysTick counter at a 1ms cycle
 	 * F_CPU is the frequency of the clock expressed in milliseconds
 	 */
 	SYST_RVR = (F_CPU / 1000) - 1;  /* SysTick Reload value  */
 	SYST_CVR = 0;                   /* SysTick Current value */
 	/*
 	 * Note:  Clearing the SysTick Current Value register by a register write
 	 *        in software does not cause SysTick to be pended.
 	 */
 	SYST_CSR =                /* SysTick Control and Status                              */
 	  SYST_CSR_CLKSOURCE |    /* 1 = core clock used for SysTick                         */
 	  SYST_CSR_TICKINT |      /* 1 = counting down to 0 will cause the SysTick exception */
 	  SYST_CSR_ENABLE;        /* 1 = the counter will operate in a multi-shot manner.    */
 
 	SCB_SHPR3 = 0x80000000;   /* Systick priority = 128 */
 	SCB_SHPR2 = 0x80000000;   /* SVCall priority = 128 */
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
