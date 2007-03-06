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

#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)>(y))?(y):(x))

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
tpl_com_data *tpl_queue_element_for_write(tpl_queue *queue)
{
    struct TPL_QUEUE_DYNAMIC    *dq = queue->dyn_desc;
    unsigned int                offset = dq->index + dq->size;
    
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
tpl_com_data *tpl_queue_element_for_read(tpl_queue *queue)
{
    struct TPL_QUEUE_DYNAMIC    *dq = queue->dyn_desc;
    
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
void tpl_write_queue(
    tpl_queue           *queue,
    tpl_com_data        *data
    )
{
    struct TPL_QUEUE_DYNAMIC    *dq = queue->dyn_desc;
    tpl_message_size            size = queue->element_size;
    unsigned int                offset = dq->index + dq->size;
    tpl_com_data                *p;
    
    /*  check the queue is not full                             */
    if ((queue->max_size - dq->size) >= queue->element_size) {
         /*  compute the pointer where the write will occur     */
        p = queue->buffer + ((offset < queue->max_size) ?
            (offset) :
            (offset - queue->max_size));
        /*  copy the data. remember the last data written
            to the queue (used for filtering)                   */
        dq->last = p;
        while (size-- > 0) {
            *p++ = *data++;
        }
        /*  inc the queue size                                  */
        dq->size += queue->element_size;
    }
}

/*
 * Read data from the queue
 */
void tpl_read_queue(
    tpl_queue           *queue,
    tpl_com_data        *data
    )
{
    struct TPL_QUEUE_DYNAMIC    *dq = queue->dyn_desc;
    tpl_message_size            size = queue->element_size;
    tpl_com_data                *p;
    
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
        ++(dq->index);
        if (dq->index > queue->max_size) {
            dq->index = 0;
        }
    }
}
