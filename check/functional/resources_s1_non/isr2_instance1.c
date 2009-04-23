/*Instance 1 of interruption isr2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareResource(ResourceA);

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr2_instance1(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_1 = GetResource(ResourceA);
	SCHEDULING_CHECK_AND_EQUAL_INT(18 , E_OS_ACCESS, result_inst_1);
}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq1_isr2_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr2_instance1",test_isr2_instance1)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&ResourceManagementTest;
}
