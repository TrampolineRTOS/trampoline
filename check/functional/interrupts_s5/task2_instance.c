/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst;
	
	SCHEDULING_CHECK_INIT(2);
	result_inst = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst); 
	
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq3_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence3",NULL,NULL,fixtures);

	return (TestRef)&InterruptProcessingTest;
}
