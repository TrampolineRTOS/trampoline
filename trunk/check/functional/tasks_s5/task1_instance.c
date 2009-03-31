/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t3);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst;
	
	result_inst = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq5_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence5",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
