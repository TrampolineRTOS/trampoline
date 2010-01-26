/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Base Message Object data structures
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_BASE_MO_H__
#define __TPL_COM_BASE_MO_H__

#include "tpl_os_types.h"
#include "tpl_os_action.h"
#include "tpl_com_types.h"
#include "tpl_com_private_types.h"
#include "tpl_com_filtering.h"

/*
 * Forward declarations
 */
struct TPL_BASE_SENDING_MO;
struct TPL_BASE_RECEIVING_MO;
struct TPL_DATA_RECEIVING_MO;

/*
 * Prototype for sending functions
 */
typedef tpl_status (*tpl_sending_func)(
  P2CONST(void, AUTOMATIC, OS_CODE),
  CONSTP2CONST(tpl_com_data, AUTOMATIC, OS_VAR));

/*
 * Prototype for receiving functions
 */
typedef tpl_status (*tpl_receiving_func)(
  P2CONST(void, AUTOMATIC, OS_CODE),
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR));

/*
 * Prototype for copying functions
 */
typedef tpl_status (*tpl_data_copy_func)(
  P2VAR(tpl_com_data, AUTOMATIC, OS_APPL_DATA),
  CONSTP2CONST(void, AUTOMATIC, OS_CONST));

/*!
 *  \struct TPL_BASE_SENDING_MO
 *
 *  \brief  Sending Message Object base data structure.
 *
 *  Internal and external communication base data structure for sending
 *  Message Objects. Concret sending message objects inherit from this
 *  structure.
 */
struct TPL_BASE_SENDING_MO {
    /*! pointer to the sending function  */
    tpl_sending_func    sender;
};

typedef struct TPL_BASE_SENDING_MO tpl_base_sending_mo;

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
    /*! notification structure              */
    tpl_action                      *notification;
    /*! message objects chaining            */
    struct TPL_BASE_RECEIVING_MO    *next_mo;
};

typedef struct TPL_BASE_RECEIVING_MO tpl_base_receiving_mo;

/*!
 *  \struct TPL_DATA_RECEIVING_MO
 *
 *  \brief  Structure for receiving message object that store a data
 *
 *  This structure extends the TPL_BASE_RECEIVING_MO by adding a pointer to
 *  the receiving function which is used to copy the data from the sender
 *  (receiving IPDU or sending message object) to the buffer, a pointer
 *  to a function which is used to copy the message data to the application
 *  data and a filter descriptor for incoming data filtering. It does not
 *  include members for storage since two kind of storage are available
 *  (queued and unqueued).
 */
struct TPL_DATA_RECEIVING_MO {
    /*! common part of the receiving message objects            */
    tpl_base_receiving_mo   base_mo;
    /*! pointer to the receiving function   */
    tpl_receiving_func      receiver;
    /*! pointer to the data copy function                       */
    tpl_data_copy_func      copier;
    /*! filter descriptor                                       */
    tpl_filter_desc         *filter;
};

typedef struct TPL_DATA_RECEIVING_MO tpl_data_receiving_mo;


/*!
 *  Table of sending message objects pointers
 */
extern CONSTP2CONST(tpl_base_sending_mo, AUTOMATIC, OS_CONST)
  tpl_send_message_table[];

/*!
 *  Table of receiving message objects pointers
 */
extern CONSTP2CONST(tpl_base_receiving_mo, AUTOMATIC, OS_CONST)
  tpl_receive_message_table[];

#endif
/*  __TPL_COM_BASE_MO_H__   */
