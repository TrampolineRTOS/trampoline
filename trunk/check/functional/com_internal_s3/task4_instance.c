/*Instance of task t4*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_flag);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t4_instance(void)
{
	StatusType result_inst_1;
	StatusType received_char;
		
	/* while readflag != 1, then receive message
	while (ReadFlag() != 1) {
	
	}*/
		
	SCHEDULING_CHECK_INIT(13);
	result_inst_1 = ReceiveMessage(rm_flag, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(13,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,(int)('2'), (int)received_char);
	
	/*result_inst_3 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(X,E_OK, result_inst_3);
	 */
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq3_t4_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t4_instance",test_t4_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
