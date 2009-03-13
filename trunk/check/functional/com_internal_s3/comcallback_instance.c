/*Instance of comcallback routine*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_com_definitions.h" //for E_COM_ID

DeclareMessage(rm_comcallback);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_comcallback_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3;
	
	char received_char;
	
	result_inst_1 = ReceiveMessage(rm_comcallback, &received_char);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	TEST_ASSERT_EQUAL_INT((int)('3'), (int)received_char);
	
	stdimpl_print("Message received from callback routine = %c \n",received_char);
	
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq3_comcallback_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_comcallback_instance",test_comcallback_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
