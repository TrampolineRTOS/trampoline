/**
 * @file tpl_os_os.c
 *
 * @section descr File description
 *
 * Trampoline OS StartOS implementation.
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

#include "tpl_os_os.h"
#include "tpl_os_kernel.h"
#include "tpl_machine_interface.h"

#define API_START_SEC_CODE
#include "tpl_memmap.h"

extern FUNC(void, OS_CODE) tpl_start_os(CONST(AppModeType, AUTOMATIC) mode);

/**
 * Starts Trampoline
 *
 * @param mode chosen application mode
 *
 * see paragraph 13.7.2.2 page 66 of OSEK/VDX 2.2.2 spec
 */
FUNC(void, OS_CODE) StartOS(
  CONST(AppModeType, AUTOMATIC) mode)
{
  GET_CURRENT_CORE_ID(core_id)

  if (tpl_current_os_state(CORE_ID_OR_NOTHING(core_id)) == OS_INIT)
  {
#if NUMBER_OF_CORES > 1
    if (core_id == OS_CORE_ID_MASTER)
    {
#endif
      /* Call target specific initialization */
      tpl_init_machine();
#if WITH_MODULES_INIT == YES
      /* Call inits for kernel modules. Generated function */
      tpl_init_modules();
#endif
#if NUMBER_OF_CORES > 1
    }
    tpl_init_core();
#endif
  }
  tpl_start_os(mode);
  /*
   * tpl_start_os does not return since the idle task will run
   * if no other task is AUTOSTART except if it is called from
   * within a task or an ISR of (which is forbidden).
   */
}

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_os.c */
