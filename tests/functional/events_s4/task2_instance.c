/**
 * @file events_s4/task2_instance.c
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

/*Instance of task t2*/

#include "tpl_os.h"

DeclareEvent(Event1);
DeclareTask(t1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_2 = ClearEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_3 = SetEvent(t1, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_4 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OK, result_inst_4);

	SCHEDULING_CHECK_INIT(17);
	result_inst_5 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK, result_inst_5);
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq4_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}

/* End of file events_s4/task2_instance.c */
