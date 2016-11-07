/**
 * @file tpl_machine.h
 *
 * @section descr File description
 *
 * Trampoline machine dependant header stuff for the PowerPC port.
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

#ifndef TPL_MACHINE_PPC_H
#define TPL_MACHINE_PPC_H

#include "tpl_os_custom_types.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_registers.h"

#define IDLE_STACK_SIZE 200

typedef uint32 tpl_stack_word;
typedef uint32 tpl_stack_size;

/*
 * Integer context of the PowerPC
 * gpr stands for General Purpose Register. They are named r0 to r31 in
 * assembly code
 * cr is the Condition Register.
 * xer is the eXtended Register for carry propagation
 * lr is the Link Register. It helds the return address for function call
 * ctr is the count register. It is used for special branches and for
 * indirect jumps
 */
struct PPC_INTEGER_CONTEXT {
    uint32 gpr[32];
    uint32 cr;
    uint32 xer;
    uint32 lr;
    uint32 ctr;
    uint32 srr0;
    uint32 srr1;
};

typedef struct PPC_INTEGER_CONTEXT ppc_integer_context;

#if WITH_FLOAT == YES
/*
 * Floating Point Context of the PowerPC
 * fpr are Floating Point Register. They are named f0 to f31 in assembly code
 * fpscr is the fp Condition Register
 */
struct PPC_FLOAT_CONTEXT {
    double  fpr[32];
    double  fpscr;
};

typedef struct PPC_FLOAT_CONTEXT ppc_float_context;
#endif


#ifdef WITH_ALTIVEC
/*
 * Vector context
 * vr are Vector Register
 * vrsave
 * vscr is the vector Condition Register
 */
struct PPC_VECTOR_CONTEXT {
    vector unsigned vr[32];
    unsigned long   vrsave;
    unsigned long   vscr;
};

typedef struct PPC_VECTOR_CONTEXT ppc_vector_context;
#endif

struct TPL_CONTEXT {
    ppc_integer_context *ic;
#if WITH_FLOAT == YES
    ppc_float_context   *fc;
#endif
#ifdef WITH_ALTIVEC
    ppc_vector_context  *vc;
#endif
};

typedef struct TPL_CONTEXT tpl_context;



/* tpl_stack is a data structure used to
 * describe the stack(s) used for each task
 * this architecture dependant structure
 * is needed for architecture that use more
 * than one stack (i.e. user stack and system
 * stack for instance).
 * may be stored in ROM
 */

struct TPL_STACK {
    tpl_stack_word      *stack_zone;
    tpl_stack_size      stack_size;
};

typedef struct TPL_STACK tpl_stack;




/**
 * @def TPL_STACK_PATTERN
 *
 * This is the pattern written at the top of each task,
 * usefull for checking stack overflow
 */
#define TPL_STACK_PATTERN 0xAA
#define TPL_FULL_STACK_PATTERN 0xAAAAAAAAU


/*
 * external variables
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
extern VAR(tpl_stack_word, OS_VAR)   tpl_kernel_stack[NUMBER_OF_CORES][KERNEL_STACK_SIZE/sizeof(tpl_stack_word)];
extern P2VAR(tpl_stack_word, OS_VAR, OS_VAR) tpl_kernel_stack_bottom[NUMBER_OF_CORES];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern FUNC(void, OS_CODE) tpl_ack_irq(void);
extern FUNC(void, OS_CODE) tpl_fill_stack_pattern(void);
extern FUNC(void, OS_CODE) Os_Init(void);
extern FUNC(void, OS_CODE) tpl_set_cpu_prio(uint8 prio);
extern FUNC(uint8, OS_CODE) tpl_get_cpu_prio(void);
#if WITH_MULTICORE == YES
extern FUNC(void, OS_CODE) tpl_slave_core_startup(void);
extern FUNC(boolean, OS_CODE) tpl_receive_intercore_it(void);
extern FUNC(uint16, OS_CODE) tpl_get_core_id(void);
#endif
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#define tpl_restore_cpu_priority() tpl_ack_irq()

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"

extern VAR(uint32, OS_VAR) tpl_current_date[NUMBER_OF_CORES];

#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#if WITH_MULTICORE == YES
#define GET_CURRENT_DATE(core_id)   tpl_current_date[core_id]
#define GET_KERNEL_STACK(core_id)   tpl_kernel_stack[core_id]
#define GET_KERNEL_STACK_BOTTOM(core_id)   tpl_kernel_stack_bottom[core_id]
#else
#define GET_CURRENT_DATE(core_id)   tpl_current_date[0]
#define GET_KERNEL_STACK(core_id)   tpl_kernel_stack[0]
#define GET_KERNEL_STACK_BOTTOM(core_id)   tpl_kernel_stack_bottom[0]
#endif

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#if WITH_AUTOSAR_TIMING_PROTECTION == YES
extern CONSTP2FUNC(void, OS_CONST, tpl_wdg_table[NUMBER_OF_CORES * 2])();
# if WITH_MULTICORE == YES
#define TPL_SET_TPWATCHDOG(core_id, ticks) (*tpl_wdg_table[core_id*2])(ticks)
#define TPL_CANCEL_TPWATCHDOG(core_id) (*tpl_wdg_table[core_id*2 + 1])()
# else
#define TPL_SET_TPWATCHDOG(core_id, ticks) (*tpl_wdg_table[0])(ticks)
#define TPL_CANCEL_TPWATCHDOG(core_id) (*tpl_wdg_table[1])()
#endif
#endif

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#endif /* TPL_MACHINE_PPC_H */
