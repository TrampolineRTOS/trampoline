

/**
 * @file efm32wg_low_power.h
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
#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_os_definitions.h"
#include "tpl_machine.h"
#include "tpl_cortex_definitions.h"
#include "tpl_os.h" 

#include "em_emu.h"
#include "em_rtc.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"

typedef VAR(uint8_t, AUTOMATIC)  EnergyModeType;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_start_systick_service(void);

FUNC(void, OS_CODE) tpl_stop_systick_service(void);

FUNC(void, OS_CODE) tpl_enter_low_power_service(CONST(uint8_t, AUTOMATIC) low_power_mode);

FUNC(void, OS_CODE)RTC_IRQ_Handler(void);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
