/*Instance of task t2*/

#include "embUnit.h"
#include "Os.h"
//#include "tpl_as_isr.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1;
	
	result_inst_1 = GetISRID();
	TEST_ASSERT_EQUAL_INT(INVALID_ISR, result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarTest_seq1_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTest,"AutosarTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTest;
}
