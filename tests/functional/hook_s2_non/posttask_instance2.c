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

#include "tpl_os.h"

DeclareAlarm(Alarm1);
DeclareTask(INVALID_TASK);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_posttask_instance2(void)
{
	StatusType result_inst_1, result_inst_2;
	TaskType task_id;
	TickType tik;
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_1 = GetTaskID(&task_id);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(22,INVALID_TASK , task_id); 
	SCHEDULING_CHECK_AND_EQUAL_INT(22,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_2 = GetAlarm(Alarm1,&tik);
	SCHEDULING_CHECK_AND_EQUAL_INT(24,E_OS_NOFUNC , result_inst_2);
	
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
