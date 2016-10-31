/*
 *  @file tpl_as_gt_kernel.c
 *
 * @section desc File description
 *
 * Trampoline autosar extension sync to global time implementation
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
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

#include "tpl_as_error.h"
#include "tpl_os_definitions.h"
#include "tpl_as_gt_kernel.h"
#include "tpl_machine_interface.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * This function is called after a schedule table has been started
 * synchronously, when the synchronized time is provided to OS
 */
FUNC(void, OS_CODE) tpl_start_sched_table_sync(
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) st,
  VAR(tpl_time, AUTOMATIC) sync_date)
{
  /*
   * MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
   * tpl_schedtable_static*. This cast behaves correctly because the
   * first member of tpl_schedtable_static is a tpl_time_obj_static
   */
  P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable =
    (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))st->stat_part;

  /*
   * compute the start date of the synchronized schedule table:
   * start date = drive_cnt.now + (duration - sync_date)
   */
  st->date =  (st->stat_part->counter->current_date) + 
              (st->date) +
              ((schedtable->length) - sync_date) +
              schedtable->expiry[0]->offset;
	
  if ( st->date > st->stat_part->counter->max_allowed_value )
  {
    st->date = st->date - st->stat_part->counter->max_allowed_value - 1;
  }

  /* as the schdule table is started synchronously, it is synchronous     */
  st->state = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;

  /* insert the schedule table in the queue */
  tpl_insert_time_obj(st);
}


/*
 * This function is called when a schedule table has been started
 * asynchronously and the synchronized time is provided to the OS
 */
FUNC(void, OS_CODE) tpl_sync_sched_table(
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)  st,
  VAR(tpl_time, AUTOMATIC)                      sync_date)
{
  /*  Get the TPL_SCHEDTABLE_STATIC structure                             */
  P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable;
  /*  Get the current index                                               */
  VAR(tpl_expiry_count, AUTOMATIC)  index;
  VAR(tpl_expiry_count, AUTOMATIC)  j;

  VAR(tpl_tick, AUTOMATIC)  drive_cnt_now;
  VAR(tpl_tick, AUTOMATIC)  drive_cnt_match;
  VAR(tpl_tick, AUTOMATIC)  position_on_tbl;
  VAR(tpl_tick, AUTOMATIC)  next_ep_offset=0;
  VAR(sint32, AUTOMATIC)  deviation;

  /* get the current date of the counter which drives the schedule table  */
  drive_cnt_now = st->stat_part->counter->current_date;

  /* get the date of expiration of the next expiry point */
  drive_cnt_match = st->date;

  /* MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
     tpl_schedtable_static*. This cast behaves correctly because st is a
     tpl_schedtable */
  schedtable =
      (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))(st->stat_part);
  /* MISRA RULE 45 VIOLATION: a tpl_time_obj* is cast to a
     tpl_schedtable*. This cast behaves correctly because the first memeber
     of tpl_schedule_table is a tpl_time_obj */
  index = ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->index;

  /* this loop calculates the offset of the next_expiry point
     from the start of the schedule table */
  for(j = 0; j <= index; j++)
  {
    next_ep_offset = next_ep_offset +
                     (((schedtable->expiry)[j])->sync_offset);
  }

  /* calculate the current position in the schedule table */
  position_on_tbl = next_ep_offset - (drive_cnt_match - drive_cnt_now);

  /* calculate the deviation and store it into the schedule table */
  deviation = position_on_tbl - sync_date;
  
  /* change state if schedule table is not synchronous */
  if( deviation <= schedtable->precision )
  {
	  st->state = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
  }
  else
  {
	  st->state = SCHEDULETABLE_RUNNING;	  
  }
	
  /* save deviation */
  ((P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA))st)->deviation = deviation;
	
}

/*
 * Start a schedule table synchronized with global time
 *
 * see paragraph 8.4.12 page 84 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
#if SCHEDTABLE_COUNT > 0
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_synchron(
  VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
  /* Tick optimization :
   * A syscall must update counters before using a timeobj's structures
   */
  TPL_UPDATE_COUNTERS((tpl_time_obj *)st);

  st = tpl_schedtable_table[sched_table_id];
  if (st->b_desc.state == (tpl_schedtable_state)SCHEDULETABLE_STOPPED)
  {
    /*
     * the schedule table is not already started,
     * it is put in the waiting state until the global time is provided
     */
    st->b_desc.state = SCHEDULETABLE_WAITING;
  }
  else
  {
    /* the schedule table is already started, return the proper error code */
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
FUNC(tpl_status, OS_CODE)  tpl_start_schedule_table_synchron_service(
  VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  GET_CURRENT_CORE_ID(core_id)

  LOCK_KERNEL()

    /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_StartScheduleTableSynchron)
  STORE_SCHEDTABLE_ID(sched_table_id)

  CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(core_id,sched_table_id,result)

  CHECK_SCHEDTABLE_SYNC_STRATEGY_DIFF_ERROR(sched_table_id, SCHEDTABLE_EXPLICIT_SYNC, result)

#if SCHEDTABLE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    result = tpl_start_schedule_table_synchron(sched_table_id);
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

/**
 *  Synchronize a schedule table with global time
 *
 * see paragraph 8.4.13 page 84 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE) tpl_sync_schedule_table_service(
  VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id,
  VAR(tpl_tick, AUTOMATIC)            value
)
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
  STORE_SERVICE(OSServiceId_SyncScheduleTable)
  STORE_SCHEDTABLE_ID(sched_table_id)
  STORE_TICK_1(value)
	
  CHECK_SCHEDTABLE_ID_ERROR(sched_table_id, result)
	
	/* check access right */
  CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(core_id,sched_table_id,result)
	
  CHECK_SCHEDTABLE_VALUE(sched_table_id, value, result)

  CHECK_SCHEDTABLE_SYNC_STRATEGY_DIFF_ERROR(sched_table_id, SCHEDTABLE_EXPLICIT_SYNC, result)
  CHECK_SCHEDTABLE_DIFF_STOPPED_AND_NEXT(sched_table_id, result)
	
#if SCHEDTABLE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /* Tick optimization :
     * A syscall must update counters before using a timeobj's structures
     */
    TPL_UPDATE_COUNTERS((tpl_time_obj *)st);
    st = tpl_schedtable_table[sched_table_id];

    /* if schedule table is waiting, start it, else if running synchronize it */
    if( st->b_desc.state == SCHEDULETABLE_WAITING )
    {
      tpl_start_sched_table_sync(&(st->b_desc), value);
    }
    else
    {
      tpl_sync_sched_table(&(st->b_desc), value);
    }

    /* Tick optimization :
     * A syscall must enable the mastersource after finishing using the timeobj
     * structure.
     */
    TPL_ENABLE_SHAREDSOURCE((tpl_time_obj *)st);
  }
#endif
	
  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}


/**
 *  Set a schedule table asynchrone to global time
 *
 * see paragraph 8.4.14 page 85 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(tpl_status, OS_CODE) tpl_set_schedule_table_async_service(
  VAR(tpl_schedtable_id, AUTOMATIC)   sched_table_id
)
{
  VAR(tpl_status, AUTOMATIC)  result = E_OK;
  GET_CURRENT_CORE_ID(core_id)

#if SCHEDTABLE_COUNT > 0
  P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) st;
  P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA) schedtable;
#endif

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  LOCK_KERNEL()

  /* store information for error hook routine    */
  STORE_SERVICE(OSServiceId_SetScheduleTableAsync)
  STORE_SCHEDTABLE_ID(sched_table_id)

  CHECK_SCHEDTABLE_ID_ERROR(sched_table_id, result)
	
	/* check access right */
  CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(core_id,sched_table_id,result)

  CHECK_SCHEDTABLE_SYNC_STRATEGY_DIFF_ERROR(sched_table_id, SCHEDTABLE_EXPLICIT_SYNC, result)

#if SCHEDTABLE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /* Tick optimization :
     * A syscall must update counters before using a timeobj's structures
     */
    TPL_UPDATE_COUNTERS((tpl_time_obj *)st);
    st = tpl_schedtable_table[sched_table_id];
    /*
     * MISRA RULE 45 VIOLATION: a tpl_time_obj_static* is cast to a
     * tpl_schedtable_static*. This cast behaves correctly because the first
     * member of tpl_schedula_table_static is a tpl_time_obj_static
     */
    schedtable = (P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))st->b_desc.stat_part;
    /* check the state of the schedule table */
    if( (SCHEDULETABLE_RUNNING == st->b_desc.state)
        || (SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS == st->b_desc.state) )
    {
      st->b_desc.state = SCHEDULETABLE_RUNNING | SCHEDULETABLE_ASYNC;
      /*st->deviation = 0;*/
    }

    /* Tick optimization :
     * A syscall must enable the mastersource after finishing using the timeobj
     * structure.
     */
    TPL_ENABLE_SHAREDSOURCE((tpl_time_obj *)st);
  }
#endif
	
  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_gt_kernel.c */
