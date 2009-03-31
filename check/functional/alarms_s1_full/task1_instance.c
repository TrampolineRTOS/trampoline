/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_alarm_kernel.h" /*for INVALID_ALARM*/
#include "tpl_os_generated_configuration.h"

DeclareAlarm(Alarm1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	
	StatusType result_inst_2, result_inst_4, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17;
	AlarmBaseType result_inst_1, result_inst_5;
	TickType result_inst_3;
	
	result_inst_2 = GetAlarmBase(INVALID_ALARM, &result_inst_1);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_2);
	
	result_inst_4 = GetAlarm(INVALID_ALARM, &result_inst_3);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_4);
	
	result_inst_6 = GetAlarmBase(Alarm1, &result_inst_5);
	TEST_ASSERT_EQUAL_INT(OSMAXALLOWEDVALUE_Counter1, (int)(result_inst_5.maxallowedvalue));
	TEST_ASSERT_EQUAL_INT(OSTICKSPERBASE_Counter1, (int)(result_inst_5.ticksperbase));
	TEST_ASSERT_EQUAL_INT(OSMINCYCLE_Counter1, (int)(result_inst_5.mincycle));	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_6);
	
	result_inst_7 = SetRelAlarm(INVALID_ALARM, 0, 0);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_7);
	
	result_inst_8 = SetRelAlarm(Alarm1, -1, 0);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_8);
	
	result_inst_9 = SetRelAlarm(Alarm1, result_inst_5.maxallowedvalue + 1, 0);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_9);

	result_inst_10 = SetRelAlarm(Alarm1, 0, result_inst_5.mincycle - 1);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_10);
	
	result_inst_11 = SetRelAlarm(Alarm1, 0,  result_inst_5.maxallowedvalue + 1);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_11);
	
	result_inst_12 = SetAbsAlarm(INVALID_ALARM, 0, 0);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_12);
	
	result_inst_13 = SetAbsAlarm(Alarm1, -1, 0);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_13);
	
	result_inst_14 = SetAbsAlarm(Alarm1, result_inst_5.maxallowedvalue + 1, 0);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_14);
	
	result_inst_15 = SetAbsAlarm(Alarm1, 0, result_inst_5.mincycle - 1);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_15);
	
	result_inst_16 = SetAbsAlarm(Alarm1, 0,  result_inst_5.maxallowedvalue + 1);
	TEST_ASSERT_EQUAL_INT(E_OS_VALUE, result_inst_16);
	
	result_inst_17 = CancelAlarm(INVALID_ALARM);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_17);
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence1",NULL,NULL,fixtures);

	return (TestRef)&AlarmsTest;
}
