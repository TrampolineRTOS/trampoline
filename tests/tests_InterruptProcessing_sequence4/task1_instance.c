/*Instance of task t1*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "../../os/tpl_os_kernel.h"

#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1;
	/*result_inst_1 = EnableInterrupt(isr2|isr3);
	...
	...
	TEST_ASSERT_EQUAL_INT((E_OK|E_OS_NOFUNC), result_inst_1);*/
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq4_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence4",setUp,tearDown,fixtures);

	return (TestRef)&InterruptProcessingTest;
}
