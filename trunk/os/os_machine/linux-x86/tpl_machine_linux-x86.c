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
	TODO: revoir les lock!! Une tâche démarrée automatique n'est pas préemptable (lock des its).
*/


/*#define __TPL_GET_LINUX_FRAME_OFFSET__ */
#ifdef __TPL_GET_LINUX_FRAME_OFFSET__
	unsigned int ebpAfterSignal;
	#define VAL_EAX 0x12345678
	/*
	found EAX at index 50 -> 50 values.
	corresponding in the tab: gs is at index (base index) 50-11 = 39
	*/
#endif
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
        perror("tpl_get_lock failed");
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
	printf("lock\n");
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
	printf("unlock\n");
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

	 /* to remove ebp and eip from the stack. */
	asm("popl	%eax \n\t");
	asm("popl	%eax \n\t");


	/* eax is used to save @ of newcontext */
	asm("movl	12(%ebp), %eax \n\t");
	/* eax gets ic of new context*/
	asm("movl	(%eax), %eax \n\t");

	/* asm("movw	 0(%eax), %gs  \n\t"); */
	/* asm("movw	 4(%eax), %fs  \n\t"); */
	/* asm("movw	 8(%eax), %es  \n\t"); */
	/* asm("movw	12(%eax), %ds  \n\t"); */
	asm("movl	16(%eax), %edi \n\t"); /*restore edi */
	asm("movl	20(%eax), %esi \n\t"); /*restore esi */
	/*ebp restored later (using stack) */

	/************* switch stack ******************/
	asm("movl	28(%eax), %esp \n\t");
	/* the stack wil have eip, ebp and eflags in that order */
	/*restore eip, using ebx, not yet restored*/
	asm("movl	48(%eax), %ebx \n\t");
	asm("pushl %ebx \n\t");				/*restore eip on top of stack */
	asm("movl	24(%eax), %ebx \n\t");
	asm("pushl %ebx \n\t");				/*then restore ebp on top of stack */
	/*restore flags now (needs a temp register -> use ebx) */
	asm("movl	56(%eax), %ebx \n\t");
	asm("pushl %ebx");	/*push flags*/
	
	asm("movl	32(%eax), %ebx \n\t");
	asm("movl	36(%eax), %edx \n\t");
	asm("movl	40(%eax), %ecx \n\t");
	/*eax restored later */
	/*eip restored later (using stack)*/
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
	asm("popf\n\t");
	/* ebp and eip are on top of the stack
	 * the two next instructions generated by gcc update 
	 * ebp : popl ebp
	 * eip : ret
	*/
}

/*
 * tpl_switch_context_from_it
 */

void tpl_switch_context_from_it(
    tpl_context *old_context,
    tpl_context *new_context)
{
	#ifdef __TPL_GET_LINUX_FRAME_OFFSET__
		int *stack;
		int i;
		asm("movl %ebp, ebpAfterSignal\n");
		stack = (int *)ebpAfterSignal;
		while(1)
		{
			if(stack[i] == VAL_EAX) break; /* found */
			i++;
		}
		printf("found EAX at index %d\n",i);
		printf("base of the structure must be  at index %d (register gs)\n",i-11);
		while(1);
	#else
		/* the registers are saved on the frame used when taking into account
		 * the POSIX signal/
		 * First: store the old context from the values saved in the frame.
		*/

		/* if no old context is defined, jump the save procedure */
		/* eax gets @ of oldcontext (first argument) */
		asm("movl	8(%ebp), %eax \n\t");
	
		/* 
	 	* if eax=0, oldcontext = NULL 
	 	* no save of the current context in this case
	 	*/
		asm("cmpl	$0, %eax \n\t");
		asm("je	nosaveIT \n\t");
		
		/* get ic from oldcontext */
		asm("movl	(%eax), %eax \n\t");

		/* Save the context stored in the frame in the old context */
		/* save registers onto oldcontext's structure */
		/*gs*/
		asm("movl	39*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  (%eax) \n\t" ); 
		/*fs*/
		asm("movl	40*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4(%eax) \n\t" ); 
		/*es*/
		asm("movl	41*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*2(%eax) \n\t" ); 
		/*ds*/
		asm("movl	42*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*3(%eax) \n\t" ); 
		/*edi*/
		asm("movl	43*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*4(%eax) \n\t" ); 
		/*esi*/
		asm("movl	44*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*5(%eax) \n\t" ); 
		/*ebp*/
		asm("movl	45*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*6(%eax) \n\t" ); 
		/*esp*/
		asm("movl	46*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*7(%eax) \n\t" ); 
		/*ebx*/
		asm("movl	47*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*8(%eax) \n\t" ); 
		/*edx*/
		asm("movl	48*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*9(%eax) \n\t" ); 
		/*ecx*/
		asm("movl	49*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*10(%eax) \n\t" ); 
		/*eax*/
		asm("movl	50*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*11(%eax) \n\t" ); 
	/* 2 dummy ints added in the linux signal frame */
		/*eip*/
		asm("movl	53*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*12(%eax) \n\t" ); 
		/*cs*/
		asm("movl	54*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*13(%eax) \n\t" ); 
		/*eflags*/
		asm("movl	55*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*14(%eax) \n\t" ); 
	/* 1 dummy int added in the linux signal frame */
		/*ss*/
		asm("movl	57*4(%ebp) ,  %ebx \n\t" );
		asm("movl	%ebx ,  4*15(%eax) \n\t" ); 

asm("nosaveIT:  \n\t");

		/* eax is used to save @ of newcontext */
		asm("movl	12(%ebp), %eax \n\t");
		/* eax gets ic of new context*/
		asm("movl	(%eax), %eax \n\t");
		/*gs*/
	/*	asm("movl	(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  39*4(%ebp) \n\t" ); 
	*/	/*fs*/
	/*	asm("movl	4*1(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  40*4(%ebp) \n\t" ); 
	*/	/*es*/
	/*	asm("movl	4*2(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  41*4(%ebp) \n\t" ); 
	*/	/*ds*/
	/*	asm("movl	4*3(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  42*4(%ebp) \n\t" ); 
	*/	/*edi*/
		asm("movl	4*4(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  43*4(%ebp) \n\t" ); 
		/*esi*/
		asm("movl	4*5(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  44*4(%ebp) \n\t" ); 
		/*ebp*/
		asm("movl	4*6(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  45*4(%ebp) \n\t" ); 
		/*esp*/
		asm("movl	4*7(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  46*4(%ebp) \n\t" ); 
		/*ebx*/
		asm("movl	4*8(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  47*4(%ebp) \n\t" ); 
		/*edx*/
		asm("movl	4*9(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  48*4(%ebp) \n\t" ); 
		/*ecx*/
		asm("movl	4*10(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  49*4(%ebp) \n\t" ); 
		/*eax*/
		asm("movl	4*11(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  50*4(%ebp) \n\t" ); 
	/* 2 dummy ints added in the linux signal frame */
		/*eip*/
		asm("movl	4*12(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  53*4(%ebp) \n\t" ); 
		/*cs*/
	/*	asm("movl	4*13(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  54*4(%ebp) \n\t" ); 
	*/	/*eflags*/
		asm("movl	4*14(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  55*4(%ebp) \n\t" );
	/* 1 dummy int added in the linux signal frame */
		/*ss*/
	/*	asm("movl	4*15(%eax) ,  %ebx \n\t" );
		asm("movl	%ebx ,  56*4(%ebp) \n\t" ); 
	*/
	#endif	
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
    lx86_start_one_shot_timer(SIGUSR1,1000000);
    
    /*
     * unblock the handling of signals
     */
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
}
