#include "../embUnit/embUnit.h"
#include "../../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "../../os/tpl_os_kernel.h"
#include "tests_tasksManagement_sequence7.h"

unsigned char instance_t1=0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{
	TestRunner_end();
	UART_envoyer_chaine("Fin des 2 tests \n");
}

TASK(t1)
{
	instance_t1 ++;
	switch(instance_t1)
	{ 
		case 1:	
		{
			TestRunner_start();
			TestRunner_runTest(TaskManagementTest_seq7_t1_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(TaskManagementTest_seq7_t1_instance2());
			break;
		}
		case 3:
		{
			ShutdownOS(E_OK);
			break;
		}
		default:
		{
			UART_envoyer_chaine("Instance error \n");
			break;
		}
	}
}

TASK(t2)
{
	TerminateTask();
}

TASK(t3)
{
	TerminateTask();
}
