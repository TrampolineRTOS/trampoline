/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline AUTOSAR IOC queue implementation
 *
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */
/* MISRA RULE 3.1 VIOLATION: special character is used in comments for svn integration, the code can survive to this ! */

#include "tpl_ioc_queue.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*!
 *  \brief  Returns a pointer to the queue element that
 *          is available for a write operation
 *          and adjust queue size
 *
 *  @param  queue   pointer to a queue
 *
 *  @return         a pointer of the available element
 *                  for write in the queue or NULL if there
 *                  is no space.
 */
FUNC(tpl_ioc_buffer, OS_CODE) tpl_ioc_queue_element_for_write(
  CONSTP2CONST(tpl_ioc_queue, AUTOMATIC, OS_CONST) queue)
{
  CONSTP2VAR(tpl_ioc_queue_dyn, AUTOMATIC, OS_VAR)  dq = queue->dyn_desc;
  P2VAR(tpl_ioc_data, AUTOMATIC, OS_VAR)            p=NULL;
  CONST(uint32, AUTOMATIC)                          offset = dq->index + dq->size;


  /*  check the queue is not full                             */
  if((queue->max_size - dq->size) >= queue->element_size)
  {
     /*  compute the pointer where the write will occur     */
    if(offset < queue->max_size)
    {
      /* MISRA RULE 17.4 VIOLATION: performing pointer aritmetic here,
         this is the fastest and most readable way to manage the buffer.
         Furthermore the offset value is checked to be in bounds, this is safe. */
      p = (queue->buffer) + offset;
    }
    else
    {
      /* MISRA RULE 17.4 VIOLATION: performing pointer aritmetic here,
         this is the fastest and most readable way to manage the buffer.
         Furthermore the offset value is checked to be in bounds, this is safe. */
      p = ((queue->buffer) + offset) - (queue->max_size);
    }

    /*  inc the queue size                                  */
    dq->size += (tpl_ioc_queue_size)queue->element_size;

  }

  return p;
}


/*!
 *  \brief  Return a pointer in a queue for a read
 *          and adjust current queue size
 *
 *  @param  queue   pointer to a queue
 *
 *  @return         a pointer of the available element
 *                  for read in the queue or NULL if there
 *                  is nothing in the queue.
 */
FUNC(tpl_ioc_buffer, OS_CODE) tpl_ioc_queue_element_for_read(
  CONSTP2CONST(tpl_ioc_queue, AUTOMATIC, OS_CONST) queue)
{
  CONSTP2VAR(tpl_ioc_queue_dyn, AUTOMATIC, OS_VAR)  dq = queue->dyn_desc;
  P2VAR(tpl_ioc_data, AUTOMATIC, OS_VAR)            p=NULL;

  /*  check the queue is not empty    */
  if(dq->size > 0)
  {
    /*  compute the pointer where the read will occur */
    /* MISRA RULE 17.4 VIOLATION: performing pointer aritmetic here,
       this is the fastest and most readable way to manage the buffer.
       Furthermore the offset value is checked to be in bounds, this is safe. */
    p = (queue->buffer) + (dq->index);

    /*  dec the queue size  */
    dq->size -= (tpl_ioc_queue_size)queue->element_size;
    /*   adjust the index   */
    dq->index += (tpl_ioc_queue_size)queue->element_size;
    if (dq->index >= queue->max_size)
    {
      dq->index = 0;
    }
  }

  return p;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_ioc_queue.c */
