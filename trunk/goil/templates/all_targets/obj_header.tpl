/*
 * file: $HEADER$
 *
 * This file contains various defines used by Trampoline
 * for conditional compiling.
 *
 * This file has been generated automatically by goil
 * on  $TIMESTAMP$
 */

#ifndef OJB_HEADER_H
#define OJB_HEADER_H

#include "tpl_config_def.h"

/*
 * Configuration flags
 */
$CONFIG_FLAGS$

$COM_CONFIG_FLAGS$

/*
 * Count of the objects used in the application.
 * These informations are used by Trampoline to avoid to
 * alloc structures when some os objects are not present.
 *
 */

/*
 * Declaration of the priority levels count
 */
#define PRIO_LEVEL_COUNT        $PRIO_LEVEL_COUNT$

/*
 * Declaration of Task object count
 */
#define TASK_COUNT              $TASK_COUNT$

/*
 * Declaration of Extended task count
 */
#define EXTENDED_TASK_COUNT     $EXTENDED_TASK_COUNT$

/*
 * Declaration of ISR2 object count
 */
#define ISR_COUNT             $ISR_COUNT$



/*
 * Declaration of Alarm object count
 */
#define ALARM_COUNT           $ALARM_COUNT$

/*
 * Declaration of Resource object count
 */
#define RESOURCE_COUNT        $RESOURCE_COUNT$

/*
 * Declaration of Send Message object count
 */
#define SEND_MESSAGE_COUNT    $SEND_MESSAGE_COUNT$

/*
 * Declaration of Receive Message object count
 */
#define RECEIVE_MESSAGE_COUNT $RECEIVE_MESSAGE_COUNT$

#ifdef WITH_AUTOSAR
/*
 * Declaration of Schedule Table object count
 */
#define SCHEDTABLE_COUNT      $SCHEDTABLE_COUNT$

/*
 * Declaration of Software Counters object count
 */
#define COUNTER_COUNT         $COUNTER_COUNT$

/*
 * Declaration of OS Application object count
 */
#define APP_COUNT             $APP_COUNT$

/*
 * Declaration of Trusted Function count
 */
#define TRUSTED_FCT_COUNT     $TRUSTED_FCT_COUNT$

/*
 * Declaration of the number of virtual watchdogs used for timing protection
 */
#define MAXIMUM_SCHEDULED_WATCHDOGS $MAX_WATCH_DOG$
#endif

/*
 * Define of RES_SCHEDULER priority
 */
#define RES_SCHEDULER_PRIORITY  $RES_SCHEDULER_PRIORITY$

#endif

/* End of file $HEADER$ */
