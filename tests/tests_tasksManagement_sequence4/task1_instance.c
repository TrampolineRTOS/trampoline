/*Instance of task t1*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1,result_inst_2,result_inst_3;
	result_inst_1 = ActivateTask(t2);
	result_inst_2 = GetEvent(t1, 0x0);
	result_inst_3 = GetEvent(t2, 0x0);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3);
	TEST_ASSERT_EQUAL_INT(E_OK , Schedule());
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq4_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence4",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
