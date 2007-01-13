/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline notification implementation.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_com_notification.h"
#include "tpl_com_base_mo.h"
#include "tpl_os_definitions.h"
#include "tpl_com_definitions.h"

void tpl_schedule(int);
tpl_status tpl_activate_task(tpl_task *);
tpl_status tpl_set_event(tpl_task *, tpl_event_mask);


/*!
 *  Notification function for notification call back
 */
void tpl_notify_callback(tpl_notification *notification)
{
    ((tpl_callback_notification *)notification)->callback();
}

/*!
 *  Notification function for notification by task activation
 */
void tpl_notify_activate_task(tpl_notification *notification)
{
    tpl_activate_task(
        ((tpl_task_activation_notification *)notification)->task
    );
}

/*!
 *  Notification function for notification by task activation
 */
void tpl_notify_setevent(tpl_notification *notification)
{
    tpl_set_event(
        ((tpl_setevent_notification *)notification)->task,
        ((tpl_setevent_notification *)notification)->mask
    );
}

/*!
 *  Notification function for flag raising
 */
/*void tpl_notify_raise_flag(tpl_notification *notification)
{
    notification->task_callback_or_flag.flag();
}*/

/*!
 *  \brief
 *
 *
 */
void tpl_notify_receiving_mos(tpl_base_receiving_mo *rmo)
{
    /*
     * Walk along the receiving message object chain and call the notification
     * for each one when the notication exists.
     */
    while (rmo != NULL) {
        tpl_notification *notification = rmo->notification;
        if (notification != NULL) {
            notification->notif(notification);
        }
        rmo = rmo->next_mo;
    }
	
	tpl_schedule(FROM_TASK_LEVEL);
}
