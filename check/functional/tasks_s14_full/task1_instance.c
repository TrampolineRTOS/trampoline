/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);
DeclareTask(t3);
DeclareTask(t4);
DeclareTask(t5);
DeclareTask(t6);
DeclareTask(t7);
DeclareTask(t8);
DeclareTask(t9);
DeclareTask(t10);
DeclareTask(t11);
DeclareTask(t12);
DeclareTask(t13);
DeclareTask(t14);
DeclareTask(t15);
DeclareTask(t16);
DeclareEvent(Task1_Event1);
DeclareEvent(Task1_Event2);
DeclareEvent(Task1_Event3);
DeclareEvent(Task1_Event4);
DeclareEvent(Task1_Event5);
DeclareEvent(Task1_Event6);
DeclareEvent(Task1_Event7);
DeclareEvent(Task1_Event8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17, result_inst_18, result_inst_19, result_inst_20, result_inst_21, result_inst_22, result_inst_23, result_inst_24;
	
	result_inst_1 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1);
	
	result_inst_2 = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
	
	result_inst_3 = ActivateTask(t4);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3);
	
	result_inst_4 = ActivateTask(t5);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_4);
	
	result_inst_5 = ActivateTask(t6);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_5);
	
	result_inst_6 = ActivateTask(t7);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_6);
	
	result_inst_7 = ActivateTask(t8);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_7);
	
	result_inst_8 = ActivateTask(t9);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_8);
	
	result_inst_9 = ActivateTask(t10);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_9);
	
	result_inst_10 = ActivateTask(t11);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_10);
	
	result_inst_11 = ActivateTask(t12);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_11);
	
	result_inst_12 = ActivateTask(t13);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_12);
	
	result_inst_13 = ActivateTask(t14);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_13);
	
	result_inst_14 = ActivateTask(t15);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_14);
	
	result_inst_15 = ActivateTask(t16);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_15);
	
	result_inst_16 = ClearEvent(Task1_Event1);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_16);
	
	result_inst_17 = ClearEvent(Task1_Event2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_17);
	
	result_inst_18 = ClearEvent(Task1_Event3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_18);
	
	result_inst_19 = ClearEvent(Task1_Event4);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_19);
	
	result_inst_20 = ClearEvent(Task1_Event5);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_20);
	
	result_inst_21 = ClearEvent(Task1_Event6);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_21);
	
	result_inst_22 = ClearEvent(Task1_Event7);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_22);
	
	result_inst_23 = ClearEvent(Task1_Event8);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_23);
	
	result_inst_24 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_24);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq14_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence14",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
