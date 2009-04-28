/*Instance of interruption isr1*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it2(void);
void tpl_send_it3(void);

/*test case:test the reaction of the system called with 
an activation of a isr*/
static void test_isr1_instance(void)
{
	SCHEDULING_CHECK_STEP(12);
	
	EnableAllInterrupts();
	DisableAllInterrupts();
	DisableAllInterrupts();
	DisableAllInterrupts();
	tpl_send_it2();
	tpl_send_it2();
	tpl_send_it2();
	
	EnableAllInterrupts();
	
	SCHEDULING_CHECK_STEP(14);
	
	tpl_send_it2();
	
	SCHEDULING_CHECK_STEP(16);
	
	SuspendAllInterrupts();
	ResumeAllInterrupts();
	SuspendAllInterrupts();
	SuspendAllInterrupts();
	SuspendAllInterrupts();
	tpl_send_it2();
	
	ResumeAllInterrupts();
	ResumeAllInterrupts();
	ResumeAllInterrupts();
	
	SCHEDULING_CHECK_STEP(18);
	
	tpl_send_it2();
	
	SCHEDULING_CHECK_STEP(20);
	
	SuspendOSInterrupts();
	ResumeOSInterrupts();
	SuspendOSInterrupts();
	SuspendOSInterrupts();
	SuspendOSInterrupts();
	tpl_send_it2();
	
	ResumeOSInterrupts();
	ResumeOSInterrupts();
	ResumeOSInterrupts();
	
	SCHEDULING_CHECK_STEP(22);
	
	tpl_send_it3();
	
	SCHEDULING_CHECK_STEP(26);
	
	
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
