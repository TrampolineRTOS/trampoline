
/*Instance of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareTask(t2);

void tpl_send_it3(void);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = ActivateTask(t2);	
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_STEP(2);
	DisableAllInterrupts();
	
	/*check interrupts disabled*/
	tpl_send_it3();
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OS_DISABLEDINT , result_inst_2);

	/*check interrupts disabled*/
	tpl_send_it3();	

	SCHEDULING_CHECK_INIT(5);
	result_inst_3 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_DISABLEDINT , result_inst_3);

	/*check interrupts disabled*/
	tpl_send_it3();	
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}

