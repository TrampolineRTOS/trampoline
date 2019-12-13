#include "tpl_assembler.h"
#include "tpl_asm_definitions.h"
#include "tpl_service_ids.h"
#include "tpl_kern_stack.h"

/*
 * The reentrancy flag is used to distinguish between a service call`
 * from the application and from a hook.
 * If 0, it ia a call from the application
 * if 1, it is a call from a hook
 */
.extern tpl_reentrancy_flag

/*
 * the tpl_sc_handler uses tpl_kern
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

/*
 * the code starts here
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
 *  0 |        PC         | + 0   (return address to the caller)
 *    +-------------------+
 *  1 | CallTerminateXXX  | + 2
 *    +-------------------+
 *
 *-----------------------------------------------------------------------------
 * -1- Compare service id to the number of services to verify its validity
 */
  cmp          #SYSCALL_COUNT, REG_SID
  jlo          tpl_sc_handler_id_ok          /* continue if lower            */
  ret                                        /* return if higher or same     */
tpl_sc_handler_id_ok:
/*-----------------------------------------------------------------------------
 * -2- Disable interrupts so that the kernel cannot be interrupted.
 * Check the reentrancy flag. If it is not zero, it means the service is
 * called from a hook and has to be processed differently.
 */
  dint
  nop	                              /*required after dint instruction*/
  tst.b        &tpl_reentrancy_flag
  jnz          tpl_sc_handler_from_hook
/*-----------------------------------------------------------------------------
 * -3- We need to have the same stack pattern for both the tpl_sc_handler and
 * an interrupt handler which calls the operating system. So we push the SR
 * and we reset the 4 higher bits (high weight of PC, not sure it is needed)
 * and set GIE in the saved SR
 */
  push         sr
  bic.b        #0xF0, 1(r1)           /* reset the 4 higher bits of saved SR */
  bis.b        #0x08, 0(r1)           /* set the GIE bit in the saved SR     */
/*
 * PROCESS STACK:
 *    +----+--------------+
 *  0 |0000|      SR      | + 0
 *    +----+--------------+
 *  1 |        PC         | + 2
 *    +-------------------+
 *  2 | CallTerminateXXX  | + 4
 *    +-------------------+
 *
 *-----------------------------------------------------------------------------
 * -4- Obviously volatile registers (r12 to r15 because we take into account
 * both ABIs) are not saved in tpl_sc_handler since the caller does not expect
 * their values to be preserved but we need to make room (8 bytes) on the
 * stack for them because an interrupt handler will save these registers at
 * this location.
 * The tpl_sc_handler needs one working register and we choose to use r11
 * which has to be saved on the process stack before using it.
 */
  sub          #8, sp
  push         r11
/*
 * PROCESS STACK:
 *    +-------------------+
 *  0 |        r11        | + 00
 *    +-------------------+
 *  1 |        r12        | + 02
 *    +-------------------+
 *  2 |        r13        | + 04
 *    +-------------------+
 *  3 |        r14        | + 06
 *    +-------------------+
 *  4 |        r15        | + 08
 *    +----+--------------+
 *  5 |0000|      SR      | + 10
 *    +----+--------------+
 *  6 |         PC        | + 12
 *    +-------------------+
 *  7 | CallTerminateXXX  | + 14
 *    +-------------------+
 *
 *-----------------------------------------------------------------------------
 * -5- Before calling the service, we setup the kernel stack. The process stack
 * pointer (PSP) is saved in r11, then SP is loaded to the kernel stack bottom
 * and the PSP is saved on the kernel stack.
 */
  mov      r1, r11                         /* save the PSP into r11          */
  mov      #tpl_kern_stack + TPL_KERNEL_STACK_SIZE, r1 /* on kernel stack    */
  push     r11                             /* push the PSP on it             */
/*
 * PROCESS STACK:                 KERNEL STACK:
 *    +-------------------+          +-------------------+
 *  0 |        r11        | + 00     |        PSP        |
 *    +-------------------+          +-------------------+
 *  1 |        r12        | + 02
 *    +-------------------+
 *  2 |        r13        | + 04
 *    +-------------------+
 *  3 |        r14        | + 06
 *    +-------------------+
 *  4 |        r15        | + 08
 *    +----+--------------+
 *  5 | PC |      SR      | + 10
 *    +----+--------------+
 *  6 |         PC        | + 12
 *    +-------------------+
 *  7 | CallTerminateXXX  | + 14
 *    +-------------------+
 *
 *-----------------------------------------------------------------------------
 * -6- Init the NEED_SWITCH/NEED_SAVE in tpl_kern.
 */
  mov      #tpl_kern, r11
  mov.b    #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
  mov.b    #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SCHEDULE(r11)
/*-----------------------------------------------------------------------------
 * -7- Call the service. The reentrancy flag is incremented before and
 * decremented after.
 */
  inc.b    &tpl_reentrancy_flag         /* surround the call by inc ...  */
  rla      REG_SID                      /* index -> offset               */
  call     tpl_dispatch_table(REG_SID)  /* func ptrs in dispatch table   */
  dec.b    &tpl_reentrancy_flag         /* ... and dec of the flag.      */
/*-----------------------------------------------------------------------------
 * -8- From there, REG_RETARG holds the return value. It is put at its location
 * in the process stack. Also r13 and r14 become usable whatever is the ABI.
 */
  pop      r13                                /* get back PSP => r13.    */
  mov      REG_RETARG, REG_RETARG_OFFSET(r13) /* put in Process's stack  */
/*
 * PROCESS STACK:                 KERNEL STACK:
 *    +-------------------+
 *  0 |        r11        | + 00             EMPTY
 *    +-------------------+
 *  1 |        r12 *      | + 02
 *    +-------------------+
 *  2 |        r13        | + 04
 *    +-------------------+
 *  3 |        r14        | + 06
 *    +-------------------+
 *  4 |        r15 †      | + 08
 *    +----+--------------+
 *  5 | PC |      SR      | + 10
 *    +----+--------------+
 *  6 |         PC        | + 12
 *    +-------------------+
 *  7 | CallTerminateXXX  | + 14
 *    +-------------------+
 *
 *    * updated if GCC for MSP ABI
 *    † updated if MSPGCC ABI
 *-----------------------------------------------------------------------------
 * -9- Check the context switch condition in tpl_kern.
 */
  mov      #tpl_kern, r11
  tst.b    TPL_KERN_OFFSET_NEED_SWITCH(r11)
  jz       tpl_sc_handler_no_context_switch
/*
 * From here we are doing a context switching
 *
 *-----------------------------------------------------------------------------
 * -10- Prepare the call to tpl_run_elected REG_RETARG to 0, aka no save.
 */
  mov      #0, REG_RETARG
/*-----------------------------------------------------------------------------
 * -11- Test the NEED_SAVE condition.
 */
  bit.b    #NEED_SAVE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
  jz       tpl_sc_handler_no_save_running_context
/*-----------------------------------------------------------------------------
 * -12- Save the context. The MSP430 have a "push multiple words", but no
 * "move multiple word". So, we get back to process stack to benefit this
 * instruction
 */
  mov      r1, r14          /* get a copy of the KSP to restore it later */
  mov      r13, r1          /* change stack to process stack             */
  pushm.w  #7, r10          /* Push r4 to r10 on process stack (save)    */
/*
 * The whole context is now saved on process stack and the kernel stack
 * has been cleaned. r14 points to the kernel stack.
 *
 * PROCESS STACK:                 KERNEL STACK:
 *    +-------------------+
 *  0 |         r4        | + 00             EMPTY
 *    +-------------------+
 *  1 |         r5        | + 02
 *    +-------------------+
 *  2 |         r6        | + 04
 *    +-------------------+
 *  3 |         r7        | + 06
 *    +-------------------+
 *  4 |         r8        | + 08
 *    +-------------------+
 *  5 |         r9        | + 10
 *    +-------------------+
 *  6 |        r10        | + 12
 *    +-------------------+
 *  7 |        r11        | + 14
 *    +-------------------+
 *  8 |        r12        | + 16
 *    +-------------------+
 *  9 |        r13        | + 18
 *    +-------------------+
 * 10 |        r14        | + 20
 *    +-------------------+
 * 11 |        r15        | + 22
 *    +----+--------------+
 * 12 | PC |      SR      | + 24
 *    +----+--------------+
 * 13 |         PC        | + 26
 *    +-------------------+
 * 14 | CallTerminateXXX  | + 28
 *    +-------------------+
 *
 *-----------------------------------------------------------------------------
 * -13- Now the stack pointer is saved in the dedicated location.
 */
  mov      &tpl_kern, r11   /* Get the s_running slot of tpl_kern in r11 */
  mov      @r11, r11        /* Get the pointer to the context (SP alone) */
  mov      r1, @r11         /* Save the stack pointer                    */
/*-----------------------------------------------------------------------------
 * -14- Prepare the argument of tpl_run_elected: 1 (aka save) and call it after
 * switching back to the kernel stack.
 */
  mov      r14, r1          /* get back to kernel stack                  */
  mov      #1, REG_RETARG
tpl_sc_handler_no_save_running_context:
/*
 * Note: when getting there with a jump, we are coming from stage 11 where we
 * are on the kernel task. So no need to switch in this because
 */
  call     #tpl_run_elected
/*-----------------------------------------------------------------------------
 * -15- tpl_run_elected has copied the elected process slot of tpl_kern to the
 * running slot. We load the stack pointer of the new running process.
 */
  mov      &tpl_kern, r11   /* Get the s_running slot of tpl_kern in r11 */
  mov      @r11, r11        /* Get the pointer to the context (SP alone) */
  mov      @r11, r1         /* Get the stack pointer                     */
/*
 * PROCESS STACK:                 KERNEL STACK:
 *    +-------------------+
 *  0 |         r4        | + 00             EMPTY
 *    +-------------------+
 *  1 |         r5        | + 02
 *    +-------------------+
 *  2 |         r6        | + 04
 *    +-------------------+
 *  3 |         r7        | + 06
 *    +-------------------+
 *  4 |         r8        | + 08
 *    +-------------------+
 *  5 |         r9        | + 10
 *    +-------------------+
 *  6 |        r10        | + 12
 *    +-------------------+
 *  7 |        r11        | + 14
 *    +-------------------+
 *  8 |        r12        | + 16
 *    +-------------------+
 *  9 |        r13        | + 18
 *    +-------------------+
 * 10 |        r14        | + 20
 *    +-------------------+
 * 11 |        r15        | + 22
 *    +----+--------------+
 * 12 | PC |      SR      | + 24
 *    +----+--------------+
 * 13 |         PC        | + 26
 *    +-------------------+
 * 14 | CallTerminateXXX  | + 28
 *    +-------------------+
 *
 *-----------------------------------------------------------------------------
 * -16- Now, the context of the new running process is loaded. Registers r4 to
 * r15} are popped and we return.
 */
  popm.w   #12,r15                 /* pop r4 to r15 at once              */
  reti                             /* and return with interrupts enabled */
/*-----------------------------------------------------------------------------
 * -17- We get there from stage 9 and we are on the kernel stack and r13
 * contains the process stack pointer. No context switch has to be performed,
 * we go back to the process stack which is as follow:
 *
 * PROCESS STACK:
 *    +-------------------+
 *  0 |        r11        | + 00
 *    +-------------------+
 *  1 |        r12        | + 02
 *    +-------------------+
 *  2 |        r13        | + 04
 *    +-------------------+
 *  3 |        r14        | + 06
 *    +-------------------+
 *  4 |        r15        | + 08
 *    +----+--------------+
 *  5 | PC |      SR      | + 10
 *    +----+--------------+
 *  6 |         PC        | + 12
 *    +-------------------+
 *  7 | CallTerminateXXX  | + 14
 *    +-------------------+
 *
 * We have to restore r11 and REG_RETARG and clean the stack before returning.
 */
tpl_sc_handler_no_context_switch:
  mov      r13, r1                 /* get back to process stack          */
  mov      REG_RETARG_OFFSET(r1), REG_RETARG  /* get back REG_RETARG     */
  pop      r11                                /* get back r11            */
  add      #8, r1                             /* clean the stack         */
  reti                                        /* return with int enabled */
/*-----------------------------------------------------------------------------
 * -18- We get here coming from stage 2. We are on the kernel stack because
 * the tpl_sc_handler has been called from a hook. We do not have to init the
 * tpl_kern fields here and we do not have to check them to see if a context
 * switch is needed. So it is a simple call. Return to the caller is done with
 * a ret because the sr has not been pushed when coming from stage 2.
 */
tpl_sc_handler_from_hook:
  rla      REG_SID                      /* index -> offset               */
  call     tpl_dispatch_table(REG_SID)
  ret

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

/*
 * End of tpl_sc_handler.S
 *=============================================================================
 */
