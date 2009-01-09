#include "../embUnit/embUnit.h"
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "../../os/tpl_os_kernel.h"
#include "test_tasks.h"

TaskManagementRef taskManagementRef;

/*Assertion variables*/
int r_1,r_2,r_3;
int flag=0;



/*Application loading*/
int main(void)
{
/*	TestRunner_start();*/
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void damned(void)
{
}

void ErrorHook(StatusType error)
{
}

void PreTaskHook(void)
{
    TaskType id;
    GetTaskID(&id);
}

void PostTaskHook(void)
{
    TaskType id;
    GetTaskID(&id);
}

void StartupHook(void)
{
	 UART_envoyer_chaine("Ca demarre ! \n");
}

void ShutdownHook(StatusType error)
{
	UART_envoyer_chaine("Au revoir et a bientot :)\n");
}

/*Tasks definitions*/
TASK(periodicTask)
{

}

TASK(t1)
{
	UART_envoyer_chaine("t1:je suis t1 \n");
	r_1 = ActivateTask(t2);
	UART_envoyer_chaine("t1:2eme activation de t2 \n");
	r_2 = ActivateTask(t2);
	UART_envoyer_chaine("t1:3eme activation de t2 \n");
	r_3 = ActivateTask(t2);
	UART_envoyer_chaine("t1:fin de t1 \n");
	test();
	TerminateTask();
}

TASK(t2)
{
	UART_envoyer_chaine("t2:je suis t2 \n");
	TerminateTask();
}

TASK(t3)
{
}

/*Interruptions definitions*/
ISR2(trap_SIGUSR1) {
    TerminateISR2();
}

ISR2(trap_SIGUSR2) {
    TerminateISR2();
}


/*********************************************************/
/*function which run the tests*/
void test(void)
{
	TestRunner_start();
	TestRunner_runTest(TaskManagementTest_tests());
	TestRunner_end();
}

/*********************************************************/
/*obligatory function to allocate the object to test*/
static void setUp(void)
{
	taskManagementRef = taskManagement_alloc();
}

TaskManagementRef taskManagement_alloc(void)
{
	TaskManagementRef t_ref;
	return t_ref;
}

/*********************************************************/
/*obligatory function to desallocate the object to test*/
static void tearDown(void)
{
	taskManagement_dealloc(taskManagementRef);
}

void taskManagement_dealloc(TaskManagementRef self)
{
	/*free(self);*/
}

/*********************************************************/
/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_case1(void)
{
	/*if we expected E_OK with an activation.
	In this test, this is the true result of the test*/
	TEST_ASSERT_EQUAL_INT(E_OK,r_1);

	/*if we expected E_OS_LIMIT with an activation.
	In this test, this is the wrong result of the test*/
	/*TEST_ASSERT_EQUAL_INT(E_OS_LIMIT,r);*/
}

static void test_case2(void)
{
	TEST_ASSERT_EQUAL_INT(E_OK,r_2);
}

static void test_case3(void)
{
	TEST_ASSERT_EQUAL_INT(E_OS_LIMIT,r_3);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_tests(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_case1",test_case1),
		new_TestFixture("test_case2",test_case2),
		new_TestFixture("test_case3",test_case3)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest",setUp,tearDown,fixtures);

	return (TestRef)&TaskManagementTest;
}
