/**
 * @file tpl_os_action.h
 *
 * @section desc File description
 *
 * Trampoline Action header. Actions are used for alarm action. They are 
 * also used by COM for notifications.
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

#ifndef TPL_OS_ACTION_H
#define TPL_OS_ACTION_H

#include "tpl_os_internal_types.h"

/*!
 *  \brief  Callback action structure
 *
 *  This structure add a callback function pointer to the action base
 *  structure.
 */
struct TPL_CALLBACK_ACTION {
    /*  base action           */
    tpl_action          b_desc;
    /*  callback function pointer   */
    tpl_callback_func   callback;
};

typedef struct TPL_CALLBACK_ACTION
tpl_callback_action;

/*!
 *  \brief  Task activation action structure
 *
 *  This structure add a task descriptor pointer to the action base
 *  structure.
 */
struct TPL_TASK_ACTIVATION_ACTION {
    /*  base action           */
    tpl_action      b_desc;
    /*  task descriptor pointer     */
    tpl_task        *task;
};

typedef struct TPL_TASK_ACTIVATION_ACTION
tpl_task_activation_action ;

/*!
 *  \brief  Set event action structure
 *
 *  This structure add a task descriptor pointer to the action base
 *  structure and an event mask
 */
struct TPL_SETEVENT_ACTION {
    /*  base action           */
    tpl_action          b_desc;
    /*  task descriptor pointer     */
    tpl_task            *task;
    /*  event mask                  */
    tpl_event_mask      mask;
};

typedef struct TPL_SETEVENT_ACTION
tpl_setevent_action;


#define OS_START_SEC_CODE
#include "Memmap.h"

/*
 * Notification functions prototypes
 */
tpl_status tpl_action_callback(const tpl_action *action);
tpl_status tpl_action_activate_task(const tpl_action *action);
tpl_status tpl_action_setevent(const tpl_action *action);

#define OS_STOP_SEC_CODE
#include "Memmap.h"

#endif /*  TPL_OS_ACTION_H  */

/* End of file tpl_os_action.h */
