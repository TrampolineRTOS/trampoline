/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Event2);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = WaitEvent(Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_2 = ClearEvent(Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_3 = WaitEvent(Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_4 = ClearEvent(Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_5 = WaitEvent(Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_6 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_6);
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq3_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence3",NULL,NULL,fixtures);

	return (TestRef)&AlarmsTest;
}
