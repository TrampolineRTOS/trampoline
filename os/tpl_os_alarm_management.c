/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Alarm Management
 *
 * See paragraph 13.6,
 * pages 62+ of OSEK/VDX 2.2.2 spec
 *
 * 2005-03-01 - revised code: Yvon's algorithm
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os.h"
#include "tpl_os_kernel.h"
#include "tpl_os_error.h"

/*
 * Prototypes of external functions
 */
tpl_status tpl_activate_task(tpl_task *);
tpl_status tpl_set_event(tpl_task *, tpl_event_mask);
void tpl_get_task_lock(void);
void tpl_release_task_lock(void);

/* extern tpl_lock *TASK_LOCK; */

/*
 * tpl_insert_alarm
 * insert an alarm in the alarm queue of the counter
 * it belongs to.
 *
 * The alarm list of a counter is a single linked list
 * and an alarm is inserted starting from the
 * head of the list
 */
void tpl_insert_alarm(tpl_alarm *alarm)
{
    /*  get the counter */
    tpl_counter *counter = alarm->counter;
    /*  initialize the current alarm to the head    */
    tpl_alarm *current_alarm = counter->first_alarm;
    tpl_alarm *prev_alarm;
    
    if (current_alarm == NULL) {
        /*  The alarm queue is empty
            So the alarm is alone in the queue      */
        counter->first_alarm = alarm;
        counter->next_alarm_to_raise = alarm;
        alarm->next_alarm = alarm->prev_alarm = NULL;
    }
    else {
        prev_alarm = NULL;
        /*  The alarm queue is not empty
            look for the place to insert the alarm  */
        while ((current_alarm != NULL) && (current_alarm->date < alarm->date)) {
            prev_alarm = current_alarm;
            current_alarm = current_alarm->next_alarm;
        }
    
        alarm->next_alarm = current_alarm;
        alarm->prev_alarm = prev_alarm;
    
        /*  insert the alarm    */
        if (current_alarm != NULL) {
            current_alarm->prev_alarm = alarm;
        }
        if (prev_alarm != NULL) {
            /*  add at the end of the queue or insert   */
            prev_alarm->next_alarm = alarm;
        }
        else {
            /*  the condition current_alarm->date < alarm->date was
                false a the beginning of the while. So the alarm
                have to be added at the head of the alarm queue     */
            counter->first_alarm = alarm;
        }
    }
    
    /*  Anyway, the alarm is put in the active state    */
    alarm->state = ALARM_ACTIVE;
}

/*
 * tpl_remove_alarm
 * remove an alarm from the alarm queue of the counter
 * it belongs to.
 */
void tpl_remove_alarm(tpl_alarm *alarm)
{
    
    tpl_counter *counter = alarm->counter;
    
    /*  adjust the head of the queue if the 
        removed alarm is at the head            */
    if (alarm == counter->first_alarm) {
        counter->first_alarm = alarm->next_alarm;
    }
    /*  adjust the next alarm to raise if it is
        the removed alarm                       */
    if (alarm == counter->next_alarm_to_raise) {
        counter->next_alarm_to_raise = alarm->next_alarm;
    }
    /*  build the link between the previous and next alarm in the queue */
    if (alarm->next_alarm != NULL) {
        alarm->next_alarm->prev_alarm = alarm->prev_alarm;
    }
    if (alarm->prev_alarm != NULL) {
        alarm->prev_alarm->next_alarm = alarm->next_alarm;
    }
    /*  if the next_alarm_to_raise was pointing to the
        alarm and the alarm was at the end of the queue
        next_alarm_to_raise is NULL and must be reset to
        the first alarm of the queue                        */
    if (counter->next_alarm_to_raise == NULL) {
        counter->next_alarm_to_raise = counter->first_alarm;
    }
    
    /*  The alarm is put in the sleep state */
    alarm->state = ALARM_SLEEP;
}

/*
 * tpl_raise_alarm is called by tpl_counter_tick
 * when an alarm is raised
 */
void tpl_raise_alarm(tpl_alarm *alarm)
{
    /*  check the kind of alarm to do the mandatory action  */
    switch (alarm->kind) {
        case ALARM_CALLBACK:
            /*  call the call back function */
            alarm->action.task_or_callback.callback();
            break;
        case ALARM_TASK_ACTIVATION:
            /*  activate the task   */
            tpl_get_task_lock();
            tpl_activate_task(alarm->action.task_or_callback.task);
            tpl_release_task_lock();
            break;
        case ALARM_EVENT_SETTING:
            /*  set the event   */
            tpl_get_task_lock();
            tpl_set_event(alarm->action.task_or_callback.task,alarm->action.mask);
            tpl_release_task_lock();
            break;
    }
    
    /*  rearm the alarm if needed   */
    if (alarm->cycle != 0) {
        /*  if the cycle is not 0,
            the new date is computed
            by adding the cycle to the current date         */
        alarm->date += alarm->cycle;
        /*  and the alarm is put back in the alarm queue
            of the counter it belongs to                    */
        tpl_insert_alarm(alarm);
    }
}

/*
 * tpl_counter_tick is called by the IT associated with a counter
 * The param is a pointer to the counter
 * It increment the counter tick and the counter value if needed
 * If the counter value is incremented, it checks the next alarm
 * date and raises alarms at that date.
 *
 * suggested modification by Seb - 2005-02-01
 */
void tpl_counter_tick(tpl_counter *counter)
{
    tpl_alarm* alarm;
    tpl_tick date;
    
    /*  inc the current tick value of the counter   */
    counter->current_tick++;
    /*  if tickperbase is reached, the counter is inc   */
    if (counter->current_tick == counter->ticks_per_base) {
        counter->current_tick = 0;
        counter->current_date++;
        date = counter->current_date;
        /*  check if the counter has reached the
            next alarm activation date  */
        alarm = counter->next_alarm_to_raise;

        while (alarm != NULL && alarm->date == date) {
            /*  note : alarm is always the next_alarm_to_raise
                since removing the alarm from the queue will
                advance next_alarm_to_raise along the queue     */
            
            /*  get the alarm from the queue    */
            tpl_remove_alarm(alarm);
            /*  raise it    */
            tpl_raise_alarm(alarm);
            /*  get the next alarm to raise     */
            alarm = counter->next_alarm_to_raise;
        }
    }
}

/*
 * OSEK/VDX API
 */

/*
 * GetAlarmBase
 *
 * See page 63 of the OSEK spec
 */
StatusType GetAlarmBase(AlarmType alarm_id, AlarmBaseRefType info)
{
    StatusType result = E_OK;
    
#ifndef NO_ALARM
    tpl_alarm *alarm;
#endif

    STORE_SERVICE(OSServiceId_GetAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_ALARM_BASE_REF(info)
    
    CHECK_ALARM_ID_ERROR(alarm_id,result)
    
#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
        alarm = tpl_alarm_table[alarm_id];
        
        /*  NOT YET IMPLEMENTED FOR mincycle and maxallowedvalue    */
        info->ticksperbase = alarm->counter->ticks_per_base;
    END_IF_NO_EXTENDED_ERROR()
#endif
    
    PROCESS_ERROR(result)
    
    return result;
}

/*
 * GetAlarm
 *
 * See page 63 of the OSEK spec
 */
StatusType GetAlarm(AlarmType alarm_id, TickRefType tick)
{
    StatusType result = E_OK;
    
#ifndef NO_ALARM
    tpl_alarm *alarm;
#endif

    STORE_SERVICE(OSServiceId_GetAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_TICK_REF(tick)

    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
        alarm = tpl_alarm_table[alarm_id];
        
        /*  verify the alarm is active  */
        if (alarm->state == ALARM_ACTIVE) {
            *tick = alarm->date - alarm->counter->current_date;
        }
        else {
            result = E_OS_NOFUNC;
        }
    END_IF_NO_EXTENDED_ERROR()
#endif

    PROCESS_ERROR(result)
    
    return result;
}

/*
 * SetRelAlarm
 *
 * See page 63 of the OSEK spec
 */
StatusType SetRelAlarm(AlarmType alarm_id, TickType increment, TickType cycle)
{
    StatusType result = E_OK;
    
#ifndef NO_ALARM
    tpl_alarm *alarm;
#endif
    
    STORE_SERVICE(OSServiceId_SetRelAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_TICK_1(increment)
    STORE_TICK_2(cycle)

    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
        alarm = tpl_alarm_table[alarm_id];
    
        if (alarm->state == ALARM_SLEEP) {
            /*  the alarm is not in use, proceed    */
            alarm->date = alarm->counter->current_date + increment;
            alarm->cycle = cycle;
            tpl_insert_alarm(alarm);
        }
        else {
            /*  the alarm is in use, return the proper error code   */
            result = E_OS_STATE;
        }
    END_IF_NO_EXTENDED_ERROR()
#endif

    PROCESS_ERROR(result)
    
    return result;
}

/*
 * SetRelAlarm
 *
 * See page 64 of the OSEK spec
 */
StatusType SetAbsAlarm(AlarmType alarm_id, TickType start, TickType cycle)
{
    StatusType result = E_OK;
    
#ifndef NO_ALARM
    tpl_alarm *alarm;
#endif
    
    STORE_SERVICE(OSServiceId_SetAbsAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_TICK_1(start)
    STORE_TICK_2(cycle)

    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
    alarm = tpl_alarm_table[alarm_id];
    
    if (alarm->state == ALARM_SLEEP) {
        /*  the alarm is not in use, proceed    */
        alarm->date = start;
        alarm->cycle = cycle;
        tpl_insert_alarm(alarm);
    }
    else {
        /*  the alarm is in use, return the proper error code   */
        result = E_OS_STATE;
    }
    END_IF_NO_EXTENDED_ERROR()
#endif

    PROCESS_ERROR(result)
    
    return result;
}

/*
 * CancelAlarm
 *
 * See page 65 of the OSEK spec
 */
StatusType CancelAlarm(AlarmType alarm_id)
{
    StatusType result = E_OK;
    
#ifndef NO_ALARM
    tpl_alarm *alarm;
#endif

    STORE_SERVICE(OSServiceId_CancelAlarm)
    STORE_ALARM_ID(alarm_id)
    
    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
    alarm = tpl_alarm_table[alarm_id];

    if (alarm->state == ALARM_ACTIVE) {
        tpl_remove_alarm(alarm);
    }
    else {
        result = E_OS_NOFUNC;
    }
    END_IF_NO_EXTENDED_ERROR()
#endif

    PROCESS_ERROR(result)
    
    return result;
}
