/*Instance of task t4*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t4_instance(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_1 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq3_t4_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t4_instance",test_t4_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}
