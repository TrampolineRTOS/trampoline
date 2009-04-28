/*Instance 1 of task t4*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t4_instance1(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_1 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OK, result_inst_1);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq16_t4_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t4_instance1",test_t4_instance1)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence16",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
