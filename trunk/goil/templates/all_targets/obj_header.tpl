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

/*
 * Configuration flags
 */
$CONFIG_FLAGS$

/*
 * Count of the objects used in the application.
 * These informations are used by Trampoline to avoid to
 * alloc structures when some os objects are not present.
 *
 */

/*
 * Declaration of Task object count
 */
#define TASK_COUNT              $TASK_COUNT$

/*
 * Declaration of ISR2 object count
 */
#define ISR_COUNT               $ISR_COUNT$

/*
 * Declaration of Alarm object count
 */
#define ALARM_COUNT             $ALARM_COUNT$

/*
 * Declaration of Resource object count
 */
#define RESOURCE_COUNT          $RESOURCE_COUNT$

/*
 * Declaration of Send Message object count
 */
#define SEND_MESSAGE_COUNT      $SEND_MESSAGE_COUNT$

/*
 * Declaration of Receive Message object count
 */
#define RECEIVE_MESSAGE_COUNT   $RECEIVE_MESSAGE_COUNT$

/*
 * Define of RES_SCHEDULER priority
 */
#define RES_SCHEDULER_PRIORITY  $RES_SCHEDULER_PRIORITY$

#endif

/* End of file $HEADER$ */
