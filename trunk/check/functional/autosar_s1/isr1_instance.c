/*Instance of task isr1*/

#include "embUnit.h"
#include "Os.h"
#include "tpl_as_isr.h"

DeclareISR(isr1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_isr1_instance(void)
{
	ISRType result_inst_1;
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_1 = GetISRID();
	SCHEDULING_CHECK_AND_EQUAL_INT(4,isr1 , result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarTest_seq1_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTest,"AutosarTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTest;
}
