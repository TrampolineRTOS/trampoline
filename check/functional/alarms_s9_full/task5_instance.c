/*Instance of task t5*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t5_instance(void)
{
	StatusType result_inst_1;
	
	EnableAllInterrupts();
	
	tpl_send_it1();
	
	result_inst_1 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq11_t5_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t5_instance",test_t5_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence11",NULL,NULL,fixtures);
	
	return (TestRef)&AlarmsTest;
}
