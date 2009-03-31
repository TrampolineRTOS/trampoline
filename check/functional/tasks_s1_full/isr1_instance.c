/*Instance of interruption isr1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h" /*for INVALID_TASK*/

DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_5;
	TaskType result_inst_4;

	result_inst_1 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OS_CALLEVEL , result_inst_1);
	
	result_inst_2 = ChainTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OS_CALLEVEL , result_inst_2);
	
	result_inst_3 = Schedule();
	TEST_ASSERT_EQUAL_INT(E_OS_CALLEVEL , result_inst_3);
	
	result_inst_5 = GetTaskID(&result_inst_4);
	TEST_ASSERT_EQUAL_INT(INVALID_TASK , result_inst_4);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_5);
	
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq1_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
