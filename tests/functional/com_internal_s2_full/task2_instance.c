/**
 * @file com_internal_s2_full/task2_instance.c
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
#include "tpl_com_definitions.h" /*for E_COM_NOMSG...*/

DeclareMessage(rm);
DeclareMessage(INVALID_MESSAGE);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_1 = GetMessageStatus(rm);	
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_COM_LIMIT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_2 = ReceiveMessage(rm, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(20,E_COM_LIMIT, result_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(20,(int)('1'), (int)received_char);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_3 = GetMessageStatus(rm);	
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_4 = ReceiveMessage(rm, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(22,E_OK, result_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(22,(int)('2'), (int)received_char);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_5 = GetMessageStatus(rm);	
	SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_6 = ReceiveMessage(rm, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(24,E_OK, result_inst_6);
	SCHEDULING_CHECK_AND_EQUAL_INT(24,(int)('3'), (int)received_char);
	
	SCHEDULING_CHECK_INIT(25);
	result_inst_7 = GetMessageStatus(rm);	
	SCHEDULING_CHECK_AND_EQUAL_INT(25,E_COM_NOMSG, result_inst_7);
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_8 = ReceiveMessage(rm, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT(29,E_COM_NOMSG, result_inst_8);

	SCHEDULING_CHECK_INIT(30);
	result_inst_9 = GetMessageStatus(rm);	
	SCHEDULING_CHECK_AND_EQUAL_INT(30,E_COM_NOMSG, result_inst_9);
	
	SCHEDULING_CHECK_INIT(31);
	result_inst_10 = ReceiveMessage(INVALID_MESSAGE, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT(34,E_COM_ID, result_inst_10);
	
	SCHEDULING_CHECK_INIT(35);
	result_inst_11 = GetMessageStatus(INVALID_MESSAGE);	
	SCHEDULING_CHECK_AND_EQUAL_INT(37,E_COM_ID, result_inst_11);

	SCHEDULING_CHECK_INIT(38);
	result_inst_12 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(38,E_OK, result_inst_12);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq2_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}

/* End of file com_internal_s2_full/task2_instance.c */
