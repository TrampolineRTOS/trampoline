/*Instance of interruption isr1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareResource(Resource1);
DeclareResource(ResourceA);

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_isr1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5,  result_inst_6;
	
	result_inst_1 = GetResource(Resource1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	result_inst_2 = ReleaseResource(Resource1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	result_inst_3 = GetResource(ResourceA);
	TEST_ASSERT_EQUAL_INT(E_OS_ACCESS, result_inst_3);

	result_inst_4 = GetResource(RES_SCHEDULER);
	TEST_ASSERT_EQUAL_INT(E_OS_ACCESS, result_inst_4);
	
	result_inst_5 = ReleaseResource(Resource1);
	TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC, result_inst_5);
	
	result_inst_6 = ReleaseResource(RES_SCHEDULER);
	TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC, result_inst_6);
}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq1_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence1",NULL,NULL,fixtures);

	return (TestRef)&ResourceManagementTest;
}
