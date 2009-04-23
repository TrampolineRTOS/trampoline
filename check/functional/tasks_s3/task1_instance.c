/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = ActivateTask(t3);
	SCHEDULING_CHECK_AND_EQUAL_INT(4 , E_OK , result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
