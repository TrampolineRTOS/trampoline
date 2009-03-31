/*Instance of callback1*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_callback1_instance(void)
{	
	SuspendAllInterrupts();
	ResumeAllInterrupts();
	tpl_send_it1();
}

/*create the test suite with all the test cases*/
TestRef InterruptsTest_seq4_callback1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_callback1_instance",test_callback1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptsTest,"InterruptsTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&InterruptsTest;
}
