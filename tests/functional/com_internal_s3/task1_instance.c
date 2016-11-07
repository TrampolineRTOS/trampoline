/**
 * @file com_internal_s3/task1_instance.c
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

DeclareMessage(sm_activatetask);
DeclareMessage(sm_setevent);
DeclareMessage(sm_comcallback);
DeclareTask(t3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = ActivateTask(t3);	
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = SendMessage(sm_activatetask, "1");	
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_3 = SendMessage(sm_setevent, "2");	
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_4 = SendMessage(sm_comcallback, "3");	
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_4);
	
	/* Message flag doesn't work
	 result_inst_2 = ActivateTask(t4);
	SCHEDULING_CHECK_AND_EQUAL_INT(X,E_OK, result_inst_2);
	
	result_inst_2 = SendMessage(sm_flag, "4");
	SCHEDULING_CHECK_AND_EQUAL_INT(X,E_OK, result_inst_2);
	
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(X,E_OK, result_inst_2);
	*/
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}

/* End of file com_internal_s3/task1_instance.c */
