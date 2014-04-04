/**
 * @file tpl_as_action.c
 *
 * @section descr File description
 *
 * Trampoline autosar extension. extra action to increment
 * a counter. Implementation
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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

#include "tpl_as_action.h"
#include "tpl_os_alarm_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 *  action function for action by incrementing counter
 */
FUNC(void, OS_CODE) tpl_action_increment_counter(
    P2CONST(tpl_action, AUTOMATIC, OS_APPL_CONST) action)
{
    /*
     * A tpl_action * is cast to a tpl_increment_counter_action *
     * This violate MISRA rule 45. However, since the
     * first member of tpl_increment_counter_action is a tpl_action
     * This cast behaves correctly.
     */
    tpl_counter_tick(((const tpl_increment_counter_action *)action)->counter);
}

/**
 *  action function for action by finalizing the scheduletable
 *
 *  The schedule table is finished                                 
 *  Test whether a schedule table has been nextified or not     
*/
FUNC(void, OS_CODE) tpl_action_finalize_schedule_table(
	P2CONST(tpl_action, AUTOMATIC, OS_APPL_CONST) action)
{
	/*
	 * A tpl_action * is cast to a tpl_finalize_schedule_table_action *
	 * This violate MISRA rule 45. However, since the
	 * first member of tpl_finalize_schedule_table_action is a tpl_action
	 * This cast behaves correctly.
	 */
	P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st =
		&(((P2CONST(tpl_finalize_schedule_table_action, AUTOMATIC, OS_APPL_CONST))action)->schedule_table->b_desc);		
	
	P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable =
		(P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))st->stat_part;
	
	/*  MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
	 tpl_schedtable*. This cast behaves correctly because the
	 first member of tpl_schedula_table is a tpl_time_obj            */
	P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) next =
		((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->next;
	
	/* Get the next expiry point */
	P2VAR(tpl_expiry_point, AUTOMATIC, OS_APPL_DATA) next_ep;
		
	P2CONST(tpl_action, AUTOMATIC, OS_APPL_DATA)  action_desc;
  VAR(tpl_action_count, AUTOMATIC)  i;
	
	VAR(tpl_tick, AUTOMATIC) before;
	
	/*VAR(tpl_expiry_count, AUTOMATIC) abs_deviation = ( ~(((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->deviation - 1 ) );
*/
	/*  Get the remaining time to fill the current schedule table
	 period. This time is stored in the offset of the first expiry
	 point                                                           */
	before = (schedtable->expiry)[0]->sync_offset;
	
	/*  Reset the cycle of the time object                                  */
	st->cycle = 0;
	
	/*  Reset the index                                                 */
	/*  MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
	 tpl_schedtable*. This cast behaves correctly because the
	 first memberof tpl_schedule_table is a tpl_time_obj             */
	((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index = 0;
	
	if (next != NULL) {
		
		/* if next, the synchronisation if forgotten because it's like a changing of mode. */

		/*  reset the state of the current schedule table               */
		st->state = SCHEDULETABLE_STOPPED;
		
    /*  Get the next expiry point                                        */
		next_ep =
		((P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))next->b_desc.stat_part)->expiry[0];
		
		/* check if expiry point at offset=0 */
		if (next_ep->offset == 0)
		{
      /*launch all the actions of the expiry point*/
			for (i = 0; i < next_ep->count; i++)
			{
				action_desc = (next_ep->actions)[i];
				(action_desc->action)(action_desc);
			}			

      /* Increment index because the first one has just been launched */
      next->index = 1;
      
      /* Change next expiry point */
      next_ep =
      ((P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))next->b_desc.stat_part)->expiry[1];
      
		}	    
      
    /*  There is a next schedule table set, start it                */
    next->b_desc.date = next->b_desc.stat_part->counter->current_date + next_ep->offset;
    
		
		/*  MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
		 tpl_time_obj*. This cast behaves correctly because the
		 first member of tpl_schedule_table is a tpl_time_obj            */
		((tpl_time_obj *)next)->state = SCHEDULETABLE_RUNNING;
		tpl_insert_time_obj((tpl_time_obj *)next);
	}
	else if (schedtable->periodic == TRUE) {
		
		/* if first expiry point in the next ST is at offset=0, launch it directly  */
		if(schedtable->expiry[0]->sync_offset == 0)
		{		
      /*launch all the actions of the expiry point*/
			for (i = 0; i < schedtable->expiry[0]->count; i++)
			{
				action_desc = (schedtable->expiry[0]->actions)[i];
				(action_desc->action)(action_desc);
			}
						
			/* reset the offset of the first expiry point too */
			(schedtable->expiry)[0]->sync_offset = (schedtable->expiry)[0]->offset;
		
			/*Increment index because the first one has just been launched*/
			((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index = 0;
		}
    else
    {
      ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index = -1;
    }

	}
	else {
		/*  reset the state of the current schedule table               */
		st->state = SCHEDULETABLE_STOPPED;
	}
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_action.c */
