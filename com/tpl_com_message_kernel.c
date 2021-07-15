/**
 * @file tpl_com_message_kernel.c
 *
 * @section desc File description
 *
 * Communication kernel functions definition
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for a part of function and data structures documentation and
 * for the ARM port
 * Copyright See4sys for hcs12 port
 * Copyright See4sys for v850 port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under a double licence:
 * - the Lesser GNU Public Licence
 * - the BSD licence
 *
 * @section infos File informations
 *
 * $Date:$
 * $Rev:$
 * $Author:$
 * $URL:$
 */

#include "tpl_com_message_kernel.h"

#include "tpl_com_internal.h"
#include "tpl_os_error.h"
#include "tpl_machine.h"
#include "tpl_com_error.h"
#include "tpl_com_base_mo.h"
#include "tpl_com_app_def.h"
#include "tpl_com_errorhook.h" /*added by Florent 090303*/
#include "tpl_os_definitions.h"
#include "tpl_trace.h"

/*#if COM_EXTENDED == YES*/
#include "tpl_com_internal_com.h"
/*#endif*/

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
extern void tpl_get_task_lock(void);
extern void tpl_release_task_lock(void);

FUNC(tpl_status, OS_CODE) tpl_get_message_status_service(
  CONST(tpl_message_id, AUTOMATIC) mess_id)
{
	/*  init the error to no error                  */
  VAR(StatusType, AUTOMATIC) result = E_OK;
	
#if RECEIVE_MESSAGE_COUNT > 0
  P2CONST(tpl_data_receiving_mo, AUTOMATIC, OS_CONST)	rmo = NULL;
	P2CONST(tpl_queue, AUTOMATIC, OS_CONST) queue = NULL;
#endif
	
  /*  lock the task structures                    */
  LOCK_KERNEL()
  
  /*  store information for error hook routine    */
  STORE_COM_SERVICE(COMServiceId_GetMessageStatus)
  STORE_COM_MESSAGE_ID(mess_id)
  
  /*  Check the error                             */
  CHECK_SEND_MESSAGE_ID_ERROR(mess_id,result)
#if RECEIVE_MESSAGE_COUNT > 0
  CHECK_NOT_ZERO_LENGTH_SEND(mess_id,result);
#endif
  /*  Check the error                             */
  CHECK_RECEIVE_MESSAGE_ID_ERROR(mess_id,result)
  
	
#if RECEIVE_MESSAGE_COUNT > 0
	IF_NO_EXTENDED_ERROR(result)
    {
		/*  get the message object from its id			*/          
		rmo = (tpl_data_receiving_mo *)tpl_receive_message_table[mess_id];
		queue = &((tpl_internal_receiving_queued_mo *)rmo)->queue;
		
		/* if message queued							*/
		if( queue->element_size != 0 )
		{
			struct TPL_QUEUE_DYNAMIC    *dq = queue->dyn_desc;
			tpl_com_data    *p = tpl_queue_element_for_read(queue);
			if (p != NULL)
			{
				/* if an overflow occured in the previous sent message */
				if (dq->overflow)
				{
					result =  E_COM_LIMIT;
				}
			}
			else{
    	  result = E_COM_NOMSG;
			}
		}
		else{
			/* if message unqueued						*/
			result =  E_COM_ID;
		}
	}
#endif
  
	PROCESS_GETMESSAGESTATUS_ERROR(result)
	
  UNLOCK_KERNEL()
  
  return result;
	
	
}

FUNC(tpl_status, OS_CODE) tpl_send_message_service(
  CONST(tpl_message_id, AUTOMATIC)   mess_id,
  CONSTP2CONST(void, AUTOMATIC, OS_APPL_DATA)  data)
{
  /*  init the error to no error                  */
  StatusType result = E_OK;
  
#if SEND_MESSAGE_COUNT > 0
  P2CONST(tpl_base_sending_mo, AUTOMATIC, OS_CONST) smo = NULL;
#endif
  
  /*  lock the task structures                    */
  LOCK_KERNEL()
  
  /*  store information for error hook routine    */
  STORE_COM_SERVICE(COMServiceId_SendMessage)
  STORE_COM_MESSAGE_ID(mess_id)
  STORE_COM_APPLICATION_DATA_REF(data)
  
  /*  Check the error                             */
  CHECK_SEND_MESSAGE_ID_ERROR(mess_id,result)
#if SEND_MESSAGE_COUNT > 0
  CHECK_NOT_ZERO_LENGTH_SEND(mess_id,result);
#endif
  
#if SEND_MESSAGE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /*  trace the sending message                    */
    TRACE_MSG_SEND(mess_id,SEND_NONZERO_MESSAGE_KIND);
    /*  get the message object from its id          */
    smo = (tpl_base_sending_mo *)tpl_send_message_table[mess_id];
    /*  call the sending function                   */
    result = smo->sender(smo, data);
  }
#endif
  
  PROCESS_COM_ERROR(result)
  
  UNLOCK_KERNEL()
  
  return result;
}

FUNC(tpl_status, OS_CODE) tpl_receive_message_service(
  CONST(tpl_message_id, AUTOMATIC)  mess_id,
  CONSTP2VAR(void, AUTOMATIC, OS_APPL_DATA) data)
{
  /*  init the error to no error                  */
  VAR(StatusType, AUTOMATIC) result = E_OK;
  
#if RECEIVE_MESSAGE_COUNT > 0
  P2CONST(tpl_data_receiving_mo, AUTOMATIC, OS_CONST) rmo = NULL;
#endif
  
  /*  lock the task structures                    */
  LOCK_KERNEL()
  
  STORE_COM_SERVICE(COMServiceId_ReceiveMessage)
  STORE_COM_MESSAGE_ID(mess_id)
  STORE_COM_APPLICATION_DATA_REF(data)
  
  /*  Check the error                             */
  CHECK_RECEIVE_MESSAGE_ID_ERROR(mess_id,result)
  
#if RECEIVE_MESSAGE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /*  trace                                       */
    TRACE_MSG_RECEIVE(mess_id);
    /*  get the message object from its id          */
    rmo = (tpl_data_receiving_mo *)tpl_receive_message_table[mess_id];
    /*  call the sending function                   */
    result = rmo->copier(data, rmo);
  }
#endif
  
  PROCESS_COM_ERROR(result)
  
  UNLOCK_KERNEL()
  
  return result;
}

FUNC(tpl_status, OS_CODE) tpl_send_zero_message_service(
  CONST(tpl_message_id, AUTOMATIC) mess_id)
{
  /*  init the error to no error                  */
  VAR(StatusType, AUTOMATIC) result = E_OK;
  
#if SEND_MESSAGE_COUNT > 0
  P2CONST(tpl_base_sending_mo, AUTOMATIC, OS_CONST) smo = NULL;
#endif
  
  /*  lock the task structures                    */
  LOCK_KERNEL()
  
  /*  store information for error hook routine    */
  STORE_COM_SERVICE(COMServiceId_SendZeroMessage)
  STORE_COM_MESSAGE_ID(mess_id)
  
  /*  Check the error                             */
  CHECK_SEND_MESSAGE_ID_ERROR(mess_id,result)
#if SEND_MESSAGE_COUNT > 0
  CHECK_ZERO_LENGTH_SEND(mess_id,result)
#endif
	
#if SEND_MESSAGE_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /*  trace the sending message                    */
    TRACE_MSG_SEND(mess_id,SEND_ZERO_MESSAGE_KIND);
    /*  get the message object from its id          */
    smo = (tpl_base_sending_mo *)tpl_send_message_table[mess_id];
    /*  call the sending function                   */
    smo->sender(smo, NULL);
  }
#endif
  
  PROCESS_COM_ERROR(result)
  
  UNLOCK_KERNEL()
  
  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* end of file tpl_com_message_kernel.c */
