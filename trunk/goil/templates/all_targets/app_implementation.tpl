#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"
#include "tpl_machine.h"
#include "tpl_os_it.h"
#include "tpl_os_it_kernel.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_action.h"
#include "tpl_com_notification.h"
#include "tpl_com_mo.h"
#include "tpl_com_internal_com.h"
#include "tpl_com_app_copy.h"
#include "tpl_com_filters.h"

#include "$HEADER$"
#include "$OBJ_HEADER$"

/*=============================================================================
 * Definition and initialization of event related defines and structures
 */
$EVENTS$

/*=============================================================================
 * Definition and initialization of Resource related structures
 */
$RESOURCES$

/*=============================================================================
 * Definition and initialization of Task related defines and structures
 */
$TASKS$

/*=============================================================================
 * Definition and initialization of ISR2 related defines and structures
 */
$ISRS$

/*=============================================================================
 * Definition and initialization of Counters related defines and structures
 */
$COUNTERS$

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
$MESSAGES$

/*=============================================================================
 * Definition and initialization of Ready List structures
 */
$READY_LIST$

/* End of file $IMPLEMENTATION$ */
