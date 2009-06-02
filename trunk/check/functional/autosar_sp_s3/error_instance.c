/*Instance of error*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance(void)
{
	StatusType result_inst_1;

	extern StatusType error_status;
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(5, E_OS_DISABLEDINT , error_status);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,OSServiceId_TerminateISR , result_inst_1);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq3_error_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance",test_error_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}
