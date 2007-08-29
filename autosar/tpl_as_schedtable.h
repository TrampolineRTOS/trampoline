/**
 * @file tpl_as_schedtable.h
 *
 * @section desc File description
 *
 * Trampoline autosar extension software schedule tables API
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
 
#ifndef TPL_AS_SCHEDTABLE_H
#define TPL_AS_SCHEDTABLE_H

#include "tpl_os_alarm.h"

typedef u8  ScheduleTableType;

/**
 * Start a schedule table at a relative date.
 *
 * @param   sched_table_id  identifier of the schedule table to be started
 * @param   offset          relative tick value between now and the first
 *                          alarm expiry
 *
 * @retval  E_OK        no error
 *                      requirement OS278
 * @retval  E_OS_ID     sched_table_id is not valid (EXTENDED status only)
 *                      requirement OS275
 * @retval  E_OS_VALUE  offset was set to 0 or is greater than the
 *                      MAXALLOWEDVALUE of the counter (EXTENDED status only)
 *                      requirement OS276 and OS332
 * @retval  E_OS_STATE  the schedule table is already started or currently in
 *                      state SCHEDULETABLE_NEXT
 *                      requirement OS277
 *
 * see paragraph 8.4.8 page 55 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
StatusType  StartScheduleTableRel(
    ScheduleTableType   sched_table_id,
    TickType            offset
);

/**
 * Start a schedule table at an absolute date.
 *
 * @param   sched_table_id  identifier of the schedule table to be started
 * @param   tick_val        absolute tick value between of the first
 *                          alarm expiry
 *
 * @retval  E_OK        no error
 *                      requirement OS351
 * @retval  E_OS_ID     sched_table_id is not valid (EXTENDED status only)
 *                      requirement OS348
 * @retval  E_OS_VALUE  tick_val is greater than the
 *                      MAXALLOWEDVALUE of the counter
 *                      requirement OS349
 * @retval  E_OS_STATE  the schedule table is already started or currently in
 *                      state SCHEDULETABLE_NEXT
 *                      requirement OS350
 *
 * see paragraph 8.4.9 page 55 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
StatusType  StartScheduleTableAbs(
    ScheduleTableType   sched_table_id,
    TickType            tick_val
);

/**
 * Stop a schedule table.
 *
 * @param   sched_table_id  identifier of the schedule table to be started
 *
 * @retval  E_OK        no error
 *                      requirement OS281
 * @retval  E_OS_ID     sched_table_id is not valid (EXTENDED status only)
 *                      requirement OS279
 * @retval  E_OS_NOFUNC the schedule table was not started
 *                      requirement OS280
 *
 * see paragraph 8.4.10 page 56 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
StatusType StopScheduleTable(
    ScheduleTableType   sched_table_id
);

/**
 * Switch the processing from one schedule table to another.
 *
 * @param   current_sd_id   identifier of the schedule table currently in use
 * @param   next_sd_id      identifier of the next schedule table to process
 *
 * @retval  E_OK        no error
 *                      requirement OS284
 * @retval  E_OS_ID     current_sd_id or next_sd_id are not valid
 *                      (EXTENDED status only).
 *                      requirement OS282
 * @retval  E_OS_NOFUNC the schedule table current_sd_id is not started or
 *                      currently in state SCHEDULETABLE_NEXT.
 *                      requirement OS283
 * @retval  E_OS_STATE  the schedule table next_sd_id is already started or
 *                      already the next schedule table to switch to
 *                      (EXTENDED status only).
 *                      requirement OS309
 *
 * see paragraph 8.4.11 page 57 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
StatusType NextScheduleTable(
    ScheduleTableType   current_sd_id,
    ScheduleTableType   next_sd_id
);

#endif /*  TPL_AS_SCHEDTABLE_H */
