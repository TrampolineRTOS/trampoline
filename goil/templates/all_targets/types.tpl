/**
 * @file tpl_app_custom_types.h
 *
 * @section File description
 *
 * This file gathers all data types which are generated from the application.
 * Please refer to comment of each type for more details.
 *
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_APP_CUSTOM_TYPES_H
#define TPL_APP_CUSTOM_TYPES_H

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"

/**
 * tpl_proc_id is used for task and isrs identifiers.
 *
 * @warning This data type must be signed
 * because -1 is used for INVALID_TASK and INVALID_ISR
 */
typedef $PROC_ID_T$ tpl_proc_id;

/**
 * tpl_priority represents a task's or a resource's priority.
 *
 * @warning This type must be signed.
 */
typedef $PRIORITY_T$ tpl_priority;

/**
 * tpl_activate_counter is used to count
 * how many time a task has been activated while
 * it was not suspended.
 */
typedef $ACTIVATION_T$ tpl_activate_counter;

/**
 * tpl_event_mask is used for event.
 * An event is a bit vector. According to the maximum number of events
 * defined in the application, it can be u8 (8 events), u16 (16 events) or
 * u32 (32 events).
 */
typedef $EVENTMASK_T$ tpl_event_mask;

/**
 * tpl_alarm_type is used for alarm identifiers.
 */
typedef $ALARM_ID_T$ tpl_alarm_id;

/**
 * tpl_resource_id is used for resource identifiers.
 *
 * @warning RES_SCHEDULER is set to the higher resource id + 1
 */
typedef $RESOURCE_ID_T$ tpl_resource_id;

#ifdef WITH_AUTOSAR
/**
 * @internal
 *
 * @todo: document this
 */
typedef $COUNTER_ID_T$ tpl_counter_id;

/**
 * @internal
 *
 * @todo: document this
 */
typedef $SCHEDTABLE_ID_T$ tpl_schedtable_id;

#endif /* WITH_AUTOSAR */

#endif /* TPL_APP_CUSTOM_TYPES_H */

/* End of file tpl_app_custom_types.h */
