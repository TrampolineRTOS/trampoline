/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline avr specifics
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL: http://localhost:8888/Trampoline/svn/tpl_machine/c166/tpl_machine_avr.h $
 */

#ifndef __TPL_MACHINE_AVR_H__
#define __TPL_MACHINE_AVR_H__

struct AVR_CONTEXT {
	unsigned int pc;   /* program counter */
	unsigned int sp;   /* stack pointer */
	unsigned int sreg; /* status register */
	unsigned int register[32]; /* table of register 0 to 31 (general prupose register file) */
};

typedef struct AVR_CONTEXT avr_context;


struct TPL_CONTEXT {
	avr_context * ic;
};

typedef struct TPL_CONTEXT tpl_context;


extern avr_context idle_task_context;
#define IDLE_CONTEXT &idle_task_context 



struct TPL_STACK {
    tpl_stack_word idata *stack_zone;
    tpl_stack_size       stack_size; 
};
typedef struct TPL_STACK tpl_stack;

#define IDLE_STACK {NULL,0}

#endif
