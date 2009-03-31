/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Event1);
DeclareTask(t5);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;

	result_inst_1 = ActivateTask(t5);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	result_inst_2 = WaitEvent(Event1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);

	result_inst_3 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);
	
	
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq6_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
