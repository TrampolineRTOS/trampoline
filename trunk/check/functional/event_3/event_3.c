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
/*
 * Define the buffers
 */
tc_buf_entry w[20] = {
	{ 19,    E_OK         },
	{ 100,   E_OK         },
	{ 21,    E_OS_ACCESS  },
	{ 11,    E_OS_ACCESS  },
	{ 20,    E_OK         },
	{ 9,     E_OK         },	
	{ 10,    E_OK         }
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
    printf("Starting event_3 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* in the start of the OS, t0 is in running state */

	ActivateTask(t1);

	ActivateTask(t2);

	WaitEvent(EV1);

	ActivateTask(t3);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 10 */
	result = SetEvent(t3,EV1);
    if (result == E_OK) tc_report(10,file,__LINE__);
    else tc_report_error(-10,result,file,__LINE__);
	
	tc_check(10);
	/* t0 close the OS */
    ShutdownOS(E_OK);	

}

TASK(t1) {

/* t1, Call GetEvent() for ready (then waiting) extended task
    Test case 19 and 20 */
	result = GetEvent(t0,EV1);
    if (result == E_OK) tc_report(CT,file,__LINE__);
    else tc_report_error(-CT,result,file,__LINE__);

	CT ++;

	if(CT==21)
		{
	SetEvent(t0,EV1);
/* t1, Call SetEvent() from nonpreemptive task on ready extended task
    Test case 9 */
	result = SetEvent(t0,EV1);
    if (result == E_OK) tc_report(9,file,__LINE__);
    else tc_report_error(-9,result,file,__LINE__);

		}
	TerminateTask();

}


TASK(t2) {

	tc_report(100,file,__LINE__);

/* t1, Call WaitEvent() from basic task
    Test case 21 */
	result = WaitEvent(EV1);
    if (result == E_OS_ACCESS) tc_report_error(21,result,file,__LINE__);
    else tc_report_error(-21,result,file,__LINE__);

/* t1, Call ClearEvent() from basic task
    Test case 11 */
	result = ClearEvent(EV1);
    if (result == E_OS_ACCESS) tc_report_error(11,result,file,__LINE__);
    else tc_report_error(-11,result,file,__LINE__);

	ActivateTask(t1);


	TerminateTask();
}


TASK(t3) {}


TASK(time_error)
{	
	tc_check(10);
	/* time_error close the OS */
    ShutdownOS(E_OK);	
}
