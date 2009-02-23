/*Instance of task t5*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t5_instance(void)
{
	//
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq5_t5_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t5_instance",test_t5_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}
