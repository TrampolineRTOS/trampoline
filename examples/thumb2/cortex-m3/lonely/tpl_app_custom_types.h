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
typedef s8 tpl_proc_id;

/**
 * tpl_priority represents a task's or a resource's priority.
 *
 * @warning This type must be signed.
 */
typedef s8 tpl_priority;

/**
 * tpl_activate_counter is used to count
 * how many time a task has been activated while
 * it was not suspended.
 */
typedef u8 tpl_activate_counter;

/**
 * tpl_event_mask is used for event.
 * An event is a bit vector. According to the maximum number of events
 * defined in the application, it can be u8 (8 events), u16 (16 events) or
 * u32 (32 events).
 */
typedef u8 tpl_event_mask;

/**
 * tpl_alarm_type is used for alarm identifiers.
 */
typedef u8 tpl_alarm_id;

/**
 * tpl_resource_id is used for resource identifiers.
 *
 * @warning RES_SCHEDULER is set to the higher resource id + 1
 */
typedef u8 tpl_resource_id;

#if (WITH_TRACE == YES)
/**
 * @internal
 *
 * Type used to store the id of an alarm or a schedule table
 * This is used only for tracing
 */
typedef u8 tpl_timeobj_id;
#endif

#ifdef WITH_AUTOSAR
/**
 * @internal
 *
 * @todo: document this
 */
typedef u8 tpl_counter_id;

/**
 * @internal
 *
 * @todo: document this
 */
typedef u8 tpl_schedtable_id;

/**
 * @internal
 *
 * Type used to store the id of an OS Application
 * Its size is computed according to the number of OS Applications
 */
typedef u8 tpl_app_id;

/**
 * @internal
 *
 * Generic type used in OS Application API
 * Its size is computed by doing the max of all object kind
 */
typedef u8 tpl_generic_id;

#endif /* WITH_AUTOSAR */

#endif /* TPL_APP_CUSTOM_TYPES_H */

/* End of file tpl_app_custom_types.h */
