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

/*
 * tpl_send_static_internal_message sends a message from an internal only
 * sending message object to a set of internal receiving message objects.
 * this function is attached to the sending message object.
 */ 
tpl_status tpl_send_static_internal_message(
    void          *smo,
    tpl_com_data  *data
    )
{
  tpl_status result = E_OK;
	tpl_status result_notification = E_OK;
    
  /*  cast the base mo to the correct type of mo                          */
  tpl_internal_sending_mo *ismo = smo;
  /*  get the first of the receiving mo                                   */
  tpl_data_receiving_mo *rmo = (tpl_data_receiving_mo *)ismo->internal_target;
	tpl_base_receiving_mo *rmo_notification = (tpl_base_receiving_mo *)ismo->internal_target;
	
  /*  iterate through the receiving mo to copy the data to the receivers  */
  while ((result == E_OK || result == E_COM_FILTEREDOUT) && (rmo != NULL))
  {
    result = rmo->receiver(rmo, data);
  
    /*
     * Walk along the receiving message object chain and call the notification
     * for each one when the notication exists (and if the message is not 
     * filtered out ).
     */
    if (result == E_OK)
    {
      tpl_action *notification = rmo_notification->notification;
      if (notification != NULL)
      {
        result_notification |= notification->action(notification);
      }
    }
    else if (result == E_COM_FILTEREDOUT)
    {
      result = E_OK;
    }
    rmo_notification = rmo_notification->next_mo;
  
    rmo = (tpl_data_receiving_mo *)rmo->base_mo.next_mo;
  }
  
  /*  notify the receivers    */
  tpl_notify_receiving_mos(result_notification, FROM_TASK_LEVEL);
      
  return result;
}

/*
 * tpl_send_zero_internal_message sends a 0 length message from an internal
 * only sending message object to a set of internal receiving message objects.
 * This function is attached to the sending message object
 */
tpl_status tpl_send_zero_internal_message(
    void          *smo,
    tpl_com_data  *data
    )
{
  /*  cast the base mo to the correct type of mo  */
  tpl_internal_sending_mo *ismo = smo;
	
	tpl_status result_notification = E_OK;
	tpl_base_receiving_mo *rmo_notification = ismo->internal_target;
	
	/*
     * Walk along the receiving message object chain and call the notification
     * for each one when the notication exists.
     */
	while (rmo_notification != NULL)
  {
		tpl_action *notification = rmo_notification->notification;
		if (notification != NULL)
    {
			result_notification |= notification->action(notification);
		}
		rmo_notification = rmo_notification->next_mo;
  }
	
  /*  notify the receivers                        */
  tpl_notify_receiving_mos(result_notification, FROM_TASK_LEVEL);
  
  return E_OK;
}

/*
 * tpl_receive_static_internal_unqueued_message get a message from a data
 * buffer and copies it to the buffer of the unqueued message object.
 * This function is attached to the receiving message object.
 */
tpl_status tpl_receive_static_internal_unqueued_message(
    void          *rmo,
    tpl_com_data  *data
    )
{
	tpl_status result = E_COM_FILTEREDOUT;
	
  /*  cast the base receiving mo to the correct type of mo                */
  tpl_internal_receiving_unqueued_mo *rum = rmo;
  /*  get the destination buffer                                          */
  tpl_com_data *mo_buf = rum->buffer.buffer;
  /*  get the size of the buffer                                          */
  int size = rum->buffer.size;
  
  /*  reception filtering                                                 */
  if (tpl_filtering(mo_buf, data, size, rum->base_mo.filter))
  {
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
tpl_status tpl_receive_static_internal_queued_message(
    void          *rmo,
    tpl_com_data  *data
    )
{
  /*  destination buffer                                      */
  tpl_com_data *dst = NULL;
  /*  cast the base receiving mo to the correct type of mo    */
  tpl_queue *rq = &(((tpl_internal_receiving_queued_mo *)rmo)->queue);
  /*  get the dynamic part of the queue                       */
  struct TPL_QUEUE_DYNAMIC    *dq = rq->dyn_desc;
  
  /*  get the buffer to perform the write                     */
  dst = tpl_queue_element_for_write(rq);
  if (dst != NULL)
  {
      int size = rq->element_size;
      while (size > 0)
      {
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
	return E_OK;
}
