/**
 * @file tpl_machine_cortex_specific.c
 *
 * @section descr File description
 *
 * Cortex specific inits and functions
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
  tpl_init_machine_specific();
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

/* End of file tpl_machine_cortex_specific.c */
