/*
 *  tpl_as_memprot.c
 *  
 * @section desc File description
 *
 * Trampoline autosar extension memory protection related
 * functions implementation
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

#include "tpl_os_definitions.h"

#if WITH_SYSTEM_CALL == NO

#include "tpl_as_memprot.h"
#include "tpl_as_memprot_kernel.h"

#define API_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * CheckISRMemoryAccess
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
FUNC(AccessType, OS_CODE) CheckISRMemoryAccess (
  CONST(ISRType, AUTOMATIC)                 isr_id,
  CONST(MemoryStartAddressType, AUTOMATIC)  address,
  CONST(MemorySizeType, AUTOMATIC)          size
)
{
  return tpl_check_isr_memory_access(isr_id, address, size);
}

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
FUNC(AccessType, OS_CODE) CheckTaskMemoryAccess (
  CONST(TaskType, AUTOMATIC)                task_id,
  CONST(MemoryStartAddressType, AUTOMATIC)  address,
  CONST(MemorySizeType, AUTOMATIC)          size
)
{
  return tpl_check_task_memory_access(task_id, address, size);
}

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

#else
#error "This file should not be part of your project since WITH_SYSTEM_CALL is YES"
#endif /* WITH_SYSTEM_CALL */

/* End of file tpl_as_memprot.c */
