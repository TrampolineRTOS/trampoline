/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t1);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4;
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_1 = ActivateTask(t1);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_LIMIT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_2 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OS_LIMIT, result_inst_2);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_3 = ChainTask(t1);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OS_LIMIT, result_inst_3);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_4 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_4);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq1_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence1",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
