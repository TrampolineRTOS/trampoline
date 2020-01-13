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

#define START_OS_SYNC_LOCK_ID   0
#endif

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#if NUMBER_OF_CORES > 1
/**
 * @internal
 *
 * tpl_startos_sync_lock is the lock used in the critical section of
 * both synchronization barriers of tpl_start_os
 */
VAR(tpl_lock, OS_VAR) tpl_startos_sync_lock = UNLOCKED_LOCK;
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_hibernate_os_service(void)
{
  GET_CURRENT_CORE_ID(core_id)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_Hibernate)

  PROCESS_ERROR(result)
}


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_checkpoint_kernel.c */

