/**
 * @file tpl_machine_cortex.h
 *
 * @section descr File description
 *
 * Common definitions for cortex platform
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

#ifndef TPL_MACHINE_CORTEX_H
#define TPL_MACHINE_CORTEX_H

#include "tpl_os_std_types.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_machine.h"
#include "tpl_os_kernel_stack.h"

/**
 * Definition of kernel access defines.
 * Specific to the target.
 */

#define TPL_KERN_OFFSET_S_RUNNING     (0)
#define TPL_KERN_OFFSET_S_ELECTED     (4)
#define TPL_KERN_OFFSET_RUNNING       (8)
#define TPL_KERN_OFFSET_ELECTED       (12)
#define TPL_KERN_OFFSET_RUNNING_ID    (16)
#define TPL_KERN_OFFSET_ELECTED_ID    (20)
#define TPL_KERN_OFFSET_NEED_SWITCH   (24)
#define TPL_KERN_OFFSET_NEED_SCHEDULE (25)

/**
 * ARM core registers
 */
/*
 * ARM_CORE_EXCEPTION_FRAME_SIZE is 32 bytes long :
 * +-------------------------------+
 * | R0                            | <- PSP
 * +-------------------------------+
 * | R1                            | <- PSP+4
 * +-------------------------------+
 * | R2                            | <- PSP+8
 * +-------------------------------+
 * | R3                            | <- PSP+12
 * +-------------------------------+
 * | R12                           | <- PSP+16
 * +-------------------------------+
 * | LR (aka R14)                  | <- PSP+20
 * +-------------------------------+
 * | Return Address (saved PC/R15) | <- PSP+24
 * +-------------------------------+
 * | xPSR (bit 9 = 1)              | <- PSP+28
 * +-------------------------------+
 */
#define ARM_CORE_EXCEPTION_FRAME_SIZE ((uint32)32)
/* ARM_INITIAL_EXC_RETURN
 * Default value of exception return value
 * 0xFFFFFFF1 - Return to Handler mode, exception return uses non-floating-point state from the MSP and execution uses MSP after return.
 * 0xFFFFFFF9 - Return to Thread mode, exception return uses non-floating-point state from MSP and execution uses MSP after return.
 * 0xFFFFFFFD - Return to Thread mode, exception return uses non-floating-point state from the PSP and execution uses PSP after return.
 * 0xFFFFFFE1 - Return to Handler mode, exception return uses floating-point-state from MSP and execution uses MSP after return.
 * 0xFFFFFFE9 - Return to Thread mode, exception return uses floating-point state from MSP and execution uses MSP after return.
 * 0xFFFFFFED - Return to Thread mode, exception return uses floating-point state from PSP and execution uses PSP after return.
 */
#define ARM_INITIAL_EXC_RETURN ((uint32)0xFFFFFFF9)

/*----------------------------------------------------------------------------*
 * The second part of the context is stored in the following structure        *
 * An instance of this structure is pointed by a pointer in the statuc task   *
 * descriptor                                                                 *
 *                                                                            *
 * +------------------+                                                       *
 * | R4               | <- CTX_GPR4                                           *
 * +------------------+                                                       *
 * | R5               | <- CTX_GPR5                                           *
 * +------------------+                                                       *
 * | R6               | <- CTX_GPR6                                           *
 * +------------------+                                                       *
 * | R7               | <- CTX_GPR7                                           *
 * +------------------+                                                       *
 * | R8               | <- CTX_GPR8                                           *
 * +------------------+                                                       *
 * | R9               | <- CTX_GPR9                                           *
 * +------------------+                                                       *
 * | R10              | <- CTX_GPR10                                          *
 * +------------------+                                                       *
 * | R11              | <- CTX_GPR11                                          *
 * +------------------+                                                       *
 * | PSP (R13)        | <- CTX_PSP                                            *
 * +------------------+                                                       *
 *----------------------------------------------------------------------------*/

typedef struct ARM_CORE_CONTEXT
{
  uint32 gpr4;          /* General purpose register r4 */
  uint32 gpr5;          /* General purpose register r5 */
  uint32 gpr6;          /* General purpose register r6 */
  uint32 gpr7;          /* General purpose register r7 */
  uint32 gpr8;          /* General purpose register r8 */
  uint32 gpr9;          /* General purpose register r9 */
  uint32 gpr10;         /* General purpose register r10 */
  uint32 gpr11;         /* General purpose register r11 */
	uint32 stackPointer;  /* Stack Pointer - r13          */
} arm_core_context;

#ifdef WITH_FLOAT
/*
 * Floating Point Context
 */
struct ARM_FLOAT_CONTEXT {
	/* is Single Precision Register s0-s31 */
    double  spr[32];
	/* Floating Point Status and Control Register */
    double  fpscr;
};

typedef struct ARM_FLOAT_CONTEXT arm_float_context;
#endif

/**
 * default size of an element in a stack
 */
typedef uint32 tpl_stack_word;

/**
 * type of a stack size
 */
typedef uint32 tpl_stack_size;

/**
 * Stack definition
 */
struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size  stack_size;
};

/**
 * Stack definition
 */
typedef struct TPL_STACK tpl_stack;

#define OS_STACK_PATTERN ((uint32)0xDEADBEEF)

/**
 * Defines the entry point of the idle task
 */
#define IDLE_ENTRY tpl_sleep

#define DISABLE_FIQ() __asm__ __volatile__ ("cpsid f;")

#define ENABLE_FIQ()  __asm__ __volatile__ ("cpsie f;")

#define DISABLE_IRQ() __asm__ __volatile__ ("cpsid i;")

#define ENABLE_IRQ()  __asm__ __volatile__ ("cpsie i;")

FUNC (void, OS_CODE) tpl_init_machine_specific (void);

#endif /* TPL_MACHINE_CORTEX_H */

/* End of file tpl_machine_cortex.h */
