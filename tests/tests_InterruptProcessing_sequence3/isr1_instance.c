/*Instance of interruption isr1*/

#include "test_instances.h"
#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_isr1_instance(void)
{
	int result_inst_1;
	/*result_inst_1 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);*/
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq3_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence3",setUp,tearDown,fixtures);

	return (TestRef)&InterruptProcessingTest;
}
