/*
 * @file tpl_slave_core_startup.s
 *
 * @section desc File description
 *
 * Trampoline dispatch level for PowerPC port
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
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

#include "tpl_assembler.h"
#include "tpl_registers_asm.h"

TPL_EXTERN(tpl_init_mmu)
TPL_EXTERN(tpl_reset_registers)

TPL_EXTERN(main)
TPL_EXTERN(_sdata)
TPL_EXTERN(_stack_addr_p1)

#ifdef __ghs__
  .vle
#endif
#define OS_START_SEC_CODE
#include "AsMemMap.h"
TPL_GLOBAL(tpl_slave_core_startup)
TPL_GLOBAL_REF(tpl_slave_core_startup):
  mflr      r26
  e_bl      TPL_EXTERN_REF(tpl_init_mmu)
  e_bl      TPL_EXTERN_REF(tpl_reset_registers)
  mtlr      r26

  e_lis     r1,TPL_HIG(TPL_EXTERN_REF(_stack_addr_p1))
  e_add16i  r1,TPL_LOW(TPL_EXTERN_REF(_stack_addr_p1))
  e_lis     r13,TPL_HIG(TPL_EXTERN_REF(_sdata))
  e_add16i  r13,TPL_LOW(TPL_EXTERN_REF(_sdata))

  e_bl      TPL_EXTERN_REF(main)

tpl_slave_core_startup_loop:
  se_b      tpl_slave_core_startup_loop

#define OS_STOP_SEC_CODE
#include "AsMemMap.h"

