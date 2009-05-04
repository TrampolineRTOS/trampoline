/*Instance of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareTask(t2);
DeclareApplication(app);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetApplicationID();	
	SCHEDULING_CHECK_AND_EQUAL_INT(1,app, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = ActivateTask(t2);	
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef AutosarTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTest,"AutosarTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTest;
}
