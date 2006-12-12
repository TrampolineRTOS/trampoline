/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protŽégŽé par la loi sur la propriŽétéŽ intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline interrupt service routines management
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_interrupts.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os.h"
#include "tpl_os_hooks.h"
#include "tpl_os_application_def.h"

static int tpl_it_nesting = 0;

void tpl_init_exec_object(tpl_exec_common *);
void tpl_put_exec_object(tpl_exec_common *, int);
void tpl_schedule(int);
void tpl_get_task_lock();
void tpl_release_task_lock();

#ifdef WITH_PRE_TASK_HOOK
/*
 * Prototype of the pre-task hook routine
 */
void PreTaskHook(void);
#endif

#ifdef WITH_POST_TASK_HOOK
/*
 * Prototype of the post-task hook routine
 */
void PostTaskHook(void);
#endif

/*
 */
void tpl_activate_isr(tpl_isr *isr)
{
    if (isr->exec_desc.activate_count <
        isr->exec_desc.static_desc->max_activate_count) {
        /*  check the task is in the SUSPENDED state before moving it       */
        if (isr->exec_desc.state == SUSPENDED) {
            /*  init the task       */
            tpl_init_exec_object(&(isr->exec_desc));
            /*  put it in the list  */
            tpl_put_exec_object(&(isr->exec_desc), NEWLY_ACTIVATED_EXEC_OBJ);
        }
        /*  inc the task activation count. When the task will terminate
            it will dec this count and if not zero it will be reactivated   */
        isr->exec_desc.activate_count++;
    }
}
 
#ifndef NO_ISR
/*
 * The central interrupt handler is called by the interrupt handler
 * with the id of the interrupt (usually its priority) as parameter
 * tpl_central_interrupt_handler saves the context of the interrupted
 * task / interrupt handler, switches to the context of the handler
 * and calls the handler
 */
void tpl_central_interrupt_handler(unsigned int id)
{
    tpl_isr         *isr_desc;
    
	/*  Is there a handler for this id ?
		ie the id has been counted in the table and there
		is a tpl_isr available
    */
#ifdef OS_EXTENDED
    if (id >= ISR_COUNT) {
        return;
    }
#endif
    tpl_it_nesting++;
    	
    isr_desc = tpl_isr_table[id];

	if (isr_desc != NULL) {
		if (isr_desc->static_desc->next == NULL) {
			/*  Only one handler for this id. run the handler   */
			tpl_activate_isr(isr_desc);
        }
        else {
            /*  look for the handler    */
            while (isr_desc != NULL) {
                if (isr_desc->static_desc->helper()) {
                    /* activate the handler */
                    tpl_activate_isr(isr_desc);
                    break;
                }
                isr_desc = isr_desc->static_desc->next;
            }
        }
    }
    
    tpl_it_nesting--;
    
    if (tpl_it_nesting == 0) {
        tpl_schedule(FROM_IT_LEVEL);
    }
}
#endif //NO_ISR

/*
 * TerminateISR
 *
 * While this function is not part of the OSEK API, it is used
 * to terminate an ISR2 routine
 */
StatusType TerminateISR2(void)
{
    tpl_exec_common *exec_obj;
    
#ifdef OS_EXTENDED
    /*  check we are at the task level  */
    if (tpl_os_state != OS_ISR2) {
        return E_OS_CALLEVEL;
    }
    /*  check the task does not own a resource  */
    if (tpl_running_obj->resources != NULL) {
        return E_OS_RESOURCE;
    }
#endif
    
    /*  lock the task structures    */
    tpl_get_task_lock();
    
    /* Call the post task hook */
    CALL_POST_TASK_HOOK()

    /*  get the running task to terminate it    */
    exec_obj = tpl_running_obj;
    tpl_running_obj = NULL;
    
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
    
    /*  unlock the task structures  */
    tpl_release_task_lock();
    
    return E_OK;
}

void EnableAllInterrupts(void)
{
}

void DisableAllInterrupts(void)
{
}

void ResumeAllInterrupts(void)
{
}

void SuspendAllInterrupts(void)
{
}

void ResumeOSInterrupts(void)
{
}

void SuspendOSInterrupts(void)
{
}
