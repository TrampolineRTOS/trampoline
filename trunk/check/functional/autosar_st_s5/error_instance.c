/*Instance of error*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT(13,OSServiceId_ActivateTask , result_inst_1);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq5_error_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance",test_error_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}
