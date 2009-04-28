/*Instance of startup routine*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_startup_instance(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetActiveApplicationMode();
	SCHEDULING_CHECK_AND_EQUAL_INT(1,OSDEFAULTAPPMODE , result_inst_1); 

	ShutdownOS(E_OK);
	
}

/*create the test suite with all the test cases*/
TestRef HookTest_seq1_startup_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_startup_instance",test_startup_instance)
	};
	EMB_UNIT_TESTCALLER(HookTest,"HookTest_sequence1",NULL,NULL,fixtures);

	return (TestRef)&HookTest;
}
