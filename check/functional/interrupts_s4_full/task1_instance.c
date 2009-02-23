/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareAlarm(Alarm1);

void WaitActivationOneShotAlarm(AlarmType Alarm);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1;
	
	EnableAllInterrupts();
	
	result_inst_1 = SetAbsAlarm(Alarm1, 2, 0);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	WaitActivationOneShotAlarm(Alarm1);		
	
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
