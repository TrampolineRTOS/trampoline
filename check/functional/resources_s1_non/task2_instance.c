/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareResource(Resource2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	
	StatusType result_inst_1, result_inst_2;
	
	result_inst_1 = GetResource(Resource2);
	TEST_ASSERT_EQUAL_INT(E_OS_ACCESS, result_inst_1);
	
	result_inst_2 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq1_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&ResourceManagementTest;
}
