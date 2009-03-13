/*Instance 5 of com error*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h" //for stdimpl_print
#include "tpl_com_error.h" //for COMErrorGetServiceId()

DeclareMessage(rm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_comerror_instance5(void)
{
	int result_inst_1;
		
	result_inst_1 = COMErrorGetServiceId();
	TEST_ASSERT_EQUAL_INT(COMServiceId_GetMessageStatus , result_inst_1);
	
	TEST_ASSERT_EQUAL_INT(SEND_MESSAGE_COUNT , COMError_ReceiveMessage_Message());
	//TEST_ASSERT_EQUAL_INT((int)('3') , *COMError_ReceiveMessage_DataRef());
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq2_comerror_instance5(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_comerror_instance5",test_comerror_instance5)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
