/**
 * @file autosar_sts_s10/task1_instance.c
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

DeclareScheduleTable(sched_explicit);
DeclareCounter(Software_Counter1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10;
	StatusType result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17, result_inst_18, result_inst_19, result_inst_20;
	StatusType result_inst_21, result_inst_22, result_inst_23, result_inst_24, result_inst_25, result_inst_26, result_inst_27, result_inst_28, result_inst_29, result_inst_30;
	StatusType result_inst_31, result_inst_32, result_inst_33, result_inst_34, result_inst_35, result_inst_36, result_inst_37, result_inst_38, result_inst_39;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1, ScheduleTableStatusType_inst_2, ScheduleTableStatusType_inst_3, ScheduleTableStatusType_inst_4, ScheduleTableStatusType_inst_5;
	ScheduleTableStatusType ScheduleTableStatusType_inst_6, ScheduleTableStatusType_inst_7, ScheduleTableStatusType_inst_8, ScheduleTableStatusType_inst_9, ScheduleTableStatusType_inst_10, ScheduleTableStatusType_inst_11;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = StartScheduleTableSynchron(sched_explicit);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
		
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(2, SCHEDULETABLE_WAITING , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_2);
		
	SCHEDULING_CHECK_INIT(3);
	result_inst_3 = SyncScheduleTable(sched_explicit, 8);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_4 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(4, SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS , ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_5 = IncrementCounter(Software_Counter1);
	/*offset = 1 (sc) - 9 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_6 = IncrementCounter(Software_Counter1);
	/*offset = 2 (sc) - 0 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_6);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_7 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(7, SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS , ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_7);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_8 = SetScheduleTableAsync(sched_explicit);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_8);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_9 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(9, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_10 = IncrementCounter(Software_Counter1);
	/*offset = 3 (sc) - 1 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_10);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_11 = IncrementCounter(Software_Counter1);
	/*offset = 4 (sc) - 2 (st) -> t2 activated */
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_11);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_12 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(13, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OK, result_inst_12);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_13 = IncrementCounter(Software_Counter1);
	/*offset = 5 (sc) - 3 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_13);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_14 = IncrementCounter(Software_Counter1);
	/*offset = 6 (sc) - 4 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OK, result_inst_14);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_15 = IncrementCounter(Software_Counter1);
	/*offset = 7 (sc) - 5 (st) -> t2 received Event1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OK, result_inst_15);
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_16 = IncrementCounter(Software_Counter1);
	/*offset = 8 (sc) - 6 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OK, result_inst_16);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_17 = IncrementCounter(Software_Counter1);
	/*offset = 9 (sc) - 7 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK, result_inst_17);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_18 = IncrementCounter(Software_Counter1);
	/*offset = 10 (sc) - 8 (st) -> t2 received Event1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(22,E_OK, result_inst_18);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_19 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_6);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(23, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_6);
	SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OK, result_inst_19);
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_20 = SyncScheduleTable(sched_explicit, 8);
	SCHEDULING_CHECK_AND_EQUAL_INT(24,E_OK, result_inst_20);
		
	SCHEDULING_CHECK_INIT(25);
	result_inst_21 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_7);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(25, SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS , ScheduleTableStatusType_inst_7);
	SCHEDULING_CHECK_AND_EQUAL_INT(25,E_OK, result_inst_21);
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_22 = IncrementCounter(Software_Counter1);
	/*offset = 11 (sc) - 9 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(26,E_OK, result_inst_22);
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_23 = IncrementCounter(Software_Counter1);
	/*offset = 12 (sc) - 0 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(27,E_OK, result_inst_23);
	
	SCHEDULING_CHECK_INIT(28);
	result_inst_24 = IncrementCounter(Software_Counter1);
	/*offset = 13 (sc) - 1 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(28,E_OK, result_inst_24);
	
	SCHEDULING_CHECK_INIT(29);
	result_inst_25 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_8);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(29, SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS , ScheduleTableStatusType_inst_8);
	SCHEDULING_CHECK_AND_EQUAL_INT(29,E_OK, result_inst_25);
	
	SCHEDULING_CHECK_INIT(30);
	result_inst_26 = SyncScheduleTable(sched_explicit, 4);
	SCHEDULING_CHECK_AND_EQUAL_INT(30,E_OK, result_inst_26);
	
	SCHEDULING_CHECK_INIT(31);
	result_inst_27 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_9);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(31, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_9);
	SCHEDULING_CHECK_AND_EQUAL_INT(31,E_OK, result_inst_27);
	
	SCHEDULING_CHECK_INIT(32);
	result_inst_28 = IncrementCounter(Software_Counter1);
	/*offset = 14 (sc) - 5 (st) -> t2 activated */
	SCHEDULING_CHECK_AND_EQUAL_INT(33,E_OK, result_inst_28);
	
	SCHEDULING_CHECK_INIT(34);
	result_inst_29 = SetScheduleTableAsync(sched_explicit);
	SCHEDULING_CHECK_AND_EQUAL_INT(34,E_OK, result_inst_29);
	
	SCHEDULING_CHECK_INIT(35);
	result_inst_30 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_10);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(35, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_10);
	SCHEDULING_CHECK_AND_EQUAL_INT(35,E_OK, result_inst_30);
	
	SCHEDULING_CHECK_INIT(36);
	result_inst_31 = IncrementCounter(Software_Counter1);
	/*offset = 15 (sc) - 6->5 (st) -> t2 receive Event1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(38,E_OK, result_inst_31);
	
	SCHEDULING_CHECK_INIT(39);
	result_inst_32 = IncrementCounter(Software_Counter1);
	/*offset = 16 (sc) - 6 (st)  */
	SCHEDULING_CHECK_AND_EQUAL_INT(39,E_OK, result_inst_32);
	
	SCHEDULING_CHECK_INIT(40);
	result_inst_33 = IncrementCounter(Software_Counter1);
	/*offset = 17 (sc) - 7 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(40,E_OK, result_inst_33);
	
	SCHEDULING_CHECK_INIT(41);
	result_inst_34 = IncrementCounter(Software_Counter1);
	/*offset = 18 (sc) - 8 (st) -> t2 received Event1 */
	SCHEDULING_CHECK_AND_EQUAL_INT(42,E_OK, result_inst_34);
	
	SCHEDULING_CHECK_INIT(43);
	result_inst_35 = IncrementCounter(Software_Counter1);
	/*offset = 19 (sc) - 9 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(43,E_OK, result_inst_35);
	
	SCHEDULING_CHECK_INIT(44);
	result_inst_36 = IncrementCounter(Software_Counter1);
	/*offset = 20 (sc) - 0 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(44,E_OK, result_inst_36);
	
	SCHEDULING_CHECK_INIT(45);
	result_inst_37 = IncrementCounter(Software_Counter1);
	/*offset = 21 (sc) - 1 (st) */
	SCHEDULING_CHECK_AND_EQUAL_INT(45,E_OK, result_inst_37);
	
	SCHEDULING_CHECK_INIT(46);
	result_inst_38 = IncrementCounter(Software_Counter1);
	/*offset = 22 (sc) - 2 (st) -> t2 activated */
	SCHEDULING_CHECK_AND_EQUAL_INT(47,E_OK, result_inst_38);
	
	SCHEDULING_CHECK_INIT(48);
	result_inst_39 = GetScheduleTableStatus(sched_explicit, &ScheduleTableStatusType_inst_11);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(48, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_11);
	SCHEDULING_CHECK_AND_EQUAL_INT(48,E_OK, result_inst_39);
	
	
}

/*create the test suite with all the test cases*/
TestRef AutosarSTSTest_seq10_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTSTest,"AutosarSTTest_sequence10",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTSTest;
}

/* End of file autosar_sts_s10/task1_instance.c */
