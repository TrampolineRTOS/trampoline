#ifndef APP_HEADER_H
#define APP_HEADER_H

#include "tpl_app_objects.h"

/*=============================================================================
 * Declaration of event related defines and structures
 */
$EVENTS$

/*=============================================================================
 * Declaration of Resource related defines and structures
 */
$RESOURCES$

/*=============================================================================
 * Declaration of Task related defines and structures
 */
$TASKS$

/*=============================================================================
 * Declaration of ISR2 related defines and structures
 */
$ISRS$

/*=============================================================================
 * Declaration of Counters related defines and structures
 */
$COUNTERS$

/*=============================================================================
 * Declaration of Alarm related defines and structures
 */
$ALARMS$

/*=============================================================================
 * Declaration of flags macros
 */
$FLAGSMACROS$ 

/*=============================================================================
 * Declaration of messages identifiers
 */
$MESSAGES$

#ifdef WITH_AUTOSAR
/*=============================================================================
 * Declaration of schedule tables related defines and structures
 */
$SCHEDULETABLES$

/*=============================================================================
 * Declaration of counters ids
 */
$COUNTERSIDS$

#endif

#endif

/* End of file $HEADER$ */
