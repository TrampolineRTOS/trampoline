/**
 * @file autosar_app_s1/task1_instance2.c
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

/*Instance 2 of task t1*/

#include "Os.h"

DeclareAlarm(Alarm1);
DeclareApplication(app1);
DeclareResource(Resource1);
DeclareScheduleTable(sched1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance2(void)
{
	ApplicationType result_app_1;
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1;
	TickType TickType_inst_1;
	
	SCHEDULING_CHECK_INIT(10);
	result_app_1 = GetApplicationID(); 
	SCHEDULING_CHECK_AND_EQUAL_INT(10, app1, result_app_1);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_1 = GetAlarm(Alarm1, &TickType_inst_1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(11, E_OS_NOFUNC, result_inst_1);
		
	SCHEDULING_CHECK_INIT(12);
	result_inst_2 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(12 , SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12, E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_3 = ReleaseResource(Resource1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(13, E_OS_NOFUNC, result_inst_3);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_4 = TerminateApplication(app1, NO_RESTART); 
	SCHEDULING_CHECK_AND_EQUAL_INT(140, E_OK, result_inst_4);
			
}

/*create the test suite with all the test cases*/
TestRef AutosarAPPTest_seq1_t1_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance2",test_t1_instance2)
	};
	EMB_UNIT_TESTCALLER(AutosarAPPTest,"AutosarAPPTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarAPPTest;
}

/* End of file autosar_app_s1/task1_instance2.c */
