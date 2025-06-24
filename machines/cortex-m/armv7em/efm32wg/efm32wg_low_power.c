

/**
 * @file efm32wg_low_power.c
 *
 * @section descr File description
 *
 * Trampoline kernel structures and functions. These functions are used
 * internally by trampoline and should not be used directly.
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

#include "efm32wg_low_power.h"
#include "tpl_os_kernel.h"
#include "tpl_os_timeobj_kernel.h"

typedef VAR(uint8_t, AUTOMATIC)  EnergyModeType;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_start_systick_service(void){
    tpl_set_systick_timer();
}

FUNC(void, OS_CODE) tpl_stop_systick_service(void){
    /* Disable SysTick Timer */
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

FUNC(void, OS_CODE) tpl_enter_low_power_service(CONST(uint8_t, AUTOMATIC) low_power_mode){
    /* First stop systick */
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    /* Set RTC priority < SVC */
    NVIC_SetPriority(RTC_IRQn, 0);
    /* Now program RTC */
    CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
    CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
    CMU_ClockEnable(cmuClock_RTC, true);
    RTC_Init_TypeDef rtcInit = RTC_INIT_DEFAULT;
    rtcInit.enable = false;
    rtcInit.debugRun = true;
    RTC_Init(&rtcInit);
    // RTC_CounterReset();
	RTC_CompareSet(0, 32);
    RTC_CompareSet(1, 0xFFFFFFFF);
    NVIC_ClearPendingIRQ(RTC_IRQn);
    NVIC_EnableIRQ(RTC_IRQn);
    RTC_IntEnable(RTC_IF_COMP0);
    /* Switch based on Low Power Mode from OIL */
    switch (low_power_mode){
        case EM1_POWER_MODE:
            RTC_Enable(true);
            EMU_EnterEM1();
            RTC_Enable(false);
            break;
        case EM2_POWER_MODE:
            RTC_Enable(true);
            EMU_EnterEM2(true);
            RTC_Enable(false);
            break;
        case EM3_POWER_MODE:
            RTC_Enable(true);
            EMU_EnterEM3(true);
            RTC_Enable(false);
            break;
        default:
            break;
    }
}

/*
 * tpl_sleep is used by the idle task
 */
void idle_function(void)
{
    while(1)
  {
    #if IDLE_POWER_MODE != ACTIVE_POWER_MODE
    EnterLowPower(IDLE_POWER_MODE);
    #else
    __WFE();
    #endif
  }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#if IDLE_POWER_MODE != ACTIVE_POWER_MODE
FUNC(void, OS_CODE) RTC_IRQ_Handler(void){
    /* Clear flag */
    RTC_IntClear(RTC_IF_COMP0);
    /* Tick every second */
    CONSTP2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter = &SystemCounter_counter_desc;
    tpl_counter_tick(counter);
    if (tpl_kern.need_schedule == TRUE)
    {
        tpl_schedule_from_running();
        tpl_start_systick_service();
        LOCAL_SWITCH_CONTEXT()
    }
}
#endif
