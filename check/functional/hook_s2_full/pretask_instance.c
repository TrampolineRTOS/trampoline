/*Instance of pretask hook routine*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h" /*Display information n the right way (printf on UNIX...)*/
#include "tpl_os_kernel.h"; //for INVALID_TASK
#include "tpl_os_generated_configuration.h"; //for OSMAXALLOWEDVALUE_Counter1...

#define t1_id 0
#define t2_id 1

DeclareAlarm(Alarm1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_pretask_instance(void)
{
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	
	result_inst_1 = GetActiveApplicationMode();
	TEST_ASSERT_EQUAL_INT(OSDEFAULTAPPMODE , result_inst_1); 
	
	TaskType task_id;
	result_inst_2 = GetTaskID(&task_id);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2); 
	
	TaskStateType task_state;
	result_inst_3 = GetTaskState(task_id, &task_state);
	
	EventMaskType event_mask;
	result_inst_4 = GetEvent(task_id,&event_mask);
	
	AlarmBaseType alarm_base;
	result_inst_5 = GetAlarmBase(Alarm1, &alarm_base);
	TEST_ASSERT_EQUAL_INT(OSMAXALLOWEDVALUE_Counter1, (int)(alarm_base.maxallowedvalue));
	TEST_ASSERT_EQUAL_INT(OSTICKSPERBASE_Counter1, (int)(alarm_base.ticksperbase));
	TEST_ASSERT_EQUAL_INT(OSMINCYCLE_Counter1, (int)(alarm_base.mincycle));
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_5);
	
	TickType tik;
	result_inst_6 = GetAlarm(Alarm1,&tik);
	
	//stdimpl_print("PRETASKHOOK - task : %d - state : %d - getevent : %d - getalarm : %d - tick : %d\n",task_id,task_state,result_inst_6,event_mask,tik);
		
	if(task_id == INVALID_TASK){
		TEST_ASSERT_EQUAL_INT(E_OS_ID , result_inst_3);
		TEST_ASSERT_EQUAL_INT(E_OS_ID , result_inst_4);
		TEST_ASSERT_EQUAL_INT(E_OK , result_inst_6);
		TEST_ASSERT_EQUAL_INT(INVALID_TASK , task_id); 
		
	}
	else if(task_id == t1_id){
		TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3);
		TEST_ASSERT_EQUAL_INT(E_OK , result_inst_4);
		TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC , result_inst_6);
		TEST_ASSERT_EQUAL_INT(0 , task_id); 
		
		TEST_ASSERT_EQUAL_INT(RUNNING , task_state);
	}
	else if(task_id == t2_id){
		TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3);
		TEST_ASSERT_EQUAL_INT(E_OS_ACCESS , result_inst_4);
		TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC , result_inst_6);
		TEST_ASSERT_EQUAL_INT(1 , task_id); 
		
		TEST_ASSERT_EQUAL_INT(RUNNING , task_state);
	}
	else {
		stdimpl_print("pretask Instance error");
	}

}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_pretask_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_pretask_instance",test_pretask_instance)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
