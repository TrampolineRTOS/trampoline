/*Instance of task t1*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17, result_inst_18, result_inst_19, result_inst_20, result_inst_21, result_inst_22, result_inst_23;

	result_inst_1 = ActivateTask(t2);
	result_inst_2 = ActivateTask(t3);
	result_inst_3 = ActivateTask(t4);
	result_inst_4 = ActivateTask(t5);
	result_inst_5 = ActivateTask(t6);
	result_inst_6 = ActivateTask(t7);
	result_inst_7 = ActivateTask(t8);
	result_inst_8 = ActivateTask(t9);
	result_inst_9 = ActivateTask(t10);
	result_inst_10 = ActivateTask(t11);
	result_inst_11 = ActivateTask(t12);
	result_inst_12 = ActivateTask(t13);
	result_inst_13 = ActivateTask(t14);
	result_inst_14 = ActivateTask(t15);
	result_inst_15 = ActivateTask(t16);
	result_inst_16 = ClearEvent(Task1_Event1);
	result_inst_17 = ClearEvent(Task1_Event2);
	result_inst_18 = ClearEvent(Task1_Event3);
	result_inst_19 = ClearEvent(Task1_Event4);
	result_inst_20 = ClearEvent(Task1_Event5);
	result_inst_21 = ClearEvent(Task1_Event6);
	result_inst_22 = ClearEvent(Task1_Event7);
	result_inst_23 = ClearEvent(Task1_Event8);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_4);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_5); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_6);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_7); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_8);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_9); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_10);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_11); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_12);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_13); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_14);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_15); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_16);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_17); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_18);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_19); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_20);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_21); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_22);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_23);
	TerminateTask();
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
