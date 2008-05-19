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
	{ 22,     E_OS_RESOURCE},			 
	{ 24,     E_OS_ID      },
	{ 27,     E_OS_RESOURCE},
	{ 28,     E_OK         },
	{ 29,     E_OK         },
	{ 31,     E_OS_LIMIT   }
};

tc_buf_entry g[20];

tc_buf_loc l[20];

char CT = 28;


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
    printf("Starting task_4 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* Au dÃ©marage de l'OS, t0 est running */

	result = GetResource(res);


/* t0, Terminatetask t0, tache qui n'a pas libérée la ressource.
    Test case 22 */
    result = TerminateTask();
    if (result == E_OS_RESOURCE) tc_report_error(22,result,file,__LINE__);
    else tc_report_error(-22,result,file,__LINE__);

/* t0, chaintask d'un id invalid.
    Test case 24 */
    result = ChainTask(invalidtaskid);
    if (result == E_OS_ID) tc_report_error(24,result,file,__LINE__);
    else tc_report_error(-24,result,file,__LINE__);

/* t0, chaintask t1, tache qui n'a pas libérée la ressource.
    Test case 27 */
    result = ChainTask(t1);
    if (result == E_OS_RESOURCE) tc_report_error(27,result,file,__LINE__);
    else tc_report_error(-27,result,file,__LINE__);

	ReleaseResource(res);

   	ChainTask(t1);

}


TASK(t1) {
    tc_report(CT,file,__LINE__); // CT = 28 puis 29
    
	CT++;

	if (CT == 29) ChainTask(t1);

	ActivateTask(t0);

	/* t0, chaintask t0, tâche qui a atteint son nombre max d'activation.
    Test case 31 */
    result = ChainTask(t0);
    if (result == E_OS_LIMIT) tc_report_error(31,result,file,__LINE__);
    else tc_report_error(-31,result,file,__LINE__);

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
