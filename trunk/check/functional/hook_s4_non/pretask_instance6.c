/*Instance 6 of pretask*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it2(void);

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_pretask_instance6(void)
{
	SCHEDULING_CHECK_STEP(8);
	
	tpl_send_it2();
	SuspendAllInterrupts();
	tpl_send_it2();
	ResumeAllInterrupts();
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq4_pretask_instance6(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_pretask_instance6",test_pretask_instance6)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}
