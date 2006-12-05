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
 * tpl_com_value is the type used by filters. According to the
 * OSEK-COM specification, it has to be an integer.
 */
typedef int tpl_com_value;

/*
 * tpl_com_count is the type used for the occurence filter
 */
typedef unsigned char tpl_com_count;

/*
 * tpl_message_id is used to identify messages
 */
typedef short int tpl_message_id;

/*
 * tpl_message_size is the data type used to store the size of a message.
 * This type has to be an unsigned one since > 0 comparisons are done in
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

#endif
