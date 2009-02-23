/*Instance of task t5*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t5_instance(void)
{
	int result_inst_1;
	
	result_inst_1 = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq6_t5_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t5_instance",test_t5_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
