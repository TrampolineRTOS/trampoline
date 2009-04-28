/*Instance 8 of pretask*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_pretask_instance8(void)
{
	SCHEDULING_CHECK_STEP(10);
	
	tpl_send_it1();
	SuspendAllInterrupts();
	tpl_send_it1();
	ResumeAllInterrupts();
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq5_pretask_instance8(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_pretask_instance8",test_pretask_instance8)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence5",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
