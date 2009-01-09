/*Instance of interruption isr3*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_isr3_instance(void)
{
/*	EnterISR();
	LeaveISR();*/
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq1_isr3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr3_instance",test_isr3_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence1",setUp,tearDown,fixtures);

	return (TestRef)&InterruptProcessingTest;
}
