/**
 * @file tpl_ctx_switch_under_it.S
 *
 * @section descr File description
 *
 * Context switch.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c)
 * CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

.syntax unified
.thumb

#include "tpl_assembler.h"
#include "tpl_asm_definitions.h"
#include "tpl_os_kernel_stack.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/*----------------------------------------------------------------------------*
 * A word about the context                                                   *
 *----------------------------------------------------------------------------*
 * Since in the Cortex architecture an interrupt or an exception triggers the *
 * stacking of some registers, the context is split in two parts. The first   *
 * part is pushed on the stack by the hardware:                               *
 * +-------------------------------+                                          *
 * | R0                            | <- PSP                                   *
 * +-------------------------------+                                          *
 * | R1                            | <- PSP+4                                 *
 * +-------------------------------+                                          *
 * | R2                            | <- PSP+8                                 *
 * +-------------------------------+                                          *
 * | R3                            | <- PSP+12                                *
 * +-------------------------------+                                          *
 * | R12                           | <- PSP+16                                *
 * +-------------------------------+                                          *
 * | LR (aka R14)                  | <- PSP+20                                *
 * +-------------------------------+                                          *
 * | Return Address (saved PC/R15) | <- PSP+24                                *
 * +-------------------------------+                                          *
 * | xPSR (bit 9 = 1)              | <- PSP+28                                *
 * +------------------------+---------------------\                           *
 * | s0 (FPU)               | <- PSP+32 - 0x20    |                           *
 * +------------------------+                     |                           *
 * | ..                     | <- PSP+.. -         |                           *
 * +------------------------+                     |                           *
 * | s15 (FPU)              | <- PSP+92 - 0x5C    |- only if FPU is available *
 * +------------------------+                     |  and process is using FPU *
 * | FPSCR (FPU)            | <- PSP+96 - 0x60    |  (USEFLOAT = TRUE in .oil)*
 * +------------------------+                     |                           *
 * | reserved (align)       | <- PSP+100- 0x64    |                           *
 * +------------------------+---------------------/                           *
 *                                                                            * 
 * The second part is stored in a structure defined in tpl_machine_cortex.h   *
 * with a pointer from the static task descriptor                             *
 * +------------------+                                                       *
 * | R4               | <- CTX_GPR4 (0)                                       *
 * +------------------+                                                       *
 * | R5               | <- CTX_GPR5 (4)                                       *
 * +------------------+                                                       *
 * | R6               | <- CTX_GPR6 (8)                                       *
 * +------------------+                                                       *
 * | R7               | <- CTX_GPR7 (12)                                      *
 * +------------------+                                                       *
 * | R8               | <- CTX_GPR8 (16)                                      *
 * +------------------+                                                       *
 * | R9               | <- CTX_GPR9 (20)                                      *
 * +------------------+                                                       *
 * | R10              | <- CTX_GPR10 (24)                                     *
 * +------------------+                                                       *
 * | R11              | <- CTX_GPR11 (28)                                     *
 * +------------------+                                                       *
 * | PSP (R13)        | <- CTX_PSP (32)                                       *
 * +------------------+                                                       *
 *----------------------------------------------------------------------------*
 */

#include "tpl_regs_offsets.h"

/*=============================================================================
 * tpl_save_context_under_it is used to save the context of the running task.
 * It is used from interrupt handlers.
 *
 * r0 contains a pointer to the static descriptor of the running task.
 * r1-r3 are working registers
 *
 */

.global tpl_save_context_under_it
.type   tpl_save_context_under_it, %function

tpl_save_context_under_it:
    /*-------------------------------------------------------------------------
     * Get a the pointer to the integer context from the pointer to the
     * static descriptor of the running task
     */
    ldr r1,[r0,#INT_CONTEXT]

    /*-------------------------------------------------------------------------
     * Save r4-r11
     */
    str r4,[r1,#CTX_GPR4]
    str r5,[r1,#CTX_GPR5]
    str r6,[r1,#CTX_GPR6]
    str r7,[r1,#CTX_GPR7]
    str r8,[r1,#CTX_GPR8]
    str r9,[r1,#CTX_GPR9]
    str r10,[r1,#CTX_GPR10]
    str r11,[r1,#CTX_GPR11]

    /*-------------------------------------------------------------------------
     * Save the PSP
     */
    mrs r2,psp
    str r2,[r1,#CTX_PSP]

#if WITH_FLOAT == YES
    /*-------------------------------------------------------------------------
     * Get a the pointer to the floating point context from the pointer to the
     * static descriptor of the running task
     */
    ldr r1,[r0,#FLOAT_CONTEXT]
    cmp r1, #0 /* r1 is NULL if there is no float context for this process */
    beq no_save_fp
    /* save all s16 to 31
     * In Lazy Context Switch (LSPEN bit in FPU->FPCCR, enabled by default),
     * s0-s15 may have not been pushed on the stack (PSP) yet. This 
     * FPU related instruction force the push (on PSP).
     * So, this instruction leads to write 17 words on PSP and 16 words on r1! 
     */
    vstm r1!, {s16-s31} 
no_save_fp:
#endif

    bx  lr

/*=============================================================================
 * tpl_load_context_under_it is used to load the context of (not yet)
 * the running task.
 *
 * It is used from interrupt handlers.
 *
 * r0 contains a pointer to the static descriptor of the running task.
 * r1-r3 are working registers
 *
 * ** it SHOULD return LR final value in r0 **
 * LR can be 
 *  * 0xFFFFFFED if the context uses FPU
 *  * 0xFFFFFFFD if the context uses no FPU
 */

.global tpl_load_context_under_it
.type   tpl_load_context_under_it, %function

tpl_load_context_under_it:
    /*-------------------------------------------------------------------------
     * Get a the pointer to the integer context from the pointer to the
     * static descriptor of the running task
     */
    ldr r1,[r0,#INT_CONTEXT]

    /*-------------------------------------------------------------------------
     * load r4-r11
     */
    ldr r4,[r1,#CTX_GPR4]
    ldr r5,[r1,#CTX_GPR5]
    ldr r6,[r1,#CTX_GPR6]
    ldr r7,[r1,#CTX_GPR7]
    ldr r8,[r1,#CTX_GPR8]
    ldr r9,[r1,#CTX_GPR9]
    ldr r10,[r1,#CTX_GPR10]
    ldr r11,[r1,#CTX_GPR11]

    /*-------------------------------------------------------------------------
     * Load the PSP
     */
    ldr r2,[r1,#CTX_PSP]
    msr psp,r2

#if WITH_FLOAT == YES
    /*-------------------------------------------------------------------------
     * Get a the pointer to the floating point context from the pointer to the
     * static descriptor of the running task
     */
    ldr r1,[r0,#FLOAT_CONTEXT]
    cmp r1, #0 /* r1 is NULL if there is no float context for this process */
    beq no_load_fp
    vldm r1!, {s16-s31} /* load spr[16..31] */
    /* now update LR to use the FPU */
    mov r0, #0xFFED  /* low 16 bits of LR, FPU */
    b end_fp 
no_load_fp:
#endif // WITH_FLOAT
    mov r0, #0xFFFD  /* low 16 bits of LR, NO FPU */
end_fp:
    movt r0, #0xFFFF /* high 16 bits of LR */
    bx   lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"
