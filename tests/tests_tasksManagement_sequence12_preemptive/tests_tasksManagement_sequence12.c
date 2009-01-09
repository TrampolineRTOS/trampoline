#include <../embUnit/embUnit.h>
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "../../os/tpl_os_kernel.h"
#include "tests_tasksManagement_sequence12.h"

unsigned char instance_t3=0;

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
	TestRunner_runTest(TaskManagementTest_seq12_t1_instance());
}

TASK(t2)
{
	TerminateTask();
}

TASK(t3)
{
	instance_t3 ++;
	if(instance_t3 == 3) { ShutdownOS(E_OK); }
	else { TerminateTask(); }
}
