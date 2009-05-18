/**
 * @file goil_s1/task1_instance.c
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

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Task1_Event1);
DeclareEvent(Task1_Event2);
DeclareEvent(Task1_Event3);
DeclareEvent(Task1_Event4);
DeclareEvent(Task1_Event5);
DeclareEvent(Task1_Event6);
DeclareEvent(Task1_Event7);
DeclareEvent(Task1_Event8);
DeclareEvent(Task1_Event9);
DeclareEvent(Task1_Event10);
DeclareEvent(Task1_Event11);
DeclareEvent(Task1_Event12);
DeclareEvent(Task1_Event13);
DeclareEvent(Task1_Event14);
DeclareEvent(Task1_Event15);
DeclareEvent(Task1_Event16);
DeclareEvent(Task1_Event17);
DeclareEvent(Task1_Event18);
DeclareEvent(Task1_Event19);
DeclareEvent(Task1_Event20);
DeclareEvent(Task1_Event21);
DeclareEvent(Task1_Event22);
DeclareEvent(Task1_Event23);
DeclareEvent(Task1_Event24);
DeclareEvent(Task1_Event25);
DeclareEvent(Task1_Event26);
DeclareEvent(Task1_Event27);
DeclareEvent(Task1_Event28);
DeclareEvent(Task1_Event29);
DeclareEvent(Task1_Event30);
DeclareEvent(Task1_Event31);
DeclareEvent(Task1_Event32);
DeclareTask(t1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17, result_inst_18, result_inst_19, result_inst_20, result_inst_21, result_inst_22, result_inst_23, result_inst_24;

	result_inst_16 = SetEvent(t1, Task1_Event9);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_16);
		
	EventMaskType result_inst_X;
	result_inst_4 = GetEvent(t1,&result_inst_X);
	TEST_ASSERT_EQUAL_INT(Task1_Event9, result_inst_X); 
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_4);	
	
	result_inst_16 = ClearEvent(Task1_Event1);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_16);
	
	result_inst_17 = ClearEvent(Task1_Event2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_17);
	
	result_inst_18 = ClearEvent(Task1_Event3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_18);
	
	result_inst_19 = ClearEvent(Task1_Event4);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_19);
	
	result_inst_20 = ClearEvent(Task1_Event5);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_20);
	
	result_inst_21 = ClearEvent(Task1_Event6);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_21);
	
	result_inst_22 = ClearEvent(Task1_Event7);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_22);
	
	result_inst_23 = ClearEvent(Task1_Event8);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_23);
	
	result_inst_22 = ClearEvent(Task1_Event9);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_22);
	
	result_inst_23 = ClearEvent(Task1_Event10);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_23);
	
	result_inst_16 = ClearEvent(Task1_Event11);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_16);
	
	result_inst_17 = ClearEvent(Task1_Event12);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_17);
	
	result_inst_18 = ClearEvent(Task1_Event13);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_18);
	
	result_inst_19 = ClearEvent(Task1_Event14);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_19);
	
	result_inst_20 = ClearEvent(Task1_Event15);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_20);
	
	result_inst_21 = ClearEvent(Task1_Event16);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_21);
	
	result_inst_22 = ClearEvent(Task1_Event17);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_22);
	
	result_inst_23 = ClearEvent(Task1_Event18);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_23);
	
	result_inst_22 = ClearEvent(Task1_Event19);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_22);
	
	result_inst_23 = ClearEvent(Task1_Event20);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_23);
	
	result_inst_16 = ClearEvent(Task1_Event21);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_16);
	
	result_inst_17 = ClearEvent(Task1_Event22);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_17);
	
	result_inst_18 = ClearEvent(Task1_Event23);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_18);
	
	result_inst_19 = ClearEvent(Task1_Event24);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_19);
	
	result_inst_20 = ClearEvent(Task1_Event25);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_20);
	
	result_inst_21 = ClearEvent(Task1_Event26);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_21);
	
	result_inst_22 = ClearEvent(Task1_Event27);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_22);
	
	result_inst_23 = ClearEvent(Task1_Event28);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_23);
	
	result_inst_22 = ClearEvent(Task1_Event29);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_22);
	
	result_inst_23 = ClearEvent(Task1_Event30);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_23);
	
	result_inst_16 = ClearEvent(Task1_Event31);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_16);
	
	result_inst_17 = ClearEvent(Task1_Event32);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_17);
}

/*create the test suite with all the test cases*/
TestRef GoilTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(GoilTest,"GoilTest_sequence1",NULL,NULL,fixtures);

	return (TestRef)&GoilTest;
}

/* End of file goil_s1/task1_instance.c */
