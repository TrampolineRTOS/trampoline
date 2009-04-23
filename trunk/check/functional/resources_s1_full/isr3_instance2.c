/*Instance 2 of interruption isr3*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareResource(Resource1);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr3_instance2(void)
{
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(22);
	result_inst_1 = GetResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(22 , E_OS_ACCESS, result_inst_1);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_2 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(23 , E_OK, result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq1_isr3_instance2(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr3_instance2",test_isr3_instance2)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&ResourceManagementTest;
}
