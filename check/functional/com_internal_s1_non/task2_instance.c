/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_com_definitions.h" /*for E_COM_ID*/

DeclareMessage(rm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_1 = GetMessageStatus(rm);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_COM_ID, result_inst_1);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_2 = ReceiveMessage(rm, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(15,E_OK, result_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,(int)('1'), (int)received_char);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_3 = ReceiveMessage(rm, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(16,E_OK, result_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,(int)('1'), (int)received_char);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_4 = ReceiveMessage(SEND_MESSAGE_COUNT, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_COM_ID, result_inst_4);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_5 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OK, result_inst_5);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq1_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
