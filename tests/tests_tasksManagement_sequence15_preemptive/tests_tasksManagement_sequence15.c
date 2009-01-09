#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "../../os/tpl_os_kernel.h"
#include "tests_tasksManagement_sequence15.h"

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void ShutdownHook(StatusType error)
{
	TestRunner_end();
	UART_envoyer_chaine("Fin du test \n");
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(TaskManagementTest_seq15_t1_instance());
}

TASK(t2)
{
	TerminateTask();
}

TASK(t3)
{
	TerminateTask();
}

TASK(t4)
{
	TerminateTask();
}

TASK(t5)
{
	TerminateTask();
}

TASK(t6)
{
	TerminateTask();
}

TASK(t7)
{
	TerminateTask();
}

TASK(t8)
{
	ShutdownOS(E_OK);
}
