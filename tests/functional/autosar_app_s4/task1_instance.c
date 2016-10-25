/**
 * @file autosar_app_s4/task1_instance.c
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

DeclareAlarm(Alarm1);
DeclareAlarm(Alarm2);
DeclareCounter(Software_Counter1);
DeclareCounter(Software_Counter2);
DeclareEvent(Event2);
DeclareEvent(Event3);
DeclareResource(Resource1);
DeclareResource(Resource2);
DeclareScheduleTable(sched1);
DeclareScheduleTable(sched2);
DeclareScheduleTable(sched3);
DeclareTask(t2);
DeclareTask(t3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	AlarmBaseType AlarmBaseType_inst_1, AlarmBaseType_inst_2;
	EventMaskType EventMaskType_inst_1, EventMaskType_inst_2;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1, ScheduleTableStatusType_inst_2;
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10;
	StatusType result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17, result_inst_18, result_inst_19, result_inst_20;
	StatusType result_inst_21, result_inst_22, result_inst_23, result_inst_24, result_inst_25, result_inst_26, result_inst_27, result_inst_28, result_inst_29, result_inst_30;
	StatusType result_inst_31, result_inst_32, result_inst_33, result_inst_34, result_inst_35, result_inst_36, result_inst_37, result_inst_38, result_inst_39, result_inst_40;
	StatusType result_inst_41, result_inst_42, result_inst_43, result_inst_44, result_inst_45, result_inst_46, result_inst_47, result_inst_48, result_inst_49, result_inst_50;
	TickType TickType_inst_1, TickType_inst_2;
	TickType TickType_inst_3 = 0;
	TaskStateType TaskStateType_inst_1, TaskStateType_inst_2;
	
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = ActivateTask(t2); 
	SCHEDULING_CHECK_AND_EQUAL_INT(1, E_OS_ACCESS, result_inst_1);	
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = ActivateTask(t3); 
	SCHEDULING_CHECK_AND_EQUAL_INT(3, E_OK, result_inst_2);	
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_3 = GetTaskState(t2, &TaskStateType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(4, E_OS_ACCESS, result_inst_3);	
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_4 = GetTaskState(t3, &TaskStateType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(5, WAITING , TaskStateType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(5, E_OK, result_inst_4);	
	
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_5 = SetEvent(t2, Event2); 
	SCHEDULING_CHECK_AND_EQUAL_INT(6, E_OS_ACCESS, result_inst_5);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_6 = SetEvent(t3, Event3); 
	SCHEDULING_CHECK_AND_EQUAL_INT(8, E_OK, result_inst_6);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_7 = GetEvent(t2, &EventMaskType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(9, E_OS_ACCESS, result_inst_7);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_8 = GetEvent(t3, &EventMaskType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(10, Event3 , EventMaskType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(10, E_OK, result_inst_8);
	
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_9 = GetResource(Resource2);
	SCHEDULING_CHECK_AND_EQUAL_INT(11, E_OS_ACCESS, result_inst_9);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_10 = GetResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12, E_OK, result_inst_10);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_11 = ReleaseResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(13, E_OK, result_inst_11);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_12 = ReleaseResource(Resource2);
	SCHEDULING_CHECK_AND_EQUAL_INT(14, E_OS_ACCESS, result_inst_12);
	
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_13 = SetAbsAlarm(Alarm2, 1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(15, E_OS_ACCESS, result_inst_13);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_14 = SetAbsAlarm(Alarm1, 1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(16, E_OK, result_inst_14);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_15 = GetAlarmBase(Alarm2, &AlarmBaseType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(17, E_OS_ACCESS, result_inst_15);
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_16 = GetAlarmBase(Alarm1, &AlarmBaseType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(18, E_OK, result_inst_16);
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_17 = GetAlarm(Alarm2, &TickType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(19, E_OS_ACCESS, result_inst_17);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_18 = GetAlarm(Alarm1, &TickType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(20, E_OK, result_inst_18);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_19 = CancelAlarm(Alarm2);
	SCHEDULING_CHECK_AND_EQUAL_INT(21, E_OS_ACCESS, result_inst_19);
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_20 = CancelAlarm(Alarm1);
	SCHEDULING_CHECK_AND_EQUAL_INT(22, E_OK, result_inst_20);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_21 = SetRelAlarm(Alarm2, 1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(23, E_OS_ACCESS, result_inst_21);
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_22 = SetRelAlarm(Alarm1, 1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(24, E_OK, result_inst_22);
	
	SCHEDULING_CHECK_INIT(25);
	result_inst_23 = CancelAlarm(Alarm1);
	SCHEDULING_CHECK_AND_EQUAL_INT(25, E_OK, result_inst_23);
	
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_24 = StartScheduleTableAbs(sched2, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(26, E_OS_ACCESS, result_inst_24);
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_25 = StartScheduleTableAbs(sched1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(27, E_OK, result_inst_25);
	
	SCHEDULING_CHECK_INIT(28);
	result_inst_26 = StopScheduleTable(sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(28, E_OS_ACCESS, result_inst_26);
	
	SCHEDULING_CHECK_INIT(29);
	result_inst_27 = StopScheduleTable(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(29, E_OK, result_inst_27);
		
	SCHEDULING_CHECK_INIT(30);
	result_inst_28 = StartScheduleTableRel(sched2, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(30, E_OS_ACCESS, result_inst_28);
	
	SCHEDULING_CHECK_INIT(31);
	result_inst_29 = StartScheduleTableRel(sched1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(31, E_OK, result_inst_29);
	
	SCHEDULING_CHECK_INIT(32);
	result_inst_30 = NextScheduleTable(sched1, sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(32, E_OS_ACCESS, result_inst_30);
	
	SCHEDULING_CHECK_INIT(33);
	result_inst_31 = NextScheduleTable(sched2, sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(33, E_OS_ACCESS, result_inst_31);
	
	SCHEDULING_CHECK_INIT(34);
	result_inst_32 = NextScheduleTable(sched1, sched3);
	SCHEDULING_CHECK_AND_EQUAL_INT(34, E_OK, result_inst_32);
	
	SCHEDULING_CHECK_INIT(35);
	result_inst_33 = StopScheduleTable(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(35, E_OK, result_inst_33);
	
	SCHEDULING_CHECK_INIT(36);
	result_inst_34 = StartScheduleTableSynchron(sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(36, E_OS_ACCESS, result_inst_34);
	
	SCHEDULING_CHECK_INIT(37);
	result_inst_35 = StartScheduleTableSynchron(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(37, E_OK, result_inst_35);
	
	SCHEDULING_CHECK_INIT(38);
	result_inst_36 = SyncScheduleTable(sched2, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(38, E_OS_ACCESS, result_inst_36);
	
	SCHEDULING_CHECK_INIT(39);
	result_inst_37 = SyncScheduleTable(sched1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(39, E_OK, result_inst_37);
	
	SCHEDULING_CHECK_INIT(40);
	result_inst_38 = SetScheduleTableAsync(sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(40, E_OS_ACCESS, result_inst_38);
	
	SCHEDULING_CHECK_INIT(41);
	result_inst_39 = SetScheduleTableAsync(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(41, E_OK, result_inst_39);
	
	SCHEDULING_CHECK_INIT(42);
	result_inst_40 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(42, E_OS_ACCESS, result_inst_40);
	
	SCHEDULING_CHECK_INIT(43);
	result_inst_41 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(43 , SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(43, E_OK, result_inst_41);
	
	
	SCHEDULING_CHECK_INIT(44);
	result_inst_42 = IncrementCounter(Software_Counter2);
	SCHEDULING_CHECK_AND_EQUAL_INT(44, E_OS_ACCESS, result_inst_42);
	
	SCHEDULING_CHECK_INIT(45);
	result_inst_43 = IncrementCounter(Software_Counter1);
	SCHEDULING_CHECK_AND_EQUAL_INT(45, E_OK, result_inst_43);
	
	SCHEDULING_CHECK_INIT(46);
	result_inst_44 = GetCounterValue(Software_Counter2, &TickType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(46, E_OS_ACCESS, result_inst_44);
	
	SCHEDULING_CHECK_INIT(47);
	result_inst_45 = GetCounterValue(Software_Counter1, &TickType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(47 , 1 , TickType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(47, E_OK, result_inst_45);
	
	SCHEDULING_CHECK_INIT(48);
	result_inst_46 = GetElapsedCounterValue(Software_Counter2, &TickType_inst_1, &TickType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(48, E_OS_ACCESS, result_inst_46);
	
	SCHEDULING_CHECK_INIT(49);
	result_inst_47 = GetElapsedCounterValue(Software_Counter1, &TickType_inst_3, &TickType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(49 , 1 , TickType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(49, E_OK, result_inst_47);

	
	SCHEDULING_CHECK_INIT(50);
	result_inst_48 = SetEvent(t3, Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(51, E_OK, result_inst_48);	
	
	SCHEDULING_CHECK_INIT(52);
	result_inst_49 = ChainTask(t2); 
	SCHEDULING_CHECK_AND_EQUAL_INT(52, E_OS_ACCESS, result_inst_49);	
	
	SCHEDULING_CHECK_INIT(53);
	result_inst_50 = ChainTask(t3); 
	SCHEDULING_CHECK_AND_EQUAL_INT(53, E_OK, result_inst_50);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarAPPTest_seq4_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarAPPTest,"AutosarAPPTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarAPPTest;
}

/* End of file autosar_app_s4/task1_instance.c */
