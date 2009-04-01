/**
 * @file tpl_debug.c
 *
 * @section descr File description
 *
 * Various functions for Debugging on Workstation (DoW) purpose.
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
 *
 */

#include "tpl_debug.h"
#include "tpl_os_rez_kernel.h"
#include <stdio.h>

void print_counter(tpl_counter *c)
{
  tpl_time_obj *t = c->first_to;
  
  printf("counter (ticks_per_base=%d, max_allowed_value=%d, min_cycle=%d)\n",
         (int)c->ticks_per_base,
         (int)c->max_allowed_value,
         (int)c->min_cycle);
  printf("    current_tick=%d, current_date=%d\n",
         (int)c->current_tick,
         (int)c->current_date);
  
  while (t != NULL) {
    printf("        date=%d, alr=%d\n",(int)t->date,(int)t);
    t = t->next_to;
  }
}

void print_rez(tpl_resource_id rez_id)
{
  printf("resource %d (ceiling_prio=%d, owner_prio=%d)\n",
         rez_id,
         tpl_resource_table[rez_id]->ceiling_priority,
         tpl_resource_table[rez_id]->owner_prev_priority);
  printf("    owner=%d\n",tpl_resource_table[rez_id]->owner);
}
