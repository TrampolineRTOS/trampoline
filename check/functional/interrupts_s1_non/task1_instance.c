/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

void tpl_send_it1(void);
void tpl_send_it2(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{	
	
	SCHEDULING_CHECK_STEP(1);
	
	EnableAllInterrupts();
	DisableAllInterrupts();
	DisableAllInterrupts();
	DisableAllInterrupts();
	tpl_send_it2();
	tpl_send_it2();
	tpl_send_it2();
	
	EnableAllInterrupts();
	EnableAllInterrupts();
	EnableAllInterrupts();
	
	SCHEDULING_CHECK_STEP(3);
	
	tpl_send_it2();
	
	SCHEDULING_CHECK_STEP(5);
	
	SuspendAllInterrupts();
	ResumeAllInterrupts();
	SuspendAllInterrupts();
	SuspendAllInterrupts();
	SuspendAllInterrupts();
	tpl_send_it2();
	
	ResumeAllInterrupts();
	ResumeAllInterrupts();
	ResumeAllInterrupts();
	
	SCHEDULING_CHECK_STEP(7);
	
	tpl_send_it2();
	
	SCHEDULING_CHECK_STEP(9);	
	
	SuspendOSInterrupts();
	ResumeOSInterrupts();
	SuspendOSInterrupts();
	SuspendOSInterrupts();
	SuspendOSInterrupts();
	tpl_send_it2();
	
	ResumeOSInterrupts();
	ResumeOSInterrupts();
	ResumeOSInterrupts();
	
	SCHEDULING_CHECK_STEP(11);
	
	tpl_send_it1();
	
	SCHEDULING_CHECK_STEP(27);
	
}

/*create the test suite with all the test cases*/
TestRef InterruptProcessingTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(InterruptProcessingTest,"InterruptProcessingTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&InterruptProcessingTest;
}
