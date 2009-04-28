/*Instance of task t8*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_oneeveryn);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t8_instance2(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(47);
	result_inst_1 = ReceiveMessage(rm_oneeveryn, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(47,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(47,1, (int)received_char);
	
	SCHEDULING_CHECK_INIT(48);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(48,E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq5_t8_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t8_instance2",test_t8_instance2)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
