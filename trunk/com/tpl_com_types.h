/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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

/*
 * tpl_message_kind is used to tag a message object
 */
typedef unsigned char tpl_message_kind;

/*
 * tpl_message_id is used to identify messages
 */
typedef short int tpl_message_id;

/*
 * tpl_message_size is the data type used to store
 * the size of a message
 */
typedef unsigned char tpl_message_size;

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

#endif