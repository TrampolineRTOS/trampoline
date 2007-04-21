/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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
tpl_status tpl_copy_from_unqueued(
    tpl_com_data            *data,
    tpl_data_receiving_mo   *rmo
    )
{
    /*  get the source buffer. rmo can be an unqueued internal
        or external message object. rmo is cast to an internal message
        object since the external is an internal with additional members
        at the end of the struct                                            */
    tpl_com_data *mo_buf = ((tpl_internal_receiving_unqueued_mo *)rmo)->buffer;

    /*  copy the data from the source message object buffer
        to the application data                                             */
    int size = ((tpl_internal_receiving_unqueued_mo *)rmo)->size;
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
tpl_status tpl_copy_from_queued(
    tpl_com_data            *data,
    tpl_data_receiving_mo   *rmo
    )
{
    /*  Default result status to E_OK                                       */
    tpl_status  result = E_OK;

    /*  get the source queue. rmo can be an unqueued internal
        or external message object. rmo is cast to an internal message
        object since the external is an internal with additional members
        at the end of the struct.                                           */
    tpl_queue   *queue = &((tpl_internal_receiving_queued_mo *)rmo)->queue;

    /*  Get the queue dynamic descriptor                                    */
    struct TPL_QUEUE_DYNAMIC    *dq = queue->dyn_desc;

    /*  Get a pointer to the source data                                    */
    tpl_com_data    *p = tpl_queue_element_for_read(queue);
    
    /*  Do the copy if the pointer is not NULL                              */
    if (p != NULL)
    {
        tpl_message_size    size = queue->element_size;
        
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

/* End of file tpl_com_app_copy.c   */
