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

// #include "tpl_os_kernel.h"
// #include "tpl_os_os_kernel.h"
#include "tpl_os_error.h"
#include "tpl_os_definitions.h"


#if WITH_SEQUENCING == YES

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

// FUNC(void, OS_CODE) tpl_start_from_trace(CORE_ID_OR_VOID(core_id))
// {
//   GET_TPL_KERN_FOR_CORE_ID(core_id, kern)

//   CONST(tpl_heap_entry, AUTOMATIC)
//   proc = tpl_remove_front_proc(CORE_ID_OR_NOTHING(core_id));

//   TPL_KERN_REF(kern).elected_id = (uint32)proc.id;
//   TPL_KERN_REF(kern).elected = tpl_dyn_proc_table[proc.id];
//   TPL_KERN_REF(kern).s_elected = tpl_stat_proc_table[proc.id];

//   if (TPL_KERN_REF(kern).elected->state == READY_AND_NEW)
//   {
//     /*
//      * the object has not be preempted. So its
//      * descriptor must be initialized
//      */
//     tpl_init_proc(proc.id);
//     tpl_dyn_proc_table[proc.id]->priority = proc.key;
//   }
//   TPL_KERN_REF(kern).need_schedule = FALSE;
// }

FUNC(void, OS_CODE) tpl_init_sequence_os(CONST(tpl_application_mode, AUTOMATIC) app_mode)
{
  GET_CURRENT_CORE_ID(core_id)
#if TASK_COUNT > 0 || ALARM_COUNT > 0 || SCHEDTABLE_COUNT > 0
  VAR(uint16, AUTOMATIC) i;
  CONST(tpl_appmode_mask, AUTOMATIC) app_mode_mask = 1 << app_mode;
#endif
  VAR(tpl_status, AUTOMATIC) result = E_OK;
#if ALARM_COUNT > 0
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) auto_time_obj;
#endif

#if (WITH_AUTOSAR == YES) && (ALARM_COUNT == 0) && (SCHEDTABLE_COUNT > 0)
  P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) auto_time_obj;
#endif

  /*  Start the idle task */
#if NUMBER_OF_CORES == 1
  result = tpl_activate_task(IDLE_TASK_ID);
#else
  result = tpl_activate_task(IDLE_TASK_0_ID + tpl_get_core_id());
#endif

  /*  Init the Ioc's unqueued buffer */
#if ((WITH_IOC == YES) && (IOC_UNQUEUED_COUNT > 0))
#if NUMBER_OF_CORES > 1
  /* Only one core must do this initialization */
  if (core_id == OS_CORE_ID_MASTER)
#endif
  {
    tpl_ioc_init_unqueued();
  }
#endif

/* On fait une mesure avec l'ADC pour avoir le niveau d'énergie*/
init_adc();
uint16 energy = tpl_ADC_read();                                                           // polling
/* On choisit la prochaine sequence en fonction de l'état courant et du niveau d'énergie */

/* On active toutes les tâches de la séquence choisie */

/* On active toutes les alarmes de la séquence choisie */

// #if TASK_COUNT > 0
//   /*  Look for autostart tasks    */
//   for (i = 0; i < TASK_COUNT; i++)
//   {
//     /*  each AUTOSTART task is activated if it belong to the  */
//     if (tpl_task_app_mode[i] & app_mode_mask)
//     {
// #if NUMBER_OF_CORES > 1
//       /* In multicore, we must check if the task belongs to the core */
//       if (tpl_stat_proc_table[i]->core_id == core_id)
// #endif
//       {
//         result = tpl_activate_task(i);
//       }
//     }
//   }
// #endif
// #if ALARM_COUNT > 0

//   /*  Look for autostart alarms    */

//   for (i = 0; i < ALARM_COUNT; i++)
//   {
//     if (tpl_alarm_app_mode[i] & app_mode_mask)
//     {
//       auto_time_obj =
//           (P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA))tpl_alarm_table[i];
// #if (NUMBER_OF_CORES > 1) && (WITH_OSAPPLICATION == YES)
//       /* In multicore, we must check if the alarm belongs to the core */
//       if (tpl_core_id_for_app[auto_time_obj->stat_part->app_id] == core_id)
// #endif
//       {
//         auto_time_obj->state = ALARM_ACTIVE;
//         tpl_insert_time_obj(auto_time_obj);
//       }
//     }
//   }

// #endif

}

FUNC(void, OS_CODE) tpl_start_os_sequence_service(
  CONST(tpl_application_mode, AUTOMATIC) mode)
{
  GET_CURRENT_CORE_ID(core_id)

#if (WITH_ERROR_HOOK == YES) || (WITH_OS_EXTENDED == YES) | (WITH_ORTI == YES)
  /*  init the error to no error  */
  VAR(tpl_status, AUTOMATIC) result = E_OK;
#endif
  /*  lock the kernel    */
  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_StartOS)
  STORE_MODE(mode);

  CHECK_OS_NOT_STARTED(core_id, result)

  IF_NO_EXTENDED_ERROR(result)
  {
#if NUMBER_OF_CORES > 1
    /*
     * Sync barrier at start of tpl_start_os_service.
     */
    tpl_sync_barrier(&tpl_start_count_0, &tpl_startos_sync_lock);

    application_mode[core_id] = mode;
#else
    application_mode = mode;
#endif

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

#if NUMBER_OF_CORES > 1
    /*
     * Sync barrier just before starting the scheduling.
     */
    tpl_sync_barrier(&tpl_start_count_1, &tpl_startos_sync_lock);
#endif

    /*
     * Call tpl_start_scheduling to elect the highest priority task
     * if such a task exists.
     */

    TPL_KERN_REF(kern).need_switch = NEED_SWITCH;

    tpl_start(CORE_ID_OR_NOTHING(core_id));

    SWITCH_CONTEXT_NOSAVE(core_id)
  }

  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif //WITH_SEQUENCING