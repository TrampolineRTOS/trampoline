/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline types definitions
 * 
 * Datatypes defined in this file can be changed by the user
 * to fit its needs. Please refer to comments of each
 * datatype.
 *
 * $Date: 2005-04-07 15:20:19 +0200 (Thu, 07 Apr 2005) $
 * $Rev$
 * $Author: jlb $
 * $URL: http://localhost:8888/Trampoline/svn/tpl_com_types.h $
 *
 */

#ifndef __TPL_COM_TYPES_H__
#define __TPL_COM_TYPES_H__

#include "tpl_os_std_types.h"
/*
 * tpl_com_value is the type used by filters. According to the
 * OSEK-COM specification, it has to be an integer.
 */
typedef int tpl_com_value;

/*! 
 *  Datatype for the message of application data atom
 */
typedef unsigned char       tpl_com_data;

/*
 * tpl_com_count is the type used for the occurence filter
 */
typedef sint8 tpl_com_count;

/*
 * tpl_message_id is used to identify messages
 */
typedef unsigned short int tpl_message_id;

/*
 * tpl_message_size is the data type used to store the size of a message.
 * This type has to be a signed one since signed comparisons are done in
 * Trampoline/COM.
 */
typedef char tpl_message_size;

/*
 * tpl_queue_size is the datatype used to store the
 * size of message queues
 */
typedef unsigned char tpl_queue_size;

/*
 * tpl_queue_index is the data type used to store the
 * current read index of message queues
 */
typedef unsigned char tpl_queue_index;

/*
 * tpl_flags is the datatype used tu store notification flags
 * basically, it is a set of bits
 */
typedef unsigned char tpl_flag_set;

/*
 * tpl_com_app_mode is the datatype used for COM Application Mode
 */
typedef uint8 tpl_com_app_mode;

/*
 * tpl_com_shut_mode is the datatype used for COM Shutdown Mode
 */
typedef uint8 tpl_com_shut_mode;

/*
 * tpl_callout_ret
 */
typedef uint8 tpl_callout_ret;

/*
 * tpl_com_srv_id
 */
typedef uint8 tpl_com_srv_id;

/*
 * tpl_com_callout, a function pointer type for callouts
 */
typedef tpl_callout_ret (*tpl_com_callout)(void);

#endif
