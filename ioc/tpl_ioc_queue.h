/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline AUTOSAR IOC queue declaration
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */
/* MISRA RULE 3.1 VIOLATION: special character is used in comments for svn integration, the code can survive to this ! */

#ifndef __TPL_IOC_QUEUE_H__
#define __TPL_IOC_QUEUE_H__

#include "tpl_ioc.h"




#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 *  Queue management functions prototypes
 *
 *  Pointer to the next element available for a write
 *  (or NULL if no space left)
 */
extern FUNC(tpl_ioc_buffer, OS_CODE) tpl_ioc_queue_element_for_write(
  CONSTP2CONST(tpl_ioc_queue, AUTOMATIC, OS_CONST) queue);

/*
 *  Pointer to the next element available for a read
 *  (or NULL if empty queue)
 */
extern FUNC(tpl_ioc_buffer, OS_CODE) tpl_ioc_queue_element_for_read(
  CONSTP2CONST(tpl_ioc_queue, AUTOMATIC, OS_CONST) queue);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif

