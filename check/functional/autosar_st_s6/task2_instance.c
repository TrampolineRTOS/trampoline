/*Instance of task t2*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	SCHEDULING_CHECK_STEP(16);
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq6_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}
