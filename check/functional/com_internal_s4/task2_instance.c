/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_activatetask);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_1 = ReceiveMessage(rm_activatetask, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(10,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,(int)('1'), (int)received_char);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq4_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
