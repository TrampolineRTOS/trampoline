/**
 * @file com_internal_s1_full/task2_instance.c
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
#include "tpl_com_definitions.h" /*for E_COM_ID*/

DeclareMessage(rm);
DeclareMessage(INVALID_MESSAGE);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_1 = GetMessageStatus(rm);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_COM_ID, result_inst_1);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_2 = ReceiveMessage(rm, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(14,E_OK, result_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,(int)('1'), (int)received_char);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_3 = ReceiveMessage(rm, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(15,E_OK, result_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,(int)('1'), (int)received_char);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_4 = ReceiveMessage(INVALID_MESSAGE, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_COM_ID, result_inst_4);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_5 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK, result_inst_5);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq1_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}

/* End of file com_internal_s1_full/task2_instance.c */
