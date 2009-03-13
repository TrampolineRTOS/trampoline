/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_com_definitions.h" //for E_COM_NOMSG...

DeclareMessage(rm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5;
	
	char received_char;
	
	result_inst_1 = GetMessageStatus(rm);	
	TEST_ASSERT_EQUAL_INT(E_COM_LIMIT, result_inst_1);
	
	result_inst_1 = ReceiveMessage(rm, &received_char);
	TEST_ASSERT_EQUAL_INT(E_COM_LIMIT, result_inst_1);
	TEST_ASSERT_EQUAL_INT((int)('1'), (int)received_char);
	//stdimpl_print("Message received = %c \n",received_char);

	result_inst_1 = GetMessageStatus(rm);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	result_inst_2 = ReceiveMessage(rm, &received_char);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	TEST_ASSERT_EQUAL_INT((int)('2'), (int)received_char);
	//stdimpl_print("Message received = %c \n",received_char);
	
	result_inst_1 = GetMessageStatus(rm);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	result_inst_3 = ReceiveMessage(rm, &received_char);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);
	TEST_ASSERT_EQUAL_INT((int)('3'), (int)received_char);
	//stdimpl_print("Message received = %c \n",received_char);
	
	result_inst_1 = GetMessageStatus(rm);	
	TEST_ASSERT_EQUAL_INT(E_COM_NOMSG, result_inst_1);
	
	result_inst_4 = ReceiveMessage(rm, &received_char);
	TEST_ASSERT_EQUAL_INT(E_COM_NOMSG, result_inst_4);

	result_inst_1 = GetMessageStatus(rm);	
	TEST_ASSERT_EQUAL_INT(E_COM_NOMSG, result_inst_1);
	
	result_inst_2 = ReceiveMessage(SEND_MESSAGE_COUNT, &received_char);
	TEST_ASSERT_EQUAL_INT(E_COM_ID, result_inst_2);
	
	result_inst_1 = GetMessageStatus(SEND_MESSAGE_COUNT);	
	TEST_ASSERT_EQUAL_INT(E_COM_ID, result_inst_1);

	result_inst_5 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_5);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq2_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
