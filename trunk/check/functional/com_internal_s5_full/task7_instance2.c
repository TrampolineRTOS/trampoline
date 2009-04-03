/*Instance of task t7*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_newisgreaterorequal);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t7_instance2(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	result_inst_1 = ReceiveMessage(rm_newisgreaterorequal, &received_char);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	TEST_ASSERT_EQUAL_INT(3, (int)received_char);
	
	result_inst_2 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq5_t7_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t7_instance2",test_t7_instance2)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
