/**
 * @file autosar_tp_s2/autosar_tp_s2.c
 *
 * @section desc File description
 *
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


StatusType instance_t3 = 0;

#include "tp.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h" /* FIXME: bypass to tpl_kern, should be updated */
#include "tpl_os_time_model.h"

#define APP_Task_t1_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
    initBoard();
    tpl_init_tp();
    tpl_start_enforcement_timer();
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareEvent(t1_event1);
DeclareEvent(t3_event1);
DeclareScheduleTable(sched1);

TASK(t1)
{
    uint8 instance_t1 = 0;
    while(1)
    {
        instance_t1++;
        switch (instance_t1)
        {
            case 1 :
                {
                    WaitEvent(t1_event1);
                    ClearEvent(t1_event1);
                    break;
                }
            case 2 :
                {
                    WaitEvent(t1_event1);
                    ClearEvent(t1_event1);
                    ActivateTask(t2);
                    break;
                }
            case 3 :
                {
                    WaitEvent(t1_event1);
                    ClearEvent(t1_event1);
                    StopScheduleTable(sched1);
                    SetEvent(t3, t3_event1);
                    ActivateTask(t4);
                    /* here the time enforcement should trigger the timing
                     * protection, so code below shall not be executed */
                    ledOn(ORANGE);
                    break;
                }
        }
        TerminateTask();
    }
}


TASK(t2)
{
    TerminateTask();
}

TASK(t3)
{
    uint8 instance_t3 = 0;

    WaitEvent(t3_event1);
    ClearEvent(t3_event1);
    /* here the time enforcement should trigger the timing
     * protection, so code below shall not be executed */
    ledOn(ORANGE);
    TerminateTask();
}

TASK(t4)
{
  ShutdownOS(E_OK);
}


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Mandatory for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

FUNC(void, OS_CODE) PreUserServiceHook(void *arg1, void *arg2, void *arg3, uint32 serviceID) {
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
            while( (cpt < transition_count) && (transition_set[cpt].service_id < serviceID) )
            {
                cpt++;
            }

            if (transition_set[cpt].service_id == serviceID) {
                tpl_te_transition const * transition = &(transition_set[cpt]);

                /* Wait for eft if the transistion has been fired early */
                tpl_te_earliest_firing_time eft = transition->eft;
                uint32 currentTime = tpl_get_enforcement_timer();
                tpl_wait_enforcement_timer(currentTime, currentTime+eft);

                /* Update current state */
                tpl_te_current_state[running] = transition->target_state;
            }
        }
    }
}

FUNC(void, OS_CODE) PostUserServiceHook(void *arg1, void *arg2, void *arg3, uint32 serviceID) {
    tpl_set_enforcement_timer(0);
}

FUNC(void, OS_CODE) ShutdownHook(StatusType error)
{ 
    ledOn(RED); 
}

FUNC(ProtectionReturnType, OS_CODE) ProtectionHook(StatusType Fatalerror)
{
    static uint8 instance_protection = 0;
	
    instance_protection++;
	switch (instance_protection)
	{
		case 1 :
		{
			ledOn(GREEN);
            break;
		}
		case 2 :
		{
			ledOn(BLUE);
            break;
		}
	}
  return PRO_TERMINATETASKISR;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file autosar_tp_s2.c */
