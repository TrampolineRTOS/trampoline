/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Event1);
DeclareTask(t3);
DeclareTask(t5);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4;
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = ActivateTask(t3);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = ActivateTask(t5);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_3 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OK, result_inst_3);

	SCHEDULING_CHECK_INIT(20);
	result_inst_4 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK, result_inst_4);
	
	
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq5_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
