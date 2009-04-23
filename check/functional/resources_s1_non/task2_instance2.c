/*Instance 2 of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareResource(Resource2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance2(void)
{
	
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(31);
	result_inst_1 = GetResource(Resource2);
	SCHEDULING_CHECK_AND_EQUAL_INT(31 , E_OS_ACCESS, result_inst_1);
	
	SCHEDULING_CHECK_INIT(32);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(32 , E_OK, result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq1_t2_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance2",test_t2_instance2)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&ResourceManagementTest;
}
