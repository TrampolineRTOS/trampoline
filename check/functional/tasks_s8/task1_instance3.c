/*Instance 3 of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance3(void)
{
	SCHEDULING_CHECK_STEP(9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq8_t1_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance3",test_t1_instance3)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence8",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
