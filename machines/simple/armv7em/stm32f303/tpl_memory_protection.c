/**
 * @file tpl_memory_protection.c
 *
 * @section descr File description
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"
#endif /* WITH_AUTOSAR */

#if WITH_MEMORY_PROTECTION == YES

#include "tpl_memory_protection.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * This function setups MMU for common memory map
 * (OS parts, devices, ...)
 */
static FUNC(void, OS_CODE) tpl_setup_common_mp (void)
{
	/*
	__DMB();	// Make sure outstanding transfers are done
	MPU->CTRL = MPU_CTRL_ENABLE_Msk; // Enable the MPU
	__DSB();  // Memory barriers to ensure subsequence data & instruction
	__ISB();  // transfers using updated MPU settings
	*/
}

static FUNC(void, OS_CODE) tpl_setup_common_mp_old (void)
{
	uint32_t i;
	uint32_t const mpu_cfg_rbar[MPU_DEFS_NB_REGION_USED] = {
		0x08000000, // Flash address for STM32F4
		PERIPH_BASE, // Peripherals address
	};
	uint32_t const mpu_cfg_rasr[MPU_DEFS_NB_REGION_USED] = {
		(MPU_DEFS_RASR_SIZE_1MB | MPU_DEFS_NORMAL_MEMORY_WT | MPU_DEFS_RASE_AP_FULL_ACCESS | MPU_RASR_ENABLE_Msk), // Flash
		(MPU_DEFS_RASR_SIZE_1KB | MPU_DEFS_SHARED_DEVICE | MPU_DEFS_RASE_AP_FULL_ACCESS | MPU_RASR_ENABLE_Msk), // GPIO D
	};
/*	uint32_t const mpu_cfg[MPU_DEFS_NB_REGION_USED][2] = {
		{ 0x08000000, (MPU_DEFS_RASR_SIZE_1MB | MPU_DEFS_NORMAL_MEMORY_WT | MPU_DEFS_RASE_AP_FULL_ACCESS | MPU_RASR_ENABLE_Msk) }, // Flash address for STM32F4
		{ 0x20000000, (MPU_DEFS_RASR_SIZE_128KB | MPU_DEFS_NORMAL_MEMORY_WT | MPU_DEFS_RASE_AP_FULL_ACCESS | MPU_RASR_ENABLE_Msk) }, // SRAM
		{ GPIOD_BASE, (MPU_DEFS_RASR_SIZE_1KB | MPU_DEFS_SHARED_DEVICE | MPU_DEFS_RASE_AP_FULL_ACCESS | MPU_RASR_ENABLE_Msk) }, // GPIO D base address
		{ GPIOA_BASE, (MPU_DEFS_RASR_SIZE_1KB | MPU_DEFS_SHARED_DEVICE | MPU_DEFS_RASE_AP_FULL_ACCESS | MPU_RASR_ENABLE_Msk) }, // GPIO A base address
		{ EXTI_BASE, (MPU_DEFS_RASR_SIZE_1KB | MPU_DEFS_SHARED_DEVICE | MPU_DEFS_RASE_AP_FULL_ACCESS | MPU_RASR_ENABLE_Msk) }, // EXTI
		{ RCC_BASE, (MPU_DEFS_RASR_SIZE_1KB | MPU_DEFS_SHARED_DEVICE | MPU_DEFS_RASE_AP_FULL_ACCESS | MPU_RASR_ENABLE_Msk) } // RCC Reset Clock CTRL base address
	};
*/	
//	if (MPU->TYPE==0) {return 1;}	// Return 1 to indicate error
	__DMB();	// Make sure outstanding transfers are done
	MPU->CTRL = 0;	// Disable the MPU
	for (i=0;i<MPU_DEFS_NB_REGION_USED;i++) {	// Configure only MPU_DEFS_NB_REGION_USED regions
		MPU->RNR = i;	// Select which MPU region to configure
		MPU->RBAR = mpu_cfg_rbar[i];  // Configure region base address register
		MPU->RASR = mpu_cfg_rasr[i]; // Configure region attribute and size register
	}
	
	for (i=MPU_DEFS_NB_REGION_USED;i<8;i++) {	// Disabled unused regions
		MPU->RNR = i;	// Select which MPU region to configure
		MPU->RBAR = 0;	// Configure region base address register
		MPU->RASR = 0;	// Configure region attribute and size register
	}
	
	MPU->CTRL = MPU_CTRL_ENABLE_Msk; // Enable the MPU
	__DSB();  // Memory barriers to ensure subsequence data & instruction
	__ISB();  // transfers using updated MPU settings
	
}

/**
 * This function setups MPU for the memory accessible
 * by the process
 */
static FUNC(void, OS_CODE) tpl_setup_self_mp (tpl_task_id this_process)
{
	if (tpl_mp_table[this_process] != NULL) /* idle task does not have any descriptor */
	{
//		MPU->CTRL = 0;	// Disable the MPU
//		MPU->RNR = 7;
//		MPU->RBAR = tpl_mp_table[this_process]->proc_var.start;
//		MPU->RASR = tpl_mp_table[this_process]->proc_var.end;
//		MPU->CTRL = MPU_CTRL_ENABLE_Msk; // Enable the MPU
//		__DSB();  // Memory barriers to ensure subsequence data & instruction
//		__ISB();  // transfers using updated MPU settings
#if WITH_AUTOSAR == YES
    /* variables from OS Application */
//    MMU_set_readwrite_area (this_process, tpl_mp_table[this_process]->osap_var.start, tpl_mp_table[this_process]->osap_var.end, CACHEABLE);
#endif /* WITH_AUTOSAR == YES */
	}
	else
	{
    /* idle task's memory protection configuration is used to provide kernel (or trusted) memory protection configuration.
     * In this configuration, everything is accessible except memory holes (where there is nothing to do),
     * this is useful to detect bugs in privileged code
     */
//    MMU_set_system_area (this_process, &MMU_start_custom_zone, &MMU_end_custom_zone, CACHEABLE);
	}
}

FUNC(void, OS_CODE) tpl_init_mp()
{
	tpl_task_id currentTaskID;

	/* Enable memory management */
#if WITH_MEMORY_PROTECTION == YES
//	SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
#endif

	MPU->RNR = 0;
	MPU->RBAR = 0x08000000;
	MPU->RASR = (MPU_DEFS_RASR_SIZE_1MB | MPU_DEFS_NORMAL_MEMORY_WT | MPU_DEFS_RASE_AP_FULL_ACCESS | MPU_RASR_ENABLE_Msk);
	
	for (currentTaskID = 0 ; currentTaskID < (TASK_COUNT + ISR_COUNT + 1) ; currentTaskID++)
	{
		if (tpl_mp_table[currentTaskID] != NULL) /* idle task does not have any descriptor */
		{
	
		}
		else
  {
			
		}
  }

  /* we points on a valid memory protection configuration, as
   * every mem. prot. conf. leave the kernel have access to
   * all its data and code */
//  MMU_set_current_process (IDLE_TASK_ID);
//  MMU_enable ();
}

FUNC(void, OS_CODE) tpl_kernel_mp (void)
{
//	__DMB();	// Make sure outstanding transfers are done
//	MPU->CTRL = 0;	// Disable the MPU
	
  /* We never disable MMU, we just provide more rights using the
   * idle tasḱ's memory protection configuration */
//  MMU_set_current_process (IDLE_TASK_ID);
}

FUNC(void, OS_CODE) tpl_user_mp (void)
{
//	tpl_setup_self_mp(tpl_kern.running_id);
//	__DMB();	// Make sure outstanding transfers are done
//	MPU->CTRL = MPU_CTRL_ENABLE_Msk; // Enable the MPU
//	__DSB();  // Memory barriers to ensure subsequence data & instruction
//	__ISB();  // transfers using updated MPU settings	

//  if (tpl_kern.running->trusted_counter > 0)
//  {
//    tpl_kern.s_running->context->psr |= 0x1F;
    /* provides the trusted mem. prot. conf */
//    MMU_set_current_process (IDLE_TASK_ID);
//    tpl_kern.running_trusted = 1;
//  }
//  else
//  {
//    tpl_kern.s_running->context->psr &= ~0x1F;
//    tpl_kern.s_running->context->psr |= 0x10;
//    MMU_set_current_process (tpl_kern.running_id);
//    tpl_kern.running_trusted = 0;
//  }
}

/**
 * Set the memory protection for a process
 */
FUNC(void, OS_CODE) tpl_set_process_mp (tpl_task_id this_process)
{
	
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_MEMORY_PROTECTION */

