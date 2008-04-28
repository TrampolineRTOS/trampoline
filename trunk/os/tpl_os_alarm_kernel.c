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

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * tpl_insert_time_obj
 * insert a time object in the time object queue of the counter
 * it belongs to.
 *
 * The time object list of a counter is a double-linked list
 * and a time object is inserted starting from the
 * head of the list
 */
FUNC(void, OS_CODE) tpl_insert_time_obj(
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC) time_obj)
{
    /*  get the counter                                                     */
    P2VAR(tpl_counter, OS_APPL_DATA, AUTOMATIC)   counter = time_obj->stat_part->counter;
    /*  initialize the current time object to the head                      */
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC)  current_to = counter->first_to;
    /*  initialize the time object that precede the current one to NULL     */
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC)  prev_to = NULL;

    if (current_to == NULL)
    {
        /*  The time object queue is empty
            So the time object is alone in the queue                        */
        counter->first_to = time_obj;
        counter->next_to = time_obj;
        time_obj->next_to = time_obj->prev_to = NULL;
    }
    else
    {
        /*  The time object queue is not empty
            look for the place to insert the alarm                          */
        while ((current_to != NULL) &&
               (current_to->date <= time_obj->date))
        {
            prev_to = current_to;
            current_to = current_to->next_to;
        }

        time_obj->next_to = current_to;
        time_obj->prev_to = prev_to;

        /*  insert the alarm    */
        if (current_to != NULL)
        {
            current_to->prev_to = time_obj;
        }
        if (prev_to != NULL)
        {
            /*  add at the end of the queue or insert                       */
            prev_to->next_to = time_obj;
        }
        else
        {
            /*  the condition current_to->date <= time_object->date was
                false a the beginning of the while. So the time object
                have to be added at the head of the time object queue       */
            counter->first_to = time_obj;
        }

        /*  Update the next_to to point to the newly
            inserted time_object if the date of the newly inserted time
            object is within the current date and the next_alarm_to_raise
            date, taking account the modulo                                 */
        if (counter->next_to->date < counter->current_date)
        {
            if ((time_obj->date > counter->current_date) ||
                (time_obj->date < counter->next_to->date))
            {
                counter->next_to = time_obj;
            }
        }
        else
        {
            if ((time_obj->date > counter->current_date) &&
                (time_obj->date < counter->next_to->date))
            {
                counter->next_to = time_obj;
            }
        }
    }
}

/*
 * tpl_remove_alarm
 * remove an alarm from the alarm queue of the counter
 * it belongs to.
 */
FUNC(void, OS_CODE) tpl_remove_time_obj(
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC) time_obj)
{

    P2VAR(tpl_counter, OS_APPL_DATA, AUTOMATIC) counter = time_obj->stat_part->counter;

    /*  adjust the head of the queue if the
        removed alarm is at the head            */
    if (time_obj == counter->first_to)
    {
        counter->first_to = time_obj->next_to;
    }
    /*  adjust the next alarm to raise if it is
        the removed alarm                       */
    if (time_obj == counter->next_to)
    {
        counter->next_to = time_obj->next_to;
    }
    /*  build the link between the previous and next alarm in the queue */
    if (time_obj->next_to != NULL)
    {
        time_obj->next_to->prev_to = time_obj->prev_to;
    }
    if (time_obj->prev_to != NULL)
    {
        time_obj->prev_to->next_to = time_obj->next_to;
    }
    /*  if the next_alarm_to_raise was pointing to the
        alarm and the alarm was at the end of the queue
        next_alarm_to_raise is NULL and must be reset to
        the first alarm of the queue                        */
    if (counter->next_to == NULL)
    {
        counter->next_to = counter->first_to;
    }
}

/**
 * @internal
 *
 * tpl_raise_alarm is called by tpl_counter_tick
 * when an alarm time object is raised.
 *
 * @param time_obj  The alarm to raise.
 */
FUNC(tpl_status, OS_CODE) tpl_raise_alarm(
    P2CONST(tpl_time_obj, OS_APPL_DATA, AUTOMATIC) time_obj)
{
    VAR(tpl_status, AUTOMATIC) result = E_OK;

    /*
     * A tpl_time_obj_static * is cast to a tpl_alarm_static *
     * This violate MISRA rule 45. However, since the
     * first member of tpl_alarm_static is a tpl_time_obj_static
     * This cast behaves correctly.
     */
    /*  Get the alarm descriptor                            */
    P2VAR(tpl_alarm_static, OS_APPL_DATA, AUTOMATIC) stat_alarm = (tpl_alarm_static *)time_obj->stat_part;
    /*  Get the action to perform from the alarm descriptor */
    P2CONST(tpl_action, OS_APPL_CONST, AUTOMATIC) action_desc = stat_alarm->action;

    /*  Call the action                                     */
    result = (action_desc->action)(action_desc) ;

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
FUNC(tpl_status, OS_CODE) tpl_counter_tick(
    P2VAR(tpl_counter, OS_APPL_DATA, AUTOMATIC) counter)
{
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC)  t_obj;
    /*
     * A non constant function pointer is used
     * This violate MISRA rule 104. This is used to call
     * the action on each alarm. The function pointed is know at conception time,
     * because only 3 function can be pointed to.
     */
    VAR(tpl_expire_func, AUTOMATIC)               expire;
    VAR(tpl_tick, AUTOMATIC)                      date;
    /* this variable is added because the same name was used twice in this function for
      2 different variables, this behavior was dependent on the compiler */
    VAR(tpl_tick, AUTOMATIC)                      new_date;
    VAR(tpl_status, AUTOMATIC)                    need_resched = NO_SPECIAL_CODE;

    /*  inc the current tick value of the counter   */
    counter->current_tick++;
    /*  if tickperbase is reached, the counter is inc   */
    if (counter->current_tick == counter->ticks_per_base)
    {
        date = counter->current_date;
        if (date == counter->max_allowed_value)
        {
            date = 0;
        }
        else
        {
            date++;
        }
        counter->current_date = date;
        counter->current_tick = 0;

        /*  check if the counter has reached the
            next alarm activation date  */
        t_obj = counter->next_to;

        while ((t_obj != NULL) && (t_obj->date == date))
        {
            /*  note : time_obj is always the next_to
                since removing the time object from the queue will
                advance next_to along the queue                     */

            /*  get the time object from the queue                  */
            tpl_remove_time_obj(t_obj);

            /*  raise it    */
            expire = t_obj->stat_part->expire;
            need_resched |=
                (TRAMPOLINE_STATUS_MASK & expire(t_obj));

            /*  rearm the alarm if needed   */
            if (t_obj->cycle != 0)
            {
                /*  if the cycle is not 0,
                    the new date is computed
                    by adding the cycle to the current date         */
                new_date = t_obj->date + t_obj->cycle;
                if (new_date > counter->max_allowed_value)
                {
                    new_date -= counter->max_allowed_value;
                }
                t_obj->date = new_date;
                /*  and the alarm is put back in the alarm queue
                    of the counter it belongs to                    */
                tpl_insert_time_obj(t_obj);
            }
            else {
                t_obj->state = TIME_OBJ_SLEEP;
            }

            /*  get the next alarm to raise     */
            t_obj = counter->next_to;
        }
    }
    return need_resched;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_alarm_kernel.c */
