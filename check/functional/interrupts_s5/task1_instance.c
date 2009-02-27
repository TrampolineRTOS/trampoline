/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1;
	
	EnableAllInterrupts();
	
	SuspendAllInterrupts();
	
	//test API service calls (ActivateTask...)
	result_inst_1 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	ResumeAllInterrupts();


}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence3",NULL,NULL,fixtures);

	return (TestRef)&InterruptProcessingTest;
}
