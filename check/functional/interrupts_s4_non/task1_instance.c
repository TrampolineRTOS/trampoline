/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareAlarm(Alarm1);
DeclareAlarm(Alarm2);

void WaitActivationOneShotAlarm(AlarmType Alarm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2;
	
	EnableAllInterrupts();
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = SetAbsAlarm(Alarm1, 2, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	WaitActivationOneShotAlarm(Alarm1);	
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_2 = SetAbsAlarm(Alarm2, 2, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_2);
	
	WaitActivationOneShotAlarm(Alarm2);		
	
	SCHEDULING_CHECK_STEP(9);
	
}

/*create the test suite with all the test cases*/
TestRef InterruptsTest_seq4_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptsTest,"InterruptsTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&InterruptsTest;
}
