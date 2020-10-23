/**
 * @file tpl_system_call.S
 *
 * @section descr File description
 *
 * System calls handling.
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
#include "tpl_service_ids.h"

.equ  NO_NEED_SWITCH_NOR_SCHEDULE, 0
.equ  NO_NEED_SWITCH, 0
.equ  NEED_SWITCH, 1
.equ  NEED_SAVE, 2

/*-----------------------------------------------------------------------------
 * the tpl_sc_handler uses tpl_kern
 */

#define OS_START_SEC_VAR
#include "tpl_as_memmap.h"

.extern tpl_kern

#define OS_STOP_SEC_VAR
#include "tpl_as_memmap.h"

/*-----------------------------------------------------------------------------
 * the tpl_sc_handler uses the dispatch table
 */

#define OS_START_SEC_CONST
#include "tpl_as_memmap.h"

.extern tpl_dispatch_table

#define OS_STOP_SEC_CONST
#include "tpl_as_memmap.h"

/*-----------------------------------------------------------------------------
 * the code starts here
 */

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/*=============================================================================
 * The system call handler is executed when the application (Task or ISR2)
 * executes a SVC by calling a service. The microcontroler is configured
 * in non priviledged thread / priviledged handler with a thread (process)
 * stack (pointed by PSP) and a handler (kernel) stack (pointed by MSP).
 * Switching from process stack to kernel stack is done automatically when
 * a SVC is executed and switching from the kernel stack to the process stack
 * is done automatically when returning from the SVC handler (tpl_sc_handler).
 *
 * It assumes the following:
 *
 * 1 - The process stack is populated according to the Cortex M standard
 *
 * +------------------+
 * | R0               | <- PSP
 * +------------------+
 * | R1               | <- PSP+4
 * +------------------+
 * | R2               | <- PSP+8
 * +------------------+
 * | R3               | <- PSP+12
 * +------------------+
 * | R12              | <- PSP+16
 * +------------------+
 * | LR               | <- PSP+20
 * +------------------+
 * | Return Address   | <- PSP+24
 * +------------------+
 * | xPSR (bit 9 = 1) | <- PSP+28
 * +------------------+
 *
 * 2 - The system call wrapper uses r3 to pass the identifier of the service.
 *     This identifier is used as an index in a function pointer table, each of
 *     these function pointer being a service of Trampoline. Services callable
 *     by ISR1 are the 6 first (so correspond to identifiers 0-5)
 *
 * 3 - registers r0, r1 and r2 contains, according to the ABI, the arguments
 *     of the service (in Trampoline, a service is limited to 3 arguments).
 *     As a result registers r0, r1 and r2 should not be changed by the SVC
 *     handler but may be changed after the call of the service (step 8).
 */

.global tpl_sc_handler
.type   tpl_sc_handler, %function

tpl_sc_handler:

    /*-----------------------------------------------------------------------*
     * Once here the stack has been changed to the master stack.             *
     * So SP is MSP, not PSP                                                 *
     *-----------------------------------------------------------------------*/

    /*-------------------------------------------------------------------------
     * 0 - registers R0-R3 have to be restored from the stack. First the PSP
     *     (process stack pointer) is copied in R0. Second registers R0-R3 are 
     * loaded from the process stack
     */
    mrs   r0,psp
    ldmia r0,{r0, r1, r2, r3}

    /*-------------------------------------------------------------------------
     * 1 - The service identifier is checked to prevent crashes if it has
     *     a wrong value
     */
    cmp   r3,#SYSCALL_COUNT
    bhs   tpl_sc_handler_invalid_service_id

    /*-------------------------------------------------------------------------
     * 1a - The service identifier is checked again for xxxInterrupt services
     *      that are callable by ISR1. If the service is callable by ISR1,
     *      interrupts are disabled before calling the service so that it
     *      can't be interrupted by an ISR1.
     */
    cmp   r3,#SYSCALL_COUNT_ISR1
    bhs   not_callable_by_isr1
    cpsid i   /* set PRIMASK */

not_callable_by_isr1:

    /*-------------------------------------------------------------------------
     * 2 - Build the kernel stack frame, see file tpl_os_kernel_stack.h
     */
    sub   sp,sp,#KS_FOOTPRINT

    /*-------------------------------------------------------------------------
     * 3 - Save working registers in the master stack frame.
     *     We need a couple of low register to work and to be compatible
     *     with armv6m. We choose r4 and r5
     */
    str   r4,[sp,#KS_R4]
    str   r5,[sp,#KS_R5]

    /*-------------------------------------------------------------------------
     * 4 - Save the link register, in armv6m, the source register of a store
     *     must be r0-r7, so we use r4 (already saved) to copy lr
     */
    mov   r4,lr
    str   r4,[sp,#KS_LR]

    /*-------------------------------------------------------------------------
     * 6 - Reset the tpl_kern variables
     */
    ldr   r4,=tpl_kern
    movs  r5,#NO_NEED_SWITCH_NOR_SCHEDULE
    strb  r5,[r4,#TPL_KERN_OFFSET_NEED_SWITCH]
    strb  r5,[r4,#TPL_KERN_OFFSET_NEED_SCHEDULE]

    /*-------------------------------------------------------------------------
     * 7 - Get the function pointer to the service
     */
    ldr   r4,=tpl_dispatch_table
    lsls  r3,r3,#2
    ldr   r3,[r4,r3]

    /*-------------------------------------------------------------------------
     * 8 - Service call
     */
    blx   r3

    /*-----------------------------------------------------------------------*
     * From here, r1, r2 and r3 are available as working register            *
     * r0 hold the result of the service and should not be changed           *
     *-----------------------------------------------------------------------*/

    /*-------------------------------------------------------------------------
     * 9 - Copy back the result to the saved r0 on the process stack
     *     r0 is at the top of the process stack
     */
    mrs   r4,psp
    str   r0,[r4]

    /*-------------------------------------------------------------------------
     * 10 - Check the context switch condition in tpl_kern
     */
    ldr   r4,=tpl_kern
    ldrb  r5,[r4,#TPL_KERN_OFFSET_NEED_SWITCH]
    cmp   r5,#NO_NEED_SWITCH
    beq   tpl_sc_handler_no_context_switch

    /*-------------------------------------------------------------------------
     * 11 - Prepare the call to tpl_run_elected by setting r0 to 0, aka no save
     */
    movs  r0,#0

    /*-------------------------------------------------------------------------
     * 12 - Check the save condition
     */
    movs  r4,#NEED_SAVE
    tst   r5,r4
    beq   tpl_sc_handler_no_save_running_context /* bit of NEED_SAVE set to 0 */

    /*-------------------------------------------------------------------------
     * 13 - Save context
     *      Load in r0 the pointer to the static descriptor of the running task
     */
    ldr   r0,=tpl_kern
    ldr   r0,[r0,#TPL_KERN_OFFSET_S_RUNNING]
    bl    tpl_save_context

    /*-------------------------------------------------------------------------
     * 14 - Prepare the call to tpl_run_elected by setting r0 to 1
     */
    movs  r0,#1

tpl_sc_handler_no_save_running_context:

    /*-------------------------------------------------------------------------
     * 15 - Call tpl_run_elected.
     *      The argument is a boolean which is true if the task is
     *      preempted. see stages 11 and 14 above.
     */
    bl    tpl_run_elected

    /*-------------------------------------------------------------------------
     * 16 - Load context
     *      Load in r0 the pointer to the context of the running task.
     *      It has been changed by tpl_run_elected
     */
    ldr   r0,=tpl_kern
    ldr   r0,[r0,#TPL_KERN_OFFSET_S_RUNNING]
    bl    tpl_load_context

tpl_sc_handler_no_context_switch:

    /*-------------------------------------------------------------------------
     * 18 - Restore the link register from the kernel stack.
     *      Symetric of stages 4
     */
    ldr   r4,[sp,#KS_LR]
    mov   lr,r4

    /*-------------------------------------------------------------------------
     * 19 - Restore r4 and r5 from the kernel stack.
     *      Symetric of stage 3
     */
    ldr   r5,[sp,#KS_R5]
    ldr   r4,[sp,#KS_R4]

    /*-------------------------------------------------------------------------
     * 20 - Deallocate frame on the MSP
     */
    add   sp,sp,#KS_FOOTPRINT

    /*-------------------------------------------------------------------------
     * 20b - Enable interrupts. This can be done without checking it has been
     *       disabled in 1a because application level interrupt masking is
     *       done using the BASEPRI register.
     */
    cpsie i   /* clear PRIMASK */

tpl_sc_handler_invalid_service_id:

    /*-------------------------------------------------------------------------
     * 21 - Return from the SVC
     */
    bx    lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

/* End of file tpl_sc_handler.S */
