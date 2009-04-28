/*Instance 2 of task t6*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_maskednewequalsmaskedold);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t6_instance2(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(36);
	result_inst_1 = ReceiveMessage(rm_maskednewequalsmaskedold, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(36,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(36,2, (int)received_char);
	
	SCHEDULING_CHECK_INIT(37);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(37,E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq6_t6_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t6_instance2",test_t6_instance2)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
