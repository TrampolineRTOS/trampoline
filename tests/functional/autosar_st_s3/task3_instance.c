/**
 * @file autosar_st_s3/task3_instance.c
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

/*Instance of task t3*/

#include "Os.h"

DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
		
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_2 = ClearEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_3 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_4 = ClearEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_5 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_6 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(22,E_OK, result_inst_6);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq3_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}

/* End of file autosar_st_s3/task3_instance.c */
