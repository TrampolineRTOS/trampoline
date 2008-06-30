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
	{ 7,     E_OS_ID      },
	{ 10,    E_OS_VALUE   },
	{ 11,    E_OS_VALUE   },
	{ 12,    E_OS_VALUE   },
	{ 13,    E_OS_VALUE   },
	{ 16,    E_OS_ID      }
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
    printf("Starting alarm_2 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* in the start of the OS, t0 is in running state */


/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 7*/
	result = SetRelAlarm(invalid_alarm,100,100);
    if (result == E_OS_ID) tc_report_error(7,result,file,__LINE__);
    else tc_report_error(-7,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 10*/
	result = SetRelAlarm(alarm1,-1,100);
    if (result == E_OS_VALUE) tc_report_error(10,result,file,__LINE__);
    else tc_report_error(-10,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 11*/
	result = SetRelAlarm(alarm1,65534,100);
    if (result == E_OS_VALUE) tc_report_error(11,result,file,__LINE__);
    else tc_report_error(-11,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 12*/
	result = SetRelAlarm(alarm1,100,-1);
    if (result == E_OS_VALUE) tc_report_error(12,result,file,__LINE__);
    else tc_report_error(-12,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 13*/
	result = SetRelAlarm(alarm1,100,65534);
    if (result == E_OS_VALUE) tc_report_error(13,result,file,__LINE__);
    else tc_report_error(-13,result,file,__LINE__);
    

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 16*/
	result = SetAbsAlarm(invalid_alarm,100,100);
    if (result == E_OS_ID) tc_report_error(16,result,file,__LINE__);
    else tc_report_error(-16,result,file,__LINE__);
	
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
