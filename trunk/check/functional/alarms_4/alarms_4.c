/*
 *     t0, t1 and t3 are extended, another are basic
 *
*/

#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "tc_check.h"

char* file = __FILE__;

#define invalidtaskid 1000
#define invalid_alarm 100
/*
 * Define the buffers
 */
tc_buf_entry w[20] = {
	{ 25,    E_OS_ID      },
	{ 26,    E_OS_NOFUNC  },
	{ 27,    E_OK         },
	{ 28,    E_OK         },
	{ 35,    E_OK         },
	{ 29,    E_OK         }
};

tc_buf_entry g[20];

tc_buf_loc l[20];

char CT = 19;

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
    printf("Starting alarm_4 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* in the start of the OS, t0 is in running state */

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 25*/
	result = CancelAlarm(invalid_alarm);
    if (result == E_OS_ID) tc_report_error(25,result,file,__LINE__);
    else tc_report_error(-25,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 26*/
	result = CancelAlarm(alarm1);
    if (result == E_OS_NOFUNC) tc_report_error(26,result,file,__LINE__);
    else tc_report_error(-26,result,file,__LINE__);

	SetAbsAlarm(alarm1,100,100);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 27*/
	result = CancelAlarm(alarm1);
    if (result == E_OK) tc_report(27,file,__LINE__);
    else tc_report_error(-27,result,file,__LINE__);


	SetAbsAlarm(alarm2,100,100);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 28*/
	result = CancelAlarm(alarm2);
    if (result == E_OK) tc_report(28,file,__LINE__);
    else tc_report_error(-28,result,file,__LINE__);
	
	SetRelAlarm(alarm2,10,10);
	WaitEvent(EV1);

	tc_report(35,file,__LINE__);
	CancelAlarm(alarm2);	
	SetRelAlarm(alarm1,10,10);
	TerminateTask();
}

TASK(t1) {

tc_report(29,file,__LINE__);
	
	tc_check(10);
	/* t0 close the OS */
    ShutdownOS(E_OK);
}



TASK(time_error)
{	
	tc_check(10);
	/* time_error close the OS */
    ShutdownOS(E_OK);	
}
