/*Instance 5 of com error*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_com_error.h" /*for COMErrorGetServiceId()*/

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_comerror_instance5(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_1 = COMErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT(23,COMServiceId_SendMessage , result_inst_1);
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_2 = (StatusType)(*COMError_ReceiveMessage_DataRef());
	SCHEDULING_CHECK_AND_EQUAL_INT(24,(StatusType)('3') , result_inst_2);
	
	SCHEDULING_CHECK_INIT(25);
	result_inst_3 = (StatusType)COMError_ReceiveMessage_Message();
	SCHEDULING_CHECK_AND_EQUAL_INT(25, (StatusType)(-1) , result_inst_3);
	
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq1_comerror_instance5(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_comerror_instance5",test_comerror_instance5)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
