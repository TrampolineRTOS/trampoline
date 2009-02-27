/*Instance of error hook routine*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h" /*Display information n the right way (printf on UNIX...)*/
#include "tpl_os_generated_configuration.h"; //for OSMAXALLOWEDVALUE_Counter1...

DeclareTask(t1);
DeclareAlarm(Alarm1);
DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_error_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	
	result_inst_1 = GetActiveApplicationMode();
	TEST_ASSERT_EQUAL_INT(OSDEFAULTAPPMODE , result_inst_1); 
	
	TaskType task_id;
	result_inst_2 = GetTaskID(&task_id);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2); 
	TEST_ASSERT_EQUAL_INT(t1 , task_id); 
		
	TaskStateType task_state;
	result_inst_3 = GetTaskState(task_id, &task_state);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3); 
	TEST_ASSERT_EQUAL_INT(RUNNING , task_state); 
	
	EventMaskType event_mask;
	result_inst_4 = GetEvent(task_id,&event_mask);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2); 
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2); 
	
	AlarmBaseType alarm_base;
	result_inst_5 = GetAlarmBase(Alarm1, &alarm_base);
	TEST_ASSERT_EQUAL_INT(OSMAXALLOWEDVALUE_Counter1, (int)(alarm_base.maxallowedvalue));
	TEST_ASSERT_EQUAL_INT(OSTICKSPERBASE_Counter1, (int)(alarm_base.ticksperbase));
	TEST_ASSERT_EQUAL_INT(OSMINCYCLE_Counter1, (int)(alarm_base.mincycle));
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_5);
	
	TickType tik;
	result_inst_6 = GetAlarm(Alarm1,&tik);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_6);
	TEST_ASSERT_EQUAL_INT(OSMAXALLOWEDVALUE , tik);
	
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
