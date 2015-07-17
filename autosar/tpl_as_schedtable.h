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

#include "tpl_os_timeobj_kernel.h"
#include "tpl_os_types.h"
/*#include "tpl_as_definitions.h"*/

typedef VAR(tpl_schedtable_id, AUTOMATIC)  ScheduleTableType;
typedef VAR(tpl_time_obj_state, AUTOMATIC) ScheduleTableStatusType;
typedef P2VAR(tpl_time_obj_state, AUTOMATIC, OS_APPL_DATA) ScheduleTableStatusRefType;

/**
 * @def DeclareScheduleTable
 *
 * Defines a Schedule Table
 *
 * @param scheduletable_id schedule table's C identifier
 *
 */
#define DeclareScheduleTable(scheduletable_id)				\
		extern CONST(ScheduleTableType, AUTOMATIC) scheduletable_id

#endif /*  TPL_AS_SCHEDTABLE_H */
