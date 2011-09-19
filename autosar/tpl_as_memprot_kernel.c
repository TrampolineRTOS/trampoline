/*
 *  tpl_as_memprot_kernel.c
 *  
 * @section desc File description
 *
 * Trampoline autosar extension memory protection kernel related
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

#include "tpl_as_memprot_kernel.h"
#include "tpl_os_mem_prot.h"

extern CONSTP2CONST(tpl_mem_prot_desc, AUTOMATIC, OS_CONST)
  tpl_mp_table[TASK_COUNT+ISR_COUNT+1];

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#define OSACCESS_READ      1
#define OSACCESS_WRITE     2
#define OSACCESS_EXECUTE   4
#define OSACCESS_STACK     8

FUNC(tpl_access, OS_CODE) tpl_check_proc_memory_access(
  CONST(tpl_proc_id, AUTOMATIC)              proc_id,
  CONSTP2CONST(u8, AUTOMATIC, OS_APPL_DATA)  address,
  CONST(u32, AUTOMATIC)                      size)
{
  /*
   * currently, supported memory regions are:
   * - variables of the process (rw)
   * - stack of the process (rws)
   * - variables of the OS Application (rw)
   * So it cannot return execute
   */
  VAR(tpl_access, AUTOMATIC) access = 0;
  CONSTP2CONST(tpl_mem_prot_desc, AUTOMATIC, OS_CONST) desc = tpl_mp_table[proc_id];
  
  if ((address >= (u8*)desc->proc_var.start) && ((address+size) <= (u8*)desc->proc_var.end))
  {
    access |= (OSACCESS_READ | OSACCESS_WRITE);
  }
  
  if ((address >= (u8*)desc->proc_stack.start) && ((address+size) <= (u8*)desc->proc_stack.end))
  {
    access |= (OSACCESS_READ | OSACCESS_WRITE | OSACCESS_STACK);
  }
          
#if WITH_AUTOSAR == YES
  if ((address >= (u8*)desc->osap_var.start) && ((address+size) <= (u8*)desc->osap_var.end))
  {
    access |= (OSACCESS_READ | OSACCESS_WRITE);
  }
#endif

  return access;
}

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
  CONST(tpl_isr_id, AUTOMATIC)              isr_id,
  CONSTP2CONST(u8, AUTOMATIC,OS_APPL_DATA)  address,
  CONST(u32, AUTOMATIC)                     size)
{
  VAR(tpl_access, AUTOMATIC) access = 0;
#if ISR_COUNT > 0
  if ((isr_id >= TASK_COUNT) && isr_id < (ISR_COUNT+TASK_COUNT))
  {
    access = tpl_check_proc_memory_access(isr_id, address, size);
  }
#endif
  return access;
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
 * @retval if the task_id is valid, the access right of
 *         the specified memory region (OS269)
 * @retval if the memory region overlaps zone where a right is different, the
 *         less favorable right win (OS314)
 * @retval if the task_id is not valid, no access is returned (OS270)
 */
FUNC(tpl_access, OS_CODE) tpl_check_task_memory_access(
  CONST(tpl_task_id, AUTOMATIC)              task_id,
  CONSTP2CONST(u8, AUTOMATIC, OS_APPL_DATA)  address,
  CONST(u32, AUTOMATIC)                      size)
{
  VAR(tpl_access, AUTOMATIC) access = 0;
#if TASK_COUNT > 0
  if (task_id < TASK_COUNT)
  {
    access = tpl_check_proc_memory_access(task_id, address, size);
  }
#endif
  return access;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file tpl_as_memprot_kernel.c */
