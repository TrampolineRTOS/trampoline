/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Internal Communication headers
 *
 * $Date: 2005-03-16 17:07:23 +0100 (Wed, 16 Mar 2005) $
 * $Rev$
 * $Author: jlb $
 * $URL: http://localhost:8888/Trampoline/svn/tpl_internal_com.h $
 */

#ifndef __TPL_INTERNAL_COM_H__
#define __TPL_INTERNAL_COM_H__

#include "tpl_com_types.h"
#include "tpl_os_types.h"

/*
 * Data types
 */
typedef tpl_message_id          MessageIdentifier;
typedef void                    *ApplicationDataRef;
typedef tpl_message_size        COMLengthType;
typedef tpl_message_size        *LengthRef;
typedef tpl_flag_set            FlagValue;
typedef tpl_com_app_mode        COMApplicationModeType;
typedef tpl_com_shut_mode       COMShutdownModeType;
typedef tpl_callout_ret         CalloutReturnType;
typedef tpl_com_srv_id          COMServiceIdType;

/*
 * Declaration
 */
#define DeclareMessage(mess_id) \
  extern CONST(MessageIdentifier, AUTOMATIC) mess_id

/*
 * Start-up services

StatusType StartCOM(COMApplicationModeType);
StatusType StopCOM(COMShutdownModeType);
COMApplicationModeType GetCOMApplicationMode(void);
StatusType InitMessage(MessageIdentifier, ApplicationDataRef);
StatusType StartPeriodic(void);
StatusType StopPeriodic(void);


 * Notification mechanism support services

FlagValue ReadFlag(void);
void ResetFlag(void);


 * Communication services

StatusType SendMessage(MessageIdentifier, ApplicationDataRef);
StatusType ReceiveMessage(MessageIdentifier, ApplicationDataRef);
StatusType SendDynamicMessage(MessageIdentifier, ApplicationDataRef, LengthRef);
StatusType ReceiveDynamicMessage(MessageIdentifier, ApplicationDataRef, LengthRef);
StatusType SendZeroMessage(MessageIdentifier);
StatusType GetMessageStatus(MessageIdentifier);
COMServiceIdType COMErrorGetServiceId(void);
*/

#endif
