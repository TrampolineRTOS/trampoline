/**
 * @file interrupts_s6/task1_instance.c
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

/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareAlarm(Alarm1);
DeclareEvent(Event1);
DeclareResource(Resource1);
DeclareTask(t2);
DeclareTask(t3);

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	AlarmBaseType AlarmBaseType_inst_1;
	EventMaskType EventMaskType_inst_1;
	StatusType result_inst_1;
	TaskStateType TaskStateType_inst_1;
	TaskType TaskType_inst_1;
	TickType TickType_inst_1;
		
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetTaskState(t3, &TaskStateType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(1, READY , TaskStateType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1, E_OK , result_inst_1);
	
	SCHEDULING_CHECK_STEP(2);
	SuspendAllInterrupts();
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_1 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_1 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_1 = ChainTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_1 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_1 = GetTaskID(&TaskType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_1 = GetTaskState(t2, &TaskStateType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_1 = GetResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_1 = ReleaseResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_1 = SetEvent(t3, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_1 = ClearEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_1 = GetEvent(t2, &EventMaskType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_1 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_1 = GetAlarmBase(Alarm1, &AlarmBaseType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_1 = GetAlarm(Alarm1, &TickType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_1 = SetRelAlarm(Alarm1, 1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_1 = SetAbsAlarm(Alarm1, 1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OS_DISABLEDINT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_1 = CancelAlarm(Alarm1);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OS_DISABLEDINT, result_inst_1);
		
	SCHEDULING_CHECK_STEP(20);
	ResumeAllInterrupts();

	/*check no event transmitted to t2?*/
	SCHEDULING_CHECK_INIT(21);
	result_inst_1 = GetEvent(t3, &EventMaskType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(21, 0 , EventMaskType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OK, result_inst_1);

}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq6_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence6",NULL,NULL,fixtures);

	return (TestRef)&InterruptProcessingTest;
}

/* End of file interrupts_s6/task1_instance.c */
