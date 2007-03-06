/**
 * @file tpl_os_alarm_kernel.c
 *
 * @section desc File description
 *
 * Trampoline Alarm Kernel implementation file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
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

#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"
#include "tpl_os_alarm_kernel.h"

static tpl_status tpl_raise_alarm(tpl_alarm *alarm);

/*
 * tpl_insert_alarm
 * insert an alarm in the alarm queue of the counter
 * it belongs to.
 *
 * The alarm list of a counter is a double-linked list
 * and an alarm is inserted starting from the
 * head of the list
 */
void tpl_insert_alarm(tpl_alarm *alarm)
{
    /*  get the counter */
    tpl_counter *counter = alarm->counter;
    /*  initialize the current alarm to the head    */
    tpl_alarm *current_alarm = counter->first_alarm;
    tpl_alarm *prev_alarm = NULL;
    
    if (current_alarm == NULL)
    {
        /*  The alarm queue is empty
            So the alarm is alone in the queue      */
        counter->first_alarm = alarm;
        counter->next_alarm_to_raise = alarm;
        alarm->next_alarm = alarm->prev_alarm = NULL;
    }
    else
    {
        /*  The alarm queue is not empty
            look for the place to insert the alarm  */
        while ((current_alarm != NULL) &&
               (current_alarm->date <= alarm->date))
        {
            prev_alarm = current_alarm;
            current_alarm = current_alarm->next_alarm;
        }
    
        alarm->next_alarm = current_alarm;
        alarm->prev_alarm = prev_alarm;
    
        /*  insert the alarm    */
        if (current_alarm != NULL)
        {
            current_alarm->prev_alarm = alarm;
        }
        if (prev_alarm != NULL)
        {
            /*  add at the end of the queue or insert   */
            prev_alarm->next_alarm = alarm;
        }
        else
        {
            /*  the condition current_alarm->date < alarm->date was
                false a the beginning of the while. So the alarm
                have to be added at the head of the alarm queue             */
            counter->first_alarm = alarm;
        }
        
        /*  Update the next_alarm_to_raise to point to the newly
            inserted alarm if the date of the newly inserted alarm
            is within the current date and the next_alarm_to_raise date,
			taking account the modulo                                       */
		if (counter->next_alarm_to_raise->date < counter->current_date)
		{
        	if ((alarm->date > counter->current_date) || 
			    (alarm->date < counter->next_alarm_to_raise->date))
            {			
				counter->next_alarm_to_raise = alarm;
			}
		}
        else
        {
        	if ((alarm->date > counter->current_date) &&
            	(alarm->date < counter->next_alarm_to_raise->date))
            {
            	counter->next_alarm_to_raise = alarm;
			}
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
    if (alarm == counter->first_alarm)
    {
        counter->first_alarm = alarm->next_alarm;
    }
    /*  adjust the next alarm to raise if it is
        the removed alarm                       */
    if (alarm == counter->next_alarm_to_raise)
    {
        counter->next_alarm_to_raise = alarm->next_alarm;
    }
    /*  build the link between the previous and next alarm in the queue */
    if (alarm->next_alarm != NULL)
    {
        alarm->next_alarm->prev_alarm = alarm->prev_alarm;
    }
    if (alarm->prev_alarm != NULL)
    {
        alarm->prev_alarm->next_alarm = alarm->next_alarm;
    }
    /*  if the next_alarm_to_raise was pointing to the
        alarm and the alarm was at the end of the queue
        next_alarm_to_raise is NULL and must be reset to
        the first alarm of the queue                        */
    if (counter->next_alarm_to_raise == NULL)
    {
        counter->next_alarm_to_raise = counter->first_alarm;
    }
    
    /*  The alarm is put in the sleep state */
    alarm->state = ALARM_SLEEP;
}

/**
 * @internal
 *
 * tpl_raise_alarm is called by tpl_counter_tick
 * when an alarm is raised.
 *
 * @param alarm     The alarm to raise.
 */
static tpl_status tpl_raise_alarm(tpl_alarm *alarm)
{
    tpl_status result = E_OK;
    
    /*  check the kind of alarm to do the mandatory action  */
    switch (alarm->kind)
    {
        case ALARM_CALLBACK:
            /*  call the call back function */
            alarm->action.task_or_callback.callback();
            break;
        case ALARM_TASK_ACTIVATION:
            /*  activate the task   */
            result = tpl_activate_task(alarm->action.task_or_callback.task);
            break;
        case ALARM_EVENT_SETTING:
            /*  set the event   */
            result = tpl_set_event(
                        alarm->action.task_or_callback.task,
                        alarm->action.mask);
            break;
        default:
            result = E_OS_STATE;
            break;
    }
    
    /*  rearm the alarm if needed   */
    if (alarm->cycle != 0)
    {
        /*  if the cycle is not 0,
            the new date is computed
            by adding the cycle to the current date         */
        alarm->date += alarm->cycle;
        /*  and the alarm is put back in the alarm queue
            of the counter it belongs to                    */
        tpl_insert_alarm(alarm);
    }
    
    return result;
}

/*
 * tpl_counter_tick is called by the IT associated with a counter
 * The param is a pointer to the counter
 * It increment the counter tick and the counter value if needed
 * If the counter value is incremented, it checks the next alarm
 * date and raises alarms at that date.
 *
 * suggested modification by Seb - 2005-02-01
 *
 * Update: 2006-12-10: Does not perform the rescheduling. 
 * tpl_schedule must be called explicitly
 */
tpl_status tpl_counter_tick(tpl_counter *counter)
{
    tpl_alarm*  alarm;
    tpl_tick    date;
    tpl_status  need_resched = NO_SPECIAL_CODE;
    
    /*  inc the current tick value of the counter   */
    counter->current_tick++;
    /*  if tickperbase is reached, the counter is inc   */
    if (counter->current_tick == counter->ticks_per_base)
    {
        counter->current_tick = 0;
        counter->current_date++;
        date = counter->current_date;
        /*  check if the counter has reached the
            next alarm activation date  */
        alarm = counter->next_alarm_to_raise;

        while ((alarm != NULL) && (alarm->date == date))
        {
            /*  note : alarm is always the next_alarm_to_raise
                since removing the alarm from the queue will
                advance next_alarm_to_raise along the queue     */
            
            /*  get the alarm from the queue    */
            tpl_remove_alarm(alarm);
            /*  raise it    */
            need_resched |=
                (TRAMPOLINE_STATUS_MASK & tpl_raise_alarm(alarm));
            /*  get the next alarm to raise     */
            alarm = counter->next_alarm_to_raise;
        }
    }
	return need_resched;
}

/* End of file tpl_alarm_kernel.c */
