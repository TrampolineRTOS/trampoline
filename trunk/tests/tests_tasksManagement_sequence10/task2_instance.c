/*Instance of task t2*/

#include "test_instances.h"
#include <embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "defaultAppWorkstation/tpl_os_generated_configuration.h"

DeclareTask(t3);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	int result_inst_1,result_inst_2;
	result_inst_1 = GetEvent(t2, 0x0);
	result_inst_2 = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
	TerminateTask();
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq10_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence10",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
