#include "tpl_asm_definitions.h"
        
	      .global tpl_sc_handler
	      .global tpl_switch_context
	      .extern tpl_dispatch_table
	      .extern tpl_run_elected
	      .extern tpl_kern
	      .extern end_except
	        
#define NO_NEED_SWITCH_NOR_SCHEDULE 0
#define NO_NEED_SWITCH 0
#define NEED_SWITCH 1
#define NEED_SAVE 2

tpl_sc_handler:
	      /* Creates stack */
	      addi sp, sp, -16
	      sw a5, 0(sp)
	      sw a6, 4(sp)
	      sw a7, 8(sp)

	      /* Reset tpl_kern variables */
	      la a5, tpl_kern
	      sb zero, TPL_KERN_OFFSET_NEED_SWITCH(a5)
	      sb zero, TPL_KERN_OFFSET_NEED_SCHEDULE(a5)
	      
	      /* Gets function pointer to the service */
	      la a5, tpl_dispatch_table
	      slli a7, a7, 2
	      add a5, a5, a7
	      lw a5, 0(a5)
        
	      /* Jumps to handler */
	      jalr a5
        
	      /* Stores return value in stack created at store_regs (0x14 + 0x10) */
	      sw a0, 0x24(sp)

tpl_switch_context:
	      /* Checks the context switch condition */
	      la a5, tpl_kern
	      lb a6, TPL_KERN_OFFSET_NEED_SWITCH(a5)
	      beq a6, zero, tpl_sc_no_context_switch
        
	      /* Prepare the call to tpl_run_elected by setting a0 to 0, aka no save */
	      li a0, 0

        /* Check the save condition */
	      li a5, NEED_SAVE
	      and a5, a5, a6
	      beq a5, zero, tpl_sc_handler_no_save_running_context
	      
	      /* Save context */
	      la  a0, tpl_kern
	      lw  a0, TPL_KERN_OFFSET_S_RUNNING(a0)
	      lw  a0, 0(a0)
	      jal tpl_save_context
        
	      /* Prepare the call to tpl_run_elected by setting a0 to 1 */
	      li a0, 1
        
tpl_sc_handler_no_save_running_context:
	      /* Call tpl_run_elected */
	      jal  tpl_run_elected

        /* Load context */
        la  a0, tpl_kern
        lw  a0, TPL_KERN_OFFSET_S_RUNNING(a0)
        lw  a0, 0(a0)
        jal tpl_load_context
        
tpl_sc_no_context_switch:
	      /* Reloads working registers */
	      la ra, end_except
        lw a7, 8(sp)
        lw a6, 4(sp)
	      lw a5, 0(sp)
	      addi sp, sp, 16
        
	      /* Returns */
	      ret
        
tpl_save_context:
	      .global tpl_save_context
	      /* Saves return address and stack pointer */
        sw sp, 0(a0)

        csrr a6, mepc
	      sw a6, 4(a0)

	      ret
        
tpl_load_context:
	      .global tpl_load_context
	      /* Reloads return address and stack pointer */
	      lw sp, 0(a0)

        lw a6, 4(a0)
        csrw mepc, a6
        
	      ret
        