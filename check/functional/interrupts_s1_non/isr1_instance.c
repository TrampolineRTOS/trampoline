/*Instance of interruption isr1*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it2(void);
void tpl_send_it3(void);

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr1_instance(void)
{
	EnableAllInterrupts();
	DisableAllInterrupts();
	DisableAllInterrupts();
	DisableAllInterrupts();
	tpl_send_it2();
	tpl_send_it2();
	tpl_send_it2();
	
	EnableAllInterrupts();
	tpl_send_it2();
	
	SuspendAllInterrupts();
	ResumeAllInterrupts();
	SuspendAllInterrupts();
	SuspendAllInterrupts();
	SuspendAllInterrupts();
	tpl_send_it2();
	
	ResumeAllInterrupts();
	ResumeAllInterrupts();
	ResumeAllInterrupts();
	tpl_send_it2();
	
	SuspendOSInterrupts();
	ResumeOSInterrupts();
	SuspendOSInterrupts();
	SuspendOSInterrupts();
	SuspendOSInterrupts();
	tpl_send_it2();
	
	ResumeOSInterrupts();
	ResumeOSInterrupts();
	ResumeOSInterrupts();
	tpl_send_it3();
	
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq1_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&InterruptProcessingTest;
}
