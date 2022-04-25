#include "tpl_assembler.h"
#include "tpl_asm_definitions.h"
#include "tpl_service_ids.h"
#include "tpl_kern_stack.h"

/*
 * The reentrancy flag is used to distinguish between a service call`
 * from the application and from a hook.
 * If 0, it is a call from the application
 * if 1, it is a call from a hook
 */
.extern tpl_reentrancy_flag


/*
    the tpl_sc_handler uses tpl_kern
*/
.extern tpl_kern

/*
 * and the kernel stack
 */
.extern tpl_kern_stack

/*
 * the tpl_sc_handler uses the dispatch table
 */
.extern tpl_dispatch_table

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
    the code starts here
*/

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/*=============================================================================
 * System call handler
 */
.global tpl_sc_handler
.type   tpl_sc_handler, %function

tpl_sc_handler:
/*
 * PROCESS STACK:
 *    +-------------------+
 *  2 | CallTerminateXXX  | + 4
 *    +-------------------+
 *
 *-----------------------------------------------------------------------------
 * -1- Compare service id to the number of services to verify its validity
 */    
    cmpx.a         #SYSCALL_COUNT, REG_SID
    jlo            tpl_sc_handler_id_ok         /* continue if lower            */
    reta                                        /* return if higher or same     */
tpl_sc_handler_id_ok:
/*-----------------------------------------------------------------------------
 * -2- Disable interrupts so that the kernel cannot be interrupted.
 * Check the reentrancy flag. If it is not zero, it means the service is
 * called from a hook and has to be processed differently.
 */
  dint
  nop	                              /*required after dint instruction*/
  tstx.b       &tpl_reentrancy_flag
  jnz          tpl_sc_handler_from_hook
/*-----------------------------------------------------------------------------
 * -3- We need to have the same stack pattern for both the tpl_sc_handler and
 * an interrupt handler which calls the operating system. 
 */
  movx.w     2(r1), r13     /* Saved PC [19..16] -> r13                  */
  movx.w     0(r1), 2(r1)   /* Copy saved PC [15..0] at the good place   */
  swpbx    r13            /* Get saved PC [19..16] in bits 11..8       */
  rlam     #4, r13        /* Shift them to bits 19..16                 */
  bisx     r2, r13        /* Add the SR in its location at 11..0       */
  bisx     #8, r13        /* set GIE bit (reset just before with dint) */
  movx.w     r13, 0(r1)       /* The stack is ok                           */
;   pushx         sr
;   bicx.b        #0xF0, 1(r1)           /* reset the 4 higher bits of saved SR */
;   bisx.b        #0x08, 0(r1)           /* set the GIE bit in the saved SR     */
/*
 * PROCESS STACK:
 *    +----+--------------+
 *  0 | PC.19:16 |   SR   | + 0
 *    +----+--------------+
 *  1 |      PC.15:0      | + 2
 *    +-------------------+
 *  2 | CallTerminateXXX  | + 4
 *    +-------------------+
 *
 *-----------------------------------------------------------------------------
 * -4- Obviously volatile registers (r12 to r15 because we take into account
 * both ABIs) are not saved in tpl_sc_handler since the caller does not expect
 * their values to be preserved but we need to make room (2*8 bytes) on the
 * stack for them because an interrupt handler will save these registers at
 * this location.
 * The tpl_sc_handler needs one working register and we choose to use r11
 * which has to be saved on the process stack before using it.
 */
  subx.a        #16, sp
  pushm.a       #1,r11
/*
 * PROCESS STACK:                                                     
 *    +-------------------+
 *  0 |      r11.15:0     | + 00
 *    +-------------------+
 *  1 |   0  | r11.19:16  | + 02
 *    +-------------------+
 *  2 |      r12.15:0     | + 04
 *    +-------------------+
 *  3 |   0  | r12.19:16  | + 06
 *    +-------------------+
 *  4 |      r13.15:0     | + 08
 *    +-------------------+
 *  5 |   0  | r13.19:16  | + 10
 *    +-------------------+
 *  6 |      r14.15:0     | + 12      
 *    +-------------------+
 *  7 |   0  | r14.19:16  | + 14
 *    +-------------------+
 *  8 |       r15.15:0    | + 16
 *    +-------------------+
 *  9 |   0  | r15.19:16  | + 18
 *    +----+--------------+
 *  10 | PC.19:16 |SR.11:0| + 20
 *    +----+--------------+
 * 11 |      PC.15:0      | + 22
 *    +-------------------+
 * 12 | CallTerminateXXX  | + 24
 *    +-------------------+
 *
 *-----------------------------------------------------------------------------
  * -5- Before calling the service, we setup the kernel stack. The process stack
 * pointer (PSP) is saved in r11, then SP is loaded to the kernel stack bottom
 * and the PSP is saved on the kernel stack.
 */
  mova      r1, r11                         /* save the PSP into r11          */
  mova      #tpl_kern_stack + TPL_KERNEL_STACK_SIZE, r1 /* on kernel stack    */
  pushx.a     r11                             /* push the PSP on it             */
/*
 * PROCESS STACK:                 KERNEL STACK:
 *    +--------------------+            +-------------------+
 *  0 |     r11.15:0   | + 0          0 |   PSP.15:0        | + 0 
 *    +--------------------+            +-------------------+
 *  1 |   0  | r11.19:16   | + 2      1 |   0 |  PSP.19:16  | + 2
 *    +--------------------+            +-------------------+
 *  2 |      r12.15:0     | + 04
 *    +-------------------+
 *  3 |   0  | r12.19:16  | + 06
 *    +-------------------+
 *  4 |      r13.15:0     | + 08
 *    +-------------------+
 *  5 |   0  | r13.19:16  | + 10
 *    +-------------------+
 *  6 |      r14.15:0     | + 12      
 *    +-------------------+
 *  7 |   0  | r14.19:16  | + 14
 *    +-------------------+
 *  8 |       r15.15:0    | + 16
 *    +-------------------+
 *  9 |   0  | r15.19:16  | + 18
 *    +--------------------+
 * 10 | PC.19:16 | SR.11:0 | + 20
 *    +--------------------+
 * 11 |      PC.15:0       | + 22
 *    +--------------------+
 * 12 | CallTerminateXXX   | + 24
 *    +--------------------+
 *
 *-----------------------------------------------------------------------------
 * -6- Init the NEED_SWITCH/NEED_SAVE in tpl_kern.
 */
  movx.a      #tpl_kern, r11
  movx.b      #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
  movx.b      #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SCHEDULE(r11)
/*-----------------------------------------------------------------------------
* -7- Call the service. The reentrancy flag is incremented before and
 * decremented after.
 */
  incx.b    &tpl_reentrancy_flag         /* surround the call by inc ...  */
  rlax.a    REG_SID                      /* index -> offset               */
  rlax.a    REG_SID                      /* index -> offset               */
  calla     tpl_dispatch_table(REG_SID)  /* func ptrs in dispatch table   */
  decx.b    &tpl_reentrancy_flag         /* ... and dec of the flag.      */
/*-----------------------------------------------------------------------------
 -8- From there, REG_RETARG holds the return value. It is put at its location
 * in the process stack. Also r13 and r14 become usable whatever is the ABI.
 */
  popx.a      r13                                /* get back PSP => r13.    */
  movx.a      REG_RETARG, REG_RETARG_OFFSET(r13) /* put in Process's stack  */
/*
 * PROCESS STACK:                 KERNEL STACK:
 *    +--------------------+            EMPTY
 *  0 |      r11.15:0      | + 00
 *    +--------------------+
 *  1 |   0  | r11.19:16   | + 02
 *    +--------------------+
 *  2 |      r12.15:0      | + 04
 *    +--------------------+
 *  3 |   0  | r12.19:16   | + 06
 *    +--------------------+
 *  4 |      r13.15:0      | + 08
 *    +--------------------+
 *  5 |   0  | r13.19:16   | + 10
 *    +--------------------+
 *  6 |      r14.15:0      | + 12      
 *    +--------------------+
 *  7 |   0  | r14.19:16   | + 14
 *    +--------------------+
 *  8 |       r15.15:0     | + 16
 *    +--------------------+
 *  9 |   0  | r15.19:16   | + 18
 *    +--------------------+
 * 10 | PC.19:16 | SR.11:0 | + 20
 *    +--------------------+
 * 11 |      PC.15:0       | + 22
 *    +--------------------+
 * 12 | CallTerminateXXX   | + 24
 *    +--------------------+
 *
 *    * updated if GCC for MSP ABI
 *    † updated if MSPGCC ABI
 *-----------------------------------------------------------------------------
 * -9- Check the context switch condition in tpl_kern.
 */
  mova      #tpl_kern, r11
  tstx.b    TPL_KERN_OFFSET_NEED_SWITCH(r11)
  jz        tpl_sc_handler_no_context_switch
/*
 * From here we are doing a context switching
 *
 *-----------------------------------------------------------------------------
 * -10- Prepare the call to tpl_run_elected REG_RETARG to 0, aka no save.
 */
  movx.a      #0, REG_RETARG
/*-----------------------------------------------------------------------------
 * -11- Test the NEED_SAVE condition.
 */
  bitx.b    #NEED_SAVE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
  jz       tpl_sc_handler_no_save_running_context
/*-----------------------------------------------------------------------------
* -12- Save the context. The MSP430 have a "push multiple words", but no
 * "move multiple word". So, we get back to process stack to benefit this
 * instruction
 */
  mova      r1, r14          /* get a copy of the KSP to restore it later */
  mova      r13, r1          /* change stack to process stack             */
  pushm.a   #7, r10          /* Push r4 to r10 on process stack (save)    */
/*
 * The whole context is now saved on process stack and the kernel stack
 * has been cleaned. r14 points to the kernel stack.
 *
 * PROCESS STACK:                 KERNEL STACK:
 *    +--------------------+
 *  0 |       r4.15:0      | + 0
 *    +--------------------+
 *  1 |   0  |  r4.19:16   | + 2
 *    +--------------------+
 *  2 |      r5.15:0       | + 4
 *    +--------------------+
 *  3 |   0  |  r5.19:16   | + 6
 *    +--------------------+
 *  4 |       r6.15:0      | + 8
 *    +--------------------+
 *  5 |   0  |  r6.19:16   | + 10
 *    +--------------------+
 *  6 |      r7.15:0       | + 12
 *    +--------------------+
 *  7 |   0  |  r7.19:16   | + 14
 *    +--------------------+
 *  8 |      r8.15:0       | + 16 
 *    +--------------------+
 *  9 |   0  |  r8.19:16   | + 18
 *    +--------------------+
 * 10 |      r9.15:0       | + 20 
 *    +--------------------+
 * 11 |   0  |  r9.19:16   | + 22
 *    +--------------------+
 * 12 |      r10.15:0      | + 24
 *    +--------------------+
 * 13 |   0  | r10.19:16   | + 26
 *    +--------------------+
 *  0 |      r11.15:0      | + 00
 *    +--------------------+
 *  1 |   0  | r11.19:16   | + 02
 *    +--------------------+
 *  2 |      r12.15:0      | + 04
 *    +--------------------+
 *  3 |   0  | r12.19:16   | + 06
 *    +--------------------+
 *  4 |      r13.15:0      | + 08
 *    +--------------------+
 *  5 |   0  | r13.19:16   | + 10
 *    +--------------------+
 *  6 |      r14.15:0      | + 12      
 *    +--------------------+
 *  7 |   0  | r14.19:16   | + 14
 *    +--------------------+
 *  8 |       r15.15:0     | + 16
 *    +--------------------+
 *  9 |   0  | r15.19:16   | + 18
 *    +--------------------+
 * 24 | PC.19:16 | SR.11:0 | + 48
 *    +--------------------+
 * 25 |      PC.15:0       | + 50
 *    +--------------------+
 * 26 | CallTerminateXXX   | + 52
 *    +--------------------+
 *
 *-----------------------------------------------------------------------------
 * -13- Now the stack pointer is saved in the dedicated location.
 */
  mova        &tpl_kern, r11   /* Get the s_running slot of tpl_kern in r11 */
  mova        @r11, r11        /* Get the pointer to the context (SP alone) */
  movx.a      r1, @r11         /* Save the stack pointer                    */
/*-----------------------------------------------------------------------------
 * -14- Prepare the argument of tpl_run_elected: 1 (aka save) and call it after
 * switching back to the kernel stack.
 */
  mova      r14, r1          /* get back to kernel stack                  */
  movx.a    #1, REG_RETARG
tpl_sc_handler_no_save_running_context:
/*
 * Note: when getting there with a jump, we are coming from stage 11 where we
 * are on the kernel task. So no need to switch in this because
 */
  calla     #tpl_run_elected
/*-----------------------------------------------------------------------------
 * -15- tpl_run_elected has copied the elected process slot of tpl_kern to the
 * running slot. We load the stack pointer of the new running process.
 */
  mova      &tpl_kern, r11   /* Get the s_running slot of tpl_kern in r11 */
  mova      @r11, r11        /* Get the pointer to the context (SP alone) */
  movx.a    @r11, r1         /* Get the stack pointer                     */
/*
 * PROCESS STACK:                 KERNEL STACK:
 *    +--------------------+
 *  0 |       r4.15:0      | + 0
 *    +--------------------+
 *  1 |   0  |  r4.19:16   | + 2
 *    +--------------------+
 *  2 |      r5.15:0       | + 4
 *    +--------------------+
 *  3 |   0  |  r5.19:16   | + 6
 *    +--------------------+
 *  4 |       r6.15:0      | + 8
 *    +--------------------+
 *  5 |   0  |  r6.19:16   | + 10
 *    +--------------------+
 *  6 |      r7.15:0       | + 12
 *    +--------------------+
 *  7 |   0  |  r7.19:16   | + 14
 *    +--------------------+
 *  8 |      r8.15:0       | + 16 
 *    +--------------------+
 *  9 |   0  |  r8.19:16   | + 18
 *    +--------------------+
 * 10 |      r9.15:0       | + 20 
 *    +--------------------+
 * 11 |   0  |  r9.19:16   | + 22
 *    +--------------------+
 * 12 |      r10.15:0      | + 24
 *    +--------------------+
 * 13 |   0  | r10.19:16   | + 26
 *    +--------------------+
 *  0 |      r11.15:0      | + 00
 *    +--------------------+
 *  1 |   0  | r11.19:16   | + 02
 *    +--------------------+
 *  2 |      r12.15:0      | + 04
 *    +--------------------+
 *  3 |   0  | r12.19:16   | + 06
 *    +--------------------+
 *  4 |      r13.15:0      | + 08
 *    +--------------------+
 *  5 |   0  | r13.19:16   | + 10
 *    +--------------------+
 *  6 |      r14.15:0      | + 12      
 *    +--------------------+
 *  7 |   0  | r14.19:16   | + 14
 *    +--------------------+
 *  8 |       r15.15:0     | + 16
 *    +--------------------+
 *  9 |   0  | r15.19:16   | + 18
 *    +--------------------+
 * 24 | PC.19:16 | SR.11:0 | + 48
 *    +--------------------+
 * 25 |      PC.15:0       | + 50
 *    +--------------------+
 * 26 | CallTerminateXXX   | + 52
 *    +--------------------+
 *
 *-----------------------------------------------------------------------------
 * -16- Now, the context of the new running process is loaded. Registers r4 to
 * r15} are popped and we return.
 */
  popm.a   #12,r15                 /* pop r4 to r15 at once              */
  reti                             /* and return with interrupts enabled */
/*-----------------------------------------------------------------------------
 * -17- We get there from stage 9 and we are on the kernel stack and r13
 * contains the process stack pointer. No context switch has to be performed,
 * we go back to the process stack which is as follow:
 *
 * PROCESS STACK:
 *    +--------------------+
 *  0 |      r11.15:0      | + 00
 *    +--------------------+
 *  1 |   0  | r11.19:16   | + 02
 *    +--------------------+
 *  2 |      r12.15:0      | + 04
 *    +--------------------+
 *  3 |   0  | r12.19:16   | + 06
 *    +--------------------+
 *  4 |      r13.15:0      | + 08
 *    +--------------------+
 *  5 |   0  | r13.19:16   | + 10
 *    +--------------------+
 *  6 |      r14.15:0      | + 12      
 *    +--------------------+
 *  7 |   0  | r14.19:16   | + 14
 *    +--------------------+
 *  8 |       r15.15:0     | + 16
 *    +--------------------+
 *  9 |   0  | r15.19:16   | + 18
 *    +--------------------+
 * 10 | PC.19:16 | SR.11:0 | + 20
 *    +--------------------+
 * 11 |      PC.15:0       | + 22
 *    +--------------------+
 * 12 | CallTerminateXXX   | + 24
 *    +--------------------+
 *
 * We have to restore r11 and REG_RETARG and clean the stack before returning.
 */
tpl_sc_handler_no_context_switch:
  mova        r13, r1                               /* get back to process stack          */
  movx.a      REG_RETARG_OFFSET(r1), REG_RETARG     /* get back REG_RETARG     */
  popx.a      r11                                   /* get back r11            */
  addx.a      #16, r1                               /* clean the stack         */
  reti                                             /* return with int enabled */
/*-----------------------------------------------------------------------------
 * -18- We get here coming from stage 2. We are on the kernel stack because
 * the tpl_sc_handler has been called from a hook. We do not have to init the
 * tpl_kern fields here and we do not have to check them to see if a context
 * switch is needed. So it is a simple call. Return to the caller is done with
 * a ret because the sr has not been pushed when coming from stage 2.
 */
tpl_sc_handler_from_hook:
  rlax.a      REG_SID                      /* index -> offset               */
  rlax.a      REG_SID                      /* index -> offset               */
  calla     tpl_dispatch_table(REG_SID)
  reta

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

/*
 * End of tpl_sc_handler.S
 *=============================================================================
 */


;     jhs         tpl_sc_handler_invalid_service_id
; 	/* Make room(16 bytes) on the stack for volatile registers */
;     sub         #16, r1
; 	/* tpl_sc_handler need one working register, 
; 	 * we choose r11 which has to be saved on the stack before using it 
; 	*/
;     pushx.a     r11
; 	/* interrupts are disabled */
;     dint
; 	/* the bottom of the stack have to be 'normalized'
; 	 * i.e. same configuration as in an interrupt
; 	 */
;     mov     22(r1), r11    /* Saved PC [19..16] -> r11                  */
;     mov     20(r1), 22(r1) /* Copy saved PC [15..0] at the good place   */
;     swpb    r11            /* Get saved PC [19..16] in bits 11..8       */
;     rlam.w  #4, r11        /* Shift them to bits 19..16                 */
;     bis     r2, r11        /* Add the SR in its location at 11..0       */
;     bis     #8, r11        /* set GIE bit (reset just before with dint) */
;     mov     r11, 20(r1)    /* The stack is ok                           */

; 	/* tpl_reentrancy_counter is checked to prevent a switch to the kernel 
;      * when executing a service called by a hook 
; 	 */
;     tst.b       &tpl_reentrancy_counter
;     jnz         tpl_sc_handler_no_stack_switch

; 	/* **************************************
; 	 * ******  stack switch -> Kernel *******
; 	 * **************************************
; 	 * ** now the stack is the one of the kernel **
; 	 * the process stack pointer is saved on the stack 
; 	 */
;     mov         r1, r11
;     mov         #tpl_kernel_stack_bottom, r1
;     push        r11

; tpl_sc_handler_no_stack_switch:
; 	/* increment tpl_reentrancy counter */
;     inc.b       &tpl_reentrancy_counter
; 	/* init the NEED_SWITCH/SAVE flags in tpl_kern */
;     mov         #tpl_kern, r11
;     mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
;     mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SCHEDULE(r11)
; 	/* call the service */
;     rla         REG_SID             /* index -> offset (=index<<1) */
;     call        tpl_dispatch_table(REG_SID)

; 	/* REG_RETARG holds the return value. 
; 	 * It is put in its location in the process stack. 
; 	 */
;     pop	r13 //get back PSP => r13
;     movx.a REG_RETARG, 16(r13) //put in Process's stack
; 	/* check the context switch condition in tpl_kern */
;     mov         #tpl_kern, r11
;     tst.b       TPL_KERN_OFFSET_NEED_SWITCH(r11)
;     jz          tpl_sc_handler_no_context_switch
; 	/* prepare the call to tpl_run_elected by setting 
; 	 * REG_RETARG to 0, a.k.a. no save */
;     mov         #0, REG_RETARG
; 	/* test the NEED_SAVE condition */
;     bit.b       #NEED_SAVE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
;     jz          tpl_sc_handler_no_save_running_context
; 	/* Save the remaining registers of the context 
; 	 * The MSP430 have a "push multiple words", but no "mov multiple word". 
; 	 * So, we get back to process stack to benefit this instruction
; 	*/
;     mov    r1, r14	/* get a copy of the KSP to restore it later */
;     mov	   r13, r1	/* change stack to process stack */	
;     pushm.a #7, r10	/* Push r4 to r10 on process stack (save) */
;     mov	   r1, r13	/* get process stack back */	
;     mov    r14, r1	/* get back to kernel stack */
; 	/* The whole context is now saved on the process stack 
; 	 * and the kernel stack has been cleaned 
; 	 * the stack pointer is saved in the dedicated location 
; 	 */
;     mov         &tpl_kern, r11      /* Get the s_running slot of tpl_kern in r11 */
;     mov         @r11, r11           /* Get the pointer to the context (SP alone) */
;     mov         r13, @r11           /* Save the stack pointer */
; 	/* prepare the argument of tpl_run_elected: 
; 	 * 1(save) and call it after switching back to the kernel stack 
; 	 */
;     mov         #1, REG_RETARG		/* argument f tpl_run_elected:1 (save) */

; tpl_sc_handler_no_save_running_context:

;     /*add         #2, r1               "pop" the PSP which is no longer useful */
;     call        #tpl_run_elected
; 	/* tpl_run_elected has copied the elected process slot 
; 	 * of the tpl_kern of the running slot
; 	 * we load the stack pointer of the new running process
; 	 */
;     mov         &tpl_kern, r11      /* Get the s_running slot of tpl_kern in r11 */
;     mov         @r11, r11           /* Get the pointer to the context (SP alone) */
; 	/* **************************************
; 	 * ****** stack switch -> process *******
; 	 * **************************************
; 	 */
;     mov         @r11, r1            /* Get the stack pointer */
; 	/* the context of the new runnign process is loaded, we pop r4 to r10 */
;     popm.a      #7, r10             /* pop r4 to r10 */
; 	jmp tpl_sc_end_of_context_switch

; 	/* If there is no ctx switch, we are still on kernel stack...
; 	 */
; tpl_sc_handler_no_context_switch:
; 	mov r13, r1	 /* get back to process stack */

; 	/* tpl_reentrancy_counter is decremented, interrupts are enabled, we return */
; tpl_sc_end_of_context_switch:
;     dec.b       &tpl_reentrancy_counter
;     jnz         tpl_sc_handler_still_in_kernel

; tpl_sc_handler_still_in_kernel:
;     popx.a      r11
;     add         #12, r1             /* skip volatile */
;     popx.a      REG_RETARG          /* Get back the return value */
;     reti

; tpl_sc_handler_invalid_service_id:
; 	/* return with a simple 'ret', as the stack shape has not been
; 	 * updated yet.
; 	 */
;     ret

; /* MAYBE SHOULDN'T BE HERE BUT IN A SEPERATE FILE */
; .global TIMER3_A0_Handler
; .type   TIMER3_A0_Handler, %function
; TIMER3_A0_Handler:
;     pushx.a REG_RETARG
; #ifdef MSPGCC_ABI
;     /* r15 has been pushed by pushed by pushx.a REG_RETARG */
;     pushm.a     #4, r14                     /* Push r11, r12, r13, r14 */
; #endif
; #ifdef GCCFORMSP_ABI
;     /* r12 has been pushed by pushx.a REG_RETARG */
;     pushm.a     #3, r15                     /* push r13, r14, r15 */
;     pushx.a     r11
; #endif

;     mov         r1, r11 /* Copy the PSP to r11 */
;     mov         #tpl_kernel_stack_bottom, r1/* Switch to the kernel stack */
;     push        r11                         /* Save PCP to kernel stack */

;     mov         #tpl_kern, r11
;     mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
;     mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SCHEDULE(r11)

;     call        #tpl_tick_TIMER3_A0_VECTOR

;     mov         r1, r13                     /* get a copy of the KSP to restore it later */
;     pop         r1                          /* get the saved process stack pointer back */

    
;     mov         #tpl_kern, r11              /* check the context switch condition in tpl_kern */
;     tst.b       TPL_KERN_OFFSET_NEED_SWITCH(r11)
;     jz          tpl_TIMER3_A0_Handler_no_context_switch

;     pushm.a     #7, r10                     /* push r4 to r10 */

;     mov         &tpl_kern, r11              /* Get the s_running slot of tpl_kern in r11 */
;     mov         @r11, r11                   /* get the pointer to the context (SP alone) */
;     mov         r1, @r11                    /* Save the stack pointer */

;     mov         r13, r1                     /* Switch back to the kernel stack */
;     mov         #1, REG_RETARG
;     add         #2, r1                      /* "pop" the PSP which is no longer usefull */
;     call        #tpl_run_elected

;     mov         &tpl_kern, r11              /* Get the s_runnign slot of tpl_kern in r11 */
;     mov         @r11, r11                   /* Get the pointer to the context (SP alone) */
;     mov         @r11, r1                    /* Get the stack  pointer */

;     popm.a      #7, r10                     /* Pop r4 to r10 */

; tpl_TIMER3_A0_Handler_no_context_switch:
; #ifdef MSPGCC_ABI
;     /* r15 will be popped by popx.a REG_RETARG */
;     popm.a      #4, r14                     /* Pop r11, r12, r13, r14 */
; #endif
; #ifdef GCCFORMSP_ABI
;     /* r12 will be popped by popx.a REG_RETARG */
;     popx.a      r11
;     popm.a      #3, r15                     /* Pop r13, r14, r15 */
; #endif
;     popx.a      REG_RETARG
;     reti

; #define OS_STOP_SEC_CODE
; #include "tpl_as_memmap.h"
