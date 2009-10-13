#include "tpl_os.h"
#include "vp_ipc_devices.h"
#include "tpl_machine.h"

#include <stdio.h>

#include "../viper2/device/tpl_can_driver.h"

/* Task declaration */
DeclareTask(Idle);

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void StartupHook(void)
{
    printf("[TPL3] Ca demarre !\n");
}

void ShutdownHook(StatusType error)
{
    printf("[TPL3] Au revoir et a bientot :)\n");
}

TASK(Idle)
{	
	printf("[TPL3] Idle\n");
	TerminateTask();
}

ISR(CAN) 
{   
    
    
}