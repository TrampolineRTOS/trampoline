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
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_1 = COMErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT(13,COMServiceId_GetMessageStatus , result_inst_1);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_2 = COMError_GetMessageStatus_Message();
	SCHEDULING_CHECK_AND_EQUAL_INT(14,rm , result_inst_2);
	
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
