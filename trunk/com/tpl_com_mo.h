/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Message Object data structures
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_MO_H__
#define __TPL_COM_MO_H__

#include "tpl_com_base_mo.h"
#include "tpl_com_queue.h"

/*
 * tpl_internal_sending_mo is internal only sending message object
 */
struct TPL_INTERNAL_SENDING_MO {
    /*  common to all sending mo                            */
    tpl_base_sending_mo             base_mo;
    /*  pointer to the internal receiving message object    */
    struct TPL_BASE_RECEIVING_MO    *internal_target;
};

typedef struct TPL_INTERNAL_SENDING_MO tpl_internal_sending_mo;

typedef tpl_internal_sending_mo tpl_internal_sending_zero_mo;

/*!
 *  \struct tpl_internal_receiving_zero_mo
 *
 *  \brief  Structure for internal communication zero length receiving
 *          message objects
 *
 *  Internal communication zero length receiving message object structure
 *  is only an alias of the basic receiving message object since no
 *  buffering is needed.
 */
typedef struct TPL_BASE_RECEIVING_MO tpl_internal_receiving_zero_mo;
 
/*!
 *  \struct TPL_INTERNAL_RECEIVING_UNQUEUED_MO
 *
 *  \brief  Structure for internal communication unqueued receiving
 *          message objects
 *
 *  Internal communication unqueued receiving message object structure
 *  adds members to manage a buffer to store the data of the messages
 *  and a filter descriptor.
 */
struct TPL_INTERNAL_RECEIVING_UNQUEUED_MO {
    /*! common part of the receiving message objects            */
    tpl_data_receiving_mo   base_mo; 
    /*! pointer to the receive buffer                           */
    tpl_com_data            *buffer;
    /*! size of the message object                              */
    tpl_message_size        size;
};

typedef struct TPL_INTERNAL_RECEIVING_UNQUEUED_MO
    tpl_internal_receiving_unqueued_mo;

/*!
 *  \struct TPL_INTERNAL_RECEIVING_QUEUED_MO
 *
 *  \brief  Structure for internal communication queued receiving
 *          message objects
 *
 *  Internal communication queued receiving message object structure
 *  adds members to manage a queue to store the data of the messages
 *  and a filter descriptor.
 */
struct TPL_INTERNAL_RECEIVING_QUEUED_MO {
    /*! common part of the receiving message objects            */
    tpl_data_receiving_mo   base_mo;
    /*! queue                                                   */
    tpl_queue               queue;
};

typedef struct TPL_INTERNAL_RECEIVING_QUEUED_MO
    tpl_internal_receiving_queued_mo;


/*!
 *  Table of sending message objects pointers
 */
extern	tpl_base_sending_mo     *tpl_send_message_table[];

/*!
 *  Table of receiving message objects pointers
 */
extern	tpl_base_receiving_mo   *tpl_receive_message_table[];


#endif
/*  __TPL_COM_MO_H__    */
