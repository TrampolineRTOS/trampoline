#include "tpl_asm_definitions.h"
#include "tpl_service_ids.h"

    .global tpl_sc_handler
    .global tpl_switch_context
    .extern tpl_dispatch_table
    .extern tpl_run_elected
    .extern tpl_kern
    .extern end_except
    .extern tpl_reentrancy_counter
    .extern tpl_mestatus
    .extern nextISP

#define NO_NEED_SWITCH_NOR_SCHEDULE 0
#define NO_NEED_SWITCH 0
#define NEED_SWITCH 1
#define NEED_SAVE 2
#define EXCEPTION_STACK_SIZE 128

tpl_sc_handler:
    /* Creates stack */
    addi sp, sp, -32
    sw a0, 0(sp)
    sw a5, 4(sp)
    sw a6, 8(sp)
    sw a7, 12(sp)
    sw ra, 16(sp)

    /* adjusts mepc */
    csrr a5, mepc
    addi a5, a5, 4
    csrw mepc, a5

    /* Adjusts reentrancy counter */
    lw a5, tpl_reentrancy_counter
    addi a5, a5, 1
    la a6, tpl_reentrancy_counter
    sw a5, 0(a6)

    /* Gets function pointer to the service */
    la a5, tpl_dispatch_table
    slli a7, a7, 2
    add a5, a5, a7
    lw a5, 0(a5)

    /* Jumps to handler */
    jalr a5

    /* Stores return value in stack */
    sw a0, 0(sp)

    /* No context switch if reentrant system call */
    lw a5, tpl_reentrancy_counter
    li a6, 1
    bne a5, a6, tpl_sc_no_context_switch

tpl_switch_context:
    /* Checks the context switch condition */
    la a5, tpl_kern
    lb a6, TPL_KERN_OFFSET_NEED_SWITCH(a5)
    beqz a6, tpl_sc_no_context_switch

    /* Prepare the call to tpl_run_elected by setting a0 to 0, aka no save */
    li a0, 0

    /* Check the save condition */
    li a5, NEED_SAVE
    and a5, a5, a6
    beqz a5, tpl_sc_handler_no_save_running_context

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

    /* Reset tpl_need_switch variable */
    la a5, tpl_kern
    sb zero, TPL_KERN_OFFSET_NEED_SWITCH(a5)

tpl_sc_no_context_switch:
    /* Wakes up core in reentrant kernel calls by triggering dummy event */
    li a5, 0x1a104018 //ESP
    li a6, 1
    sw a6, 0(a5)

    /* Adjusts reentrancy counter */
    lw a5, tpl_reentrancy_counter
    addi a5, a5, -1
    la a6, tpl_reentrancy_counter
    sw a5, 0(a6)

    /* Reenables interruptions */
    bnez a5, 1f
    lw a6, tpl_mestatus
    csrw 0x7c0, a6

    /* Clears up dummy event */
    li a5, 0x1a10401C //ECP
    li a6, 1
    sw a6, 0(a5)

    /* Trigger pending interruptions */
    li a5, 0x1a104000
    lw a6, nextISP
    sw a6, 8(a5) //ISP
    la a5, nextISP
    sw zero, 0(a5)

1:
    /* Reloads working registers */
    lw ra, 16(sp)
    lw a7, 12(sp)
    lw a6, 8(sp)
    lw a5, 4(sp)
    lw a0, 0(sp)
    addi sp, sp, 32

    /* Returns */
    eret

tpl_save_context:
    .global tpl_save_context
    /* Saves return address and stack pointer */

    csrr a6, mepc
    sw a6, 4(a0)

    lw a6, tpl_mestatus
    sw a6, 8(a0)

    lw a5, 16(sp)
    sw a5, 12(a0) //ra

    // Saves pile
    addi sp, sp, -EXCEPTION_STACK_SIZE
    sw  sp, 0(a0)
    sw  x3, 0x00(sp)  // gp
    sw  x4, 0x04(sp)  // tp
    sw  x5, 0x08(sp)  // t0
    sw  x6, 0x0c(sp)  // t1
    sw  x7, 0x10(sp)  // t2
    sw x11, 0x14(sp)  // a1
    sw x12, 0x18(sp)  // a2
    sw x13, 0x1C(sp)  // a3
    sw x14, 0x20(sp)  // a4
    sw x28, 0x24(sp)  // t3
    sw x29, 0x28(sp)  // t4
    sw x30, 0x2c(sp)  // t5
    sw x31, 0x30(sp)  // t6
    csrr x28, 0x7B0
    csrr x29, 0x7B1
    csrr x30, 0x7B2
    sw x28, 0x34(sp)  // lpstart[0]
    sw x29, 0x38(sp)  // lpend[0]
    sw x30, 0x3C(sp)  // lpcount[0]
    csrr x28, 0x7B4
    csrr x29, 0x7B5
    csrr x30, 0x7B6
    sw x28, 0x40(sp)  // lpstart[1]
    sw x29, 0x44(sp)  // lpend[1]
    sw x30, 0x48(sp)  // lpcount[1]
    sw x8, 0x4C(sp)   // s0
    sw x9, 0x50(sp)   // s1
    sw x18, 0x54(sp)  // s2
    sw x19, 0x58(sp)  // s3
    sw x20, 0x5C(sp)  // s4
    sw x21, 0x60(sp)  // s5
    sw x22, 0x64(sp)  // s6
    sw x23, 0x68(sp)  // s7
    sw x24, 0x6C(sp)  // s8
    sw x25, 0x70(sp)  // s9
    sw x26, 0x74(sp)  // s10
    sw x27, 0x78(sp)  // s11

    ret

tpl_load_context:
    .global tpl_load_context
    /* Reloads return address, interrupt mask, and stack pointer */
    lw sp, 0(a0)

    lw x27, 0x78(x2)  // s11
    lw x26, 0x74(x2)  // s10
    lw x25, 0x70(x2)  // s9
    lw x24, 0x6C(x2)  // s8
    lw x23, 0x68(x2)  // s7
    lw x22, 0x64(x2)  // s6
    lw x21, 0x60(x2)  // s5
    lw x20, 0x5C(x2)  // s4
    lw x19, 0x58(x2)  // s3
    lw x18, 0x54(x2)  // s2
    lw x9,  0x50(x2)  // s1
    lw x8,  0x4c(x2)  // s0
    lw x28, 0x40(x2)  // lpstart[1]
    lw x29, 0x44(x2)  // lpend[1]
    lw x30, 0x48(x2)  // lpcount[1]
    csrrw x0, 0x7B4, x28
    csrrw x0, 0x7B5, x29
    csrrw x0, 0x7B6, x30
    lw x28, 0x34(x2)  // lpstart[0]
    lw x29, 0x38(x2)  // lpend[0]
    lw x30, 0x3C(x2)  // lpcount[0]
    csrrw x0, 0x7B0, x28
    csrrw x0, 0x7B1, x29
    csrrw x0, 0x7B2, x30
    lw  x3, 0x00(x2)
    lw  x4, 0x04(x2)
    lw  x5, 0x08(x2)
    lw  x6, 0x0c(x2)
    lw  x7, 0x10(x2)
    lw x11, 0x14(x2)
    lw x12, 0x18(x2)
    lw x13, 0x1C(x2)
    lw x14, 0x20(x2)
    lw x28, 0x24(x2)
    lw x29, 0x28(x2)
    lw x30, 0x2C(x2)
    lw x31, 0x30(x2)
    addi sp, sp, EXCEPTION_STACK_SIZE

    lw a6, 4(a0)
    csrw mepc, a6

    la a5, tpl_mestatus
    lw a6, 8(a0)
    sw a6, 0(a5)

    lw a5, 12(a0)
    sw a5, 16(sp) //ra

    ret

tpl_set_priority:
    .global tpl_set_priority

    li a5, 0x1a104000
    la a6, tpl_priority_interruption_masks
    slli a7, a0, 2
    add a6, a6, a7
    lw a6, 0(a6)
    sw a6, 0(a5) //IER
    ret
