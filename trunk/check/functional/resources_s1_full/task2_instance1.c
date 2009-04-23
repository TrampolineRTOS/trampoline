/*Instance 1 of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareResource(Resource2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance1(void)
{
	
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_1 = GetResource(Resource2);
	SCHEDULING_CHECK_AND_EQUAL_INT(19 , E_OS_ACCESS, result_inst_1);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(20 , E_OK, result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq1_t2_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance1",test_t2_instance1)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&ResourceManagementTest;
}
