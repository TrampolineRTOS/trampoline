#include "tpl_os.h"
#include "../drivers/mss_watchdog/mss_watchdog.h"
#include "m2sxxx.h"


DeclareTask (T2);
DeclareTask (T3);
DeclareTask (T4);
DeclareTask (T5);
DeclareTask (T6);

DeclareEvent (event1);
DeclareEvent (event2);

DeclareResource(res1);

#define SYST_CVR     *(volatile uint32_t *)0xE000E018
#define SYST_CTRL    *(volatile uint32_t *)0xE000E010
#define MONITEUR0bis    *(volatile uint32_t *)0x20003000
#define MONITEUR1bis    *(volatile uint32_t *)0x20003004
#define MONITEUR2bis    *(volatile uint32_t *)0x20003008
#define MONITEUR3bis    *(volatile uint32_t *)0x2000300c
#define MONITEUR4bis    *(volatile uint32_t *)0x20003010
#define MONITEUR5bis    *(volatile uint32_t *)0x20003014
#define MONITEUR6bis    *(volatile uint32_t *)0x20003018
#define MONITEUR7bis    *(volatile uint32_t *)0x2000301c
#define MONITEUR0ter    *(volatile uint32_t *)0x20004000
#define MONITEUR1ter    *(volatile uint32_t *)0x20004004
#define MONITEUR2ter    *(volatile uint32_t *)0x20004008
#define MONITEUR3ter    *(volatile uint32_t *)0x2000400c
#define MONITEUR4ter    *(volatile uint32_t *)0x20004010
#define MONITEUR5ter    *(volatile uint32_t *)0x20004014
#define MONITEUR6ter    *(volatile uint32_t *)0x20004018
#define MONITEUR7ter    *(volatile uint32_t *)0x2000401c
/*
int *p_config_moniteur = (int *)0x5000002C;
int *moniteur1 = (int *)0x50000028;
int *moniteur2 = (int *)0x50000030;
*/

int *moniteur0 = (int *)0x50000174;
int *moniteur1 = (int *)0x50000178;
int *moniteur2 = (int *)0x5000017c;
int *moniteur3 = (int *)0x50000180;
int *moniteur4 = (int *)0x50000184;
int *moniteur5 = (int *)0x50000188;
int *moniteur6 = (int *)0x5000018c;
int *moniteur7 = (int *)0x50000190;

int cpt_cycle = 1;
int cpt_cycle_isr = 0;

int val_0_moniteur = 0;
int val_1_moniteur = 0;
int val_2_moniteur = 0;
int val_3_moniteur = 0;
int val_4_moniteur = 0;
int val_5_moniteur = 0;
int val_6_moniteur = 0;
int val_7_moniteur = 0;

int error_hook = 0;

int j = 0;
int tab_trace[120]={0};
int tab_trace2[120]={0};
int tab_trace3[120]={0};
void ErrorHook ( void )
{
	error_hook = 1;
//	HardFault_Handler();
}


/*void doSysTickIt()
{
	GPIO->GPIO_OUT = 0x4;//GPIO_2 à 1
}*/

void init_monitoring()
{
	//reset
	int i;
	//*p_config_moniteur = 1;
	GPIO->GPIO_OUT = 0x2;
	for(i=0;i<10;i++);
	GPIO->GPIO_OUT = 0;
	//GPIO->GPIO_OUT = 0x1;
	//for(i=0;i<10;i++);
	//GPIO->GPIO_OUT = 0;
	//*p_config_moniteur = 0;
}

void isr_fpga_function()
{
	GPIO->GPIO_OUT = 0x1;
	//*p_config_moniteur = 0; //Desactivation IT monitoring
	//*p_config_moniteur = 2;
	
	cpt_cycle_isr = cpt_cycle;
	val_0_moniteur = *moniteur0;
	val_1_moniteur = *moniteur1;
	val_2_moniteur = *moniteur2;
	val_3_moniteur = *moniteur3;
	val_4_moniteur = *moniteur4;
	val_5_moniteur = *moniteur5;
	val_6_moniteur = *moniteur6;
	val_7_moniteur = *moniteur7;
	MONITEUR0bis = *moniteur0;
	MONITEUR1bis= *moniteur1;
	MONITEUR2bis = *moniteur2;
	MONITEUR3bis = *moniteur3;
	MONITEUR4bis = *moniteur4;
	MONITEUR5bis = *moniteur5;
	MONITEUR6bis = *moniteur6;
	MONITEUR7bis = *moniteur7;
	MONITEUR0ter = *moniteur0;
	MONITEUR1ter = *moniteur1;
	MONITEUR2ter = *moniteur2;
	MONITEUR3ter = *moniteur3;
	MONITEUR4ter = *moniteur4;
	MONITEUR5ter = *moniteur5;
	MONITEUR6ter = *moniteur6;
	MONITEUR7ter = *moniteur7;
}

/*
void FabricIrq0_IRQHandler()//void isr_fpga_function()
{
	GPIO->GPIO_OUT = 0x1;
	// *p_config_moniteur = 0; //Desactivation IT monitoring
	// *p_config_moniteur = 2;
	moniteur = 1;
	MONITEURbis = 1;	
	cpt_cycle_isr = cpt_cycle;
	val_0_moniteur = *moniteur0;
	val_1_moniteur = *moniteur1;
	val_2_moniteur = *moniteur2;
	val_3_moniteur = *moniteur3;
	val_4_moniteur = *moniteur4;
	val_5_moniteur = *moniteur5;
	val_6_moniteur = *moniteur6;
	val_7_moniteur = *moniteur7;
	// *p_config_moniteur = 0;
	/ *NVIC_ClearPendingIRQ(FabricIrq0_IRQn);	
	GPIO->GPIO_OUT = 0x0;
	NVIC_DisableIRQ(FabricIrq0_IRQn);//On stop l'IT

}*/

void FabricIrq0_IRQ_ClearFlag()
{
	NVIC_ClearPendingIRQ(FabricIrq0_IRQn);	
	GPIO->GPIO_OUT = 0x0;
	NVIC_DisableIRQ(FabricIrq0_IRQn);//On stop l'IT
	//init_monitoring();
	
}

/*void FabricIrq2_IRQ_ClearFlag()
{
	//GPIO->GPIO_OUT = 0x0;//GPIO_2 à 0
	//NVIC_ClearPendingIRQ(FabricIrq2_IRQn);	
}*/


FUNC(int, OS_APPL_CODE) main(void)
{
	//int i;
	MONITEUR0bis = 0;
	MONITEUR1bis= 0;
	MONITEUR2bis = 0;
	MONITEUR3bis = 0;
	MONITEUR4bis = 0;
	MONITEUR5bis = 0;
	MONITEUR6bis = 0;
	MONITEUR7bis = 0;
	MONITEUR0ter = 0;
	MONITEUR1ter = 0;
	MONITEUR2ter = 0;
	MONITEUR3ter = 0;
	MONITEUR4ter = 0;
	MONITEUR5ter = 0;
	MONITEUR6ter = 0;
	MONITEUR7ter = 0;
	MSS_WD_init();
	MSS_WD_enable_timeout_irq();
	GPIO->GPIO_0_CFG = 5; //output mode. IACK
	GPIO->GPIO_1_CFG = 5; //output mode. RST
	//GPIO->GPIO_2_CFG = 5; //output mode. RESET MONITORING
	//for(i=0;i<5;i++);
	GPIO->GPIO_OUT = 0x0;
	init_monitoring();
	//*p_config_moniteur = 2; //Activation IT monitoring
	//NVIC_ClearPendingIRQ(FabricIrq0_IRQn);
	GPIO->GPIO_OUT = 0x1;
	NVIC_ClearPendingIRQ(FabricIrq0_IRQn);	
	GPIO->GPIO_OUT = 0x0;	
	NVIC_EnableIRQ (FabricIrq0_IRQn);
	//NVIC_EnableIRQ (FabricIrq2_IRQn);


	
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

#define APP_Task_T1_START_SEC_CODE
#include "tpl_memmap.h"

TASK(T1)
{
	tab_trace[j] = 1 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 1 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 1 + 100 * (cpt_cycle - 1);
	j++;
	//doSysTickIt();		// IT pour alarme 1/2
	ActivateTask(T2);
	tab_trace[j] = 4 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 4 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 4 + 100 * (cpt_cycle - 1);
	j++;
	WaitEvent(event1);
	tab_trace[j] = 5 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 5 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 5 + 100 * (cpt_cycle - 1);
	j++;
	ClearEvent(event1);
	tab_trace[j] = 6 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 6 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 6 + 100 * (cpt_cycle - 1);
	j++;
	ActivateTask(T3);
	tab_trace[j] = 7 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 7 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 7 + 100 * (cpt_cycle - 1);
	j++;
	WaitEvent(event2);
	tab_trace[j] = 18 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 18 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 18 + 100 * (cpt_cycle - 1);
	j++;
	WaitEvent(event1);
	tab_trace[j] = 20 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 20 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 20 + 100 * (cpt_cycle - 1);
	j++;
	GetResource(res1);
	tab_trace[j] = 21 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 21 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 21 + 100 * (cpt_cycle - 1);
	j++;
	ReleaseResource(res1);
	tab_trace[j] = 22 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 22 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 22 + 100 * (cpt_cycle - 1);
	j++;

	TerminateTask();
}
#define APP_Task_T1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_T2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(T2)
{
	tab_trace[j] = 2 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 2 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 2 + 100 * (cpt_cycle - 1);
	j++;
	SetEvent(T1,event1);
	tab_trace[j] = 3 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 3 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 3 + 100 * (cpt_cycle - 1);
	j++;
	TerminateTask();
}
#define APP_Task_T2_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_T3_START_SEC_CODE
#include "tpl_memmap.h"
TASK(T3)
{
	tab_trace[j] = 8 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 8 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 8 + 100 * (cpt_cycle - 1);
	j++;
	GetResource(res1);
	tab_trace[j] = 9 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 9 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 9 + 100 * (cpt_cycle - 1);
	j++;
	SetEvent(T1,event2);
	tab_trace[j] = 10 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 10 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 10 + 100 * (cpt_cycle - 1);
	j++;
	ActivateTask(T4);//doSysTickIt();		// IT pour alarme 2/2
	tab_trace[j] = 17 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 17 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 17 + 100 * (cpt_cycle - 1);
	j++;
	ReleaseResource(res1);
	tab_trace[j] = 19 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 19 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 19 + 100 * (cpt_cycle - 1);
	j++;
	SetEvent(T1,event1);
	tab_trace[j] = 23 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 23 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 23 + 100 * (cpt_cycle - 1);
	j++;
	TerminateTask();
}
#define APP_Task_T3_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_T4_START_SEC_CODE
#include "tpl_memmap.h"
TASK(T4)
{
	tab_trace[j] = 11 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 11 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 11 + 100 * (cpt_cycle - 1);
	j++;
	Schedule();
	tab_trace[j] = 12 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 12 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 12 + 100 * (cpt_cycle - 1);
	j++;
	ActivateTask(T5);
	tab_trace[j] = 13 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 13 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 13 + 100 * (cpt_cycle - 1);
	j++;
	Schedule();
	tab_trace[j] = 16 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 16 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 16 + 100 * (cpt_cycle - 1);
	j++;
	TerminateTask();
}
#define APP_Task_T4_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_T5_START_SEC_CODE
#include "tpl_memmap.h"
TASK(T5)
{
	tab_trace[j] = 14 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 14 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 14 + 100 * (cpt_cycle - 1);
	j++;
	ChainTask(T6);
}
#define APP_Task_T5_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_T6_START_SEC_CODE
#include "tpl_memmap.h"
TASK(T6)
{
	tab_trace[j] = 15 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 15 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 15 + 100 * (cpt_cycle - 1);
	j++;
	TerminateTask();
}
#define APP_Task_T6_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_Tfond_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Tfond)
{
	tab_trace[j] = 24 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 24 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 24 + 100 * (cpt_cycle - 1);
	j++;
	cpt_cycle++;
	ActivateTask(T1);
	tab_trace[j] = 24 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 24 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 24 + 100 * (cpt_cycle - 1);
	j++;
	cpt_cycle++;
	ActivateTask(T1);
	tab_trace[j] = 24 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 24 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 24 + 100 * (cpt_cycle - 1);
	j++;
	cpt_cycle++;
	ActivateTask(T1);
	tab_trace[j] = 24 + 100 * (cpt_cycle - 1);
	tab_trace2[j] = 24 + 100 * (cpt_cycle - 1);
	tab_trace3[j] = 24 + 100 * (cpt_cycle - 1);
	j++;
	TerminateTask();
}
#define APP_Task_Tfond_STOP_SEC_CODE
#include "tpl_memmap.h"



