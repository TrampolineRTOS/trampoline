/**
 * @file olimex_bootstrap_stage1.S
 *
 * @section descr File description
 *
 * First part of the bootstrap for OLIMEX
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "../../../tpl_asm_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

.global tpl_armv7_bootstrap_entry
tpl_armv7_bootstrap_entry:
ldr pc,reset_handler
ldr pc,undefined_handler
ldr pc,swi_handler
ldr pc,prefetch_handler
ldr pc,data_handler
ldr pc,hyp_handler
ldr pc,irq_handler
ldr pc,fiq_handler
reset_handler:      .word reset
undefined_handler:  .word hang
swi_handler:        .word smc
prefetch_handler:   .word hang
data_handler:       .word hang
hyp_handler:        .word hang
irq_handler:        .word irq
fiq_handler:        .word hang

reset:

;@ b skip
mrs r0,cpsr
bic r0,r0,#0x1F
orr r0,r0,#0x13
msr spsr_cxsf,r0
add r0,pc,#4
msr ELR_hyp,r0
eret
skip:

mrc p15, 0, r1, c12, c0, 0 ;@ get vbar
mov r0,#0x8000
;@ mov r1,#0x0000
ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}
ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}

mov r12,#0
mcr p15, 0, r12, c7, c10, 1
dsb
mov r12, #0
mcr p15, 0, r12, c7, c5, 0
mov r12, #0
mcr p15, 0, r12, c7, c5, 6
dsb
isb
smc #0

mrc p15,0,r2,c1,c0,0
bic r2,#0x1000
bic r2,#0x0004
mcr p15,0,r2,c1,c0,0


mov r0,#0x8000
mcr p15, 0, r0, c12, c0, 0

;@ mov r0,#0x8000
;@ mov r1,#0x0000
;@ ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
;@ stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}
;@ ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
;@ stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}

;@ (PSR_IRQ_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
mov r0,#0xD2
msr cpsr_c,r0
mov sp,#0x8000

;@ (PSR_FIQ_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
mov r0,#0xD1
msr cpsr_c,r0
mov sp,#0x4000

;@ (PSR_SVC_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
mov r0,#0xD3
msr cpsr_c,r0
mov sp,#0x8000000

bl notmain
hang: b hang

smc:
mrc p15, 0, r1, c1, c1, 0
bic r1, r1, #1
mcr p15, 0, r1, c1, c1, 0
movs    pc, lr

.globl PUT32
PUT32:
str r1,[r0]
bx lr

.globl GET32
GET32:
ldr r0,[r0]
bx lr

.globl dummy
dummy:
bx lr

.globl enable_irq
enable_irq:
mrs r0,cpsr
bic r0,r0,#0x80
msr cpsr_c,r0
bx lr

irq:
push {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,lr}
@bl c_irq_handler
pop  {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,lr}
subs pc,lr,#4

  /* jump to high level bootstrap part */
notmain:
  b tpl_armv7_bootstrap_stage2

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file olimex_bootstrap_stage1.S */
