/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Communication kernel implementation
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_definitions.h"
#include "tpl_com_definitions.h"
#include "tpl_com_queue.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*!
 *  \brief  Returns a pointer to the queue element that
 *          is available for a write operation
 *
 *  @param  queue   pointer to a queue
 *
 *  @return         a pointer of the available element
 *                  for write in the queue or NULL if there
 *                  is no space.    
 */
FUNC(tpl_com_data, OS_CODE) *tpl_queue_element_for_write(
  CONSTP2CONST(tpl_queue, AUTOMATIC, OS_CONST) queue)
{
  CONSTP2CONST(tpl_queue_dyn, AUTOMATIC, OS_VAR) dq = queue->dyn_desc;
  CONST(uint32, AUTOMATIC) offset = dq->index + dq->size;
  
  /*  check the queue is not full */
  if ((queue->max_size - dq->size) >= queue->element_size) {
    /*  return the pointer where the write will occur */
    return queue->buffer +
      ((offset < queue->max_size) ?
      (offset) :
      (offset - queue->max_size));
  }
  else {
    return NULL;
  }
}

/*
 * Return a pointer in a queue for a read
 */
FUNC(tpl_com_data, OS_CODE) *tpl_queue_element_for_read(
  CONSTP2CONST(tpl_queue, AUTOMATIC, OS_CONST) queue)
{
  CONSTP2CONST(tpl_queue_dyn, AUTOMATIC, OS_VAR) dq = queue->dyn_desc;
  
  /*  check the queue is not empty    */
  if (dq->size > 0) {
    /*  compute the pointer where the read would occur */
    return queue->buffer + dq->index;
  }
  else {
    return NULL;
  }
}

/*
 * Write data in the queue
 */
FUNC(void, OS_CODE) tpl_write_queue(
  CONSTP2CONST(tpl_queue, AUTOMATIC, OS_CONST) queue,
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR)     data)
{
  CONSTP2VAR(tpl_queue_dyn, AUTOMATIC, OS_VAR)  dq = queue->dyn_desc;
  VAR(tpl_message_size, AUTOMATIC)              size = queue->element_size;
  CONST(uint32, AUTOMATIC)                      offset = dq->index + dq->size;
  P2VAR(tpl_com_data, AUTOMATIC, OS_VAR)        last = queue->last;
  P2VAR(tpl_com_data, AUTOMATIC, OS_VAR)        p;
  
  /*  check the queue is not full                             */
  if ((queue->max_size - dq->size) >= queue->element_size) {
     /*  compute the pointer where the write will occur     */
    p = queue->buffer + ((offset < queue->max_size) ?
      (offset) :
      (offset - queue->max_size));
    /*  copy the data. remember the last data written
        to the queue (used for filtering)                   */
    while (size-- > 0) {
      *last++ = *data;
      *p++ = *data++;
    }
    /*  inc the queue size                                  */
    dq->size += queue->element_size;
  }
}

/*
 * Read data from the queue
 */
FUNC(void, OS_CODE) tpl_read_queue(
  CONSTP2CONST(tpl_queue, AUTOMATIC, OS_CONST) queue,
  P2VAR(tpl_com_data, AUTOMATIC, OS_VAR)       data)
{
  CONSTP2VAR(tpl_queue_dyn, AUTOMATIC, OS_VAR)  dq = queue->dyn_desc;
  VAR(tpl_message_size, AUTOMATIC)              size = queue->element_size;
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR)      p;
  
  /*  check the queue is not empty    */
  if (dq->size > 0) {
    /*  compute the pointer where the read will occur */
    p = queue->buffer + dq->index;
    /*  copy the data   */
    while (size-- > 0) {
      *data++ = *p++;
    }
    /*  dec the queue size  */
    dq->size -= queue->element_size;
    /*   adjust the index   */
    dq->index += queue->element_size;
    if (dq->index > queue->max_size) {
      dq->index = 0;
    }
  }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_com_queue.c */
