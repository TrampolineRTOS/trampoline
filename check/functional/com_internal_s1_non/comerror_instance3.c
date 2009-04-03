/*Instance 3 of com error*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_com_error.h" /*for COMErrorGetServiceId()*/

DeclareMessage(rm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_comerror_instance3(void)
{
	StatusType result_inst_1, result_inst_2;
		
	result_inst_1 = COMErrorGetServiceId();
	TEST_ASSERT_EQUAL_INT(COMServiceId_GetMessageStatus , result_inst_1);
	
	result_inst_2 = COMError_GetMessageStatus_Message();
	TEST_ASSERT_EQUAL_INT(rm , result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq1_comerror_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_comerror_instance3",test_comerror_instance3)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
