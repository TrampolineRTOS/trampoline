#include <avr/io.h> //SP
#include "tpl_asm_definitions.h"
#include "tpl_app_define.h" //ISR_COUNT

#define KERNEL_STACK_SIZE 100

  .global tpl_reentrancy_counter
.data
  .align 2
tpl_reentrancy_counter:
  .short 0
tpl_old_sreg:
  .short 0

//kernel stack: push is post-decremented, so the bottom stack 
//pointer should be the last storage location
tpl_kernel_stack:
  .space KERNEL_STACK_SIZE-1
tpl_kernel_stack_bottom:
  .space 1

.section .text

.extern tpl_dispatch_table
.extern tpl_counter_tick
.extern tpl_kern
.equ  NO_NEED_SWITCH_NOR_SCHEDULE , 0
.equ  NO_NEED_SWITCH              , 0
.equ  NEED_SCHEDULE               , 1
.equ  NEED_SWITCH                 , 1
.equ  NEED_SAVE                   , 2
.equ  TPL_COUNTER_TICK_CALL       , 0x80
.equ  TPL_ISR2_HANDLER_BIT        , 6 
.equ  TPL_ISR2_HANDLER            , (1<<TPL_ISR2_HANDLER_BIT)
.equ SYSCALL_COUNT                , 28


.global tpl_switch_to_kernel_stack
tpl_switch_to_kernel_stack:
	//r18,r19,r20,r21 and r30,r31 may not be restored at the end of the function.
	//according to the ABI (https://gcc.gnu.org/wiki/avr-gcc#Register_Layout)

	//get returned address from current user stack
	pop r2
	pop r3
#ifdef __AVR_3_BYTE_PC__
	pop r4
#endif
	//We DO NOT restore it on the user stack as the return 
	//address will be different when getting back the user stack.
	//get the kernel stack pointer
	ldi r30,lo8(tpl_kernel_stack_bottom)
	ldi r31,hi8(tpl_kernel_stack_bottom)
	//save the sp of the caller
	in r28,_SFR_IO_ADDR(SPL)
	in r29,_SFR_IO_ADDR(SPH)
	//set the kernel stack
	out _SFR_IO_ADDR(SPL), r30
	out _SFR_IO_ADDR(SPH), r31
	/********** current stack is now kernel stack **********/
	//push the return address
#ifdef __AVR_3_BYTE_PC__
	push r4
#endif
	push r3
	push r2
	//... and return with the new stack.
	ret

.global tpl_switch_to_user_stack
tpl_switch_to_user_stack:
	//first thing on the stack is the return address.
	//we need to move it on the user stack
	pop r2
	pop r3
#ifdef __AVR_3_BYTE_PC__
	pop r4
#endif
	//then get back the user stack value
	out _SFR_IO_ADDR(SPL), r28
	out _SFR_IO_ADDR(SPH), r29
	//change to user stack.
	/********** current stack is now user stack **********/
	//get back return address.
#ifdef __AVR_3_BYTE_PC__
	push r4
#endif
	push r3
	push r2
	ret

#avr version of the tpl_counter_tick
.global tpl_avr_counter_tick
tpl_avr_counter_tick:
	ldi r30, TPL_COUNTER_TICK_CALL
	call tpl_sc_handler
	ret
	
#avr entry point for an interrupt
#the first argument should be the ISR2 id.
.global tpl_avr_ISR2_handler
tpl_avr_ISR2_handler:
	ldi r30, TPL_ISR2_HANDLER
	call tpl_sc_handler
	ret

/** This function is a 'virtual' system call handler:
 * It is called by each system call, to enter in the Kernel.
 * System Call arguments are in R24 and registers before.
 * for SetRelAlarm(u8, u32, u32), it uses:
 *  - r16(LSB)-19(MSB) for 3rd arg
 *  - r20(LSB)-23(MSB) for 2nd arg
 *  - r24(LSB)-r25 for first one.
 * value is returned in R24.
 * 
 * we will use as working registers:
 * - R30/R31	:> should not be preserved (unless under interrupt)
 * - R0			:> should not be preserved (unless under interrupt)
 * - R2-R3		:> should be saved on user stack
 * - R16		:> some asm instructions require to use a reg number > 15 (ldi...)

 * get service id on R0.
 * => not on the ABI, but all is in assembly.
 */


.global tpl_sc_handler
tpl_sc_handler:

	/* save working registers on user stack
     */
	//we will use R2 and R3 => save it on user stack.
	push r2
	push r3
	push r4
	push r5
	push r6
	push r7
	//save SREG
	in r2,_SFR_IO_ADDR(SREG)
	push r2
	//save r28/r29 => will get the user stack.
	//TODO: here or in the switch to kernel stack function?
	push r28
	push r29
	mov r7,r30 ;save service id in r7

	/* clear interrupts
	 */
	cli ; update sreg
	
	/* should we have to switch to kernel stack */
	//tpl_reentrancy_counter++
	lds r30,tpl_reentrancy_counter
	subi r30, 0xFF
	sts tpl_reentrancy_counter,r30
	//tpl_reentrancy_counter == 1?
	cpi r30,0x01
	brne tpl_enter_kernel_end
	//yes => tpl_switch_to_kernel_stack
	call tpl_switch_to_kernel_stack ;use r2-r6,r30-r31
tpl_enter_kernel_end:
	
	/* we have now kernel stack
	 * |    |
	 * |    | <- SP (kern)
	 * |----|
	 */

	/* 
	 * Reset the tpl_need_switch variable to NO_NEED_SWITCH before
	 * calling the service. This is needed because, beside
	 * tpl_schedule, no service modify this variable. So an old value
	 * is retained
	 */
	ldi r30, NO_NEED_SWITCH_NOR_SCHEDULE
	sts tpl_kern+TPL_KERN_OFFSET_NEED_SWITCH,r30

	/**call the service
	  */
	mov r30,r7 ;get back the service id.

	// => r16-r24 SHOULD NOT HAVE BEEN MODIFIED BEFORE CALLING
	//    THE SERVICE (it contains service arguments)
	//3 cases here:
	// * call the service (in r30)
	// * call tpl_central_interrupt_handler -> for an ISR
	// * call tpl_counter_tick (for a counter)
	// if MSB = 1 (0x80) => tpl_counter_tick. argument (counter ref) is in r24/r25
	andi r30,TPL_COUNTER_TICK_CALL
	breq no_tpl_counter_tick
		call tpl_counter_tick // *** counter tick part
		//nedd schedule?
		lds r31,tpl_kern+TPL_KERN_OFFSET_NEED_SCHEDULE
		andi r31, NEED_SCHEDULE
		breq tpl_end_call
			call tpl_schedule_from_running
		rjmp tpl_end_call
no_tpl_counter_tick:          // *** not counter call part (may be isr2 or service call).
#if ISR_COUNT != 0
		mov r30,r7  ;get back the service id.
		andi r30, TPL_ISR2_HANDLER
		breq tpl_service_call_part
tpl_isr2_part:                // *** isr2 part
		call tpl_central_interrupt_handler
		rjmp tpl_end_call
tpl_service_call_part:        // *** service call part
#endif //ISR_COUNT
		mov r30,r7 ;get back the service id.
		//check syscall count:
		cpi r30,SYSCALL_COUNT
		brcc tpl_end_call
		//ok, syscall is in the correct range. Now find the function in the dispatch table.
		add r30,r30 //offset is twice (TODO on mega too?)
		ldi r31,0
		subi r30,lo8(-(tpl_dispatch_table))
		sbci r31,hi8(-(tpl_dispatch_table))
		ld r0, Z+	//in the table => get the service function address
		ld r31,Z
		mov r30,r0
		icall

tpl_end_call:                 // *** end of specific parts.
	//We still should preserve r24 (return argument from service.)
	/*
	 * Check the tpl_need_switch variable
	 * to see if a switch should occur
	 */
	lds r31,tpl_kern+TPL_KERN_OFFSET_NEED_SWITCH ; get a need_switch in r31
	mov r30,r31		; get a copy in r30
	andi r30, NEED_SWITCH	;require reg >= 16
	breq no_context_switch
	
	//Ok, there is a context switch
	/*
	 * Check if context of the task/isr that just lost the CPU needs
	 * to be saved. No save is needed for a TerminateTask or ChainTask
	 */
	andi r31,NEED_SAVE
	breq no_save
	//Ok, we have to save the current context.
	call tpl_avr_save_context
	//done.
no_save:
	//ok, here:
	// * the old context is saved (if needed)
	// * the stack is the one of the kernel
	// * the new context is not already loaded
	// -> update tpl_kern internal structures.
	push r24 ; return from the service call
	mov r24,r31 ;call with the SAVE value.
	call tpl_run_elected
	pop r24 ; get back the service call return.

	//now, restore the context.
	call tpl_avr_restore_context
no_context_switch:


	//tpl_reentrancy_counter--
	//r18 may be modified.
	lds r18,tpl_reentrancy_counter
	subi r18, 0x01
	sts tpl_reentrancy_counter,r18
	//tpl_reentrancy_counter == 0?
	and	r18, r18
	brne tpl_leave_kernel_end
	//yes => tpl_switch_to_kernel_stack
	call tpl_switch_to_user_stack 
tpl_leave_kernel_end:

	//epilogue
	pop r29
	pop r28
	pop r2
	out _SFR_IO_ADDR(SREG),r2
	pop r7
	pop r6
	pop r5
	pop r4
	pop r3
	pop r2
	ret

