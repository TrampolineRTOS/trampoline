/*Instance 4 of com error*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_com_error.h" /*for COMErrorGetServiceId()*/

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_comerror_instance4(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
	
	SCHEDULING_CHECK_INIT(33);
	result_inst_1 = COMErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT(33,COMServiceId_ReceiveMessage , result_inst_1);
	
	SCHEDULING_CHECK_INIT(34);
	result_inst_2 = (StatusType)(*COMError_ReceiveMessage_DataRef());
	SCHEDULING_CHECK_AND_EQUAL_INT(34,(StatusType)('3') , result_inst_2);
	
	SCHEDULING_CHECK_INIT(35);
	result_inst_3 = (StatusType)COMError_ReceiveMessage_Message();
	SCHEDULING_CHECK_AND_EQUAL_INT(35,SEND_MESSAGE_COUNT , result_inst_3);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq2_comerror_instance4(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_comerror_instance4",test_comerror_instance4)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
