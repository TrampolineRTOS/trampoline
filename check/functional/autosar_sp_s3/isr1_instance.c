
/*Instance of task isr1*/

#include "embUnit.h"
#include "Os.h"

void tpl_send_it3(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_isr1_instance(void)
{
	SCHEDULING_CHECK_STEP(2);
	DisableAllInterrupts();
	
	/*check interrupts disabled*/
	SCHEDULING_CHECK_STEP(3);
	tpl_send_it3();
	
	SCHEDULING_CHECK_STEP(4);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq3_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}

