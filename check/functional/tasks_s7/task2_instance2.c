/*Instance 2 of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance2(void)
{
	StatusType result_inst;
	
	SCHEDULING_CHECK_INIT(5);
	result_inst = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK , result_inst); 
	
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq7_t2_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance2",test_t2_instance2)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence7",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
