/*Instance of task t4*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_newisgreater);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t4_instance2(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(57);
	result_inst_1 = ReceiveMessage(rm_newisgreater, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(57,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(57,5, (int)received_char);
	
	SCHEDULING_CHECK_INIT(58);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(58,E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq5_t4_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t4_instance2",test_t4_instance2)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
