/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline AUTOSAR IOC internal types
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */
/* MISRA RULE 3.1 VIOLATION: special character is used in comments for svn integration, the code can survive to this ! */

#ifndef __TPL_IOC_INTERNAL_TYPES_H__
#define __TPL_IOC_INTERNAL_TYPES_H__

#include "tpl_os_definitions.h"
#include "tpl_os_internal_types.h"
#include "tpl_app_custom_types.h"


/**
 * @typedef tpl_ioc_message_size
 *
 * used for size of an ioc message in bytes
 */
typedef uint32 tpl_ioc_message_size;


/**
 * @typedef tpl_ioc_data
 *
 * type of data managed by ioc, byte
 */
typedef uint8 tpl_ioc_data;


/**
 * @typedef tpl_ioc_buffer
 *
 * type for pointer to tpl_ioc_data,
 * used to simplify double pointer types
 */
typedef P2VAR(tpl_ioc_data, TYPEDEF, OS_VAR) tpl_ioc_buffer;


/**
 * @typedef tpl_ioc_unqueued_mo
 *
 * type unqueued ioc message object descriptor
 */
struct TPL_IOC_UNQUEUED_MO
{
  P2CONST(tpl_ioc_buffer, TYPEDEF, OS_CONST)        buffer;
  P2CONST(tpl_ioc_buffer, TYPEDEF, OS_CONST)        init_buffer;
  P2CONST(tpl_ioc_message_size, TYPEDEF, OS_CONST)  element_size;
  VAR(tpl_ioc_id, TYPEDEF)                          id;
  VAR(tpl_ioc_size, TYPEDEF)                        nb_mo;
};

typedef struct TPL_IOC_UNQUEUED_MO tpl_ioc_unqueued_mo;


/**
 * @typedef tpl_ioc_queue_dyn
 *
 * type for dynamic part of queue descriptor
 */
struct TPL_IOC_QUEUE_DYN
{
  VAR(tpl_ioc_queue_size, TYPEDEF)  size;
  VAR(tpl_ioc_queue_size, TYPEDEF)  index;
  VAR(tpl_bool, TYPEDEF)            overflow;
};

typedef struct TPL_IOC_QUEUE_DYN tpl_ioc_queue_dyn;


/**
 * @typedef tpl_ioc_queue
 *
 * type for static part of queue descriptor
 */
struct TPL_IOC_QUEUE
{
  P2VAR(tpl_ioc_queue_dyn, TYPEDEF, OS_VAR) dyn_desc;
  P2VAR(tpl_ioc_data, TYPEDEF, OS_VAR)      buffer;
  VAR(tpl_ioc_queue_size, TYPEDEF)          max_size;
  VAR(tpl_ioc_message_size, TYPEDEF)        element_size;
};

typedef struct TPL_IOC_QUEUE tpl_ioc_queue;


/**
 * @typedef tpl_ioc_queued_mo
 *
 * type queued ioc message object descriptor
 */
struct TPL_IOC_QUEUED_MO
{
  P2CONST(tpl_ioc_queue, TYPEDEF, OS_CONST) queue;
  VAR(tpl_ioc_id, TYPEDEF)                  id;
  VAR(tpl_ioc_size, TYPEDEF)                nb_mo;
};

typedef struct TPL_IOC_QUEUED_MO tpl_ioc_queued_mo;


/**
 * @typedef tpl_ioc_message
 *
 * type for ioc message passed in IOC APIs
 */
struct TPL_IOC_MESSAGE
{
  P2VAR(tpl_ioc_data, TYPEDEF, OS_APPL_DATA)  data;
  VAR(tpl_ioc_message_size, TYPEDEF)          length;
};

typedef struct TPL_IOC_MESSAGE tpl_ioc_message;

/*  __TPL_IOC_INTERNAL_TYPES_H__ */
#endif

