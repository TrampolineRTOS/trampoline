/*Instance of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareCounter(Counter1);
DeclareTask(t1);
DeclareAlarm(Alarm1);

void WaitActivationOneShotAlarm(AlarmType Alarm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2;
	TickType TickType_inst_1, TickType_inst_2 = 0, TickType_inst_3, alarm_increment;
	
	alarm_increment = 2;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetCounterValue(Counter1, &TickType_inst_1);	
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(1,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,0, TickType_inst_1);

	SCHEDULING_CHECK_INIT(2);
	do{
		result_inst_1 = GetCounterValue(Counter1, &TickType_inst_1);
	}while(TickType_inst_1 < 2);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,2 , TickType_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = SetRelAlarm(Alarm1, alarm_increment, 0);	
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_2);	

	SCHEDULING_CHECK_INIT(4);
	result_inst_1 = GetCounterValue(Counter1, &TickType_inst_1);	
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK, result_inst_1);
	
	WaitActivationOneShotAlarm(Alarm1);
	
	SCHEDULING_CHECK_INIT(5);
	int temp = TickType_inst_1;
	result_inst_1 = GetElapsedCounterValue(Counter1, &TickType_inst_1, &TickType_inst_3);	   
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(5,E_OK , result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(5, temp + alarm_increment , TickType_inst_1); /**/
	SCHEDULING_CHECK_AND_EQUAL_INT(5, alarm_increment , TickType_inst_3); /*alarm_increment*/
		
}

/*create the test suite with all the test cases*/
TestRef AutosarTest_seq2_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTest,"AutosarTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTest;
}
