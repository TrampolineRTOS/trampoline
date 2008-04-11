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
 * $URL$
 */

#ifndef __TPL_MACHINE_AVR_H__
#define __TPL_MACHINE_AVR_H__

#include "tpl_os_custom_types.h"

/*
struct AVR_CONTEXT {
	u16 sp;   
};

typedef struct AVR_CONTEXT avr_context;
*/

typedef u16 * avr_context;

struct TPL_CONTEXT {
	avr_context * ic;
};

typedef struct TPL_CONTEXT tpl_context;


extern avr_context idle_task_context;
#define IDLE_CONTEXT {&idle_task_context} 



struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size   stack_size; 
};
typedef struct TPL_STACK tpl_stack;

#define IDLE_STACK {NULL,0}

#endif
