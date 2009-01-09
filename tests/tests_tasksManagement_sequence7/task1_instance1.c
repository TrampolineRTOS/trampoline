/*Instance 1 of task t1*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance1(void)
{
	int result_inst1_1,result_inst1_2,result_inst1_3,result_inst1_4;
	result_inst1_1 = ActivateTask(t2);
	result_inst1_2 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst1_1); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst1_2);
	Schedule();
	result_inst1_3 = ActivateTask(t1);
	result_inst1_4 = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst1_3); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst1_4);
	ChainTask(t3);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq7_t1_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance1",test_t1_instance1)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence7",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
