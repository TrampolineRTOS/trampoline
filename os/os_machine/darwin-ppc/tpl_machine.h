/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline 32 bits Mac OS X process machine dependant stuff
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_internal_types.h"

#ifndef __TPL_MACHINE_DARWIN_PPC_H__
#define __TPL_MACHINE_DARWIN_PPC_H__

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
};

typedef struct PPC_INTEGER_CONTEXT ppc_integer_context;

/*
 * Floating Point Context of the PowerPC
 * fpr are Floating Point Register. They are named f0 to f31 in assembly code
 * fpscr is the fp Condition Register
 */
struct PPC_FLOAT_CONTEXT {
    double          fpr[32];
    unsigned long   fpscr;
};

typedef struct PPC_FLOAT_CONTEXT ppc_float_context;


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
    ppc_float_context   *fc;
#ifdef WITH_ALTIVEC
    ppc_vector_context  *vc;
#endif
};

typedef struct TPL_CONTEXT tpl_context;

ppc_integer_context idle_task_context;

#ifdef WITH_ALTIVEC
#define IDLE_CONTEXT { &idle_task_context, NULL, NULL }
#else
#define IDLE_CONTEXT { &idle_task_context, NULL }
#endif

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

#define IDLE_STACK {NULL,0}

#endif