/*Instance 1 of pretask hook routine*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"; /*for OSMAXALLOWEDVALUE_Counter1...*/

DeclareTask(t1);
DeclareTask(t2);
DeclareAlarm(Alarm1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_pretask_instance1(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	TaskType task_id;
	TaskStateType task_state;
	EventMaskType event_mask;
	AlarmBaseType alarm_base;
	TickType tik;
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_1 = GetActiveApplicationMode();
	SCHEDULING_CHECK_AND_EQUAL_INT(10,OSDEFAULTAPPMODE , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_2 = GetTaskID(&task_id);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(11,t1 , task_id); 
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK , result_inst_2); 
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_3 = GetTaskState(task_id, &task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(12,RUNNING , task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK , result_inst_3);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_4 = GetEvent(task_id,&event_mask);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_5 = GetAlarmBase(Alarm1, &alarm_base);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(14,OSMAXALLOWEDVALUE_Counter1, (int)(alarm_base.maxallowedvalue));
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(14,OSTICKSPERBASE_Counter1, (int)(alarm_base.ticksperbase));
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(14,OSMINCYCLE_Counter1, (int)(alarm_base.mincycle));
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK , result_inst_5);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_6 = GetAlarm(Alarm1,&tik);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OS_NOFUNC , result_inst_6);
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_pretask_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_pretask_instance1",test_pretask_instance1)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}
