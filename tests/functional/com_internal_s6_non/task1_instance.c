/**
 * @file com_internal_s6_non/task1_instance.c
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
#include "tpl_com_definitions.h"  /*for E_COM_X*/

DeclareMessage(sm);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11;
	StatusType car1;
	
	car1 = 3;
	SCHEDULING_CHECK_INIT(1);
	result_inst_2 = SendMessage(sm, &car1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_3 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_3);

	car1 = 12;
	SCHEDULING_CHECK_INIT(11);
	result_inst_4 = SendMessage(sm, &car1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_5 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK, result_inst_5);
	
	car1 = 7;
	SCHEDULING_CHECK_INIT(21);
	result_inst_6 = SendMessage(sm, &car1);
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OK, result_inst_6);
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_7 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(28,E_OK, result_inst_7);
	
	car1 = 7;
	SCHEDULING_CHECK_INIT(29);
	result_inst_8 = SendMessage(sm, &car1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(29,E_OK, result_inst_8);
	
	SCHEDULING_CHECK_INIT(30);
	result_inst_9 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(34,E_OK, result_inst_9);
	
	car1 = 2;
	SCHEDULING_CHECK_INIT(35);
	result_inst_10 = SendMessage(sm, &car1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(35,E_OK, result_inst_10);
	
	SCHEDULING_CHECK_INIT(36);
	result_inst_11 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(48,E_OK, result_inst_11);
	
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq6_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}

/* End of file com_internal_s6_non/task1_instance.c */
