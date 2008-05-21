/*
 *     t2 is extended, another are basic
 *
*/

#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "tc_check.h"

char* file = __FILE__;

#define invalidtaskid 1000
/*
 * Define the buffers
 */
tc_buf_entry w[20] = {
    { 17,     E_OK         },
    { 23,     E_OK         },
    { 18,     E_OK         },
    { 102,    E_OK         },
    { 19,     E_OS_LIMIT   },
	{ 33,     E_OS_LIMIT   },
	{ 103,    E_OK		   }			 
};

tc_buf_entry g[20];

tc_buf_loc l[20];


#define _XOPEN_SOURCE 500
//#include <unistd.h>

void StartupHook(void);

int main(void)
{
	StartupHook();
    StartOS(OSDEFAULTAPPMODE);
	
    return 0;
}

void StartupHook(void)
{
    printf("Starting task_3 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;

TASK(t0)  /* in the start of the OS, t0 is in running state */
{

/* t0, Call ActivateTask() from non-preemptive task on running basic task
which has not reached max. number of activations
    Test case 17 */
    result = ActivateTask(t0);
    if (result != E_OK) tc_report_error(-17,result,file,__LINE__);
    else tc_report(17,file,__LINE__);


	ActivateTask(t1);

/* Call TerminateTask()
    Test case 23 */
	TerminateTask();
}

TASK(t1) {

    tc_report(23,file,__LINE__);
	
/* t1, Call ActivateTask() from preemptive task on running basic task
which has not reached max. number of activations
    Test case 18 */
    result = ActivateTask(t1);
    if (result == E_OK) tc_report(18,file,__LINE__);
    else tc_report_error(-18,result,file,__LINE__);

	ActivateTask(t2);

/* t1, Call ActivateTask() on waiting extended task and has reached
max. number of activations
    Test case 19 */
    result = ActivateTask(t2);
    if (result == E_OS_LIMIT) tc_report_error(19,result,file,__LINE__);
    else tc_report_error(-19,result,file,__LINE__);

/* t1, Call ChainTask() on waiting extended task
    Test case 33 */
    result = ChainTask(t2);
    if (result == E_OS_LIMIT) tc_report_error(33,result,file,__LINE__);
    else tc_report_error(-33,result,file,__LINE__);
	
	SetEvent(t2,EV1);
	
	TerminateTask();
}

TASK(t2) {

    tc_report(102,file,__LINE__);

	WaitEvent(EV1);

	tc_report(103,file,__LINE__);

	tc_check(10);
	/* t3 close the OS */
    ShutdownOS(E_OK);
}


TASK(time_error)
{	
	tc_check(10);
	/* time_error close the OS */
    ShutdownOS(E_OK);	
}
