#include "../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include <stdio.h>

#include <C167CS.H>

sbit LED=P8^0;
sbit LED1=P8^1;

void InitApp(void)
{
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
    printf("Avant %d\n",id);
}

void PostTaskHook(void)
{
    TaskType id;
    GetTaskID(&id);
    printf("Apres %d\n",id);
}

void StartupHook(void)
{
    printf("Ca demarre !\n");
}

void ShutdownHook(StatusType error)
{
    printf("Au revoir et a bientot :)\n");
}

ISR2(it_trap32)
{
	LED1=!LED1;
	ActivateTask(tick);
	TerminateISR2();
}

TASK(tick)
{
	LED = !LED;
    TerminateTask();
}

TASK(init)
{
	T01CON = 0x0045; /* period 840 ms. Timer 0*/ 
	T0IC = 0x0050;   /* IE=1, ILVL 4, GLVL 0  */
    TerminateTask();
}

