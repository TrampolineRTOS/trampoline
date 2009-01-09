/*Instance 2 of task t1*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance2(void)
{
	int result_inst2;
	result_inst2 = ActivateTask(t1);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst2);
	TerminateTask();
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq7_t1_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance2",test_t1_instance2)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence7",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
