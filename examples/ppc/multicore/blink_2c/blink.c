/**
 * @file multicore/blink_2c/blink.c
 *
 * @section desc File description
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "Os.h"
#include "tpl_os.h"

#define APP_Task_t1_app1_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
VAR(uint32, AUTOMATIC) led_state1 = 0;
#define APP_Task_t1_app1_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define APP_Task_t1_app2_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
VAR(uint32, AUTOMATIC) led_state2 = 0;
#define APP_Task_t1_app2_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

DeclareTask(t1_app1);
DeclareTask(t1_app2);

#define APP_COMMON_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
#if NUMBER_OF_CORES > 1
    StatusType rv;

    switch(GetCoreID()){
      case OS_CORE_ID_MASTER :
        initLed();
        setLed(0, led_state1);
        /* Wakeup core 1 */
        StartCore(OS_CORE_ID_1, &rv);
        if(rv == E_OK)
          StartOS(OSDEFAULTAPPMODE);
        break;
      case OS_CORE_ID_1 :
        /* Core 1 : leds were already initialized by the core 0 at this step */
        setLed(1, led_state2);
        StartOS(OSDEFAULTAPPMODE);
        break;
      default :
        /* Should not happen */
        break;
    }
#else
    initLed();
    setLed(0, led_state1);
    StartOS(OSDEFAULTAPPMODE);
#endif

    return 0;
}
#define APP_COMMON_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_t1_app1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(t1_app1)
{
    led_state1 = !led_state1;
    setLed(0, led_state1);
    TerminateTask();
}
#define APP_Task_t1_app1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_t1_app2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(t1_app2)
{
    led_state2 = !led_state2;
    setLed(1, led_state2);
    TerminateTask();
}
#define APP_Task_t1_app2_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file blink.c */

