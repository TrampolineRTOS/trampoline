#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h";

TestRef HookTest_seq4_t1_instance(void);
TestRef HookTest_seq4_isr1_instance(void);

void tpl_send_it1(void);

int error_instance = 0;
int posttask_instance = 0;
int pretask_instance = 0;
int task1_instance = 0;

DeclareTask(t2);
DeclareTask(t1);

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void StartupHook(void)
{ 
	TestRunner_start();
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

void ErrorHook(void)
{ 
	error_instance++;
	switch (error_instance) {
		case 1: {
			//
			break;
		}
		case 2: {
			//
			break;
		}
		case 3: {
			
			break;
		}
		case 4: {
			
			break;
		}
		default: {
			
			break;
		}
	}
	
	
	
}

void PreTaskHook(void)
{ 
	pretask_instance++;
	stdimpl_print("Pretaskhook : case%d",pretask_instance);
	switch (pretask_instance) {
		case 1: {
			//
			break;
		}
		case 2: {
			//
			break;
		}
		case 3: {
			
			break;
		}
		case 4: {
			//stdimpl_print(" - ResumeAllInterrupts\n");
			//ResumeAllInterrupts();
			break;
		}
		default: {
			
			break;
		}
	}
	stdimpl_print("\n");	
	
}

void PostTaskHook(void)
{ 
	posttask_instance++;
	stdimpl_print("Posttaskhook : case%d",posttask_instance);
	switch (posttask_instance) {
		case 1: {
			stdimpl_print(" - call interrupt");
			tpl_send_it1();
			tpl_send_it1();
			tpl_send_it1();
			tpl_send_it1();
			tpl_send_it1();
			tpl_send_it1();
			break;
		}
		case 2: {
			stdimpl_print(" - SuspendAllInterrupts");
			SuspendAllInterrupts();
			stdimpl_print(" - ResumeAllInterrupts");
			ResumeAllInterrupts();
			stdimpl_print(" - call interrupt");
			tpl_send_it1();
			break;
		}
		case 3: {
			stdimpl_print(" - call interrupt");
			tpl_send_it1();			
			break;
		}
		case 4: {
			break;
		}
		default: {
			stdimpl_print(" - call interrupt");
			tpl_send_it1();
			break;
		}
	}
	stdimpl_print("\n");
}

TASK(t1)
{
	task1_instance++;
	stdimpl_print("Task1 : case%d",task1_instance);
	switch (task1_instance) {
		case 1: {
			stdimpl_print("\n");
			EnableAllInterrupts();
			ChainTask(t1);
			
			break;
		}
		case 2: {		
			stdimpl_print(" - \n");
			ChainTask(t1);
			break;
		}
		case 3: {
			stdimpl_print(" - \n");
			ChainTask(t1);
			break;
		}
		case 4: {
			stdimpl_print(" - \n");
			ChainTask(t1);
			break;
		}	
		case 5: {	
			stdimpl_print(" - \n");
			ChainTask(t1);
			break;
		}
		default: {
			stdimpl_print(" - \n");
			break;
		}
	}

	
	//TestRunner_runTest(HookTest_seq4_t1_instance());
	/*stdimpl_print("before interrupt\n");
	tpl_send_it1();
	
	stdimpl_print("Suspend interrupt from task\n");
	SuspendAllInterrupts();
	
	stdimpl_print("before interrupt\n");
	tpl_send_it1();
	tpl_send_it1();
	
	stdimpl_print("Resume interrupt from task\n");
	ResumeAllInterrupts();
	
	tpl_send_it1();
	
	stdimpl_print("before chaintask\n");
	ChainTask(t2);
*/
}


TASK(t2)
{
	stdimpl_print("before shutdownOS\n");
	ShutdownOS(E_OK);
}


ISR(isr1)
{
	stdimpl_print("**** ISR1 : case1 \n");
	//TestRunner_runTest(HookTest_seq4_isr1_instance());
}