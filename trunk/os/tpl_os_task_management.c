/**
 * @file tpl_os_task_management.c
 *
 * @section desc File description
 *
 * Trampoline Task Management Calls
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
 */
 
#include "tpl_os.h"
#include "tpl_os_kernel.h"
#include "tpl_os_error.h"
#include "tpl_os_hooks.h"

/*
 * Prototypes of kernel fonctions
 */
extern tpl_exec_common *tpl_get_exec_object(void);
extern void tpl_put_exec_object(tpl_exec_common *, int);
extern void tpl_init_exec_object(tpl_exec_common *);
extern void tpl_get_task_lock(void);
extern void tpl_release_task_lock(void);

/*
 * Prototypes of machine dependent functions
 */
extern void tpl_switch_context(tpl_context *, tpl_context *);
extern void tpl_switch_context_from_it(tpl_context *, tpl_context *);

#ifdef WITH_PRE_TASK_HOOK
/*
 * Prototype of the pre-task hook routine
 */
extern void PreTaskHook(void);
#endif

#ifdef WITH_POST_TASK_HOOK
/*
 * Prototype of the post-task hook routine
 */
extern void PostTaskHook(void);
#endif

/*
 * Declaration of the idle task descriptor
 */
extern tpl_task idle_task;

/**
 * @internal
 *
 * Get an internal resource
 *
 * @param task task from which internal resource is got
 */
void tpl_get_internal_resource(tpl_exec_common *task)
{
    tpl_internal_resource *rez = task->static_desc->internal_resource;
    
    if (rez != NULL && !rez->taken) {
        rez->taken = TRUE;
        rez->owner_prev_priority = task->priority;
        task->priority = rez->ceiling_priority;
    }
}

/**
 * @internal
 *
 * Release an internal resource
 *
 * @param task task from which internal resource is released
 */
void tpl_release_internal_resource(tpl_exec_common *task)
{
    tpl_internal_resource *rez = task->static_desc->internal_resource;

    if (rez != NULL && rez->taken) {
        rez->taken = FALSE;
        task->priority = rez->owner_prev_priority;
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
void tpl_schedule(int from)
{
    tpl_exec_common *old_running_obj;
    tpl_exec_common *exec_obj;
    
    /*  save the old running task for context switching */
    old_running_obj = tpl_running_obj;
    /*  get the ready task with the higher priority     */
    exec_obj = tpl_exec_obj_list_head;
    
    if  (exec_obj != NULL) {
        /*  there is a ready task   */
        if (tpl_running_obj != NULL) {
            /*  There is a running task
                get the priorities and compare them     */
            if (tpl_running_obj->state != RUNNING ||
                exec_obj->priority > tpl_running_obj->priority) {
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
                if (tpl_running_obj->state == RUNNING) {
                    /*  the current running task become READY           */
                    tpl_running_obj->state = READY;
                    /*  put the running task in the ready task list     */
                    /*  Bug fix. preempted objects are put at the head
                        of the set while newly activated objects are
                        put at the end of the set. So we have to
                        distinguish them                                */
                    tpl_put_exec_object(tpl_running_obj, PREEMPTED_EXEC_OBJ);
                }
                else {
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
        else {
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
    if (tpl_running_obj != old_running_obj) {
        /*  Set the state of the OS according to the running task   */
        if (tpl_running_obj == (tpl_exec_common *)&idle_task) {
            tpl_os_state = OS_IDLE;
        }
        else if (tpl_running_obj->static_desc->type == IS_ROUTINE) {
            tpl_os_state = OS_ISR2;
        }
        else {
            tpl_os_state = OS_TASK;
        }
        /*  Switch the context  */
        if (from == FROM_TASK_LEVEL) {
            if (old_running_obj != NULL) {
                tpl_switch_context(
                    &(old_running_obj->static_desc->context),
                    &(tpl_running_obj->static_desc->context));
            }
            else {
                tpl_switch_context(
                    NULL,
                    &(tpl_running_obj->static_desc->context));
            }
        }
        else { /* FROM_IT_LEVEL */
            if (old_running_obj != NULL) {
                tpl_switch_context_from_it(
                    &(old_running_obj->static_desc->context),
                    &(tpl_running_obj->static_desc->context));
            }
            else {
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
tpl_status tpl_activate_task(tpl_task *task)
{
    tpl_status result = E_OS_LIMIT;

    if (task->exec_desc.activate_count <
        task->exec_desc.static_desc->max_activate_count) {
        /*  check the task is in the SUSPENDED state before moving it       */
        if (task->exec_desc.state == SUSPENDED) {
            /*  init the task       */
            tpl_init_exec_object(&(task->exec_desc));
            /*  put it in the list  */
            tpl_put_exec_object(&(task->exec_desc), NEWLY_ACTIVATED_EXEC_OBJ);
        }
        /*  inc the task activation count. When the task will terminate
            it will dec this count and if not zero it will be reactivated   */
        task->exec_desc.activate_count++;

        result = E_OK_AND_SCHEDULE;
    }

    return result;
}


/*
 * OSEK/VDX API services
 *
 * see header file documentation or refer to the OSEK/VDX 2.2.2 specification
 */

StatusType ActivateTask(TaskType task_id)
{
    /*  init the error to no error  */
    StatusType result = E_OK;
    
    /*  lock the task structures    */
    LOCK_WHEN_TASK()
    
    /*  store information for error hook routine    */
    STORE_SERVICE(OSServiceId_ActivateTask)
    STORE_TASK_ID(task_id)
    
    /*  Check a task_id error   */
    CHECK_TASK_ID_ERROR(task_id,result)
    
#ifndef NO_TASK
    IF_NO_EXTENDED_ERROR(result)
        result = tpl_activate_task(tpl_task_table[task_id]);
        if (result == E_OK_AND_SCHEDULE) {
            tpl_schedule(FROM_TASK_LEVEL);
            result &= OSEK_STATUS_MASK;
        }
    END_IF_NO_EXTENDED_ERROR()
#endif
    
    PROCESS_ERROR(result)

    /*  unlock the task structures  */
    UNLOCK_WHEN_TASK()
    
    return result;
}

StatusType TerminateTask(void)
{
    /*  init the error to no error  */
    StatusType result = E_OK;

#ifndef NO_TASK
    tpl_exec_common *exec_obj;
#endif
        
    /*  lock the task structures    */
    LOCK_WHEN_TASK()
    
    /*  store information for error hook routine    */
    STORE_SERVICE(OSServiceId_TerminateTask)
    
    /*  check we are at the task level  */
    CHECK_TASK_CALL_LEVEL_ERROR(result)
    /*  check the task does not own a resource  */
    CHECK_RUNNING_OWNS_REZ_ERROR(result)

#ifndef NO_TASK
    IF_NO_EXTENDED_ERROR(result)
    
        /* Call the post task hook */
        CALL_POST_TASK_HOOK()

        /*  get the running task to terminate it    */
        exec_obj = tpl_running_obj;
        tpl_running_obj = NULL;
        
        /*  release the internal resource   */
        tpl_release_internal_resource(exec_obj);
        
        /*  dec the activation count    */
        exec_obj->activate_count--;
        
        if (exec_obj->activate_count > 0) {
            /*  the task got multiple activations
                so instead of returning it to the SUSPENDED state
                it is inited again and put back in the ready task list  */
            exec_obj->state = READY;
            tpl_init_exec_object(exec_obj);
            tpl_put_exec_object(exec_obj, NEWLY_ACTIVATED_EXEC_OBJ);
        }
        else {
            /*  the task is SUSPENDED   */
            exec_obj->state = SUSPENDED;
        }

        tpl_schedule(FROM_TASK_LEVEL);
    END_IF_NO_EXTENDED_ERROR()
#endif

    PROCESS_ERROR(result)
    
    /*  unlock the task structures  */
    UNLOCK_WHEN_TASK()

    return result;
}

StatusType ChainTask(TaskType task_id)
{
    StatusType result = E_OK;

#ifndef NO_TASK
    tpl_exec_common *r_exec_obj;
    tpl_exec_common *exec_obj;
#endif

    /*  lock the task system    */
    LOCK_WHEN_TASK()

    /*  store information for error hook routine    */
    STORE_SERVICE(OSServiceId_ChainTask)
    STORE_TASK_ID(task_id)
    
    /*  Check a call level error    */
    CHECK_TASK_CALL_LEVEL_ERROR(result)
    /*  Check a task_id error       */
    CHECK_TASK_ID_ERROR(task_id,result)
    /*  Check no resource is held by the terminating task   */
    CHECK_RUNNING_OWNS_REZ_ERROR(result)

#ifndef NO_TASK
    IF_NO_EXTENDED_ERROR(result)

        /* Call the post task hook */
        CALL_POST_TASK_HOOK()

        /*  get the running object      */
        r_exec_obj = tpl_running_obj;
        tpl_running_obj = NULL;
        
        /*  release the internal resource   */
        tpl_release_internal_resource(r_exec_obj);
        
        exec_obj = (tpl_exec_common *)(tpl_task_table[task_id]); 
        
        if (r_exec_obj == exec_obj) {
            /*  tasks are the same. So the task is put
                back in the ready list after init.      */
            tpl_init_exec_object(exec_obj);
            tpl_put_exec_object(exec_obj, NEWLY_ACTIVATED_EXEC_OBJ);
        }
        else {
            /*  terminate the calling task
                dec the activation count of the calling task    */
            r_exec_obj->activate_count--;
            
            if (r_exec_obj->activate_count > 0) {
                /*  the task got multiple activations
                    so instead of returning it to the SUSPENDED state
                    it is inited again and put back in the ready task list  */
                tpl_init_exec_object(r_exec_obj);
                tpl_put_exec_object(r_exec_obj, NEWLY_ACTIVATED_EXEC_OBJ);
            }
            else {
                /*  the task is SUSPENDED   */
                r_exec_obj->state = SUSPENDED;
            }
            
            /*  activate the new task   */
            if (exec_obj->activate_count <
                exec_obj->static_desc->max_activate_count) {
                /*  check the task is in the SUSPENDED
                    state before moving it   */
                if (exec_obj->state == SUSPENDED) {
                    /*  init the task   */
                    tpl_init_exec_object(exec_obj);
                    /*  put it in the list  */
                    tpl_put_exec_object(exec_obj, NEWLY_ACTIVATED_EXEC_OBJ);
                    
                    result = E_OK;
                }
                /*  inc the stack activation count. When the task will
                    terminate, it will dec this count and if not zero
                    it will be reactivated                              */
                exec_obj->activate_count++;
            }
        }
            
        tpl_schedule(FROM_TASK_LEVEL);
    END_IF_NO_EXTENDED_ERROR()
#endif
    
    PROCESS_ERROR(result)
    
    /*  unlock the task structures  */
    UNLOCK_WHEN_TASK()
    
    return result;
}

StatusType Schedule(void)
{
    StatusType result = E_OK;
    
    /*  lock the task system    */
    LOCK_WHEN_TASK()
    
    /*  store information for error hook routine    */
    STORE_SERVICE(OSServiceId_Schedule)

    /*  Check a call level error    */
    CHECK_TASK_CALL_LEVEL_ERROR(result)
    /*  Check no resource is held by the calling task   */
    CHECK_RUNNING_OWNS_REZ_ERROR(result)
    
#ifndef NO_TASK
    IF_NO_EXTENDED_ERROR(result)
        /*  release the internal resource   */
        tpl_release_internal_resource(tpl_running_obj);
        /*  does the rescheduling           */
        tpl_schedule(FROM_TASK_LEVEL);
    END_IF_NO_EXTENDED_ERROR()
#endif
    
    PROCESS_ERROR(result)

    /*  unlock the task structures  */
    UNLOCK_WHEN_TASK()
    
    return result;
}

StatusType GetTaskID(TaskRefType task_id)
{
    /*  get the task id from the task descriptor.
        note : the idle task has an id set to INVALID_TASK
        Done when the idle task is running, tpl_get_task_id
        returns naturally INVALID_TASK in task_id   */
    *task_id = tpl_running_obj->static_desc->id;
    
    return E_OK;
}

StatusType GetTaskState(TaskType task_id,TaskStateRefType state)
{
    StatusType result = E_OK;
    
    LOCK_WHEN_HOOK()
    
    /*  store information for error hook routine    */
    STORE_SERVICE(OSServiceId_GetTaskState)
    STORE_TASK_STATE_REF(state)

    /*  Check a task_id error       */
    CHECK_TASK_ID_ERROR(task_id,result)
    
#ifndef NO_TASK
    IF_NO_EXTENDED_ERROR(result)
        *state = ((tpl_exec_common *)(tpl_task_table[task_id]))->state;
    END_IF_NO_EXTENDED_ERROR()
#endif

    PROCESS_ERROR(result)

    UNLOCK_WHEN_HOOK()
    
    return result;
}
