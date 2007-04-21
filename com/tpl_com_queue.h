/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Communication kernel header
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_KERNEL_H__
#define __TPL_COM_KERNEL_H__

#include "tpl_com_private_types.h"
#include "tpl_com_base_mo.h"

/*! 
 *  \brief  Dynamic part of the queue structure
 *
 *  The dynamic part of the queue structure belong to queue management.
 *  Queues are used in queued receiving message objects. This part
 *  manages data that change during the application lifetime.
 *  It must be stored in RAM.
 */ 
struct TPL_QUEUE_DYNAMIC {
    /*! The pointer to the last written element (used for filtering)    */
    tpl_com_data            *last;
    /*! The current size of the queue                                   */
    tpl_queue_size          size;
    /*! The read index                                                  */
    tpl_queue_index         index;
    /*! A flag to notify an overflow of the queue                       */
    tpl_bool                overflow;
};

/*!
 *  \brief  Static part of the queue structure
 *
 *  The static part of the queue structure belong to queue management.
 *  Queues are used in queued receiving message objects. This part
 *  manages data that do not change during the application lifetime.
 *  It can be stored in ROM.
 */ 
struct TPL_QUEUE_STATIC {
    /*! pointer to the dynamic descriptor                               */
    struct TPL_QUEUE_DYNAMIC *dyn_desc;
    /*! max_size of the queue (number of tpl_com_data elements)         */
    tpl_queue_size          max_size;
    /*! size of an element of the queue                                 */
    tpl_message_size        element_size;
    /*! pointer to the beginning of the buffer                          */
    tpl_com_data            *buffer;
};

/*!
 *  Queue datatypes
 */
typedef struct TPL_QUEUE_DYNAMIC tpl_queue_dyn;
typedef struct TPL_QUEUE_STATIC tpl_queue;

/*
 *  Queue management functions prototypes
 *
 *  Pointer to the next element available for a write
 *  (or NULL if no space left)
 */
tpl_com_data *tpl_queue_element_for_write(tpl_queue *);

/*
 *  Pointer to the next element available for a read
 *  (or NULL if empty queue)
 */
tpl_com_data *tpl_queue_element_for_read(tpl_queue *);

#endif
