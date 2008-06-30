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
	{ 19,    E_OS_VALUE   },
	{ 20,    E_OS_VALUE   },
	{ 21,    E_OS_VALUE   },
	{ 22,    E_OS_VALUE   },
	{ 23,    E_OK         },
	{ 24,    E_OK         },
	{ 17,    E_OS_STATE   },
	{ 18,    E_OS_STATE   }
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
    printf("Starting alarm_3 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* in the start of the OS, t0 is in running state */

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 19*/
	result = SetAbsAlarm(alarm1,-1,100);
    if (result == E_OS_VALUE) tc_report_error(19,result,file,__LINE__);
    else tc_report_error(-19,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 20*/
	result = SetAbsAlarm(alarm1,65534,100);
    if (result == E_OS_VALUE) tc_report_error(20,result,file,__LINE__);
    else tc_report_error(-20,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 21*/
	result = SetAbsAlarm(alarm1,100,-1);
    if (result == E_OS_VALUE) tc_report_error(21,result,file,__LINE__);
    else tc_report_error(-21,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 22*/
	result = SetAbsAlarm(alarm1,100,65534);
    if (result == E_OS_VALUE) tc_report_error(22,result,file,__LINE__);
    else tc_report_error(-22,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 23*/
	result = SetAbsAlarm(alarm1,100,100);
    if (result == E_OK) tc_report_error(23,result,file,__LINE__);
    else tc_report_error(-23,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 24*/
	result = SetAbsAlarm(alarm2,100,100);
    if (result == E_OK) tc_report_error(24,result,file,__LINE__);
    else tc_report_error(-24,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 17*/
	result = SetAbsAlarm(alarm1,100,100);
    if (result == E_OS_STATE) tc_report_error(17,result,file,__LINE__);
    else tc_report_error(-17,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 18*/
	result = SetAbsAlarm(alarm2,100,100);
    if (result == E_OS_STATE) tc_report_error(18,result,file,__LINE__);
    else tc_report_error(-18,result,file,__LINE__);
	
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
