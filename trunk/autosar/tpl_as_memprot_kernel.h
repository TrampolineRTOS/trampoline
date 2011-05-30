/*
 *  tpl_as_memprot_kernel.h
 *  
 * @section desc File description
 *
 * Trampoline autosar extension memory protection kernel related
 * functions header
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_AS_MEMPROT_KERNEL_H
#define TPL_AS_MEMPROT_KERNEL_H

#include "tpl_os_internal_types.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * tpl_check_isr_memory_access
 *
 * @param  isr_id   ISR reference
 *
 * @param  address  Start of memory area
 *
 * @param  size     Size of memory area 
 *
 * @retval if the isr_id is valid, the access right of
 *         the specified memory region (OS267)
 * @retval if the memory region overlaps zone where a right is different, the
 *         less favorable right win (OS313)
 * @retval if the isr_id is not valid, no access is returned (OS268)
 */
FUNC(tpl_access, OS_CODE) tpl_check_isr_memory_access(
  CONST(tpl_isr_id, AUTOMATIC)               isr_id,
  CONSTP2CONST(u8, AUTOMATIC, OS_APPL_DATA)  address,
  CONST(u32, AUTOMATIC)                      size
);

/**
 * CheckTaskMemoryAccess
 *
 * @param  task_id  Task reference
 *
 * @param  address  Start of memory area
 *
 * @param  size     Size of memory area 
 *
 * @retval if the isr_id is valid, the access right of
 *         the specified memory region (OS267)
 * @retval if the memory region overlaps zone where a right is different, the
 *         less favorable right win (OS313)
 * @retval if the isr_id is not valid, no access is returned (OS268)
 */
FUNC(tpl_access, OS_CODE) tpl_check_task_memory_access(
  CONST(tpl_task_id, AUTOMATIC)                task_id,
  CONSTP2CONST(u8, AUTOMATIC, OS_APPL_DATA)    address,
  CONST(u32, AUTOMATIC)                        size
);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
#endif /* TPL_AS_MEMPROT_KERNEL_H */
/* End of file tpl_as_memprot_kernel.h */
