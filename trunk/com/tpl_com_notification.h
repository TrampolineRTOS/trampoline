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

/*
 * Notification structure
 */
struct TPL_NOTIFICATION {
	tpl_notification_func	notif;
	union {
        tpl_callback_func   callback;
        tpl_task            *task;
        tpl_flag_set        flags;
    }   task_callback_or_flag;
    tpl_event_mask          mask;
};

typedef struct TPL_NOTIFICATION tpl_notification;

/*  __TPL_COM_NOTIFICATION_H__  */
#endif
