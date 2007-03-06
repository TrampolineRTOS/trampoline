/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline internal communication functions declarations.
 * These functions are attached to the message object.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */
 
#ifndef __TPL_COM_INTERNAL_COM__
#define __TPL_COM_INTERNAL_COM__

tpl_status tpl_send_static_internal_message(tpl_base_sending_mo*, tpl_com_data*);
tpl_status tpl_send_zero_internal_message(tpl_base_sending_mo*, tpl_com_data*);
tpl_status tpl_receive_static_internal_unqueued_message(tpl_base_receiving_mo*, tpl_com_data*);
tpl_status tpl_receive_static_internal_queued_message(tpl_base_receiving_mo*,tpl_com_data*);

#endif
/* __TPL_COM_INTERNAL_COM__ */
