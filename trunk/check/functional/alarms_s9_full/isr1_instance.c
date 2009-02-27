/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_alarm_kernel.h" /*for INVALID_ALARM*/

DeclareAlarm(Alarm0);
DeclareAlarm(Alarm1_1);
DeclareAlarm(Alarm1_2);
DeclareAlarm(Alarm2_1);
DeclareAlarm(Alarm2_2);
DeclareAlarm(Alarm3);
DeclareTask(t4);

void WaitActivationOneShotAlarm(AlarmType Alarm);
void WaitActivationPeriodicAlarm(AlarmType Alarm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_isr1_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15;
	int result_inst_16, result_inst_17, result_inst_18, result_inst_19, result_inst_20, result_inst_21, result_inst_22, result_inst_23, result_inst_24, result_inst_25, result_inst_26, result_inst_27, result_inst_28, result_inst_29, result_inst_30, result_inst_31, result_inst_32, result_inst_33, result_inst_34, result_inst_35;
	
	result_inst_1 = ActivateTask(t4);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	AlarmBaseType alarmbase;
	result_inst_2 = GetAlarmBase(INVALID_ALARM, &alarmbase);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_2);
	
	result_inst_3 = GetAlarmBase(Alarm0, &alarmbase);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);
	
	TickType tik;
	result_inst_4 = GetAlarm(INVALID_ALARM, &tik);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_4);
	
	result_inst_5 = GetAlarm(Alarm0, &tik);
	TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC, result_inst_5);
	
	
	result_inst_6 = SetRelAlarm(INVALID_ALARM, 0, 0);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_6);
	
	result_inst_7 = SetRelAlarm(Alarm0, -1 , 0);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_7);
	
	result_inst_8 = SetRelAlarm(Alarm0, alarmbase.maxallowedvalue + 1 , 0);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_8);	
	
	result_inst_9 = SetRelAlarm(Alarm0, 0 , alarmbase.mincycle - 1);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_9);
	
	result_inst_10 = SetRelAlarm(Alarm0, 0 , alarmbase.maxallowedvalue + 1);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_10);	
	
	
	result_inst_11 = SetAbsAlarm(INVALID_ALARM, 0, 0);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_11);
	
	result_inst_12 = SetAbsAlarm(Alarm0, -1 , 0);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_12);
	
	result_inst_13 = SetAbsAlarm(Alarm0, alarmbase.maxallowedvalue + 1 , 0);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_13);	
	
	result_inst_14 = SetAbsAlarm(Alarm0, 0 , alarmbase.mincycle - 1);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_14);
	
	result_inst_15 = SetAbsAlarm(Alarm0, 0 , alarmbase.maxallowedvalue + 1);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_15);	
	
	
	result_inst_16 = CancelAlarm(INVALID_ALARM);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_16);	
	
	result_inst_17 = CancelAlarm(Alarm0);
	TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC, result_inst_17);	
	
	//Alarm1_1 & Alarm1_2	
	result_inst_18 = SetRelAlarm(Alarm1_1, 2 , 2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_18);	
	
	result_inst_19 = SetRelAlarm(Alarm1_1, 2 , 2);
	TEST_ASSERT_EQUAL_INT(E_OS_STATE, result_inst_19);	
	
	result_inst_20 = GetAlarm(Alarm1_1, &tik);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_20);
	TEST_ASSERT_EQUAL_INT(2, tik);
	
	WaitActivationPeriodicAlarm(Alarm1_1);
	
	result_inst_21 = CancelAlarm(Alarm1_1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_21);	
	
	
	result_inst_22 = SetAbsAlarm(Alarm1_2, 2 , 0);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_22);	
	
	result_inst_23 = SetAbsAlarm(Alarm1_2, 2 , 2);
	TEST_ASSERT_EQUAL_INT(E_OS_STATE, result_inst_23);	
	
	WaitActivationOneShotAlarm(Alarm1_2);
	
	//Alarm2_1 & Alarm2_2
	result_inst_24 = SetRelAlarm(Alarm2_1, 2 , 2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_24);	
	
	result_inst_25 = SetRelAlarm(Alarm2_1, 2 , 2);
	TEST_ASSERT_EQUAL_INT(E_OS_STATE, result_inst_25);	
	
	result_inst_26 = GetAlarm(Alarm2_1, &tik);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_26);
	TEST_ASSERT_EQUAL_INT(2, tik);
	
	WaitActivationPeriodicAlarm(Alarm2_1);
	
	result_inst_27 = CancelAlarm(Alarm2_1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_27);	
	
	
	result_inst_28 = SetAbsAlarm(Alarm2_2, 2 , 0);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_28);	
	
	result_inst_29 = SetAbsAlarm(Alarm2_2, 2 , 2);
	TEST_ASSERT_EQUAL_INT(E_OS_STATE, result_inst_29);	
	
	WaitActivationOneShotAlarm(Alarm2_2);
	
	//Alarm3
	result_inst_30 = SetRelAlarm(Alarm3, 2 , 2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_30);	
	
	result_inst_31 = SetRelAlarm(Alarm3, 2 , 2);
	TEST_ASSERT_EQUAL_INT(E_OS_STATE, result_inst_31);	
	
	result_inst_32 = GetAlarm(Alarm3, &tik);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_32);
	TEST_ASSERT_EQUAL_INT(2, tik);
	
	WaitActivationPeriodicAlarm(Alarm3);
	
	result_inst_33 = CancelAlarm(Alarm3);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_33);	
	
	
	result_inst_34 = SetAbsAlarm(Alarm3, 2 , 0);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_34);	
	
	result_inst_35 = SetAbsAlarm(Alarm3, 2 , 2);
	TEST_ASSERT_EQUAL_INT(E_OS_STATE, result_inst_35);	
	
	WaitActivationOneShotAlarm(Alarm3);
	
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq11_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence11",NULL,NULL,fixtures);
	
	return (TestRef)&AlarmsTest;
}
