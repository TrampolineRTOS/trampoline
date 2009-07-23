/*Instance 2 of task t2*/

#include "embUnit.h"
#include "Os.h"

DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance2(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4;
	
	SCHEDULING_CHECK_INIT(33);
	result_inst_1 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(36,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(37);
	result_inst_2 = ClearEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(37,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(38);
	result_inst_3 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(41,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(42);
	result_inst_4 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(42,E_OK, result_inst_4);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTSTest_seq10_t2_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance2",test_t2_instance2)
	};
	EMB_UNIT_TESTCALLER(AutosarSTSTest,"AutosarSTSTest_sequence10",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTSTest;
}
