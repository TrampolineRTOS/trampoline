/*Instance of task t4*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t4_instance(void)
{
	int result_inst;
	result_inst = SetEvent(t2, Event2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst);
	TerminateTask();
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq11_t4_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t4_instance",test_t4_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence11",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
