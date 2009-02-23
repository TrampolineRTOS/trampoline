/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h" /*Display information in the right way (printf on UNIX...)*/

DeclareTask(t3);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	
	int result_inst_1;
	
	result_inst_1 = ActivateTask(t3);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq8_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence8",NULL,NULL,fixtures);

	return (TestRef)&AlarmsTest;
}
