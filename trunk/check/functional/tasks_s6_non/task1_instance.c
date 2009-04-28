/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);
DeclareEvent(Event2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1,result_inst_2,result_inst_4,result_inst_5,result_inst_6,result_inst_7,result_inst_8;
	TaskStateType result_inst_3;

	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK , result_inst_2); 
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_4 = GetTaskState(t2,&result_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(6,WAITING , result_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_5 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OS_LIMIT , result_inst_5);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_6 = ChainTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OS_LIMIT , result_inst_6);	
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_7= SetEvent(t2,Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK , result_inst_7);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_8 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK , result_inst_8); 
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq6_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence6",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
