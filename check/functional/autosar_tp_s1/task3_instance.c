
/*Instance of task t3*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance(void)
{
	
  SCHEDULING_CHECK_STEP(7);
  
  while(1); /* --> ProtectionHook */
		
}

/*create the test suite with all the test cases*/
TestRef AutosarTPTest_seq1_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTPTest,"AutosarTPTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTPTest;
}

