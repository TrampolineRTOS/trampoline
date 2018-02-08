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

    sw  sp, 0x00(a0)

    csrr a6, mepc
    sw a6, 0x04(a0)

    lw a6, tpl_mestatus
    sw a6, 0x08(a0)

    lw a5, 16(sp)
    sw a5, 0x0C(a0) //ra

    // Saves pile
    sw  x3, 0x10(a0)  // gp
    sw  x4, 0x14(a0)  // tp
    sw  x5, 0x18(a0)  // t0
    sw  x6, 0x1C(a0)  // t1
    sw  x7, 0x20(a0)  // t2
    sw x11, 0x24(a0)  // a1
    sw x12, 0x28(a0)  // a2
    sw x13, 0x2C(a0)  // a3
    sw x14, 0x30(a0)  // a4
    sw x28, 0x34(a0)  // t3
    sw x29, 0x38(a0)  // t4
    sw x30, 0x3C(a0)  // t5
    sw x31, 0x40(a0)  // t6
    csrr x28, 0x7B0
    csrr x29, 0x7B1
    csrr x30, 0x7B2
    sw x28, 0x44(a0)  // lpstart[0]
    sw x29, 0x48(a0)  // lpend[0]
    sw x30, 0x4C(a0)  // lpcount[0]
    csrr x28, 0x7B4
    csrr x29, 0x7B5
    csrr x30, 0x7B6
    sw x28, 0x50(a0)  // lpstart[1]
    sw x29, 0x54(a0)  // lpend[1]
    sw x30, 0x58(a0)  // lpcount[1]
    sw x8, 0x5C(a0)   // s0
    sw x9, 0x60(a0)   // s1
    sw x18, 0x64(a0)  // s2
    sw x19, 0x68(a0)  // s3
    sw x20, 0x6C(a0)  // s4
    sw x21, 0x70(a0)  // s5
    sw x22, 0x74(a0)  // s6
    sw x23, 0x78(a0)  // s7
    sw x24, 0x7C(a0)  // s8
    sw x25, 0x80(a0)  // s9
    sw x26, 0x84(a0)  // s10
    sw x27, 0x88(a0)  // s11

    ret

tpl_load_context:
    .global tpl_load_context
    /* Reloads return address, interrupt mask, and stack pointer */
    lw x27, 0x88(a0)  // s11
    lw x26, 0x84(a0)  // s10
    lw x25, 0x80(a0)  // s9
    lw x24, 0x7C(a0)  // s8
    lw x23, 0x78(a0)  // s7
    lw x22, 0x74(a0)  // s6
    lw x21, 0x70(a0)  // s5
    lw x20, 0x6C(a0)  // s4
    lw x19, 0x68(a0)  // s3
    lw x18, 0x64(a0)  // s2
    lw x9,  0x60(a0)  // s1
    lw x8,  0x5C(a0)  // s0
    lw x28, 0x50(a0)  // lpstart[1]
    lw x29, 0x54(a0)  // lpend[1]
    lw x30, 0x58(a0)  // lpcount[1]
    csrrw x0, 0x7B4, x28
    csrrw x0, 0x7B5, x29
    csrrw x0, 0x7B6, x30
    lw x28, 0x44(a0)  // lpstart[0]
    lw x29, 0x48(a0)  // lpend[0]
    lw x30, 0x4C(a0)  // lpcount[0]
    csrrw x0, 0x7B0, x28
    csrrw x0, 0x7B1, x29
    csrrw x0, 0x7B2, x30
    lw x31, 0x40(a0)
    lw x30, 0x3C(a0)
    lw x29, 0x38(a0)
    lw x28, 0x34(a0)
    lw x14, 0x30(a0)
    lw x13, 0x2C(a0)
    lw x12, 0x28(a0)
    lw x11, 0x24(a0)
    lw  x7, 0x20(a0)
    lw  x6, 0x1C(a0)
    lw  x5, 0x18(a0)
    lw  x4, 0x14(a0)
    lw  x3, 0x10(a0)

    lw sp, 0(a0)

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
