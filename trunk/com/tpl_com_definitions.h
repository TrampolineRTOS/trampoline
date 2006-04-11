/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Definition for OSEK/COM
 *
 * $Date: 2005-04-07 15:20:19 +0200 (Thu, 07 Apr 2005) $
 * $Rev$
 * $Author: jlb $
 * $URL: http://localhost:8888/Trampoline/svn/tpl_com_definitions.h $
 */

#ifndef __TPL_COM_DEFINITIONS_H__
#define __TPL_COM_DEFINITIONS_H__

/*
 * Result codes
 */
#define E_COM_ID        17
#define E_COM_LENGTH    18
#define E_COM_LIMIT     19
#define E_COM_NOMSG     20

#ifdef WITH_EXTERNAL_COM
/*
 * message type
 */
#endif

/*
 * message kind
 */
#define SEND_STATIC_INTERNAL            1
#define SEND_STATIC_EXTERNAL            2
#define SEND_DYNAMIC_EXTERNAL           4
#define SEND_ZERO_INTERNAL              8
#define SEND_ZERO_EXTERNAL              16

#define RECEIVE_ZERO_INTERNAL           17
#define RECEIVE_ZERO_EXTERNAL           18
#define RECEIVE_UNQUEUED_INTERNAL       19
#define RECEIVE_QUEUED_INTERNAL         20
#define RECEIVE_UNQUEUED_EXTERNAL       21
#define RECEIVE_QUEUED_EXTERNAL         22
#define RECEIVE_DYNAMIC_EXTERNAL        23
#define RECEIVE_ZERO_SENDERS            24

#endif