/*Instance of task t1*/

#include "test_instances.h"
#include <embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "defaultAppWorkstation/tpl_os_generated_configuration.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst;
	result_inst = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq10_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence10",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
