/**
 * @file tpl_machine_arm_generic.h
 *
 * @section descr File description
 *
 * Common definitions for generic ARM platform
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

#ifndef TPL_MACHINE_ARM_GENERIC_H
#define TPL_MACHINE_ARM_GENERIC_H

#include "tpl_os_std_types.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_machine.h"

/**
 * ARM internal registers symbolic names
 */
typedef enum
{
  armreg_r0 = 0,
    armreg_a1 = 0,
  armreg_r1 = 1,
    armreg_a2 = 1,
  armreg_r2 = 2,
    armreg_a3 = 2,
  armreg_r3 = 3,
    armreg_a4 = 3,
  armreg_r4 = 4,
    armreg_v1 = 4,
  armreg_r5 = 5,
    armreg_v2 = 5,
  armreg_r6 = 6,
    armreg_v3 = 6,
  armreg_r7 = 7,
    armreg_v4 = 7,
  armreg_r8 = 8,
    armreg_v5 = 8,
  armreg_r9 = 9,
    armreg_v6 = 9,
    armreg_rfp = 9,
  armreg_r10 = 10,
    armreg_v7 = 10,
    armreg_sl = 10,
  armreg_r11 = 11,
    armreg_v8 = 11,
    armreg_fp = 11,
  armreg_r12 = 12,
    armreg_ip = 12,
  armreg_r13 = 13,
    armreg_sp = 13,
  armreg_r14 = 14,
    armreg_lr = 14,
  armreg_r15 = 15,
    armreg_pc = 15
} tpl_arm_core_register_names;

/**
 * ARM core registers
 */
/*
 * ARM_CORE_EXCEPTION_FRAME_SIZE is 36 bytes long :
 * xpsr
 * pc
 * lr
 * r12
 * r3
 * r2
 * r1
 * r0
 * default value of EXC_RETURN
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

struct ARM_CORE_CONTEXT {
	/* General Purpose Register r4-r11 */
	uint32 gpr[8];
	/* Stack Pointer - r13 */
	uint32 sp;
};

/**
 * ARM generic platform context
 */
typedef struct ARM_CORE_CONTEXT arm_core_context;

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

/**
 * Defines the entry point of the idle task
 */
#define IDLE_ENTRY tpl_sleep

#define DISABLE_FIQ() __asm__ __volatile__ ("mrs r0, cpsr ;" \
                                            "orr r0, r0, #0b01000000 ;" \
                                            "msr cpsr_c, r0" \
                                            : \
                                            : \
                                            : "r0")

#define ENABLE_FIQ()  __asm__ __volatile__ ("mrs r0, cpsr ;" \
                                            "bic r0, r0, #0b01000000 ;" \
                                            "msr cpsr_c, r0" \
                                            : \
                                            : \
                                            : "r0")

#define DISABLE_IRQ() __asm__ __volatile__ ("cpsid i;")

#define ENABLE_IRQ()  __asm__ __volatile__ ("cpsie i;")

#endif /* TPL_MACHINE_ARM_GENERIC_H */

/* End of file tpl_machine_arm_generic.h */
