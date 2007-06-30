/**
 * @file tpl_os_action.h
 *
 * @section desc File description
 *
 * Trampoline Action implementation. Actions are used for alarm action. They
 * are also used by COM for actions.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"
#include "tpl_os_action.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 *  action function for action call back
 */
tpl_status tpl_action_callback(const tpl_action *action)
{
    /*
     * A tpl_action * is cast to a tpl_callback_action *
     * This violate MISRA rule 45. However, since the
     * first member of tpl_callback_action * is a tpl_action *
     * This cast behaves correctly.
     */
    ((const tpl_callback_action *)action)->callback();
    
    return E_OK;
}

/**
 *  action function for action by task activation
 */
tpl_status tpl_action_activate_task(const tpl_action *action)
{
    /*
     * A tpl_action * is cast to a tpl_task_activation_action *
     * This violate MISRA rule 45. However, since the
     * first member of tpl_task_activation_action * is a tpl_action *
     * This cast behaves correctly.
     */
    return tpl_activate_task(
        ((const tpl_task_activation_action *)action)->task
    );
}

/**
 *  action function for action by setting event
 */
tpl_status tpl_action_setevent(const tpl_action *action)
{
    /*
     * A tpl_action * is cast to a tpl_setevent_action *
     * This violate MISRA rule 45. However, since the
     * first member of tpl_setevent_action * is a tpl_action *
     * This cast behaves correctly.
     */
    return tpl_set_event(
        ((const tpl_setevent_action *)action)->task,
        ((const tpl_setevent_action *)action)->mask
    );
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_action.c */
