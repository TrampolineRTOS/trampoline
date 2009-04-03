/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_setevent);
DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
	StatusType received_char;
	
	result_inst_1 = WaitEvent(Event1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	result_inst_2 = ReceiveMessage(rm_setevent, &received_char);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	TEST_ASSERT_EQUAL_INT((int)('2'), (int)received_char);

	result_inst_3 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq4_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
