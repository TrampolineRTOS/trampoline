/*Instance of interruption isr2*/

//#include "test_instances.h"
#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_isr2_instance(void)
{
	int result_inst_1;
	
	result_inst_1 = GetActiveApplicationMode();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq4_isr2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr2_instance",test_isr2_instance)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence4",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
