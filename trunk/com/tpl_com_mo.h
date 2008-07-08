/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
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
#include "tpl_com_buffer.h"

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
 *  \struct TPL_RECEIVING_UNQUEUED_MO
 *
 *  \brief  Structure for internal communication unqueued receiving
 *          message objects
 *
 *  Internal communication unqueued receiving message object structure
 *  adds members to manage a buffer to store the data of the messages
 *  and a filter descriptor.
 */
struct TPL_RECEIVING_UNQUEUED_MO {
    /*! common part of the receiving message objects            */
    tpl_data_receiving_mo   base_mo; 
    /*! receive buffer                                          */
    tpl_com_buffer          buffer;
};

typedef struct TPL_RECEIVING_UNQUEUED_MO
    tpl_receiving_unqueued_mo;

typedef struct TPL_RECEIVING_UNQUEUED_MO
    tpl_internal_receiving_unqueued_mo;

/*!
 *  \struct TPL_RECEIVING_QUEUED_MO
 *
 *  \brief  Structure for internal communication queued receiving
 *          message objects
 *
 *  Internal communication queued receiving message object structure
 *  adds members to manage a queue to store the data of the messages
 *  and a filter descriptor.
 */
struct TPL_RECEIVING_QUEUED_MO {
    /*! common part of the data receiving message objects       */
    tpl_data_receiving_mo   base_mo;
    /*! queue                                                   */
    tpl_queue               queue;
};

typedef struct TPL_RECEIVING_QUEUED_MO
    tpl_receiving_queued_mo;
    
typedef struct TPL_RECEIVING_QUEUED_MO
    tpl_internal_receiving_queued_mo;

/**
 *  @typedef    TPL_EXTERNAL_RECEIVING_UNQUEUED_MO
 *
 *  @brief  Structure for external communication unqueued receiving
 *          message objects
 *
 *  External communication unqueued receiving message objects structure
 *  adds members to manage a buffer to store the data of the messages
 *  and a filter descriptor.
 */
typedef struct TPL_RECEIVING_UNQUEUED_MO
    tpl_external_receiving_unqueued_mo;
 
#endif
/*  __TPL_COM_MO_H__    */
