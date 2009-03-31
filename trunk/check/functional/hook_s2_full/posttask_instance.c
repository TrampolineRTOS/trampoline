/*Instance of posttask hook routine*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h"; /*for INVALID_TASK*/
#include "config.h" /*Display information n the right way (printf on UNIX...)*/
#include "tpl_os_generated_configuration.h"; /*for OSMAXALLOWEDVALUE_Counter1...*/

DeclareTask(t1);
DeclareAlarm(Alarm1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_posttask_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	TaskType task_id;
	TaskStateType task_state;
	EventMaskType event_mask;
	AlarmBaseType alarm_base;
	TickType tik;

	result_inst_1 = GetActiveApplicationMode();
	TEST_ASSERT_EQUAL_INT(OSDEFAULTAPPMODE , result_inst_1); 
	
	result_inst_2 = GetTaskID(&task_id);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2); 
	
	result_inst_3 = GetTaskState(task_id, &task_state);
	/* When a task is finishing, Task_state should be RUNNING.
	 Here, Task_state is not equal to RUNNING. When tpl_schedule_from_dying() is called,
	 task_state is equal to DYING (0x7) and when gettaskstate() is called, it returns
	 DYING && 0x3 = 0x3 which is equal to WAITING.
	 -> Maybe we have to change DYING from 0x7 to 0x6.
	 */
	
	result_inst_4 = GetEvent(task_id,&event_mask);
	
	result_inst_5 = GetAlarmBase(Alarm1, &alarm_base);
	TEST_ASSERT_EQUAL_INT(OSMAXALLOWEDVALUE_Counter1, (int)(alarm_base.maxallowedvalue));
	TEST_ASSERT_EQUAL_INT(OSTICKSPERBASE_Counter1, (int)(alarm_base.ticksperbase));
	TEST_ASSERT_EQUAL_INT(OSMINCYCLE_Counter1, (int)(alarm_base.mincycle));
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_5);
	
	result_inst_6 = GetAlarm(Alarm1,&tik);

	/*stdimpl_print("POSTTASKHOOK - task : %d - state : %d - getevent : %d - getalarm : %d - tick : %d\n",task_id,task_state,result_inst_6,event_mask,tik);
	*/
	
	if(task_id == INVALID_TASK)
	{
		TEST_ASSERT_EQUAL_INT(E_OS_ID , result_inst_3);
		TEST_ASSERT_EQUAL_INT(E_OS_ID , result_inst_4);
		TEST_ASSERT_EQUAL_INT(INVALID_TASK , task_id); 
	}
	else if(task_id == t1)
	{
		TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3);
		TEST_ASSERT_EQUAL_INT(E_OK , result_inst_4);
		TEST_ASSERT_EQUAL_INT(t1 , task_id);
		
		/* After resolving task_state ****
			On task_state :
				if equal to WAITING -> GetAlarm equal E_OK (t1 is waiting for an event just after setting the alarm)
				if equal to RUNNING -> GetAlarm equal E_OS_FUNC (when t1 is dying (after t1 received Event1), the alarm doesn't exist anymore)
		
			TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC , result_inst_6);
		*/
	}
	else
	{
		stdimpl_print("posttask Instance error");
	}
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_posttask_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_posttask_instance",test_posttask_instance)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
