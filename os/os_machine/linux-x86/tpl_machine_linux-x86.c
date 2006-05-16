/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protg par la loi sur la proprit intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline 32 bits Darwin X86 process machine dependant stuff
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_machine.h"
#include "tpl_os_internal_types.h"
#include "tpl_viper_interface.h"
#include "tpl_os_interrupts.h"
#include "../App/tpl_os_generated_configuration.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
 * table which stores the signals used for interrupt
 * handlers
 */
extern int signal_for_id[ISR_COUNT];

/*
 * The signal set corresponding to the enabled interrupts
 */
sigset_t    signal_set;

/*
 * The signal handler used when interrupts are enabled
 */
void tpl_signal_handler(int sig)
{
    unsigned int id;

	printf("signal d'IT\n");
    for (id = 0; id < ISR_COUNT; id++) {
        if (signal_for_id[id] == sig) {
            tpl_central_interrupt_handler(id);
            break;
        }
    }
}

/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
    while (1) sleep(10);
}

void tpl_shutdown(void)
{
	/* remove ITs */
	if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_shutdown failed");
        exit(-1);
    }
    /* sleep forever */
    while (1) sleep(10);
}

/*
 * tpl_get_task_lock is used to lock a critical section 
 * around the task management in the os.
 */
void tpl_get_task_lock(void)
{
    /*
     * block the handling of signals
     */
	/*printf("lock\n"); */
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_get_lock failed");
        exit(-1);
    }
}

/*
 * tpl_release_task_lock is used to unlock a critical section
 * around the task management in the os.
 */
void tpl_release_task_lock(void)
{
	/*printf("unlock\n"); */
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_release_lock failed");
        exit(-1);
    }
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and lr and init the other registers to 0
 */
void tpl_init_context(tpl_exec_common *exec_obj)
{
	/*int *topStack;*/
	x86_integer_context *ic = exec_obj->static_desc->context.ic;
	
	/* init the structure with nul values. */
	ic->gs=0;
	ic->fs=0;
	ic->es=0;
	ic->ds=0;
	ic->edi=0;
	ic->esi=0;
	ic->ebx=0;
	ic->edx=0;
	ic->ecx=0;
	ic->eax=0;
	ic->cs=0;
	ic->eflags=0;
	ic->ss=0;

	/* define the entry point of the function */
	ic->eip = (unsigned long)exec_obj->static_desc->entry;
	
	/* define the stack pointer. */
	ic->esp = ((unsigned long)exec_obj->static_desc->stack.stack_zone)
	               + exec_obj->static_desc->stack.stack_size;

	ic->ebp=ic->esp;
}

/*
 * tpl_init_machine init the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{
	int id;
	struct sigaction sa;
	printf("start viper.\n");
	lx86_init_viper(); 

	sigemptyset(&signal_set);

    /*
     * init a signal mask to block all signals (aka interrupts)
     */
    for (id = 0; id < ISR_COUNT; id++) {
        sigaddset(&signal_set,signal_for_id[id]);
    }

    /*
     * init the sa structure to install the handler
     */
    sa.sa_handler = tpl_signal_handler;
    sa.sa_mask = signal_set;
    sa.sa_flags = 0;
    /*
     * Install the signal handler used to emulate interruptions
     */
    for (id = 0; id < ISR_COUNT; id++) {
        sigaction(signal_for_id[id],&sa,NULL);
    }
    
    /*
     * block the handling of signals
     */
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }

    /*
     * call viper to program the timer
     * This should be in user code. It is here for testing
     */
    lx86_start_one_shot_timer(SIGUSR1,10); 
    
    /*
     * unblock the handling of signals
     */
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
}

/* This part is for debugging purpose. The way registers are saved 
 * on the stack when there is a POSIX signal may differ in the Linux 
 * kernel. This code allow to check the place where the structure is 
 * stored (see assembly file tpl_ctx_switch.s).
 */
#ifdef __TPL_GET_LINUX_FRAME_OFFSET__
	unsigned int ebpAfterSignal;
	#define VAL_EAX 0x12345678
	/*
	found EAX at index 50 -> 50 values.
	corresponding in the tab: gs is at index (base index) 50-11 = 39
	*/
	
	void tpl_switch_context_from_it(
		tpl_context *old_context,
		tpl_context *new_context)
	{
		int *stack;
		int i;
		printf("search for EAX (value is 0x%x)\n", VAL_EAX);
		asm("movl %ebp, ebpAfterSignal\n");
		stack = (int *)ebpAfterSignal;
		while(1)
		{
			if(stack[i] == VAL_EAX) break; /* found */
			i++;
		}
		printf("found EAX at index %d\n",i);
		printf("Value of symbol FRAME_OFFSET in file\n");
		printf("\tos/os_machine/linux-x86/tpl_ctx_switch.s must be: %d\n",i-11);
		tpl_sleep();
	}

#endif


