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


/*!
 *  Notification function for notification call back
 */
void tpl_notify_callback(tpl_notification *notification)
{
    notification->task_callback_or_flag.callback();
}

/*!
 *  Notification function for flag raising
 */
void tpl_notify_raise_flag(tpl_notification *notification)
{
    notification->task_callback_or_flag.flags = COM_TRUE;
}

/*
 * tpl_handle_notification handles the notification according
 * to its kind
 */
void tpl_handle_notification(tpl_notification *notification)
{
    if (notification != NULL) {
        switch (notification->kind) {
            case NOTIFICATION_CALLBACK:
                /*  call the call back function */
                notification->task_callback_or_flag_ptr.callback();
                break;
            case NOTIFICATION_FLAG:
                /*  set the flag to COM_TRUE    */
                notification->task_callback_or_flag_ptr->flag = COM_TRUE;
                break;
            case NOTIFICATION_TASK:
            /*  activate the task   */
                tpl_get_task_lock();
                tpl_activate_task(notification->task_callback_or_flag_ptr.task);
                tpl_release_task_lock();
                break;
            case NOTIFICATION_EVENT:
                /*  set the event   */
                tpl_get_task_lock();
                tpl_set_event(
                    notification->task_callback_or_flag_ptr.task,
                    notification->mask);
                tpl_release_task_lock();
                break;
        }
    }
}

/*!
 *  \brief
 *
 *
 */
void tpl_notify_receiving_mos(tpl_base_receiving_mo *rmo)
{
    /*
     * Walk along the receiving message object chain and call the notification
     * for each one. During that, the rescheduling is locked
     */
    tpl_lock_scheduling();
    
    while (rmo != NULL) {
        rmo->notification.notif(&rmo->notification);
    }
}
