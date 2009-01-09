#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "../../os/tpl_os_kernel.h"
#include "tests_tasksManagement_sequence4.h"

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
	TestRunner_runTest(TaskManagementTest_seq4_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TerminateTask();
}
