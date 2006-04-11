/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline 32 bits x86 process machine dependant stuff
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_internal_types.h"

#ifndef __TPL_MACHINE_X86_H__
#define __TPL_MACHINE_X86_H__

/*
 * Integer context of the x86
 * *GS, *FS, *ES, SS, *DS, *CS => 16 bits
 * *EDX, *ECX, *EBX, *EAX => 32 bits
 * *EDI, *ESI, *ESP, *EBP, *EIP => 32 bits
 * *EFLAGS
 */
struct X86_INTEGER_CONTEXT {
	unsigned long gs;
	unsigned long fs;
	unsigned long es;
	unsigned long ds;
	unsigned long edi;
	unsigned long esi;
	unsigned long ebp;
	unsigned long esp;
	unsigned long ebx;
	unsigned long edx;
	unsigned long ecx;
	unsigned long eax;
	/*linux inserts here 2 dummy ints.*/
	unsigned long eip;
	unsigned long cs;
	unsigned long eflags;
	/*linux inserts here 1 dummy int.*/
	unsigned long ss;
};

typedef struct X86_INTEGER_CONTEXT x86_integer_context;

/*
 * Floating Point Context of the x86
 * TODO: Not defined yet
 */

struct X86_FLOAT_CONTEXT {
     double          fpr[32];
    /* unsigned long   fpscr; */
};

typedef struct X86_FLOAT_CONTEXT x86_float_context;


struct TPL_CONTEXT {
    x86_integer_context *ic;
    x86_float_context   *fc;
};

typedef struct TPL_CONTEXT tpl_context;

x86_integer_context idle_task_context;

#define IDLE_CONTEXT { &idle_task_context, NULL}


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
