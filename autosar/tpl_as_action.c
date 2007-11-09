/**
 * @file tpl_as_action.c
 *
 * @section descr File description
 *
 * Trampoline autosar extension. extra action to increment
 * a counter. Implementation
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#include "tpl_as_action.h"
#include "tpl_os_alarm_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 *  action function for action by incrementing counter
 */
FUNC(tpl_status, OS_CODE) tpl_action_increment_counter(
    P2CONST(tpl_action, OS_APPL_CONST, AUTOMATIC) action)
{
    /*
     * A tpl_action * is cast to a tpl_increment_counter_action *
     * This violate MISRA rule 45. However, since the
     * first member of tpl_increment_counter_action is a tpl_action
     * This cast behaves correctly.
     */
    return tpl_counter_tick(
        ((const tpl_increment_counter_action *)action)->counter
    );
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_action.c */
