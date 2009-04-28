/*Instance of task t3*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareEvent(Event3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_1 = WaitEvent(Event3);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OK, result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq3_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
