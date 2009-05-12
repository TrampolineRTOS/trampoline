/**
 * @file tpl_as_counter.c
 *
 * @internal
 *
 * @section desc File description
 *
 * Trampoline autosar extension software counters functions
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
 
#ifndef WITH_SYSTEM_CALL

#include "tpl_as_counter.h"
#include "tpl_as_counter_kernel.h"
#include "tpl_os_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Increment a counter.
 *
 * counter_id is the identifier of the counter to be incremented.
 * The function returns E_OK if everything was ok or E_OS_ID
 * (extended error only) if counter_id is invalid
 *
 * see paragraph 8.4.12, page 70 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) IncrementCounter(VAR(CounterType, AUTOMATIC) counter_id)
{
    return OSEK_STATUS_MASK & tpl_increment_counter_service(counter_id);
}


/**
 * Get the current value of a counter.
 *
 * counter_id is the identifier of the counter and value a reference (pointer)
 * to the variable where the value of the counter is stored.
 *
 * see paragraph 8.4.12, page 70 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) GetCounterValue(
    VAR(CounterType, AUTOMATIC) counter_id,
    VAR(TickRefType, AUTOMATIC) value)
{
    return tpl_get_counter_value_service(counter_id, value);
}


/**
 * Get the elapsed value of a counter.
 *
 * counter_id is the identifier of the counter and value a reference (pointer)
 * to the variable where the value of the counter is stored.
 *
 * see paragraph 8.4.12, page 70 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) GetElapsedCounterValue(
    VAR(CounterType, AUTOMATIC) counter_id,
    VAR(TickRefType, AUTOMATIC) previous_value,
    VAR(TickRefType, AUTOMATIC) value)
{
    return tpl_get_elapsed_counter_value_service(
        counter_id,
        previous_value,
        value
    );
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#else
#error "This file should not be part of your project since WITH_SYSTEM_CALL is defined"
#endif /* WITH_SYSTEM_CALL */

/* End of file tpl_as_counter.c */
