/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h" /*Display information in the right way (printf on UNIX...)*/

DeclareEvent(Event2);
DeclareTask(t4);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	
	int result_inst_1, result_inst_2, result_inst_3, result_inst_4;
	
	result_inst_1 = WaitEvent(Event2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	result_inst_2 = ClearEvent(Event2);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
		
	result_inst_3 = ActivateTask(t4);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_3);
	
	result_inst_4 = TerminateTask();
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_4);
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq8_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence8",NULL,NULL,fixtures);

	return (TestRef)&AlarmsTest;
}
