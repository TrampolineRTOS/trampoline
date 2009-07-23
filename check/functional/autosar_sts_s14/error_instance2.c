/*Instance 2 of error*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance2(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT(12,OSServiceId_ActivateTask , result_inst_1);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTSTest_seq14_error_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance2",test_error_instance2)
	};
	EMB_UNIT_TESTCALLER(AutosarSTSTest,"AutosarSTSTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTSTest;
}
