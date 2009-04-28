/*Instance2 of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance2(void)
{
	SCHEDULING_CHECK_STEP(9);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq9_t3_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance2",test_t3_instance2)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence9",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
