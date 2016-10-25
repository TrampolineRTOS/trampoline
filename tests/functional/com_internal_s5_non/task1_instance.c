/**
 * @file com_internal_s5_non/task1_instance.c
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
#include "tpl_com_definitions.h"  /*for E_COM_ID*/

DeclareMessage(sm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17, result_inst_18;
	StatusType car1;
	
	car1 = 1;
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = SendMessage(sm, &car1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_2);
	
	car1 = 2;
	SCHEDULING_CHECK_INIT(9);
	result_inst_3 = SendMessage(sm, &car1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_3);

	SCHEDULING_CHECK_INIT(10);
	result_inst_4 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_4);

	car1 = 3;
	SCHEDULING_CHECK_INIT(15);
	result_inst_5 = SendMessage(sm, &car1);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_6 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(22,E_OK, result_inst_6);

	car1 = 2;
	SCHEDULING_CHECK_INIT(23);
	result_inst_7 = SendMessage(sm, &car1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OK, result_inst_7);
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_8 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(26,E_OK, result_inst_8);

	car1 = 1;
	SCHEDULING_CHECK_INIT(27);
	result_inst_9 = SendMessage(sm, &car1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(27,E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(28);
	result_inst_10 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(34,E_OK, result_inst_10);

	car1 = 0;
	SCHEDULING_CHECK_INIT(35);
	result_inst_11 = SendMessage(sm, &car1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(35,E_OK, result_inst_11);
	
	SCHEDULING_CHECK_INIT(36);
	result_inst_12 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(42,E_OK, result_inst_12);

	car1 = 1;
	SCHEDULING_CHECK_INIT(43);
	result_inst_13 = SendMessage(sm, &car1);
	SCHEDULING_CHECK_AND_EQUAL_INT(43,E_OK, result_inst_13);
	
	SCHEDULING_CHECK_INIT(44);
	result_inst_14 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(48,E_OK, result_inst_14);

	car1 = 2;
	SCHEDULING_CHECK_INIT(49);
	result_inst_15 = SendMessage(sm, &car1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(49,E_OK, result_inst_15);
	
	SCHEDULING_CHECK_INIT(50);
	result_inst_16 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(52,E_OK, result_inst_16);

	car1 = 5;
	SCHEDULING_CHECK_INIT(53);
	result_inst_17 = SendMessage(sm, &car1);
	SCHEDULING_CHECK_AND_EQUAL_INT(53,E_OK, result_inst_17);

	SCHEDULING_CHECK_INIT(54);
	result_inst_18 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(62,E_OK, result_inst_18);

}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq5_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}

/* End of file com_internal_s5_non/task1_instance.c */
