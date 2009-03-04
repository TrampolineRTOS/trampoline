/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	int result_inst_1;
	
	result_inst_1 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK , result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq4_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence4",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
