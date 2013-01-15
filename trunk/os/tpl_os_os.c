/**
 * @file tpl_os_os.c
 *
 * @section descr File description
 *
 * Trampoline OS StartOS implementation.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
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
  if (tpl_current_os_state() == OS_INIT)
  {
    tpl_init_machine();
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
