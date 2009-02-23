/*Instance of isr1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h" //for INVALID_TASK

DeclareTask(t1);
DeclareTask(t2);
DeclareTask(t3);
DeclareTask(t4);
DeclareTask(t5);
DeclareTask(t6);
DeclareTask(t7);
DeclareTask(t8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_isr1_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_15, result_inst_17, result_inst_19;
	
	result_inst_1 = ActivateTask(INVALID_TASK);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_1);
	
	result_inst_2 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2); 
	
	result_inst_3 = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3); 
	
	result_inst_4 = ActivateTask(t4);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_4); 
	
	result_inst_5 = ActivateTask(t5);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_5); 
	
	result_inst_6 = ActivateTask(t6);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_6); 
	
	result_inst_7 = ActivateTask(t7);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_7); 
	
	result_inst_8 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_8); 
	
	result_inst_9 = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_9); 
	
	result_inst_10 = ActivateTask(t4);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_10); 
	
	result_inst_11 = ActivateTask(t1);
	TEST_ASSERT_EQUAL_INT(E_OS_LIMIT , result_inst_11); 
	
	result_inst_12 = ActivateTask(t5);
	TEST_ASSERT_EQUAL_INT(E_OS_LIMIT , result_inst_12); 
	
	result_inst_13 = ActivateTask(t8);
	TEST_ASSERT_EQUAL_INT(E_OS_LIMIT , result_inst_13); 
	
	TaskStateType result_inst_14;
	result_inst_15 = GetTaskState(INVALID_TASK, &result_inst_14);
	//TEST_ASSERT_EQUAL_INT(E_OK , result_inst_14); 
	TEST_ASSERT_EQUAL_INT(E_OS_ID , result_inst_15);
	
	TaskStateType result_inst_16;
	result_inst_17 = GetTaskState(t8, &result_inst_16);
	TEST_ASSERT_EQUAL_INT(WAITING , result_inst_16); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_17);
	
	TaskType result_inst_18;
	result_inst_19 = GetTaskID(&result_inst_18);
	TEST_ASSERT_EQUAL_INT(INVALID_TASK , result_inst_18);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_19); 

}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq16_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence16",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
