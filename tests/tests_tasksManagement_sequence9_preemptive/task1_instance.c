/*Instance of task t1*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1,result_inst_2,result_inst_3,result_inst_4;
	result_inst_1 = GetTaskID(t1);
	result_inst_2 = GetTaskState(t1, RUNNING);
	result_inst_3 = GetTaskState(t2, SUSPENDED);
	result_inst_4 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_4);
	ChainTask(t3);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq9_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence9",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
