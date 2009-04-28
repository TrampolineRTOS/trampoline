/*Instance 2 of task t4*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t4_instance2(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_1 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OK, result_inst_1);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq16_t4_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t4_instance2",test_t4_instance2)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence16",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
