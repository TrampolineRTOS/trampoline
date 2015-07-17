/**
 * @file tpl_os_multicore_kernel.h
 *
 * @section descr File description
 *
 * Trampoline multicore kernel services header.
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

#ifndef TPL_OS_MULTICORE_KERNEL_H
#define TPL_OS_MULTICORE_KERNEL_H

#include "tpl_os_multicore.h"
#include "tpl_os_types.h"

#define OS_START_SEC_VAR_8BITS
#include "tpl_memmap.h"

/**
 * The status of cores. The table is indexed by the core identifier
 * that ranges from 0 to NUMBER_OF_CORES - 1
 */
extern VAR(CoreStatusType, OS_APPL_DATA) tpl_core_status[NUMBER_OF_CORES];

#define OS_STOP_SEC_VAR_8BITS
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_16BITS
#include "tpl_memmap.h"

/**
 * tpl_start_count
 */
extern VAR(uint16, OS_APPL_DATA) tpl_start_count_0;
extern VAR(uint16, OS_APPL_DATA) tpl_start_count_1;

/**
 * tpl_number_of_activated_cores
 */
extern VAR(uint16, OS_APPL_DATA) tpl_number_of_activated_cores;


#define OS_STOP_SEC_VAR_16BITS
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * tpl_get_core_id_service returns the identifier of the core.
 *
 * @retval  The unique ID of the core running the caller.
 *
 * see paragraph 8.4.23 page 147 of
 * AUTOSAR Specification of Operating System V5.0.0 R4.0 Rev 3
 */
FUNC(CoreIdType, OS_CODE) tpl_get_core_id_service(void);

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
  CONST(CoreIdType, AUTOMATIC)      core_id,
  CONSTP2VAR(StatusType, AUTOMATIC, OS_APPL_DATA) status);

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
  CONST(CoreIdType, AUTOMATIC)      core_id,
  CONSTP2VAR(StatusType, AUTOMATIC, OS_APPL_DATA) status);

/**
 * tpl_shutdown_all_cores_service shutdown all the running cores.
 *
 * @param   error       The shutdown error code.
 *
 * see paragraph 8.4.29 page 153 of
 * AUTOSAR Specification of Operating System V5.0.0 R4.0 Rev 3
 */
FUNC(void, OS_CODE) tpl_shutdown_all_cores_service(
  CONST(StatusType, AUTOMATIC) error);

/**
 * tpl_get_number_of_activated_cores_service returns the number
 * of activated cores.
 *
 * @retval    The number of cores activated by the StartCore service.
 */
FUNC(uint32, OS_CODE) tpl_get_number_of_activated_cores_service(void);

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
  CONST(CoreIdType, AUTOMATIC)          core_id,
  CONSTP2VAR(CoreStatusType, AUTOMATIC, OS_APPL_DATA) status);

/**
 * tpl_sync_barrier does a synchronization barrier
 *
 * @param   enter_count   the counter used to count the number of cores
 * @param   lock          the lock used to protect the critical section
 */
FUNC(void, OS_CODE) tpl_sync_barrier(
  CONSTP2VAR(uint16, AUTOMATIC, OS_VAR)   enter_count,
  CONSTP2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_OS_MULTICORE_KERNEL_H */
#endif

/* End of file tpl_os_multicore_kernel.h */
