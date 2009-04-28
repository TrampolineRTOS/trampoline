/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t1);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1,result_inst_3,result_inst_5,result_inst_6;
	EventMaskType result_inst_2, result_inst_4;

	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK , result_inst_1); 
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_3 = GetEvent(t1, &result_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(2,E_OK , result_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK , result_inst_3);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_5 = GetEvent(t2, &result_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(3,E_OK , result_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK , result_inst_5);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_6 = Schedule();
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK , result_inst_6);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq4_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence4",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
