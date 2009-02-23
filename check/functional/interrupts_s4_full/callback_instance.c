/*Instance of callback*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_callback_instance(void)
{	
	SuspendAllInterrupts();
	
	tpl_send_it1();
	
	ResumeAllInterrupts();
	
}

/*create the test suite with all the test cases*/
TestRef InterruptsTest_seq4_callback_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_callback_instance",test_callback_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptsTest,"InterruptsTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&InterruptsTest;
}
