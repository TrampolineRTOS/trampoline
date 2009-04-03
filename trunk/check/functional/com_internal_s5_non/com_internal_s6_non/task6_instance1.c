/*Instance of task t6*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_newisless);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t6_instance1(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	result_inst_1 = ReceiveMessage(rm_newisless, &received_char);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	TEST_ASSERT_EQUAL_INT(1, (int)received_char);
	
	result_inst_2 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq5_t6_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t6_instance1",test_t6_instance1)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
