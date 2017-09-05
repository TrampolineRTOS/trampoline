// Copyright 2016 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the “License”); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an “AS IS” BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include "pulpino.h"

#define EXCEPTION_STACK_SIZE 128

    .extern tpl_sc_handler
    .extern tpl_interruption_handler
    .extern idle_function

/* ========================================================= [ entry ] === */
    .section .text
reset_handler:
    .global reset_handler
    /* set all registers to zero */
    mv  x1, x0
    mv  x2, x1
    mv  x3, x1
    mv  x4, x1
    mv  x5, x1
    mv  x6, x1
    mv  x7, x1
    mv  x8, x1
    mv  x9, x1
    mv x10, x1
    mv x11, x1
    mv x12, x1
    mv x13, x1
    mv x14, x1
    mv x15, x1
    mv x16, x1
    mv x17, x1
    mv x18, x1
    mv x19, x1
    mv x20, x1
    mv x21, x1
    mv x22, x1
    mv x23, x1
    mv x24, x1
    mv x25, x1
    mv x26, x1
    mv x27, x1
    mv x28, x1
    mv x29, x1
    mv x30, x1
    mv x31, x1

    /* stack initilization */
    la   x2, _stack_start

_start:
    .global _start

    /* clear BSS */
    la x26, _bss_start
    la x27, _bss_end

    bge x26, x27, zero_loop_end

zero_loop:
    sw x0, 0(x26)
    addi x26, x26, 4
    ble x26, x27, zero_loop
zero_loop_end:
    /* Run global initialization functions */
    call    __libc_init_array

main_entry:
    addi   x10, x0, 0
    addi   x11, x0, 1
    jal  uart_set_cfg;

    /* jump to main program entry point (argc = argv = 0) */
    addi x10, x0, 0
    addi x11, x0, 0
    jal x1, main

    jal uart_wait_tx_done;
    j   idle_function

/* ================================= [ illegal instruction handler] === */
.global illegal_insn_handler
illegal_insn_handler:
    csrci 0x7c0, 1
    j illegal_insn_handler_c

    .global _init
    .global _fini
_init:
_fini:
    # These don't have to do anything since we use init_array/fini_array.
    ret

/* =================================================== [ exceptions ] === */
/* This section has to be down here, since we have to disable rvc for it  */

    .section .vectors, "ax"
    .option norvc;

    // external interrupts are handled by the same callback
    // until compiler supports IRQ routines
    .org 0x00
    .rept 32
    j tpl_interruption_handler
    .endr

    // reset vector
    .org 0x80
    jal x0, reset_handler

    // illegal instruction exception
    .org 0x84
    jal x0, illegal_insn_handler

    // ecall handler
    .org 0x88
    jal x0, tpl_sc_handler
