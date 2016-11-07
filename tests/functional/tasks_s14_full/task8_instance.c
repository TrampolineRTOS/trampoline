/**
 * @file tasks_s14_full/task8_instance.c
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

/*Instance of task t8*/

#include "tpl_os.h"

DeclareEvent(Task8_Event1);
DeclareEvent(Task8_Event2);
DeclareEvent(Task8_Event3);
DeclareEvent(Task8_Event4);
DeclareEvent(Task8_Event5);
DeclareEvent(Task8_Event6);
DeclareEvent(Task8_Event7);
DeclareEvent(Task8_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t8_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	
	SCHEDULING_CHECK_INIT(79);
	result_inst_1 = ClearEvent(Task8_Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(79,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(80);
	result_inst_2 = ClearEvent(Task8_Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(80,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(81);
	result_inst_3 = ClearEvent(Task8_Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(81,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(82);
	result_inst_4 = ClearEvent(Task8_Event4);
	SCHEDULING_CHECK_AND_EQUAL_INT(82,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(83);
	result_inst_5 = ClearEvent(Task8_Event5);
	SCHEDULING_CHECK_AND_EQUAL_INT(83,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(84);
	result_inst_6 = ClearEvent(Task8_Event6);
	SCHEDULING_CHECK_AND_EQUAL_INT(84,E_OK , result_inst_6);
	
	SCHEDULING_CHECK_INIT(85);
	result_inst_7 = ClearEvent(Task8_Event7);
	SCHEDULING_CHECK_AND_EQUAL_INT(85,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(86);
	result_inst_8 = ClearEvent(Task8_Event8);
	SCHEDULING_CHECK_AND_EQUAL_INT(86,E_OK , result_inst_8);
	
	SCHEDULING_CHECK_INIT(87);
	result_inst_9 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(87,E_OK , result_inst_9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t8_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t8_instance",test_t8_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}

/* End of file tasks_s14_full/task8_instance.c */
