/**
 * @file multicore/blink_1c/blink.c
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
    uint32 led_state = 1;
#define APP_Task_t1_app1_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define APP_Task_t1_app1_START_SEC_CODE
#include "tpl_memmap.h"

DeclareTask(t1_app1);

int main(void)
{
    initLed();
    setLed(0, 1);

    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

TASK(t1_app1)
{
    setLed(2, led_state);
    led_state = led_state ? 0 : 1;
    TerminateTask();
}

#define APP_Task_t1_app1_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file blink.c */

