/**
 * @file hook_s2_full/posttask_instance2.c
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

/*Instance 2 of posttask hook routine*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"; /*for OSMAXALLOWEDVALUE_Counter1...*/

DeclareTask(t1);
DeclareAlarm(Alarm1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_posttask_instance2(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5;
	TaskType task_id;
	TaskStateType task_state;
	EventMaskType event_mask;
	AlarmBaseType alarm_base;
	TickType tik;
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_1 = GetTaskID(&task_id);	
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(19,t1 , task_id);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_2 = GetTaskState(task_id, &task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(20,WAITING , task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_3 = GetEvent(task_id,&event_mask);
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OK , result_inst_3);
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_4 = GetAlarmBase(Alarm1, &alarm_base);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(22,OSMAXALLOWEDVALUE_Counter1, (int)(alarm_base.maxallowedvalue));
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(22,OSTICKSPERBASE_Counter1, (int)(alarm_base.ticksperbase));
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(22,OSMINCYCLE_Counter1, (int)(alarm_base.mincycle));
	SCHEDULING_CHECK_AND_EQUAL_INT(22,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_5 = GetAlarm(Alarm1,&tik);
	SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OK , result_inst_5);
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_posttask_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_posttask_instance2",test_posttask_instance2)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}

/* End of file hook_s2_full/posttask_instance2.c */
