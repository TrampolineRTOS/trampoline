/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline ARM7 specifics
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL: http://localhost:8888/Trampoline/svn/tpl_machine/ARM7/tpl_machine_ARM7.h $
 */

#include "../../tpl_os_internal_types.h"

#ifndef __TPL_MACHINE_ARM7_H__
#define __TPL_MACHINE_ARM7_H__

/* in comment for each register: address in memory / sfr number */
struct ARM7_CONTEXT {
	unsigned int R[16];   /* FF0E / 87 */

};

typedef struct ARM7_CONTEXT arm7_context;


struct TPL_CONTEXT {
	arm7_context * ic;
};

typedef struct TPL_CONTEXT tpl_context;


extern arm7_context idle_task_context;
#define IDLE_CONTEXT &idle_task_context 



struct TPL_STACK {
    tpl_stack_word 	*stack_zone;
    tpl_stack_size       stack_size;
};
typedef struct TPL_STACK tpl_stack;

/*#define IDLE_TASK_SYS_STACK_LENGTH 10
extern tpl_stack_word idata idle_task_sys_stack[IDLE_TASK_SYS_STACK_LENGTH];
#define IDLE_STACK {&idle_task_sys_stack,0,NULL,0}*/
#define IDLE_STACK {NULL,0}

#endif
