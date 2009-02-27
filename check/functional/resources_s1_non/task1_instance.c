/*Instance of task t1*/

//#include "test_instances.h"
#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_rez_kernel.h" /*for INVALID_RESOURCE*/

DeclareResource(Resource1);
DeclareResource(Resource2);
DeclareResource(Resource3);
DeclareResource(Resource4);
DeclareResource(Resource5);
DeclareResource(Resource6);
DeclareResource(ResourceA);
DeclareTask(t2);

void tpl_send_it2(void);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	
	int result_inst_1, result_inst_1_5, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17, result_inst_18, result_inst_19;
	
	EnableAllInterrupts();
	
	result_inst_1 = GetResource(ResourceA);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	result_inst_1_5 = ReleaseResource(ResourceA);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1_5);
	
	result_inst_2 = GetResource(INVALID_RESOURCE);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_2);
	
	result_inst_3 = GetResource(Resource1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);
	
	result_inst_4 = GetResource(Resource2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_4);
	
	result_inst_5 = GetResource(Resource3);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_5);
	
	result_inst_6 = GetResource(Resource4);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_6);
	
	result_inst_7 = GetResource(Resource5);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_7);
	
	result_inst_8 = GetResource(Resource6);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_8);
	
	result_inst_9 = ReleaseResource(Resource6);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_9);

	result_inst_10 = ReleaseResource(Resource5);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_10);
	
	result_inst_11 = ReleaseResource(Resource4);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_11);
	
	result_inst_12 = ReleaseResource(Resource3);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_12);
	
	result_inst_13 = ReleaseResource(Resource2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_13);
	
	result_inst_14 = ReleaseResource(Resource1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_14);
	
	//trigger interrupt ISR2
	tpl_send_it2();
	
	result_inst_15 = ReleaseResource(Resource1);
	TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC, result_inst_15);

	result_inst_16 = ReleaseResource(RES_SCHEDULER);
	TEST_ASSERT_EQUAL_INT(E_OS_NOFUNC, result_inst_16);
	
	result_inst_17 = ReleaseResource(INVALID_RESOURCE);
	TEST_ASSERT_EQUAL_INT(E_OS_ID, result_inst_17);
	
	result_inst_18 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_18);
	
	result_inst_19 = Schedule();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_19);
	
	
}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence1",NULL,NULL,fixtures);

	return (TestRef)&ResourceManagementTest;
}
