/*Instance 3 of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance3(void)
{
	StatusType result_inst;
	
	SCHEDULING_CHECK_INIT(11);
	result_inst = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK , result_inst);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq12_t2_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance3",test_t2_instance3)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence12",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
