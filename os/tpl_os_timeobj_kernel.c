/**
 * @file tpl_os_timeobj_kernel.c
 *
 * @section desc File description
 *
 * Trampoline time object Kernel implementation file. A time object is the
 * parent object of alarms and schedule tables.
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

/*#include "tpl_os_definitions.h"*/
#include "tpl_os_timeobj_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"

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
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) time_obj)
{
    /*  get the counter                                                     */
    P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA)
        counter = time_obj->stat_part->counter;
    /*  initialize the current time object to the head                      */
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)
        current_to = counter->first_to;
    /*  initialize the time object that precede the current one to NULL     */
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)
        prev_to = NULL_PTR;

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
 * tpl_remove_time_obj removes a time object from the time object queue
 * of the counter it belongs to.
 */
FUNC(void, OS_CODE) tpl_remove_time_obj(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) time_obj)
{

    P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter = time_obj->stat_part->counter;

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

/*
 * tpl_remove_timeobj_set removes a consecutive set of time object with
 * the same date starting with the next_to of the counter given as parameter.
 * Added:jlb:2008-09-25. 
 */
STATIC FUNC(void, OS_CODE) tpl_remove_timeobj_set(
    P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter)
{
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) first_to = counter->next_to;
    
    if (first_to != NULL)
    {
        P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)    last_to;
        P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)    t_obj = first_to;
        P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)    af_to;
        VAR(tpl_tick, AUTOMATIC)                        date = first_to->date;
        
        /*  look for the last time object with the same date as the first one   */
        do
        {
            last_to = t_obj;
            t_obj = t_obj->next_to;
        }
        while ((t_obj != NULL) && (t_obj->date == date));
        
        /*  disconnect the chain of object(s). */
        t_obj = first_to->prev_to;
        af_to = last_to->next_to;
        if (t_obj != NULL)
        {
            t_obj->next_to = af_to;
        }
        if (af_to != NULL)
        {
            af_to->prev_to = t_obj;
        }
        /*  if first_to is also the first_to of the queue, update the
            first_to of the counter                     */
        if (counter->first_to == first_to)
        {
            counter->first_to = af_to;
        }
        /*  update the next_to of the counter           */
        if (af_to != NULL) 
        {
            counter->next_to = af_to;
        }
        else
        {
            counter->next_to = counter->first_to;
        }
        /*  update the end of the chain of object(s)    */
        last_to->next_to = NULL;
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
 *
 * Update: 2006-12-10: Does not perform the rescheduling.
 *  tpl_schedule must be called explicitly
 * Bug fix:jlb:2008-09-25 
 *  When 2 alarms or more were scheduled at the same date and their cycle
 *  was also the same, tpl_counter_tick went into an infinite loop because
 *  alarms were put back in the queue at the same date modulo the
 *  max_allowed_value. Now, the alarms at the same date are removed
 *  from the queue by tpl_remove_timeobj_set before being processed.
 */
FUNC(tpl_status, OS_CODE) tpl_counter_tick(
    P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter)
{
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)  t_obj;
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

    /*  inc the current tick value of the counter       */
    counter->current_tick++;
    /*  if tickperbase is reached, the counter is inc   */
    if (counter->current_tick == counter->ticks_per_base)
    {
        date = counter->current_date;
        date++;
        if (date > counter->max_allowed_value)
        {
            date = 0;
        }
        counter->current_date = date;
        counter->current_tick = 0;

        /*  check if the counter has reached the
            next alarm activation date                  */
        t_obj = counter->next_to;
        
        if ((t_obj != NULL) && (t_obj->date == date))
        {
            /*  the date of the counter has reached
                the date of the next time obj.
                extract the time object with this date
                from the list                           */
            tpl_remove_timeobj_set(counter);
            
            do
            {
                tpl_time_obj *next_to = t_obj->next_to; 
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
                /*  get the next one     */
                t_obj = next_to;
            } while (t_obj != NULL);
        }
    }
    return need_resched;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_timeobj_kernel.c */
