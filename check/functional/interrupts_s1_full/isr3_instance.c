/*Instance of interruption isr3*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it2(void);

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_isr3_instance(void)
{	
	SCHEDULING_CHECK_STEP(23);
	
	tpl_send_it2();
	
	SCHEDULING_CHECK_STEP(24);
	
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq1_isr3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr3_instance",test_isr3_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence1",NULL,NULL,fixtures);

	return (TestRef)&InterruptProcessingTest;
}
