/*Instance of task t1*/

//#include "test_instances.h"
#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h" /*for INVALID_TASK*/

DeclareTask(t1);
DeclareTask(t2);
DeclareEvent(Event1);

void tpl_send_it2(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1,result_inst_2, result_inst_3, result_inst_4, result_inst_6, result_inst_8, result_inst_10, result_inst_11, result_inst_12;
	
	EnableAllInterrupts();
	
	result_inst_1 = SetEvent(INVALID_TASK,Event1);	
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_1);
	
	result_inst_2 = SetEvent(t1,Event1);	
	TEST_ASSERT_EQUAL_INT(E_OS_ACCESS, result_inst_2);
	
	result_inst_3 = SetEvent(t2,Event1);	
	TEST_ASSERT_EQUAL_INT(E_OS_STATE, result_inst_3);
	
	result_inst_4 = ClearEvent(Event1);	
	TEST_ASSERT_EQUAL_INT(E_OS_ACCESS, result_inst_4);
	
	tpl_send_it2();
		
	EventMaskType result_inst_5; 
	result_inst_6 = GetEvent(INVALID_TASK,&result_inst_5);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_6);

	EventMaskType result_inst_7; 
	result_inst_8 = GetEvent(t1,&result_inst_7);	
	TEST_ASSERT_EQUAL_INT(E_OS_ACCESS, result_inst_8);	
	
	EventMaskType result_inst_9; 
	result_inst_10 = GetEvent(t2,&result_inst_9);
	TEST_ASSERT_EQUAL_INT(E_OS_STATE, result_inst_10);	
	
	result_inst_11 = WaitEvent(Event1);
	TEST_ASSERT_EQUAL_INT(E_OS_ACCESS, result_inst_11);

	result_inst_12 = ChainTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_12);

}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
