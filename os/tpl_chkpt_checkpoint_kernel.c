/**
 * @file tpl_os_checkpoint_kernel.c
 *
 * @section descr File description
 *
 * Trampoline checkpointing os services implementation.
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
 *
 */

#include "tpl_os_os_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_machine_interface.h"
#include "tpl_trace.h"
#include "tpl_os_hooks.h"
#include "tpl_chkpt_checkpoint_kernel.h"

#if NUMBER_OF_CORES > 1
#include "tpl_os_multicore_kernel.h"
# if SPINLOCK_COUNT > 0
# include "tpl_as_spinlock_kernel.h"
# endif
#endif

#define OS_START_SEC_CONST_16BIT
#include "tpl_memmap.h"
static CONST (sint16,OS_CONST) NO_CHECKPOINT = -1;
#define OS_STOP_SEC_CONST_16BIT
#include "tpl_memmap.h"
#define OS_START_SEC_VAR_NON_VOLATILE_16BIT
#include "tpl_memmap.h"
VAR (sint16,OS_VAR) tpl_checkpoint_buffer = -1;
#define OS_STOP_SEC_VAR_NON_VOLATILE_16BIT
#include "tpl_memmap.h"

extern void framUpWrite8(const uint16 address, const uint8 data);
extern void framUpWrite16(const uint16 address, const uint16 data);
extern uint8 framUpRead8(const uint16 address);
extern uint16 framUpRead16(const uint16 address);
extern void tpl_save_checkpoint(const uint16 buffer);
extern void tpl_load_checkpoint(const uint16 buffer);

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_hibernate_os_service(void)
{
  sint16 l_buffer;
  GET_CURRENT_CORE_ID(core_id)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_Hibernate)

  l_buffer = (tpl_checkpoint_buffer + 1) % 1;
  tpl_save_checkpoint(l_buffer);
  tpl_checkpoint_buffer = l_buffer;

  //  while(1);

  PROCESS_ERROR(result)
}

FUNC(void, OS_CODE) tpl_restartos_os_service(void)
{
  GET_CURRENT_CORE_ID(core_id)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_RestartOS)

  PROCESS_ERROR(result)
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_checkpoint_kernel.c */

