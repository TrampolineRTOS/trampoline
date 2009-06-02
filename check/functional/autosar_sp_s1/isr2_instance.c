
/*Instance of task isr1*/

#include "embUnit.h"
#include "Os.h"
#include "tpl_as_isr.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_isr2_instance(void)
{
	SCHEDULING_CHECK_STEP(8);
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq1_isr2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr2_instance",test_isr2_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}
