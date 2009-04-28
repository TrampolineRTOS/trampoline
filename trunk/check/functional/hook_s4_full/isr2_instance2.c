/*Instance 2 of interruption isr2*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr2_instance2(void)
{
	SCHEDULING_CHECK_STEP(9);

	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq4_isr2_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr2_instance2",test_isr2_instance2)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}
