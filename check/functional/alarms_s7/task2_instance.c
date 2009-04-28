/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_1 = ClearEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_2 = WaitEvent(Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq7_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence7",NULL,NULL,fixtures);

	return (TestRef)&AlarmsTest;
}
