/*
 *     t0, t1 and t3 are extended, another are basic
 *
*/

#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "tpl_os_kernel.h"
#include "tc_check.h"

char* file = __FILE__;

#define invalidtaskid 1000
#define invalid_alarm 100
/*
 * Define the buffers
 */
tc_buf_entry w[20] = {
	{ 30,    E_OK         }
};

tc_buf_entry g[20];

tc_buf_loc l[20];

char Expire = 0;

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
    printf("Starting alarm_5 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* in the start of the OS, t0 is in running state */
   	
    while (tpl_task_table[t1]->exec_desc.activate_count==0);
    tc_report(30,file,__LINE__);

    TerminateTask();

/* t0, Call SetEvent() from preemptive task on ready extended task
    Test case 28*/
	result = CancelAlarm(alarm2);
    if (result == E_OK) tc_report(28,file,__LINE__);
    else tc_report_error(-28,result,file,__LINE__);

	
}

TASK(t1) {
tc_check(10);
/* time_error close the OS */
ShutdownOS(E_OK);

}

void func (void)
{
	Expire = 1;
}

TASK(time_error)
{	
	tc_check(10);
	/* time_error close the OS */
    ShutdownOS(E_OK);	
}
