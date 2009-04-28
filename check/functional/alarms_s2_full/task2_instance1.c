/*Instance1 of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance1(void)
{
	StatusType result_inst;

	SCHEDULING_CHECK_INIT(6);
	result_inst = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK , result_inst); 
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq2_t2_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance1",test_t2_instance1)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AlarmsTest;
}
