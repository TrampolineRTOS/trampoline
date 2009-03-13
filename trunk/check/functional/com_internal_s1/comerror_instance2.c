/*Instance of com error*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h" //for stdimpl_print
#include "tpl_com_error.h" //for COMErrorGetServiceId()

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_comerror_instance2(void)
{
	int result_inst_1;
	
	result_inst_1 = COMErrorGetServiceId();
	TEST_ASSERT_EQUAL_INT(COMServiceId_ReceiveMessage , result_inst_1);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq1_comerror_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_comerror_instance2",test_comerror_instance2)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
