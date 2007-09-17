/**
 * @file tpl_as_counter.h
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
#ifndef TPL_AS_COUNTER_H
#define TPL_AS_COUNTER_H

#include "tpl_os_application_def.h" /* defines WITH_AUTOSAR */
#include "tpl_os_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_alarm.h"

/**
 * @typedef CounterType
 *
 * A counter identifier.
 *
 * see paragraph 8.3.13, page 50 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
typedef tpl_counter_id  CounterType;

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
StatusType IncrementCounter(
    CounterType counter_id
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
StatusType GetCounterValue(
    CounterType counter_id,
    TickRefType value
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
StatusType GetElapsedCounterValue(
    CounterType counter_id,
    TickType    previous_value,
    TickRefType value
);

/* TPL_AS_COUNTER_H */
#endif
