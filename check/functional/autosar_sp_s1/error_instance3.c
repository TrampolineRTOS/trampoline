/*Instance of error*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance3(void)
{
	extern StatusType error_status;
	
	SCHEDULING_CHECK_INIT(7);
	SCHEDULING_CHECK_AND_EQUAL_INT(7, E_OS_MISSINGEND , error_status);
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq1_error_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance3",test_error_instance3)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}

