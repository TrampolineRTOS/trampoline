/*Instance 4 of interruption isr1*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_isr1_instance4(void)
{
	SCHEDULING_CHECK_STEP(14);

}

/*create the test suite with all the test cases*/
TestRef HookTest_seq5_isr1_instance4(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance4",test_isr1_instance4)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence5",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
