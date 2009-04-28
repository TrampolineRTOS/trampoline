/*Instance of task t4*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_newisequal);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t4_instance(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(45);
	result_inst_1 = ReceiveMessage(rm_newisequal, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(45,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(45,2, (int)received_char);
	
	SCHEDULING_CHECK_INIT(46);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(46,E_OK, result_inst_2);
	
	
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq6_t4_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t4_instance",test_t4_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
