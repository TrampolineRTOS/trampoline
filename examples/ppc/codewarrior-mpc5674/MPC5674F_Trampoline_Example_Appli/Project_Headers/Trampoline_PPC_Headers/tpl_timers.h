/**
 * @file tpl_timers.h
 *
 * @section descr File description
 *
 * Trampoline machine dependant functions
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * MPC5674F port - copyright(c) 2016 propriété de l'IRT Saint Exupery, tous droits reservés
 *
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


#include "tpl_app_define.h"


#ifndef TPL_TIMERS_H
#define TPL_TIMERS_H

/* MPC5674F_Porting_Modif : Add the addresses of PIT configuration registers */ 
#define PIT_BASE_ADDR    0xC3FF0000
#define PIT_MCR_ADDR     0x000
#define PIT_LDVAL_ADDR   0x100
#define PIT_CVAL_ADDR    0x104
#define PIT_TCTRL_ADDR   0x108
#define PIT_TFLG_ADDR    0x10C

#define PIT_MCR_FRZ     ((uint32)0x1<<0U)
#define PIT_MCR_MDIS    ((uint32)0x1<<1U)
#define PIT_TCTRL_TEN   ((uint32)0x1<<0U)
#define PIT_TCTRL_TIE   ((uint32)0x1<<1U)
#define PIT_TFLG_TIF    ((uint32)0x1<<0U)

/* MISRA RULE 19.7 VIOLATION: this macro is used to compute pit adresses,
 * it would be very inefficient to use a function here, and this part
 * of code has to be kept the fastest possible
 */
#define PIT_MCR         ((volatile uint32*)(PIT_BASE_ADDR + PIT_MCR_ADDR))
#define PIT_LDVAL(pit)  ((volatile uint32*)(PIT_BASE_ADDR + PIT_LDVAL_ADDR + ((pit)<<4)))
#define PIT_CVAL(pit)   ((volatile uint32*)(PIT_BASE_ADDR + PIT_CVAL_ADDR + ((pit)<<4)))
#define PIT_TCTRL(pit)  ((volatile uint32*)(PIT_BASE_ADDR + PIT_TCTRL_ADDR + ((pit)<<4)))
#define PIT_TFLG(pit)   ((volatile uint32*)(PIT_BASE_ADDR + PIT_TFLG_ADDR + ((pit)<<4)))


#define TPL_PIT_VALUE(value) ((uint32)(TPL_PIT_RATIO*value))

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern FUNC(void, OS_CODE) tpl_init_pit(void);

extern FUNC(void, OS_CODE) tpl_load_pit(
  VAR(uint8, AUTOMATIC) pit,
  VAR(uint32, AUTOMATIC) ticks);

extern FUNC(void, OS_CODE) tpl_stop_pit(
  VAR(uint8, AUTOMATIC) pit);

#if WITH_AUTOSAR_TIMING_PROTECTION == YES
extern FUNC(void, OS_CODE) tpl_watchdog_handler(void);
#endif

#if TPL_TICK_TIMER != TPL_DECREMENTER
extern FUNC(void, OS_CODE) tpl_tick_handler(void);
#endif

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif

