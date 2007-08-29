/**
 * @file tpl_as_counter.c
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
 
#include "tpl_as_counter.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_as_error.h"

/*
 * Increment a counter.
 *
 * counter_id is the identifier of the counter to be incremented.
 * The function returns E_OK if everything was ok or E_OS_ID
 * (extended error only) if counter_id is invalid
 *
 * see paragraph 8.4.12, page 58 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
StatusType IncrementCounter(CounterType counter_id)
{
    StatusType result = E_OK;
    tpl_counter *counter = NULL;
    tpl_status  need_rescheduling = NO_SPECIAL_CODE;
    
    /*  lock the task structures                    */
    LOCK_WHEN_TASK_OR_ISR()
    
    /*  store information for error hook routine    */
    STORE_SERVICE(OSServiceId_IncrementCounter)
    STORE_COUNTER_ID(counter_id)
    
    /*  check a counter_id error                    */
    CHECK_COUNTER_ID_ERROR(counter_id,result)
    
    IF_NO_EXTENDED_ERROR(result)
    
        /*  get the counter descriptor              */
        counter = tpl_counter_table[id];
        
        /*  increment the counter                   */
        need_rescheduling |= tpl_counter_tick(counter);

        if (need_rescheduling == NEED_RESCHEDULING) {
            tpl_schedule(FROM_TASK_LEVEL);
        }
        
    IF_NO_EXTENDED_ERROR_END()

    PROCESS_ERROR(result)

    /*  unlock the task structures                  */
    UNLOCK_WHEN_TASK_OR_ISR();
}

/*


struct TPL_COUNTER  *counter;
tpl_state           state;
tpl_tick            period;

---

ScheduleTables :

- Revoir la structure des alarmes -> minimiser l'empreinte ram.
- Implémentation au dessus des alarmes.

*/