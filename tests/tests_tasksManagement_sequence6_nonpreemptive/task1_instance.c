/*Instance of task t1*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1,result_inst_2,result_inst_3,result_inst_4,result_inst_5;
	result_inst_1 = ActivateTask(t2);
	Schedule();
	result_inst_2 = GetTaskState(t2,RUNNING);
	result_inst_3 = ActivateTask(t2);
	result_inst_4 = ChainTask(t2);
	result_inst_5 = SetEvent(t2,Event2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
	TEST_ASSERT_EQUAL_INT(E_OS_LIMIT , result_inst_3);
	TEST_ASSERT_EQUAL_INT(E_OS_LIMIT , result_inst_4);	
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_5);
	Schedule();
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq6_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence6",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
