/*Instance 2 of callback*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_callback_instance2(void)
{
	SCHEDULING_CHECK_STEP(39);
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq9_callback_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_callback_instance2",test_callback_instance2)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence9",NULL,NULL,fixtures);
	
	return (TestRef)&AlarmsTest;
}
