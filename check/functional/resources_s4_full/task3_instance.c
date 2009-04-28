/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t3_instance(void)
{	
	StatusType result_inst;
	
	SCHEDULING_CHECK_INIT(5);
	result_inst = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst); 

}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq4_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence4",NULL,NULL,fixtures);

	return (TestRef)&ResourceManagementTest;
}
