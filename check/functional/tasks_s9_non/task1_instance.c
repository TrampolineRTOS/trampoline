/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t1);
DeclareTask(t2);
DeclareTask(t3);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_2,result_inst_4,result_inst_6,result_inst_7,result_inst_8,result_inst_9;
	
	TaskType result_inst_1;
	result_inst_2 = GetTaskID(&result_inst_1);
	TEST_ASSERT_EQUAL_INT(0 , result_inst_1);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
	
	TaskStateType result_inst_3;
	result_inst_4 = GetTaskState(t1,&result_inst_3);
	TEST_ASSERT_EQUAL_INT(RUNNING , result_inst_3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_4);
	
	TaskStateType result_inst_5;
	result_inst_6 = GetTaskState(t2,&result_inst_5);
	TEST_ASSERT_EQUAL_INT(SUSPENDED , result_inst_5);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_6);
	
	result_inst_7 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_7);
	
	result_inst_8 = Schedule();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_8);
	
	result_inst_9 = ChainTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_9);

}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq9_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence9",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
