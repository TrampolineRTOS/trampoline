/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline 32 bits Darwin PPC process machine dependant stuff
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
#include "tpl_os_generated_configuration.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
 * struct used to save the register of a new context before calling
 * tpl_release_task_lock from tpl_switch_context
 */
struct DPPC_REGISTER_SAVING_AREA {
    unsigned long r0;   /*  0 bytes offset  */
    unsigned long r2;   /*  4 bytes offset  */
    unsigned long r3;   /*  8 bytes offset  */
    unsigned long r4;   /* 12 bytes offset  */
    unsigned long r5;   /* 16 bytes offset  */
    unsigned long r6;   /* 20 bytes offset  */
    unsigned long r7;   /* 24 bytes offset  */
    unsigned long r8;   /* 28 bytes offset  */
    unsigned long r9;   /* 32 bytes offset  */
    unsigned long r10;  /* 36 bytes offset  */
    unsigned long r11;  /* 40 bytes offset  */
    unsigned long r12;  /* 44 bytes offset  */
    unsigned long ctr;  /* 48 bytes offset  */
    unsigned long xer;  /* 52 bytes offset  */
};

typedef struct DPPC_REGISTER_SAVING_AREA dppc_register_saving_area;

/*
 * struct corresponding to the linkage area
 */
struct DPPC_LINKAGE_AREA {
    unsigned long sp;   /*  0 bytes offset  */
    unsigned long cr;   /*  4 bytes offset  */
    unsigned long lr;   /*  8 bytes offset  */
};

typedef struct DPPC_LINKAGE_AREA dppc_linkage_area;

#define DPPC_REGISTER_SAVING_AREA_SIZE  56
#define DPPC_LINKAGE_AREA_SIZE          12

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
    while (1) {
        printf("il reste a dormir %d s\n", sleep(10));
    }
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

asm void tpl_switch_context(
    tpl_context *old_context,
    tpl_context *new_context)
{
        cmpwi   old_context,0
        beq     nosave
        /*
         * Save the current context in the old context
         */
        lwz     r2,0(old_context) /* Get the pointer to the integer context   */
        stmw    r0,0(r2)        	/* store the GPRs	*/
        mfcr    r0
        stw     r0,128(r2)        /* store the CR        */
        mfxer   r0
        stw     r0,132(r2)        /* store the XER	*/
        mflr    r0
        stw     r0,136(r2)        /* store the LR        */
        mfctr   r0
        stw     r0,140(r2)        /* store the CTR	*/
        /*
         * restore the current context to the new context
         */         
nosave: lwz     r2,0(new_context) /* Get the pointer to the integer context   */
        lwz     r1,4(r2)          /* Get the stack pointer  */
        /*
         * build a space on the stack to save volatile
         * registers, sp is stored at the top of the stack in
         * the process
         */
        stwu    r1,-(DPPC_REGISTER_SAVING_AREA_SIZE+DPPC_LINKAGE_AREA_SIZE)(r1)
        
        lwz     r0,140(r2)                          /* Get the CTR (volatile)   */
        stw     r0,(DPPC_LINKAGE_AREA_SIZE+48)(r1)  /* save it on the stack     */
        
        lwz     r0,136(r2)                          /* Get the LR               */
        /* save it in the link area */
        stw     r0,(DPPC_REGISTER_SAVING_AREA_SIZE+DPPC_LINKAGE_AREA_SIZE+8)(r1)
                
        lwz     r0,132(r2)                          /* Get the XER (volatile)   */
        stw     r0,(DPPC_LINKAGE_AREA_SIZE+52)(r1)  /* save it on the stack     */
        
        lwz     r0,128(r2)                          /* Get the CR               */
        /* save it in the link area */
        stw     r0,(DPPC_REGISTER_SAVING_AREA_SIZE+DPPC_LINKAGE_AREA_SIZE+4)(r1)

        /*
         * Get the GPR
         */
        lmw     r3,12(r2)
        lwz     r0,0(r2)
        lwz     r2,0(r2)

        /*
         * store the volatile part on the stack
         */
        stw     r0,DPPC_LINKAGE_AREA_SIZE(r1)
        stw     r2,(DPPC_LINKAGE_AREA_SIZE+4)(r1)
        stw     r3,(DPPC_LINKAGE_AREA_SIZE+8)(r1)
        stw     r4,(DPPC_LINKAGE_AREA_SIZE+12)(r1)
        stw     r5,(DPPC_LINKAGE_AREA_SIZE+16)(r1)
        stw     r6,(DPPC_LINKAGE_AREA_SIZE+20)(r1)
        stw     r7,(DPPC_LINKAGE_AREA_SIZE+24)(r1)
        stw     r8,(DPPC_LINKAGE_AREA_SIZE+28)(r1)
        stw     r9,(DPPC_LINKAGE_AREA_SIZE+32)(r1)
        stw     r10,(DPPC_LINKAGE_AREA_SIZE+36)(r1)
        stw     r11,(DPPC_LINKAGE_AREA_SIZE+40)(r1)
        stw     r12,(DPPC_LINKAGE_AREA_SIZE+44)(r1)

        /*
         * release the lock
         */
        bl      tpl_release_task_lock
        
        /*
         * restore the registers
         */
        lwz     r0,(DPPC_LINKAGE_AREA_SIZE+48)(r1)  /* get the ctr  */
        mtctr   r0
        
        /* get the lr   */
        lwz     r0,(DPPC_REGISTER_SAVING_AREA_SIZE+DPPC_LINKAGE_AREA_SIZE+8)(r1)
        mtlr    r0
        
        lwz     r0,(DPPC_LINKAGE_AREA_SIZE+52)(r1)  /* get the xer  */
        mtxer   r0
        
        /* get the cr   */
        lwz     r0,(DPPC_REGISTER_SAVING_AREA_SIZE+DPPC_LINKAGE_AREA_SIZE+4)(r1)
        mtcr    r0
        
        lwz     r0,DPPC_LINKAGE_AREA_SIZE(r1)
        lwz     r2,(DPPC_LINKAGE_AREA_SIZE+4)(r1)
        lwz     r3,(DPPC_LINKAGE_AREA_SIZE+8)(r1)
        lwz     r4,(DPPC_LINKAGE_AREA_SIZE+12)(r1)
        lwz     r5,(DPPC_LINKAGE_AREA_SIZE+16)(r1)
        lwz     r6,(DPPC_LINKAGE_AREA_SIZE+20)(r1)
        lwz     r7,(DPPC_LINKAGE_AREA_SIZE+24)(r1)
        lwz     r8,(DPPC_LINKAGE_AREA_SIZE+28)(r1)
        lwz     r9,(DPPC_LINKAGE_AREA_SIZE+32)(r1)
        lwz     r10,(DPPC_LINKAGE_AREA_SIZE+36)(r1)
        lwz     r11,(DPPC_LINKAGE_AREA_SIZE+40)(r1)
        lwz     r12,(DPPC_LINKAGE_AREA_SIZE+44)(r1)

        /*
         * restore the stack pointer
         */
        lwz     r1,0(r1)
}

/*
 * tpl_switch_context_from_it
 */

#define SAVINGS 20

asm void tpl_switch_context_from_it(
    tpl_context *old_context /* aka r3 */,
    tpl_context *new_context /* aka r4 */)
{
    /*
     * This function is a little bit intricated under darwin
     *
     * First it copies the registers saved on the stack by the signal handling
     * stuff in the old_context
     */
    stwu    r1,-(SAVINGS)(r1)    /*  build a small space on stack to save regs   */    
    stw     r0,4(r1)    /*  r0 is used as tmp to do the copy                */
    stw     r2,8(r1)    /*  r2 is used as pointer to the context            */
    stw     r5,12(r1)   /*  r5 is used as pointer to the stack              */
    stw     r6,16(r1)   /*  r6 is used as index                             */
    lwz     r2,0(r3)   /*  get the pointer to the integer context  */
    /* pointer to integer registers saved on the stack  */
    addi    r5,r1,(SAVINGS+ADDITIONAL_STUFF+INTEGER_REGISTERS_OFFSET)
    li      r6,0      /*  init the index to 0 */
cs: lwzx    r0,r5,r6    /*  read current integer register from stack    */
    stwx    r0,r2,r6    /*  write it to the context                     */
    addi    r6,r6,4     /*  next register                               */
    cmpwi   r6,(4*32)   /*  last one                                    */
    blt     cs
    /*  copy the CR     */
    lwz     r0,(SAVINGS+ADDITIONAL_STUFF+CONDITION_REGISTER_OFFSET)(r1)
    stw     r0,(4*32)(r2)
    /*  copy the XER    */
    lwz     r0,(SAVINGS+ADDITIONAL_STUFF+EXTENDED_REGISTER_OFFSET)(r1)
    stw     r0,(4*33)(r2)
    /*  copy the LR     */
    lwz     r0,(SAVINGS+ADDITIONAL_STUFF+RETURN_ADDRESS_OFFSET)(r1)
    stw     r0,(4*34)(r2)
    /*  copy the CTR    */
    lwz     r0,(SAVINGS+ADDITIONAL_STUFF+COUNT_REGISTER_OFFSET)(r1)
    stw     r0,(4*35)(r2)
    
    /*
     * Second, appropriate fields of the frame are populated with the content
     * of the registers got from the new context
     *    
     * copy of the integer registers, r5 is already set to the start of the
     * corresponding area in the stack. r2 is set to point to the new_context
     */
    lwz     r2,0(r4)
    /*  init the index to 0 for the copy  */
    li      r6,0
    /*  copy the integer register   */
cr: lwzx    r0,r2,r6
    stwx    r0,r5,r6
    addi    r6,r6,4
    cmpwi   r6,(4*32)
    blt     cr
    
    /*
     * copy the other registers
     *
     *  copy the CR
     */
    lwz     r0,(4*32)(r2)
    stw     r0,(SAVINGS+ADDITIONAL_STUFF+CONDITION_REGISTER_OFFSET)(r1)
    /*  copy the XER    */
    lwz     r0,(4*33)(r2)
    stw     r0,(SAVINGS+ADDITIONAL_STUFF+EXTENDED_REGISTER_OFFSET)(r1)
    /*  copy the LR     */
    lwz     r0,(4*34)(r2)
    stw     r0,(SAVINGS+ADDITIONAL_STUFF+RETURN_ADDRESS_OFFSET)(r1)
    /*  copy the CTR    */
    lwz     r0,(4*35)(r2)
    stw     r0,(SAVINGS+ADDITIONAL_STUFF+COUNT_REGISTER_OFFSET)(r1)
    
    /*  get back the SAVINGS from the stack */
    lwz     r0,4(r1)    /*  r0 is used as tmp to do the copy                */
    lwz     r2,8(r1)    /*  r2 is used as pointer to the context            */
    lwz     r5,12(r1)   /*  r5 is used as pointer to the stack              */
    lwz     r6,16(r1)   /*  r6 is used as index                             */
    /*  restore the stack pointer */
    lwz     r1,0(r1)
    /*  that's all  */
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and lr and init the other registers to 0
 */
void tpl_init_context(tpl_exec_common *exec_obj)
{
	int i;
	ppc_integer_context *ic = exec_obj->static_desc->context.ic;
	
	for (i = 0; i < 32; i++ ) {
        ic->gpr[i] = 0;
	}
	
	ic->cr = 0;
	ic->xer = 0;
	ic->ctr = 0;
	
	ic->lr = (unsigned long)exec_obj->static_desc->entry;
	ic->gpr[1] = ((unsigned long)exec_obj->static_desc->stack.stack_zone)
	               + exec_obj->static_desc->stack.stack_size
	               - sizeof(dppc_linkage_area); 
	/*  Size of the linkage area used to store (among others)
        the link register if the task calls a function          */
}

/*
 * tpl_init_machine init the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{
    int id;
    struct sigaction sa;
    
    dppc_init_viper();
    
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
    dppc_start_auto_timer(SIGUSR1,30000000);
    
    /*
     * unblock the handling of signals
     */
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
}
