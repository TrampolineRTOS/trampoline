
/*Instance of task t2*/

#include "embUnit.h"
#include "Os.h"

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	
	SCHEDULING_CHECK_STEP(9);
	
	/*check interrupts enabled*/
	tpl_send_it1();
	
	SCHEDULING_CHECK_STEP(11);
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq1_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}

