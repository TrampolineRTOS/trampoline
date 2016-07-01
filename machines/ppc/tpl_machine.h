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
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
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

#ifndef TPL_MACHINE_PPC_H
#define TPL_MACHINE_PPC_H

#include "tpl_os_custom_types.h"

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
    unsigned long gpr[32];
    unsigned long cr;
    unsigned long xer;
    unsigned long lr;
    unsigned long ctr;
    unsigned long srr0;
    unsigned long srr1;
};

typedef struct PPC_INTEGER_CONTEXT ppc_integer_context;

#ifdef WITH_FLOAT
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
#ifdef WITH_FLOAT
    ppc_float_context   *fc;
#endif
#ifdef WITH_ALTIVEC
    ppc_vector_context  *vc;
#endif
};

typedef struct TPL_CONTEXT tpl_context;

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
extern VAR(ppc_integer_context, OS_VAR) idle_task_context;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

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
 * @def IDLE_CONTEXT
 *
 * The context used to save the idle task
 */
#ifdef WITH_FLOAT
#  define IDLE_CONTEXT { &idle_task_context, NULL }
#else
#  ifdef WITH_ALTIVEC
#    define IDLE_CONTEXT { &idle_task_context, NULL, NULL }
#  else
#    define IDLE_CONTEXT { &idle_task_context }
#  endif
#endif

/**
 * @def SIZE_OF_IDLE_TASK
 *
 * The size of the stack of the idle task which is also the stack
 * used for machine startup
 */
#define IDLE_STACK_SIZE  200

/*
 * external variables
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

extern VAR(ppc_integer_context, OS_VAR) idle_task_context;

extern VAR(uint8, OS_VAR) tpl_keep_prio[15];

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

typedef P2FUNC(void, OS_CODE, INTfunc)(void);
extern INTfunc InterruptVectortable[];

/* TODO : This function is called after an ISR2 has been terminated. It should
 *        restore the hardware's cpu priority if it has been increased before
 *        the execution of the ISR2 (see ppc/multicore/tpl_machine.h for an
 *        example).
 */
#define tpl_restore_cpu_priority()

#endif /* TPL_MACHINE_PPC_H */
