/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Event1);
DeclareTask(t1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_2 = ClearEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_3 = SetEvent(t1, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_4 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OK, result_inst_4);

	SCHEDULING_CHECK_INIT(17);
	result_inst_5 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK, result_inst_5);
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq4_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
