/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline notification header.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_NOTIFICATION_H__
#define __TPL_COM_NOTIFICATION_H__

#include "tpl_os_internal_types.h"
#include "tpl_com_private_types.h"

#define NOTIFICATION_CALLBACK   0
#define NOTIFICATION_FLAG       1
#define NOTIFICATION_TASK       2
#define NOTIFICATION_EVENT      3

struct TPL_NOTIFICATION;

/*
 * Prototype for notification functions
 */
typedef void (*tpl_notification_func)(
    struct TPL_NOTIFICATION *
);

/*!
 *  \brief  Notification base structure
 *
 *  This structure contains the pointer to the notification function only.
 *  It is the common part for the notification descriptor structures and is
 *  extended to add the notification parameters.
 */
struct TPL_NOTIFICATION {
    /*  Notification function pointer   */
	tpl_notification_func	notif;
};

typedef struct TPL_NOTIFICATION tpl_notification;

/*!
 *  \brief  Callback notification structure
 *
 *  This structure add a callback function pointer to the notification base
 *  structure.
 */
struct TPL_CALLBACK_NOTIFICATION {
    /*  base notification           */
    tpl_notification    b_desc;
    /*  callback function pointer   */
    tpl_callback_func   callback;
};

typedef struct TPL_CALLBACK_NOTIFICATION
tpl_callback_notification;

/*!
 *  \brief  Task activation notification structure
 *
 *  This structure add a task descriptor pointer to the notification base
 *  structure.
 */
struct TPL_TASK_ACTIVATION_NOTIFICATION {
    /*  base notification           */
    tpl_notification    b_desc;
    /*  task descriptor pointer     */
    tpl_task            *task;
};

typedef struct TPL_TASK_ACTIVATION_NOTIFICATION
tpl_task_activation_notification ;

/*!
 *  \brief  Set event notification structure
 *
 *  This structure add a task descriptor pointer to the notification base
 *  structure and an event mask
 */
struct TPL_SETEVENT_NOTIFICATION {
    /*  base notification           */
    tpl_notification    b_desc;
    /*  task descriptor pointer     */
    tpl_task            *task;
    /*  event mask                  */
    tpl_event_mask          mask;
};

typedef struct TPL_SETEVENT_NOTIFICATION
tpl_setevent_notification;

/*  __TPL_COM_NOTIFICATION_H__  */
#endif
