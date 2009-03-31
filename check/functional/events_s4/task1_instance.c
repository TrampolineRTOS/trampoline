/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);
DeclareTask(t3);
DeclareTask(t4);
DeclareEvent(Event1);
DeclareEvent(Event2);
DeclareEvent(Event3);


/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_3, result_inst_5, result_inst_6, result_inst_8, result_inst_9, result_inst_11, result_inst_12, result_inst_13, result_inst_14;
	TaskStateType result_inst_2, result_inst_7;
	EventMaskType result_inst_4, result_inst_10;

	result_inst_1 = SetEvent(t2,Event2);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);	
	
	result_inst_3 = GetTaskState(t2, &result_inst_2);
	TEST_ASSERT_EQUAL_INT(WAITING, result_inst_2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);	

	result_inst_5 = GetEvent(t2,&result_inst_4);
	TEST_ASSERT_EQUAL_INT(Event2, result_inst_4);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_5);	
	
	result_inst_6 = ActivateTask(t3);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_6);	
	
	result_inst_8 = GetTaskState(t3, &result_inst_7);
	TEST_ASSERT_EQUAL_INT(READY, result_inst_7);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_8);
	
	result_inst_9 = SetEvent(t3,Event3);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_9);	
	
	result_inst_11 = GetEvent(t3,&result_inst_10);
	TEST_ASSERT_EQUAL_INT(Event3, result_inst_10);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_11);	
	
	result_inst_12 = SetEvent(t2,Event1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_12);	
	
	result_inst_13 = ActivateTask(t4);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_13);	
	
	result_inst_14 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_14);
	
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq4_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
