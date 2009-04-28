/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst_1;
	
	EnableAllInterrupts();
	
	SCHEDULING_CHECK_STEP(5);
	tpl_send_it1();
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_1 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OK, result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq5_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
