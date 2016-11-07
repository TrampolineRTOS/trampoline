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

#include "tpl_os.h"

DeclareAlarm(Alarm1);
DeclareEvent(Event1);
DeclareResource(Resource1);
DeclareTask(t2);


/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	AlarmBaseType AlarmBaseType_inst_1;
	EventMaskType EventMaskType_inst_1;
	StatusType result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17, result_inst_18, result_inst_19;
	TaskStateType TaskStateType_inst_1;
	TaskType TaskType_inst_1;
	TickType TickType_inst_1;
		
	SCHEDULING_CHECK_STEP(1);
	
	SCHEDULING_CHECK_STEP(2);
	SuspendAllInterrupts();
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OS_DISABLEDINT, result_inst_2);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_3 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_DISABLEDINT, result_inst_3);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_4 = ChainTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OS_DISABLEDINT, result_inst_4);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_5 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OS_DISABLEDINT, result_inst_5);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_6 = GetTaskID(&TaskType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OS_DISABLEDINT, result_inst_6);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_7 = GetTaskState(t2, &TaskStateType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OS_DISABLEDINT, result_inst_7);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_8 = GetResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OS_DISABLEDINT, result_inst_8);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_9 = ReleaseResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OS_DISABLEDINT, result_inst_9);
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_10 = SetEvent(t2, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OS_DISABLEDINT, result_inst_10);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_11 = ClearEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(22,E_OS_DISABLEDINT, result_inst_11);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_12 = GetEvent(t2, &EventMaskType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(24,E_OS_DISABLEDINT, result_inst_12);
	
	SCHEDULING_CHECK_INIT(25);
	result_inst_13 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(26,E_OS_DISABLEDINT, result_inst_13);
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_14 = GetAlarmBase(Alarm1, &AlarmBaseType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(28,E_OS_DISABLEDINT, result_inst_14);
	
	SCHEDULING_CHECK_INIT(29);
	result_inst_15 = GetAlarm(Alarm1, &TickType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(30,E_OS_DISABLEDINT, result_inst_15);
	
	SCHEDULING_CHECK_INIT(31);
	result_inst_16 = SetRelAlarm(Alarm1, 1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(32,E_OS_DISABLEDINT, result_inst_16);
	
	SCHEDULING_CHECK_INIT(33);
	result_inst_17 = SetAbsAlarm(Alarm1, 1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(34,E_OS_DISABLEDINT, result_inst_17);
	
	SCHEDULING_CHECK_INIT(35);
	result_inst_18 = CancelAlarm(Alarm1);
	SCHEDULING_CHECK_AND_EQUAL_INT(36,E_OS_DISABLEDINT, result_inst_18);
	
	SCHEDULING_CHECK_INIT(37);
	result_inst_19 = GetActiveApplicationMode();
	SCHEDULING_CHECK_AND_EQUAL_INT(38,OSDEFAULTAPPMODE, result_inst_19);
	
	SCHEDULING_CHECK_STEP(39);
	ResumeAllInterrupts();
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
