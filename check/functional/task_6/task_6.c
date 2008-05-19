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
	{ 1,     E_OS_ID      },
	{ 2,     E_OS_ACCESS  },
	{ 3,     E_OS_STATE   },
	{ 100,   E_OK         },
	{ 5,     E_OK         },
	{ 4,     E_OK         },
	{ 101,   E_OK         },
	{ 14,    E_OK         },
	{ 8,     E_OK         },
	{ 102,   E_OK         },
	{ 6,     E_OK         }
	
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
    printf("Starting task_6 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* Au dÃ©marage de l'OS, t0 est running */

/* t0, set event avec un task id invalid
    Test case 1 */
	result = SetEvent(invalidtaskid,EV1);
    if (result == E_OS_ID) tc_report_error(1,result,file,__LINE__);
    else tc_report_error(-1,result,file,__LINE__);

/* t0, set event avec une tâche basic
    Test case 2 */
	result = SetEvent(t0,EV1);
    if (result == E_OS_ACCESS) tc_report_error(2,result,file,__LINE__);
    else tc_report_error(-2,result,file,__LINE__);

/* t0, set event avec une tâche en suspended
    Test case 3 */
	result = SetEvent(t2,EV1);
    if (result == E_OS_STATE) tc_report_error(3,result,file,__LINE__);
    else tc_report_error(-3,result,file,__LINE__);


	ActivateTask(t2);
	ActivateTask(t1);

/* t0, set event avec le mauvais évènement
    Test case 8 */
	result = SetEvent(t2,EV2);
    if (result == E_OK) tc_report(8,file,__LINE__);
    else tc_report_error(-8,result,file,__LINE__);

/* t0, set event avec une tâche de priorité supérieur
    Test case 6 */
	result = SetEvent(t2,EV1);
    if (result == E_OK) tc_report(6,file,__LINE__);
    else tc_report_error(-6,result,file,__LINE__);

	tc_check(10);
	/* t3 ferme l'OS */
    ShutdownOS(E_OK);

	

}

TASK(t1) {
/* t1, set event avec une tâche en suspended
    Test case 5 */
	result = SetEvent(t2,EV2);
    if (result == E_OK) tc_report(5,file,__LINE__);
    else tc_report_error(-5,result,file,__LINE__);

/* t1, set event avec une tâche en suspended
    Test case 4 */
	result = SetEvent(t2,EV1);
    if (result == E_OK) tc_report(4,file,__LINE__);
    else tc_report_error(-4,result,file,__LINE__);

	TerminateTask();

}





TASK(t2) {

	tc_report(100,file,__LINE__);

    WaitEvent(EV1);
	
	tc_report(101,file,__LINE__);

	/* t1, tâche étendue clear un évènement.
    Test case 14 */
	result = ClearEvent(EV1);
    if (result == E_OK) tc_report(14,file,__LINE__);
    else tc_report_error(-14,result,file,__LINE__);

	WaitEvent(EV1);

	tc_report(102,file,__LINE__);

	TerminateTask();
}

TASK(time_error)
{	
	tc_check(10);
	/* t3 ferme l'OS */
    ShutdownOS(E_OK);	
}
