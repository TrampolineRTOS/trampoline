/**
 * @file hook_s2_full/pretask_instance4.c
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

/*Instance 4 of pretask hook routine*/

#include "tpl_os.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_pretask_instance4(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
	TaskType task_id;
	TaskStateType task_state;
	EventMaskType event_mask;
	
	SCHEDULING_CHECK_INIT(36);
	result_inst_1 = GetTaskID(&task_id);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(36,t2 , task_id); 
	SCHEDULING_CHECK_AND_EQUAL_INT(36,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(37);
	result_inst_2 = GetTaskState(task_id, &task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(37,RUNNING , task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT(37,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(38);
	result_inst_3 = GetEvent(task_id,&event_mask);
	SCHEDULING_CHECK_AND_EQUAL_INT(39,E_OS_ACCESS , result_inst_3);
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_pretask_instance4(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_pretask_instance4",test_pretask_instance4)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}

/* End of file hook_s2_full/pretask_instance4.c */
