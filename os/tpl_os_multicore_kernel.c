/**
 * @file tpl_os_multicore_kernel.c
 *
 * @section descr File description
 *
 * Trampoline multicore kernel services implementation.
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

#include "tpl_os_multicore_kernel.h"
#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"

#define OS_START_SEC_VAR_16BITS
#include "tpl_memmap.h"

VAR(uint16, OS_VAR)
  tpl_number_of_activated_cores = 1;

VAR(uint16, OS_VAR)
  tpl_number_of_non_autosar_activated_cores = 0;

VAR(uint16, OS_VAR) tpl_start_count_0 = 1;
VAR(uint16, OS_VAR) tpl_start_count_1 = 1;

#define OS_STOP_SEC_VAR_16BITS
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_8BITS
#include "tpl_memmap.h"

/**
 * The status of cores. The table is indexed by the core identifier
 * that ranges from 0 to NUMBER_OF_CORES - 1
 */
extern VAR(CoreStatusType, OS_VAR) tpl_core_status[NUMBER_OF_CORES];

#define OS_STOP_SEC_VAR_8BITS
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * tpl_sync_barrier does a synchronization barrier
 *
 * @param   enter_count   the counter used to count the number of cores
 * @param   lock          the lock used to protect the critical section
 */
FUNC(void, OS_CODE) tpl_sync_barrier(
  CONSTP2VAR(uint16, AUTOMATIC, OS_VAR)   enter_count,
  CONSTP2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock)
{
  VAR(uint16, AUTOMATIC) count;

  tpl_get_lock(lock);
  count = --*enter_count;
  tpl_release_lock(lock);

  while (count > 0)
  {
    tpl_get_lock(lock);
    count = *enter_count;
    tpl_release_lock(lock);
  }
}

/**
 * tpl_get_core_id_service returns the identifier of the core.
 *
 * @retval  The unique ID of the core running the caller.
 *
 * see paragraph 8.4.23 page 147 of
 * AUTOSAR Specification of Operating System V5.0.0 R4.0 Rev 3
 */
FUNC(CoreIdType, OS_CODE) tpl_get_core_id_service(void)
{
  return tpl_get_core_id();
}

/**
 * tpl_start_core_service starts a processing core.
 *
 * @param   core_id     the core to start
 * @param   status      status returned by StartCore.
 *                      E_OK:        No Error (standard & extended).
 *                      E_OS_ID:     <core_id> is invalid (extended).
 *                      E_OS_ACCESS: The function was called after starting
 *                                   the OS (extended).
 *                      E_OS_STATE:  The core is already started (extended).
 *
 * see paragraph 8.4.24 page 147 of
 * AUTOSAR Specification of Operating System V5.0.0 R4.0 Rev 3
 */
FUNC(void, OS_CODE) tpl_start_core_service(
  CONST(CoreIdType, AUTOMATIC)                    core_id,
  CONSTP2VAR(StatusType, AUTOMATIC, OS_APPL_DATA) status)
{
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /* lock the kernel */
  LOCK_KERNEL()

  /* store information for error hook routine */
  STORE_SERVICE(OSServiceId_StartCore)
  STORE_CORE_ID(core_id)

  /* Check errors */
  CHECK_CORE_ID_ERROR(core_id, result)

  /* BEGIN_START_CORE_CRITICAL_SECTION() */

  CHECK_START_CORE_ERROR(core_id, result)
  CHECK_STARTCORE_OS_NOT_STARTED(tpl_get_core_id(), result)

  IF_NO_EXTENDED_ERROR(result)
  {
    tpl_core_status[core_id] = STARTED_CORE_AUTOSAR;
    tpl_number_of_activated_cores++;
    tpl_start_count_0++;
    tpl_start_count_1++;
    tpl_start_core(core_id);
  }

  /* END_START_CORE_CRITICAL_SECTION() */

  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()

  *status = result;
}

/**
 * tpl_start_non_autosar_core_service starts a non AUTOSAR processing core.
 *
 * @param   core_id     the core to start
 * @param   status      status returned by StartCore.
 *                      E_OK:        No Error (standard & extended).
 *                      E_OS_ID:     <core_id> is invalid (extended).
 *                      E_OS_STATE:  The core is already started (extended).
 *
 * see paragraph 8.4.25 page 148 of
 * AUTOSAR Specification of Operating System V5.0.0 R4.0 Rev 3
 */
FUNC(void, OS_CODE) tpl_start_non_autosar_core_service(
  CONST(CoreIdType, AUTOMATIC)                    core_id,
  CONSTP2VAR(StatusType, AUTOMATIC, OS_APPL_DATA) status)
{
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /* lock the kernel */
  LOCK_KERNEL()

  /* store information for error hook routine */
  STORE_SERVICE(OSServiceId_StartNonAutosarCore)
  STORE_CORE_ID(core_id)

  /* Check errors */
  CHECK_CORE_ID_ERROR(core_id, result)
  CHECK_START_CORE_ERROR(core_id, result)

  IF_NO_EXTENDED_ERROR(result)
  {
    tpl_core_status[tpl_get_core_id()] = STARTED_CORE_NON_AUTOSAR;
    tpl_number_of_non_autosar_activated_cores++;
    tpl_start_core(core_id);
  }

  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()

  *status = result;
}

/**
 * tpl_shutdown_all_cores_service shutdowns all the running cores.
 *
 * @param   error       The shutdown error code.
 *
 * see paragraph 8.4.29 page 153 of
 * AUTOSAR Specification of Operating System V5.0.0 R4.0 Rev 3
 */
FUNC(void, OS_CODE) tpl_shutdown_all_cores_service(
  CONST(StatusType, AUTOMATIC) error)
{
  /* TODO */
}

/**
 * tpl_get_number_of_activated_cores_service returns the number
 * of activated cores.
 *
 * @retval    The number of cores activated by the StartCore service.
 */
FUNC(uint32, OS_CODE) tpl_get_number_of_activated_cores_service(void)
{
  VAR(uint32, AUTOMATIC) number;
  /* lock the kernel */
  LOCK_KERNEL()

  number = tpl_number_of_activated_cores;

  /*  unlock the kernel  */
  UNLOCK_KERNEL()

  return number;
}

/**
 * tpl_get_core_status_service allows to get the status of a processing core.
 *
 * @param     core_id       The core of which the status is got.
 * @param     core_status   Core status returned by GetCoreStatus.
 *
 * @retval    E_OK:     No error, the core status was successfully written
 *                      in <core_status> (standard & extended).
 *            E_OS_ID:  <core_id> is invalid (extended).
 */
FUNC(StatusType, OS_CODE) tpl_get_core_status_service(
  CONST(CoreIdType, AUTOMATIC)                        core_id,
  CONSTP2VAR(CoreStatusType, AUTOMATIC, OS_APPL_DATA) status)
{
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /* lock the kernel */
  LOCK_KERNEL()

  /* store information for error hook routine */
  STORE_SERVICE(OSServiceId_GetCoreStatus)
  STORE_CORE_ID(core_id)

  /* Check errors */
  CHECK_CORE_ID_ERROR(core_id, result)

  IF_NO_EXTENDED_ERROR(result)
  {
    *status = tpl_core_status[core_id];
  }

  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_multicore_kernel.c */
