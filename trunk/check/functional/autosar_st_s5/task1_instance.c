/**
 * @file autosar_st_s5/task1_instance.c
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
#include "Os.h"

DeclareCounter(Software_Counter);
DeclareScheduleTable(sched1);
DeclareScheduleTable(sched2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1, ScheduleTableStatusType_inst_2, ScheduleTableStatusType_inst_3, ScheduleTableStatusType_inst_4, ScheduleTableStatusType_inst_5;

	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = StartScheduleTableRel(sched1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = NextScheduleTable(sched1, sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_3 = IncrementCounter(Software_Counter);
	/*start schedule table (because StartScheduleTabelRel(x, 1)) - offset = 0+offset_sched*/
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_4 = IncrementCounter(Software_Counter);
	/*offset = 1+offset_sched -> t2 */
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_4);
		
	SCHEDULING_CHECK_INIT(6);
	result_inst_5 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(6, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_5);

	SCHEDULING_CHECK_INIT(7);
	result_inst_6 = StopScheduleTable(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_6);

	SCHEDULING_CHECK_INIT(8);
	result_inst_7 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(8, SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_7);
	
	/*Restart*/
	SCHEDULING_CHECK_INIT(9);
	result_inst_8 = StartScheduleTableRel(sched1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_8);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_9 = NextScheduleTable(sched1, sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_10 = IncrementCounter(Software_Counter);
	/*start schedule table (because StartScheduleTabelRel(x, 1)) - offset = 0+offset_sched*/
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_10);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_11 = IncrementCounter(Software_Counter);
	/*offset = 1+offset_sched -> t2 : error*/
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OK, result_inst_11);
		
	SCHEDULING_CHECK_INIT(14);
	result_inst_12 = IncrementCounter(Software_Counter);
	/*offset = 2+offset_sched =0+offset_sched -> check lauch action if action of sched_2 exists at offset=0*/
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_12);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_13 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(15, SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OK, result_inst_13);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_14 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(16, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OK, result_inst_14);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_15 = IncrementCounter(Software_Counter);
	/*offset = 1+offset_sched -> setevent to t2*/
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OK, result_inst_15);
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_16 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(19, SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OK, result_inst_16);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq5_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}

/* End of file autosar_st_s5/task1_instance.c */
