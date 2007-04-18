/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
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

#include "tpl_os_action.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_com_base_mo.h"
#include "tpl_com_definitions.h"

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
        tpl_action *notification = rmo->notification;
        if (notification != NULL) {
            notification->action(notification);
        }
        rmo = rmo->next_mo;
    }
	
	tpl_schedule(FROM_TASK_LEVEL);
}
