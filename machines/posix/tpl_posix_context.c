/**
 *
 * @file tpl_posix_irq.c
 *
 * @section descr File description
 *
 * Implementation of internal function of Trampoline posix platform
 * for task context creation
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

#define _XOPEN_SOURCE 501
#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#include "tpl_app_config.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"
#include "tpl_os_types.h"
#include "tpl_machine_posix.h"

/**
 * global variables used to store the "old" context
 * during the trampoline phase used to create a new context
 */
VAR(sigset_t,OS_VAR)        saved_mask;
VAR(sig_atomic_t,OS_VAR)    handler_has_been_triggered;
VAR(tpl_proc_id,OS_VAR)     new_proc_id;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_create_context_boot(void)
{
    tpl_proc_id context_owner_proc_id;

    /*
     * 10 : restore the mask modified by longjmp so that
     * all tasks are executed with the same mask
     * Commented out since longjmp/setjmp replace longjmp/setjmp
     */
    sigprocmask(SIG_SETMASK, &saved_mask, NULL);

    /* 11 : store the id of the owner of this context */
    context_owner_proc_id = new_proc_id;

    /* 12 & 13 : context is ready, jump back to the tpl_create_context */
    if( 0 == setjmp(tpl_stat_proc_table[context_owner_proc_id]->context->initial) )
    {
        longjmp(tpl_stat_proc_table[IDLE_TASK_ID]->context->current, 1);
    }

    /* We are back for the first dispatch. Let's go */
    tpl_osek_func_stub(tpl_kern.running_id);

    /* We should not be there. Let's crash*/
    abort();
    return;
}

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_create_context_trampoline(int sigid)
{
    (void) sigid;

    /* 5 : new context created. We go back to tpl_init_context */
    if( 0==setjmp(tpl_stat_proc_table[new_proc_id]->context->initial) )
    {
        handler_has_been_triggered = TRUE;
        return;
    }

    /*
     * 9 : we are back after a jump, but no more in signal handling mode
     * We are ready to boot the new context with a clean stack
     */
    tpl_create_context_boot();
    return;
}

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_create_context(
        CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
    struct sigaction new_action;
    struct sigaction old_action;
    stack_t new_stack;
    stack_t old_stack;
    sigset_t new_mask;
    sigset_t old_mask;

    /* 1 : save the current mask, and mask our worker signal : SIGUSR1 */
    sigemptyset(&new_mask);
    sigaddset(&new_mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &new_mask, &old_mask);

    /*
     * 2 : install the new action for our worker signal.
     * Triggered function : tpl_init_context_trampoline.
     * It will be executed on its own stack (that is the trick).
     * When it will be executed, all signals will be blocked.
     */
    memset((void*)&new_action, 0, sizeof(new_action));
    new_action.sa_handler = tpl_create_context_trampoline;
    new_action.sa_flags = SA_ONSTACK;
    sigemptyset(&new_action.sa_mask);
    sigaction(SIGUSR1, &new_action, &old_action);

    /* 3 : prepare the new stack */
    new_stack.ss_sp = (tpl_stat_proc_table[proc_id]->stack)->stack_zone;
    new_stack.ss_size = (tpl_stat_proc_table[proc_id]->stack)->stack_size;
    new_stack.ss_flags = 0;
    sigaltstack(&new_stack, &old_stack);

    /* 4-a : store data for new context in globals */
    new_proc_id = proc_id;
    saved_mask = old_mask;
    handler_has_been_triggered = FALSE;
    /* 4-b : send the worker signal */
    kill(getpid(), SIGUSR1);
    /* 4-c : prepare to unblock the worker signal */
    sigfillset(&new_mask);
    sigdelset(&new_mask, SIGUSR1);
    /*
     * 4-d : unblock the worker signal and wait for it.
     * Once it is arrived, the previous mask is restored.
     */
    while(FALSE == handler_has_been_triggered)
        sigsuspend(&new_mask);

    /*
     * 6 : we are back from tpl_init_context_trampoline.
     * We can restore the previous signal handling configuration
     */
    sigaltstack(NULL, &new_stack);
    new_stack.ss_flags = SS_DISABLE;
    sigaltstack(&new_stack, NULL);
    if( ! (old_stack.ss_flags & SS_DISABLE) )
        sigaltstack(&old_stack, NULL);
    sigaction(SIGUSR1, &old_action, NULL);
    sigprocmask(SIG_SETMASK, &old_mask, NULL);

    /*
     * 7 & 8 : we jump back to the created context.
     * This time, we are no more in signal handling mode
     */
    if ( 0 == setjmp(tpl_stat_proc_table[IDLE_TASK_ID]->context->current) )
        longjmp(tpl_stat_proc_table[new_proc_id]->context->initial,1);

    /*
     * 14 : we go back to the caller
     */
    return;
}

