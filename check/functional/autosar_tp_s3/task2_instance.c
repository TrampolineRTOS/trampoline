
/*Instance of task t2*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{	
	SCHEDULING_CHECK_STEP(5);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarTPTest_seq3_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTPTest,"AutosarTPTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTPTest;
}

