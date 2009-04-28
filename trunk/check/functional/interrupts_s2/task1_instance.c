/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it2(void);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst;

	EnableAllInterrupts();
	
	SCHEDULING_CHECK_STEP(1);
	
	tpl_send_it2();

	SCHEDULING_CHECK_INIT(5);
	result_inst = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst); 
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq2_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence2",NULL,NULL,fixtures);

	return (TestRef)&InterruptProcessingTest;
}
