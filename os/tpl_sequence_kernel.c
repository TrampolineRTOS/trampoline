/**
 * @file tpl_sequence_kernel.c
 *
 * @section descr File description
 *
 * Trampoline sequence os services implementation.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de
 * Nantes Trampoline is protected by the French intellectual property law.
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

#include "tpl_sequence_kernel.h"
#include "tpl_chkpt_checkpoint_kernel.h"
#include "tpl_machine_interface.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_os_hooks.h"
#include "tpl_os_kernel.h"
#include "tpl_os_os_kernel.h"
#include "tpl_trace.h"

#include "msp430.h"

#include "tpl_chkpt_adc.h"

#include <stdint.h>

#if WITH_SEQUENCING == YES

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
STATIC VAR(tpl_application_mode, OS_VAR) application_mode_sequence = NOAPPMODE;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

// void init_adc() {

//   static uint8_t use1V2Ref = 0;

//   ADC12CTL0 &= ~ADC12ENC;                     // disable ADC
//   ADC12CTL0 = ADC12ON | ADC12SHT0_2;
//   ADC12CTL1 = ADC12SSEL_0 | ADC12DIV_7;       // ADC12OSC as ADC12CLK (~5MHz)
//   / 8 ADC12CTL3 = ADC12TCMAP | ADC12BATMAP;       // Map Temp and BAT
//   ADC12CTL1 |= ADC12SHP;                      // ADCCLK = MODOSC; sampling
//   timer ADC12CTL2 |= ADC12RES_2;                    // 12-bit resolution
//   while (REFCTL0 & REFGENBUSY);               // If ref generator busy, WAIT
//   if (use1V2Ref) {
//     REFCTL0 = REFON | REFVSEL_0;                // 1.2V reference
//     ADC12MCTL0 = ADC12INCH_31 | ADC12VRSEL_1;   // idem. Channel 31 is AVCC/2
//   }
//   else {
//     REFCTL0 = REFON | REFVSEL_1;                // 2V reference
//     ADC12MCTL0 = ADC12INCH_31 | ADC12VRSEL_1;   // idem. Channel 31 is AVCC/2
//   }

//   if (REFCTL0 & REFON) while (!(REFCTL0 & REFGENRDY)); // wait till ref
//   generator ready ADC12CTL0 |= ADC12ENC;
// 	return;
// }

// uint16 tpl_ADC_read(){
// 	ADC12CTL0 |= ADC12SC;
// 	while(!(ADC12IFGR0 & BIT0));
// 	return ADC12MEM0;
// }

// void end_adc()
// {
//   ADC12CTL0 &= ~ADC12ENC;
//   ADC12CTL0 &= ~ADC12ON;
//   return;
// }

FUNC(void, OS_CODE)
tpl_init_sequence_os(CONST(tpl_application_mode, AUTOMATIC) app_mode)
{
  GET_CURRENT_CORE_ID(core_id);
  VAR(uint16, AUTOMATIC) i;
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  /*  Start the idle task */
#if NUMBER_OF_CORES == 1
  result = tpl_activate_task(IDLE_TASK_ID);
#else
  result = tpl_activate_task(IDLE_TASK_0_ID + tpl_get_core_id());
#endif

  /*  Init the Ioc's unqueued buffer */
#if ((WITH_IOC == YES) && (IOC_UNQUEUED_COUNT > 0))
  {
    tpl_ioc_init_unqueued();
  }
#endif

  /* Get energy level from ADC */
  tpl_adc_init_simple();
  /* Polling */
  uint16 energy = readPowerVoltage_simple();
  // end_adc();
  /* Compare energy level with energy from sequences with FROM_STATE =
   * tpl_kern_seq->state */
  CONSTP2CONST(tpl_sequence_ref, AUTOMATIC, OS_VAR)
  ptr_state = tpl_sequence_state[tpl_kern_seq.state];
  // tpl_sequence **ptr_state = tpl_sequence_state[tpl_kern_seq.state];
  for (i = 0; i < ENERGY_LEVEL_COUNT; i++)
  {
    CONSTP2CONST(tpl_sequence, AUTOMATIC, OS_VAR) ptr_seq = ptr_state[i];
    // tpl_sequence *ptr_seq = ptr_state[i];
    if (energy >= ptr_seq->energy)
    {
      tpl_kern_seq.elected =
          (CONSTP2VAR(tpl_sequence, AUTOMATIC, OS_VAR))ptr_seq;
      break;
    }
  }

  /* Activate tasks from the sequence */
  P2CONST(uint8, AUTOMATIC, OS_VAR) ptr = tpl_kern_seq.elected->seqTaskTab;
  // uint8 *ptr = tpl_kern_seq.elected->seqTaskTab;
  for (i = 0; i < tpl_kern_seq.elected->nb_task; i++)
  {
    result = tpl_activate_task(*ptr);
    ptr++;
  }

/* Activate alarms from the sequence */
#if ALARM_COUNT > 0

  P2CONST(tpl_sequence_alarm, AUTOMATIC, OS_VAR)
  ptr_al = tpl_kern_seq.elected->seqAlarmTab;
  // tpl_sequence_alarm *ptr_al = tpl_kern_seq.elected->seqAlarmTab;

  for (i = 0; i < tpl_kern_seq.elected->nb_alarm; i++)
  {
    /* yep we can't do Syscall :( */
    // tpl_set_abs_alarm_service(tpl_alarm_table[ptr_al->al_id],
    // ptr_al->al_alarmTime, ptr_al->al_cycleTime);
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
    alarm = tpl_alarm_table[ptr_al->al_id];
    TPL_UPDATE_COUNTERS(alarm);
    if (alarm->state == (tpl_time_obj_state)ALARM_SLEEP)
    {
      /* the alarm is not in use, proceed */
      alarm->date = ptr_al->al_alarmTime;
      alarm->cycle = ptr_al->al_cycleTime;
      alarm->state = ALARM_ACTIVE;
      tpl_insert_time_obj(alarm);
    }
    else
    {
      /* the alarm is in use, ? */
      /* Should never happend */
    }
    TPL_ENABLE_SHAREDSOURCE(alarm);
    ptr_al++;
  }
#endif
  /* Update tpl_kern_seq.state with next state from sequence elected */
  tpl_kern_seq.state = tpl_kern_seq.elected->to_state;
}

FUNC(void, OS_CODE)
tpl_start_os_sequence_service(CONST(tpl_application_mode, AUTOMATIC) mode)
{
  GET_CURRENT_CORE_ID(core_id)
  tpl_init_machine();
#if WITH_MODULES_INIT == YES
  tpl_init_modules();
#endif
#if (WITH_ERROR_HOOK == YES) || (WITH_OS_EXTENDED == YES) | (WITH_ORTI == YES)
  /*  init the error to no error  */
  VAR(tpl_status, AUTOMATIC) result = E_OK;
#endif
  /*  lock the kernel    */
  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_StartOSSequence)
  STORE_MODE(mode)

  CHECK_OS_NOT_STARTED(core_id, result)

  IF_NO_EXTENDED_ERROR(result)
  {
    application_mode_sequence = mode;

    tpl_init_sequence_os(mode);

    tpl_enable_counters();

    /*
     * Call the startup hook. According to the spec, it should be called
     * after the os is initialized and before the scheduler is running
     */
    CALL_STARTUP_HOOK()

    /*
     * Call the OS Application startup hooks if needed
     */
    CALL_OSAPPLICATION_STARTUP_HOOKS()

    /*
     * Call tpl_start_scheduling to elect the highest priority task
     * if such a task exists.
     */

    tpl_start_scheduling(CORE_ID_OR_NOTHING(core_id));

    SWITCH_CONTEXT_NOSAVE(core_id)
  }

  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()
}


FUNC(void, OS_CODE) tpl_choose_next_sequence(void){
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /* update mask for task in tpl_kern_seq */
  tpl_kern_seq.elected->mask_seq_terminate &= ~(1<<TPL_KERN(core_id).s_running->id);

  /* test if all task from sequence are terminated */
  if (tpl_kern_seq.elected->mask_seq_terminate == 0x00)
  {
    /* reset task_terminate */
    tpl_kern_seq.elected->mask_seq_terminate =
        tpl_kern_seq.elected->vec_seq_terminate;

    VAR(uint16, AUTOMATIC) i;
    CONSTP2CONST(tpl_sequence_ref, AUTOMATIC, OS_VAR)
    ptr_state = tpl_sequence_state[tpl_kern_seq.state];
    // tpl_sequence **ptr_state = tpl_sequence_state[tpl_kern_seq.state];
    P2VAR(tpl_sequence, AUTOMATIC, OS_VAR) ptr_seq = NULL;
    P2VAR(tpl_sequence, AUTOMATIC, OS_VAR) tmp_ptr_seq = NULL;

    while (ptr_seq == NULL)
    {
      /* Get energy level from ADC */
      tpl_adc_init_simple();
      /* Polling */
      uint16 energy = readPowerVoltage_simple();
      // end_adc();

      for (i = 0; i < ENERGY_LEVEL_COUNT; i++)
      {
        tmp_ptr_seq = (P2VAR(tpl_sequence, AUTOMATIC, OS_VAR))ptr_state[i];
        if (energy >= tmp_ptr_seq->energy)
        {
          tpl_kern_seq.elected = tmp_ptr_seq;
          ptr_seq = tmp_ptr_seq;
          break;
        }
      }
      /* Not enough energy to elect next sequence --> hibernate */
      if (ptr_seq == NULL)
      {
        tpl_chkpt_hibernate();
      }
    }

    /* Activate tasks from the sequence */
    P2CONST(uint8, AUTOMATIC, OS_VAR) ptr = tpl_kern_seq.elected->seqTaskTab;
    // uint8 *ptr = tpl_kern_seq.elected->seqTaskTab;
    for (i = 0; i < tpl_kern_seq.elected->nb_task; i++)
    {
      result = tpl_activate_task(*ptr);
      ptr++;
    }

    /* Activate alarms from the sequence */

#if ALARM_COUNT > 0

    // CONSTP2VAR(tpl_sequence_alarm, AUTOMATIC, OS_VAR) ptr_al =
    // tpl_kern_seq.elected->seqAlarmTab;
    tpl_sequence_alarm *ptr_al = tpl_kern_seq.elected->seqAlarmTab;

    for (i = 0; i < tpl_kern_seq.elected->nb_alarm; i++)
    {

      P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm;
      P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) cnt;
      VAR(tpl_tick, AUTOMATIC) date;

      alarm = tpl_alarm_table[ptr_al->al_id];
      TPL_UPDATE_COUNTERS(alarm);
      if (alarm->state == (tpl_time_obj_state)ALARM_SLEEP)
      {
        /* the alarm is not in use, proceed */
        cnt = alarm->stat_part->counter;
        date = cnt->current_date + ptr_al->al_alarmTime;
        if (date > cnt->max_allowed_value)
        {
          date -= (cnt->max_allowed_value + 1);
        }

        alarm->date = date;
        alarm->cycle = ptr_al->al_cycleTime;
        alarm->state = ALARM_ACTIVE;
        tpl_insert_time_obj(alarm);
      }
      else
      {
        /* the alarm is in use, ? */
      }
      TPL_ENABLE_SHAREDSOURCE(alarm);
      ptr_al++;
    }
#endif
    /* Update tpl_kern_seq.state with next state from sequence elected */
    tpl_kern_seq.state = tpl_kern_seq.elected->to_state; 
  }
}

FUNC(void, OS_CODE) tpl_terminate_task_sequence_service(void){

  GET_CURRENT_CORE_ID(core_id)

  /* init the error to no error */
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /* lock the kernel */
  LOCK_KERNEL()
  /* store information for error hook routine */
  STORE_SERVICE(OSServiceId_TerminateTaskSequence)
  /* check interrupts are not disabled by user */
  CHECK_INTERRUPT_LOCK(result)
  /* check we are at the task level */
  CHECK_TASK_CALL_LEVEL_ERROR(core_id, result)
  /* check the task does not own a ressource */
  CHECK_RUNNING_OWNS_REZ_ERROR(core_id, result)
  /* check the task does not occupy spinlock(s) */
  CHECK_SCHEDULE_WHILE_OCCUPED_SPINLOCK(core_id, result)

#if TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result){
    /* the activate count is decreased */
    TPL_KERN(core_id).running->activate_count--;
    /* terminate the running task */
    tpl_terminate();
    /* task switching should occur */
    TPL_KERN(core_id).need_switch = NEED_SWITCH;
  }
#endif

  /* unlock kernel */
  UNLOCK_KERNEL()
  
  tpl_choose_next_sequence();

  /* start the highest priority process */
  tpl_start(CORE_ID_OR_NOTHING(core_id));
  SWITCH_CONTEXT_NOSAVE(CORE_ID_OR_NOTHING(core_id))

  PROCESS_ERROR(result)
  return;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif // WITH_SEQUENCING