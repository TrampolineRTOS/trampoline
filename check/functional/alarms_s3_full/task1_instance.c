/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareAlarm(Alarm1);

void WaitActivationPeriodicAlarm(AlarmType Alarm);
void WaitActivationOneShotAlarm(AlarmType Alarm);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	TickType result_inst_7;
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = SetAbsAlarm(Alarm1, 2, 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = SetAbsAlarm(Alarm1, 3, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OS_STATE, result_inst_2);
	
	WaitActivationPeriodicAlarm(Alarm1);
	
	WaitActivationPeriodicAlarm(Alarm1);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_3 = CancelAlarm(Alarm1);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_4 = SetRelAlarm(Alarm1, 2, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_5 = SetRelAlarm(Alarm1, 3, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OS_STATE, result_inst_5);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_6 = GetAlarm(Alarm1, &result_inst_7);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(11,2, result_inst_7);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_6);
	
	WaitActivationOneShotAlarm(Alarm1);

	SCHEDULING_CHECK_STEP(13);
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence3",NULL,NULL,fixtures);

	return (TestRef)&AlarmsTest;
}
