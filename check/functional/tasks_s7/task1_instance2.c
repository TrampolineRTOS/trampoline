/*Instance 2 of task t1*/

#include "tpl_os.h"
#include "embUnit.h"

DeclareTask(t1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance2(void)
{
	int result_inst2_1, result_inst2_2;
	
	result_inst2_1 = ActivateTask(t1);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst2_1);
	
	result_inst2_2 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst2_2);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq7_t1_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance2",test_t1_instance2)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence7",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
