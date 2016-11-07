/**
 * @file alarms_s9_non/isr1_instance.c
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

/*Instance of task t3*/

#include "tpl_os.h"

DeclareAlarm(Alarm0);
DeclareAlarm(Alarm1_1);
DeclareAlarm(Alarm1_2);
DeclareAlarm(Alarm2_1);
DeclareAlarm(Alarm2_2);
DeclareAlarm(Alarm3);
DeclareAlarm(INVALID_ALARM);
DeclareTask(t3);
DeclareTask(t4);

void WaitActivationOneShotAlarm(AlarmType Alarm);
void WaitActivationPeriodicAlarm(AlarmType Alarm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_isr1_instance(void)
{
	StatusType result_inst_1, result_inst_1_5, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15;
	StatusType result_inst_16, result_inst_17, result_inst_18, result_inst_19, result_inst_20, result_inst_21, result_inst_22, result_inst_23, result_inst_24, result_inst_25, result_inst_26, result_inst_27, result_inst_28, result_inst_29, result_inst_30, result_inst_31, result_inst_32, result_inst_33, result_inst_34, result_inst_35;
	AlarmBaseType alarmbase;
	TickType tik;
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = ActivateTask(t4);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_1_5 = ActivateTask(t3);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_1_5);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_2 = GetAlarmBase(INVALID_ALARM, &alarmbase);
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OS_ID, result_inst_2);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_3 = GetAlarmBase(Alarm0, &alarmbase);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_4 = GetAlarm(INVALID_ALARM, &tik);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_ID, result_inst_4);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_5 = GetAlarm(Alarm0, &tik);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OS_NOFUNC, result_inst_5);
	
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_6 = SetRelAlarm(INVALID_ALARM, 0, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OS_ID, result_inst_6);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_7 = SetRelAlarm(Alarm0, -1 , 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OS_VALUE, result_inst_7);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_8 = SetRelAlarm(Alarm0, alarmbase.maxallowedvalue + 1 , 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OS_VALUE, result_inst_8);	
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_9 = SetRelAlarm(Alarm0, 0 , alarmbase.mincycle - 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OS_VALUE, result_inst_9);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_10 = SetRelAlarm(Alarm0, 0 , alarmbase.maxallowedvalue + 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OS_VALUE, result_inst_10);	
	
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_11 = SetAbsAlarm(INVALID_ALARM, 0, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OS_ID, result_inst_11);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_12 = SetAbsAlarm(Alarm0, -1 , 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OS_VALUE, result_inst_12);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_13 = SetAbsAlarm(Alarm0, alarmbase.maxallowedvalue + 1 , 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OS_VALUE, result_inst_13);	
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_14 = SetAbsAlarm(Alarm0, 0 , alarmbase.mincycle - 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OS_VALUE, result_inst_14);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_15 = SetAbsAlarm(Alarm0, 0 , alarmbase.maxallowedvalue + 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OS_VALUE, result_inst_15);	
	
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_16 = CancelAlarm(INVALID_ALARM);
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OS_ID, result_inst_16);	
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_17 = CancelAlarm(Alarm0);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OS_NOFUNC, result_inst_17);	
	
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_18 = SetRelAlarm(Alarm1_1, 2 , 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK, result_inst_18);	
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_19 = SetRelAlarm(Alarm1_1, 2 , 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OS_STATE, result_inst_19);	
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_20 = GetAlarm(Alarm1_1, &tik);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(22,E_OK, result_inst_20);
	SCHEDULING_CHECK_AND_EQUAL_INT(22,2, tik);
	
	WaitActivationPeriodicAlarm(Alarm1_1);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_21 = CancelAlarm(Alarm1_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OK, result_inst_21);	
	
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_22 = SetAbsAlarm(Alarm1_2, 2 , 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(24,E_OK, result_inst_22);	
	
	SCHEDULING_CHECK_INIT(25);
	result_inst_23 = SetAbsAlarm(Alarm1_2, 2 , 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(25,E_OS_STATE, result_inst_23);	
	
	WaitActivationOneShotAlarm(Alarm1_2);
	
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_24 = SetRelAlarm(Alarm2_1, 2 , 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(26,E_OK, result_inst_24);	
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_25 = SetRelAlarm(Alarm2_1, 2 , 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(27,E_OS_STATE, result_inst_25);	
	
	SCHEDULING_CHECK_INIT(28);
	result_inst_26 = GetAlarm(Alarm2_1, &tik);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(28,E_OK, result_inst_26);
	SCHEDULING_CHECK_AND_EQUAL_INT(28,2, tik);
	
	WaitActivationPeriodicAlarm(Alarm2_1);
	
	SCHEDULING_CHECK_INIT(29);
	result_inst_27 = CancelAlarm(Alarm2_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(29,E_OK, result_inst_27);	
	
	
	SCHEDULING_CHECK_INIT(30);
	result_inst_28 = SetAbsAlarm(Alarm2_2, 2 , 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(30,E_OK, result_inst_28);	
	
	SCHEDULING_CHECK_INIT(31);
	result_inst_29 = SetAbsAlarm(Alarm2_2, 2 , 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(31,E_OS_STATE, result_inst_29);	
	
	WaitActivationOneShotAlarm(Alarm2_2);
	
	
	SCHEDULING_CHECK_INIT(32);
	result_inst_30 = SetRelAlarm(Alarm3, 2 , 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(32,E_OK, result_inst_30);	
	
	SCHEDULING_CHECK_INIT(33);
	result_inst_31 = SetRelAlarm(Alarm3, 2 , 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(33,E_OS_STATE, result_inst_31);	
	
	SCHEDULING_CHECK_INIT(34);
	result_inst_32 = GetAlarm(Alarm3, &tik);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(34,E_OK, result_inst_32);
	SCHEDULING_CHECK_AND_EQUAL_INT(34,2, tik);
	
	WaitActivationPeriodicAlarm(Alarm3);
	
	SCHEDULING_CHECK_INIT(36);
	result_inst_33 = CancelAlarm(Alarm3);
	SCHEDULING_CHECK_AND_EQUAL_INT(36,E_OK, result_inst_33);	
	
	
	SCHEDULING_CHECK_INIT(37);
	result_inst_34 = SetAbsAlarm(Alarm3, 2 , 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(37,E_OK, result_inst_34);	
	
	SCHEDULING_CHECK_INIT(38);
	result_inst_35 = SetAbsAlarm(Alarm3, 2 , 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(38,E_OS_STATE, result_inst_35);	
	
	WaitActivationOneShotAlarm(Alarm3);
	
	SCHEDULING_CHECK_STEP(40);
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq9_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence9",NULL,NULL,fixtures);
	
	return (TestRef)&AlarmsTest;
}

/* End of file alarms_s9_non/isr1_instance.c */
