/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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

/*
 * Data types
 */
typedef tpl_message_id          MessageIdentifier;
typedef tpl_com_data            *ApplicationDataRef;
typedef tpl_com_length          COMLengthType;
typedef tpl_com_length          *LengthRef;
typedef tpl_flag                FlagValue;
typedef tpl_com_app_mode        COMApplicationModeType;
typedef tpl_com_shut_mode       COMShutdownModeType;
typedef tpl_callout_ret         CalloutReturnType;
typedef tpl_com_srv_id          COMServiceIdType;

/*
 * Start-up services
 */
StatusType StartCOM(COMAppicationModeType);
StatusType StopCOM(COMShutdownModeType);
COMApplicationModeType GetCOMApplicationMode(void);
StatusType InitMessage(MessageIdentifier, ApplicationDataRef);
StatusType StartPeriodic(void);
StatusType StopPeriodic(void);

/*
 * Notification mechanism support services
 */
FlagValue ReadFlag(void);
void ResetFlag(void);

/*
 * Communication services
 */
StatusType SendMessage(MessageIdentifier, ApplicationDataRef);
StatusType ReceiveMessage(MessageIdentifier, ApplicationDataRef);
StatusType SendDynamicMessage(MessageIdentifier, ApplicationDataRef, LengthRef);
StatusType ReceiveDynamicMessage(MessageIdentifier, ApplicationDataRef, LengthRef);
StatusType SendZeroMessage(MessageIdentifier);
StatusType GetMessageStatus(MessageIdentifier);
COMServiceIdType COMErrorGetServiceId(void);


#endif