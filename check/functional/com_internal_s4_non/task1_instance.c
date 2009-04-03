/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_com_definitions.h"  /*for E_COM_X*/

DeclareMessage(sm);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	StatusType car1;
		
	car1 = 3;
	result_inst_2 = SendMessage(sm, &car1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	car1 = 12;
	result_inst_3 = SendMessage(sm, &car1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);
	
	car1 = 7;
	result_inst_4 = SendMessage(sm, &car1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_4);
	
	car1 = 7;
	result_inst_5 = SendMessage(sm, &car1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_5);
	
	car1 = 2;
	result_inst_6 = SendMessage(sm, &car1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_6);
		
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq4_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
