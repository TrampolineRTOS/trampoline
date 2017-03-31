/**
 * @file te-example-ieeedt
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) LS2N 2005-2017
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

#include "tp.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h" /* FIXME: bypass to tpl_kern, should be updated */
#include "tpl_os_time_model.h"
#include "tpl_timing_protection.h"

#define APP_Task_t1_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
    initBoard();
    tpl_start_enforcement_timer();
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

FUNC(void, OS_APPL_CODE) waitMilliseconds(int milliseconds)
{
    volatile int i;
    for (i = 0; i < milliseconds*16800; i++);
}

DeclareEvent(e_t1_offset);
DeclareEvent(e_t2_timeout);
DeclareAlarm(a_t2_timeout);

TASK(t1)
{
    WaitEvent(e_t1_offset);

    /* do some computations */
    waitMilliseconds(8);

    TerminateTask();
}
#define APP_Task_t1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_t2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(t2)
{
    SetRelAlarm(a_t2_timeout, 17, 0);

    /* do some computations */
    waitMilliseconds(5);

    CancelAlarm(a_t2_timeout);
    TerminateTask();
}
#define APP_Task_t2_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_t3_START_SEC_CODE
#include "tpl_memmap.h"
TASK(t3)
{
    WaitEvent(e_t2_timeout);

    /* do some computation to recover t2 failure */
    waitMilliseconds(2);

    TerminateTask();
}
#define APP_Task_t3_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Mandatory for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

FUNC(void, OS_CODE) PreUserServiceHook(void *arg1, void *arg2, void *arg3, uint32 serviceID) {
//  ledOn(RED);
    /*
     * TODO: get proc_id through parameters
     * FIXME: not functionnal w/ memory protection activated
     */
    tpl_proc_id running = tpl_kern.running_id;

    /*
     *  When called byt StartOS, running_id is invalid
     */
    if (running != INVALID_PROC_ID)
    {
        /*
         * Identify the transitions that has been taken
         */
        if (tpl_state_table[running] != NULL) {

            tpl_te_model_state current_state         = tpl_te_current_state[running];
            tpl_te_transition const * transition_set = tpl_state_table[running][current_state].transitions;
            uint8 transition_count                   = tpl_state_table[running][current_state].count;

            uint8 cpt = 0;
            while( (cpt < transition_count) && (transition_set[cpt].service_id != serviceID) )
            {
                cpt++;
            }

            if (transition_set[cpt].service_id == serviceID) {
                tpl_te_transition const * transition = &(transition_set[cpt]);

                /* Wait for eft if the transistion has been fired early */
                tpl_te_earliest_firing_time eft = transition->eft;
                uint32 currentTime = tpl_get_enforcement_timer();
                if (currentTime < eft) {
//     ledOff(RED);
                 tpl_wait_enforcement_timer(currentTime, eft);
                }
                /* Update current state */
                tpl_te_current_state[running] = transition->target_state;
            }
        }
    }
//     ledOff(RED);
}

FUNC(void, OS_CODE) PostUserServiceHook(void *arg1, void *arg2, void *arg3, uint32 serviceID) {
    tpl_set_enforcement_timer(0);
}

FUNC(void, OS_CODE) StartupHook(void)
{
    tpl_init_tp();
}

FUNC(void, OS_CODE) ShutdownHook(StatusType error)
{
    ledOn(RED);
}

FUNC(ProtectionReturnType, OS_CODE) ProtectionHook(StatusType Fatalerror)
{
    ledOn(RED);
/*
    static uint8 instance_protection = 0;

    instance_protection++;
    switch (instance_protection)
    {
        case 1 :
            {
            }
            break;
        case 2 :
            {
                ledOn(GREEN);
            }
            break;
        default :
            break;
    }
 */
    return PRO_TERMINATETASKISR;
}

FUNC(void, OS_CODE) PreTaskHook(void)
{
  TaskType runningTask;
  GetTaskID(&runningTask);
  if      (runningTask == t1) ledOn(GREEN);
  else if (runningTask == t2) ledOn(BLUE);
  else if (runningTask == t3) ledOn(ORANGE);
}

FUNC(void, OS_CODE) PostTaskHook(void)
{
  TaskType runningTask;
  GetTaskID(&runningTask);
  if      (runningTask == t1) ledOff(GREEN);
  else if (runningTask == t2) ledOff(BLUE);
  else if (runningTask == t3) ledOff(ORANGE);
}


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file autosar_tp_s1.c */
