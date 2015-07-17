/*
 * @file tpl_os_event_kernel.h
 *
 * @section desc File description
 *
 * Trampoline Event Management header file
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

#ifndef TPL_OS_EVENT_KERNEL_H
#define TPL_OS_EVENT_KERNEL_H

#include "tpl_os_types.h"
#include "tpl_os_task_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * Set events of a task
 *
 * @param   task_id     identifier of the task for which events will be set
 * @param   event       event mask for selected event bits
 *
 * @retval  E_OK        no error
 * @retval  E_OS_ID     (extended error only) task_id is invalid
 * @retval  E_OS_ACCESS (extended error only) referenced task is not extended task
 * @retval  E_OS_STATE  (extended error only) referenced task is suspended
 *
 * see paragraph 13.5.3.1 page 60 of OSEK/VDX 2.2.2 spec
 */
FUNC(tpl_status, OS_CODE) tpl_set_event_service(
    CONST(tpl_task_id, AUTOMATIC)       task_id,
    CONST(tpl_event_mask, AUTOMATIC)    event);


/**
 * Clear event of current task
 *
 * @param   event           event mask for selected event bits
 *
 * @retval  E_OK            no error
 * @retval  E_OS_ACCESS     (extended error only) caller is not an extended task
 * @retval  E_OS_CALLEVEL   (extended error only) call at interrupt level
 *
 * see paragraph 13.5.3.2 page 61 of OSEK/VDX 2.2.2 spec
 */
FUNC(tpl_status, OS_CODE) tpl_clear_event_service(
    CONST(tpl_event_mask, AUTOMATIC) event);


/**
 * Get the state of an event
 *
 * @param   task_id     identifier of the task
 * @param   event       #tpl_event_mask variable where the event value will
 *                      be stored
 *
 * @retval  E_OK        no error
 * @retval  E_OS_ACCESS (extended error only) referenced task is not extended
 * @retval  E_OS_STATE  (extended error only) referenced task is suspended
 *
 * see paragraph 13.5.3.3 page 61 of OSEK/VDX 2.2.2 spec
 */
FUNC(tpl_status, OS_CODE) tpl_get_event_service(
    CONST(tpl_task_id, AUTOMATIC)                       task_id,
    CONSTP2VAR(tpl_event_mask, AUTOMATIC, OS_APPL_DATA) event);


/**
 * Waits for some bits in the event
 *
 * @param   event   event mask for selected event bits
 *
 * @retval  E_OK            no error
 * @retval  E_OS_ACCESS     (extended error only) calling task is not an
 *                          extended task
 * @retval  E_OS_RESOURCE   (extended error only) calling task occupies
 *                          resources
 * @retval  E_OS_CALLEVEL   (extended error only) call at interrupt level
 *
 * see paragraph 13.5.3.4 page 61 of OSEK/VDX 2.2.2 spec
 */
FUNC(tpl_status, OS_CODE) tpl_wait_event_service(
    CONST(tpl_event_mask, AUTOMATIC) event);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_EVENT_KERNEL_H */

/* End of file tpl_os_event_kernel.h */
