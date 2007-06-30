/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
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

#include "tpl_os_it_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os.h"
#include "tpl_os_application_def.h"
#include "tpl_machine_interface.h"

#ifndef NO_ISR

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

static void tpl_activate_isr(tpl_isr *a_isr);

/*
 */
static void tpl_activate_isr(tpl_isr *a_isr)
{
    if (a_isr->exec_desc.activate_count <
        a_isr->exec_desc.static_desc->max_activate_count)
    {
        /*  check the task is in the SUSPENDED state before moving it       */
        if (a_isr->exec_desc.state == (tpl_exec_state)SUSPENDED)
        {
            /*  init the task       */
            tpl_init_exec_object(&(a_isr->exec_desc));
            /*  put it in the list  */
            tpl_put_exec_object(
                &(a_isr->exec_desc),
                (u8)NEWLY_ACTIVATED_EXEC_OBJ
            );
        }
        /*  inc the task activation count. When the task will terminate
            it will dec this count and if not zero it will be reactivated   */
        a_isr->exec_desc.activate_count++;
    }
}
 
/*
 * The central interrupt handler is called by the interrupt handler
 * with the id of the interrupt (usually its priority) as parameter
 * tpl_central_interrupt_handler saves the context of the interrupted
 * task / interrupt handler, switches to the context of the handler
 * and calls the handler
 */
void tpl_central_interrupt_handler(const u16 id)
{
    static s32 tpl_it_nesting =  0;
    tpl_isr                     *a_isr_desc;
    
	/*  Is there a handler for this id ?
		ie the id has been counted in the table and there
		is a tpl_isr available
    */
#ifdef OS_EXTENDED
    if (id < ISR_COUNT)
    {
#endif
        tpl_it_nesting++;
            
        a_isr_desc = tpl_isr_table[id];

        if (a_isr_desc != NULL)
        {
            if ((a_isr_desc->static_desc->next) == NULL)
            {
                /*  Only one handler for this id. run the handler   */
                tpl_activate_isr(a_isr_desc);
            }
            else
            {
                /*  look for the handler    */
                while (a_isr_desc != NULL)
                {
                    if (a_isr_desc->static_desc->helper() == TRUE)
                    {
                        /* activate the handler */
                        tpl_activate_isr(a_isr_desc);
                    }
                    a_isr_desc = a_isr_desc->static_desc->next;
                }
            }
        }
        
        tpl_it_nesting--;
        
        if (tpl_it_nesting == 0)
        {
            tpl_schedule((u8)FROM_IT_LEVEL);
        }
#ifdef OS_EXTENDED
    }
#endif
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* NO_ISR */

/* End of file tpl_os_it_kernel.c */
