/*Instance 6 of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_always);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance6(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(37);
	result_inst_1 = ReceiveMessage(rm_always, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(37,0, (int)received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT(37,E_OK, result_inst_1);
		
	SCHEDULING_CHECK_INIT(38);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(38,E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq5_t2_instance6(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance6",test_t2_instance6)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
