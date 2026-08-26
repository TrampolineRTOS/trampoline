/**
 * @file tpl_rp2040_ici_handler.S
 *
 * @section descr File description
 *
 * Intercore interruption for rp2040
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
#include "tpl_service_ids.h"
#include "tpl_app_define.h"

#if NUMBER_OF_CORES > 1

.equ  NO_NEED_SWITCH_NOR_SCHEDULE, 0
.equ  NO_NEED_SWITCH, 0
.equ  NEED_SWITCH, 1
.equ  NEED_SAVE, 2

/*-----------------------------------------------------------------------------
 * the tpl_rp2040_ici_handler uses tpl_kern
 */

#define OS_START_SEC_VAR
#include "tpl_as_memmap.h"

.extern tpl_kern

#define OS_STOP_SEC_VAR
#include "tpl_as_memmap.h"


/*-----------------------------------------------------------------------------
 * the code starts here
 */

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/*=============================================================================
 * IRQ Handlers for intercore_IT (FIFO SIO_IRQ_PROC0)
 ******************************************************************************/
.global SIO_IRQ_PROC0_Handler 
.type   SIO_IRQ_PROC0_Handler, %function

/*---------------------------------------------------------------------------*/
SIO_IRQ_PROC0_Handler :
    /*-------------------------------------------------------------------------
    * 1 - Save the LR and r4 on the stack so we can acces tpl_kern[core_id] faster
    */
    push {r4,lr}

    /* 2 - FIFO acknowledge for the core0 
     */
     
    bl   tpl_ici_ack

    /* 3a - mask other interruption to prevent spinlock and 
     *Lock the kernel before accesing tpl_kern struct 
     */
    cpsid i 
    bl tpl_get_task_lock 

    /* 3 - Check the context switch condition */
    ldr  r4,=tpl_kern
    ldr r4,[r4]
    ldrb r1,[r4,#TPL_KERN_OFFSET_NEED_SWITCH]
    cmp  r1,#NO_NEED_SWITCH
    beq  ICI_handler_0_end_switch

    /* 4 - Reset the tpl_kern variables */
    movs r1,#NO_NEED_SWITCH_NOR_SCHEDULE
    strb r1,[r4,#TPL_KERN_OFFSET_NEED_SWITCH]
    strb r1,[r4,#TPL_KERN_OFFSET_NEED_SCHEDULE]

    /* 5 - Save context */
    ldr  r0,[r4,#TPL_KERN_OFFSET_S_RUNNING]
    bl   tpl_save_context_under_it

    /* 6 - Call tpl_run_elected */
    movs r0,#1
    bl   tpl_run_elected


    /* 7 - Load context */
    movs r5,#NO_NEED_SWITCH_NOR_SCHEDULE
    strb r5,[r4,#TPL_KERN_OFFSET_NEED_SWITCH]
    strb r5,[r4,#TPL_KERN_OFFSET_NEED_SCHEDULE]
    ldr  r0,[r4,#TPL_KERN_OFFSET_S_RUNNING]
    bl   tpl_load_context_under_it

ICI_handler_0_end_switch :

    /* 8 - Release the spinlock and unmask the other interruption
    *     pop LR and R4 that was saved at stage 1 into PC and return from the handler
    */

    bl tpl_release_task_lock 
    cpsie i
    pop  {r4,pc}
/*---------------------------------------------------------------------------*/

/*=============================================================================
 * IRQ Handlers for intercore_IT (FIFO SIO_IRQ_PROC1)
 ******************************************************************************/
.global SIO_IRQ_PROC1_Handler 
.type   SIO_IRQ_PROC1_Handler , %function

/*---------------------------------------------------------------------------*/
SIO_IRQ_PROC1_Handler :
    /*-------------------------------------------------------------------------
    * 1 - Save the LR and r4 on the stack so we can acces tpl_kern[core_id] faster
    */
    push {r4,lr}

    /* 2 - FIFO acknowledge for the core0 
     */
     
    bl   tpl_ici_ack

    /* 3a - mask other interruption to prevent spinlock and 
     *Lock the kernel before accesing tpl_kern struct 
     */
    cpsid i
    bl tpl_get_task_lock 


    /* 3 - Check the context switch condition */
    ldr  r4,=tpl_kern
    ldr r4,[r4, #4]
    ldrb r1,[r4,#TPL_KERN_OFFSET_NEED_SWITCH]
    cmp  r1,#NO_NEED_SWITCH
    beq  ICI_handler_1_end_switch

    /* 4 - Reset the tpl_kern variables */
    movs r1,#NO_NEED_SWITCH_NOR_SCHEDULE
    strb r1,[r4,#TPL_KERN_OFFSET_NEED_SWITCH]
    strb r1,[r4,#TPL_KERN_OFFSET_NEED_SCHEDULE]

    /* 5 - Save context */
    ldr  r0,[r4,#TPL_KERN_OFFSET_S_RUNNING]
    bl   tpl_save_context_under_it

    /* 6 - Call tpl_run_elected */
    movs r0,#1
    bl   tpl_run_elected


    /* 7 - Load context */
    movs r5,#NO_NEED_SWITCH_NOR_SCHEDULE
    strb r5,[r4,#TPL_KERN_OFFSET_NEED_SWITCH]
    strb r5,[r4,#TPL_KERN_OFFSET_NEED_SCHEDULE]
    ldr  r0,[r4,#TPL_KERN_OFFSET_S_RUNNING]
    bl   tpl_load_context_under_it

ICI_handler_1_end_switch :

    /* 8 - Release the spinlock and unmask the other interruption
    *     pop LR and R4 that was saved at stage 1 into PC and return from the handler
    */

    bl tpl_release_task_lock 
    cpsie i
    pop  {r4,pc}
/*---------------------------------------------------------------------------*/

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#else

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

.extern tpl_null_it

.global SIO_IRQ_PROC0_Handler 
.type   SIO_IRQ_PROC0_Handler, %function
SIO_IRQ_PROC0_Handler:
    ldr r0, =tpl_null_it
    bx r0

.global SIO_IRQ_PROC1_Handler 
.type   SIO_IRQ_PROC1_Handler, %function
SIO_IRQ_PROC1_Handler:
    ldr r0, =tpl_null_it
    bx r0
#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#endif

.end

/* End of file tpl_rp2040_ici_handler */