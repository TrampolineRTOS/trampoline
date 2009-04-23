/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(2 , E_OK , result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 =  TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(3 , E_OK , result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq3_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
