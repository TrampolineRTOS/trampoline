/*Instance 1 of com error*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_com_error.h" /*for COMErrorGetServiceId()*/

DeclareMessage(sm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_comerror_instance1(void)
{
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = COMErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT(2,COMServiceId_GetMessageStatus , result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = COMError_GetMessageStatus_Message();
	SCHEDULING_CHECK_AND_EQUAL_INT(3,sm , result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq1_comerror_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_comerror_instance1",test_comerror_instance1)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
