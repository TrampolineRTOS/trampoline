/**
 * @file tpl_as_counter_kernel.h
 *
 * @section desc File description
 *
 * Trampoline autosar extension software counters API
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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
#ifndef TPL_AS_COUNTER_KERNEL_H
#define TPL_AS_COUNTER_KERNEL_H

#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_timeobj_kernel.h"


#if COUNTER_COUNT > 0
/*  MISRA RULE 27 VIOLATION: This object is not declared as external
 in a header file because it is only used in this file but declared
 in the configuration file
 */
extern CONSTP2VAR(tpl_counter, OS_VAR, OS_APPL_DATA)
tpl_counter_table[COUNTER_COUNT];
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * Increment a counter.
 *
 * @param counter_id    identifier of the counter to be incremented
 *
 * @retval  E_OK        no error
 *                      requirements OS286 and OS321
 * @retval  E_OS_ID     counter_id is not valid (EXTENDED status only)
 *                      requirement OS285
 *
 * see paragraph 8.4.12, page 70 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_increment_counter_service(
    VAR(tpl_counter_id, AUTOMATIC) counter_id
);

/**
 * Get the value of a counter.
 *
 * @param counter_id    identifier of the counter
 * @param value         reference to the variable where is value is returned
 *
 * @retval  E_OK        no error
 *                      requirements OS377
 * @retval  E_OS_ID     (extended error only) counter_id is invalid
 *                      requirement OS376
 *
 * see paragraph 8.4.12, page 70 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_get_counter_value_service(
    VAR(tpl_counter_id, AUTOMATIC)              counter_id,
    P2VAR(tpl_tick, AUTOMATIC, OS_APPL_DATA)    value
);

/**
 * Get the elapsed value of a counter.
 *
 * @param counter_id        identifier of the counter
 * @param previous_value    previous value of the counter
 * @param value             reference to the variable where is value is
 *                          returned
 *
 * @retval  E_OK        no error
 *                      requirement OS382
 * @retval  E_OS_VALUE  the previous_value parameter is larger than the
 *                      maxallowedvalue of the counter
 *                      requirement OS391
 * @retval  E_OS_ID     (extended error only) counter_id is invalid
 *                      requirement OS381
 *
 * see paragraph 8.4.12, page 71 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_get_elapsed_counter_value_service(
    VAR(tpl_counter_id, AUTOMATIC)              counter_id,
    P2VAR(tpl_tick, AUTOMATIC, OS_APPL_DATA)    previous_value,
    P2VAR(tpl_tick, AUTOMATIC, OS_APPL_DATA)    value
);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_AS_COUNTER_KERNEL_H */
#endif

/* End of file tpl_as_counter_kernel.h */
