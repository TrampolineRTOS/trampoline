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

#include "tpl_os_internal_types.h"

#ifndef __TPL_MACHINE_C166_H__
#define __TPL_MACHINE_C166_H__

/* in comment for each register: address in memory / sfr number */
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


extern c166_context idle_task_context;
#define IDLE_CONTEXT &idle_task_context 



struct TPL_STACK {
    tpl_stack_word idata *sys_stack_zone;
    tpl_stack_size       sys_stack_size; 
    tpl_stack_word       *user_stack_zone;
    tpl_stack_size       user_stack_size;
};
typedef struct TPL_STACK tpl_stack;

#define IDLE_STACK {NULL,0,NULL,0}

#endif
