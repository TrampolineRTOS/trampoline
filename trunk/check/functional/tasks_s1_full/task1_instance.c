/*Instance of task t1*/
#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h" /*for INVALID_TASK*/

DeclareTask(t1);
DeclareTask(t2);

void tpl_send_it2(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
	
	EnableAllInterrupts();
	
	result_inst_2 = ActivateTask(INVALID_TASK);	
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_2);
	
	result_inst_3 = GetTaskState(INVALID_TASK,0x0);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_3);
	
	result_inst_4 = ChainTask(INVALID_TASK);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_4);
	
	result_inst_5 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_5);
		
	result_inst_6 = GetResource(RES_SCHEDULER);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_6);
	
	result_inst_7 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OS_RESOURCE, result_inst_7);
	
	result_inst_8 = ChainTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OS_RESOURCE, result_inst_8);
	
	result_inst_9 = ReleaseResource(RES_SCHEDULER);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_9);
	
	tpl_send_it2();
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
