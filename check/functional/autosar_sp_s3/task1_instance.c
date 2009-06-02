/*Instance of task t1*/

#include "embUnit.h"
#include "Os.h"

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	SCHEDULING_CHECK_STEP(1);
	
	tpl_send_it1();
	
	SCHEDULING_CHECK_STEP(7);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}