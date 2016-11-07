/**
 * @file events_s2_non/task1_instance.c
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

DeclareTask(t1);
DeclareTask(t2);
DeclareEvent(Event1);
DeclareEvent(Event2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_0, result_inst_2, result_inst_3, result_inst_5, result_inst_6, result_inst_7,  result_inst_9, result_inst_10, result_inst_11;
	EventMaskType result_inst_1, result_inst_4, result_inst_8;

	SCHEDULING_CHECK_INIT(5);
	result_inst_0 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_0);
		
	SCHEDULING_CHECK_INIT(6);
	result_inst_2 = GetEvent(t2,&result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(6,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_3 = SetEvent(t1,Event1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_5 = GetEvent(t1,&result_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(8,Event1, result_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_6 = WaitEvent(Event1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_6);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_7 = ClearEvent(Event1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_7);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_9 = GetEvent(t1,&result_inst_8);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(11,E_OK, result_inst_8);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_10 = SetEvent(t2,Event2);	
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_10);
		
	SCHEDULING_CHECK_INIT(13);
	result_inst_11 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_11);

}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq2_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}

/* End of file events_s2_non/task1_instance.c */
