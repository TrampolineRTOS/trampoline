/*Instance of interruption isr1*/

#include "test_instances.h"
#include <embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "../../os/tpl_os_kernel.h"
#include "defaultAppWorkstation/tpl_os_generated_configuration.h"

DeclareTask(t2);


/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_isr1_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4;
	result_inst_1 = TerminateTask();
	result_inst_2 = ChainTask(t2);
	result_inst_3 = Schedule();
	/*result_inst_4 = GetTaskID();*/
	TEST_ASSERT_EQUAL_INT(E_OS_CALLEVEL , result_inst_1);
	TEST_ASSERT_EQUAL_INT(E_OS_CALLEVEL , result_inst_2);
	TEST_ASSERT_EQUAL_INT(E_OS_CALLEVEL , result_inst_3);
	/*TEST_ASSERT_EQUAL_INT(E_OS_CALLEVEL , result_inst_4);*/
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq1_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence1",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
