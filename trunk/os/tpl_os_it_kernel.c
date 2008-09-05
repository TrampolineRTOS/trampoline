/**
 * @file tpl_os_interrupts.c
 *
 * @section desc File description
 *
 * Trampoline interrupt service routines management
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
#include "tpl_os_it_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os.h"
#include "tpl_os_application_def.h"
#include "tpl_machine_interface.h"

#ifdef WITH_AUTOSAR_STACK_MONITORING
#include "tpl_as_stack_monitor.h"
#endif /* WITH_AUTOSAR_STACK_MONITORING */

#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#endif

#ifndef NO_ISR

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

STATIC FUNC(void, OS_CODE) tpl_activate_isr(
    P2VAR(tpl_isr, AUTOMATIC, OS_APPL_DATA) a_isr);

/*
 */
STATIC FUNC(void, OS_CODE) tpl_activate_isr(
    P2VAR(tpl_isr, AUTOMATIC, OS_APPL_DATA) a_isr)
{
    /*  MISRA RULE 33 VIOLATION: the right statement does
        not need to be executed if the first test fails
    */
    if ((a_isr->exec_desc.activate_count <
        a_isr->exec_desc.static_desc->max_activate_count)
#ifdef WITH_AUTOSAR
        && (tpl_is_isr2_enabled(a_isr))
#endif

        )
    {
        /*  check the isr is in the SUSPENDED state before moving it        */
        if (a_isr->exec_desc.state == (tpl_exec_state)SUSPENDED)
        {
            /*  init the isr       */
            tpl_init_exec_object(&(a_isr->exec_desc));
            /*  put it in the list  */
            tpl_put_new_exec_object(&(a_isr->exec_desc));
        }
        /*  inc the isr activation count. When the isr will terminate
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
FUNC(void, OS_CODE) tpl_central_interrupt_handler(CONST(u16, AUTOMATIC) id)
{
    _STATIC_ VAR(s32, AUTOMATIC) tpl_it_nesting =  0;
    P2VAR(tpl_isr, AUTOMATIC, OS_APPL_DATA) a_isr_desc;

#ifdef WITH_AUTOSAR_STACK_MONITORING
    tpl_check_stack(tpl_running_obj);
#endif /* WITH_AUTOSAR_STACK_MONITORING */

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
            if( (u8)OS_IDLE == tpl_os_state )
            {
                tpl_schedule_from_idle();
            }
            else
            {
                tpl_schedule_from_running(FROM_IT_LEVEL);
            }

        }
#ifdef OS_EXTENDED
    }
#endif
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* NO_ISR */

/* End of file tpl_os_it_kernel.c */
