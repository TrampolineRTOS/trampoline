/*
 *     t0 preemptive basic task
 *     t1 non-preemptive extended task
 *     t2 preemptive extended task
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
	{ 100,   E_OK         },
	{ 22,    E_OS_RESOURCE},
	{ 18,    E_OK         },
	{ 25,    E_OK         },
	{ 15,    E_OS_ID      },
	{ 16,    E_OS_ACCESS  },
	{ 17,    E_OS_STATE   },
	{ 101,   E_OK         },
	{ 7,     E_OK         },	
	{ 26,    E_OK         }
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
    printf("Starting event_2 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* in the start of the OS, t0 is in running state */

	ActivateTask(t1);

/* t0, Call GetEvent() with invalid Task ID
    Test case 15 */
	result = GetEvent(invalidtaskid,EV1);
    if (result == E_OS_ID) tc_report_error(15,result,file,__LINE__);
    else tc_report_error(-15,result,file,__LINE__);
	
/* t0, Call GetEvent() for basic task
    Test case 16 */
	result = GetEvent(t0,EV1);
    if (result == E_OS_ACCESS) tc_report_error(16,result,file,__LINE__);
    else tc_report_error(-16,result,file,__LINE__);

/* t0, Call GetEvent() for suspended extended task
    Test case 17 */
	result = GetEvent(t2,EV1);
    if (result == E_OS_STATE) tc_report_error(17,result,file,__LINE__);
    else tc_report_error(-17,result,file,__LINE__);

	ActivateTask(t2);

	

}

TASK(t1) {
	tc_report(100,file,__LINE__);
	GetResource(res);

/* t1, Call WaitEvent() from extended task which occupies a resource
    Test case 22 */
	result = WaitEvent(EV1);
    if (result == E_OS_RESOURCE) tc_report_error(22,result,file,__LINE__);
    else tc_report_error(-22,result,file,__LINE__);

	ReleaseResource(res);
	
/* t1, Call GetEvent() for running extended task
    Test case 18 */
	result = GetEvent(t1, EV1);
    if (result == E_OK) tc_report(18,file,__LINE__);
    else tc_report_error(-18,result,file,__LINE__);

    SetEvent(t1, EV1);
    
/* t1, Call WaitEvent() from extended task. None of the events 
waited for is set
    Test case 25 */
	result = WaitEvent(EV1);
    if (result == E_OK) tc_report(25,file,__LINE__);
    else tc_report_error(-25,result,file,__LINE__);

	ClearEvent(EV1);

/* t1, Call WaitEvent() from extended task. None of the events 
waited for isn't set
    Test case 26 */
	result = WaitEvent(EV1);
    if (result == E_OK) tc_report(26,file,__LINE__);
    else tc_report_error(-26,result,file,__LINE__);

	tc_check(10);
	/* t1 close the OS */
    ShutdownOS(E_OK);

}





TASK(t2) {

	tc_report(101,file,__LINE__);

/* t2, Call SetEvent() from preemptive task on waiting extended
task which is waiting for at least one of the requested events and has
lower priority than running task
    Test case 7 */
	result = SetEvent(t1,EV1);
    if (result == E_OK) tc_report(7,file,__LINE__);
    else tc_report_error(-7,result,file,__LINE__);

	TerminateTask();
}

TASK(time_error)
{	
	tc_check(10);
	/* time_error close the OS */
    ShutdownOS(E_OK);	
}
