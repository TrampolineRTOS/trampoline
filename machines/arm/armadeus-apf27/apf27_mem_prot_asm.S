/**
 * @file apf27_mem_prot_asm.S
 *
 * @section descr File description
 *
 * Low level part of ARMADEUS-APF27 memory protection management
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

.global apf27_init_mem_prot_lowlevel
apf27_init_mem_prot_lowlevel:
  mov pc, lr

/* Control register c1
 * Enable align address condrol, 'A' bit
 * Enable MMU, 'M' bit
 */
.global tpl_enable_memory_protection
tpl_enable_memory_protection:
  /* Set domain 0 as client - it's only the one used here - */
  mov r2, #0x1          
  mcr p15, 0, r2, c3, c0, 0

  /* Flush TLB */
  mcr p15, 0, r2, c8, c7, 0

  /* Set the A and M bits */
  mrc p15, 0, r2, c1, c0, 0  
  orr r2, r2, #0b11
  mcr p15, 0, r2, c1, c0, 0
  b 1f /* pipeline flush */
1:
  mov pc, lr

.global tpl_disable_memory_protection
tpl_disable_memory_protection:
  /* Unset the A and M bits */
  mrc p15, 0, r2, c1, c0, 0
  bic r2, r2, #0b11
  mcr p15, 0, r2, c1, c0, 0
  b 1f /* pipeline flush */
1:
  mov pc, lr

.global tpl_switch_memory_protection_context
tpl_switch_memory_protection_context:
  /* Set the translation table base address */
  ldr r1, [r0, #OFFSET_RUNNING_ID]  /* get the ID of the running process */
  
    /* get the address of the table of all translation table base address*/
  ldr r2, =ttb_table
  ldr r2, [r2, r1, LSL #2]
  mcr p15, 0, r2, c2, c0, 0    /* set the system with this new base address */
  b 1f /* pipeline_flush */
1:
  mov pc, lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#endif /* WITH_MEMORY_PROTECTION == YES */

