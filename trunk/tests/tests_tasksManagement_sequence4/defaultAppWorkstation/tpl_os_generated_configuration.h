#ifndef APP_HEADER_H
#define APP_HEADER_H

#include "tpl_app_objects.h"

/*=============================================================================
 * Declaration of event related defines and structures
 */
/*
 * event Event1
 */
#define mask_of_Event1 1
#define Event1 mask_of_Event1

/*
 * event Event2
 */
#define mask_of_Event2 2
#define Event2 mask_of_Event2


/*=============================================================================
 * Declaration of Resource related defines and structures
 */


/*=============================================================================
 * Declaration of Task related defines and structures
 */

#define task_id_of_t1  0
#define t1  task_id_of_t1
#define task_id_of_t2  1
#define t2  task_id_of_t2


/*=============================================================================
 * Declaration of ISR2 related defines and structures
 */


/*=============================================================================
 * Declaration of Counters related defines and structures
 */


/*=============================================================================
 * Declaration of Alarm related defines and structures
 */


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
