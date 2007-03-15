/**
 * @file tpl_os_kernel.c
 *
 * @section descr File description
 *
 * Trampoline kernel structures and functions. These functions are used
 * internally by trampoline and should not be used directly.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
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
 *
 */

#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_hooks.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"

static /*@null@*/ tpl_exec_common *tpl_get_exec_object(void);
static void tpl_get_internal_resource(tpl_exec_common *a_task);

/*
 * idle_task is the task descriptor of the kernel task
 * used when no other task is ready. The OS starts
 * by setting this task as the running task (ie the
 * init code currently being run.
 * It then calls tpl_schedule to start the
 * multitasking and falls back in an infinite loop.
 */

/**
 * @internal
 *
 * static part of the idle task descriptor
 *
 * @see #idle_task
 */
static tpl_exec_static idle_task_static = {
    /* context              */  IDLE_CONTEXT,
    /* no stack             */  IDLE_STACK,
    /* no entry point       */  NULL,
    /* internal resource    */  NULL,
    /* id is INVALID_TASK   */  INVALID_TASK,
    /* base priority is -1  */  -1,
    /* max activate count   */  1,
    /* type is BASIC        */  TASK_BASIC
};

/**
 * @internal
 *
 * idle task descriptor
 */
static tpl_task idle_task = {
    /*  Common members  */
    {
    /* static descriptor    */  &idle_task_static,
    /* resources            */  NULL,
    /* next task            */  NULL,
    /* next set             */  NULL,
    /* activation count     */  0,
    /* priority             */  -1,
    /* state                */  RUNNING
    },
    /* task members */
    /* event set            */  0,
    /* event wait           */  0
};

/**
 * @internal 
 *
 * tpl_running_obj is the currently running task in the application.
 *
 * At system startup it is set to the idle task
 */
tpl_exec_common *tpl_running_obj = (tpl_exec_common *)&idle_task;

/**
 * @internal
 *
 * tpl_task_list_head is the head of the ready task list
 * it points to the most higher priority task.
 */
static tpl_exec_common *tpl_exec_obj_list_head = NULL;

/*
 * tpl_last_result store the last error
 * encountered by Trampoline.
 * It is used has a return value
 * for some OS services and for the
 * ErrorHook routine
 */
/* tpl_status tpl_last_result = E_OK; */

u8 tpl_os_state = OS_INIT; /* see doc in header file declaration */

tpl_resource_id RES_SCHEDULER = -1;  /* see doc in header declaration */

/**
 * The scheduler resource descriptor
 *
 * @see #RES_SCHEDULER
 */
tpl_resource res_sched = {
    RES_SCHEDULER_PRIORITY, /**< the ceiling priority is defined as the
                                 maximum priority of the tasks of the
                                 application                                */
    0,                      /*   owner_prev_priority                        */
    NULL,                   /*   owner                                      */
    NULL                    /*   next_res                                   */
};

/**
 * INTERNAL_RES_SCHEDULER is an internal resource with the higher task priority
 * in the application. A task is non preemptable when INTERNAL_RES_SCHEDULER
 * is set as internal resource.
 */
tpl_internal_resource INTERNAL_RES_SCHEDULER = {
    RES_SCHEDULER_PRIORITY, /**< the ceiling priority is defined as the
                                 maximum priority of the tasks of the
                                 application                                */
    0,
    NULL
};

/**
 * @internal
 *
 * tpl_get_exec_object extracts the highest priority ready executable
 * object from the executable objects list and returns it.
 * tpl_get_exec_object returns NULL if no ready executable object
 * is available
 *
 * @return highest priority executable object descriptor
 */
static /*@null@*/ tpl_exec_common *tpl_get_exec_object(void)
{
    tpl_exec_common *current = tpl_exec_obj_list_head;
    tpl_exec_common *new_head = NULL;
    
    if (current != NULL)
    {
        if (current->next_exec != NULL)
        {
            /*  if the set does contains other tasks,
                the new_head points to the next task
                of the set and the next_set pointer is
                copied                                  */
            new_head = current->next_exec;
            new_head->next_set = current->next_set;
        }
        else
        {
            /*  if not, the new_head points to the
                next_set                            */
            new_head = current->next_set;
        }
        /*  copy the new_head to the list head  */
        tpl_exec_obj_list_head = new_head;
    }
    return current; 
}

/**
 * @internal
 *
 * tpl_put_exec_object put an executable object
 * in the ready executable object list
 *
 * @param exec_obj address of the executable object descriptor
 * @param kind can be one of #PREEMPTED_EXEC_OBJ or #NEWLY_ACTIVATED_EXEC_OBJ
 */
void tpl_put_exec_object(
    tpl_exec_common *exec_obj,
    const u8        kind)
{
    /*  starting from the head, look for a set
        with the same or lower priority         */
    tpl_exec_common *current = tpl_exec_obj_list_head;
    tpl_exec_common *previous = NULL;

    /*  reset executable object pointers */
    exec_obj->next_set = exec_obj->next_exec = NULL;
    
    /* first, we poll for the right exec object set (find the right priority level) */
    while ((current != NULL) && (current->priority > exec_obj->priority))
    {
        previous = current;
        current = current->next_set;
    }
    
    /*  cond changed from previous == NULL to
        current == NULL && previous == NULL
        so if current->priority <= exec_obj->priority the first time
        the list is not treated as empty
        Mik, 2005-03-01                                             */
    if ((current == NULL) && (previous == NULL))
    {
        /*  if previous is NULL the list was empty.
            so the executable object is alone (do you feel it ;))   */
        tpl_exec_obj_list_head = exec_obj;
    }
    else
    {
        if (current == NULL)
        {
            /*  if current is NULL, the executable object has a lower
                priority than all the others in the list
                too bad, no luck :D                         */
            previous->next_set = exec_obj;
        }
        else
        {
            /*  we are here when the executable object will be added to an
                existing set or will be added to an empty set               */
            if (current->priority == exec_obj->priority)
            {
                if (kind == (u8)NEWLY_ACTIVATED_EXEC_OBJ)
                {
                    /*  if a set was found with the same priority.
                        if it is a newly activated executable object,
                        it is added at the end of an existing set           */
                    while (current->next_exec != NULL)
                    {
                        current = current->next_exec;
                    }
                    current->next_exec = exec_obj;
                }
                else
                {
                    /*  Bug fix. preempted objects are put at the head
                        of the set while newly activated objects are
                        put at the end of the set. So we have to
                        distinguish them
                        Yvon - 2006/03/22                                   */
                    exec_obj->next_exec = current;
                    exec_obj->next_set = current->next_set;
                    current->next_set = NULL;
                    if (previous == NULL)
                    {
                        tpl_exec_obj_list_head = exec_obj;
                    }
                    else
                    {
                        previous->next_set = exec_obj;
                    }
                }
            }
            else
            {
                /*  no set with the same priority was found
                    the task is inserted between the previous and
                    the current
                    if the previous is NULL, the task has to be inserted
                    before the first element of the list in its own set
                    ---
                    Bug fix, if the set needs to be put at the 
                    head of the list, it would not wotk
                    Mik, 2005-03-01                                         */
                if (previous == NULL)
                {
                    tpl_exec_obj_list_head = exec_obj;
                }
                else
                {
                    previous->next_set = exec_obj;
                }
                /*  anyway, the next set is the current one */
                exec_obj->next_set = current;
            }
        }
    }
}

/**
 * @internal
 *
 * Get an internal resource
 *
 * @param task task from which internal resource is got
 */
static void tpl_get_internal_resource(tpl_exec_common *a_task)
{
    tpl_internal_resource *rez = a_task->static_desc->internal_resource;
    
    if ((rez != NULL) && (rez->taken == FALSE))
    {
        rez->taken = TRUE;
        rez->owner_prev_priority = a_task->priority;
        a_task->priority = rez->ceiling_priority;
    }
}

/**
 * @internal
 *
 * Release an internal resource
 *
 * @param task task from which internal resource is released
 */
void tpl_release_internal_resource(tpl_exec_common *a_task)
{
    tpl_internal_resource *rez = a_task->static_desc->internal_resource;

    if ((rez != NULL) && (rez->taken == TRUE))
    {
        rez->taken = FALSE;
        a_task->priority = rez->owner_prev_priority;
    }
}

/**
 * @internal
 *
 * Does the scheduling
 *
 * This function is called by the OSEK/VDX Schedule service
 * and by various function when a rescheduling is needed
 * 
 * @param from can be one of #FROM_TASK_LEVEL or #FROM_IT_LEVEL
 */
void tpl_schedule(const u8 from)
{
    tpl_exec_common *old_running_obj;
    tpl_exec_common *exec_obj;
    
    /*  save the old running task for context switching */
    old_running_obj = tpl_running_obj;
    /*  get the ready task with the higher priority     */
    exec_obj = tpl_exec_obj_list_head;
    
    if  (exec_obj != NULL)
    {
        /*  there is a ready task   */
        if (tpl_running_obj != NULL)
        {
            /*  There is a running task
                get the priorities and compare them     */
            if ((tpl_running_obj->state != (tpl_exec_state)RUNNING) ||
                (exec_obj->priority > tpl_running_obj->priority))
            {
                /*  the running task is not running (it has been put in
                    the WAITING state of has not the higher priority).
                    So a task switch will occur. It is time to call
                    the PostTaskHook while the soon descheduled task
                    is running                                          */
                CALL_POST_TASK_HOOK()
                /*  get the ready task from the ready task list         */
                exec_obj = tpl_get_exec_object();
                
                /*  test wether the currently "running" task lose
                    the CPU because it has not the higher priority
                    or because it has been put in the WAITING state     */
                if (tpl_running_obj->state == (tpl_exec_state)RUNNING)
                {
                    /*  the current running task become READY           */
                    tpl_running_obj->state = (tpl_exec_state)READY;
                    /*  put the running task in the ready task list     */
                    /*  Bug fix. preempted objects are put at the head
                        of the set while newly activated objects are
                        put at the end of the set. So we have to
                        distinguish them                                */
                    tpl_put_exec_object(tpl_running_obj, PREEMPTED_EXEC_OBJ);
                }
                else
                {
                    /*  if the task lose the CPU because it has been
                        put in the WAITING state, its internal
                        resource is released                            */
                    tpl_release_internal_resource(tpl_running_obj);
                }
                
                /*  set the task that have been got from the list
                    as the running task                             */
                tpl_running_obj = exec_obj;
                /*  the inserted task become RUNNING                */
                tpl_running_obj->state = RUNNING;
                /*  If an internal resource is assigned to the task
                    and it is not already taken by it, take it      */
                tpl_get_internal_resource(tpl_running_obj); 
                /*  A new task has been elected
                    It is time to call PreTaskHook while the
                    rescheduled task is running                     */
                CALL_PRE_TASK_HOOK()

            }
        }
        else
        {
            /*  There is no running task                            */
            tpl_running_obj = tpl_get_exec_object();
            /*  the inserted task become RUNNING                    */
            tpl_running_obj->state = RUNNING;
            /*  If an internal resource is assigned to the task
                and it is not already taken by it, take it          */
            tpl_get_internal_resource(tpl_running_obj); 
            /*  A new task is prepared to run                       */
            CALL_PRE_TASK_HOOK()
        }
    }
    /*  Check whether the new and the old running task are not the
        same before doing an os state change and a context switch   */
    if (tpl_running_obj != old_running_obj)
    {
        /*  Set the state of the OS according to the running task   */
        if (tpl_running_obj == (tpl_exec_common *)&idle_task)
        {
            tpl_os_state = OS_IDLE;
        }
        else if (tpl_running_obj->static_desc->type == IS_ROUTINE)
        {
            tpl_os_state = OS_ISR2;
        }
        else
        {
            tpl_os_state = OS_TASK;
        }
        /*  Switch the context  */
        if (from == (u8)FROM_TASK_LEVEL)
        {
            if (old_running_obj != NULL)
            {
                tpl_switch_context(
                    &(old_running_obj->static_desc->context),
                    &(tpl_running_obj->static_desc->context));
            }
            else
            {
                tpl_switch_context(
                    NULL,
                    &(tpl_running_obj->static_desc->context));
            }
        }
        else
        { /* FROM_IT_LEVEL */
            if (old_running_obj != NULL)
            {
                tpl_switch_context_from_it(
                    &(old_running_obj->static_desc->context),
                    &(tpl_running_obj->static_desc->context));
            }
            else
            {
                tpl_switch_context_from_it(
                    NULL,
                    &(tpl_running_obj->static_desc->context));
            }
        }
    }
}

/**
 * @internal
 *
 * This function is called by OSEK/VDX ActivateTask and by
 * the raise of an alarm.
 *
 * the activation count is incremented
 * if the task is in the SUSPENDED state, it is moved
 * to the task list
 *
 * @param task reference of the task's identifier
 */
tpl_status tpl_activate_task(tpl_task *a_task)
{
    tpl_status result = E_OS_LIMIT;

    if (a_task->exec_desc.activate_count <
        a_task->exec_desc.static_desc->max_activate_count)
    {
        /*  check the task is in the SUSPENDED state before moving it       */
        if (a_task->exec_desc.state == (tpl_exec_state)SUSPENDED)
        {
            /*  init the task       */
            tpl_init_exec_object(&(a_task->exec_desc));
            /*  put it in the list  */
            tpl_put_exec_object(
                &(a_task->exec_desc),
                (u8)NEWLY_ACTIVATED_EXEC_OBJ
            );
        }
        /*  inc the task activation count. When the task will terminate
            it will dec this count and if not zero it will be reactivated   */
        a_task->exec_desc.activate_count++;

        result = (tpl_status)E_OK_AND_SCHEDULE;
    }

    return result;
}

/**
 * @internal
 * 
 * This function is used by SetEvent and by tpl_raise_alarm
 * 
 * @param task              Pointer to the task descriptor
 * @param incoming_event    Event mask
 */
tpl_status tpl_set_event(
    tpl_task                *a_task,
    const tpl_event_mask    incoming_event)
{
    tpl_status result = E_OK;

    if (a_task->exec_desc.state != (tpl_exec_state)SUSPENDED)
    {
        /*  merge the incoming event mask with the old one  */
        a_task->evt_set = (tpl_event_mask)(a_task->evt_set | incoming_event);
        /*  cross check the event the task is
            waiting for and the incoming event              */
        if ((a_task->evt_wait & incoming_event) != 0)
        {
            /*  the task was waiting for at least one of the event set
                the wait mask is reset to 0                 */
            a_task->evt_wait = (tpl_event_mask)0;
            /*  anyway check it is in the WAITING state     */
            if (a_task->exec_desc.state == (tpl_exec_state)WAITING)
            {
                /*  set the state to READY  */
                a_task->exec_desc.state = (tpl_exec_state)READY;
                /*  put the task in the READY list          */
                tpl_put_exec_object(
                    (tpl_exec_common *)a_task,
                    (u8)NEWLY_ACTIVATED_EXEC_OBJ);
                /*  notify a scheduling needs to be done    */
                result = (tpl_status)E_OK_AND_SCHEDULE;
            }
        }
    }
    else
    {
        result = E_OS_STATE;
    }
    
    return result;
}

/**
 * @internal
 *
 * Executable object initialization.
 *
 * This function initialize the common part of task
 * or category 2 interrupt service routine to make them ready
 * for execution. If the object is an task it initializes
 * the event masks too (this has no effect on basic tasks).
 *
 * @param exec_obj address of the executable object descriptor
 */
void tpl_init_exec_object(tpl_exec_common *exec_obj)
{
    /*  The priority is set to the base priority of the executable object    */
    exec_obj->priority = exec_obj->static_desc->base_priority;
    /*  Set the state to READY (an executable object
        that is inited is put in the READY list  */
    exec_obj->state = READY;
    /*  set the resources list to NULL   */
    exec_obj->resources = NULL;
    /*  both task list links are set to NULL too    */
    exec_obj->next_exec = exec_obj->next_set = NULL;
    /*  context init is machine dependant
        tpl_init_context is defined in tpl_machine.c    */
    tpl_init_context(exec_obj);
    /*  if the object is a task, init the events    */
    if ((exec_obj->static_desc->type & IS_ROUTINE) == 0)
    {
        ((tpl_task *)exec_obj)->evt_set = ((tpl_task *)exec_obj)->evt_wait = 0;
    }
}

/**
 * @internal 
 *
 * Initialization of Trampoline
 */
void tpl_init_os(void)
{
    u16         i;
#ifndef NO_ALARM
    tpl_alarm   *auto_alarm;
#endif

#ifndef NO_TASK
    tpl_task    *auto_task;
    
    /*  Look for autostart tasks    */
        
    for (i = 0; i < TASK_COUNT; i++)
    {
        auto_task = tpl_task_table[i];
        if (auto_task->exec_desc.state == (tpl_exec_state)AUTOSTART)
        {
            /*  each AUTOSTART task is inserted in the READY list   */
            /*  init the task   */
            tpl_init_exec_object((tpl_exec_common *)auto_task);
            /*  inc the activation count. The max_activate_count
                is not tested since it should be a last equal to one  */
            auto_task->exec_desc.activate_count++;
            /*  Put the task in the ready list  */
            tpl_put_exec_object(
                &(auto_task->exec_desc),
                (u8)NEWLY_ACTIVATED_EXEC_OBJ
            );
        }
    }  
#endif
#ifndef NO_ALARM
 
    /*  Look for autostart alarms    */
        
    for (i = 0; i < ALARM_COUNT; i++)
    {
        auto_alarm = tpl_alarm_table[i];
        if (auto_alarm->state == (tpl_alarm_state)ALARM_AUTOSTART)
        {
			tpl_insert_alarm(auto_alarm);
        }
    }  
	
#endif
}

/* End of file tpl_os_kernel.c */
