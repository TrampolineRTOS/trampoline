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
 * $Date: 2011-01-17 19:18:25 +0100 (Lun, 17 jan 2011) $ - $Rev: 1299 $
 * $Author: jlb $
 * $URL: https://trampoline.rts-software.org/svn/trunk/com/tpl_com_message_management.c $
 */

/*#include "Std_Types.h"*/
#include "tpl_ioc_internal_types.h"
#include "tpl_ioc_queue.h"
#include "tpl_os_error.h"
#include "tpl_ioc_kernel.h"
#include "tpl_ioc.h"
#include "tpl_os_kernel.h"
/*#include "tpl_as_definitions.h"*/
/*#include "tpl_as_app_kernel.h"*/

#define API_START_SEC_CODE
#include "tpl_memmap.h"

#if (IOC_QUEUED_COUNT > 0)

FUNC(Std_ReturnType, OS_CODE) IOC_Send(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data)
{
	return tpl_ioc_send_queued_service(ioc_id, ioc_data);
}

FUNC(Std_ReturnType, OS_CODE) IOC_Receive(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data)
{
	return tpl_ioc_receive_queued_service(ioc_id, ioc_data);
}

FUNC(StatusType, OS_CODE) IOC_EmptyQueue(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id)
{
	return tpl_ioc_empty_queue_service(ioc_id);
}

#endif

#if (IOC_UNQUEUED_COUNT > 0)

FUNC(Std_ReturnType, OS_CODE) IOC_Write(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data)
{
	return tpl_ioc_send_unqueued_service(ioc_id, ioc_data);
}

FUNC(StatusType, OS_CODE) IOC_Read(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data)
{
	return tpl_ioc_receive_unqueued_service(ioc_id, ioc_data);
}

FUNC(void, OS_CODE) IOC_Init(void)
{
	return tpl_ioc_init_unqueued();
}

#endif

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_ioc_message_management.c */
