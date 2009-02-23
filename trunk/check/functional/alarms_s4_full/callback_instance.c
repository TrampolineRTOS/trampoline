/*Instance of callback*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_callback_instance(void)
{
	int result_inst_1;
	
	result_inst_1 = ActivateTask(t2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq4_callback_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_callback_instance",test_callback_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&AlarmsTest;
}
