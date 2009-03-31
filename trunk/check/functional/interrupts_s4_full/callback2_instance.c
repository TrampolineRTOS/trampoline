/*Instance of callback2*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it1(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_callback2_instance(void)
{	
	SuspendAllInterrupts();
	SuspendAllInterrupts();
	SuspendAllInterrupts();
	tpl_send_it1();
	ResumeAllInterrupts();
	ResumeAllInterrupts();
	ResumeAllInterrupts();
}

/*create the test suite with all the test cases*/
TestRef InterruptsTest_seq4_callback2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_callback2_instance",test_callback2_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptsTest,"InterruptsTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&InterruptsTest;
}
