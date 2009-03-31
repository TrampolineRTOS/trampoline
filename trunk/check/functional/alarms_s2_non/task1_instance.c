/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"

DeclareAlarm(Alarm1);

void WaitActivationPeriodicAlarm(AlarmType Alarm);
void WaitActivationOneShotAlarm(AlarmType Alarm);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	
	StatusType result_inst_2, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_14, result_inst_15;
	AlarmBaseType result_inst_1;
	TickType result_inst_3, result_inst_13;
	
	result_inst_2 = GetAlarmBase(Alarm1, &result_inst_1);
	TEST_ASSERT_EQUAL_INT(OSMAXALLOWEDVALUE_Counter1, (int)(result_inst_1.maxallowedvalue));
	TEST_ASSERT_EQUAL_INT(OSTICKSPERBASE_Counter1, (int)(result_inst_1.ticksperbase));
	TEST_ASSERT_EQUAL_INT(OSMINCYCLE_Counter1, (int)(result_inst_1.mincycle));
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	result_inst_4 = GetAlarm(Alarm1, &result_inst_3);
	TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC, result_inst_4);
	
	result_inst_5 = CancelAlarm(Alarm1);
	TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC, result_inst_5);
	
	result_inst_6 = SetAbsAlarm(Alarm1, 2, 2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_6);
	
	result_inst_7 = SetAbsAlarm(Alarm1, 3, 0);
	TEST_ASSERT_EQUAL_INT(E_OS_STATE, result_inst_7);

	WaitActivationPeriodicAlarm(Alarm1);
	
	result_inst_8 = Schedule();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_8);	

	WaitActivationPeriodicAlarm(Alarm1);

	result_inst_9 = Schedule();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_9);	

	result_inst_10 = CancelAlarm(Alarm1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_10);
	
	result_inst_11 = SetRelAlarm(Alarm1, 2, 0);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_11);
	
	result_inst_12 = SetRelAlarm(Alarm1, 3, 0);
	TEST_ASSERT_EQUAL_INT(E_OS_STATE, result_inst_12);
	
	result_inst_14 = GetAlarm(Alarm1, &result_inst_13);
	TEST_ASSERT_EQUAL_INT(2, result_inst_13);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_14);
	
	WaitActivationOneShotAlarm(Alarm1);

	result_inst_15 = Schedule();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_15);
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq2_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence2",NULL,NULL,fixtures);

	return (TestRef)&AlarmsTest;
}
