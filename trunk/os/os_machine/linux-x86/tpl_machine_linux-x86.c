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
 * $Date: 2005-06-17 16:31:51 +0200 (Fri, 17 Jun 2005) $
 * $Rev: 90 $
 * $Author: jlb $
 * $URL: https://svn.irccyn.pro1.typhon.org/trampoline/os/os_machine/x86/tpl_machine_x86.c $
 */

#include "tpl_machine.h"
#include "tpl_os_internal_types.h"
#include "tpl_viper_interface.h"
#include "tpl_os_interrupts.h"
#include "../App/tpl_os_generated_configuration.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* offset of regs in the structure.*/
/* but unused because I didn't found how to insert them
 * in assembly language :'(
 **/
#define CTX_gs_OFFSET 	0
#define CTX_fs_OFFSET 	4
#define CTX_es_OFFSET 	8
#define CTX_ds_OFFSET 	12
#define CTX_edi_OFFSET 	16
#define CTX_esi_OFFSET 	20
#define CTX_ebp_OFFSET 	24
#define CTX_esp_OFFSET 	28
#define CTX_ebx_OFFSET 	32
#define CTX_edx_OFFSET 	36
#define CTX_ecx_OFFSET 	40
#define CTX_eax_OFFSET 	44
#define CTX_eip_OFFSET 	48
#define CTX_cs_OFFSET 	52
#define CTX_eflags_OFFSET 56
#define CTX_ss_OFFSET 	60


/*
 * struct used to save the register of a new context before calling
 * tpl_release_task_lock from tpl_switch_context
 */
struct X86_REGISTER_SAVING_AREA {
    unsigned short gs;   /*  0 bytes offset  */
    unsigned short fs;   /*  2 bytes offset  */
    unsigned short es;   /*  4 bytes offset  */
    unsigned short ss;   /*  6 bytes offset  */
    unsigned short ds;   /*  8 bytes offset  */
    unsigned short cs;   /* 10 bytes offset  */
    unsigned long esp;  /* 12 bytes offset  */
    unsigned long ebp;  /* 16 bytes offset  */
    unsigned long edi;  /* 20 bytes offset  */
    unsigned long esi;  /* 24 bytes offset  */
    unsigned long edx;  /* 28 bytes offset  */
    unsigned long ecx;  /* 32 bytes offset  */
    unsigned long ebx;  /* 36 bytes offset  */
    unsigned long eax;  /* 40 bytes offset  */
};

typedef struct LX86_REGISTER_SAVING_AREA lx86_register_saving_area;

/*
 * struct corresponding to the linkage area
 * not defined yet for the x86
 */
struct LX86_LINKAGE_AREA {
     unsigned long sp;   /*  0 bytes offset  */
     unsigned long cr;   /*  4 bytes offset  */
     unsigned long lr;   /*  8 bytes offset  */
};

typedef struct LX86_LINKAGE_AREA lx86_linkage_area;

#define LX86_REGISTER_SAVING_AREA_SIZE  56
#define LX86_LINKAGE_AREA_SIZE          12

/*
 * Offset from the top of the stack to get
 * the saved registers. It is used for
 * context switching while handling a signal
 */

/*
 * SIGNAL_FRAME_SIZE is the size of the stuff the handling
 * off signal put on the stack.
 */
#define SIGNAL_FRAME_SIZE           0x0670

/*
 * ADDITIONAL_STUFF is the size of the stuff the functions called
 * by the signal handler put on the stack as it is when we reach the
 * tpl_switch_context_from_it function
 */
#define ADDITIONAL_STUFF            0xD0

/*
 * INTEGER_REGISTERS_OFFSET is the offset, counted from the top
 * of the stack as it is in the handler (no additional stuff),
 * of the integer registers the signal handling saved on the stack
 */
#define INTEGER_REGISTERS_OFFSET    0x01B0

/*
 * RETURN_ADDRESS_OFFSET is the offset, counted from the top
 * of the stack as it is in the handler (no additional stuff),
 * of the link register the signal handling saved on the stack
 */
#define RETURN_ADDRESS_OFFSET       0x01A8

/*
 * CONDITION_REGISTER_OFFSET is the offset, counted from the top
 * of the stack as it is in the handler (no additional stuff),
 * of the condition register the signal handling saved on the stack
 */
#define CONDITION_REGISTER_OFFSET   0x0230

/*
 * EXTENDED_REGISTER_OFFSET is the offset, counted from the top
 * of the stack as it is in the handler (no additional stuff),
 * of the eXtended register the signal handling saved on the stack
 */
#define EXTENDED_REGISTER_OFFSET    0x0234

/*
 * COUNT_REGISTER_OFFSET is the offset, counted from the top
 * of the stack as it is in the handler (no additional stuff),
 * of the count register the signal handling saved on the stack
 */
#define COUNT_REGISTER_OFFSET       0x023C

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
    while (1);
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
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_release_lock failed");
        exit(-1);
    }
}

void tpl_switch_context(
    tpl_context *old_context,
    tpl_context *new_context)
{
	/* 
	* if no old context is defined, jump the save procedure
	*/
	/* Save eax that will be use to store oldcontext's @ */
	asm("pushl	%eax \n\t");
	/* eax gets @ of oldcontext (first argument) */
	asm("movl	8(%ebp), %eax \n\t");
	
	/* 
	 * if eax=0, oldcontext = NULL 
	 * no save of the current context in this case
	 */
	asm("cmpl	$0, %eax \n\t");
	asm("je	nosave \n\t");
		
	/* get ic from oldcontext */
	asm("movl	(%eax), %eax \n\t");

	/* Save the current context in the old context */
	/* save 16 bits registers onto oldcontext's structure */
	asm("movw	%gs ,  (%eax) \n\t" );
	asm("movw	%fs , 4(%eax) \n\t");
	asm("movw	%es , 8(%eax) \n\t");
	asm("movw	%ds , 12(%eax) \n\t");
	asm("movl	%edi, 16(%eax) \n\t");
	asm("movl	%esi, 20(%eax) \n\t");
	asm("movl	%ebp, 24(%eax) \n\t");
	/*esp saved later.*/
	asm("movl	%ebx, 32(%eax) \n\t");
	asm("movl	%edx, 36(%eax) \n\t");
	asm("movl	%ecx, 40(%eax) \n\t");

	/* move @ of oldcontext to ebx, in order to store eax */
	/* (since ebx is already stored) */
	asm("movl	%eax, %ebx \n\t");
	asm("popl	%eax \n\t");
	asm("movl	%eax, 44(%ebx) \n\t");

	/* save now the stack pointer: eax has been poped. */
	asm("movl	%esp, 28(%ebx) \n\t");

	/*return address. */
	asm("pushl	%eax \n\t" ); 
	asm("movl	4(%ebp), %eax \n\t");
	asm("movl	%eax, 48(%ebx) \n\t"); /* save the return address*/

	asm("movl	%cs , 52(%ebx) \n\t"  );
	asm("movl	$0, 56(%ebx) \n\t");  /* eflags set to 0*/
	asm("movl	%ss , 60(%ebx) \n\t"  );
	
asm("nosave:  \n\t");
	/*
	* restore the current context to the new context
	*/ 

	 /* to preserve the stack (same nb of push/pop) */        
	asm("popl	%eax \n\t");

	/* eax is used to save @ of newcontext */
	asm("movl	12(%ebp), %eax \n\t");
	/* eax gets ic of new context*/
	asm("movl	(%eax), %eax \n\t");

	/* asm("movw	 0(%eax), %gs  \n\t"); */
	/* asm("movw	 4(%eax), %fs  \n\t"); */
	/* asm("movw	 8(%eax), %es  \n\t"); */
	/* asm("movw	12(%eax), %ds  \n\t"); */
	asm("movl	16(%eax), %edi \n\t");
	asm("movl	20(%eax), %esi \n\t");
	/*ebp restored later */
	/************* switch stack ******************/
	asm("movl	28(%eax), %esp \n\t");
	/*restore flags now (needs a temp register -> use ebx) */
	asm("movl	56(%eax), %ebx \n\t");
	asm("pushf");	/*push flags*/
	
	asm("movl	32(%eax), %ebx \n\t");
	asm("movl	36(%eax), %edx \n\t");
	asm("movl	40(%eax), %ecx \n\t");
	/*eax restored later */
	/*eip restored later */
	/* asm("movl	52(%eax), %cs  \n\t"); */
	/*eflags are pushed on the the stack, and restored later */
	/* asm("movl	60(%eax), %ss  \n\t"); */


	/* use ebx, to restore eax. */
	asm("pushl	%ebx \n\t");
	asm("movl	%eax, %ebx \n\t");
	asm("movl	44(%ebx), %eax \n\t");
	
	asm("popl	%ebx \n\t"); /* restore ebx */

	/* retore flags on top of stack (following instruction will
	 * not change flags (push and ret)) 
	 */
	asm("popf");
	/* ebp and eip are not restored, as they MUST be on top of the stack
	 * the two next instructions generated by gcc update 
	 * ebp : popl ebp
	 * eip : ret
	 */
}

/*
 * tpl_switch_context_from_it
 */

#define SAVINGS 20

void tpl_switch_context_from_it(
    tpl_context *old_context /* aka r3 */,
    tpl_context *new_context /* aka r4 */)
{
    /* not implemented yet */
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and lr and init the other registers to 0
 */
void tpl_init_context(tpl_exec_common *exec_obj)
{
	int *topStack;
	x86_integer_context *ic = exec_obj->static_desc->context.ic;
	
	/* init the structure with nul values. */
	ic->gs=0;
	ic->fs=0;
	ic->es=0;
	ic->ds=0;
	ic->edi=0;
	ic->esi=0;
	ic->ebp=0;
	ic->esp=0;
	ic->ebx=0;
	ic->edx=0;
	ic->ecx=0;
	ic->eax=0;
	ic->eip=0;
	ic->cs=0;
	ic->eflags=0;
	ic->ss=0;

	/* define the entry point of the function */
	ic->eip = (unsigned long)exec_obj->static_desc->entry;
	
	/* define the stack pointer*/
	ic->esp = ((unsigned long)exec_obj->static_desc->stack.stack_zone)
	               + exec_obj->static_desc->stack.stack_size - 2*sizeof(int);

	/* the first thing that will be done after the context switch is to pop
	 * the frame pointer (ebp) and the instruction pointer (eip). So they
	 * must be pushed on top of the stack (that's why 2 ints are removed from 
	 * the top of the stack.
	 */
	topStack = (int *)(ic->esp);
	topStack[0] = ic->esp;
	topStack[1] = ic->eip;
}

/*
 * tpl_init_machine init the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{
    int id;
    struct sigaction sa;
    
    /* lx86_init_viper(); */
    
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
    /*lx86_start_one_shot_timer(SIGUSR1,3000000);*/
    
    /*
     * unblock the handling of signals
     */
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
}
