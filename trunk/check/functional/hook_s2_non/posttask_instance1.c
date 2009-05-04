/*Instance 1 of posttask hook routine*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"; /*for OSMAXALLOWEDVALUE_Counter1...*/

DeclareAlarm(Alarm1);
DeclareTask(INVALID_TASK);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_posttask_instance1(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	TaskType task_id;
	TaskStateType task_state;
	EventMaskType event_mask;
	AlarmBaseType alarm_base;
	TickType tik;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetActiveApplicationMode();
	SCHEDULING_CHECK_AND_EQUAL_INT(1,OSDEFAULTAPPMODE , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = GetTaskID(&task_id);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(2,INVALID_TASK , task_id); 
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK , result_inst_2); 
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_3 = GetTaskState(task_id, &task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OS_ID , result_inst_3);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_4 = GetEvent(task_id,&event_mask);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_ID , result_inst_4);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_5 = GetAlarmBase(Alarm1, &alarm_base);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(7,OSMAXALLOWEDVALUE_Counter1, (int)(alarm_base.maxallowedvalue));
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(7,OSTICKSPERBASE_Counter1, (int)(alarm_base.ticksperbase));
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(7,OSMINCYCLE_Counter1, (int)(alarm_base.mincycle));
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK , result_inst_5);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_6 = GetAlarm(Alarm1,&tik);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OS_NOFUNC , result_inst_6);
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_posttask_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_posttask_instance1",test_posttask_instance1)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}
