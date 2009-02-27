/*Instance of interruption isr1*/

//#include "test_instances.h"
#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_isr1_instance(void)
{
	//
	
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq2_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence2",NULL,NULL,fixtures);

	return (TestRef)&InterruptProcessingTest;
}
