/*Instance of task t3*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t3_instance(void)
{
	int result_inst;
	result_inst = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst);
	TerminateTask();
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq3_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence3",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
