/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1;

	tpl_send_it1();
	
	result_inst_1 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1); 
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq16_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence16",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
