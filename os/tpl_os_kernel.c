/**
 * @file tpl_os_kernel.c
 *
 * @section descr File description
 *
 * Trampoline kernel structures
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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
#include "tpl_machine.h"

extern void tpl_context_switch(tpl_context *, tpl_context *);
extern void tpl_init_context(tpl_exec_common *);
extern void tpl_get_task_lock(void);
extern void tpl_release_task_lock(void);

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
tpl_exec_static idle_task_static = {
    /* context              */  IDLE_CONTEXT,
    /* no stack             */  IDLE_STACK,
    /* no entry point       */  NULL,
    /* internal resource    */  NULL,
    /* id is INVALID_TASK   */  INVALID_TASK,
    /* base priority is -1  */  -1,
    /* max activate count   */  1,
    /* type is BASIC        */  BASIC_TASK
};

/**
 * @internal
 *
 * idle task descriptor
 */
tpl_task idle_task = {
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
 * tpl_running_task is the currently running task in the application.
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
tpl_exec_common *tpl_exec_obj_list_head = NULL;

/*
 * tpl_last_result store the last error
 * encountered by Trampoline.
 * It is used has a return value
 * for some OS services and for the
 * ErrorHook routine
 */
/* tpl_status tpl_last_result = E_OK; */

unsigned char tpl_os_state = OS_INIT; /* see doc in header file declaration */

tpl_resource_id RES_SCHEDULER = -1;  /* see doc in header file declaration */

/**
 * The scheduler resource descriptor
 *
 * @see #RES_SCHEDULER
 */
tpl_resource res_scheduler = {
  /* ceiling_priority */    127,
	/* owner_prev_priority */ 0,
	/* owner */               NULL,
	/* next_res */            NULL
};

/**
 * @deprecated
 */
tpl_lock tpl_task_lock = { NULL, NULL};
tpl_lock *TASK_LOCK = &tpl_task_lock; /* deprecated, see in header file */

/**
 * @internal
 *
 * tpl_get_exec_object get the higher priority ready executable
 * object from the executable objects list and returns it.
 * tpl_get_exec_object returns NULL if no ready executable object
 * is available
 *
 * @return highest priority executable object descriptor
 */
tpl_exec_common *tpl_get_exec_object(void)
{
    tpl_exec_common *current = tpl_exec_obj_list_head;
    tpl_exec_common *new_head = NULL;
    
    if (current != NULL) {
        if ((new_head = current->next_exec) != NULL) {
            /*  if the set does contains other tasks,
                the new_head points to the next task
                of the set and the next_set pointer is
                copied                                  */
            new_head->next_set = current->next_set;
        }
        else {
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
void tpl_put_exec_object(tpl_exec_common *exec_obj, int kind)
{
    /*  starting from the head, look for a set
        with the same or lower priority         */
    tpl_exec_common *current = tpl_exec_obj_list_head;
    tpl_exec_common *previous = NULL;
    tpl_exec_common *next = NULL;

    /*  reset executable object pointers */
    exec_obj->next_set = exec_obj->next_exec = NULL;
    
    while (current != NULL && current->priority > exec_obj->priority) {
        previous = current;
        current = current->next_set;
    }
    
    /*  cond changed from previous == NULL to
        current == NULL && previous == NULL
        so if current->priority <= exec_obj->priority the first time
        the list is not treated as empty
        Mik, 2005-03-01                                             */
    if (current == NULL && previous == NULL) {
        /*  if previous is NULL the list was empty.
            so the executable object is alone (do you feel it ;))    */
        tpl_exec_obj_list_head = exec_obj;
    }
    else {
        if (current == NULL) {
            /*  if current is NULL, the executable object has a lower
                priority than all the others in the list
                too bad, no luck :D                         */
            previous->next_set = exec_obj;
        }
        else {
            /*  we are here when the executable object will be added to an
                existing set or will be added to an empty set               */
            if (current->priority == exec_obj->priority) {
                if (kind == NEWLY_ACTIVATED_EXEC_OBJ) {
                    /*  if a set was found with the same priority.
                        if it is a newly activated executable object,
                        it is added at the end of an existing set           */
                    while ((next = current->next_exec) != NULL) {
                        current = next;
                    }
                    current->next_exec = exec_obj;
                }
                else {
                    /*  Bug fix. preempted objects are put at the head
                        of the set while newly activated objects are
                        put at the end of the set. So we have to
                        distinguish them
                        Yvon - 2006/03/22                                   */
                    exec_obj->next_exec = current;
                    exec_obj->next_set = current->next_set;
                    current->next_set = NULL;
                    if (previous == NULL) {
                        tpl_exec_obj_list_head = exec_obj;
                    }
                    else {
                        previous->next_set = exec_obj;
                    }
                }
            }
            else {
                /*  no set with the same priority was found
                    the task is inserted between the previous and
                    the current
                    if the previous is NULL, the task has to be inserted
                    before the first element of the list in its own set
                    ---
                    Bug fix, if the set needs to be put at the 
                    head of the list, it would not wotk
                    Mik, 2005-03-01                                         */
                if (previous == NULL) {
                    tpl_exec_obj_list_head = exec_obj;
                }
                else {
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
    if (! (exec_obj->static_desc->type & IS_ROUTINE)) {
        ((tpl_task *)exec_obj)->evt_set = ((tpl_task *)exec_obj)->evt_wait = 0;
    }
}

extern void tpl_insert_alarm(tpl_alarm *alarm);

/**
 * @internal 
 *
 * Initialization of Trampoline
 */
void tpl_init_os(void)
{
    int         i;
#ifndef NO_ALARM
    tpl_alarm    *alarm;
#endif

#ifndef NO_TASK
    tpl_task    *task;
    
    /*  Look for autostart tasks    */
        
    for (i = 0; i < TASK_COUNT; i++) {
        task = tpl_task_table[i];
        if (task->exec_desc.state == AUTOSTART) {
            /*  each AUTOSTART task is inserted in the READY list   */
            /*  init the task   */
            tpl_init_exec_object((tpl_exec_common *)task);
            /*  inc the activation count. The max_activate_count
                is not tested since it should be a last equal to one  */
            task->exec_desc.activate_count++;
            /*  Put the task in the ready list  */
            tpl_put_exec_object(&(task->exec_desc), NEWLY_ACTIVATED_EXEC_OBJ);
        }
    }  
#endif
#ifndef NO_ALARM
 
    /*  Look for autostart tasks    */
        
    for (i = 0; i < ALARM_COUNT; i++) {
        alarm = tpl_alarm_table[i];
        if (alarm->state == ALARM_AUTOSTART) {
			tpl_insert_alarm(alarm);
        }
    }  
	
#endif
}

