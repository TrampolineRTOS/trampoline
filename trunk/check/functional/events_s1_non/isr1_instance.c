/*Instance of interruption isr1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr1_instance(void)
{
	StatusType result_inst_1, result_inst_2;
	
	result_inst_1 = ClearEvent(Event1);
	TEST_ASSERT_EQUAL_INT(E_OS_CALLEVEL , result_inst_1);

	result_inst_2 = WaitEvent(Event1);
	TEST_ASSERT_EQUAL_INT(E_OS_CALLEVEL , result_inst_2);

}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq1_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
