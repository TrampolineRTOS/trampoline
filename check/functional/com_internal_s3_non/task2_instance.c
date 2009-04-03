/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_activatetask);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	result_inst_1 = ReceiveMessage(rm_activatetask, &received_char);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	TEST_ASSERT_EQUAL_INT((int)('1'), (int)received_char);
	
	ShutdownOS(E_OK);
	//result_inst_2 = TerminateTask();
	//TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq3_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
