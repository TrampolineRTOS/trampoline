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
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_7, result_inst_6, result_inst_7, result_inst_8, result_inst_9;
/*	result_inst_1 = EnableInterrupt(isr1);
	result_inst_2 = DisableInterrupt(isr1);
	result_inst_3 = EnableInterrupt(isr1);
	result_inst_4 = EnableInterrupt(isr2);
	result_inst_5 = DisableInterrupt(isr2);
	result_inst_6 = EnableInterrupt(isr2);
	result_inst_7 = EnableInterrupt(isr3);
	result_inst_8 = DisableInterrupt(isr3);
	result_inst_9 = EnableInterrupt(isr3);
	TEST_ASSERT_EQUAL_INT((E_OK|E_OS_NOFUNC), result_inst_1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);
	TEST_ASSERT_EQUAL_INT((E_OK|E_OS_NOFUNC), result_inst_4);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_5);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_6);
	TEST_ASSERT_EQUAL_INT((E_OK|E_OS_NOFUNC), result_inst_7);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_8);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_9);*/
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence1",setUp,tearDown,fixtures);

	return (TestRef)&InterruptProcessingTest;
}
