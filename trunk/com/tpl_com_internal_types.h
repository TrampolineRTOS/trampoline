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

#include "tpl_com_types.h"

/*
 * Prototype for sending function
 */
typedef tpl_status (*tpl_sending_func)(
    struct TPL_BASE_SENDING_MO *,
    tpl_appication_data *
);

/*
 * Prototype for receiving function
 */
typedef tpl_status (*tpl_receiving_func)(
    struct TPL_BASE_RECEIVING_MO *,
    tpl_application_data *
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
    tpl_filter              filter;
    /*  pointer to the buffer               */
    tpl_application_data    *buffer;
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
    /*  common to all sending mo    */
    tpl_base_sending_mo     base_mo;
    /*  function pointer to the filter  */
    tpl_filter              filter;
    /*  pointer to the buffer           */
    tpl_application_data    *buffer;
    /*  pointer to the internal receiving message object    */
    struct TPL_BASE_RECEIVING_MO    *internal_target;
    /*  pointer to the IPDU         */
    struct TPL_SENDING_IPDU *external_target;
};

typedef struct TPL_INTERNAL_EXTERNAL_SENDING_MO tpl_internal_external_sending_mo;

struct TPL_QUEUE {
    tpl_queue_size  max_size;
    tpl_queue_size  size;
    tpl_queue_size  element_size;
    tpl_queue_index index;
    char            *buffer;
    char            *last;
};
typedef struct TPL_QUEUE tpl_queue;

struct TPL_NOTIFICATION {
    char a;
};

typedef struct TPL_NOTIFICATION tpl_notification;

/*
 * Receiving message object descriptors
 * There is 3 kinds of receiving message objects :
 * - zero length
 * - unqueued
 * - queued
 * as long as a common data structure called tpl_base_receiving_mo 
 */
struct TPL_BASE_RECEIVING_MO {
    tpl_message_size    size;
    unsigned char       kind;
/*    tpl_receive_notification toto; */
};

typedef struct TPL_BASE_RECEIVING_MO tpl_base_receiving_mo;

struct TPL_UNQUEUED_RECEIVING_MO {
    /*  more than one unqueued Message Object may receive a message.
        next_mo is used to build a list of destination message objects. */
    struct TPL_UNQUEUED_RECEIVING_MO *next_mo;
};

typedef struct TPL_UNQUEUED_RECEIVING_MO tpl_unqueued_receiving_mo;

/*
struct TPL_QUEUED_RECEIVING_MO {
};

typedef struct TPL_QUEUED_RECEIVING_MO tpl_queued_receiving_mo;
*/
/*
 * Sending message object
 */
struct TPL_SENDING_MESSAGE_OBJECT {
    /*  size of the message object in bytes */
    tpl_message_size        size;
    /*  first of the receiving messages for internal communication  */
    /*  tpl_receiving_message   *internal_destination;  */
#ifdef WITH_EXTERNAL_COM
    /*  buffer to store the message */
    tpl_message_atom        *buffer;
    /*  sending filter              */
    tpl_filter              filter;
    /*  destination ipdu            */
    tpl_sending_ipdu        *ipdu;
#endif
};

typedef struct TPL_SENDING_MESSAGE_OBJECT tpl_sending_mo;



#ifdef WITH_EXTERNAL_COM
    //
#else
#endif

#ifdef WITH_EXTERNAL_COM
    // type of the message
    tpl_message_type  type;
#endif

        
#endif