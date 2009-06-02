/*Instance of task t3*/

#include "embUnit.h"
#include "Os.h"

DeclareAlarm(Alarm1);

void WaitActivationOneShotAlarm(AlarmType Alarm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = SetRelAlarm(Alarm1, 3, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(1, E_OK, result_inst_1);
	
	WaitActivationOneShotAlarm(Alarm1);
	
	SCHEDULING_CHECK_STEP(11);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq2_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}
