/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst;
	
	SCHEDULING_CHECK_INIT(4);
	result_inst = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK , result_inst); 
	
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq2_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
