/*Instance 3 of callback*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_callback_instance3(void)
{
	SCHEDULING_CHECK_STEP(10);
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq4_callback_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_callback_instance3",test_callback_instance3)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&AlarmsTest;
}
