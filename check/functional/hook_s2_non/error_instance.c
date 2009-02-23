/*Instance of error hook routine*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_error_instance(void)
{
	int result_inst_1;
	
	result_inst_1 = GetActiveApplicationMode();
	TEST_ASSERT_EQUAL_INT(OSDEFAULTAPPMODE , result_inst_1); 
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_error_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance",test_error_instance)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
