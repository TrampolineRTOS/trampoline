/**
 * @file tasks_s14_non/task7_instance.c
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

/*Instance of task t7*/

#include "tpl_os.h"

DeclareEvent(Task7_Event1);
DeclareEvent(Task7_Event2);
DeclareEvent(Task7_Event3);
DeclareEvent(Task7_Event4);
DeclareEvent(Task7_Event5);
DeclareEvent(Task7_Event6);
DeclareEvent(Task7_Event7);
DeclareEvent(Task7_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t7_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	
	SCHEDULING_CHECK_INIT(70);
	result_inst_1 = ClearEvent(Task7_Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(70,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(71);
	result_inst_2 = ClearEvent(Task7_Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(71,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(72);
	result_inst_3 = ClearEvent(Task7_Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(72,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(73);
	result_inst_4 = ClearEvent(Task7_Event4);
	SCHEDULING_CHECK_AND_EQUAL_INT(73,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(74);
	result_inst_5 = ClearEvent(Task7_Event5);
	SCHEDULING_CHECK_AND_EQUAL_INT(74,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(75);
	result_inst_6 = ClearEvent(Task7_Event6);
	SCHEDULING_CHECK_AND_EQUAL_INT(75,E_OK , result_inst_6);
	
	SCHEDULING_CHECK_INIT(76);
	result_inst_7 = ClearEvent(Task7_Event7);
	SCHEDULING_CHECK_AND_EQUAL_INT(76,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(77);
	result_inst_8 = ClearEvent(Task7_Event8);
	SCHEDULING_CHECK_AND_EQUAL_INT(77,E_OK , result_inst_8);
	
	SCHEDULING_CHECK_INIT(78);
	result_inst_9 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(78,E_OK , result_inst_9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t7_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t7_instance",test_t7_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}

/* End of file tasks_s14_non/task7_instance.c */
