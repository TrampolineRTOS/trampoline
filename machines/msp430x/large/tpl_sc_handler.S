#include "tpl_assembler.h"
#include "tpl_asm_definitions.h"
#include "tpl_service_ids.h"

.equ NO_NEED_SWITCH_NOR_SCHEDULE,   0
.equ NO_NEED_SWITCH,                0
.equ NEED_SWITCH,                   1
.equ NEED_SAVE,                     2

.extern tpl_reentrancy_counter

/*
    the tpl_sc_handler uses tpl_kern
*/

#define OS_START_SEC_VAR
#include "tpl_as_memmap.h"
.equ KERNEL_STACK_SIZE, 400
.extern tpl_kern
tpl_kernel_stack:
	.space KERNEL_STACK_SIZE-2
tpl_kernel_stack_bottom:
	.space 2

#define OS_STOP_SEC_VAR
#include "tpl_as_memmap.h"

/*
    the tpl_sc_handler uses the dispatch table
*/

#define OS_START_SEC_CONST
#include "tpl_as_memmap.h"

.extern tpl_dispatch_table

#define OS_STOP_SEC_CONST
#include "tpl_as_memmap.h"

/*
    the code starts here
*/

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

.global         tpl_sc_handler
.type           tpl_sc_handler, %function
tpl_sc_handler:
	/* Compare service id to the number of services to verify its validity */
    cmp         #SYSCALL_COUNT, REG_SID
    jhs         tpl_sc_handler_invalid_service_id
	/* Make room(16 bytes) on the stack for volatile registers */
    sub         #16, r1
	/* tpl_sc_handler need one working register, 
	 * we choose r11 which has to be saved on the stack before using it 
	*/
    pushx.a     r11
	/* interrupts are disabled */
    dint
	/* the bottom of the stack have to be 'normalized'
	 * i.e. same configuration as in an interrupt
	 */
    mov     22(r1), r11    /* Saved PC [19..16] -> r11                  */
    mov     20(r1), 22(r1) /* Copy saved PC [15..0] at the good place   */
    swpb    r11            /* Get saved PC [19..16] in bits 11..8       */
    rlam.w  #4, r11        /* Shift them to bits 19..16                 */
    bis     r2, r11        /* Add the SR in its location at 11..0       */
    bis     #8, r11        /* set GIE bit (reset just before with dint) */
    mov     r11, 20(r1)    /* The stack is ok                           */

	/* tpl_reentrancy_counter is checked to prevent a switch to the kernel 
     * when executing a service called by a hook 
	 */
    tst.b       &tpl_reentrancy_counter
    jnz         tpl_sc_handler_no_stack_switch

	/* **************************************
	 * ******  stack switch -> Kernel *******
	 * **************************************
	 * ** now the stack is the one of the kernel **
	 * the process stack pointer is saved on the stack 
	 */
    mov         r1, r11
    mov         #tpl_kernel_stack_bottom, r1
    push        r11

tpl_sc_handler_no_stack_switch:
	/* increment tpl_reentrancy counter */
    inc.b       &tpl_reentrancy_counter
	/* init the NEED_SWITCH/SAVE flags in tpl_kern */
    mov         #tpl_kern, r11
    mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
    mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SCHEDULE(r11)
	/* call the service */
    rla         REG_SID             /* index -> offset (=index<<1) */
    call        tpl_dispatch_table(REG_SID)

	/* REG_RETARG holds the return value. 
	 * It is put in its location in the process stack. 
	 */
    pop	r13 //get back PSP => r13
    movx.a REG_RETARG, 16(r13) //put in Process's stack
	/* check the context switch condition in tpl_kern */
    mov         #tpl_kern, r11
    tst.b       TPL_KERN_OFFSET_NEED_SWITCH(r11)
    jz          tpl_sc_handler_no_context_switch
	/* prepare the call to tpl_run_elected by setting 
	 * REG_RETARG to 0, a.k.a. no save */
    mov         #0, REG_RETARG
	/* test the NEED_SAVE condition */
    bit.b       #NEED_SAVE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
    jz          tpl_sc_handler_no_save_running_context
	/* Save the remaining registers of the context 
	 * The MSP430 have a "push multiple words", but no "mov multiple word". 
	 * So, we get back to process stack to benefit this instruction
	*/
    mov    r1, r14	/* get a copy of the KSP to restore it later */
    mov	   r13, r1	/* change stack to process stack */	
    pushm.a #7, r10	/* Push r4 to r10 on process stack (save) */
    mov	   r1, r13	/* get process stack back */	
    mov    r14, r1	/* get back to kernel stack */
	/* The whole context is now saved on the process stack 
	 * and the kernel stack has been cleaned 
	 * the stack pointer is saved in the dedicated location 
	 */
    mov         &tpl_kern, r11      /* Get the s_running slot of tpl_kern in r11 */
    mov         @r11, r11           /* Get the pointer to the context (SP alone) */
    mov         r13, @r11           /* Save the stack pointer */
	/* prepare the argument of tpl_run_elected: 
	 * 1(save) and call it after switching back to the kernel stack 
	 */
    mov         #1, REG_RETARG		/* argument f tpl_run_elected:1 (save) */

tpl_sc_handler_no_save_running_context:

    /*add         #2, r1               "pop" the PSP which is no longer useful */
    call        #tpl_run_elected
	/* tpl_run_elected has copied the elected process slot 
	 * of the tpl_kern of the running slot
	 * we load the stack pointer of the new running process
	 */
    mov         &tpl_kern, r11      /* Get the s_running slot of tpl_kern in r11 */
    mov         @r11, r11           /* Get the pointer to the context (SP alone) */
	/* **************************************
	 * ****** stack switch -> process *******
	 * **************************************
	 */
    mov         @r11, r1            /* Get the stack pointer */
	/* the context of the new runnign process is loaded, we pop r4 to r10 */
    popm.a      #7, r10             /* pop r4 to r10 */
	jmp tpl_sc_end_of_context_switch

	/* If there is no ctx switch, we are still on kernel stack...
	 */
tpl_sc_handler_no_context_switch:
	mov r13, r1	 /* get back to process stack */

	/* tpl_reentrancy_counter is decremented, interrupts are enabled, we return */
tpl_sc_end_of_context_switch:
    dec.b       &tpl_reentrancy_counter
    jnz         tpl_sc_handler_still_in_kernel

tpl_sc_handler_still_in_kernel:
    popx.a      r11
    add         #12, r1             /* skip volatile */
    popx.a      REG_RETARG          /* Get back the return value */
    reti

tpl_sc_handler_invalid_service_id:
	/* return with a simple 'ret', as the stack shape has not been
	 * updated yet.
	 */
    ret

/* MAYBE SHOULDN'T BE HERE BUT IN A SEPERATE FILE */
.global TIMER3_A0_Handler
.type   TIMER3_A0_Handler, %function
TIMER3_A0_Handler:
    pushx.a REG_RETARG
#ifdef MSPGCC_ABI
    /* r15 has been pushed by pushed by pushx.a REG_RETARG */
    pushm.a     #4, r14                     /* Push r11, r12, r13, r14 */
#endif
#ifdef GCCFORMSP_ABI
    /* r12 has been pushed by pushx.a REG_RETARG */
    pushm.a     #3, r15                     /* push r13, r14, r15 */
    pushx.a     r11
#endif

    mov         r1, r11 /* Copy the PSP to r11 */
    mov         #tpl_kernel_stack_bottom, r1/* Switch to the kernel stack */
    push        r11                         /* Save PCP to kernel stack */

    mov         #tpl_kern, r11
    mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
    mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SCHEDULE(r11)

    call        #tpl_tick_TIMER3_A0_VECTOR

    mov         r1, r13                     /* get a copy of the KSP to restore it later */
    pop         r1                          /* get the saved process stack pointer back */

    
    mov         #tpl_kern, r11              /* check the context switch condition in tpl_kern */
    tst.b       TPL_KERN_OFFSET_NEED_SWITCH(r11)
    jz          tpl_TIMER3_A0_Handler_no_context_switch

    pushm.a     #7, r10                     /* push r4 to r10 */

    mov         &tpl_kern, r11              /* Get the s_running slot of tpl_kern in r11 */
    mov         @r11, r11                   /* get the pointer to the context (SP alone) */
    mov         r1, @r11                    /* Save the stack pointer */

    mov         r13, r1                     /* Switch back to the kernel stack */
    mov         #1, REG_RETARG
    add         #2, r1                      /* "pop" the PSP which is no longer usefull */
    call        #tpl_run_elected

    mov         &tpl_kern, r11              /* Get the s_runnign slot of tpl_kern in r11 */
    mov         @r11, r11                   /* Get the pointer to the context (SP alone) */
    mov         @r11, r1                    /* Get the stack  pointer */

    popm.a      #7, r10                     /* Pop r4 to r10 */

tpl_TIMER3_A0_Handler_no_context_switch:
#ifdef MSPGCC_ABI
    /* r15 will be popped by popx.a REG_RETARG */
    popm.a      #4, r14                     /* Pop r11, r12, r13, r14 */
#endif
#ifdef GCCFORMSP_ABI
    /* r12 will be popped by popx.a REG_RETARG */
    popx.a      r11
    popm.a      #3, r15                     /* Pop r13, r14, r15 */
#endif
    popx.a      REG_RETARG
    reti

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"
