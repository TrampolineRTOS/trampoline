/*Instance 4 of posttask*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it2(void);

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_posttask_instance4(void)
{
	SCHEDULING_CHECK_STEP(5);
	
	tpl_send_it2();
	SuspendAllInterrupts();
	tpl_send_it2();
	ResumeAllInterrupts();
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq6_posttask_instance4(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_posttask_instance4",test_posttask_instance4)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence6",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
