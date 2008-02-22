/**
 * @file 
 *
 * @section 
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

#ifndef __TPL_MACHINE_H8300H_H__
#define __TPL_MACHINE_H8300H_H__

#include "tpl_os_custom_types.h"

typedef u32 * h8300h_context ;


typedef struct {
	h8300h_context * ic;
}tpl_context ;


extern h8300h_context idle_task_context;
#define IDLE_CONTEXT {&idle_task_context} 



struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size   stack_size; 
};
typedef struct TPL_STACK tpl_stack;

extern tpl_stack_word stack_zone_of_idleTask[512/sizeof(tpl_stack_word)];

#define IDLE_STACK { stack_zone_of_idleTask, 512 }

#endif
