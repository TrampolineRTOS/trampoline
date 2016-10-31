/**
 * @file tpl_as_st_kernel.c
 *
 * @internal
 *
 * @section desc File description
 *
 * Trampoline autosar extension software schedule tables machinery
 * implementation file
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
 */

#include "tpl_as_st_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_as_error.h"
#include "tpl_os_errorhook.h"
#include "tpl_as_protec_hook.h"
#include "tpl_machine_interface.h"
#include "tpl_dow.h"
#if WITH_MEMORY_PROTECTION == YES
#include "tpl_os_mem_prot.h"
#endif /* WITH_MEMORY_PROTECTION == YES */


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_tick, OS_CODE) tpl_min(
   VAR(tpl_tick, AUTOMATIC) var_1,
   VAR(tpl_tick, AUTOMATIC) var_2);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * @def INVALID_SCHEDULETABLE
 *
 * This value is used to specify an invalid schedule table
 */
CONST(tpl_schedtable_id, AUTOMATIC) INVALID_SCHEDULETABLE = SCHEDTABLE_COUNT;

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_tick, OS_CODE) tpl_min(
   VAR(tpl_tick, AUTOMATIC) var_1,
   VAR(tpl_tick, AUTOMATIC) var_2)
{
  VAR(tpl_tick, AUTOMATIC) return_value;

  if(var_1 > var_2)
  {
    return_value = var_2;
  }
  else
  {
    return_value = var_1;
  }
  return return_value;
}

FUNC(void, OS_CODE) tpl_adjust_next_expiry_point(
					P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st,
					VAR(tpl_expiry_count, AUTOMATIC) index,
					VAR(tpl_bool, AUTOMATIC) last_expiry_point
					)
{
  /*
   * MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
	 * tpl_schedtable_static*. This cast behaves correctly because st is a
	 * tpl_schedtable
   */
  P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable =
    (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))st->stat_part;
	
  P2VAR(tpl_expiry_point, AUTOMATIC, OS_APPL_DATA) next_ep;
	
  VAR(sint32, AUTOMATIC) deviation =
    ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->deviation;
	
  VAR(tpl_tick, AUTOMATIC) adjustment;
  
  /* if last expiry point */
  if ( last_expiry_point == TRUE )
  {
    /* Get the next expiry point */
    next_ep = (schedtable->expiry)[0];
    
    /* Adjust it according to deviation */
    if ( deviation <= 0 )
    {
      adjustment = tpl_min(~(deviation - 1), (next_ep->max_retard));
			
      /* if adjustment > first.delay, adjust final.delay*/
      if ( adjustment > next_ep->sync_offset)
      {
        (schedtable->expiry)[schedtable->count-1]->sync_offset -=
          (adjustment - next_ep->sync_offset);
        next_ep->sync_offset = 0;
      }
      else
      {
        next_ep->sync_offset -= adjustment;
      }
      ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->deviation +=
        adjustment;
    }
    else
    {
      adjustment = tpl_min(deviation, (next_ep->max_advance));
      next_ep->sync_offset += adjustment;
      ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->deviation -=
        adjustment;			 
    }
  }
  else
  /* if not last expiry point */
  {
    
    /* Get the next expiry point */
    next_ep = (schedtable->expiry)[index+1];
    
    /* Adjust it according to deviation */
    if ( deviation <= 0 )
    {
      adjustment = tpl_min(~(deviation - 1), (next_ep->max_retard));
      next_ep->sync_offset -= adjustment;
      ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->deviation +=
        adjustment;
    }
    else
    {
      adjustment = tpl_min(deviation, (next_ep->max_advance));
      next_ep->sync_offset += adjustment;
      ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->deviation -=
        adjustment;			 
    }
  }
}


/*
 * This function is called when the alarm wrapped to the schedule table is
 * raised. After getting the static part of the alarm (that in this case is
 * a TPL_SCHEDTABLE_STATIC structure, this function get the next expiry point
 * and execute the corresponding actions. Then the alarm is updated to match
 * the offset of the next expiry point.
 */
FUNC(void, OS_CODE) tpl_process_schedtable(
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st)
{
  /*  Get the TPL_SCHEDTABLE_STATIC structure                             */
  /*  MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
      tpl_schedtable_static*. This cast behaves correctly because st is a
      tpl_schedtable */
  P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable =
    (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))st->stat_part;
	
  /*  MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
	 tpl_schedtable*. This cast behaves correctly because the
	 first member of tpl_schedula_table is a tpl_time_obj            */
	P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) next =
  ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->next;
  
  /*  Get the current index                                               */
  /*  MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
      tpl_schedtable*. This cast behaves correctly because the first member
      of tpl_schedula_table is a tpl_time_obj */
  VAR(tpl_expiry_count, AUTOMATIC)  index =
    ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index;
	VAR(tpl_expiry_count, AUTOMATIC)  index_temp = index;
	
  /*  Get the current expiry point                                        */
  P2VAR(tpl_expiry_point, AUTOMATIC, OS_APPL_DATA) current_ep =
  	(schedtable->expiry)[index];

  P2CONST(tpl_action, AUTOMATIC, OS_APPL_DATA)  action_desc;
  VAR(tpl_action_count, AUTOMATIC)  i;
	
	VAR(tpl_expiry_count, AUTOMATIC) abs_deviation = ( ~(((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->deviation - 1 ) );
	
  /*launch all the actions of the expiry point*/
  for (i = 0; i < current_ep->count; i++)
  {
    action_desc = (current_ep->actions)[i];
    (action_desc->action)(action_desc);
  }
	
  index = ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index;
	
  /*
   * reset the offset of last expiry point to its default value, because
   * adjustment for synchronisation of this expiry point has been done
   */
  (schedtable->expiry)[index_temp]->sync_offset = (schedtable->expiry)[index_temp]->offset;
  
  /*if finalize expiry point and if repeating st hasn't got offset at 0 */
  if ( (index_temp == (schedtable->count - 1)) && ((schedtable->periodic == FALSE) || (next != NULL)))
  {
    /* do nothing */
  }
  else
  {
    if (index != (uint16)(-1))
    {
    
      /* change state of the schedule table */
      if (schedtable->sync_strat != SCHEDTABLE_NO_SYNC)
      {
        /*
         * if deviation is less than the configured precision,
         * the schedule table is considered synchronized
         * if the schedule table is asynchronous (started or became),
         * the schedule table is configured as RUNNING
         */
        if ((st->state & SCHEDULETABLE_ASYNC) == SCHEDULETABLE_ASYNC)
        {
          st->state = SCHEDULETABLE_RUNNING | SCHEDULETABLE_ASYNC;
        }
        else
        {
          if ( abs_deviation <= (schedtable->precision) )
          {
            st->state = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
          }
          else
          {
            st->state = SCHEDULETABLE_RUNNING;
          }
        }
      }
      else
      {
        st->state = SCHEDULETABLE_RUNNING;
      }
              
      /* adjust next expiry point if EXPLICIT schedule table and not asynchronous */
      if ((schedtable->sync_strat == SCHEDTABLE_EXPLICIT_SYNC) &&
          ((st->state & SCHEDULETABLE_ASYNC) != SCHEDULETABLE_ASYNC) &&
          (abs_deviation > (schedtable->precision)))
      {
        tpl_adjust_next_expiry_point(
          st,
          index, 
          (( (index == (schedtable->count - 2)) ) &&
           (schedtable->periodic == TRUE))
        );
      }
		
    }
    
    /*  Prepare the next expiry point                                       */
    index++;
    /*
     * The schedule table is not finished
     * Set the next cycle to the offset of the next expiry point
     * (offsets are not relative to the start of the schedule table
     * but to the previous expiry point
     *
     * MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a tpl_schedtable*.
     * This cast behaves correctly because the first member of
     * tpl_schedule_table is a tpl_time_obj
     */
    st->cycle = (schedtable->expiry)[index]->sync_offset;
    ((tpl_schedule_table *)st)->index = index;
	}
}

/*
 * Start a schedule table at a relative date.
 *
 * see paragraph 8.4.8 page 80 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
#if SCHEDTABLE_COUNT > 0
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_rel(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            offset
)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
  P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) cnt;
  VAR(tpl_tick, AUTOMATIC) date;
  P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable;

  st = tpl_schedtable_table[sched_table_id];
  /* MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
     tpl_schedtable_static*. This cast behaves correctly because the first memeber
     of tpl_schedula_table_static is a tpl_time_obj_static */
  schedtable = (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))(st->b_desc.stat_part);
  /* A syscall must update counters before using a timeobj's structures */
  TPL_UPDATE_COUNTERS((tpl_time_obj *)st);

  if (st->b_desc.state == (tpl_schedtable_state)SCHEDULETABLE_STOPPED)
  {
    /*  the schedule table is not already started, proceed  */
    cnt = st->b_desc.stat_part->counter;

    /* if NO_SYNC, state = RUNNING
       if EXPLICIT, state = RUNNING and ASYNC  */
    st->b_desc.state = SCHEDULETABLE_RUNNING | SCHEDULETABLE_ASYNC;

    date = cnt->current_date + offset + (schedtable->expiry[0])->offset;

    /* if date > max_allowed_value, take the modulus */
    if (date > cnt->max_allowed_value)
    {
      date = date - cnt->max_allowed_value - 1;
    }
    st->b_desc.date = date;
    /* MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
       tpl_time_obj*. This cast behaves correctly because the first member
       of tpl_schedula_table is a tpl_time_obj */
    tpl_insert_time_obj((tpl_time_obj *)st);
  }
  else
  {
    /* the schedule table is already started,
       return the proper error code                        */
    result = E_OS_STATE;
  }

  /* Tick optimization :
   * A syscall must enable the mastersource after finishing using the timeobj
   * structure.
   */
  TPL_ENABLE_SHAREDSOURCE((tpl_time_obj *)st);
  return result;
}
#endif
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_rel_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            offset
)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  GET_CURRENT_CORE_ID(core_id)

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  LOCK_KERNEL()

  STORE_SERVICE(OSServiceId_StartScheduleTableRel)
  STORE_SCHEDTABLE_ID(sched_table_id)
  STORE_TICK_1(offset)

  CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(core_id,sched_table_id,result)

  CHECK_SCHEDTABLE_OFFSET_VALUE(sched_table_id,offset,result)

  CHECK_SCHEDTABLE_SYNC_STRATEGY_EQUAL_ERROR(sched_table_id, SCHEDTABLE_IMPLICIT_SYNC, result)

#if SCHEDTABLE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    result = tpl_start_schedule_table_rel(sched_table_id, offset);
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

/*
 * Start a schedule table at an absolute date.
 *
 * see paragraph 8.4.9 page 80 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
#if SCHEDTABLE_COUNT > 0
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_abs(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            tick_val
)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
  P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable;
  P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) cnt;
  VAR(tpl_tick, AUTOMATIC) date;

  st = tpl_schedtable_table[sched_table_id];
  /* MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
   tpl_schedtable_static*. This cast behaves correctly because the first memeber
   of tpl_schedula_table_static is a tpl_time_obj_static */
  schedtable = (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))(st->b_desc.stat_part);
  /* A syscall must update counters before using a timeobj's structures */
  TPL_UPDATE_COUNTERS((tpl_time_obj *)st);
  if (st->b_desc.state == (tpl_schedtable_state)SCHEDULETABLE_STOPPED)
  {
    /*  the schedule table is not already started, proceed  */
    cnt = st->b_desc.stat_part->counter;

    /* if NO_SYNC, state = RUNNING,
     otherwise, state = RUNNING_AND_SYNCHRONOUS */
    if (schedtable->sync_strat == SCHEDTABLE_IMPLICIT_SYNC)
    {
      st->b_desc.state = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
    }
    else
    {
      st->b_desc.state = SCHEDULETABLE_RUNNING | SCHEDULETABLE_ASYNC;
    }

    date = (tick_val + (schedtable->expiry[0])->offset);

    /*printf("startstabs - tick_val=%d - (schedtable->expiry[0])->offset=%d - cnt->max_allowed_value=%d - cnt->current_date=%d\n",tick_val,(schedtable->expiry[0])->offset,cnt->max_allowed_value,cnt->current_date);*/
    /* if <tick_val> is after current_date and first expiry point comes between current_date and <tick_val>
      or if <tick_val> is before current_date and first expiry point comes after current_date
      so, bootstrap is needed */
    if ( ( (date > cnt->max_allowed_value) && ((date - (cnt->max_allowed_value + 1)) > cnt->current_date) ) ||
       ( (tick_val < cnt->current_date) && (date > cnt->current_date) ) )
    {
      st->b_desc.state = st->b_desc.state | SCHEDULETABLE_BOOTSTRAP;
    }

    /* if date > max_allowed_value, take the modulus */
    if ( date > cnt->max_allowed_value)
    {
      date -= (cnt->max_allowed_value + 1);
    }
    st->b_desc.date = date;
    /*printf(" - date=%d - state=%d\n",st->b_desc.date,st->b_desc.state);*/
    /* MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
       tpl_time_obj*. This cast behaves correctly because the first memeber
       of tpl_schedula_table is a tpl_time_obj */
    tpl_insert_time_obj((tpl_time_obj *)st);
  }
  else
  {
      /*  the schedule table is already started,
          return the proper error code                        */
      result = E_OS_STATE;
  }

  /* Tick optimization :
   * A syscall must enable the mastersource after finishing using the timeobj
   * structure.
   */
  TPL_ENABLE_SHAREDSOURCE((tpl_time_obj *)st);
  return result;
}
#endif
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_abs_service(
    VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
    VAR(tpl_tick, AUTOMATIC)            tick_val
)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  GET_CURRENT_CORE_ID(core_id)

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  LOCK_KERNEL()

  STORE_SERVICE(OSServiceId_StartScheduleTableAbs)
  STORE_SCHEDTABLE_ID(sched_table_id)
  STORE_TICK_1(tick_val)

  CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(core_id,sched_table_id,result)

  CHECK_SCHEDTABLE_TICK_VALUE(sched_table_id,tick_val,result)

#if SCHEDTABLE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    result = tpl_start_schedule_table_abs(sched_table_id, tick_val);
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

/*
 * Stop a schedule table.
 *
 * see paragraph 8.4.10 page 81 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE) tpl_stop_schedule_table_service(
  VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  GET_CURRENT_CORE_ID(core_id)

#if SCHEDTABLE_COUNT > 0
  P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
#endif

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  LOCK_KERNEL()

  STORE_SERVICE(OSServiceId_StopScheduleTable)
  STORE_SCHEDTABLE_ID(sched_table_id)

  CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)
	
	/* check access right */
	CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(core_id,sched_table_id,result)

#if SCHEDTABLE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    st = tpl_schedtable_table[sched_table_id];

    /* Check the schedule table is started */
    if (st->b_desc.state != (tpl_schedtable_state)SCHEDULETABLE_STOPPED)
    {
      /* check if next schedule table exists */
      if (st->next != NULL)
      {
        st->next->b_desc.state = SCHEDULETABLE_STOPPED;
      }

      /*
       * MISRA RULE 45 VIOLATION: a tpl_schedtable* is cast to a
       * tpl_time_obj*. This cast behaves correctly because the first member
       * of tpl_schedul_table is a tpl_time_obj
       */
      tpl_remove_time_obj((tpl_time_obj *)st);
      st->b_desc.state = SCHEDULETABLE_STOPPED;
      st->index = 0; /* reset the expiry point index to 0 */
    }
    else
    {
      result = E_OS_NOFUNC;
    }
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

/*
 * Switch the processing from one schedule table to another.
 *
 * see paragraph 8.4.11 page 83 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE) tpl_next_schedule_table_service(
  VAR(tpl_schedtable_id, AUTOMATIC)   current_st_id,
  VAR(tpl_schedtable_id, AUTOMATIC)   next_st_id)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  GET_CURRENT_CORE_ID(core_id)

#if SCHEDTABLE_COUNT > 0
  P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) current_st;
  P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) next_st;
#endif

    /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  LOCK_KERNEL()

  STORE_SERVICE(OSServiceId_NextScheduleTable)
  STORE_SCHEDTABLE_ID(current_st_id)
  STORE_SCHEDTABLE_ID2(next_st_id)

  CHECK_SCHEDTABLE_ID_ERROR(current_st_id, result)
	
	/* check access right */
	CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(core_id,current_st_id,result)
    
	CHECK_SCHEDTABLE_ID_ERROR(next_st_id, result)
	
	/* check access right */
	CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(core_id,next_st_id,result)
	
	CHECK_SCHEDTABLE_TO_STOPPED(next_st_id,result)

#if SCHEDTABLE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    current_st = tpl_schedtable_table[current_st_id];
    next_st = tpl_schedtable_table[next_st_id];

    CHECK_SCHEDTABLE_COUNTERS(current_st, next_st, result)

    IF_NO_EXTENDED_ERROR(result)
    {
      /*  Check the current schedule table is started         */
      if ((current_st->b_desc.state != SCHEDULETABLE_STOPPED) &&
          (current_st->b_desc.state != SCHEDULETABLE_NEXT))
      {
        /*  Set the next pointer                            */
        if (current_st->next != NULL)
        {
          current_st->next->b_desc.state = SCHEDULETABLE_STOPPED;
        }
        current_st->next = next_st;
        /*  And the state of the next schedule table        */
        next_st->b_desc.state = SCHEDULETABLE_NEXT;
      }
      else
      {
        result = E_OS_NOFUNC;
      }
    }
  }
#endif

  PROCESS_ERROR(result)
  
  UNLOCK_KERNEL()

  return result;
}


/**
 * Get the status of a schedule table
 *
 * see paragraph 8.4.15 page 86 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE) tpl_get_schedule_table_status_service(
  VAR(tpl_schedtable_id, AUTOMATIC)                       sched_table_id,
  P2VAR(tpl_schedtable_state, AUTOMATIC, OS_APPL_DATA)    status)
{
  VAR(tpl_status, AUTOMATIC)  result = E_OK;
  GET_CURRENT_CORE_ID(core_id)

#if SCHEDTABLE_COUNT > 0
  P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
#endif

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetScheduleTableStatus)
  STORE_SCHEDTABLE_ID(sched_table_id)
  STORE_ST_STATUS_REF(status)

  CHECK_SCHEDTABLE_ID_ERROR(sched_table_id, result)
	
	/* check access right */
	CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(core_id,sched_table_id,result)

  /* check status is in an authorized memory region */
  CHECK_DATA_LOCATION(core_id, status, result);
  
#if SCHEDTABLE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    st = tpl_schedtable_table[sched_table_id];
    *status = (st->b_desc.state & ~SCHEDULETABLE_BOOTSTRAP & ~SCHEDULETABLE_ASYNC);
  }
#endif
	
  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_st_kernel.c */
