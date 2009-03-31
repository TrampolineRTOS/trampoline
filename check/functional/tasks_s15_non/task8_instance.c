/*Instance of task t8*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t8_instance(void)
{
	StatusType result_inst_1, result_inst_2;
	
	result_inst_1 = WaitEvent(Event1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	result_inst_2 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq16_t8_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t8_instance",test_t8_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence16",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
