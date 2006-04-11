/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline kernel structures
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

void tpl_context_switch(tpl_context *, tpl_context *);
void tpl_init_context(tpl_exec_common *);
void tpl_get_task_lock(void);
void tpl_release_task_lock(void);

/*
 * idle_task is the task descriptor of the kernel task
 * used when no other task is ready. The OS starts
 * by setting this task as the running task (ie the
 * init code currently being run.
 * It then calls tpl_schedule to start the
 * multitasking and falls back in an infinite loop.
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

/*
 * tpl_running_task is the currently running
 * task in the application.
 * At system startup it is set to the
 * idle task
 */
tpl_exec_common *tpl_running_obj = (tpl_exec_common *)&idle_task;

/*
 * tpl_task_list_head is the head of the task list
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

/*
 * tpl_os_state stores the current state of Trampoline
 * it is set when the OS go from a state to another one
 * and used in various services. For instance, if the
 * OS is in the ISR state, tpl_schedule is not executed
 * and is postponed at the end of the ISR execution
 */
unsigned char tpl_os_state = OS_INIT;

/*
 * RES_SCHEDULER is used to deny preemption
 * It can be used by a task but is not stored
 * in the resource table.  
 */
tpl_resource_id RES_SCHEDULER = -1;

tpl_resource res_scheduler;

/*
 * various locks in the kernel
 */
tpl_lock tpl_task_lock = { NULL, NULL};
tpl_lock *TASK_LOCK = &tpl_task_lock;

/*
 * tpl_get_exec_object get the higher priority ready executable
 * object from the executable objects list and returns it.
 * tpl_get_exec_object returns NULL if no ready executable object
 * is available
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

/*
 * tpl_put_exec_object put an executable object
 * in the ready executable object list
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


/*
 * executable object initialization.
 * This function initialize the common part of task
 * and isr to ready them for execution. If the object is
 * a task it init the event masks too.
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

/*
 * OS initialization
 */
void tpl_init_os(void)
{
#ifndef NO_TASK

    int         i;
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
}

