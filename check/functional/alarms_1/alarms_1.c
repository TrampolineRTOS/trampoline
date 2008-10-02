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
	{ 1,     E_OS_ID      },
	{ 2,     E_OK         },
	{ 3,     E_OS_ID      },
	{ 4,     E_OS_NOFUNC  },
	{ 14,    E_OK         },	
	{ 15,    E_OK         },	
	{ 5,     E_OK         },	
	{ 6,     E_OK         },	
	{ 8,     E_OS_STATE   },	
	{ 9,     E_OS_STATE   }
};

tc_buf_entry g[20];

tc_buf_loc l[20];

char CT = 19;

#define _XOPEN_SOURCE 500
#include <unistd.h>

void StartupHook(void);

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
	
    return 0;
}

void StartupHook(void)
{
    printf("Starting alarm_1 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* in the start of the OS, t0 is in running state */

    AlarmBaseType base;
	TickType tick;

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 1*/
	result = GetAlarmBase(invalid_alarm,&base);
    if (result == E_OS_ID) tc_report_error(1,result,file,__LINE__);
    else tc_report_error(-1,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 2*/
	result = GetAlarmBase(alarm1,&base);
    if (result == E_OK) tc_report_error(2,result,file,__LINE__);
    else tc_report_error(-2,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 3*/
	result = GetAlarm(invalid_alarm,&tick);
    if (result == E_OS_ID) tc_report_error(3,result,file,__LINE__);
    else tc_report_error(-3,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 4*/
	result = GetAlarm(alarm1,&tick);
    if (result == E_OS_NOFUNC) tc_report_error(4,result,file,__LINE__);
    else tc_report_error(-4,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 14*/
	result = SetRelAlarm(alarm1,100,100);
    if (result == E_OK) tc_report_error(14,result,file,__LINE__);
    else tc_report_error(-14,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 15*/
	result = SetRelAlarm(alarm2,100,100);
    if (result == E_OK) tc_report_error(15,result,file,__LINE__);
    else tc_report_error(-15,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 5*/
	result = GetAlarm(alarm1,&tick);
    if (result == E_OK) tc_report(5,file,__LINE__);
    else tc_report_error(-5,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 6*/
	result = GetAlarm(alarm2,&tick);
    if (result == E_OK) tc_report(6,file,__LINE__);
    else tc_report_error(-6,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 8*/
	result = SetRelAlarm(alarm1,100,100);
    if (result == E_OS_STATE) tc_report_error(8,result,file,__LINE__);
    else tc_report_error(-8,result,file,__LINE__);

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 9*/
	result = SetRelAlarm(alarm2,100,100);
    if (result == E_OS_STATE) tc_report_error(9,result,file,__LINE__);
    else tc_report_error(-9,result,file,__LINE__);
	
	/* t0 close the OS */
    CancelAlarm(alarm1);
    ShutdownOS(E_OK);	

}


TASK(time_error)
{	
	/* time_error close the OS */
    ShutdownOS(E_OK);	
}
