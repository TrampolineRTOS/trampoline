/**
 * @file autosar_sp_s5/task1_instance.c
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

DeclareApplication(app1);
DeclareCounter(Software_Counter1);
DeclareScheduleTable(sched1);
DeclareScheduleTable(sched2);
DeclareTask(t1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	ApplicationType ApplicationType_inst_1, ApplicationType_inst_2;
	ISRType ISRType_inst_1;
	ObjectAccessType ObjectAccessType_inst_1;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1;
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12;
	TickType TickType_inst_1, TickType_inst_2;
	
	SCHEDULING_CHECK_STEP(1);
	DisableAllInterrupts();
	
	SCHEDULING_CHECK_INIT(2);
	ApplicationType_inst_1 = GetApplicationID();
	SCHEDULING_CHECK_AND_EQUAL_INT(3, app1, ApplicationType_inst_1);
	
	SCHEDULING_CHECK_INIT(4);
	ISRType_inst_1 = GetISRID();
	SCHEDULING_CHECK_AND_EQUAL_INT(5, INVALID_ISR, ISRType_inst_1);
	
	SCHEDULING_CHECK_INIT(6);
	ObjectAccessType_inst_1 = CheckObjectAccess(app1, OBJECT_TASK, t1);
	SCHEDULING_CHECK_AND_EQUAL_INT(7, ACCESS, ObjectAccessType_inst_1);

	SCHEDULING_CHECK_INIT(8);
	ApplicationType_inst_2 = CheckObjectOwnership(OBJECT_TASK, t1);
	SCHEDULING_CHECK_AND_EQUAL_INT(9, app1, ApplicationType_inst_2);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_1 = StartScheduleTableRel(sched1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11, E_OS_DISABLEDINT, result_inst_1);

	SCHEDULING_CHECK_INIT(12);
	result_inst_2 = StartScheduleTableAbs(sched1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(13, E_OS_DISABLEDINT, result_inst_2);
		
	SCHEDULING_CHECK_INIT(14);
	result_inst_3 = StopScheduleTable(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(15, E_OS_DISABLEDINT, result_inst_3);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_4 = NextScheduleTable(sched1, sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(17, E_OS_DISABLEDINT, result_inst_4);
		
	SCHEDULING_CHECK_INIT(18);
	result_inst_5 = StartScheduleTableSynchron(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(19, E_OS_DISABLEDINT, result_inst_5);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_6 = SyncScheduleTable(sched1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(21, E_OS_DISABLEDINT, result_inst_6);
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_7 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(23, E_OS_DISABLEDINT, result_inst_7);
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_8 = SetScheduleTableAsync(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(25, E_OS_DISABLEDINT, result_inst_8);
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_9 = IncrementCounter(Software_Counter1);
	SCHEDULING_CHECK_AND_EQUAL_INT(27, E_OS_DISABLEDINT, result_inst_9);
	
	SCHEDULING_CHECK_INIT(28);
	result_inst_10 = GetCounterValue(Software_Counter1, &TickType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(29, E_OS_DISABLEDINT, result_inst_10);
	
	SCHEDULING_CHECK_INIT(30);
	result_inst_11 = GetElapsedCounterValue(Software_Counter1, &TickType_inst_1, &TickType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(31, E_OS_DISABLEDINT, result_inst_11);
	
	SCHEDULING_CHECK_INIT(32);
	result_inst_12 = TerminateApplication(app1, NO_RESTART);
	SCHEDULING_CHECK_AND_EQUAL_INT(33, E_OS_DISABLEDINT, result_inst_12);

	SCHEDULING_CHECK_STEP(34);	
	EnableAllInterrupts();
	
	/*
	 Missing :
		- CallTrustedFunction
		- CheckISRMemoryAccess
		- CheckTaskMemoryAccess
		- GetActiveApplicationMode (OS tests)
	 Ok but not tested :
		- StartOS (OS tests)
		- ShutdownOS (OS tests)
	 */
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq5_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}

/* End of file autosar_sp_s5/task1_instance.c */
