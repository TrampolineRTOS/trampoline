/**
 * @file autosar_st_s1/task1_instance.c
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

DeclareScheduleTable(INVALID_SCHEDULETABLE);
DeclareScheduleTable(sched1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17, result_inst_18;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1, ScheduleTableStatusType_inst_2, ScheduleTableStatusType_inst_3, ScheduleTableStatusType_inst_4, ScheduleTableStatusType_inst_5;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(1,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = StartScheduleTableRel(INVALID_SCHEDULETABLE, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OS_ID, result_inst_2);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_3 = StartScheduleTableRel(sched1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OS_VALUE, result_inst_3);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_4 = StartScheduleTableRel(sched1, 99); /* > (OSMAXALLOWEDVALUE - InitOffset) */
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OS_VALUE, result_inst_4);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_5 = StartScheduleTableRel(sched1, 98);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_6 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(9,SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_6);
		
	SCHEDULING_CHECK_INIT(10);
	result_inst_7 = StartScheduleTableRel(sched1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OS_STATE, result_inst_7);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_8 = StopScheduleTable(INVALID_SCHEDULETABLE);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OS_ID, result_inst_8);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_9 = StopScheduleTable(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_10 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(15,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OK, result_inst_10);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_11 = StopScheduleTable(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OS_NOFUNC, result_inst_11);
	
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_12 = StartScheduleTableAbs(INVALID_SCHEDULETABLE, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OS_ID, result_inst_12);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_13 = StartScheduleTableAbs(sched1, 101); /* > (OSMAXALLOWEDVALUE) */
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OS_VALUE, result_inst_13);
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_14 = StartScheduleTableAbs(sched1, 100);
	SCHEDULING_CHECK_AND_EQUAL_INT(22,E_OK, result_inst_14);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_15 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(23,SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OK, result_inst_15);
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_16 = StartScheduleTableAbs(sched1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(25,E_OS_STATE, result_inst_16);
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_17 = StopScheduleTable(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(26,E_OK, result_inst_17);
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_18 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(27,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT(27,E_OK, result_inst_18);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}

/* End of file autosar_st_s1/task1_instance.c */
