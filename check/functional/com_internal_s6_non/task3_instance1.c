/*Instance 1 of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_maskednewdiffersx);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance1(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_1 = ReceiveMessage(rm_maskednewdiffersx, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(3,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,3, (int)received_char);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq6_t3_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance1",test_t3_instance1)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
