/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline internal communication functions. These functions are
 * attached to the message object.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_com_internal_com.h"
#include "tpl_os_definitions.h"
#include "tpl_com_definitions.h"
#include "tpl_com_notification.h"

#if WITH_COM == YES
/**
 * @def INVALID_MESSAGE
 *
 * This value is used to specify an invalid message ID
 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONST(tpl_message_id, AUTOMATIC) INVALID_MESSAGE = SEND_MESSAGE_COUNT;
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * tpl_send_static_internal_message sends a message from an internal only
 * sending message object to a set of internal receiving message objects.
 * this function is attached to the sending message object.
 */ 
FUNC(tpl_status, OS_CODE) tpl_send_static_internal_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       smo,
  CONSTP2CONST(tpl_com_data, AUTOMATIC, OS_VAR) data)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
    
  /*  cast the base mo to the correct type of mo                          */
  CONSTP2CONST(tpl_internal_sending_mo, AUTOMATIC, OS_CONST)
  ismo = smo;
  /*  get the first of the receiving mo                                   */
  P2CONST(tpl_data_receiving_mo, AUTOMATIC, OS_CONST)
  rmo = (tpl_data_receiving_mo *)ismo->internal_target;

  /*  iterate through the receiving mo to copy the data to the receivers  */
  while ((result == E_OK) && (rmo != NULL))
  {
    result = rmo->receiver(rmo, data);
  
    /*
     * Walk along the receiving message object chain and call the notification
     * for each one when the notication exists (and if the message is not 
     * filtered out ).
     */
    if (result == E_OK)
    {
      tpl_action *notification = rmo->base_mo.notification;
      if (notification != NULL)
      {
        notification->action(notification);
      }
    }
    else if (result == E_COM_FILTEREDOUT)
    {
      result = E_OK;
    }
    
    rmo = (tpl_data_receiving_mo *)rmo->base_mo.next_mo;
  }
  
  /*  notify the receivers    */
  tpl_notify_receiving_mos(FROM_TASK_LEVEL);
      
  return result;
}

/*
 * tpl_send_zero_internal_message sends a 0 length message from an internal
 * only sending message object to a set of internal receiving message objects.
 * This function is attached to the sending message object
 */
FUNC(tpl_status, OS_CODE) tpl_send_zero_internal_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       smo,
  CONSTP2CONST(tpl_com_data, AUTOMATIC, OS_VAR) data)
{
  /*  cast the base mo to the correct type of mo  */
  CONSTP2CONST(tpl_internal_sending_mo, AUTOMATIC, OS_CONST)
    ismo = smo;

	P2CONST(tpl_base_receiving_mo, AUTOMATIC, OS_CONST)
  rmo_notification = ismo->internal_target;
	
	/*
     * Walk along the receiving message object chain and call the notification
     * for each one when the notication exists.
     */
	while (rmo_notification != NULL)
  {
		tpl_action *notification = rmo_notification->notification;
		if (notification != NULL)
    {
			notification->action(notification);
		}
		rmo_notification = rmo_notification->next_mo;
  }
	
  /*  notify the receivers                        */
  tpl_notify_receiving_mos(FROM_TASK_LEVEL);
  
  return E_OK;
}

/*
 * tpl_receive_static_internal_unqueued_message get a message from a data
 * buffer and copies it to the buffer of the unqueued message object.
 * This function is attached to the receiving message object.
 */
FUNC(tpl_status, OS_CODE) tpl_receive_static_internal_unqueued_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       rmo,
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR) data)
{
	VAR(tpl_status, AUTOMATIC) result = E_COM_FILTEREDOUT;
	
  /*  cast the base receiving mo to the correct type of mo                */
  CONSTP2CONST(tpl_internal_receiving_unqueued_mo, AUTOMATIC, OS_CONST)
  rum = rmo;
  /*  get the destination buffer                                          */
  P2VAR(tpl_com_data, AUTOMATIC, OS_VAR)
  mo_buf = rum->buffer.buffer;
  
  /*  reception filtering                                                 */
  if (tpl_filtering(mo_buf, data, rum->base_mo.filter))
  {
    /*  get the size of the buffer                                          */
    VAR(int, AUTOMATIC) size = rum->buffer.size;
    result =  E_OK;
    /*  copy the data from the source (data)
     to the message object buffer
     */
    while (size-- > 0)
    {
      *mo_buf++ = *data++;
    }
  }
		
	return result;
}

/*!
 * tpl_receive_static_internal_queued_message get a message from a data
 * buffer and copies it to the buffer of a queued message object.
 * This function is attached to the receiving message object.
 */
FUNC(tpl_status, OS_CODE) tpl_receive_static_internal_queued_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)   rmo,
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR)  data)
{
	VAR(tpl_status, AUTOMATIC) result = E_COM_FILTEREDOUT;
  /* get the queue */
  CONSTP2CONST(tpl_queue, AUTOMATIC, OS_CONST) rq =
    &(((tpl_internal_receiving_queued_mo *)rmo)->queue);
  /* get the dynamic part of the queue */
  CONSTP2VAR(tpl_queue_dyn, AUTOMATIC, OS_VAR)
    dq = rq->dyn_desc;
  /* get the pointer to the last value */
  P2VAR(tpl_com_data, AUTOMATIC, OS_VAR) last = rq->last;
  
  /*
   * filter the message
   */
  if (tpl_filtering(
    last,
    data,
    ((tpl_internal_receiving_queued_mo *)rmo)->base_mo.filter))
  {
    /* destination buffer */
    P2VAR(tpl_com_data, AUTOMATIC, OS_VAR) dst = NULL;
    result = E_OK;
    /* get the buffer to perform the write */
    dst = tpl_queue_element_for_write(rq);
    if (dst != NULL)
    {
      int size = rq->element_size;
      while (size > 0)
      {
        *last++ = *data;
        *dst++ = *data++;
        size--;
      }
      
      /* update the current size of the queue */
      dq->size += rq->element_size;
    }
    else
    {
      dq->overflow = TRUE;
    }
  }
	return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_com_internal_com.c */
