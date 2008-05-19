/*
 *     t0, t1, t2 et t3 sont extended,
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
	{ 32,     E_OK         },
	{ 34,     E_OK         },
	{ 39,     E_OK         },
	{ 40,     E_OS_ID      },
	{ 41,     E_OK         }
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
    printf("Starting task_5 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* Au démarage de l'OS, t0 est running */

/* t1, chaintask t3.
    Test case 32 */
	ChainTask(t1);

}

TASK(t1) {
    TaskStateType state4;
    TaskRefType id4;

	tc_report(32,file,__LINE__);

/* Schedule
    Test case 34 */
    result = Schedule();
    if (result == E_OK) tc_report(34,file,__LINE__);
    else tc_report_error(-34,result,file,__LINE__);


/* get task id
    Test case 39 */
    result = GetTaskID(id4);
    if (result == E_OK) tc_report(39,file,__LINE__);
    else tc_report_error(-39,result,file,__LINE__);

/* get task state d'un id invalid
    Test case 40 */
    result = GetTaskState(invalidtaskid,&state4);
    if (result == E_OS_ID) tc_report_error(40,result,file,__LINE__);
    else tc_report_error(-40,result,file,__LINE__);

/* get task state 
    Test case 41 */
    result = GetTaskState(t0,&state4);
    if (result == E_OK) tc_report(41,file,__LINE__);
    else tc_report_error(-41,result,file,__LINE__);

	tc_check(10);
	/* t3 ferme l'OS */
    ShutdownOS(E_OK);

}

TASK(time_error)
{	
	tc_check(10);
	/* t3 ferme l'OS */
    ShutdownOS(E_OK);	
}
