/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst;
	
	result_inst = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst); 

}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq3_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence3",NULL,NULL,fixtures);

	return (TestRef)&ResourceManagementTest;
}
