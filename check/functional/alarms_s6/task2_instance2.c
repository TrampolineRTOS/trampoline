/*Instance2 of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance2(void)
{
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq6_t2_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance2",test_t2_instance2)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&AlarmsTest;
}
