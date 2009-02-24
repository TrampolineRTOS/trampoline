/*Instance1 of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance1(void)
{
	int result_inst;
	
	result_inst = ChainTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst);
	
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq9_t3_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance1",test_t3_instance1)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence9",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
