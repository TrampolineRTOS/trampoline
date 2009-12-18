#include "tpl_os_internal_types.h"
#include "tpl_machine.h"
#include "tpl_os_it.h"
#include "tpl_os_it_kernel.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_alarm.h"
#include "tpl_os_rez_kernel.h"
#include "tpl_os_rez.h"
#include "tpl_os_event_kernel.h"
#include "tpl_os_event.h"
#include "tpl_os_action.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"

/*#ifndef WITH_AUTOSAR*/
#if WITH_COM == YES
#include "tpl_com_notification.h"
#include "tpl_com_mo.h"
#include "tpl_com_internal.h"
#include "tpl_com_internal_com.h"
#include "tpl_com_external_com.h"
#include "tpl_com_app_copy.h"
#include "tpl_com_filters.h"
#endif
/*#endif*/

#include "$HEADER$"
#include "$OBJ_HEADER$"

#ifdef WITH_AUTOSAR
#include "tpl_as_schedtable.h"
#include "tpl_as_st_kernel.h"
#include "tpl_as_action.h"
#include "tpl_as_isr_kernel.h"
#include "tpl_as_isr.h"
#include "tpl_as_counter.h"
#include "tpl_as_app_kernel.h"
#include "tpl_as_trusted_fct.h"
#include "tpl_as_trusted_fct_kernel.h"
#include "tpl_as_application.h"
#endif

/* #include "Application_types.h" */

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*=============================================================================
 * Declaration of event masks
 */
$EVENTS$

/*=============================================================================
 * Declaration of Resource IDs
 */
$REZIDS$

/*=============================================================================
 * Declaration of Task IDs
 */
$PROCIDS$

/*=============================================================================
 * Declaration of Alarm IDs
 */
$ALARMIDS$

/*=============================================================================
 * Declaration of Counter IDs
 */
#ifdef WITH_AUTOSAR
$COUNTERIDS$
#endif

/*=============================================================================
 * Declaration of messages IDs
 */
$MESSAGEIDS$

/*=============================================================================
 * Declaration of Scheduletables IDs
 */
#ifdef WITH_AUTOSAR
$SCHEDTABLEIDS$
#endif

/*=============================================================================
 * Declaration of OS Application IDs
 */
#ifdef WITH_AUTOSAR
$OSAPPIDS$

$TRUSTED_IDS$
#endif

#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Definition and initialization of Resource related structures
 */
$RESOURCES$

/*=============================================================================
 * Definition and initialization of Counters related defines and structures
 */
$COUNTERS$

/*=============================================================================
 * Definition and initialization of Task related defines and structures
 */
$TASKS$

/*=============================================================================
 * Definition and initialization of ISR2 related defines and structures
 */
$ISRS$

#if WITH_IT_TABLE == YES
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
$IT_TABLE$
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
#endif

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*=============================================================================
 * Definition and initialization of process tables (tasks and isrs)
 */
$PROC_STATIC_TABLE$

$PROC_DYNAMIC_TABLE$

#if EXTENDED_TASK_COUNT > 0
$TASK_EVENTS_TABLE$
#endif

#if ISR_COUNT > 0
$ISR_HELPER_TABLE$

#ifdef WITH_AUTOSAR
$ISR_ENABLE_TABLE$
#endif

#endif

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Definition and initialization of Alarm related structures
 */
$ALARMS$

/*=============================================================================
 * Declaration of flags functions
 */
$FLAGSFUNCTIONS$

/*=============================================================================
 * Definition and initialization of Messages related structures
 */
$NETWORKMESSAGES$
$MESSAGES$

#ifdef WITH_AUTOSAR
/*=============================================================================
 * Declaration of schedule tables related defines and structures
 */
$SCHEDULETABLES$

/*=============================================================================
 * Declaration of OS applications related defines and structures
 */
$OSAPPLICATIONS$

/*=============================================================================
 * Declaration of Trusted Functions table
 */
$TRUSTED_FCTS$

$TRUSTED_TABLE$
#endif

#if WITH_MEMORY_PROTECTION == YES
$MEMORY_PROTECTION$
#endif

/*=============================================================================
 * Definition and initialization of Ready List structures
 */
$READY_LIST$

$PROC_NAMES$

/*
#if CRC_LEVEL > 0
$CRC_TABLE$
#endif
*/

/* End of file $IMPLEMENTATION$ */
