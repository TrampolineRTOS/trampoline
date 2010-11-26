/**
 * @file apf27_tpl_stubs.c
 *
 * @section descr File description
 *
 * ARMADEUS platform specific routines and variables
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
#include "tpl_os_application_def.h"
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"
#endif /* WITH_AUTOSAR */

#include "arm926_cpu_cache.h"
#include "arm926_mem_prot.h"
#include "arm926_mmu.h"

#if WITH_MEMORY_PROTECTION == YES
#include "arm926_mmu.h"
#endif /* WITH_MEMORY_PROTECTION */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

struct ARM_CONTEXT idle_task_context;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern int main (void);

FUNC(void, OS_CODE) tpl_shutdown ()
{
  DISABLE_FIQ ();
  DISABLE_IRQ ();

#if WITH_MEMORY_PROTECTION == YES
  /* disable the MMU, useful for debugging sessions */
  MMU_disable ();
#endif /* WITH_MEMORY_PROTECTION */
#if WITH_CPU_CACHE == YES
  arm926_cache_off ();
  arm926_cache_invalidate ();
#endif /* WITH_CPU_CACHE */

  /* fall into very low consumption mode : all
   * internal CPU clocks are disabled.
   */
  __asm__ ("mcr p15,0,r0,c7,c0,4\n");

  while (1);
}

extern void tpl_init_machine_generic (void);

FUNC(void, OS_CODE) tpl_init_machine()
{
#if WITH_MEMORY_PROTECTION == YES
  tpl_init_mp();
#endif /* WITH_MEMORY_PROTECTION == YES */

#if WITH_CPU_CACHE == YES
  arm926_cache_on ();
#else
  arm926_cache_off ();
#endif /* WITH_CPU_CACHE == YES*/

  tpl_init_machine_generic ();
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#if WITH_AUTOSAR_TIMING_PROTECTION == YES

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_set_watchdog (
  VAR(tpl_time, AUTOMATIC) delay)
{
  /* TODO */
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_cancel_watchdog ()
{
  /* TODO */
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(tpl_time, OS_CODE) tpl_get_local_current_date ()
{
  /* TODO delete these lines there are juste for debbug */
  VAR(tpl_time, OS_VAR) current_date;
  current_date = 0;
  return current_date;
  /* TODO */
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* defined WITH_AUTOSAR_TIMING_PROTECTION */

#if WITH_AUTOSAR_STACK_MONITORING == YES
/* FIXME : needs update (tpl_proc_static) */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 *  Check if one stack overflow have occured.
 *
 *  @param    this_exec_obj    The executable object to monitor
 *
 *  @retval    tmp    If set at one, a stack overflow is detected
 */

/* FIXME : needs update (tpl_proc_static) */

FUNC(tpl_bool, OS_CODE) tpl_check_stack_pointer (
    CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  VAR(tpl_bool, OS_VAR) tmp;
  /* FIXME : needs update (tpl_proc_static)
  if(this_exec_obj->static_desc->context.core_context->r[sp]<
    &(this_exec_obj->static_desc->stack))*/
  tmp=1; /*no overflow detected*/
  //else tmp=0; /*there is an overflow*/
  return tmp;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_AUTOSAR_STACK_MONITORING */

