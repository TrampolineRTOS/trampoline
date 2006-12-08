/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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

#include "tpl_os_types.h"
#include "tpl_os_definitions.h"
#include "tpl_com_private_types.h"
#include "tpl_com_mo.h"

void tpl_notify_receiving_mos(tpl_base_receiving_mo *);

/*
 * tpl_send_static_internal_message sends a message from an internal only
 * sending message object to a set of internal receiving message objects.
 * this function is attached to the sending message object.
 */ 
tpl_status tpl_send_static_internal_message(
    tpl_base_sending_mo *smo,
    tpl_com_data        *data
    )
{
    /*  cast the base mo to the correct type of mo                          */
    tpl_internal_sending_mo *ismo = (tpl_internal_sending_mo *)smo;
    /*  get the first of the receiving mo                                   */
    tpl_base_receiving_mo *rmo = ismo->internal_target;
    /*  iterate through the receiving mo to copy the data to the receivers  */
    while (rmo != NULL) {
        rmo->receiver(rmo, data);
        rmo = rmo->next_mo;
    }
    
    /*  notify the receivers    */
    tpl_notify_receiving_mos(ismo->internal_target);
        
    return E_OK;
}

/*
 * tpl_send_zero_internal_message sends a 0 length message from an internal
 * only sending message object to a set of internal receiving message objects.
 * This function is attached to the sending message object
 */
tpl_status tpl_send_zero_internal_message(
    tpl_base_sending_mo     *smo,
    tpl_com_data            *data
    )
{
    /*  cast the base mo to the correct type of mo  */
    tpl_internal_sending_mo *ismo = (tpl_internal_sending_mo *)smo;
    /*  notify the receivers                        */
    tpl_notify_receiving_mos(ismo->internal_target);
    
    return E_OK;
}

/*
 * tpl_receive_static_internal_unqueued_message get a message from a data
 * buffer and copies it to the buffer of the unqueued message object.
 * This function is attached to the receiving message object.
 */
tpl_status tpl_receive_static_internal_unqueued_message(
    tpl_base_receiving_mo   *rmo,
    tpl_com_data            *data
    )
{
    /*  cast the base receiving mo to the correct type of mo                */
    tpl_internal_receiving_unqueued_mo *rum =
        (tpl_internal_receiving_unqueued_mo *)rmo;
    /*  get the destination buffer                                          */
    tpl_com_data *mo_buf = rum->buffer;
    
    /*  reception filtering                                                 */
    if (tpl_filtering
    /*  copy the data from the source (data) to the message object buffer   */
    int size = rum->size;
    while (size-- > 0) {
        *mo_buf++ = *data++;
    }
    
    return E_OK;
}

/*!
 * tpl_receive_static_internal_queued_message get a message from a data
 * buffer and copies it to the buffer of a queued message object.
 * This function is attached to the receiving message object.
 */
tpl_status tpl_receive_static_internal_queued_message(
    tpl_base_receiving_mo   *rmo,
    tpl_application_data    *data
    )
{
    /*  destination buffer                                      */
    tpl_application_data *dst = NULL;
    /*  cast the base receiving mo to the correct type of mo    */
    tpl_queue *rq = (tpl_internal_receiving_queued_mo *)rmo->queue;
    
    /*  get the buffer to perform the write                     */
    if ((dst = tpl_queue_element_for_write(rq)) != NULL) {
        int size = rq->element_size;
        while (size-- > 0) {
            *dst++ = *data++;
        }
        return E_OK;
    }
    else {
        return E_COM_LIMIT;
    }
}
