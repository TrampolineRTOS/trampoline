/*
 * @file tpl_ctx_switch.s
 *
 * @section desc File description
 *
 * Trampoline context switch
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
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

#include "tpl_os_kernel_stack.h"
#include "tpl_app_define.h"

  .global tpl_save_context
  .global tpl_load_context
  .global tpl_pre_save_context
  .global tpl_post_load_context

#define INT_CONTEXT 0
#define FP_CONTEXT  4

	/*
	 * Mapping in the context structures
	 */
#define CTX_GPR0		0
#define CTX_GPR1		4
#define CTX_GPR2		8
#define CTX_GPR3		12
#define CTX_GPR4		16
#define CTX_GPR5		20
#define CTX_GPR6		24
#define CTX_GPR7		28
#define CTX_GPR8		32
#define CTX_GPR9		36
#define CTX_GPR10		40
#define CTX_GPR11		44
#define CTX_GPR12		48
#define CTX_GPR13		52
#define CTX_GPR14		56
#define CTX_GPR15		60
#define CTX_PROCESS_SP	64

	/*
 	 * tpl_save_context saves the context in the context passed in r3
	 * this function is called from tpl_sc_handler and we are running
	 * on the kernel stack so the actual value of some registers to save
	 * are saved on the kernel stack.
	 *
	 * @param   r6 contains the pointer to the context pointers
	 */
tpl_save_context:
	ldr r6, [r6, #INT_CONTEXT]
	/* <!DGAR> Don t forget to save caller SP from kernel stack (saved at the beginning of exception call) to context */
	/*
	 * setup the kernel stack stuff
	 */
	/* PSP */
	ldr r4, [r5, #KS_PROCESS_SP]	/* Load process SP into r4 */
	str r4, [r6, #CTX_PROCESS_SP]	/* and save it into context */
	/* R4 */
	ldr r4, [r5, #KS_R4]			/* Load R4 into r4 */
	str r4, [r6, #CTX_GPR4]			/* and save it into context */
	/* R5 */
	ldr r4, [r5, #KS_R5]			/* Load R5 into r4 */
	str r4, [r6, #CTX_GPR5]			/* and save it into context */
	/* R6 */
	mov r4, r12						/* get back r6 from r12 ARMV6 restriction*/
	str r4, [r6, #CTX_GPR6]
	/* R7 */
	str r7, [r6, #CTX_GPR7]
	/* R8 */						/*** start high register bank ***/
	mov r4,r8
	str r4, [r6, #CTX_GPR8]
	/* R9 */
	mov r4,r9
	str r4, [r6, #CTX_GPR9]
	/* R10 */
	mov r4,r10
	str r4, [r6, #CTX_GPR10]
	/* R11 */
	mov r4,r11
	str r4, [r6, #CTX_GPR11]
	/* Save return value of service into process frame */
    bx lr

	/*
	 * tpl_load_context loads a context from a tpl_context
	 * to the registers and to the kernel stack
	 * This function is run on the kernel stack
	 *
	 * @param   r6 contains the pointer to the context pointers
	 */
tpl_load_context:
	ldr r6, [r6, #INT_CONTEXT] /* Get the pointer to the integer context */
	/*
	 * setup the kernel stack stuff
	 */
	/* PSP */
	ldr r4, [r6, #CTX_PROCESS_SP]	/* load process sp */
	str r4, [r5, #KS_PROCESS_SP]	/* and put it into kernel stack */
	/* R4 */
	ldr r4, [r6, #CTX_GPR4]			/* and save it into context */
	str r4, [r5, #KS_R4]			/* Load R4 into r4 */
	/* R5 */
	ldr r4, [r6, #CTX_GPR5]			/* and save it into context */
	str r4, [r5, #KS_R5]			/* Load R5 into r4 */
	/* R6 */
	ldr r4, [r6, #CTX_GPR6]
	mov r12, r4						/* r12 used to save r6 (ARMv6) */
	/* R7 */
	ldr r7, [r6, #CTX_GPR7]
	/* R8 */						/*** start high register bank ***/
	mov r4,r8
	ldr r4, [r6, #CTX_GPR8]
	/* R9 */
	mov r4,r9
	ldr r4, [r6, #CTX_GPR9]
	/* R10 */
	mov r4,r10
	ldr r4, [r6, #CTX_GPR10]
	/* R11 */
	mov r4,r11
	ldr r4, [r6, #CTX_GPR11]
	bx lr
