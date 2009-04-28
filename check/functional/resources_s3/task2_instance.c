/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst;
	
	SCHEDULING_CHECK_INIT(6);
	result_inst = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst); 

}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq3_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence3",NULL,NULL,fixtures);

	return (TestRef)&ResourceManagementTest;
}
