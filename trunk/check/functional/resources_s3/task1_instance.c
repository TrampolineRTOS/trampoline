/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h"

DeclareTask(t2);
DeclareTask(t3);
DeclareResource(Resource1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	
	StatusType result_inst_1,result_inst_2, result_inst_3, result_inst_4;
	
	result_inst_1 = GetResource(Resource1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1); 
		
	result_inst_2 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	result_inst_3 = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);
	
	result_inst_4 = ReleaseResource(Resource1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_4);

}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence3",NULL,NULL,fixtures);

	return (TestRef)&ResourceManagementTest;
}
