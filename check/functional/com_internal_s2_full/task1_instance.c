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
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12;
	
	result_inst_1 = GetMessageStatus(sm);	
	TEST_ASSERT_EQUAL_INT(E_COM_NOMSG, result_inst_1);
	
	result_inst_2 = SendMessage(SEND_MESSAGE_COUNT, "5");	
	TEST_ASSERT_EQUAL_INT(E_COM_ID, result_inst_2);
	
	result_inst_3 = GetMessageStatus(sm);	
	TEST_ASSERT_EQUAL_INT(E_COM_NOMSG, result_inst_3);
	
	result_inst_4 = SendMessage(sm, "1");	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_4);
	
	result_inst_5 = GetMessageStatus(sm);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_5);
	
	result_inst_6 = SendMessage(sm, "2");	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_6);
	
	result_inst_7 = GetMessageStatus(sm);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_7);
	
	result_inst_8 = SendMessage(sm, "3");	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_8);
	
	result_inst_9 = GetMessageStatus(sm);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_9);
	
	result_inst_10 = SendMessage(sm, "4");	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_10);
	
	result_inst_11 = GetMessageStatus(sm);	
	TEST_ASSERT_EQUAL_INT(E_COM_LIMIT, result_inst_11);
	
	result_inst_12 = ActivateTask(t2);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_12);
			
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq2_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
