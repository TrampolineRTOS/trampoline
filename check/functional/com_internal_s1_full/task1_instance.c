/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_com_definitions.h"  /*for E_COM_ID*/

DeclareMessage(sm);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	
	/*result_inst_1 = GetCOMApplicationMode();	
	SCHEDULING_CHECK_AND_EQUAL_INT(X,E_OK, result_inst_1);
	*/
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetMessageStatus(sm);	
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_COM_ID, result_inst_1);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_2 = SendMessage(SEND_MESSAGE_COUNT, "3");	
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_COM_ID, result_inst_2);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_3 = SendMessage(sm, "0");
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_4 = SendMessage(sm, "1");	
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_5 = ActivateTask(t2);	
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_6 = SendMessage(-1, "3");
	SCHEDULING_CHECK_AND_EQUAL_INT(24,E_COM_ID, result_inst_6);
	
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
