/*
 *     t0, t1, t2 et t3 sont extended,
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
    { 6,      E_OK        },
    { 101,    E_OK        },
    { 102,    E_OK        },
    { 8,      E_OK        },
    { 7,      E_OK        },
	{ 103,    E_OK        },
	{ 9,      E_OK        },				
	{ 11,     E_OS_LIMIT  },
	{ 16,     E_OS_LIMIT  }
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
    printf("Starting task_2 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

TASK(t0)  /* Au d√©marage de l'OS, t0 est running */
{
    StatusType result;

/* t0, non pr√©emptive, active t1, tache extended.
	Test case 6 */
    result = ActivateTask(t1);
    if (result != E_OK) tc_report_error(-6,result,file,__LINE__);
    else tc_report(6,file,__LINE__);

	TerminateTask();
}

TASK(t1) {

	StatusType result1;

    tc_report(101,file,__LINE__);
	
/* t1, pr√©emptive, active t2, tache extended suspended, qui a une priorit√© plus grande.
    Test case 7 */
    result1 = ActivateTask(t2);
    if (result1 == E_OK) tc_report_error(7,result1,file,__LINE__);
    else tc_report_error(-7,result1,file,__LINE__);

	
	TerminateTask();
}

TASK(t2) {
	StatusType result2;
    TaskStateType state2;

    tc_report(102,file,__LINE__);

/* t2, pr√©emptive, active t3, tache extended suspended, qui a une priorit√© plus petite.
    Test case 8 */
    result2 = ActivateTask(t3);
	GetTaskState(t3,&state2);
    if (result2 == E_OK && state2 == READY) tc_report_error(8,result2,file,__LINE__);
    else tc_report_error(-8,result2,file,__LINE__);


	TerminateTask();
}

TASK(t3) {
    StatusType result3;
    TaskStateType state3;

    tc_report(103,file,__LINE__);
    
/* t3, pr√©emptive, active t1, tache extended suspended de mÍme prioritÈ.
    Test case 9 */
    result3 = ActivateTask(t1);
    GetTaskState(t1,&state3);
    if (result3 == E_OK && state3 == READY) tc_report_error(9,result3,file,__LINE__);
    else tc_report_error(-9,result3,file,__LINE__);

/* t3, active t1, tache extended ready qui ‡ atteint son nombre max d'activation.
    Test case 11 */
    result3 = ActivateTask(t1);
    GetTaskState(t1,&state3);
    if (result3 == E_OS_LIMIT && state3 == READY) tc_report_error(11,result3,file,__LINE__);
    else tc_report_error(-11,result3,file,__LINE__);
	
/* t3, active t3, tache extended ready qui ‡ atteint son nombre max d'activation.
    Test case 16 */
    result3 = ActivateTask(t3);
    if (result3 == E_OS_LIMIT) tc_report_error(16,result3,file,__LINE__);
    else tc_report_error(-16,result3,file,__LINE__);



	tc_check(10);
	/* t3 ferme l'OS */
    ShutdownOS(E_OK);

	TerminateTask();
}

TASK(time_error)
{}
