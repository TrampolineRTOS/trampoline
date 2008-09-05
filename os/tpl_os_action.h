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
    /*  base action                 */
    VAR(tpl_action, TYPEDEF)        b_desc;
    /*  callback function pointer   */
    VAR(tpl_callback_func, TYPEDEF) callback;
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
    /*  base action                 */
    VAR(tpl_action, TYPEDEF)                b_desc;
    /*  task descriptor pointer     */
    P2VAR(tpl_task, TYPEDEF, OS_APPL_DATA)  task;
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
    /*  base action                 */
    VAR(tpl_action, TYPEDEF)                b_desc;
    /*  task descriptor pointer     */
    P2VAR(tpl_task, TYPEDEF, OS_APPL_DATA)  task;
    /*  event mask                  */
    VAR(tpl_event_mask, TYPEDEF)            mask;
};

typedef struct TPL_SETEVENT_ACTION
tpl_setevent_action;


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Notification functions prototypes
 */
FUNC(tpl_status, OS_CODE) tpl_action_callback(
    P2CONST(tpl_action, AUTOMATIC, OS_APPL_CONST) action
);
FUNC(tpl_status, OS_CODE) tpl_action_activate_task(
    P2CONST(tpl_action, AUTOMATIC, OS_APPL_CONST) action
);
FUNC(tpl_status, OS_CODE) tpl_action_setevent(
    P2CONST(tpl_action, AUTOMATIC, OS_APPL_CONST) action
);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /*  TPL_OS_ACTION_H  */

/* End of file tpl_os_action.h */
