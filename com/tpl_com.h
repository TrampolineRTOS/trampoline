/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline OSEK communication datatypes
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_H__
#define __TPL_COM_H__

#include "tpl_com_private_types.h"
#include "tpl_com_definitions.h"

#ifndef __TPL_INTERNAL_COM_H__
#define __TPL_INTERNAL_COM_H__

typedef tpl_message_id  MessageIdentifier;
typedef void            *ApplicationDataRef;
typedef tpl_flag_value  FlagValue;

StatusType SendMessage(MessageIdentifier mess_id, ApplicationDataRef data);
StatusType ReceiveMessage(MessageIdentifier mess_id, ApplicationDataRef data);
StatusType SendZeroMessage(MessageIdentifier mess_id);

/*	__TPL_INTERNAL_COM_H__	*/
#endif

/*	__TPL_COM_H__	*/
#endif
