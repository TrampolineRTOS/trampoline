#include "tpl_os.h"
#include "vp_ipc_devices.h"
#include "tpl_machine.h"

#include <stdio.h>

#include "../viper2/device/tpl_can_driver.h"

/* Variables Initialisation */
char direction = 0;
tpl_sending_ipdu s_ipdu;

/* Task declaration */
DeclareTask(SendButtons);
DeclareResource(ResourceVector);

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void StartupHook(void)
{
    printf("[TPL_PC] Ca demarre !\n");
}

void ShutdownHook(StatusType error)
{
    printf("[TPL_PC] Au revoir et a bientot :)\n");
}

TASK(SendButtons)
{
    /* SendVector to CAN */
    s_ipdu.id = 0;
    s_ipdu.transmission_mode = 0;
    s_ipdu.nb_message = 2;
    
    unsigned char test[1]; // = "message";
    
	GetResource(ResourceVector);
    test[0] = direction;
	ReleaseResource(ResourceVector);
    
    s_ipdu.buf = test;
    
    /* send ipdu */
    printf("[TPL_PC] Send an I-PDU... id:%d - mode:%d - buf:%d\n", s_ipdu.id,s_ipdu.transmission_mode,s_ipdu.buf[0]);
    send_ipdu(&viper, &global_shared_memory, NET0, &s_ipdu);

	TerminateTask();
}

ISR(BPFaster) 
{
	GetResource(ResourceVector);
	direction = 1;
	ReleaseResource(ResourceVector);
	ActivateTask(SendButtons);
}

ISR(BPSlower) 
{
	GetResource(ResourceVector);	
	direction = 2;
	ReleaseResource(ResourceVector);
	ActivateTask(SendButtons);
}

ISR(BPLeft) 
{
	GetResource(ResourceVector);
	direction = 3;
	ReleaseResource(ResourceVector);
	ActivateTask(SendButtons);
}

ISR(BPRight) 
{
	GetResource(ResourceVector);
	direction = 4;
	ReleaseResource(ResourceVector);
	ActivateTask(SendButtons);    
}
