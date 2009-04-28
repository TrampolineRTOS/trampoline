/*Instance 2 of task t1*/

#include "tpl_os.h"
#include "embUnit.h"

DeclareTask(t1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance2(void)
{
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_1 = ActivateTask(t1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK , result_inst_1);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK , result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq7_t1_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance2",test_t1_instance2)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence7",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
