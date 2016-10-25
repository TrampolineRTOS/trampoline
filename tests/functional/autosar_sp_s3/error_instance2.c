/**
 * @file autosar_sp_s3/error_instance2.c
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

/*Instance 2 of error*/

#include "Os.h"

DeclareTask(t3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance2(void)
{
	extern StatusType error_status;
	StatusType result_inst_1, result_inst_2;
	TaskType TaskType_inst_1;
	TaskStateType TaskStateType_inst_1;
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_1 = GetTaskID(&TaskType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(7 , t3 , TaskType_inst_1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(7, E_OK , result_inst_1);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_2 = GetTaskState(TaskType_inst_1, &TaskStateType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(8 , RUNNING , TaskStateType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(8, E_OS_MISSINGEND , error_status);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq3_error_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance2",test_error_instance2)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}

/* End of file autosar_sp_s3/error_instance2.c */
