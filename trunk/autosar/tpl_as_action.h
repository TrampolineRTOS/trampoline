/**
 * @file tpl_as_action.h
 *
 * @section descr File description
 *
 * Trampoline autosar extension. extra action to increment
 * a counter. Header
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

#ifndef TPL_AS_ACTION_H
#define TPL_AS_ACTION_H

#include "tpl_os_action.h"
#include "tpl_os_timeobj_kernel.h"
#include "tpl_as_st_kernel.h"

/*!
 *  \brief  Increment counter action structure
 *
 *  This structure add a pointer to a counter to the base action
 *  structure.
 */
struct TPL_INCREMENT_COUNTER_ACTION {
    /*  base action           */
    VAR(tpl_action, AUTOMATIC)                  b_desc;
    /*  callback function pointer   */
    P2VAR(tpl_counter, TYPEDEF, OS_APPL_DATA) counter;
};

typedef struct TPL_INCREMENT_COUNTER_ACTION
tpl_increment_counter_action;

/*!
 *  \brief  Finalize Schedule Table action structure
 *
 *  This structure add a schedule table to the base action
 *  structure.
 */
struct TPL_FINALIZE_SCHEDULE_TABLE_ACTION {
    /*  base action           */
    VAR(tpl_action, AUTOMATIC)                  b_desc;
    /*  callback function pointer   */
    P2VAR(tpl_schedule_table, TYPEDEF, OS_APPL_DATA) schedule_table;
};

typedef struct TPL_FINALIZE_SCHEDULE_TABLE_ACTION
	tpl_finalize_schedule_table_action;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Notification function prototype
 */
FUNC(void, OS_CODE) tpl_action_increment_counter(
    P2CONST(tpl_action, AUTOMATIC, OS_APPL_CONST) action);

FUNC(void, OS_CODE) tpl_action_finalize_schedule_table(
	P2CONST(tpl_action, AUTOMATIC, OS_APPL_CONST) action);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_AS_ACTION_H */
#endif

/* End of file tpl_as_action.h */
