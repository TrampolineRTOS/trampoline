/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_com_definitions.h"  /*for E_COM_ID*/

DeclareMessage(sm_activatetask);
DeclareMessage(sm_setevent);
DeclareMessage(sm_comcallback);
DeclareTask(t3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = ActivateTask(t3);	
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = SendMessage(sm_activatetask, "1");	
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_3 = SendMessage(sm_setevent, "2");	
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_4 = SendMessage(sm_comcallback, "3");	
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_4);
	
	/* Message flag doesn't work
	 result_inst_2 = ActivateTask(t4);
	SCHEDULING_CHECK_AND_EQUAL_INT(X,E_OK, result_inst_2);
	
	result_inst_2 = SendMessage(sm_flag, "4");
	SCHEDULING_CHECK_AND_EQUAL_INT(X,E_OK, result_inst_2);
	*/
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_5 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_5);
	
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
