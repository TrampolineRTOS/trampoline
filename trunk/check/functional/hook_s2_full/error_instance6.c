/*Instance 6 of error hook routine*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_error_instance6(void)
{
	SCHEDULING_CHECK_STEP(28);

}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_error_instance6(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance6",test_error_instance6)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
