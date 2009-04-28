/*Instance 3 of posttask hook routine*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h"; /*for INVALID_TASK*/

DeclareAlarm(Alarm1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_posttask_instance3(void)
{
	StatusType result_inst_1, result_inst_2;
	TaskType task_id;
	TickType tik;
	
	SCHEDULING_CHECK_INIT(31);
	result_inst_1 = GetTaskID(&task_id);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(31,INVALID_TASK , task_id); 
	SCHEDULING_CHECK_AND_EQUAL_INT(31,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(32);
	result_inst_2 = GetAlarm(Alarm1,&tik);
	SCHEDULING_CHECK_AND_EQUAL_INT(33,E_OS_NOFUNC , result_inst_2);
	
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq2_posttask_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_posttask_instance3",test_posttask_instance3)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&HookTest;
}
