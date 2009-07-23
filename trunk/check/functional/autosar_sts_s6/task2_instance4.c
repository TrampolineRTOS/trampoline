/*Instance 4 of task t2*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance4(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(25);
	result_inst_1 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(25,E_OK, result_inst_1);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTSTest_seq6_t2_instance4(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance4",test_t2_instance4)
	};
	EMB_UNIT_TESTCALLER(AutosarSTSTest,"AutosarSTSTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTSTest;
}
