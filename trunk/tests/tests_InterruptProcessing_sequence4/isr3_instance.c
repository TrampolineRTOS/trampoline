/*Instance of interruption isr3*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_isr3_instance(void)
{
	int result_inst_1;
/*	EnterISR();
	result_inst_1 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	LeaveISR();*/
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq4_isr3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr3_instance",test_isr3_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence4",setUp,tearDown,fixtures);

	return (TestRef)&InterruptProcessingTest;
}
