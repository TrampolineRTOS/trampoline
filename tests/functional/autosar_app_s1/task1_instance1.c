/**
 * @file autosar_app_s1/task1_instance1.c
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

/*Instance 1 of task t1*/

#include "Os.h"

DeclareAlarm(Alarm1);
DeclareApplication(app1);
DeclareResource(Resource1);
DeclareScheduleTable(sched1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance1(void)
{
	ApplicationType result_app_1;
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1;
	TickType TickType_inst_1;
	
	SCHEDULING_CHECK_INIT(1);
	result_app_1 = GetApplicationID(); 
	SCHEDULING_CHECK_AND_EQUAL_INT(1, app1, result_app_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = SetRelAlarm(Alarm1, 1, 0); 
	SCHEDULING_CHECK_AND_EQUAL_INT(2, E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = GetAlarm(Alarm1, &TickType_inst_1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(3, E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_3 = StartScheduleTableAbs(sched1, 0); 
	SCHEDULING_CHECK_AND_EQUAL_INT(4, E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_4 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(5 , SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(5, E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_5 = GetResource(Resource1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(6, E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_6 = TerminateApplication(app1, INVALID_RESTART);
	SCHEDULING_CHECK_AND_EQUAL_INT(8, E_OS_VALUE, result_inst_6);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_7 = TerminateApplication(app1, RESTART); 
	SCHEDULING_CHECK_AND_EQUAL_INT(90, E_OK, result_inst_7);
	
			
}

/*create the test suite with all the test cases*/
TestRef AutosarAPPTest_seq1_t1_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance1",test_t1_instance1)
	};
	EMB_UNIT_TESTCALLER(AutosarAPPTest,"AutosarAPPTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarAPPTest;
}

/* End of file autosar_app_s1/task1_instance1.c */
