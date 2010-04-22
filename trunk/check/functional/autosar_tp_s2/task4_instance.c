
/*Instance of task t4*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t4_instance(void)
{
  
  SCHEDULING_CHECK_STEP(11);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarTPTest_seq2_t4_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t4_instance",test_t4_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTPTest,"AutosarTPTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTPTest;
}

