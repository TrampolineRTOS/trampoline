/*Instance of task t4*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);
DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t4_instance(void)
{
	StatusType result_inst_1, result_inst_3, result_inst_4;
	TaskStateType result_inst_2;
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_1 = SetEvent(t2,Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_3 = GetTaskState(t2, &result_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(15,READY, result_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OK, result_inst_3);	
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_4 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OK, result_inst_4);
	
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq4_t4_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t4_instance",test_t4_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
