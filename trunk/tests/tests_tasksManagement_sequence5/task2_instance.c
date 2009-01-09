/*Instance of task t2*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	int result_inst;
	result_inst = GetEvent(t2, 0x0);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst);
	TerminateTask();
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq5_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence5",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
