/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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

#include "tpl_com_internal_types.h"
#include "tpl_com_definitions.h"

#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)>(y))?(y):(x))

/*
 * Write data in the queue
 */
void tpl_write_queue(tpl_queue *queue, char *data, tpl_message_size size)
{
    char *p;
    
    /*  check the queue is not full */
    if ((queue->max_size - queue->size) >= queue->element_size) {
        /*  compute the pointer where the write will occur */
        p = queue->buffer + (((queue->index + queue->size) < queue->max_size) ?
            (queue->index + queue->size) :
            (queue->index + queue->size - queue->max_size));
        /*  copy the data   */
        size = MIN(size, queue->element_size);
        /*  remember the last data written to the queue (used for filtering)   */
        queue->last = p;
        while (size-- > 0) {
            *p++ = *data++;
        }
        /*  inc the queue size  */
        queue->size += queue->element_size;
    }
}

/*
 * Read data from the queue
 */
void tpl_read_queue(tpl_queue *queue, char *data, tpl_message_size size)
{
    char *p;
    
    /*  check the queue is not empty    */
    if (queue->size > 0) {
        /*  compute the pointer where the read will occur */
        p = queue->buffer + queue->index;
        /*  copy the data   */
        size = MIN(size, queue->element_size);
        while (size-- > 0) {
            *data++ = *p++;
        }
        /*  dec the queue size  */
        queue->size -= queue->element_size;
        /*   adjust the index   */
        ++queue->index;
        if (queue->index > queue->max_size) {
            queue->index = 0;
        }
    }
}

/*
 * tpl_filtering handles the filtering of messages.
 * It takes two data pointers (new_data and old_data), cast the
 * data to the tpl_com_value datatype (should be a 32bits unsigned
 * int and calls the appropriate filter to do the job.
 * if compiled with DATA_ALIGNMENT set, the addresses of new and
 * old data are checked for alignement before casting the
 * pointers
 * If the check failed, tpl_filtering returns TRUE
 */
bool tpl_filtering(
    char                *old_data,
    char                *new_data,
    tpl_message_size    size,
    tpl_filter_param    *param)
{
    /*  two variables to store the old and new value    */
    tpl_com_value   old_value = 0;
    tpl_com_value   new_value = 0;
    /*  Checks there is a filter set */
    if (param->filter != NULL) {
        /*  Checks the data is compatible with filter. Size have
            to be less or equal than the tpl_com_value data size    */
        if (size <= sizeof(tpl_com_value)) {
            /*  get the data    */
            while (size > 0) {
#if ENDIANESS == BIG
                old_value = (old_value << sizeof(char)) | *old_data++;
                new_value = (new_value << sizeof(char)) | *new_data++;
#else
                old_value = (old_value << sizeof(char)) | (*(old_data + size - 1));
                new_value = (new_value << sizeof(char)) | (*(new_data + size - 1));
#endif
                --size;
            }
            /*  Call the filter */
            return param->filter(param, old_value, new_value);
        }
        else {
            return TRUE;
        }
    }
    else {
        return TRUE;
    }
}

/*
 * Transmit functions. These functions are referenced by
 * receiving and/or sending message object to handle the
 * communication according to the type of message object
 */

/*
 * copy data from a static internal message object
 * to a receiving unqueued message object.
 * filtering is done in the process.
 * Returns TRUE if the copy has been done
 * (ie the filter was successfully crossed)
 */
bool tpl_static_to_unqueued(tpl_send_mo *smo, tpl_receive_mo *rmo)
{
    char *s = ((tpl_send_static_internal_mo *)smo)->buffer;
    char *r = ((tpl_receive_unqueued_internal_mo *)rmo)->buffer;
    /*  The size of the receiving message object is used    */
    tpl_message_size size = ((tpl_receive_unqueued_internal_mo *)rmo)->size;
    
    if (tpl_filtering(r,s,size,((tpl_receive_unqueued_internal_mo *)rmo)->filter_param)) {
        /*  filtering is ok for the copy    */
        while (size > 0) {
            *r++ = *s++;
            --size;
        }
        return TRUE;
    }
    else {
        return FALSE;
    }
}

/*
 * copy data from a static internal message object
 * to a receiving queued message object.
 * filtering is done in the process.
 * returns TRUE if the copy has been done
 * (ie the filter was successfully crossed and the queue is not full)
 */
bool tpl_static_to_queued(tpl_send_mo *smo, tpl_receive_mo *rmo)
{
    char *s = ((tpl_send_static_internal_mo *)smo)->buffer;
    char *r;
    tpl_queue *queue = ((tpl_receive_queued_internal_mo *)rmo)->queue;
    
    if (tpl_filtering(queue->last,s,queue->element_size,(tpl_receive_queued_internal_mo *)rmo->filter_param)) {
        /*  check the queue is not full */
        if ((queue->max_size - queue->size) >= queue->element_size) {
            /*  compute the pointer where the write will occur */
            r = queue->buffer + (((queue->index + queue->size) < queue->max_size) ?
                (queue->index + queue->size) :
                (queue->index + queue->size - queue->max_size));
            /*  copy the data   */
           /* à modifier */ size = MIN(size, queue->element_size);
            /*  remember the last data written to the queue (used for filtering the next time)   */
            queue->last = r;
            while (size-- > 0) {
                *r++ = *s++;
            }
            /*  inc the queue size  */
            /* à modifier */ queue->size += queue->element_size;
            
            return TRUE;
        }
        else {
            return FALSE;
        }
    }
    else {
        return FALSE;
    }    
}

/*
 * Receive functions. These functions are referenced by
 * receiving message object to handle the copy of 
 * application data
 */
 
/*
 * Copy the data of an unqueued message object to
 * application data
 */
tpl_status tpl_copy_unqueued(tpl_receive_mo *rmo, tpl_app_data *data)
{
    char    *src = ((tpl_receive_unqueued_internal_mo *)rmo)->buffer;
    tpl_message_size size = ((tpl_receive_unqueued_internal_mo *)rmo)->size;
    
    while (size > 0) {
        *data++ = *src++;
        --size;
    }
    
    return E_OK;
}

/*
 * Copy the data of a queued message object to
 * application data
 */
tpl_status tpl_copy_queued(tpl_receive_mo *rmo, tpl_app_data *data)
{
    char *s;
    tpl_queue *queue = ((tpl_receive_queued_internal_mo *)rmo)->queue;
    tpl_message_size size = ((tpl_receive_queued_internal_mo *)rmo)->size;
    
    /*  check the queue is not empty    */
    if (queue->size > 0) {
        /*  compute the pointer where the read will occur */
        s = queue->buffer + queue->index;
        while (size-- > 0) {
            *data++ = *s++;
        }
        /*  dec the queue size  */
        queue->size -= rmo->size;
        /*   adjust the index   */
        queue->index += rmo->size;
        if (queue->index > rmo->queue->max_size) {
            queue->index = 0;
        }
    }
}