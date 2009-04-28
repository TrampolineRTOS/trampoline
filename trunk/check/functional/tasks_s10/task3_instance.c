/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t3);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst_2, result_inst_3;
	EventMaskType result_inst_1;
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_2 = GetEvent(t3, &result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(5,E_OK , result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK , result_inst_2);

	SCHEDULING_CHECK_INIT(6);
	result_inst_3 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK , result_inst_3);
	
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq10_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence10",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
