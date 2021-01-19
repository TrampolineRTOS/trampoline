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

.extern running
.extern func1TD
.extern func2TD

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
  /*-------------------------------------------------------------------------
   * Return from the SVC
   */
exit_tpl_sc_handler:
  bx lr

.global SwitchContext
.type   SwitchContext, %function

SwitchContext:
  svc #0
  bx lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

/* End of file tpl_sc_handler.S */
