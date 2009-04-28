/*Instance of error hook routine*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"; /*for OSMAXALLOWEDVALUE_Counter1...*/

DeclareTask(t1);
DeclareAlarm(Alarm1);
DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	TaskType task_id;
	TaskStateType task_state;
	EventMaskType event_mask;
	AlarmBaseType alarm_base;
	TickType tik;
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_1 = GetActiveApplicationMode();
	SCHEDULING_CHECK_AND_EQUAL_INT(4,OSDEFAULTAPPMODE , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_2 = GetTaskID(&task_id);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(5,E_OK , result_inst_2); 
	SCHEDULING_CHECK_AND_EQUAL_INT(5,t1 , task_id); 
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_3 = GetTaskState(task_id, &task_state);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(6,E_OK , result_inst_3); 
	SCHEDULING_CHECK_AND_EQUAL_INT(6,RUNNING , task_state); 
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_4 = GetEvent(task_id,&event_mask);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(7,E_OK , result_inst_2); 
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK , result_inst_2); 
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_5 = GetAlarmBase(Alarm1, &alarm_base);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(8,OSMAXALLOWEDVALUE_Counter1, (int)(alarm_base.maxallowedvalue));
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(8,OSTICKSPERBASE_Counter1, (int)(alarm_base.ticksperbase));
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(8,OSMINCYCLE_Counter1, (int)(alarm_base.mincycle));
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK , result_inst_5);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_6 = GetAlarm(Alarm1,&tik);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK , result_inst_6);
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq3_error_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance",test_error_instance)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}
