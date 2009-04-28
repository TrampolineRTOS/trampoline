/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_2, result_inst_3;
	TaskStateType result_inst_1;
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_2 = GetTaskState(t1,&result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(5,READY , result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_3 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK , result_inst_3);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq9_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence9",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
