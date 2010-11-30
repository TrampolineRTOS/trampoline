/**
 * @file apf27_call_trusted_fct.S
 *
 * @section descr File description
 *
 * Management of trusted functions
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
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */

#include "tpl_os_application_def.h"
#include "../tpl_asm_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

#if WITH_MEMORY_PROTECTION == YES
.global tpl_call_trusted_function_service
tpl_call_trusted_function_service:
#if TRUSTED_FCT_COUNT > 0
  /* immediatly return E_OS_SERVICEID if trusted function's id is invalid */
  cmp r0, #TRUSTED_FCT_COUNT
  movhs r0, #E_OS_SERVICEID
  movhs pc, lr

  stmfd sp!, {r4}

  /* get the task's return address, so we can push it into process' stack
   * (see kernel enter stack frame documented in tpl_system_call.S) */
  ldr r4, [sp, #(16 + 4)]

  /* switch to user mode to access to current process' registers */
  mrs r3, cpsr
  bic r3, r3, #0x1F
  orr r3, r3, #CPSR_SYS_MODE
  msr cpsr, r3

  /* pushes process' lr and process' return address (in r4) on process' stack */
  stmfd sp!, {r4, lr}
  /* copies ExitTrustedFunction to lr to force this system call on return from trusted function */
  ldr lr, =ExitTrustedFunction

  /* get back to system call mode */
  mrs r3, cpsr
  bic r3, r3, #0x1F
  orr r3, r3, #CPSR_SVC_MODE
  msr cpsr, r3
  
  /* prepare to run trusted function in privileged mode: we change
   * SPSR (via kernel enter stack frame) as there will be no context switch */
  ldr r3, [sp, #4]
  bic r3, r3, #0x1F
  orr r3, r3, #CPSR_SYS_MODE
  str r3, [sp, #4]

  /* forces kernel enter stack frame to simulate trusted function call */
  ldr r3, =tpl_trusted_fct_table
  ldr r3, [r3, r0, LSL #2] /* get function pointer from trusted functions table */
  str r3, [sp, #(16 + 4)]

  /* increment task's trusted counter */
  ldr r3, =tpl_kern
  ldr r3, [r3, #TPL_KERN_OFFSET_RUNNING]
  ldr r2, [r3, #TPL_PROC_TRUSTED_COUNT] /* according to tpl_os_internal_types.h, trusted_count is an "unsigned int" */
  add r2, r2, #1
  str r2, [r3, #TPL_PROC_TRUSTED_COUNT]

  /* get back to system call handler 
   *
   * note that r0 and r1 are left unmodified as they have the two parameters values
   * and they will be restored to the task as if they would contain the returned value
   */
  ldmfd sp!, {r4}
  mov pc, lr
#else /* if TRUSTED_FCT_COUNT == 0 */
  mov r0, #E_OS_SERVICEID
  mov pc, lr
#endif /* TRUSTED_FCT_COUNT == 0*/
#endif /* WITH_MEMORY_PROTECTION == YES */

.global tpl_exit_trusted_function_service
tpl_exit_trusted_function_service:
#if WITH_MEMORY_PROTECTION == YES
#if TRUSTED_FCT_COUNT > 0
  /* decrement task's trusted counter (only if >0, otherwise this is probably an attack) */
  ldr r3, =tpl_kern
  ldr r3, [r3, #TPL_KERN_OFFSET_RUNNING]
  ldr r2, [r3, #TPL_PROC_TRUSTED_COUNT] /* according to tpl_os_internal_types.h, trusted_count is an "unsigned int" */
  cmp r2, #0
  beq cracker_in_action
  sub r2, r2, #1
  str r2, [r3, #TPL_PROC_TRUSTED_COUNT]

  /* give back the original process's rights.
   *
   * many things already done by tpl_mp_kernel_exit but,
   * as there will be no context switch, we force SPSR (via
   * kernel enter stack frame)
   */
  cmp r2, #1
  ldr r3, [sp]
  bic r3, r3, #0x1F
  orrhs r3, r3, #CPSR_SYS_MODE
  orrlo r3, r3, #CPSR_USR_MODE
  str r3, [sp]

  /* switch to user mode to access to current process' registers */
  mrs r3, cpsr
  bic r3, r3, #0x1F
  orr r3, r3, #CPSR_SYS_MODE
  msr cpsr, r3

  /* as ExitTrustedFunction is not really a system call, we remove the LR
   * pushed by the system call wrapper (see in tpl_invoque.s), then we can
   * see directly what have been pushed by tpl_call_trusted_function_service */
  add sp, sp, #4
  /* pops process' lr and process' return address (in r3) on process' stack */
  ldmfd sp!, {r2, lr}

  /* get back to system call mode */
  mrs r3, cpsr
  bic r3, r3, #0x1F
  orr r3, r3, #CPSR_SVC_MODE
  msr cpsr, r3

  /* restores the task's return address, on the kernel enter stack frame
   * (see kernel enter stack frame documented in tpl_system_call.S) */
  str r2, [sp, #16]

  /* returns with no error */
  mov r0, #E_OK
  mov pc, lr

cracker_in_action:
  /* we do nothing (but returning an error) ! */
  mov r0, #E_OS_PROTECTION_EXCEPTION
  mov pc, lr

#else /* if TRUSTED_FCT_COUNT == 0 */
  mov r0, #E_OS_SERVICEID
  mov pc, lr
#endif /* TRUSTED_FCT_COUNT == 0 */
#else /* WITH_MEMORY_PROTECTION != YES */
  mov r0, #E_OS_SERVICEID
  mov pc, lr
#endif /* WITH_MEMORY_PROTECTION != YES */

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

