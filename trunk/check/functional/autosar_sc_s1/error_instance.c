/*Instance of error*/

#include "embUnit.h"
#include "Os.h"
/*#include "tpl_os_error.h" */ /*for OSErrorGetServiceId()*/

DeclareTask(t1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance(void)
{
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT(8,OSServiceId_ActivateTask , result_inst_1);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_2 = OSError_ActivateTask_TaskID();
	SCHEDULING_CHECK_AND_EQUAL_INT(9,t1 , result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarTest_seq1_error_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance",test_error_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTest,"AutosarTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTest;
}
