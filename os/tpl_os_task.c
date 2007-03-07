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
 */
 
#include "tpl_os.h"
#include "tpl_os_kernel.h"
#include "tpl_machine_interface.h"
#include "tpl_os_error.h"
#include "tpl_os_hooks.h"

/*
 * OSEK/VDX API services
 *
 * see header file documentation or refer to the OSEK/VDX 2.2.2 specification
 */

StatusType ActivateTask(const TaskType task_id)
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
        if (result == (tpl_status)E_OK_AND_SCHEDULE)
        {
            tpl_schedule(FROM_TASK_LEVEL);
            result &= OSEK_STATUS_MASK;
        }
    IF_NO_EXTENDED_ERROR_END()
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
        
        if (exec_obj->activate_count > 0)
        {
            /*  the task got multiple activations
                so instead of returning it to the SUSPENDED state
                it is inited again and put back in the ready task list  */
            exec_obj->state = READY;
            tpl_init_exec_object(exec_obj);
            tpl_put_exec_object(exec_obj, NEWLY_ACTIVATED_EXEC_OBJ);
        }
        else
        {
            /*  the task is SUSPENDED   */
            exec_obj->state = SUSPENDED;
        }

        tpl_schedule(FROM_TASK_LEVEL);
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)
    
    /*  unlock the task structures  */
    UNLOCK_WHEN_TASK()

    return result;
}

StatusType ChainTask(const TaskType task_id)
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
        
        if (r_exec_obj == exec_obj)
        {
            /*  tasks are the same. So the task is put
                back in the ready list after init.      */
            tpl_init_exec_object(exec_obj);
            tpl_put_exec_object(exec_obj, NEWLY_ACTIVATED_EXEC_OBJ);
        }
        else
        {
            /*  terminate the calling task
                dec the activation count of the calling task    */
            r_exec_obj->activate_count--;
            
            if (r_exec_obj->activate_count > 0)
            {
                /*  the task got multiple activations
                    so instead of returning it to the SUSPENDED state
                    it is inited again and put back in the ready task list  */
                tpl_init_exec_object(r_exec_obj);
                tpl_put_exec_object(r_exec_obj, NEWLY_ACTIVATED_EXEC_OBJ);
            }
            else
            {
                /*  the task is SUSPENDED   */
                r_exec_obj->state = SUSPENDED;
            }
            
            /*  activate the new task   */
            if (exec_obj->activate_count <
                exec_obj->static_desc->max_activate_count)
            {
                /*  check the task is in the SUSPENDED
                    state before moving it   */
                if (exec_obj->state == SUSPENDED)
                {
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
    IF_NO_EXTENDED_ERROR_END()
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
    IF_NO_EXTENDED_ERROR_END()
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

StatusType GetTaskState(
    const TaskType      task_id,
    TaskStateRefType    state)
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
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    UNLOCK_WHEN_HOOK()
    
    return result;
}

/* End of file tpl_os_task.c */
