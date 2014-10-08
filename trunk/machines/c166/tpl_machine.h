/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline C166 specifics
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL: http://localhost:8888/Trampoline/svn/tpl_machine/c166/tpl_machine_c166.h $
 */



 /*****************
  * IMPORTANT NOTE
  *****************
  * the C167 is an obsolete port and the context switch from interrupt
  * get various data from the stack. This imposes that the context switch
  * function SHOULD be called directly from the interrupt handler
  * for both user interrupts and counters interrupts.
  * The sources should be patched to take it into account:
  * in file os/tpl_os_interrupt_kernel.c 
  *     -> in function 'tpl_central_interrupt_handler':
  * it SHOULD not call the context switch:
  * // LOCAL_SWITCH_CONTEXT(a_core_id) //line to comment.
  * This line is required for other ports.
  */

#ifndef __TPL_MACHINE_C166_H__
#define __TPL_MACHINE_C166_H__

#include "tpl_os_custom_types.h"


/* in comment for each register: address in memory / sfr number */
/* GPR are also saved, but in internal ram (idata), in other structure. */
struct C166_CONTEXT {
	unsigned int mdc;   /* FF0E / 87 */
	unsigned int dpp0;  /* FE00 / 00 */
	unsigned int dpp1;  /* FE02 / 01 */
	unsigned int dpp2;  /* FE04 / 02 */
	unsigned int dpp3;  /* FE06 / 03 */
	unsigned int mdh;   /* FE0C / 06 */
	unsigned int mdl;   /* FE0E / 07 */
	unsigned int sp;    /* FE12 / 09 */
	unsigned int stkov; /* FE14 / 0A */
	unsigned int stkun; /* FE16 / 0B */
	unsigned int psw;
	unsigned int csp;
	unsigned int ip;
	unsigned int cp;    /* FE10 / 08 */
	unsigned int ustack;    /* user stack: R0 */
};

typedef struct C166_CONTEXT c166_context;


struct TPL_CONTEXT {
	c166_context * ic;
};

typedef struct TPL_CONTEXT tpl_context;

/**
 * tpl_stack_word is the basic element of a stack in order to have a proper
 * data alignement.
 */
typedef uint16 tpl_stack_word;

/**
 * tpl_stack_size is the data type used to store the stack size
 */
typedef uint16 tpl_stack_size;


struct TPL_STACK {
  tpl_stack_word idata *sys_stack_zone;
  tpl_stack_size       sys_stack_size; 
  tpl_stack_word near  *user_stack_zone;
  tpl_stack_size       user_stack_size;
};
typedef struct TPL_STACK tpl_stack;

/**
 * @def SIZE_OF_IDLE_TASK
 *
 * The size of the stack of the idle task which is also the stack
 * used for machine startup
 */
#define SIZE_OF_IDLE_USR_STACK   256 //TODO: may be optimized..
#define SIZE_OF_IDLE_SYS_STACK   256 //TODO: may be optimized..


#endif
