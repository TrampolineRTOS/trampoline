#ifndef APP_HEADER_H
#define APP_HEADER_H

#include "tpl_app_objects.h"

/*=============================================================================
 * Declaration of event related defines and structures
 */
/*
 * event evt1
 */
#define mask_of_evt1 1
#define evt1 mask_of_evt1



/*=============================================================================
 * Declaration of Resource related defines and structures
 */

#define resource_id_of_r1  0
#define r1  resource_id_of_r1
#define resource_id_of_r2  1
#define r2  resource_id_of_r2


/*=============================================================================
 * Declaration of Task related defines and structures
 */

#define task_id_of_periodicTask  0
#define periodicTask  task_id_of_periodicTask
#define task_id_of_t1  1
#define t1  task_id_of_t1
#define task_id_of_t2  2
#define t2  task_id_of_t2
#define task_id_of_t3  3
#define t3  task_id_of_t3


/*=============================================================================
 * Declaration of ISR2 related defines and structures
 */

#define isr_id_of_trap_SIGUSR1  0
#define trap_SIGUSR1  isr_id_of_trap_SIGUSR1
#define isr_id_of_trap_SIGUSR2  1
#define trap_SIGUSR2  isr_id_of_trap_SIGUSR2


/*=============================================================================
 * Declaration of Counters related defines and structures
 */
#define OSTICKSPERBASE_counter100ms 2
#define OSMAXALLOWEDVALUE_counter100ms 255
#define OSMINCYCLE_counter100ms 1



/*=============================================================================
 * Declaration of Alarm related defines and structures
 */

#define alarm_id_of_alarm1s  0
#define alarm1s  alarm_id_of_alarm1s
#define alarm_id_of_alarmevent  1
#define alarmevent  alarm_id_of_alarmevent


/*=============================================================================
 * Declaration of flags macros
 */
 

/*=============================================================================
 * Declaration of messages identifiers
 */






#ifdef WITH_AUTOSAR
/*=============================================================================
 * Declaration of schedule tables related defines and structures
 */
$SCHEDULETABLES$

/*=============================================================================
 * Declaration of counters ids
 */


#endif

#endif

/* End of file tpl_os_generated_configuration.h */
