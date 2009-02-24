/*Instance of task t4*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);
DeclareEvent(Event2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t4_instance(void)
{
	int result_inst_1, result_inst_2;
	
	result_inst_1 = SetEvent(t2, Event2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1);
	
	result_inst_2 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq11_t4_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t4_instance",test_t4_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence11",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
