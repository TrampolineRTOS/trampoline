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
 * @param counter_id identifier of the counter to be incremented
 *
 * @retval  E_OK    no error
 * @retval  E_OS_ID (extended error only) counter_id is invalid
 *
 * see paragraph 8.4.12, page 58 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
StatusType IncrementCounter(CounterType counter_id);

/* TPL_AS_COUNTER_H */
#endif
