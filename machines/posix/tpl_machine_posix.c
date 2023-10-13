/*
 * Trampoline OS
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline posix machine dependent stuffs
 *
 */

#define _XOPEN_SOURCE 1000

#include "tpl_posix_internal.h"

#include "tpl_machine.h"
#include "tpl_app_config.h"
#include "tpl_os_internal_types.h"
#include "tpl_viper_interface.h"
#include "tpl_os_interrupt_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_machine_interface.h"
#include "tpl_os.h"
#include "tpl_os_application_def.h" /* define NO_ISR if needed. */
#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h" /* for tpl_running_obj */
#include "tpl_as_definitions.h"
#include "tpl_os_task_kernel.h"
#include "tpl_os_resource_kernel.h"
#endif /* WITH_AUTOSAR */

#if defined(__unix__) || defined(__APPLE__)
#include <assert.h>
#endif

#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "tpl_machine_posix.h"
#include "tpl_posixvp_irq_gen.h"

extern volatile int tpl_locking_depth;
extern char tpl_user_task_lock;
extern char tpl_cpt_os_task_lock;

#if TASK_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateTask(void);
#endif

#if ISR_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateISR2(void);
#endif

extern void viper_kill(void);

/*
 * idle_function is used by the idle task
 */
void idle_function(void)
{
    while(1) pause();
}

void tpl_shutdown(void)
{
    tpl_posix_sigblock("tpl_shutdown_failed");
    viper_kill();

    exit(0);
}

volatile int x = 0;
int cnt = 0;
/*
 * tpl_get_task_lock is used to lock a critical section
 * around the task management in the os.
 */
void tpl_get_task_lock(void)
{
    /*
     * block the handling of signals
     */
    if(0 == tpl_locking_depth) {
        tpl_posix_sigblock("tpl_get_lock failed");
    }
    tpl_locking_depth++;
    tpl_cpt_os_task_lock++;
}

/*
 * tpl_release_task_lock is used to unlock a critical section
 * around the task management in the os.
 */
void tpl_release_task_lock(void)
{
#if defined(__unix__) || defined(__APPLE__)
    assert( tpl_locking_depth > 0 );
#endif
    tpl_locking_depth--;
    tpl_cpt_os_task_lock--;

    if ( (tpl_locking_depth == 0) && (FALSE == tpl_user_task_lock) )
    {
        tpl_posix_sigunblock("tpl_release_lock failed");
    }
}

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
    FUNC(void, OS_CODE) tpl_switch_context(
            CONSTP2CONST(tpl_context, AUTOMATIC, OS_CONST) old_context,
            CONSTP2CONST(tpl_context, AUTOMATIC, OS_CONST) new_context)
{
    if( NULL == old_context)
    {
        _longjmp((*new_context)->current, 1);
    }
    else if ( 0 == _setjmp((*old_context)->current) )
    {
        _longjmp((*new_context)->current, 1);
    }
    return;
}

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
    FUNC(void, OS_CODE) tpl_switch_context_from_it(
            CONSTP2CONST(tpl_context, AUTOMATIC, OS_CONST) old_context,
            CONSTP2CONST(tpl_context, AUTOMATIC, OS_CONST) new_context)
{
    if( NULL == old_context )
    {
        _longjmp((*new_context)->current, 1);
    }
    else if ( 0 == _setjmp((*old_context)->current) )
    {
        _longjmp((*new_context)->current, 1);
    }
    return;
}

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_init_context(
        CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
    memcpy( tpl_stat_proc_table[proc_id]->context->current,
            tpl_stat_proc_table[proc_id]->context->initial,
            sizeof(jmp_buf));
}


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
void tpl_osek_func_stub( tpl_proc_id task_id )
{
    tpl_proc_function func = tpl_stat_proc_table[task_id]->entry;
    tpl_proc_type     type = tpl_stat_proc_table[task_id]->type;

    /* Avoid signal blocking due to a previous call to tpl_init_context in a OS_ISR2 context. */
    tpl_release_task_lock();

    (*func)();

    /* Terminate Task/ISR*/
    if (type == IS_ROUTINE) {
#if ISR_COUNT > 0
        CallTerminateISR2();
#endif
    }
    else
    {
#if TASK_COUNT > 0
        CallTerminateTask();
        fprintf(stderr, "[OSEK/VDX Spec. 2.2.3 Sec. 4.7] Ending the task without a call to TerminateTask or ChainTask is strictly forbidden and causes undefined behaviour.\n");
        exit(1);
#endif
    }
}

void quit(int n)
{
    (void) n;

    ShutdownOS(E_OK);
}

/*
 * tpl_init_machine starts the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{

    // TODO: invert control flow between these 2 functions
    tpl_posixvp_irq_gen_init();

    tpl_proc_id proc_id;

    /* create the context of each tpl_proc */
    for(    proc_id = 0;
            proc_id < TASK_COUNT+ISR_COUNT+1;
            proc_id++)
    {
        tpl_create_context(proc_id);
    }

    // TODO: replace with posix sigaction
    signal(SIGINT, quit);
    signal(SIGHUP, quit);

    tpl_posix_siginit();

    tpl_viper_init();

#if ((WITH_AUTOSAR == YES) && (SCHEDTABLE_COUNT > 0)) || (ALARM_COUNT > 0)
    tpl_viper_start_auto_timer(signal_for_counters,10000);  /* 10 ms */
#endif

#if WITH_AUTOSAR_TIMING_PROTECTION == YES
    tpl_start_tptimer();
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
}

