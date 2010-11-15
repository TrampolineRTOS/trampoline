/**
 * @file apf27_mmu_asm.S
 *
 * @section descr File description
 *
 * Driver for memory management unit of ARM926EJ-S CPU
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
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_application_def.h"

#if WITH_MEMORY_PROTECTION == YES

.set OFFSET_RUNNING_ID, 16

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

.global MMU_enable
MMU_enable:
  mov pc, lr

.global MMU_disable
MMU_disable:
  mov pc, lr

.global MMU_switch_context
MMU_switch_context:
  mov pc, lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#endif /* WITH_MEMORY_PROTECTION == YES */

