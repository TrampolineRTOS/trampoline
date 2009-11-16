/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline application receiving functions implementation
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_com_app_copy.h"
#include "tpl_com_mo.h"

/*!
 *  \file
 *  \brief  From receiving message object to application copy functions.
 *
 *  One of the copy functions have to be stored in the copyer
 *  member of the receiving message object according to its kind and
 *  is called indirectly by the ReceiveMessage communication service.
 */

#include "tpl_com_private_types.h"
#include "tpl_os_definitions.h"
#include "tpl_com_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*!
 *  \brief  Copy a message from an unqueued message object
 *          to an application data.
 *
 *  This function is used to copy a message from the buffer of an unqueued
 *  receiving message object to an application data. 
 *
 *  @param  rmo     a pointer to the receiving message object that store
 *                  the message to be copied.
 *  @param  data    a pointer to the application data where the message
 *                  will be copied.
 *  @return         the status code. Since this function cannot fail (provided
 *                  the parameters are ok), it is always E_OK.
 */
FUNC(tpl_status, OS_CODE) tpl_copy_from_unqueued(
  P2VAR(tpl_com_data, AUTOMATIC, OS_APPL_DATA)  data,
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       rmo)
{
  /*  get the source buffer. rmo can be an unqueued internal
      or external message object. rmo is cast to an internal message
      object since the external is an internal with additional members
      at the end of the struct                                            */
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR) mo_buf =
    ((tpl_internal_receiving_unqueued_mo *)rmo)->buffer.buffer;

  /*  copy the data from the source message object buffer
      to the application data                                             */
  VAR(int, AUTOMATIC) size =
    ((tpl_internal_receiving_unqueued_mo *)rmo)->buffer.size;
  while (size-- > 0) {
    *data++ = *mo_buf++;
  }
  
  return E_OK;
}

/*!
 *  \brief  Copy a message from a queued message object
 *          to an application data.
 *
 *  This function is used to copy a message from the queue of a queued
 *  receiving message object to an application data. 
 *
 *  @param  rmo     a pointer to the receiving message object that store
 *                  the message to be copied.
 *  @param  data    a pointer to the application data where the message
 *                  will be copied.
 *  @return         the status code. The status
 *                  code can be E_OK (a message was in the queue), E_COM_NOMSG
 *                  if the queue is empty or E_COM_LIMIT is the queue has
 *                  been overflown. If E_COM_NOMSG is returned, the application
 *                  data is left untouched.
 */
FUNC(tpl_status, OS_CODE) tpl_copy_from_queued(
  P2VAR(tpl_com_data, AUTOMATIC, OS_APPL_DATA)  data,
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)       rmo)
{
  /*  Default result status to E_OK                                       */
  VAR(tpl_status, AUTOMATIC) result = E_OK;

  /*  get the source queue. rmo can be an unqueued internal
      or external message object. rmo is cast to an internal message
      object since the external is an internal with additional members
      at the end of the struct.                                           */
  CONSTP2CONST(tpl_queue, AUTOMATIC, OS_CONST)
  queue = &((tpl_internal_receiving_queued_mo *)rmo)->queue;

  /*  Get the queue dynamic descriptor                                    */
  CONSTP2VAR(struct TPL_QUEUE_DYNAMIC, AUTOMATIC, OS_VAR)
  dq = queue->dyn_desc;

  /*  Get a pointer to the source data                                    */
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR)
  p = tpl_queue_element_for_read(queue);
  
  /*  Do the copy if the pointer is not NULL                              */
  if (p != NULL)
  {
      VAR(tpl_message_size, AUTOMATIC) size = queue->element_size;
      
      while (size-- > 0)
      {
          *data++ = *p++;
      }
      
      /*  dec the queue size  */
      dq->size -= queue->element_size;
      /*   adjust the index   */
      dq->index += queue->element_size;
      
      if (dq->index >= queue->max_size)
      {
          dq->index = 0;
      }
      
  /* if an overflow occured in the previous sent message */
      if (dq->overflow)
      {
          dq->overflow = FALSE;
          result =  E_COM_LIMIT;
      }
  }
  else
  {
      result = E_COM_NOMSG;
  }
  
  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_com_app_copy.c   */
