/*Instance 4 of pretask hook routine*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_pretask_instance4(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
	TaskType task_id;
	TaskStateType task_state;
	EventMaskType event_mask;

	SCHEDULING_CHECK_INIT(45);
	result_inst_1 = GetTaskID(&task_id);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(45,t2 , task_id); 
	SCHEDULING_CHECK_AND_EQUAL_INT(45,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(46);
	result_inst_2 = GetTaskState(task_id, &task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(46,RUNNING , task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT(46,E_OK , result_inst_2);

	SCHEDULING_CHECK_INIT(47);
	result_inst_3 = GetEvent(task_id,&event_mask);
	SCHEDULING_CHECK_AND_EQUAL_INT(48,E_OS_ACCESS , result_inst_3);

}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_pretask_instance4(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_pretask_instance4",test_pretask_instance4)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
