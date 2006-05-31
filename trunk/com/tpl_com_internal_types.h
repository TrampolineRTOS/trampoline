/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Communication Type
 *
 * $Date: 2005-04-07 15:20:19 +0200 (Thu, 07 Apr 2005) $
 * $Rev$
 * $Author: jlb $
 * $URL: http://localhost:8888/Trampoline/svn/tpl_com_internal_types.h $
 */

#ifndef __TPL_COM_INTERNAL_TYPES_H__
#define __TPL_COM_INTERNAL_TYPES_H__

#include "tpl_com_filtering.h"

typedef unsigned char tpl_com_data;

/*
 * Forward declarations
 */
struct TPL_BASE_SENDING_MO;
struct TPL_BASE_RECEIVING_MO;

/*
 * Prototype for sending function
 */
typedef tpl_status (*tpl_sending_func)(
    struct TPL_BASE_SENDING_MO *,
    tpl_com_data *
);

/*
 * Prototype for receiving function
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

/*
 * tpl_external_sending_mo is external only sending message object
 */
struct TPL_EXTERNAL_SENDING_MO {
    /*  common to all sending mo            */
    tpl_base_sending_mo     base_mo;
    /*  function pointer to the filter      */
    tpl_filter_desc         filter;
    /*  pointer to the buffer               */
    tpl_com_data            *buffer;
    /*  pointer to the IPDU                 */
    tpl_sending_ipdu        *external_target;
    /*  location of the message in the IPDU */
    tpl_ipdu_location       message_location;
};

typedef struct TPL_EXTERNAL_SENDING_MO tpl_external_sending_mo;

/*
 * tpl_internal_external_sending_mo is internal AND external
 * sending message object
 */
struct TPL_INTERNAL_EXTERNAL_SENDING_MO {
    /*  common to all sending mo                            */
    tpl_base_sending_mo             base_mo;
    /*  function pointer to the filter                      */
    tpl_filter                      filter;
    /*  pointer to the buffer                               */
    tpl_com_data                    *buffer;
    /*  pointer to the internal receiving message object    */
    struct TPL_BASE_RECEIVING_MO    *internal_target;
    /*  pointer to the IPDU                                 */
    struct TPL_SENDING_IPDU         *external_target;
};

typedef struct TPL_INTERNAL_EXTERNAL_SENDING_MO
tpl_internal_external_sending_mo;

/*
 * Structures used for queued receiving message objects
 */
struct TPL_QUEUE_DYNAMIC {
    /*  current size of the queue                                       */
    tpl_queue_size          size;
    /*  read index                                                      */
    tpl_queue_index         index;
    /*  pointer to the last written element (used for filtering)        */
    tpl_com_data            *last;
};

struct TPL_QUEUE_STATIC {
    /*  pointer to the dynamic descriptor                               */
    struct TPL_QUEUE_DYNAMIC *dyn_desc;
    /*  max_size of the queue (number of tpl_application_data elements) */
    tpl_queue_size          max_size;
    /*  size of an element of the queue                                 */
    tpl_queue_size          element_size;
    /*  pointer to the beginning of the buffer                          */
    tpl_com_data            *buffer;
};

typedef struct TPL_QUEUE_STATIC tpl_queue;

/*
 * Receiving message object descriptors
 * There is 3 kinds of receiving message objects :
 * - zero length
 * - unqueued
 * - queued
 * as long as a common data structure called tpl_base_receiving_mo 
 */
struct TPL_BASE_RECEIVING_MO {
    /*  pointer to the receiving function   */
    tpl_receiving_func              receiver;
    /*  notification structure              */
    tpl_notification                notification;
    /*  message objects chaining            */
    struct TPL_BASE_RECEIVING_MO    *next_mo;
};

typedef struct TPL_BASE_RECEIVING_MO tpl_base_receiving_mo;

struct TPL_INTERNAL_RECEIVING_UNQUEUED_MO {
    /*  common part of the receiving message objects    */
    tpl_base_receiving_mo   base_mo;
    /*  pointer to the receive buffer                   */
    tpl_com_data            *buffer;
    /*  filtering                                       */
    tpl_filter_desc         filter;
    /*  size of the message object                      */
    tpl_data_size           size;
};

typedef struct TPL_INTERNAL_RECEIVING_UNQUEUED_MO
tpl_internal_receiving_unqueued_mo;

struct TPL_INTERNAL_RECEIVING_QUEUED_MO {
    /*  common part of the receiving message objects    */
    tpl_base_receiving_mo   base_mo;
    /*  queue                                           */
    tpl_queue               *queue;
    /*  filtering                                       */
    tpl_filter_desc         filter;
};

typedef struct TPL_INTERNAL_RECEIVING_QUEUED_MO
tpl_internal_receiving_queued_mo;

#endif
