/*Instance 1 of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance1(void)
{
	int result_inst1_1, result_inst1_2;
	
	result_inst1_1 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst1_1);
	
	result_inst1_2 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst1_2);

}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq8_t1_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance1",test_t1_instance1)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence8",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
