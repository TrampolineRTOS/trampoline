/*
 *  @file tpl_as_global_time.h
 *
 * @section desc File description
 *
 * Trampoline autosar extension sync to global time header
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

#ifndef TPL_AS_GLOBAL_TIME_H
#define TPL_AS_GLOBAL_TIME_H

#include "tpl_as_schedtable.h"

typedef VAR(tpl_tick, AUTOMATIC) GlobalTimeTickType;

/**
 * Start a schedule table sync with global time.
 *
 * @param   sched_table_id  identifier of the schedule table to be started
 * @param   gt              global time
 *
 * @retval  E_OK        no error
 *                      requirement OS389
 * @retval  E_OS_ID     (EXTENDED status only) sched_table_id is not valid
 *                      or the schedule table cannot be synchronized
 *                      (LOCAL_TO_GLOBAL_TIME_SYNCHRONIZATION=FALSE)
 *                      requirement OS387
 * @retval  E_OS_VALUE  The global time is invalid
 *                      requirement OS395
 * @retval  E_OS_STATE  the schedule table is not in the state
 *                      SCHEDULETABLE_NOT_STARTED
 *                      requirement OS388
 *
 * see paragraph 8.4.15 page 71 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) StartScheduleTableSynchron ( 
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id, 
    VAR(GlobalTimeTickType, AUTOMATIC)  gt 
);

/**
 * Synchronize a schedule table with global time.
 *
 * @param   sched_table_id  identifier of the schedule table to be synchronized
 * @param   gt              global time
 *
 * @retval  E_OK        no error.
 * @retval  E_OS_ID     (EXTENDED status only) sched_table_id is not valid
 *                      or the schedule table cannot be synchronized
 *                      (LOCAL_TO_GLOBAL_TIME_SYNCHRONIZATION=FALSE)
 * @retval  E_OS_STATE  the schedule tables is in the state
 *                      SCHEDULETABLE_NOT_STARTED.
 *
 * see paragraph 8.4.16, page 72 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) SyncScheduleTable(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id,
    VAR(GlobalTimeTickType, AUTOMATIC)  gt
);

/**
 * Set the status of the schedule table to asynchronous
 *
 * @param sched_table_id  identifier of the schedule table to set
 *
 * @retval  E_OK        no error.
 * @retval  E_OS_ID     (EXTENDED status only) sched_table_id is not valid
 *
 * see paragraph 8.4.17, page 73 of
 * AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(StatusType, OS_CODE) SetScheduleTableAsync(
    VAR(ScheduleTableType, AUTOMATIC) sched_table_id
);

/* TPL_AS_GLOBAL_TIME_H */
#endif

/* End of file tpl_as_global_time.h */
