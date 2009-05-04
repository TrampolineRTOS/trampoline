/*Instance of task t2*/

#include "embUnit.h"
#include "Os.h"
#include "tpl_as_isr.h"

void tpl_send_it1();

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	ISRType result_inst_1;
	StatusType result_inst_2;
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_1 = GetISRID();
	SCHEDULING_CHECK_AND_EQUAL_INT(3,INVALID_ISR, result_inst_1);
	
	tpl_send_it1();
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_2);
	
	
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
