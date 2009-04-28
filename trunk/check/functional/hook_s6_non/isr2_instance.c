/*Instance of interruption isr2*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr2_instance(void)
{	
	SCHEDULING_CHECK_STEP(6);
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq6_isr2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr2_instance",test_isr2_instance)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}
