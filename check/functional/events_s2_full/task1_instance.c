/*Instance of task t1*/

//#include "test_instances.h"
#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t1);
DeclareTask(t2);
DeclareEvent(Event1);
DeclareEvent(Event2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_2, result_inst_3, result_inst_5, result_inst_6, result_inst_7,  result_inst_9, result_inst_10;
	
	EventMaskType result_inst_1;
	result_inst_2 = GetEvent(t2,&result_inst_1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	result_inst_3 = SetEvent(t1,Event1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);
	
	EventMaskType result_inst_4;
	result_inst_5 = GetEvent(t1,&result_inst_4);
	TEST_ASSERT_EQUAL_INT(Event1, result_inst_4);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_5);
	
	result_inst_6 = WaitEvent(Event1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_6);
	
	result_inst_7 = ClearEvent(Event1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_7);
	
	EventMaskType result_inst_8;
	result_inst_9 = GetEvent(t1,&result_inst_8);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_8);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_9);
	
	result_inst_10 = SetEvent(t2,Event2);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_10);

}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq2_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
