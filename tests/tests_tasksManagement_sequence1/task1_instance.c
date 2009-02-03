/*Instance of task t1*/

#include "test_instances.h"
#include <embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "../../os/tpl_os_kernel.h"

/*#include "../../autosar/Os.h"*/

#include "tpl_os_generated_configuration.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	EnableAllInterrupts();
	result_inst_2 = ActivateTask(INVALID_TASK);
	result_inst_3 = GetTaskState(INVALID_TASK,0x0);
	result_inst_4 = ChainTask(INVALID_TASK);
	result_inst_5 = ActivateTask(t2);
	Schedule();

	result_inst_6 = GetResource(RES_SCHEDULER);
	result_inst_7 = TerminateTask();
	result_inst_8 = ChainTask(t2);
	result_inst_9 = ReleaseResource(RES_SCHEDULER);
	
/*	tpl_activate_isr();
	...
	...*/



	//TEST_ASSERT_EQUAL_INT((E_OK|E_OS_NOFUNC), result_inst_1);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_2);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_3);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_4);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_5);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_6);
	
	TEST_ASSERT_EQUAL_INT(E_OS_RESOURCE, result_inst_7);
	TEST_ASSERT_EQUAL_INT(E_OS_RESOURCE, result_inst_8);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_9);
	
	TerminateTask();
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence1",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
