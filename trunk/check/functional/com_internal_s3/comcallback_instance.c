/*Instance of comcallback routine*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_comcallback);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_comcallback_instance(void)
{
	StatusType result_inst_1;
	StatusType received_char;
	
	/*not allowed !!! Should be E_OS_CALLEVEL*/
	SCHEDULING_CHECK_INIT(10);
	result_inst_1 = ReceiveMessage(rm_comcallback, &received_char); 
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(10,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,(int)('3'), (int)received_char);
	
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq3_comcallback_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_comcallback_instance",test_comcallback_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
