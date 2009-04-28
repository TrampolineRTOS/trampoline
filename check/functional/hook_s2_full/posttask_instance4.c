/*Instance 4 of posttask hook routine*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t1);
DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_posttask_instance4(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
	TaskType task_id;
	TaskStateType task_state;
	EventMaskType event_mask;
	
	SCHEDULING_CHECK_INIT(42);
	result_inst_1 = GetTaskID(&task_id);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(42,t1 , task_id);
	SCHEDULING_CHECK_AND_EQUAL_INT(42,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(43);
	result_inst_2 = GetTaskState(task_id, &task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(43,RUNNING , task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT(43,E_OK , result_inst_2);
	
	SCHEDULING_CHECK_INIT(44);
	result_inst_3 = GetEvent(task_id,&event_mask);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(44,Event1 , event_mask);
	SCHEDULING_CHECK_AND_EQUAL_INT(44,E_OK , result_inst_3);
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_posttask_instance4(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_posttask_instance4",test_posttask_instance4)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}
