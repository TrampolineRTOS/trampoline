/**
 * @file apf27_mmu.c
 *
 * @section descr File description
 *
 * Part of the MMU driver which configures the memory protection map
 * which depends on the hardware.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_definitions.h"
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"
#endif /* WITH_AUTOSAR */

#if WITH_MEMORY_PROTECTION == YES

#include "arm926_mmu.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern FUNC(void, OS_CODE) MMU_set_system_section (tpl_task_id this_process, u32 address, CacheableMemoryArea cacheable);
extern FUNC(void, OS_CODE) MMU_set_tiny_pages_area (tpl_task_id this_process, u8 *from, u8 *to, u8 this_access_permission, CacheableMemoryArea cacheable);

FUNC(void, OS_CODE) MMU_set_board_system_areas (tpl_task_id this_process)
{
  /* the following sections are for BROM and interlaced reserved areas*/
  MMU_set_system_section (this_process, 0x00000000, CACHEABLE);
  MMU_set_system_section (this_process, 0x00100000, CACHEABLE);
  MMU_set_system_section (this_process, 0x00200000, CACHEABLE);
  MMU_set_system_section (this_process, 0x00300000, CACHEABLE);
  MMU_set_system_section (this_process, 0x00400000, CACHEABLE);
  MMU_set_system_section (this_process, 0x00500000, CACHEABLE);
  MMU_set_system_section (this_process, 0x00600000, CACHEABLE);
  MMU_set_system_section (this_process, 0x00700000, CACHEABLE);
  /* so called "internal registers", ie many devices */
  MMU_set_system_section (this_process, 0x10000000, NONCACHEABLE);
  /* CSI and ATA devices, and many reserved memory space */
  MMU_set_system_section (this_process, 0x80000000, NONCACHEABLE);
  /* TODO : add EMI and PCMCIA areas */
  /* reserved area and vector RAM */
  MMU_set_system_section (this_process, 0xFFF00000, CACHEABLE);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_MEMORY_PROTECTION */

