/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline types definitions
 * 
 * Datatypes defined in this file can be changed by the user
 * to fit its needs. Please refer to comments of each
 * datatype.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */
 
#ifndef __TPL_OS_TYPES_H__
#define __TPL_OS_TYPES_H__

/*
 * tpl_task_id is used for task ids.
 * note this data type must be a signed one
 * because -1 is used for INVALID_TASK
 * Change it to use id greater than 32767
 */
typedef short int tpl_task_id;

/*
 * tpl_priority is used for task and resource
 * priority. By default it is a char
 * you can change it if you want a priority greater
 * than 127. Keep in mind tpl_priority should not
 * be an unsigned data type since -1 is used
 * for the idle task priority.
 */
typedef char tpl_priority;

/*
 * tpl_activate_counter is used to count
 * how many time a task has been activated while
 * it was not suspended.
 */
typedef unsigned char tpl_activate_counter;

/*
 * tpl_event_mask is used for event.
 * An event is a bit vector. By default 8 events per task are available.
 * If more events per task are needed, feel free to set tpl_event_mask to
 * an unsigned short int (16 events) or an unsigned long int (32 events).
 */
typedef unsigned char tpl_event_mask;

/*
 * tpl_tick is used for relative and absolute dates.
 * tpl_tick should be an unsigned datatype.
 * By default it is an unsigned short int.
 * It can be changed according to the user needs
 */
typedef unsigned short int tpl_tick;

/*
 * tpl_alarm_type is used for alarm ids.
 * By default, it is set to unsigned char.
 * So up to 256 alarms are available. It can be changed
 * to unsigned short int or unsigned long int
 * if more alarms are needed
 */
typedef unsigned char tpl_alarm_id;

/*
 * tpl_resource_id is used for resource ids.
 * By default it is set to a signed char.
 * So up to 128 user resources are available
 * RES_SCHEDULER has id -1. Stick to signed datatype
 * to avoid unpredictable behavior.
 */
typedef signed char tpl_resource_id;

/*
 * tpl_stack_word is the basic element of a stack
 * the goal is to have a proper data alignement
 */
typedef unsigned long tpl_stack_word;

/*
 * tpl_stack_size is the data type used to store
 * the stack size
 */
typedef unsigned short tpl_stack_size;

/*
 * tpl_buffer is a pointer to a chunk of data in memory
 */
typedef char *tpl_buffer;

#endif
