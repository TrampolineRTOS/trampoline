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
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_1 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_2 = ReceiveMessage(rm_setevent, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(8,E_OK, result_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,(int)('2'), (int)received_char);

	SCHEDULING_CHECK_INIT(9);
	result_inst_3 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_3);
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
