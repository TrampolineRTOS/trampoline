/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Message Object implementation
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os.h"
#include "tpl_com_internal.h"
#include "tpl_os_error.h"
#include "tpl_machine.h"
#include "tpl_com_error.h"
#include "tpl_com_base_mo.h"
#include "tpl_com_app_def.h"
#include "tpl_com_errorhook.h" /*added by Florent 090303*/

/*#if COM_EXTENDED == YES*/
#include "tpl_com_internal_com.h"
/*#endif*/

#include "tpl_com_message_kernel.h"

#define API_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(StatusType, OS_CODE) GetMessageStatus(
  CONST(MessageIdentifier, AUTOMATIC) mess_id)
{
  return tpl_get_message_status_service(mess_id);
}

FUNC(StatusType, OS_CODE) SendMessage(
  CONST(MessageIdentifier, AUTOMATIC)   mess_id,
  CONST(ApplicationDataRef, AUTOMATIC)  data)
{
  return tpl_send_message_service(mess_id, data);
}

FUNC(StatusType, OS_CODE) ReceiveMessage(
  CONST(MessageIdentifier, AUTOMATIC)  mess_id,
  CONST(ApplicationDataRef, AUTOMATIC) data)
{
  return tpl_receive_message_service(mess_id, data);
}

FUNC(StatusType, OS_CODE) SendZeroMessage(
  CONST(MessageIdentifier, AUTOMATIC) mess_id)
{
  return tpl_send_zero_message_service(mess_id);
}

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_com_message_management.c */
