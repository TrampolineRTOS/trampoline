/**
 * @file arm926_mem_prot.c
 *
 * @section descr File description
 *
 * Trampoline's memory protection for ARM926
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

#include "arm926_mem_prot.h"
#include "arm926_memmap_symbols.h"
#include "arm926_mmu.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/* FIXME: should be declared somewhere else (in tpl_app_config.h ?) */
extern CONSTP2CONST(tpl_mem_prot_desc, AUTOMATIC, OS_CONST) tpl_mp_table[TASK_COUNT+ISR_COUNT+1];

/**
 * This function setups MMU for common memory map
 * (OS parts, devices, ...)
 */
static FUNC(void, OS_CODE) tpl_setup_common_mp (tpl_task_id this_process)
{
  /* provided by board part of the port */
  MMU_set_board_system_areas (this_process);
 
  /* Trampoline's core private code, constants and variables */ 
  MMU_set_system_area (this_process, &__SEG_START_OS_PRIVATE, &__SEG_END_OS_PRIVATE, CACHEABLE);
  
  /* Shared code and constants */
  MMU_set_readonly_area (this_process, &__SEG_START_APP_CODE_CONST_RGN, &__SEG_END_APP_CODE_CONST_RGN, CACHEABLE);

  /* shared variables (FIXME: a clear policy should be find for external libraries and GCC builtin functions) */
  MMU_set_readonly_area (this_process, &__SEG_START_COMMON_VARS, &__SEG_END_COMMON_VARS, CACHEABLE);
}

/**
 * This function setups MMU for the memory accessible
 * by the process
 */
static FUNC(void, OS_CODE) tpl_setup_self_mp (tpl_task_id this_process)
{
  if (tpl_mp_table[this_process] != NULL) /* idle task does not have any descriptor */
  {
    /* variables */
    MMU_set_readwrite_area (this_process, tpl_mp_table[this_process]->proc_var.start, tpl_mp_table[this_process]->proc_var.end, CACHEABLE);
    /* stack */
    MMU_set_readwrite_area (this_process, tpl_mp_table[this_process]->proc_stack.start, tpl_mp_table[this_process]->proc_stack.end, CACHEABLE);
#if WITH_AUTOSAR == YES
    /* variables from OS Application */
    MMU_set_readwrite_area (this_process, tpl_mp_table[this_process]->osap_var.start, tpl_mp_table[this_process]->osap_var.end, CACHEABLE);
#endif /* WITH_AUTOSAR == YES */
  }
  else
  {
    /* idle task's memory protection configuration is used to provide kernel (or trusted) memory protection configuration.
     * In this configuration, everything is accessible except memory holes (where there is nothing to do),
     * this is useful to detect bugs in privileged code
     */
    MMU_set_system_area (this_process, &MMU_start_custom_zone, &MMU_end_custom_zone, CACHEABLE);
  }
}

FUNC(void, OS_CODE) tpl_init_mp()
{
  tpl_task_id i;

  MMU_init ();

  for (i = 0 ; i < (TASK_COUNT + ISR_COUNT + 1) ; i++)
  {
    tpl_setup_common_mp (i);
    tpl_setup_self_mp (i);
  }

  /* we points on a valid memory protection configuration, as
   * every mem. prot. conf. leave the kernel have access to
   * all its data and code */
  MMU_set_current_process (IDLE_TASK_ID);
  MMU_enable ();
}

FUNC(void, OS_CODE) tpl_mp_kernel_enter (void)
{
  /* We never disable MMU, we just provide more rights using the
   * idle tasḱ's memory protection configuration */
  MMU_set_current_process (IDLE_TASK_ID);
}

FUNC(void, OS_CODE) tpl_mp_kernel_exit (void)
{
  if (tpl_kern.running->trusted_counter > 0)
  {
    tpl_kern.s_running->context->psr |= 0x1F;
    /* provides the trusted mem. prot. conf */
    MMU_set_current_process (IDLE_TASK_ID);
    tpl_kern.running_trusted = 1;
  }
  else
  {
    tpl_kern.s_running->context->psr &= ~0x1F;
    tpl_kern.s_running->context->psr |= 0x10;
    MMU_set_current_process (tpl_kern.running_id);
    tpl_kern.running_trusted = 0;
  }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_MEMORY_PROTECTION */

