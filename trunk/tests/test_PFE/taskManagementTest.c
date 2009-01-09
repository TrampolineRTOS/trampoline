 /* 
  * @file taskManagementTest.c
  * 
  * 
  * $Date: 2008/05/20 12:09:34 $
 * $Rev$
 * $Author: GuillaumeNuth $
 * $URL$
 */

#include <embUnit.h>
#include "taskManagement.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "../../os/os_machine/ARM7/OKI/interruption.h"
#include "tpl_os_task.h"

#include "../../os/tpl_os.h"

#define E_OS_ID 3
#define E_OK 0
#define E_OS_LIMIT 4
#define E_OS_RESOURCE 6
#define INVALID_TASK -1

#define TIMER_0 0

TaskManagementRef taskManagementRef;

/*obligatory function to allocate the object to test*/
static void setUp(void)
{
	taskManagementRef = taskManagement_alloc();
}

/*obligatory function to desallocate the object to test*/
static void tearDown(void)
{
	taskManagement_dealloc(taskManagementRef);
}

/*test case:test the reaction of the system called with an invalid task*/
static void testInvalidTask(void)
{
	EnableAllInterrupts();
	TEST_ASSERT_EQUAL_INT(E_OS_ID , ActivateTask(INVALID_TASK));
	TEST_ASSERT_EQUAL_INT(E_OS_ID, GetTaskState(INVALID_TASK,4));
	TEST_ASSERT_EQUAL_INT(E_OS_ID, ChainTask(INVALID_TASK));
}

/*test case:test the system for the task management sequence 1*/
static void testSchedule_1(void)
{
	TEST_ASSERT_EQUAL_INT(E_OK, ActivateTask(2));
	Schedule();
	TEST_ASSERT_EQUAL_INT(E_OK, ActivateTask(1));
	TEST_ASSERT_EQUAL_INT(E_OK, ActivateTask(2));
	Schedule();
}

/*test case:test the system for the task management sequence 2*/
static void testSchedule_2(void)
{
	TEST_ASSERT_EQUAL_INT(E_OS_LIMIT, ActivateTask(2));
	TEST_ASSERT_EQUAL_INT(E_OK, ActivateTask(3));
	TEST_ASSERT_EQUAL_INT(E_OK, Schedule());
	TEST_ASSERT_EQUAL_INT(E_OK, Schedule());
	
}

/*function used as an ISR*/
void explose(void){
	UART_envoyer_chaine("watchdog !!!");
}

/*test case:test the system for the IT management*/
static void testIt_1(void)
{
	int delay = 150;
	
	EnableAllInterrupts();
	Timer_set_valeur_initiale (TIMER_0, 0);
	TEST_ASSERT_EQUAL_INT(0, Timer_get_valeur(TIMER_0));
	Timer_set_valeur_finale (TIMER_0, (UInt16) delay);
	Timer_set_periode (TIMER_0, (UInt32) delay);
	Interruption_set_gestionnaire_irq (INTERRUPTION_TIMER_0,explose,NULL);
	Timer_activer_interruptions (TIMER_0);
	
	Timer_demarrer (TIMER_0);
	
	TEST_ASSERT_EQUAL_INT(delay, Timer_get_valeur(TIMER_0));
	TEST_ASSERT_EQUAL_INT(1, Timer_evenement(TIMER_0));
	TEST_ASSERT_EQUAL_INT(1, Timer_evenement(TIMER_0));
	TEST_ASSERT_EQUAL_INT(10, Timer_get_valeur(TIMER_0));
	
	/*Timer_acquitter_evenement(TIMER_0);*/
}


/*create the test suite with all the test cases*/
TestRef TaskManagementTest_tests(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("testInvalidTask",testInvalidTask),
		new_TestFixture("testSchedule_1",testSchedule_1),
		new_TestFixture("testSchedule_2",testSchedule_2),
		new_TestFixture("testIt_1",testIt_1),
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
