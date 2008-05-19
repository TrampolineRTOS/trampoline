/*
 *     t0, t1 et t2 sont extended, les autres sont basic
 *
*/

#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "tc_check.h"

char* file = __FILE__;
/*
 * Define the buffers
 */
tc_buf_entry w[20] = {
    { 103,      E_OK        },
    { 6,        E_OK        },
    { 100,      E_OK        },
    { 102,      E_OK        },
    { 7,        E_OK        }
};

tc_buf_entry g[20];

tc_buf_loc l[20];


#define _XOPEN_SOURCE 500
#include <unistd.h>

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void StartupHook(void)
{
    printf("Starting task_2 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType error)
{
    tc_check(10);
}

TASK(t0)  /* Au démarage de l'OS, t0 est running */
{
    StatusType result;

/* t0, préemptive, active t3, tache basique de priorité plus grande */
    result = ActivateTask(t3);
    if (result != E_OK) tc_report_error(-100,result,file,__LINE__);
    else tc_report(100,file,__LINE__);

/* t0, préemptive, active t2, tache extended suspended, qui a une priorité plus grande.
   Test case 7 */
    result = ActivateTask(t2);
    if (result == E_OK) tc_report_error(7,result,file,__LINE__);
    else tc_report_error(-7,result,file,__LINE__);
    
/* t0 ferme l'OS */
    ShutdownOS(E_OK);
	TerminateTask();
}

TASK(t1) {
    tc_report(101,file,__LINE__);
	TerminateTask();
}

TASK(t2) {
    tc_report(102,file,__LINE__);
	TerminateTask();
}

TASK(t3) {
    StatusType result3;
    TaskStateType state3;

    tc_report(103,file,__LINE__);
    
/* t3, non préemptive, active t1, tache extended suspended.
   Test case 6 */
    result3 = ActivateTask(t1);
    GetTaskState(t1,&state3);
    if (result3 == E_OK && state3 == READY) tc_report_error(6,result3,file,__LINE__);
    else tc_report_error(-6,result3,file,__LINE__);

	TerminateTask();
}


