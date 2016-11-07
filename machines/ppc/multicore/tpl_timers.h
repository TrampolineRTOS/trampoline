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
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */


#include "tpl_app_define.h"


#ifndef TPL_TIMERS_H
#define TPL_TIMERS_H


#define TPL_PIT_VALUE(value) ((uint32)(TPL_WATCHDOG_RATIO*value))

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern FUNC(void, OS_CODE) tpl_init_pit(void);

#if 0 /* Moved to generated functions */
extern FUNC(void, OS_CODE) tpl_load_pit(
  VAR(uint8, AUTOMATIC) pit,
  VAR(uint32, AUTOMATIC) ticks);
/* Generated in goil */
extern FUNC(void, OS_CODE) tpl_load_pits(void);

extern FUNC(void, OS_CODE) tpl_start_pit(
  VAR(uint8, AUTOMATIC) pit);

extern FUNC(void, OS_CODE) tpl_stop_pit(
  VAR(uint8, AUTOMATIC) pit);

extern FUNC(tpl_bool, OS_CODE)  tpl_call_counter_tick();


#if WITH_AUTOSAR_TIMING_PROTECTION == YES
extern FUNC(tpl_bool, OS_CODE) tpl_watchdog_handler(void);
#endif
#endif


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif

