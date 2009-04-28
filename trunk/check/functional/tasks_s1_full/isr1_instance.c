/*Instance of interruption isr1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h" /*for INVALID_TASK*/

DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_5;
	TaskType result_inst_4;

	SCHEDULING_CHECK_INIT(13);
	result_inst_1 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OS_CALLEVEL , result_inst_1);
	
	SCHEDULING_CHECK_INIT(14)
	result_inst_2 = ChainTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OS_CALLEVEL , result_inst_2);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_3 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OS_CALLEVEL , result_inst_3);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_5 = GetTaskID(&result_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(16,INVALID_TASK , result_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OK , result_inst_5);
	
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq1_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
