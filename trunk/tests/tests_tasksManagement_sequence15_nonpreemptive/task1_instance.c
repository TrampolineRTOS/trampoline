/*Instance of task t1*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1,result_inst_2,result_inst_3,result_inst_4,result_inst_5,result_inst_6,result_inst_7;
	result_inst_1 = ActivateTask(t2);
	result_inst_2 = ActivateTask(t3);
	result_inst_3 = ActivateTask(t4);
	result_inst_4 = ActivateTask(t5);
	result_inst_5 = ActivateTask(t6);
	result_inst_6 = ActivateTask(t7);
	result_inst_7 = ActivateTask(t8);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_4);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_5); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_6);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_7); 
	TerminateTask();
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq15_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence15",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
