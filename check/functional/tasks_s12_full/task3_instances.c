/*Instances of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instances(void)
{
	int result_inst;
	
	result_inst = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq12_t3_instances(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instances",test_t3_instances)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence12",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
