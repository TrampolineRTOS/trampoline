/**
 * @file tpl_ctx_switch.S
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
 * +-------------------------------+                                          *
 * If the FPU is enabled, the FPU context is not saved by hardware,           *
 * as the kernel do not use FPU instructions. The FPU registers should        *
 * be saved/restored in the load/save context functions                       *
 * (ArmV7 - Architecture Reference manual (DDI 0403E.e), sec. B.3.2.21)       *
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
 *                                                                            *
 * if the FPU is enabled for the task (USEFLOAT = TRUE; in .oil), the FP      *
 * context (pointer from static task descriptor) contains all the FP          *
 * registers (32 SPR+FPSCR), see arm_float_context
 *----------------------------------------------------------------------------*
 */

#include "tpl_regs_offsets.h"

/*=============================================================================
 * tpl_save_context is used to save the context of the running task.
 * It is used from the system call handler.
 *
 * r0 contains a pointer to the static descriptor of the running task.
 * r1-r3 are working registers
 * values to be saved in r4 and r5 are not in these registers but have been
 * saved on the MSP.
 */

.global tpl_save_context
.type   tpl_save_context, %function

tpl_save_context:
    /*-------------------------------------------------------------------------
     * Get a the pointer to the integer context from the pointer to the
     * static descriptor of the running task
     */
    ldr r1,[r0,#INT_CONTEXT]

    /*-------------------------------------------------------------------------
     * Retrieve r4 and r5 from the stack, they have been saved in the
     * tpl_sc_handler.
     */
    ldr r2,[sp,#KS_R4]
    str r2,[r1,#CTX_GPR4]

    /*-------------------------------------------------------------------------
     * Retrieve r5 and save it
     */
    ldr r2,[sp,#KS_R5]
    str r2,[r1,#CTX_GPR5]

    /*-------------------------------------------------------------------------
     * Save r6-r11
     */
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
    /* save all s0 to s31 */
    vstm r1!, {s0-s31}
    /* save fpscr */
    vmrs r0,fpscr
    str r0,[r1]
no_save_fp:
#endif
    bx  lr

/*=============================================================================
 * tpl_load_context is used to load the context of (not yet) the running task.
 * It is used from the system call handler and from interrupt handlers.
 *
 * r0 contains a pointer to the static descriptor of the running task.
 * r1-r3 are working registers
 * values to be loaded into r4 and r5 are put in the MSP.
 */

.global tpl_load_context
.type   tpl_load_context, %function

tpl_load_context:
    /*-------------------------------------------------------------------------
     * Get a the pointer to the integer context from the pointer to the
     * static descriptor of the running task
     */
    ldr r1,[r0,#INT_CONTEXT]

    /*-------------------------------------------------------------------------
     * Put r4 into the stack. It will be put back in r4 by the tpl_sc_handler
     * tpl_sc_handler.
     */
    ldr r2,[r1,#CTX_GPR4]
    str r2,[sp,#KS_R4]

    /*-------------------------------------------------------------------------
     * Put r5 into the stack. It will be put back in r5 by the tpl_sc_handler
     * tpl_sc_handler.
     */
    ldr r2,[r1,#CTX_GPR5]
    str r2,[sp,#KS_R5]

    /*-------------------------------------------------------------------------
     * load r6-r11
     */
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
    vldm r1!, {s0-s31} /* load s[0..31] */
    ldr r0,[r1]
    vmsr fpscr, r0 /* load fpscr */
no_load_fp:
#endif // WITH_FLOAT
    bx   lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"
