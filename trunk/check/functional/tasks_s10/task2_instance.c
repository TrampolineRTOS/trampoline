/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);
DeclareTask(t3);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_2,result_inst_3, result_inst_4;
	EventMaskType result_inst_1;
	
	result_inst_2 = GetEvent(t2, &result_inst_1);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
	
	result_inst_3 = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_3);
	
	result_inst_4 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_4);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq10_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence10",NULL,NULL,fixtures);

	return (TestRef)&TaskManagementTest;
}
