/**
 * @file autosar_st_s7/task1_instance.c
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

#include "Os.h"

DeclareCounter(Software_Counter);
DeclareScheduleTable(sched1);
DeclareScheduleTable(sched2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1, ScheduleTableStatusType_inst_2, ScheduleTableStatusType_inst_3, ScheduleTableStatusType_inst_4, ScheduleTableStatusType_inst_5, ScheduleTableStatusType_inst_6;
		
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(1, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(2, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_3 = IncrementCounter(Software_Counter);
	/*offset = 1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_3);
		
	SCHEDULING_CHECK_INIT(4);
	result_inst_4 = IncrementCounter(Software_Counter);
	/*offset = 2 -> sched1 starts */
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_5 = IncrementCounter(Software_Counter);
	/*offset = 3 -> t2 starts*/
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_6 = IncrementCounter(Software_Counter);
	/*offset = 4  */
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_6);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_7 = IncrementCounter(Software_Counter);
	/*offset = 5 -> sched1 restarts */
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_7);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_8 = IncrementCounter(Software_Counter);
	/*offset = 6 -> t2 can't restarts -> errorhook */
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_8);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_9 = IncrementCounter(Software_Counter);
	/*offset = 7 -> t2 receive event1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_10 = IncrementCounter(Software_Counter);
	/*offset = 8  -> t2 can't receive event1 because suspended -> errorhook*/
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_10);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_11 = IncrementCounter(Software_Counter);
	/*offset = 9 -> t2 activated and received event1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK, result_inst_11);

	SCHEDULING_CHECK_INIT(18);
	result_inst_12 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(18, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OK, result_inst_12);
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_13 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(19, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OK, result_inst_13);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_14 = StopScheduleTable(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK, result_inst_14);
		
	SCHEDULING_CHECK_INIT(21);
	result_inst_15 = StopScheduleTable(sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OK, result_inst_15);
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_16 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(22, SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT(22,E_OK, result_inst_16);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_17 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_6);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(23, SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_6);
	SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OK, result_inst_17);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq7_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence7",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}

/* End of file autosar_st_s7/task1_instance.c */
