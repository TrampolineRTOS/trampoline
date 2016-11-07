/**
 * @file autosar_tp_s1/task1_instance3.c
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


/*Instance 3 of task t1*/

#include "Os.h"

DeclareScheduleTable(sched1);
DeclareTask(t3);
DeclareTask(t4);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance3(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
	
  SCHEDULING_CHECK_INIT(5);
	result_inst_1 = StopScheduleTable(sched1);
  SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_1);
	
  SCHEDULING_CHECK_INIT(6);
	result_inst_2 = ActivateTask(t3);
  SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_2);
	
  SCHEDULING_CHECK_INIT(9);
	result_inst_3 = ActivateTask(t4);
  SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_3);
	
  while(1); /* --> Protection Hook */
  
}

/*create the test suite with all the test cases*/
TestRef AutosarTPTest_seq1_t1_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance3",test_t1_instance3)
	};
	EMB_UNIT_TESTCALLER(AutosarTPTest,"AutosarTPTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTPTest;
}


/* End of file autosar_tp_s1/task1_instance3.c */
