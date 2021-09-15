/**
 * @file tpl_os_checkpoint_kernel.c
 *
 * @section descr File description
 *
 * Trampoline checkpointing os services implementation.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#include "tpl_os_os_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_machine_interface.h"
#include "tpl_trace.h"
#include "tpl_os_hooks.h"
#include "tpl_chkpt_checkpoint_kernel.h"

#include "msp430.h"
#include "tpl_chkpt_adc.h"

#if NUMBER_OF_CORES > 1
#include "tpl_os_multicore_kernel.h"
# if SPINLOCK_COUNT > 0
# include "tpl_as_spinlock_kernel.h"
# endif
#endif

extern FUNC(void, OS_CODE) tpl_restart_os(void);

#define OS_START_SEC_VAR_NON_VOLATILE_16BIT
#include "tpl_memmap.h"
VAR (sint16,OS_VAR) tpl_checkpoint_buffer = -1;
#define OS_STOP_SEC_VAR_NON_VOLATILE_16BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
//void disable_irq_for_hibernate(){
	///* Disable TIMER3_A0 interrupt */
	//TA3CCTL0 &= ~CCIE;
//}

//void restore_irq_for_hibernate(){
	///* Restore TIMER3_A0 interrupt */
	//TA3CCTL0 |= CCIE;
//}

//uint16 conversion_adc(){
	//ADC12CTL0 |= ADC12ON;
	//ADC12CTL0 |= ADC12ENC | ADC12SC;
	//while(ADC12CTL1 & ADC12BUSY);
	//ADC12CTL0 &= ~(ADC12ENC);
	//ADC12CTL0 &= ~(ADC12ON);
	//REFCTL0 &= ~(REFON);
	//return ADC12MEM0;
//}

FUNC(void, OS_CODE) tpl_hibernate_os_service(void)
{
  sint16 l_buffer;

  GET_CURRENT_CORE_ID(core_id)

  /* init the error to no error */
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /* lock the kernel */
  LOCK_KERNEL()
  /* store information for error hook routine */
  STORE_SERVICE(OSServiceId_TerminateTask)
  /* check interrupts are not disabled by user */
  CHECK_INTERRUPT_LOCK(result)
  /* check we are at the task level */
  CHECK_TASK_CALL_LEVEL_ERROR(core_id,result)
  /* check the task does not own a resource */
  CHECK_RUNNING_OWNS_REZ_ERROR(core_id, result)
  /*  checks the task does not occupy spinlock(s)   */
  CHECK_SCHEDULE_WHILE_OCCUPED_SPINLOCK(core_id, result)

#if TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /* the activate count is decreased */
    TPL_KERN(core_id).running->activate_count--;

    /* terminate the running task */
    tpl_terminate();
    /* task switching should occur */
    TPL_KERN(core_id).need_switch = NEED_SWITCH;
    /* start the highest priority process */
    tpl_start(CORE_ID_OR_NOTHING(core_id));

    SWITCH_CONTEXT_NOSAVE(CORE_ID_OR_NOTHING(core_id))
  }
#endif

  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()

  l_buffer = (tpl_checkpoint_buffer + 1) % 2;
  tpl_save_checkpoint(l_buffer);
  tpl_checkpoint_buffer = l_buffer;
  
  /* Choose one: Shutdown or periodic check of battery */
  
  // Shutdown

  tpl_shutdown(); //on msp430 => LPM4
	
  // Periodic check
  //RTCCTL0_H = RTCKEY_H;                     						// Unlock RTC key protected registers
  //RTCCTL0_L = RTCRDYIE;
  //RTCCTL1 = RTCBCD | RTCHOLD;
  //RTCYEAR = 0x2021;
  //RTCMON = 0x9;
  //RTCDAY = 0x11;
  //RTCDOW = 0x03;
  //RTCHOUR = 0x10;
  //RTCMIN = 0x32;
  //RTCSEC = 0x15;
  //RTCCTL1 &= ~(RTCHOLD);
  
  //#define RESUME_FROM_HIBERNATE_THRESHOLD (3000)
  //uint16 flag = 1;
  //uint16 vcc = 0;
  
  //while(flag){
	  //vcc = conversion_adc();
	  //if(vcc>RESUME_FROM_HIBERNATE_THRESHOLD){
		  //RTCCTL1 |= RTCHOLD;
		  //flag = 0;
		  //break;
	  //}
	  //else{
		  //disable_irq_for_hibernate();	
		  //__bis_SR_register(LPM3_bits);
		  //__bic_SR_register(GIE);
		  //restore_irq_for_hibernate();
	  //}
  //}	  
  PROCESS_ERROR(result)
}

FUNC(void, OS_CODE) tpl_restart_os_service(void)
{
  GET_CURRENT_CORE_ID(core_id)

    //#if (WITH_ERROR_HOOK == YES) || (WITH_OS_EXTENDED == YES) | (WITH_ORTI == YES)
  /*  init the error to no error  */
    //  VAR(tpl_status, AUTOMATIC) result = E_OK;
    //#endif

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_StartOS)
  STORE_MODE(mode);

  //  CHECK_OS_NOT_STARTED(core_id, result)

  //  IF_NO_EXTENDED_ERROR(result)
  //  {
  //#if NUMBER_OF_CORES > 1
    /*
     * Sync barrier at start of tpl_start_os_service.
     */
  //    tpl_sync_barrier(&tpl_start_count_0, &tpl_startos_sync_lock);
  //#endif

  //    TRACE_TPL_INIT()

      //    tpl_init_os(mode);

      //    tpl_enable_counters();

    /*
     * Call the startup hook. According to the spec, it should be called
     * after the os is initialized and before the scheduler is running
     */
      //    CALL_STARTUP_HOOK()

    /*
     * Call the OS Application startup hooks if needed
     */
      //    CALL_OSAPPLICATION_STARTUP_HOOKS()

  //#if NUMBER_OF_CORES > 1
    /*
     * Sync barrier just before starting the scheduling.
     */
  //    tpl_sync_barrier(&tpl_start_count_1, &tpl_startos_sync_lock);
  //#endif

    /*
     * Call tpl_start_scheduling to elect the highest priority task
     * if such a task exists.
     */

  tpl_load_checkpoint(tpl_checkpoint_buffer);

    /* Posix */
  //    SWITCH_CONTEXT_NOSAVE(core_id)
      //  }

  PROCESS_ERROR(result)
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) RestartOS(void)
{
  GET_CURRENT_CORE_ID(core_id)

  tpl_init_machine();
#if WITH_MODULES_INIT == YES
  /* Call inits for kernel modules. Generated function */
  tpl_init_modules();
#endif
  tpl_restart_os();
  /*
   * tpl_start_os does not return since the idle task will run
   * if no other task is AUTOSTART except if it is called from
   * within a task or an ISR of (which is forbidden).
   */
}

/* End of file tpl_os_checkpoint_kernel.c */

