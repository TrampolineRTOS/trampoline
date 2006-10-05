/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Internal Communication Type
 *
 * $Date: 2005-04-07 15:20:19 +0200 (Thu, 07 Apr 2005) $ - $Rev$
 * $Author: jlb $
 * $URL: http://localhost:8888/Trampoline/svn/tpl_com_internal_types.h $
 */

#ifndef __TPL_COM_INTERNAL_PRIVATE_TYPES_H__
#define __TPL_COM_INTERNAL_PRIVATE_TYPES_H__

#include "tpl_com_types.h"
#include "tpl_com_filtering.h"
#include "tpl_com_notification.h"

typedef unsigned char tpl_com_data;

/*
 * Forward declarations
 */
struct TPL_BASE_SENDING_MO;
struct TPL_BASE_RECEIVING_MO;

/*
 * Prototype for sending functions
 */
typedef tpl_status (*tpl_sending_func)(
    struct TPL_BASE_SENDING_MO *,
    tpl_com_data *
);

/*
 * Prototype for receiving functions
 */
typedef tpl_status (*tpl_receiving_func)(
    struct TPL_BASE_RECEIVING_MO *,
    tpl_com_data *
);

/*
 * tpl_base_sending_mo is the base datastructure for internal
 * and external communication message objects.
 */
struct TPL_BASE_SENDING_MO {
    /*  pointer to the sending function  */
    tpl_sending_func    sender;
};

typedef struct TPL_BASE_SENDING_MO tpl_base_sending_mo;

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

/*!
 *  \struct TPL_BASE_RECEIVING_MO
 *
 *  \brief  Basic structure for receiving message objects
 *
 *  There are 3 kinds of receiving message objects for internal communication:
 *  - zero length
 *  - unqueued
 *  - queued
 *
 *  External communication adds receiving IPDU related information to the
 *  internal receiving message objects.
 */
struct TPL_BASE_RECEIVING_MO {
    /*! pointer to the receiving function   */
    tpl_receiving_func              receiver;
    /*! notification structure              */
    tpl_notification                notification;
    /*! message objects chaining            */
    struct TPL_BASE_RECEIVING_MO    *next_mo;
};

typedef struct TPL_BASE_RECEIVING_MO tpl_base_receiving_mo;

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
 *  \struct TPL_DATA_RECEIVING_MO
 *
 *  \brief  Structure for receiving message object that store a data
 *
 *  This structure extends the TPL_BASE_RECEIVING_MO by adding a pointer
 *  a function which is used to copy the message data to the application
 *  data and a filter descriptor for incoming data filtering.
 */
struct TPL_DATA_RECEIVING_MO {
    /*! common part of the receiving message objects            */
    tpl_base_receiving_mo   base_mo;
    /*! pointer to the data copy function                       */
    tpl_data_copy_func      copier;
    /*! filter descriptor                                       */
    tpl_filter_desc         filter;
};

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
    tpl_base_receiving_mo   base_mo; 
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
    tpl_base_receiving_mo   base_mo;
    /*! queue                                                   */
    tpl_queue               *queue;
    /*! filter descriptor                                       */
    tpl_filter_desc         filter;
};

typedef struct TPL_INTERNAL_RECEIVING_QUEUED_MO
tpl_internal_receiving_queued_mo;

#endif
