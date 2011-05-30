/**
 * @file tpl_as_memprot.h
 *
 * @section desc File description
 *
 * Trampoline autosar extension memory protection related functions header
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

#ifndef TPL_AS_MEMPROT_H
#define TPL_AS_MEMPROT_H

#include "tpl_as_isr.h"
#include "tpl_os_types.h"

/**
 * @typedef AccessType
 *
 * This data type holds the access right associated to a memory region
 * AccessType is an opaque type and should be used by macros
 * OSMEMORY_IS_READABLE, OSMEMORY_IS_WRITEABLE, OSMEMORY_IS_EXECUTABLE
 * and OSMEMORY_IS_STACKSPACE
 *
 * Bit allocation is as follow:
 * bit0 - 0: read is not allowed, 1: read is allowed
 * bit1 - 0: write is not allowed, 1: write is allowed
 * bit2 - 0: region is not executable, 1: region is executable
 * bit3 - 0: region is not stack space, 1: region is stack space
 */
typedef VAR(tpl_access, TYPEDEF) AccessType;

/**
 * @def OSMEMORY_IS_READABLE
 *
 * @param  the access descriptor of the memory region
 * @retval TRUE if the memory region is readable
 * @retval FALSE if the memory region is not readable
 */
#define OSMEMORY_IS_READABLE(access_type) (access_type & 0x1)

/**
 * @def OSMEMORY_IS_WRITABLE
 *
 * @param  the access descriptor of the memory region
 * @retval TRUE if the memory region is writable
 * @retval FALSE if the memory region is not writable
 */
#define OSMEMORY_IS_WRITABLE(access_type) ((access_type & 0x2) >> 1)

/**
 * @def OSMEMORY_IS_EXECUTABLE
 *
 * @param  the access descriptor of the memory region
 * @retval TRUE if the memory region is executable
 * @retval FALSE if the memory region is not executable
 */
#define OSMEMORY_IS_EXECUTABLE(access_type) ((access_type & 0x4) >> 2)

/**
 * @def OSMEMORY_IS_STACKSPACE
 *
 * @param  the access descriptor of the memory region
 * @retval TRUE if the memory region is stack space
 * @retval FALSE if the memory region is not stack space
 */
#define OSMEMORY_IS_STACKSPACE(access_type) ((access_type & 0x8) >> 3)

/**
 * @typedef MemoryStartAddressType
 *
 * This data type is a pointer which is able to point to any location
 * in the MCU address space.
 *
 * See paragraph 8.3.7, page 74 of
 * Autosar Specification of Operating System V3.1.1 R3.1 Rev 0002
 */
typedef P2VAR(u8, TYPEDEF, OS_APPL_DATA) MemoryStartAddressType;

/**
 * @typedef MemorySizeType
 *
 * This data type holds the size (in bytes) of a memory region.
 *
 * See paragraph 8.3.8, page 74 of
 * Autosar Specification of Operating System V3.1.1 R3.1 Rev 0002
 */
typedef VAR(u32, TYPEDEF) MemorySizeType;


#define OS_START_SEC_CODE
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
FUNC(AccessType, OS_CODE) CheckTaskMemoryAccess (
  CONST(TaskType, AUTOMATIC)                task_id,
  CONST(MemoryStartAddressType, AUTOMATIC)  address,
  CONST(MemorySizeType, AUTOMATIC)          size
);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_AS_MEMPROT_H */
/* End of file tpl_as_memprot.h */
