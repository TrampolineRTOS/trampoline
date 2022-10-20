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

#if WITH_CHECKPOINTING == YES

#include "tpl_os_os_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_machine_interface.h"
#include "tpl_trace.h"
#include "tpl_os_hooks.h"
#include "tpl_chkpt_checkpoint_kernel.h"

#include "msp430.h"
#include <stdint.h>

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

void init_adc() {

  static uint8_t use1V2Ref = 0;

  ADC12CTL0 &= ~ADC12ENC;                     // disable ADC
  ADC12CTL0 = ADC12ON | ADC12SHT0_2;          
  ADC12CTL1 = ADC12SSEL_0 | ADC12DIV_7;       // ADC12OSC as ADC12CLK (~5MHz) / 8
  ADC12CTL3 = ADC12TCMAP | ADC12BATMAP;       // Map Temp and BAT
  ADC12CTL1 |= ADC12SHP;                      // ADCCLK = MODOSC; sampling timer
  ADC12CTL2 |= ADC12RES_2;                    // 12-bit resolution
  while (REFCTL0 & REFGENBUSY);               // If ref generator busy, WAIT
  if (use1V2Ref) {
    REFCTL0 = REFON | REFVSEL_0;                // 1.2V reference
    ADC12MCTL0 = ADC12INCH_31 | ADC12VRSEL_1;   // idem. Channel 31 is AVCC/2
  }
  else {
    REFCTL0 = REFON | REFVSEL_1;                // 2V reference
    ADC12MCTL0 = ADC12INCH_31 | ADC12VRSEL_1;   // idem. Channel 31 is AVCC/2
  }

  if (REFCTL0 & REFON) while (!(REFCTL0 & REFGENRDY)); // wait till ref generator ready
  ADC12CTL0 |= ADC12ENC;
	return;
}

uint16 tpl_ADC_read(){
	ADC12CTL0 |= ADC12SC;
	while(!(ADC12IFGR0 & BIT0));
	// ADC12CTL0 &= ~(ADC12ENC);
	// REFCTL0 &= ~(REFON);
	return ADC12MEM0;
}

void tpl_RTC_init()
{

    // Unlock RTC key protected registers
    RTCCTL0_H = RTCKEY_H;
    // Clear RTCAIE RTCAIFG and AE bits to prevent potential erroneous alarm condition
    RTCCTL0_L &= ~RTCAIE;
    RTCCTL0_L &= ~RTCAIFG;
    // Calendar + Hold, Hexa code
    RTCCTL1 = RTCHOLD | RTCMODE;
    // Random year, day, month, day of week, hour, set minute and sec to 0
    RTCYEAR = 0x0000;
    RTCMON = 0x0;
    RTCDAY = 0x00;
    RTCDOW = 0x00;
    RTCHOUR = 0x0;
    RTCMIN = 0x00;
    RTCSEC = 0x00;
    // reset all register alarm because they are in undefined state when reset
    RTCAHOUR &= ~(0x80);
    RTCADOW &= ~(0x80);
    RTCADAY &= ~(0x80);
    // set alarm in next '1' minutes + enable interrupt
    #define PERIOD_WAKE_UP 0x01
    RTCAMIN = (PERIOD_WAKE_UP | (1<<7));
    // Interrupt from alarm                     						
    RTCCTL0_L = RTCAIE;
    // start rtc
    RTCCTL1 &= ~(RTCHOLD);
}

void tpl_RTC_stop()
{
		  // stop rtc
		  RTCCTL1 |= RTCHOLD;
}

void tpl_lpm_hibernate()
{
  /* Disable TIMER3_A0 interrupt 
     in LPM3, ACLK is still active
   */
	TA3CCTL0 &= ~CCIE;
  /* enters in LPM - enable interrupt for RTC*/
  __bis_SR_register(LPM3_bits + GIE);
  /* remove interrupts (we are in kernel mode) */
	__bic_SR_register(GIE);
 	/* Restore TIMER3_A0 interrupt */
  TA3CCTL0 |= CCIE;
}

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
  // tpl_save_checkpoint();
  tpl_save_checkpoint_dma(l_buffer);
  tpl_checkpoint_buffer = l_buffer;
  
  uint16_t waiting_loop = 1;
  init_adc();
  while(waiting_loop){
    tpl_RTC_init(); //startRTC => interrupt next 1 min
    if(tpl_ADC_read() > RESUME_FROM_HIBERNATE_THRESHOLD){
      tpl_RTC_stop();
		  waiting_loop = 0;
	  } else {
      tpl_lpm_hibernate();
	  }
  }
  PROCESS_ERROR(result)
}

#if __GXX_ABI_VERSION == 1011 || __GXX_ABI_VERSION == 1013
/* ISR1 related to RTC_VECTOR */
__attribute__((section (".irq_func")))
__interrupt void tpl_direct_irq_handler_RTC_VECTOR(void)
#elif __GXX_ABI_VERSION == 1002
void __attribute__((interrupt(RTC_VECTOR))) tpl_direct_irq_handler_RTC_VECTOR()
#else
    #error "Unsupported ABI"
#endif
{
  // Clear interrupt flag
  RTCCTL0_L &= ~RTCAIFG;
  // Exit LPM
  LPM3_EXIT;
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

  // tpl_load_checkpoint();
  tpl_load_checkpoint_dma(tpl_checkpoint_buffer);

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

#endif //WITH_CHECKPOINTING
