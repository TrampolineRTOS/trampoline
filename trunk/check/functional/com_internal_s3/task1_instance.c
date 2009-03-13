/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_com_definitions.h"  //for E_COM_ID
#include "config.h" /*Display information in the right way (printf on UNIX...)*/

DeclareMessage(sm_activatetask);
DeclareMessage(sm_setevent);
DeclareMessage(sm_comcallback);
DeclareTask(t3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1, result_inst_2;
	
	result_inst_1 = ActivateTask(t3);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	result_inst_2 = SendMessage(sm_activatetask, "1");	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	result_inst_2 = SendMessage(sm_setevent, "2");	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	result_inst_2 = SendMessage(sm_comcallback, "3");	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	/*result_inst_2 = ActivateTask(t4);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	result_inst_2 = SendMessage(sm_flag, "4");
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	result_inst_2 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	*/
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
