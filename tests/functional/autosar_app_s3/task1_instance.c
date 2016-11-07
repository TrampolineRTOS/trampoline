/**
 * @file autosar_app_s3/task1_instance.c
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
DeclareAlarm(INVALID_ALARM);
DeclareApplication(app1);
DeclareApplication(app2);
DeclareCounter(Software_Counter);
DeclareCounter(INVALID_COUNTER);
DeclareResource(Resource1);
DeclareResource(RES_SCHEDULER);
DeclareResource(INVALID_RESOURCE);
DeclareScheduleTable(sched1);
DeclareScheduleTable(sched2);
DeclareScheduleTable(INVALID_SCHEDULETABLE);
DeclareTask(t1);
DeclareTask(t2);
DeclareTask(INVALID_TASK);
DeclareISR(softwareInterruptHandler0);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	ObjectAccessType result_obj_1, result_obj_2, result_obj_3, result_obj_4, result_obj_5, result_obj_6, result_obj_7, result_obj_8, result_obj_9, result_obj_10, result_obj_11, result_obj_12;
	ObjectAccessType result_obj_13, result_obj_14, result_obj_15, result_obj_16, result_obj_17, result_obj_18, result_obj_19, result_obj_20, result_obj_21, result_obj_22;/*, result_obj_23;*/
	ApplicationType result_app_1, result_app_2, result_app_3, result_app_4, result_app_5, result_app_6, result_app_7, result_app_8, result_app_9, result_app_10, result_app_11, result_app_12, result_app_13, result_app_14;
	
	SCHEDULING_CHECK_INIT(1);
	result_obj_1 = CheckObjectAccess(INVALID_OSAPPLICATION_ID, OBJECT_TASK, t1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(1, NO_ACCESS, result_obj_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_obj_2 = CheckObjectAccess(app1, OBJECT_TYPE_COUNT, t1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(2, NO_ACCESS, result_obj_2);
	
	
	SCHEDULING_CHECK_INIT(3);
	result_obj_3 = CheckObjectAccess(app1, OBJECT_TASK, INVALID_TASK); 
	SCHEDULING_CHECK_AND_EQUAL_INT(3, NO_ACCESS, result_obj_3);
	
	SCHEDULING_CHECK_INIT(4);
	result_obj_4 = CheckObjectAccess(app1, OBJECT_TASK, t1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(4, ACCESS, result_obj_4);
	
	SCHEDULING_CHECK_INIT(5);
	result_obj_5 = CheckObjectAccess(app1, OBJECT_TASK, t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(5, NO_ACCESS, result_obj_5);
	
		
	SCHEDULING_CHECK_INIT(6);
	result_obj_6 = CheckObjectAccess(app2, OBJECT_ISR, INVALID_ISR); 
	SCHEDULING_CHECK_AND_EQUAL_INT(6, NO_ACCESS, result_obj_6);
	
	SCHEDULING_CHECK_INIT(7);
	result_obj_7 = CheckObjectAccess(app2, OBJECT_ISR, softwareInterruptHandler0); 
	SCHEDULING_CHECK_AND_EQUAL_INT(7, ACCESS, result_obj_7);
	
	SCHEDULING_CHECK_INIT(8);
	result_obj_8 = CheckObjectAccess(app1, OBJECT_ISR, softwareInterruptHandler0); 
	SCHEDULING_CHECK_AND_EQUAL_INT(8, NO_ACCESS, result_obj_8);
	
	
	SCHEDULING_CHECK_INIT(9);
	result_obj_9 = CheckObjectAccess(app2, OBJECT_ALARM, INVALID_ALARM); 
	SCHEDULING_CHECK_AND_EQUAL_INT(9, NO_ACCESS, result_obj_9);
	
	SCHEDULING_CHECK_INIT(10);
	result_obj_10 = CheckObjectAccess(app1, OBJECT_ALARM, Alarm1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(10, ACCESS, result_obj_10);
	
	SCHEDULING_CHECK_INIT(11);
	result_obj_11 = CheckObjectAccess(app2, OBJECT_ALARM, Alarm1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(11, NO_ACCESS, result_obj_11);
	
	
	SCHEDULING_CHECK_INIT(12);
	result_obj_12 = CheckObjectAccess(app1, OBJECT_RESOURCE, INVALID_RESOURCE); 
	SCHEDULING_CHECK_AND_EQUAL_INT(12, NO_ACCESS, result_obj_12);
	
	SCHEDULING_CHECK_INIT(13);
	result_obj_13 = CheckObjectAccess(app1, OBJECT_RESOURCE, Resource1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(13, ACCESS, result_obj_13);
	
	SCHEDULING_CHECK_INIT(14);
	result_obj_14 = CheckObjectAccess(app2, OBJECT_RESOURCE, Resource1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(14, NO_ACCESS, result_obj_14);
	
	SCHEDULING_CHECK_INIT(15);
	result_obj_15 = CheckObjectAccess(app1, OBJECT_RESOURCE, RES_SCHEDULER); 
	SCHEDULING_CHECK_AND_EQUAL_INT(15, ACCESS, result_obj_15);
	
	SCHEDULING_CHECK_INIT(16);
	result_obj_16 = CheckObjectAccess(app2, OBJECT_RESOURCE, RES_SCHEDULER); 
	SCHEDULING_CHECK_AND_EQUAL_INT(16, ACCESS, result_obj_16);
	
	
	SCHEDULING_CHECK_INIT(17);
	result_obj_17 = CheckObjectAccess(app1, OBJECT_SCHEDULETABLE, INVALID_SCHEDULETABLE); 
	SCHEDULING_CHECK_AND_EQUAL_INT(17, NO_ACCESS, result_obj_17);
	
	SCHEDULING_CHECK_INIT(18);
	result_obj_18 = CheckObjectAccess(app1, OBJECT_SCHEDULETABLE, sched1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(18, ACCESS, result_obj_18);
	
	SCHEDULING_CHECK_INIT(19);
	result_obj_19 = CheckObjectAccess(app1, OBJECT_SCHEDULETABLE, sched2); 
	SCHEDULING_CHECK_AND_EQUAL_INT(19, NO_ACCESS, result_obj_19);
	
	
	SCHEDULING_CHECK_INIT(20);
	result_obj_20 = CheckObjectAccess(app1, OBJECT_COUNTER, INVALID_COUNTER); 
	SCHEDULING_CHECK_AND_EQUAL_INT(20, NO_ACCESS, result_obj_20);
	
	SCHEDULING_CHECK_INIT(21);
	result_obj_21 = CheckObjectAccess(app1, OBJECT_COUNTER, Software_Counter); 
	SCHEDULING_CHECK_AND_EQUAL_INT(21, ACCESS, result_obj_21);
	
	SCHEDULING_CHECK_INIT(22);
	result_obj_22 = CheckObjectAccess(app2, OBJECT_COUNTER, Software_Counter); 
	SCHEDULING_CHECK_AND_EQUAL_INT(22, NO_ACCESS, result_obj_22);
	
	SCHEDULING_CHECK_INIT(23);
	result_app_1 = CheckObjectOwnership(OBJECT_TYPE_COUNT, t1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(23, INVALID_OSAPPLICATION_ID, result_app_1);
	
	SCHEDULING_CHECK_INIT(24);
	result_app_2 = CheckObjectOwnership(OBJECT_TASK, INVALID_TASK); 
	SCHEDULING_CHECK_AND_EQUAL_INT(24, INVALID_OSAPPLICATION_ID, result_app_2);
	
	SCHEDULING_CHECK_INIT(25);
	result_app_3 = CheckObjectOwnership(OBJECT_TASK, t1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(25, app1, result_app_3);
	
	
	SCHEDULING_CHECK_INIT(26);
	result_app_4 = CheckObjectOwnership(OBJECT_ISR, INVALID_ISR); 
	SCHEDULING_CHECK_AND_EQUAL_INT(26, INVALID_OSAPPLICATION_ID, result_app_4);
	
	SCHEDULING_CHECK_INIT(27);
	result_app_5 = CheckObjectOwnership(OBJECT_ISR, softwareInterruptHandler0); 
	SCHEDULING_CHECK_AND_EQUAL_INT(27, app2, result_app_5);
	
	
	SCHEDULING_CHECK_INIT(28);
	result_app_6 = CheckObjectOwnership(OBJECT_ALARM, INVALID_ALARM); 
	SCHEDULING_CHECK_AND_EQUAL_INT(28, INVALID_OSAPPLICATION_ID, result_app_6);
	
	SCHEDULING_CHECK_INIT(29);
	result_app_7 = CheckObjectOwnership(OBJECT_ALARM, Alarm1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(29, app1, result_app_7);
	
	
	SCHEDULING_CHECK_INIT(30);
	result_app_8 = CheckObjectOwnership(OBJECT_RESOURCE, INVALID_RESOURCE); 
	SCHEDULING_CHECK_AND_EQUAL_INT(30, INVALID_OSAPPLICATION_ID, result_app_8);
	
	SCHEDULING_CHECK_INIT(31);
	result_app_9 = CheckObjectOwnership(OBJECT_RESOURCE, Resource1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(31, app1, result_app_9);
	
	SCHEDULING_CHECK_INIT(32);
	result_app_10 = CheckObjectOwnership(OBJECT_RESOURCE, RES_SCHEDULER); 
	SCHEDULING_CHECK_AND_EQUAL_INT(32, INVALID_OSAPPLICATION_ID, result_app_10);
	
	
	SCHEDULING_CHECK_INIT(33);
	result_app_11 = CheckObjectOwnership(OBJECT_SCHEDULETABLE, INVALID_SCHEDULETABLE); 
	SCHEDULING_CHECK_AND_EQUAL_INT(33, INVALID_OSAPPLICATION_ID, result_app_11);
	
	SCHEDULING_CHECK_INIT(34);
	result_app_12 = CheckObjectOwnership(OBJECT_SCHEDULETABLE, sched1); 
	SCHEDULING_CHECK_AND_EQUAL_INT(34, app1, result_app_12);
	
	
	SCHEDULING_CHECK_INIT(35);
	result_app_13 = CheckObjectOwnership(OBJECT_COUNTER, INVALID_COUNTER); 
	SCHEDULING_CHECK_AND_EQUAL_INT(35, INVALID_OSAPPLICATION_ID, result_app_13);
	
	SCHEDULING_CHECK_INIT(36);
	result_app_14 = CheckObjectOwnership(OBJECT_COUNTER, Software_Counter); 
	SCHEDULING_CHECK_AND_EQUAL_INT(36, app1, result_app_14);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarAPPTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarAPPTest,"AutosarAPPTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarAPPTest;
}

/* End of file autosar_app_s3/task1_instance.c */
