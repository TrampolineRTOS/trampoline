#include "../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include <stdio.h>

#define WORKSTATION __APPLE__ || __linux__
#ifndef WORKSTATION 

#include <C167CS.H>

sbit LED=P8^0;
sbit LED1=P8^1;

#else

#define _XOPEN_SOURCE 500
#include <unistd.h>

#endif

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

#ifndef WORKSTATION 

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

#else
/* Workstation */

TASK(titi)
{
    printf("titi\n");
    ActivateTask(toto);
    TerminateTask();
}

TASK(toto)
{
    static int compte = 0;
    int i;
    
    compte++;
    printf("toto\n");
    fflush(stdout);
    for (i=0; i<10000000; i++);
    ActivateTask(tata);
	printf("toto2\n");
	fflush(stdout);
    if (compte < 30) {
        ChainTask(toto);
    }
    else {
        ShutdownOS(E_OK);
    }
}

TASK(tata)
{
    printf("tata\n");
    TerminateTask();
}

ISR2(it_trap30) {
    printf("catch\n");
    TerminateISR2();
}

#endif

