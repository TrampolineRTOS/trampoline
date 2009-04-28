/*Instance of task t8*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t8_instance(void)
{
	SCHEDULING_CHECK_STEP(15);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq13_t8_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t8_instance",test_t8_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence13",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
