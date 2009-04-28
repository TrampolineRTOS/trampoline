/*Instance of task t7*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Event1);
DeclareTask(t8);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t7_instance(void)
{
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_1 = SetEvent(t8, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK , result_inst_1);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq16_t7_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t7_instance",test_t7_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence16",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
